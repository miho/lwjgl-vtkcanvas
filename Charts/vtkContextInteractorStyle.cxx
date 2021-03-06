/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkContextInteractorStyle.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkContextInteractorStyle.h"

#include "vtkContextMouseEvent.h"
#include "vtkContextKeyEvent.h"
#include "vtkContextScene.h"
#include "vtkCallbackCommand.h"
#include "vtkCommand.h"
#include "vtkObjectFactory.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"

#include <cassert>

vtkStandardNewMacro(vtkContextInteractorStyle);

//--------------------------------------------------------------------------
vtkContextInteractorStyle::vtkContextInteractorStyle()
{
  this->Scene = NULL;
  this->ProcessingEvents = 0;
  this->SceneCallbackCommand->SetClientData(this);
  this->SceneCallbackCommand->SetCallback(
    vtkContextInteractorStyle::ProcessSceneEvents);
  this->InteractorCallbackCommand->SetClientData(this);
  this->InteractorCallbackCommand->SetCallback(
    vtkContextInteractorStyle::ProcessInteractorEvents);
  this->LastSceneRepaintMTime = 0;
  this->TimerId = 0;
  this->TimerCallbackInitialized = false;
}

//--------------------------------------------------------------------------
vtkContextInteractorStyle::~vtkContextInteractorStyle()
{
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  os << indent << "Scene: " << this->Scene << endl;
  if (this->Scene)
    {
    this->Scene->PrintSelf(os, indent.GetNextIndent());
    }
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::SetScene(vtkContextScene* scene)
{
  if (this->Scene == scene)
    {
    return;
    }
  if (this->Scene)
    {
    this->Scene->RemoveObserver(this->SceneCallbackCommand.GetPointer());
    }

  this->Scene = scene;

  if (this->Scene)
    {
    this->Scene->AddObserver(vtkCommand::ModifiedEvent,
                             this->SceneCallbackCommand.GetPointer(),
                             this->Priority);
    }
  this->Modified();
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::ProcessSceneEvents(vtkObject*,
                                                   unsigned long event,
                                                   void* clientdata,
                                                   void* vtkNotUsed(calldata))
{
  vtkContextInteractorStyle* self =
    reinterpret_cast<vtkContextInteractorStyle *>( clientdata );
  switch (event)
    {
    case vtkCommand::ModifiedEvent:
      self->OnSceneModified();
      break;
    default:
      break;
    }
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::ProcessInteractorEvents(vtkObject*,
                                                        unsigned long,
                                                        void* clientdata,
                                                        void* vtkNotUsed(calldata))
{
  vtkContextInteractorStyle* self =
    reinterpret_cast<vtkContextInteractorStyle *>(clientdata);
  self->RenderNow();
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::RenderNow()
{
  this->TimerId = 0;
  if (this->Scene && !this->ProcessingEvents &&
      this->Interactor->GetInitialized())
    {
    this->Interactor->GetRenderWindow()->Render();
    }
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::OnSceneModified()
{
  if (!this->Scene
      || !this->Scene->GetDirty()
      || this->ProcessingEvents
      || this->Scene->GetMTime() == this->LastSceneRepaintMTime
      || !this->Interactor->GetInitialized())
    {
    return;
    }
  this->BeginProcessingEvent();
  if (!this->TimerCallbackInitialized && this->Interactor)
    {
    this->Interactor->AddObserver(vtkCommand::TimerEvent,
                                  this->InteractorCallbackCommand.GetPointer(),
                                  0.0);
    this->TimerCallbackInitialized = true;
    }
  this->LastSceneRepaintMTime = this->Scene->GetMTime();
  // If there is no timer, create a one shot timer to render an updated scene
  if (this->TimerId == 0)
    {
    this->Interactor->CreateOneShotTimer(40);
    }
  this->EndProcessingEvent();
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::BeginProcessingEvent()
{
  ++this->ProcessingEvents;
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::EndProcessingEvent()
{
  --this->ProcessingEvents;
  assert(this->ProcessingEvents >= 0);
  if (this->ProcessingEvents == 0)
    {
    this->OnSceneModified();
    }
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::OnMouseMove()
{
  this->BeginProcessingEvent();

  bool eatEvent = false;
  if (this->Scene)
    {
    int x = this->Interactor->GetEventPosition()[0];
    int y = this->Interactor->GetEventPosition()[1];
    eatEvent = this->Scene->MouseMoveEvent(x, y);
    }
  if (!eatEvent)
    {
    this->Superclass::OnMouseMove();
    }

  this->EndProcessingEvent();
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::OnLeftButtonDown()
{
  this->BeginProcessingEvent();

  bool eatEvent = false;
  if (this->Scene)
    {
    int x = this->Interactor->GetEventPosition()[0];
    int y = this->Interactor->GetEventPosition()[1];
    if (this->Interactor->GetRepeatCount())
      {
      eatEvent =
        this->Scene->DoubleClickEvent(vtkContextMouseEvent::LEFT_BUTTON, x, y);
      }
    else
      {
      eatEvent =
        this->Scene->ButtonPressEvent(vtkContextMouseEvent::LEFT_BUTTON, x, y);
      }
    }
  if (!eatEvent)
    {
    this->Superclass::OnLeftButtonDown();
    }
  this->EndProcessingEvent();
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::OnLeftButtonUp()
{
  this->BeginProcessingEvent();

  bool eatEvent = false;
  if (this->Scene)
    {
    int x = this->Interactor->GetEventPosition()[0];
    int y = this->Interactor->GetEventPosition()[1];
    eatEvent =
      this->Scene->ButtonReleaseEvent(vtkContextMouseEvent::LEFT_BUTTON, x, y);
    }
  if (!eatEvent)
    {
    this->Superclass::OnLeftButtonUp();
    }
  this->EndProcessingEvent();
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::OnMiddleButtonDown()
{
  this->BeginProcessingEvent();

  bool eatEvent = false;
  if (this->Scene)
    {
    int x = this->Interactor->GetEventPosition()[0];
    int y = this->Interactor->GetEventPosition()[1];
    if (this->Interactor->GetRepeatCount())
      {
      eatEvent =
        this->Scene->DoubleClickEvent(vtkContextMouseEvent::MIDDLE_BUTTON, x, y);
      }
    else
      {
      eatEvent =
        this->Scene->ButtonPressEvent(vtkContextMouseEvent::MIDDLE_BUTTON, x, y);
      }
    }
  if (!eatEvent)
    {
    this->Superclass::OnMiddleButtonDown();
    }
  this->EndProcessingEvent();
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::OnMiddleButtonUp()
{
  this->BeginProcessingEvent();

  bool eatEvent = false;
  if (this->Scene)
    {
    int x = this->Interactor->GetEventPosition()[0];
    int y = this->Interactor->GetEventPosition()[1];
    eatEvent =
      this->Scene->ButtonReleaseEvent(vtkContextMouseEvent::MIDDLE_BUTTON, x, y);
    }
  if (!eatEvent)
    {
    this->Superclass::OnMiddleButtonUp();
    }
  this->EndProcessingEvent();
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::OnRightButtonDown()
{
  this->BeginProcessingEvent();

  bool eatEvent = false;
  if (this->Scene)
    {
    int x = this->Interactor->GetEventPosition()[0];
    int y = this->Interactor->GetEventPosition()[1];
    if (this->Interactor->GetRepeatCount())
      {
      eatEvent =
        this->Scene->DoubleClickEvent(vtkContextMouseEvent::RIGHT_BUTTON, x, y);
      }
    else
      {
      eatEvent =
        this->Scene->ButtonPressEvent(vtkContextMouseEvent::RIGHT_BUTTON, x, y);
      }
    }
  if (!eatEvent)
    {
    this->Superclass::OnRightButtonDown();
    }
  this->EndProcessingEvent();
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::OnRightButtonUp()
{
  this->BeginProcessingEvent();

  bool eatEvent = false;
  if (this->Scene)
    {
    int x = this->Interactor->GetEventPosition()[0];
    int y = this->Interactor->GetEventPosition()[1];
    eatEvent =
      this->Scene->ButtonReleaseEvent(vtkContextMouseEvent::RIGHT_BUTTON, x, y);
    }
  if (!eatEvent)
    {
    this->Superclass::OnRightButtonUp();
    }
  this->EndProcessingEvent();
}

//----------------------------------------------------------------------------
void vtkContextInteractorStyle::OnMouseWheelForward()
{
  this->BeginProcessingEvent();

  bool eatEvent = false;
  if (this->Scene)
    {
    int x = this->Interactor->GetEventPosition()[0];
    int y = this->Interactor->GetEventPosition()[1];
    eatEvent =
      this->Scene->MouseWheelEvent(static_cast<int>(this->MouseWheelMotionFactor), x, y);
    }
  if (!eatEvent)
    {
    this->Superclass::OnMouseWheelForward();
    }
  this->EndProcessingEvent();
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::OnMouseWheelBackward()
{
  this->BeginProcessingEvent();

  bool eatEvent = false;
  if (this->Scene)
    {
    int x = this->Interactor->GetEventPosition()[0];
    int y = this->Interactor->GetEventPosition()[1];
    eatEvent =
      this->Scene->MouseWheelEvent(-static_cast<int>(this->MouseWheelMotionFactor), x, y);
    }
  if (!eatEvent)
    {
    this->Superclass::OnMouseWheelBackward();
    }
  this->EndProcessingEvent();
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::OnSelection(unsigned int rect[5])
{
  this->BeginProcessingEvent();
  if (this->Scene)
    {
    this->Scene->ProcessSelectionEvent(rect);
    }
  this->EndProcessingEvent();
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::OnChar()
{
  this->Superclass::OnChar();
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::OnKeyPress()
{
  this->BeginProcessingEvent();
  vtkContextKeyEvent event;
  vtkVector2i position(this->Interactor->GetEventPosition()[0],
                       this->Interactor->GetEventPosition()[0]);
  event.SetInteractor(this->Interactor);
  event.SetPosition(position);
  bool keepEvent = false;
  if (this->Scene)
    {
    keepEvent = this->Scene->KeyPressEvent(event);
    }
  if (!keepEvent)
    {
    this->Superclass::OnKeyPress();
    }
  this->EndProcessingEvent();
}

//--------------------------------------------------------------------------
void vtkContextInteractorStyle::OnKeyRelease()
{
  this->BeginProcessingEvent();
  vtkContextKeyEvent event;
  vtkVector2i position(this->Interactor->GetEventPosition()[0],
                       this->Interactor->GetEventPosition()[0]);
  event.SetInteractor(this->Interactor);
  event.SetPosition(position);
  bool keepEvent = false;
  if (this->Scene)
    {
    keepEvent = this->Scene->KeyReleaseEvent(event);
    }
  if (!keepEvent)
    {
    this->Superclass::OnKeyRelease();
    }
  this->EndProcessingEvent();
}
