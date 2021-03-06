/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImageSincInterpolator.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkImageSincInterpolator - perform sinc interpolation on images
// .SECTION Description
// vtkImageSincInterpolator provides various windowed sinc interpolation
// methods for image data.  The default is a five-lobed Lanczos interpolant,
// with a kernel size of 6.  The interpolator can also bandlimit the image,
// which can be used for antialiasing.  The interpolation kernels are
// evaluated via a lookup table for efficiency.
// .SECTION Thanks
// Thanks to David Gobbi at the Seaman Family MR Centre and Dept. of Clinical
// Neurosciences, Foothills Medical Centre, Calgary, for providing this class.
// .SECTION See also
// vtkImageReslice


#ifndef __vtkImageSincInterpolator_h
#define __vtkImageSincInterpolator_h

#include "vtkAbstractImageInterpolator.h"

#define VTK_LANCZOS_WINDOW 0
#define VTK_COSINE_WINDOW  1
#define VTK_HANN_WINDOW    2
#define VTK_HAMMING_WINDOW 3
#define VTK_BLACKMAN_WINDOW 4
#define VTK_KAISER_WINDOW 5
#define VTK_SINC_KERNEL_SIZE_MAX 32

class vtkImageData;
struct vtkInterpolationInfo;

class VTK_FILTERING_EXPORT vtkImageSincInterpolator :
  public vtkAbstractImageInterpolator
{
public:
  static vtkImageSincInterpolator *New();
  vtkTypeMacro(vtkImageSincInterpolator, vtkAbstractImageInterpolator);
  virtual void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // The window function to use.  The default is Lanczos, which is very
  // popular and performs well with a kernel width of 6.  The Cosine,
  // Hann, and Hamming window functions are traditional window functions.
  // The Blackman and Kaiser functions are the best choices when a large
  // window width is used.
  virtual void SetWindowFunction(int mode);
  void SetWindowFunctionToLanczos() {
    this->SetWindowFunction(VTK_LANCZOS_WINDOW); }
  void SetWindowFunctionToCosine() {
    this->SetWindowFunction(VTK_COSINE_WINDOW); }
  void SetWindowFunctionToHann() {
    this->SetWindowFunction(VTK_HANN_WINDOW); }
  void SetWindowFunctionToHamming() {
    this->SetWindowFunction(VTK_HAMMING_WINDOW); }
  void SetWindowFunctionToBlackman() {
    this->SetWindowFunction(VTK_BLACKMAN_WINDOW); }
  void SetWindowFunctionToKaiser() {
    this->SetWindowFunction(VTK_KAISER_WINDOW); }
  int GetWindowFunction() { return this->WindowFunction; }
  virtual const char *GetWindowFunctionAsString();

  // Description:
  // Set the window half-width, this must be an integer between 1 and 16.
  // The kernel size will be twice this value if no blur factors are
  // applied. The total number of sinc lobes will be one less than twice
  // the half-width, so if the half-width is 3 there will be 5 sinc lobes.
  void SetWindowHalfWidth(int n);
  int GetWindowHalfWidth() { return this->WindowHalfWidth; }

  // Description:
  // Turn this on in order to use SetWindowParameter.  If it is off,
  // then the default parameter will be used for the window.
  void SetUseWindowParameter(int val);
  void UseWindowParameterOn() { this->SetUseWindowParameter(1); }
  void UseWindowParameterOff() { this->SetUseWindowParameter(0); }
  int GetUseWindowParameter() { return this->UseWindowParameter; }

  // Description:
  // Set a window function parameter.  The way this parameter is used
  // will depend on the window function.  The tunable windows are the
  // Hann window (default value 0.5), the Blackman window (default
  // value 0.16), and the Kaiser window (default value 3*n where n is
  // the window half-width).  This parameter will be ignored unless
  // UseWindowParameter is On.
  void SetWindowParameter(double parm);
  double GetWindowParameter() { return this->WindowParameter; }

  // Description:
  // Get the support size for use in computing update extents.  If the data
  // will be sampled on a regular grid, then pass a matrix describing the
  // structured coordinate transformation between the output and the input.
  // Otherwise, pass NULL as the matrix to retrieve the full kernel size.
  virtual void ComputeSupportSize(const double matrix[16], int support[3]);

  // Description:
  // Blur the image by widening the windowed sinc kernel by the specified
  // factors for the x, y, and z directions.  This reduces the bandwidth
  // by these same factors.  If you turn Antialiasing on, then the blur
  // factors will be computed automatically from the output sampling rate.
  // Blurring increases the computation time because the kernel size
  // increases by the blur factor.
  void SetBlurFactors(double x, double y, double z);
  void SetBlurFactors(const double f[3]) {
    this->SetBlurFactors(f[0], f[1], f[2]); }
  void GetBlurFactors(double f[3]) {
    f[0] = this->BlurFactors[0];
    f[1] = this->BlurFactors[1];
    f[2] = this->BlurFactors[2]; }
  double *GetBlurFactors() { return this->BlurFactors; }

  // Description:
  // Turn on antialiasing.  If antialiasing is on, then the BlurFactors
  // will be computed automatically from the output sampling rate such that
  // that the image will be bandlimited to the Nyquist frequency.  This
  // is only applicable when the interpolator is being used by a resampling
  // filter like vtkImageReslice.  Such a filter will indicate the output
  // sampling by calling the interpolator's ComputeSupportSize() method,
  // which will compute the blur factors at the same time that it computes
  // the support size.
  void SetAntialiasing(int antialiasing);
  void AntialiasingOn() { this->SetAntialiasing(1); }
  void AntialiasingOff() { this->SetAntialiasing(0); }
  int GetAntialiasing() { return this->Antialiasing; }

  // Description:
  // Returns true if the interpolator supports weight precomputation.
  // This will always return true for this interpolator.
  virtual bool IsSeparable();

  // Description:
  // If the data is going to be sampled on a regular grid, then the
  // interpolation weights can be precomputed.  A matrix must be
  // supplied that provides a transformation between the provided
  // extent and the structured coordinates of the input.  This
  // matrix must perform only permutations, scales, and translation,
  // i.e. each of the three columns must have only one non-zero value.
  // A new extent is provided for out-of-bounds checks.
  // THIS METHOD IS THREAD SAFE.
  virtual void PrecomputeWeightsForExtent(
    const double matrix[16], const int extent[6], int newExtent[6],
    vtkInterpolationWeights *&weights);
  virtual void PrecomputeWeightsForExtent(
    const float matrix[16], const int extent[6], int newExtent[6],
    vtkInterpolationWeights *&weights);

  // Description:
  // Free the precomputed weights.  THIS METHOD IS THREAD SAFE.
  virtual void FreePrecomputedWeights(vtkInterpolationWeights *&weights);

protected:
  vtkImageSincInterpolator();
  ~vtkImageSincInterpolator();

  // Description:
  // Update the interpolator.
  virtual void InternalUpdate();

  // Description:
  // Copy the interpolator.
  virtual void InternalDeepCopy(vtkAbstractImageInterpolator *obj);

  // Description:
  // Get the interpolation functions.
  virtual void GetInterpolationFunc(
    void (**doublefunc)(
      vtkInterpolationInfo *, const double [3], double *));
  virtual void GetInterpolationFunc(
    void (**floatfunc)(
      vtkInterpolationInfo *, const float [3], float *));

  // Description:
  // Get the row interpolation functions.
  virtual void GetRowInterpolationFunc(
    void (**doublefunc)(
      vtkInterpolationWeights *, int, int, int, double *, int));
  virtual void GetRowInterpolationFunc(
    void (**floatfunc)(
      vtkInterpolationWeights *, int, int, int, float *, int));

  // Description:
  // Build the lookup tables used for the interpolation.
  virtual void BuildKernelLookupTable();

  // Description:
  // Free the kernel lookup tables.
  virtual void FreeKernelLookupTable();

  int WindowFunction;
  int WindowHalfWidth;
  float *KernelLookupTable[3];
  int KernelSize[3];
  int Antialiasing;
  double BlurFactors[3];
  double LastBlurFactors[3];
  double WindowParameter;
  int UseWindowParameter;

private:
  vtkImageSincInterpolator(const vtkImageSincInterpolator&);  // Not implemented.
  void operator=(const vtkImageSincInterpolator&);  // Not implemented.
};

#endif
