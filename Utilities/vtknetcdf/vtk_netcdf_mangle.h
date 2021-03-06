#ifndef vtk_netcdf_mangle_h
#define vtk_netcdf_mangle_h

/*

This header file mangles all symbols exported from the netcdf library.
It is included in all files while building the netcdf library.  Due to
namespace pollution, no netcdf headers should be included in .h files in
VTK.

The following command was used to obtain the symbol list:

nm libvtkNetCDF.a |grep " [TRD] "

This is the way to recreate the whole list:

nm bin/libvtkNetCDF.so |grep " [TRD] " | awk '{ print "#define "$3" vtk_netcdf_"$3 }' | \
        grep -v vtk_netcdf__fini | grep -v vtk_netcdf__init | sort

Note that _fini and _init should be excluded because they are not functions
implemented by the library but are rather created by the linker and
used when the shared library is loaded/unloaded from an executable.

*/

#define default_create_format vtk_netcdf_default_create_format
#define dup_NC_attrarrayV vtk_netcdf_dup_NC_attrarrayV
#define dup_NC_dimarrayV vtk_netcdf_dup_NC_dimarrayV
#define dup_NC_vararrayV vtk_netcdf_dup_NC_vararrayV
#define elem_NC_attrarray vtk_netcdf_elem_NC_attrarray
#define elem_NC_dimarray vtk_netcdf_elem_NC_dimarray
#define fill_NC_var vtk_netcdf_fill_NC_var
#define find_NC_Udim vtk_netcdf_find_NC_Udim
#define free_NC_attrarrayV0 vtk_netcdf_free_NC_attrarrayV0
#define free_NC_attrarrayV vtk_netcdf_free_NC_attrarrayV
#define free_NC_attr vtk_netcdf_free_NC_attr
#define free_NC_dimarrayV0 vtk_netcdf_free_NC_dimarrayV0
#define free_NC_dimarrayV vtk_netcdf_free_NC_dimarrayV
#define free_NC_dim vtk_netcdf_free_NC_dim
#define free_NC_string vtk_netcdf_free_NC_string
#define free_NC_vararrayV0 vtk_netcdf_free_NC_vararrayV0
#define free_NC_vararrayV vtk_netcdf_free_NC_vararrayV
#define free_NC_var vtk_netcdf_free_NC_var
#define nc_abort vtk_netcdf_nc_abort
#define ncabort vtk_netcdf_ncabort
#define nc_advise vtk_netcdf_nc_advise
#define ncattcopy vtk_netcdf_ncattcopy
#define ncattdel vtk_netcdf_ncattdel
#define ncattget vtk_netcdf_ncattget
#define ncattinq vtk_netcdf_ncattinq
#define ncattname vtk_netcdf_ncattname
#define ncattput vtk_netcdf_ncattput
#define ncattrename vtk_netcdf_ncattrename
#define NC_calcsize vtk_netcdf_NC_calcsize
#define NC_check_id vtk_netcdf_NC_check_id
#define NC_check_name vtk_netcdf_NC_check_name
#define NC_check_vlen vtk_netcdf_NC_check_vlen
#define nc_cktype vtk_netcdf_nc_cktype
#define nc_close vtk_netcdf_nc_close
#define ncclose vtk_netcdf_ncclose
#define nc_copy_att vtk_netcdf_nc_copy_att
#define nc_copy_var vtk_netcdf_nc_copy_var
#define nc__create_mp vtk_netcdf_nc__create_mp
#define nc__create vtk_netcdf_nc__create
#define nc_create vtk_netcdf_nc_create
#define nccreate vtk_netcdf_nccreate
#define nc_def_dim vtk_netcdf_nc_def_dim
#define nc_def_var vtk_netcdf_nc_def_var
#define nc_del_att vtk_netcdf_nc_del_att
#define nc_delete_mp vtk_netcdf_nc_delete_mp
#define nc_delete vtk_netcdf_nc_delete
#define ncdimdef vtk_netcdf_ncdimdef
#define ncdimid vtk_netcdf_ncdimid
#define ncdiminq vtk_netcdf_ncdiminq
#define ncdimrename vtk_netcdf_ncdimrename
#define nc__enddef vtk_netcdf_nc__enddef
#define nc_enddef vtk_netcdf_nc_enddef
#define ncendef vtk_netcdf_ncendef
#define ncerr vtk_netcdf_ncerr
#define NC_findattr vtk_netcdf_NC_findattr
#define NC_findvar vtk_netcdf_NC_findvar
#define nc_get_att_double vtk_netcdf_nc_get_att_double
#define nc_get_att_float vtk_netcdf_nc_get_att_float
#define nc_get_att_int vtk_netcdf_nc_get_att_int
#define nc_get_att_long vtk_netcdf_nc_get_att_long
#define nc_get_att_schar vtk_netcdf_nc_get_att_schar
#define nc_get_att_short vtk_netcdf_nc_get_att_short
#define nc_get_att_text vtk_netcdf_nc_get_att_text
#define nc_get_att_uchar vtk_netcdf_nc_get_att_uchar
#define nc_get_att vtk_netcdf_nc_get_att
#define nc_get_NC vtk_netcdf_nc_get_NC
#define nc_get_rec vtk_netcdf_nc_get_rec
#define nc_get_var1_double vtk_netcdf_nc_get_var1_double
#define nc_get_var1_float vtk_netcdf_nc_get_var1_float
#define nc_get_var1_int vtk_netcdf_nc_get_var1_int
#define nc_get_var1_long vtk_netcdf_nc_get_var1_long
#define nc_get_var1_schar vtk_netcdf_nc_get_var1_schar
#define nc_get_var1_short vtk_netcdf_nc_get_var1_short
#define nc_get_var1_text vtk_netcdf_nc_get_var1_text
#define nc_get_var1_uchar vtk_netcdf_nc_get_var1_uchar
#define nc_get_var1 vtk_netcdf_nc_get_var1
#define nc_get_vara_double vtk_netcdf_nc_get_vara_double
#define nc_get_vara_float vtk_netcdf_nc_get_vara_float
#define nc_get_vara_int vtk_netcdf_nc_get_vara_int
#define nc_get_vara_long vtk_netcdf_nc_get_vara_long
#define nc_get_vara_schar vtk_netcdf_nc_get_vara_schar
#define nc_get_vara_short vtk_netcdf_nc_get_vara_short
#define nc_get_vara_text vtk_netcdf_nc_get_vara_text
#define nc_get_vara_uchar vtk_netcdf_nc_get_vara_uchar
#define nc_get_vara vtk_netcdf_nc_get_vara
#define nc_get_var_double vtk_netcdf_nc_get_var_double
#define nc_get_var_float vtk_netcdf_nc_get_var_float
#define nc_get_var_int vtk_netcdf_nc_get_var_int
#define nc_get_var_long vtk_netcdf_nc_get_var_long
#define nc_get_varm_double vtk_netcdf_nc_get_varm_double
#define nc_get_varm_float vtk_netcdf_nc_get_varm_float
#define nc_get_varm_int vtk_netcdf_nc_get_varm_int
#define nc_get_varm_long vtk_netcdf_nc_get_varm_long
#define nc_get_varm_schar vtk_netcdf_nc_get_varm_schar
#define nc_get_varm_short vtk_netcdf_nc_get_varm_short
#define nc_get_varm_text vtk_netcdf_nc_get_varm_text
#define nc_get_varm_uchar vtk_netcdf_nc_get_varm_uchar
#define nc_get_varm vtk_netcdf_nc_get_varm
#define nc_get_var_schar vtk_netcdf_nc_get_var_schar
#define nc_get_vars_double vtk_netcdf_nc_get_vars_double
#define nc_get_vars_float vtk_netcdf_nc_get_vars_float
#define nc_get_var_short vtk_netcdf_nc_get_var_short
#define nc_get_vars_int vtk_netcdf_nc_get_vars_int
#define nc_get_vars_long vtk_netcdf_nc_get_vars_long
#define nc_get_vars_schar vtk_netcdf_nc_get_vars_schar
#define nc_get_vars_short vtk_netcdf_nc_get_vars_short
#define nc_get_vars_text vtk_netcdf_nc_get_vars_text
#define nc_get_vars_uchar vtk_netcdf_nc_get_vars_uchar
#define nc_get_vars vtk_netcdf_nc_get_vars
#define nc_get_var_text vtk_netcdf_nc_get_var_text
#define nc_get_var_uchar vtk_netcdf_nc_get_var_uchar
#define nc_inq_attid vtk_netcdf_nc_inq_attid
#define nc_inq_attlen vtk_netcdf_nc_inq_attlen
#define nc_inq_attname vtk_netcdf_nc_inq_attname
#define nc_inq_atttype vtk_netcdf_nc_inq_atttype
#define nc_inq_att vtk_netcdf_nc_inq_att
#define nc_inq_base_pe vtk_netcdf_nc_inq_base_pe
#define nc_inq_dimid vtk_netcdf_nc_inq_dimid
#define nc_inq_dimlen vtk_netcdf_nc_inq_dimlen
#define nc_inq_dimname vtk_netcdf_nc_inq_dimname
#define nc_inq_dim vtk_netcdf_nc_inq_dim
#define nc_inq_format vtk_netcdf_nc_inq_format
#define nc_inq_libvers vtk_netcdf_nc_inq_libvers
#define nc_inq_natts vtk_netcdf_nc_inq_natts
#define nc_inq_ndims vtk_netcdf_nc_inq_ndims
#define nc_inq_nvars vtk_netcdf_nc_inq_nvars
#define nc_inq_rec vtk_netcdf_nc_inq_rec
#define nc_inq_type vtk_netcdf_nc_inq_type
#define ncinquire vtk_netcdf_ncinquire
#define nc_inq_unlimdim vtk_netcdf_nc_inq_unlimdim
#define nc_inq_vardimid vtk_netcdf_nc_inq_vardimid
#define nc_inq_varid vtk_netcdf_nc_inq_varid
#define nc_inq_varname vtk_netcdf_nc_inq_varname
#define nc_inq_varnatts vtk_netcdf_nc_inq_varnatts
#define nc_inq_varndims vtk_netcdf_nc_inq_varndims
#define nc_inq_vartype vtk_netcdf_nc_inq_vartype
#define nc_inq_var vtk_netcdf_nc_inq_var
#define nc_inq vtk_netcdf_nc_inq
#define ncio_close vtk_netcdf_ncio_close
#define ncio_create vtk_netcdf_ncio_create
#define ncio_filesize vtk_netcdf_ncio_filesize
#define ncio_open vtk_netcdf_ncio_open
#define ncio_pad_length vtk_netcdf_ncio_pad_length
#define NC_lookupvar vtk_netcdf_NC_lookupvar
#define nc__open_mp vtk_netcdf_nc__open_mp
#define nc__open vtk_netcdf_nc__open
#define nc_open vtk_netcdf_nc_open
#define ncopen vtk_netcdf_ncopen
#define ncopts vtk_netcdf_ncopts
#define nc_put_att_double vtk_netcdf_nc_put_att_double
#define nc_put_att_float vtk_netcdf_nc_put_att_float
#define nc_put_att_int vtk_netcdf_nc_put_att_int
#define nc_put_att_long vtk_netcdf_nc_put_att_long
#define nc_put_att_schar vtk_netcdf_nc_put_att_schar
#define nc_put_att_short vtk_netcdf_nc_put_att_short
#define nc_put_att_text vtk_netcdf_nc_put_att_text
#define nc_put_att_uchar vtk_netcdf_nc_put_att_uchar
#define nc_put_att vtk_netcdf_nc_put_att
#define nc_put_rec vtk_netcdf_nc_put_rec
#define nc_put_var1_double vtk_netcdf_nc_put_var1_double
#define nc_put_var1_float vtk_netcdf_nc_put_var1_float
#define nc_put_var1_int vtk_netcdf_nc_put_var1_int
#define nc_put_var1_long vtk_netcdf_nc_put_var1_long
#define nc_put_var1_schar vtk_netcdf_nc_put_var1_schar
#define nc_put_var1_short vtk_netcdf_nc_put_var1_short
#define nc_put_var1_text vtk_netcdf_nc_put_var1_text
#define nc_put_var1_uchar vtk_netcdf_nc_put_var1_uchar
#define nc_put_var1 vtk_netcdf_nc_put_var1
#define nc_put_vara_double vtk_netcdf_nc_put_vara_double
#define nc_put_vara_float vtk_netcdf_nc_put_vara_float
#define nc_put_vara_int vtk_netcdf_nc_put_vara_int
#define nc_put_vara_long vtk_netcdf_nc_put_vara_long
#define nc_put_vara_schar vtk_netcdf_nc_put_vara_schar
#define nc_put_vara_short vtk_netcdf_nc_put_vara_short
#define nc_put_vara_text vtk_netcdf_nc_put_vara_text
#define nc_put_vara_uchar vtk_netcdf_nc_put_vara_uchar
#define nc_put_vara vtk_netcdf_nc_put_vara
#define nc_put_var_double vtk_netcdf_nc_put_var_double
#define nc_put_var_float vtk_netcdf_nc_put_var_float
#define nc_put_var_int vtk_netcdf_nc_put_var_int
#define nc_put_var_long vtk_netcdf_nc_put_var_long
#define nc_put_varm_double vtk_netcdf_nc_put_varm_double
#define nc_put_varm_float vtk_netcdf_nc_put_varm_float
#define nc_put_varm_int vtk_netcdf_nc_put_varm_int
#define nc_put_varm_long vtk_netcdf_nc_put_varm_long
#define nc_put_varm_schar vtk_netcdf_nc_put_varm_schar
#define nc_put_varm_short vtk_netcdf_nc_put_varm_short
#define nc_put_varm_text vtk_netcdf_nc_put_varm_text
#define nc_put_varm_uchar vtk_netcdf_nc_put_varm_uchar
#define nc_put_varm vtk_netcdf_nc_put_varm
#define nc_put_var_schar vtk_netcdf_nc_put_var_schar
#define nc_put_vars_double vtk_netcdf_nc_put_vars_double
#define nc_put_vars_float vtk_netcdf_nc_put_vars_float
#define nc_put_var_short vtk_netcdf_nc_put_var_short
#define nc_put_vars_int vtk_netcdf_nc_put_vars_int
#define nc_put_vars_long vtk_netcdf_nc_put_vars_long
#define nc_put_vars_schar vtk_netcdf_nc_put_vars_schar
#define nc_put_vars_short vtk_netcdf_nc_put_vars_short
#define nc_put_vars_text vtk_netcdf_nc_put_vars_text
#define nc_put_vars_uchar vtk_netcdf_nc_put_vars_uchar
#define nc_put_vars vtk_netcdf_nc_put_vars
#define nc_put_var_text vtk_netcdf_nc_put_var_text
#define nc_put_var_uchar vtk_netcdf_nc_put_var_uchar
#define ncrecget vtk_netcdf_ncrecget
#define ncrecinq vtk_netcdf_ncrecinq
#define ncrecput vtk_netcdf_ncrecput
#define nc_redef vtk_netcdf_nc_redef
#define ncredef vtk_netcdf_ncredef
#define nc_rename_att vtk_netcdf_nc_rename_att
#define nc_rename_dim vtk_netcdf_nc_rename_dim
#define nc_rename_var vtk_netcdf_nc_rename_var
#define nc_set_base_pe vtk_netcdf_nc_set_base_pe
#define nc_set_default_format vtk_netcdf_nc_set_default_format
#define nc_set_fill vtk_netcdf_nc_set_fill
#define ncsetfill vtk_netcdf_ncsetfill
#define nc_strerror vtk_netcdf_nc_strerror
#define nc_sync vtk_netcdf_nc_sync
#define ncsync vtk_netcdf_ncsync
#define NC_sync vtk_netcdf_NC_sync
#define nctypelen vtk_netcdf_nctypelen
#define ncvardef vtk_netcdf_ncvardef
#define ncvarget1 vtk_netcdf_ncvarget1
#define ncvargetg vtk_netcdf_ncvargetg
#define ncvargets vtk_netcdf_ncvargets
#define ncvarget vtk_netcdf_ncvarget
#define ncvarid vtk_netcdf_ncvarid
#define ncvarinq vtk_netcdf_ncvarinq
#define ncvarput1 vtk_netcdf_ncvarput1
#define ncvarputg vtk_netcdf_ncvarputg
#define ncvarputs vtk_netcdf_ncvarputs
#define ncvarput vtk_netcdf_ncvarput
#define ncvarrename vtk_netcdf_ncvarrename
#define NC_var_shape vtk_netcdf_NC_var_shape
#define ncx_get_double_double vtk_netcdf_ncx_get_double_double
#define ncx_get_double_float vtk_netcdf_ncx_get_double_float
#define ncx_get_double_int vtk_netcdf_ncx_get_double_int
#define ncx_get_double_long vtk_netcdf_ncx_get_double_long
#define ncx_get_double_schar vtk_netcdf_ncx_get_double_schar
#define ncx_get_double_short vtk_netcdf_ncx_get_double_short
#define ncx_get_double_uchar vtk_netcdf_ncx_get_double_uchar
#define ncx_get_float_double vtk_netcdf_ncx_get_float_double
#define ncx_get_float_float vtk_netcdf_ncx_get_float_float
#define ncx_get_float_int vtk_netcdf_ncx_get_float_int
#define ncx_get_float_long vtk_netcdf_ncx_get_float_long
#define ncx_get_float_schar vtk_netcdf_ncx_get_float_schar
#define ncx_get_float_short vtk_netcdf_ncx_get_float_short
#define ncx_get_float_uchar vtk_netcdf_ncx_get_float_uchar
#define ncx_get_int_double vtk_netcdf_ncx_get_int_double
#define ncx_get_int_float vtk_netcdf_ncx_get_int_float
#define ncx_get_int_int vtk_netcdf_ncx_get_int_int
#define ncx_get_int_long vtk_netcdf_ncx_get_int_long
#define ncx_get_int_schar vtk_netcdf_ncx_get_int_schar
#define ncx_get_int_short vtk_netcdf_ncx_get_int_short
#define ncx_get_int_uchar vtk_netcdf_ncx_get_int_uchar
#define ncx_getn_double_double vtk_netcdf_ncx_getn_double_double
#define ncx_getn_double_float vtk_netcdf_ncx_getn_double_float
#define ncx_getn_double_int vtk_netcdf_ncx_getn_double_int
#define ncx_getn_double_long vtk_netcdf_ncx_getn_double_long
#define ncx_getn_double_schar vtk_netcdf_ncx_getn_double_schar
#define ncx_getn_double_short vtk_netcdf_ncx_getn_double_short
#define ncx_getn_double_uchar vtk_netcdf_ncx_getn_double_uchar
#define ncx_getn_float_double vtk_netcdf_ncx_getn_float_double
#define ncx_getn_float_float vtk_netcdf_ncx_getn_float_float
#define ncx_getn_float_int vtk_netcdf_ncx_getn_float_int
#define ncx_getn_float_long vtk_netcdf_ncx_getn_float_long
#define ncx_getn_float_schar vtk_netcdf_ncx_getn_float_schar
#define ncx_getn_float_short vtk_netcdf_ncx_getn_float_short
#define ncx_getn_float_uchar vtk_netcdf_ncx_getn_float_uchar
#define ncx_getn_int_double vtk_netcdf_ncx_getn_int_double
#define ncx_getn_int_float vtk_netcdf_ncx_getn_int_float
#define ncx_getn_int_int vtk_netcdf_ncx_getn_int_int
#define ncx_getn_int_long vtk_netcdf_ncx_getn_int_long
#define ncx_getn_int_schar vtk_netcdf_ncx_getn_int_schar
#define ncx_getn_int_short vtk_netcdf_ncx_getn_int_short
#define ncx_getn_int_uchar vtk_netcdf_ncx_getn_int_uchar
#define ncx_getn_schar_double vtk_netcdf_ncx_getn_schar_double
#define ncx_getn_schar_float vtk_netcdf_ncx_getn_schar_float
#define ncx_getn_schar_int vtk_netcdf_ncx_getn_schar_int
#define ncx_getn_schar_long vtk_netcdf_ncx_getn_schar_long
#define ncx_getn_schar_schar vtk_netcdf_ncx_getn_schar_schar
#define ncx_getn_schar_short vtk_netcdf_ncx_getn_schar_short
#define ncx_getn_schar_uchar vtk_netcdf_ncx_getn_schar_uchar
#define ncx_getn_short_double vtk_netcdf_ncx_getn_short_double
#define ncx_getn_short_float vtk_netcdf_ncx_getn_short_float
#define ncx_getn_short_int vtk_netcdf_ncx_getn_short_int
#define ncx_getn_short_long vtk_netcdf_ncx_getn_short_long
#define ncx_getn_short_schar vtk_netcdf_ncx_getn_short_schar
#define ncx_getn_short_short vtk_netcdf_ncx_getn_short_short
#define ncx_getn_short_uchar vtk_netcdf_ncx_getn_short_uchar
#define ncx_getn_text vtk_netcdf_ncx_getn_text
#define ncx_getn_void vtk_netcdf_ncx_getn_void
#define ncx_get_off_t vtk_netcdf_ncx_get_off_t
#define ncx_get_short_double vtk_netcdf_ncx_get_short_double
#define ncx_get_short_float vtk_netcdf_ncx_get_short_float
#define ncx_get_short_int vtk_netcdf_ncx_get_short_int
#define ncx_get_short_long vtk_netcdf_ncx_get_short_long
#define ncx_get_short_schar vtk_netcdf_ncx_get_short_schar
#define ncx_get_short_short vtk_netcdf_ncx_get_short_short
#define ncx_get_short_uchar vtk_netcdf_ncx_get_short_uchar
#define ncx_get_size_t vtk_netcdf_ncx_get_size_t
#define ncx_howmany vtk_netcdf_ncx_howmany
#define ncx_len_NC vtk_netcdf_ncx_len_NC
#define ncx_pad_getn_schar_double vtk_netcdf_ncx_pad_getn_schar_double
#define ncx_pad_getn_schar_float vtk_netcdf_ncx_pad_getn_schar_float
#define ncx_pad_getn_schar_int vtk_netcdf_ncx_pad_getn_schar_int
#define ncx_pad_getn_schar_long vtk_netcdf_ncx_pad_getn_schar_long
#define ncx_pad_getn_schar_schar vtk_netcdf_ncx_pad_getn_schar_schar
#define ncx_pad_getn_schar_short vtk_netcdf_ncx_pad_getn_schar_short
#define ncx_pad_getn_schar_uchar vtk_netcdf_ncx_pad_getn_schar_uchar
#define ncx_pad_getn_short_double vtk_netcdf_ncx_pad_getn_short_double
#define ncx_pad_getn_short_float vtk_netcdf_ncx_pad_getn_short_float
#define ncx_pad_getn_short_int vtk_netcdf_ncx_pad_getn_short_int
#define ncx_pad_getn_short_long vtk_netcdf_ncx_pad_getn_short_long
#define ncx_pad_getn_short_schar vtk_netcdf_ncx_pad_getn_short_schar
#define ncx_pad_getn_short_short vtk_netcdf_ncx_pad_getn_short_short
#define ncx_pad_getn_short_uchar vtk_netcdf_ncx_pad_getn_short_uchar
#define ncx_pad_getn_text vtk_netcdf_ncx_pad_getn_text
#define ncx_pad_getn_void vtk_netcdf_ncx_pad_getn_void
#define ncx_pad_putn_schar_double vtk_netcdf_ncx_pad_putn_schar_double
#define ncx_pad_putn_schar_float vtk_netcdf_ncx_pad_putn_schar_float
#define ncx_pad_putn_schar_int vtk_netcdf_ncx_pad_putn_schar_int
#define ncx_pad_putn_schar_long vtk_netcdf_ncx_pad_putn_schar_long
#define ncx_pad_putn_schar_schar vtk_netcdf_ncx_pad_putn_schar_schar
#define ncx_pad_putn_schar_short vtk_netcdf_ncx_pad_putn_schar_short
#define ncx_pad_putn_schar_uchar vtk_netcdf_ncx_pad_putn_schar_uchar
#define ncx_pad_putn_short_double vtk_netcdf_ncx_pad_putn_short_double
#define ncx_pad_putn_short_float vtk_netcdf_ncx_pad_putn_short_float
#define ncx_pad_putn_short_int vtk_netcdf_ncx_pad_putn_short_int
#define ncx_pad_putn_short_long vtk_netcdf_ncx_pad_putn_short_long
#define ncx_pad_putn_short_schar vtk_netcdf_ncx_pad_putn_short_schar
#define ncx_pad_putn_short_short vtk_netcdf_ncx_pad_putn_short_short
#define ncx_pad_putn_short_uchar vtk_netcdf_ncx_pad_putn_short_uchar
#define ncx_pad_putn_text vtk_netcdf_ncx_pad_putn_text
#define ncx_pad_putn_void vtk_netcdf_ncx_pad_putn_void
#define ncx_put_double_double vtk_netcdf_ncx_put_double_double
#define ncx_put_double_float vtk_netcdf_ncx_put_double_float
#define ncx_put_double_int vtk_netcdf_ncx_put_double_int
#define ncx_put_double_long vtk_netcdf_ncx_put_double_long
#define ncx_put_double_schar vtk_netcdf_ncx_put_double_schar
#define ncx_put_double_short vtk_netcdf_ncx_put_double_short
#define ncx_put_double_uchar vtk_netcdf_ncx_put_double_uchar
#define ncx_put_float_double vtk_netcdf_ncx_put_float_double
#define ncx_put_float_float vtk_netcdf_ncx_put_float_float
#define ncx_put_float_int vtk_netcdf_ncx_put_float_int
#define ncx_put_float_long vtk_netcdf_ncx_put_float_long
#define ncx_put_float_schar vtk_netcdf_ncx_put_float_schar
#define ncx_put_float_short vtk_netcdf_ncx_put_float_short
#define ncx_put_float_uchar vtk_netcdf_ncx_put_float_uchar
#define ncx_put_int_double vtk_netcdf_ncx_put_int_double
#define ncx_put_int_float vtk_netcdf_ncx_put_int_float
#define ncx_put_int_int vtk_netcdf_ncx_put_int_int
#define ncx_put_int_long vtk_netcdf_ncx_put_int_long
#define ncx_put_int_schar vtk_netcdf_ncx_put_int_schar
#define ncx_put_int_short vtk_netcdf_ncx_put_int_short
#define ncx_put_int_uchar vtk_netcdf_ncx_put_int_uchar
#define ncx_put_NC vtk_netcdf_ncx_put_NC
#define ncx_putn_double_double vtk_netcdf_ncx_putn_double_double
#define ncx_putn_double_float vtk_netcdf_ncx_putn_double_float
#define ncx_putn_double_int vtk_netcdf_ncx_putn_double_int
#define ncx_putn_double_long vtk_netcdf_ncx_putn_double_long
#define ncx_putn_double_schar vtk_netcdf_ncx_putn_double_schar
#define ncx_putn_double_short vtk_netcdf_ncx_putn_double_short
#define ncx_putn_double_uchar vtk_netcdf_ncx_putn_double_uchar
#define ncx_putn_float_double vtk_netcdf_ncx_putn_float_double
#define ncx_putn_float_float vtk_netcdf_ncx_putn_float_float
#define ncx_putn_float_int vtk_netcdf_ncx_putn_float_int
#define ncx_putn_float_long vtk_netcdf_ncx_putn_float_long
#define ncx_putn_float_schar vtk_netcdf_ncx_putn_float_schar
#define ncx_putn_float_short vtk_netcdf_ncx_putn_float_short
#define ncx_putn_float_uchar vtk_netcdf_ncx_putn_float_uchar
#define ncx_putn_int_double vtk_netcdf_ncx_putn_int_double
#define ncx_putn_int_float vtk_netcdf_ncx_putn_int_float
#define ncx_putn_int_int vtk_netcdf_ncx_putn_int_int
#define ncx_putn_int_long vtk_netcdf_ncx_putn_int_long
#define ncx_putn_int_schar vtk_netcdf_ncx_putn_int_schar
#define ncx_putn_int_short vtk_netcdf_ncx_putn_int_short
#define ncx_putn_int_uchar vtk_netcdf_ncx_putn_int_uchar
#define ncx_putn_schar_double vtk_netcdf_ncx_putn_schar_double
#define ncx_putn_schar_float vtk_netcdf_ncx_putn_schar_float
#define ncx_putn_schar_int vtk_netcdf_ncx_putn_schar_int
#define ncx_putn_schar_long vtk_netcdf_ncx_putn_schar_long
#define ncx_putn_schar_schar vtk_netcdf_ncx_putn_schar_schar
#define ncx_putn_schar_short vtk_netcdf_ncx_putn_schar_short
#define ncx_putn_schar_uchar vtk_netcdf_ncx_putn_schar_uchar
#define ncx_putn_short_double vtk_netcdf_ncx_putn_short_double
#define ncx_putn_short_float vtk_netcdf_ncx_putn_short_float
#define ncx_putn_short_int vtk_netcdf_ncx_putn_short_int
#define ncx_putn_short_long vtk_netcdf_ncx_putn_short_long
#define ncx_putn_short_schar vtk_netcdf_ncx_putn_short_schar
#define ncx_putn_short_short vtk_netcdf_ncx_putn_short_short
#define ncx_putn_short_uchar vtk_netcdf_ncx_putn_short_uchar
#define ncx_putn_text vtk_netcdf_ncx_putn_text
#define ncx_putn_void vtk_netcdf_ncx_putn_void
#define ncx_put_off_t vtk_netcdf_ncx_put_off_t
#define ncx_put_short_double vtk_netcdf_ncx_put_short_double
#define ncx_put_short_float vtk_netcdf_ncx_put_short_float
#define ncx_put_short_int vtk_netcdf_ncx_put_short_int
#define ncx_put_short_long vtk_netcdf_ncx_put_short_long
#define ncx_put_short_schar vtk_netcdf_ncx_put_short_schar
#define ncx_put_short_short vtk_netcdf_ncx_put_short_short
#define ncx_put_short_uchar vtk_netcdf_ncx_put_short_uchar
#define ncx_put_size_t vtk_netcdf_ncx_put_size_t
#define ncx_szof vtk_netcdf_ncx_szof
#define new_NC_string vtk_netcdf_new_NC_string
#define new_x_NC_attr vtk_netcdf_new_x_NC_attr
#define new_x_NC_dim vtk_netcdf_new_x_NC_dim
#define new_x_NC_var vtk_netcdf_new_x_NC_var
#define nextUTF8 vtk_netcdf_nextUTF8
#define nulldup vtk_netcdf_nulldup
#define read_numrecs vtk_netcdf_read_numrecs
#define set_NC_string vtk_netcdf_set_NC_string
#define write_numrecs vtk_netcdf_write_numrecs

#include "vtknetcdf/ncconfig.h"

#endif /* vtk_netcdf_mangle_h */
