/*
 *  Copyright (C) 2011, 2012, 2013 Michael Hofmann
 *  
 *  This file is part of ScaFaCoS.
 *  
 *  ScaFaCoS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  ScaFaCoS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser Public License for more details.
 *  
 *  You should have received a copy of the GNU Lesser Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *  

 *  
 *  SL - Sorting Library, michael <dot> hofmann <at> informatik <dot> tu-chemnitz <dot> de
 */


#ifndef __SL_BACK__P_H__
#define __SL_BACK__P_H__

#ifdef SL_USE_MPI
 #include <mpi.h>
#endif /* SL_USE_MPI */

#define SL_PROTO(_f_)  _f_

#define back__p_sl_key_type_c              long long
#define back__p_sl_key_type_mpi            MPI_LONG_LONG
#define back__p_sl_key_size_mpi            1
#define back__p_sl_key_type_fmt            "lld"

#define back__p_sl_key_integer

/*#define back__p_SL_DATA0*/
#define back__p_sl_data0_type_c            fcs_float
#define back__p_sl_data0_size_c            3
#define back__p_sl_data0_type_mpi          FCS_MPI_FLOAT
#define back__p_sl_data0_size_mpi          3

#define back__p_SL_DATA1
#define back__p_sl_data1_type_c            fcs_float
#define back__p_sl_data1_size_c            1
#define back__p_sl_data1_type_mpi          FCS_MPI_FLOAT
#define back__p_sl_data1_size_mpi          1

#define back__p_MC_ALLTOALL_INT_2STEP_THRESHOLD  1024




#if defined(MSEG_ROOT) && !defined(back__p_MSEG_ROOT)
# define back__p_MSEG_ROOT  MSEG_ROOT
#endif

#if defined(MSEG_BORDER_UPDATE_REDUCTION) && !defined(back__p_MSEG_BORDER_UPDATE_REDUCTION)
# define back__p_MSEG_BORDER_UPDATE_REDUCTION  MSEG_BORDER_UPDATE_REDUCTION
#endif

#if defined(MSEG_DISABLE_BEST_CHOICE) && !defined(back__p_MSEG_DISABLE_BEST_CHOICE)
# define back__p_MSEG_DISABLE_BEST_CHOICE  MSEG_DISABLE_BEST_CHOICE
#endif

#if defined(MSEG_DISABLE_MINMAX) && !defined(back__p_MSEG_DISABLE_MINMAX)
# define back__p_MSEG_DISABLE_MINMAX  MSEG_DISABLE_MINMAX
#endif

#if defined(MSEG_ENABLE_OPTIMZED_LOWHIGH) && !defined(back__p_MSEG_ENABLE_OPTIMZED_LOWHIGH)
# define back__p_MSEG_ENABLE_OPTIMZED_LOWHIGH  MSEG_ENABLE_OPTIMZED_LOWHIGH
#endif

#if defined(MSEG_FORWARD_ONLY) && !defined(back__p_MSEG_FORWARD_ONLY)
# define back__p_MSEG_FORWARD_ONLY  MSEG_FORWARD_ONLY
#endif

#if defined(MSEG_INFO) && !defined(back__p_MSEG_INFO)
# define back__p_MSEG_INFO  MSEG_INFO
#endif

#if defined(MSEG_TRACE_IF) && !defined(back__p_MSEG_TRACE_IF)
# define back__p_MSEG_TRACE_IF  MSEG_TRACE_IF
#endif






/* override SL_USE_MPI from sl_config.h */
#ifdef SL_USE_MPI_IGNORE
# undef SL_USE_MPI
#endif

#ifdef SL_USE_MPI_FORCE
# ifndef SL_USE_MPI
#  define SL_USE_MPI
# endif
#endif

/* override SL_USE_OMP from sl_config.h */
#ifdef SL_USE_OMP_IGNORE
# undef SL_USE_OMP
#endif

#ifdef SL_USE_OMP_FORCE
# ifndef SL_USE_OMP
#  define SL_USE_OMP
# endif
#endif


#ifndef back__p_SL_INDEX
# undef back__p_SL_PACKED_INDEX
#endif


/* if no special datatype for (sl default) integer ... */
#ifndef back__p_sl_int_type_c
  /* ... use a default one */
# define back__p_sl_int_type_c               long      /* sl_macro */
# undef back__p_sl_int_type_mpi
# define back__p_sl_int_type_mpi             MPI_LONG  /* sl_macro */
# undef back__p_sl_int_size_mpi
# define back__p_sl_int_size_mpi             1         /* sl_macro */
# undef back__p_sl_int_type_fmt
# define back__p_sl_int_type_fmt             "ld"      /* sl_macro */
#else
  /* ... use the given one and check whether an mpi-type is present and required */
# ifdef SL_USE_MPI
#  if !defined(back__p_sl_int_type_mpi) || !defined(back__p_sl_int_size_mpi)
#   error "back__p_sl_int_type_mpi and/or back__p_sl_int_size_mpi missing"
#  endif
# endif
# ifndef back__p_sl_int_type_fmt
#  error "back__p_sl_int_type_fmt macro is missing, using d as default"
#  define back__p_sl_int_type_fmt  "d"
# endif
#endif


/* if no special datatype for (intern) weight ... */
#ifndef back__p_sl_weight_type_c
 /* ... use (sl default) integer */
# define back__p_sl_weight_type_c             back__p_sl_int_type_c    /* sl_macro */
# undef back__p_sl_weight_type_mpi
# define back__p_sl_weight_type_mpi           back__p_sl_int_type_mpi  /* sl_macro */
# undef back__p_sl_weight_size_mpi
# define back__p_sl_weight_size_mpi           back__p_sl_int_size_mpi  /* sl_macro */
# undef back__p_sl_weight_type_fmt
# define back__p_sl_weight_type_fmt           back__p_sl_int_type_fmt  /* sl_macro */
# undef back__p_sl_weight_intequiv
# define back__p_sl_weight_intequiv                            /* sl_macro */
#else
  /* ... use the given one and check whether an mpi-type is present and required */
# ifdef SL_USE_MPI
#  if !defined(back__p_sl_weight_type_mpi) || !defined(back__p_sl_weight_size_mpi)
#   error "back__p_sl_weight_type_mpi and/or back__p_sl_weight_size_mpi missing"
#  endif
# endif
# ifndef back__p_sl_weight_type_fmt
#  error "back__p_sl_weight_type_fmt macro is missing, using f as default"
#  define back__p_sl_weight_type_fmt  "f"
# endif
#endif


/* if no special datatype for indexes ... */
#ifndef back__p_sl_index_type_c
 /* ... use the primary integer type */
# define back__p_sl_index_type_c             back__p_sl_int_type_c
# undef back__p_sl_index_type_mpi
# define back__p_sl_index_type_mpi           back__p_sl_int_type_mpi
# undef back__p_sl_index_size_mpi
# define back__p_sl_index_size_mpi           back__p_sl_int_size_mpi
# undef back__p_sl_index_type_fmt
# define back__p_sl_index_type_fmt           back__p_sl_int_type_fmt
#else
  /* ... use the given one and check whether an mpi-type is present and required */
# ifdef SL_USE_MPI
#  if !defined(back__p_sl_index_type_mpi) || !defined(back__p_sl_index_size_mpi)
#   error "back__p_sl_index_type_mpi and/or back__p_sl_index_size_mpi missing"
#  endif
# endif
# ifndef back__p_sl_index_type_fmt
#  error "back__p_sl_index_type_fmt macro is missing, using d as default"
#  define back__p_sl_index_type_fmt  "d"
# endif
#endif


/* default pure keys */
#ifndef back__p_sl_key_pure_type_c
# define back__p_sl_key_pure_type_c          back__p_sl_key_type_c  /* sl_macro */
#endif
#ifndef back__p_sl_key_pure_type_mpi
# define back__p_sl_key_pure_type_mpi        back__p_sl_key_type_mpi  /* sl_macro */
#endif
#ifndef back__p_sl_key_pure_size_mpi
# define back__p_sl_key_pure_size_mpi        back__p_sl_key_size_mpi  /* sl_macro */
#endif
#ifndef back__p_sl_key_pure_type_fmt
# ifdef back__p_sl_key_type_fmt
#  define back__p_sl_key_pure_type_fmt       back__p_sl_key_type_fmt  /* sl_macro */
# endif
#endif

#ifndef back__p_sl_key_purify
 /* key val -> key val */
 #define back__p_sl_key_purify(k)            (k)  /* sl_macro */
#endif
#ifndef back__p_sl_key_get_pure
 /* key component pointer -> key val pointer */
 #define back__p_sl_key_get_pure(k)          (k)  /* sl_macro */
#endif
#ifndef back__p_sl_key_set_pure
 /* key component pointer and key val */
 #define back__p_sl_key_set_pure(k, p)       (*(k) = p)  /* sl_macro */
#endif


/* default pure key comparisons */
#ifndef back__p_sl_key_pure_cmp_eq
 #define back__p_sl_key_pure_cmp_eq(k0, k1)  ((k0) == (k1))  /* sl_macro */
#endif
#ifndef back__p_sl_key_pure_cmp_ne
 #define back__p_sl_key_pure_cmp_ne(k0, k1)  ((k0) != (k1))  /* sl_macro */
#endif
#ifndef back__p_sl_key_pure_cmp_lt
 #define back__p_sl_key_pure_cmp_lt(k0, k1)  ((k0) < (k1))  /* sl_macro */
#endif
#ifndef back__p_sl_key_pure_cmp_le
 #define back__p_sl_key_pure_cmp_le(k0, k1)  ((k0) <= (k1))  /* sl_macro */
#endif
#ifndef back__p_sl_key_pure_cmp_gt
 #define back__p_sl_key_pure_cmp_gt(k0, k1)  ((k0) > (k1))  /* sl_macro */
#endif
#ifndef back__p_sl_key_pure_cmp_ge
 #define back__p_sl_key_pure_cmp_ge(k0, k1)  ((k0) >= (k1))  /* sl_macro */
#endif


/* default key comparisons */
#ifndef back__p_sl_key_cmp_eq
 #define back__p_sl_key_cmp_eq(k0, k1)       (back__p_sl_key_pure_cmp_eq(back__p_sl_key_purify(k0), back__p_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef back__p_sl_key_cmp_ne
 #define back__p_sl_key_cmp_ne(k0, k1)       (back__p_sl_key_pure_cmp_ne(back__p_sl_key_purify(k0), back__p_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef back__p_sl_key_cmp_lt
 #define back__p_sl_key_cmp_lt(k0, k1)       (back__p_sl_key_pure_cmp_lt(back__p_sl_key_purify(k0), back__p_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef back__p_sl_key_cmp_le
 #define back__p_sl_key_cmp_le(k0, k1)       (back__p_sl_key_pure_cmp_le(back__p_sl_key_purify(k0), back__p_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef back__p_sl_key_cmp_gt
 #define back__p_sl_key_cmp_gt(k0, k1)       (back__p_sl_key_pure_cmp_gt(back__p_sl_key_purify(k0), back__p_sl_key_purify(k1)))  /* sl_macro */
#endif
#ifndef back__p_sl_key_cmp_ge
 #define back__p_sl_key_cmp_ge(k0, k1)       (back__p_sl_key_pure_cmp_ge(back__p_sl_key_purify(k0), back__p_sl_key_purify(k1)))  /* sl_macro */
#endif


/* default random key */
#ifdef back__p_sl_key_integer
# if !defined(back__p_sl_key_val_srand) || !defined(back__p_sl_key_val_rand) || !defined(back__p_sl_key_val_rand_minmax)
#  undef back__p_sl_key_val_srand
#  undef back__p_sl_key_val_rand
#  undef back__p_sl_key_val_rand_minmax
#  define back__p_sl_key_val_srand(_s_)                 z_srand(_s_)                                        /* sl_macro */
#  define back__p_sl_key_val_rand()                     ((back__p_sl_key_pure_type_c) z_rand())                     /* sl_macro */
#  define back__p_sl_key_val_rand_minmax(_min_, _max_)  ((back__p_sl_key_pure_type_c) z_rand_minmax(_min_, _max_))  /* sl_macro */
# endif
#endif


/* disable data components on request */
/* DATAX_TEMPLATE_BEGIN */
#ifdef back__p_SL_DATA0_IGNORE
# undef back__p_SL_DATA0
#endif
#ifdef back__p_SL_DATA1_IGNORE
# undef back__p_SL_DATA1
#endif
#ifdef back__p_SL_DATA2_IGNORE
# undef back__p_SL_DATA2
#endif
#ifdef back__p_SL_DATA3_IGNORE
# undef back__p_SL_DATA3
#endif
#ifdef back__p_SL_DATA4_IGNORE
# undef back__p_SL_DATA4
#endif
#ifdef back__p_SL_DATA5_IGNORE
# undef back__p_SL_DATA5
#endif
#ifdef back__p_SL_DATA6_IGNORE
# undef back__p_SL_DATA6
#endif
#ifdef back__p_SL_DATA7_IGNORE
# undef back__p_SL_DATA7
#endif
#ifdef back__p_SL_DATA8_IGNORE
# undef back__p_SL_DATA8
#endif
#ifdef back__p_SL_DATA9_IGNORE
# undef back__p_SL_DATA9
#endif
#ifdef back__p_SL_DATA10_IGNORE
# undef back__p_SL_DATA10
#endif
#ifdef back__p_SL_DATA11_IGNORE
# undef back__p_SL_DATA11
#endif
#ifdef back__p_SL_DATA12_IGNORE
# undef back__p_SL_DATA12
#endif
#ifdef back__p_SL_DATA13_IGNORE
# undef back__p_SL_DATA13
#endif
#ifdef back__p_SL_DATA14_IGNORE
# undef back__p_SL_DATA14
#endif
#ifdef back__p_SL_DATA15_IGNORE
# undef back__p_SL_DATA15
#endif
#ifdef back__p_SL_DATA16_IGNORE
# undef back__p_SL_DATA16
#endif
#ifdef back__p_SL_DATA17_IGNORE
# undef back__p_SL_DATA17
#endif
#ifdef back__p_SL_DATA18_IGNORE
# undef back__p_SL_DATA18
#endif
#ifdef back__p_SL_DATA19_IGNORE
# undef back__p_SL_DATA19
#endif
/* DATAX_TEMPLATE_END */


/* sl_macro back__p_sl_elem_weight */


/* disable sl_dataX_weight if there is not weight */
#ifndef back__p_sl_elem_weight
/* DATAX_TEMPLATE_BEGIN */
# undef back__p_sl_data0_weight
# undef back__p_sl_data1_weight
# undef back__p_sl_data2_weight
# undef back__p_sl_data3_weight
# undef back__p_sl_data4_weight
# undef back__p_sl_data5_weight
# undef back__p_sl_data6_weight
# undef back__p_sl_data7_weight
# undef back__p_sl_data8_weight
# undef back__p_sl_data9_weight
# undef back__p_sl_data10_weight
# undef back__p_sl_data11_weight
# undef back__p_sl_data12_weight
# undef back__p_sl_data13_weight
# undef back__p_sl_data14_weight
# undef back__p_sl_data15_weight
# undef back__p_sl_data16_weight
# undef back__p_sl_data17_weight
# undef back__p_sl_data18_weight
# undef back__p_sl_data19_weight
/* DATAX_TEMPLATE_END */
#endif


/* disable back__p_sl_elem_weight if the weight component is missing */
/* DATAX_TEMPLATE_BEGIN */
#if defined(back__p_sl_data0_weight) && !defined(back__p_SL_DATA0)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data1_weight) && !defined(back__p_SL_DATA1)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data2_weight) && !defined(back__p_SL_DATA2)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data3_weight) && !defined(back__p_SL_DATA3)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data4_weight) && !defined(back__p_SL_DATA4)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data5_weight) && !defined(back__p_SL_DATA5)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data6_weight) && !defined(back__p_SL_DATA6)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data7_weight) && !defined(back__p_SL_DATA7)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data8_weight) && !defined(back__p_SL_DATA8)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data9_weight) && !defined(back__p_SL_DATA9)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data10_weight) && !defined(back__p_SL_DATA10)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data11_weight) && !defined(back__p_SL_DATA11)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data12_weight) && !defined(back__p_SL_DATA12)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data13_weight) && !defined(back__p_SL_DATA13)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data14_weight) && !defined(back__p_SL_DATA14)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data15_weight) && !defined(back__p_SL_DATA15)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data16_weight) && !defined(back__p_SL_DATA16)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data17_weight) && !defined(back__p_SL_DATA17)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data18_weight) && !defined(back__p_SL_DATA18)
# undef back__p_sl_elem_weight
#endif
#if defined(back__p_sl_data19_weight) && !defined(back__p_SL_DATA19)
# undef back__p_sl_elem_weight
#endif
/* DATAX_TEMPLATE_END */


/* verify that the flex component is the last (FIXME: only if packed is on?) */
/* sl_macro back__p_FLECKS_GUARD */
/* DATAX_TEMPLATE_BEGIN */
#ifdef back__p_SL_DATA0
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data0_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA1
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data1_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA2
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data2_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA3
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data3_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA4
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data4_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA5
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data5_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA6
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data6_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA7
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data7_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA8
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data8_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA9
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data9_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA10
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data10_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA11
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data11_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA12
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data12_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA13
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data13_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA14
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data14_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA15
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data15_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA16
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data16_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA17
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data17_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA18
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data18_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
#ifdef back__p_SL_DATA19
# ifdef back__p_FLECKS_GUARD
#  error "flexible data component is not the last data component!"
# else
#  ifdef back__p_sl_data19_flex
#   define back__p_FLECKS_GUARD
#  endif
# endif
#endif
/* DATAX_TEMPLATE_END */






#ifdef sort_radix_width_default

 #ifndef sort_radix_width_max
  #define sort_radix_width_max       sort_radix_width_default
 #endif

#else /* sort_radix_width_default */

  #ifndef sort_radix_width_max
   #define sort_radix_width_max      12
  #endif

  #define sort_radix_width_default   sort_radix_width_max

#endif /* sort_radix_width_default */

#ifndef sort_radix_db_width_default
# define sort_radix_db_width_default  sort_radix_width_default
#endif

#ifndef sort_radix_ip_width_default
# define sort_radix_ip_width_default  sort_radix_width_default
#endif

#ifndef sort_radix_iter_width_default
# define sort_radix_iter_width_default  sort_radix_width_default
#endif

/* radix-sort thresholds */
#ifndef sort_radix_threshold
# define sort_radix_threshold  256
#endif

#ifndef sort_radix_ip_threshold
# define sort_radix_ip_threshold  sort_radix_threshold
#endif

#ifndef sort_radix_db_threshold
# define sort_radix_db_threshold  sort_radix_threshold
#endif

#ifndef sort_radix_iter_threshold
# define sort_radix_iter_threshold  sort_radix_threshold
#endif


#ifndef ncopy_auto_loop_border_o4o
 #define ncopy_auto_loop_border_o4o  2
#endif

#ifndef ncopy_auto_loop_border_a4o
 #define ncopy_auto_loop_border_a4o  2
#endif

#ifndef nmove_auto_loop_border_o4o
 #define nmove_auto_loop_border_o4o  2
#endif

#ifndef nmove_auto_loop_border_a4o
 #define nmove_auto_loop_border_a4o  2
#endif


/* configure tuneable */
#ifdef SL_TUNEABLE

#if 0
 /* sort_radix_threshold_rec */
 extern int tuneable_sort_radix_threshold_rec;

 /* sort_radix_threshold_iter */
 extern int tuneable_sort_radix_threshold_iter;

#endif
#endif






#ifndef SL_RTI_TID_DECLARED
# define SL_RTI_TID_DECLARED

enum rti_tid
{
  /* src/base_mpi/base_mpi.c */
  rti_tid_mpi_merge2,
  rti_tid_mpi_merge2_find,
  rti_tid_mpi_merge2_moveright,
  rti_tid_mpi_merge2_exchange,
  rti_tid_mpi_merge2_moveleft,
  rti_tid_mpi_merge2_local,
  rti_tid_mpi_mergek_equal,
  rti_tid_mpi_mergek_equal_while,
  rti_tid_mpi_mergek_equal_while_merge2,
  rti_tid_mpi_mergek_sorted,
  rti_tid_mpi_mergek_sorted_while,
  rti_tid_mpi_mergek_sorted_while_check,
  rti_tid_mpi_mergek_sorted_while_oddeven,
  rti_tid_mpi_mergek,
  rti_tid_mpi_mergek_equalike,
  rti_tid_mpi_mergek_while,
  rti_tid_mpi_mergek_while_check,
  rti_tid_mpi_mergek_while_oddeven,
  rti_tid_mpi_partition_exact_generic,
  rti_tid_mpi_partition_exact_generic_select,
  rti_tid_mpi_partition_exact_generic_rcounts,
  rti_tid_mpi_partition_exact_radix_ngroups,
  rti_tid_mpi_partition_exact_radix_ngroups_pconds,
  rti_tid_mpi_partition_exact_radix_ngroups_idxin,
  rti_tid_mpi_partition_exact_radix_ngroups_up,
  rti_tid_mpi_partition_exact_radix_ngroups_down,
  rti_tid_mpi_partition_exact_radix_ngroups_down_select,
  rti_tid_mpi_partition_exact_radix_ngroups_down_alltoall,
  rti_tid_mpi_partition_exact_radix_ngroups_down_x2suby,
  rti_tid_mpi_partition_exact_radix_ngroups_down_merge,
  rti_tid_mpi_partition_exact_radix_ngroups_idxout,
  rti_tid_mpi_partition_exact_radix_ngroups_idxout_loop,
  rti_tid_mpi_partition_exact_radix_ngroups_idxout_alltoall,
  rti_tid_mpi_partition_exact_radix_2groups,
  rti_tid_mpi_partition_exact_radix_2groups_pconds,
  rti_tid_mpi_partition_exact_radix_2groups_select1st,
  rti_tid_mpi_partition_exact_radix_2groups_x2suby,
  rti_tid_mpi_partition_exact_radix_2groups_alltoall,
  rti_tid_mpi_partition_exact_radix_2groups_select2nd,
  rti_tid_mpi_partition_exact_radix_2groups_subx2y,
  rti_tid_mpi_partition_sample,
  rti_tid_mpi_partition_sample_select,
  rti_tid_mpi_partition_sample_rcounts,
  rti_tid_mpi_select_exact_generic,
  rti_tid_mpi_select_exact_generic_sync_init,
  rti_tid_mpi_select_exact_generic_sync_exit,
  rti_tid_mpi_select_exact_generic_while,
  rti_tid_mpi_select_exact_generic_while_check,
  rti_tid_mpi_select_exact_generic_while_check_bins,
  rti_tid_mpi_select_exact_generic_while_check_bins_local,
  rti_tid_mpi_select_exact_generic_while_check_bins_global,
  rti_tid_mpi_select_exact_generic_while_check_round1,
  rti_tid_mpi_select_exact_generic_while_check_pre,
  rti_tid_mpi_select_exact_generic_while_check_part,
  rti_tid_mpi_select_exact_generic_while_check_part_root,
  rti_tid_mpi_select_exact_generic_while_check_final,
  rti_tid_mpi_select_exact_generic_while_check_final_root,
  rti_tid_mpi_select_exact_generic_while_check_post,


  rti_tid_all,
  rti_tid_sort_insert,
  rti_tid_sort_quick,
  rti_tid_sort_radix,
  rti_tid_sort_radix_iter,
  rti_tid_sort_permute_forward,
  rti_tid_sort_permute_backward,

  rti_tid_mpi_all,

  rti_tid_mpi_merge2_fe,
  rti_tid_mpi_merge2_xchg,

  rti_tid_mpi_mergek_merge2,

  rti_tid_mpi_splitk_exact,
  rti_tid_mpi_splitk_exact_init,
  rti_tid_mpi_splitk_exact_loop,
  rti_tid_mpi_splitk_exact_loop_walk,
  rti_tid_mpi_splitk_exact_loop_flow,
  rti_tid_mpi_splitk_exact_loop_flow_gather,
  rti_tid_mpi_splitk_exact_loop_flow_create,
  rti_tid_mpi_splitk_exact_loop_flow_reduce,
  rti_tid_mpi_splitk_exact_loop_flow_unbalance,
  rti_tid_mpi_splitk_exact_loop_dist,
  rti_tid_mpi_splitk_exact_loop_dist_pre,
  rti_tid_mpi_splitk_exact_loop_dist_a2av,

  rti_tid_mpi_splitk_dummy,
  rti_tid_mpi_splitk_dummy_init,
  rti_tid_mpi_splitk_dummy_loop,

  rti_tid_mpi_partition_joink,
  rti_tid_mpi_partition_joink_init,
  rti_tid_mpi_partition_joink_loop,
  rti_tid_mpi_partition_joink_loop_flow,
  rti_tid_mpi_partition_joink_loop_dist,

  rti_tid_mpi_select_radix_final,

  rti_tid_mpi_partition_radix2,
  rti_tid_mpi_partition_radix2_sync,
  rti_tid_mpi_partition_radix2_sync_init,
  rti_tid_mpi_partition_radix2_sync_exit,
/*  rti_tid_mpi_partition_radix2_while,
  rti_tid_mpi_partition_radix2_while_count,
  rti_tid_mpi_partition_radix2_while_allreduce,
  rti_tid_mpi_partition_radix2_while_round1,
  rti_tid_mpi_partition_radix2_while_round1_allgather,
  rti_tid_mpi_partition_radix2_while_exscan,
  rti_tid_mpi_partition_radix2_while_check,
  rti_tid_mpi_partition_radix2_while_check_pre,
  rti_tid_mpi_partition_radix2_while_check_classes,
  rti_tid_mpi_partition_radix2_while_check_final,
  rti_tid_mpi_partition_radix2_while_check_post,*/
  rti_tid_mpi_partition_radix2_final,

  rti_tid_mpi_sample_complete,
  rti_tid_mpi_sample_complete_gather,
  rti_tid_mpi_sample_complete_detect,
  rti_tid_mpi_sample_complete_bcast,

  rti_tid_mpi_select_qs,
  rti_tid_mpi_select_qs_pre,
  rti_tid_mpi_select_qs_loop,
  rti_tid_mpi_select_qs_part,
  rti_tid_mpi_select_qs_reduce_sizes,
  rti_tid_mpi_select_qs_area,
  rti_tid_mpi_select_qs_pivot_new,
  rti_tid_mpi_select_qs_pivot_gather,
  rti_tid_mpi_select_qs_pivot_detect,

  rti_tid_mpi_sample_select_qs,
  rti_tid_mpi_sample_select_qs_pre,
  rti_tid_mpi_sample_select_qs_select,

  rti_tid_mpi_sample_precise,
  rti_tid_mpi_sample_precise_llec,
  rti_tid_mpi_sample_precise_gather,
  rti_tid_mpi_sample_precise_detect,

  rti_tid_mpi_sample_permutation,

  rti_tid_mpi_sm_simple,
  rti_tid_mpi_sm_simple_sort,
  rti_tid_mpi_sm_simple_merge,

  rti_tids
};

#endif /* SL_RTI_TID_DECLARED */






#define back__p_SPEC_TLOC

typedef back__p_sl_int_type_c back__p_spec_int_t;

typedef int back__p_spec_proc_t;

#define back__p_SPEC_LOC_NONE   -1
#define back__p_SPEC_PROC_NONE  MPI_PROC_NULL

typedef void *back__p_spec_tloc_data_t;
typedef void *back__p_spec_tproc_data_t;

struct back__p__elements_t;

typedef struct back__p__elements_t *back__p_spec_elem_buf_t;

typedef struct back__p__elements_t back__p_spec_elem_t;

typedef back__p_sl_int_type_c back__p_spec_elem_index_t;

#define back__p_spec_elem_set_n(_e_, _n_)     back__p_elem_set_size((_e_), (_n_))
#define back__p_spec_elem_get_n(_e_)          back__p_elem_get_size((_e_))
#define back__p_spec_elem_set_nmax(_e_, _n_)  back__p_elem_set_max_size((_e_), (_n_))
#define back__p_spec_elem_get_nmax(_e_)       back__p_elem_get_max_size((_e_))

#define back__p_spec_elem_set_buf(_e_, _b_)   *(_e_) = *(_b_)
#define back__p_spec_elem_get_buf(_e_)        (_e_)

#define back__p_spec_elem_copy_at(_se_, _sat_, _de_, _dat_) \
  elem_copy_at((_se_), (_sat_), (_de_), (_dat_))

#define back__p_spec_elem_exchange_at(_s0_, _s0at_, _s1_, _s1at_, _t_) \
  elem_xchange_at((_s0_), (_s0at_), (_s1_), (_s1at_), (_t_))






/* tproc count */

/* sp_macro back__p_SPEC_DECLARE_TPROC_COUNT_DB */
#define back__p_SPEC_DECLARE_TPROC_COUNT_DB \
  struct { back__p_spec_elem_index_t i; back__p_spec_proc_t p; } spec0cd;

/* sp_macro back__p_SPEC_DO_TPROC_COUNT_DB */
#define back__p_SPEC_DO_TPROC_COUNT_DB(_tp_, _tpd_, _b_, _cs_)  do { \
  for (spec0cd.i = 0; spec0cd.i < back__p_spec_elem_get_n(_b_); ++spec0cd.i) { \
    spec0cd.p = (_tp_)(back__p_spec_elem_get_buf(_b_), spec0cd.i, _tpd_); \
    if (spec0cd.p == back__p_SPEC_PROC_NONE) continue; \
    ++(_cs_)[spec0cd.p]; \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROC_COUNT_DB */
#define back__p_SPEC_FUNC_TPROC_COUNT_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_count_db(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts) \
{ \
  back__p_SPEC_DECLARE_TPROC_COUNT_DB \
  back__p_SPEC_DO_TPROC_COUNT_DB(_tp_, tproc_data, s, counts); \
}

/* sp_macro back__p_SPEC_DECLARE_TPROC_COUNT_IP */
#define back__p_SPEC_DECLARE_TPROC_COUNT_IP \
  struct { back__p_spec_elem_index_t i, t; back__p_spec_proc_t p; } spec0ci;

/* sp_macro back__p_SPEC_DO_TPROC_COUNT_IP */
#define back__p_SPEC_DO_TPROC_COUNT_IP(_tp_, _tpd_, _b_, _cs_)  do { \
  spec0ci.t = 0; \
  for (spec0ci.i = 0; spec0ci.i < back__p_spec_elem_get_n(_b_); ++spec0ci.i) { \
    spec0ci.p = (_tp_)(back__p_spec_elem_get_buf(_b_), spec0ci.i, _tpd_); \
    if (spec0ci.p == back__p_SPEC_PROC_NONE) continue; \
    ++(_cs_)[spec0ci.p]; \
    if (spec0ci.t < spec0ci.i) back__p_spec_elem_copy_at((_b_), spec0ci.i, (_b_), spec0ci.t); \
    ++spec0ci.t; \
  } \
  back__p_spec_elem_set_n(_b_, spec0ci.t); \
} while (0)

/* sp_macro back__p_SPEC_FUNC_TPROC_COUNT_IP */
#define back__p_SPEC_FUNC_TPROC_COUNT_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_count_ip(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts) \
{ \
  back__p_SPEC_DECLARE_TPROC_COUNT_IP \
  back__p_SPEC_DO_TPROC_COUNT_IP(_tp_, tproc_data, s, counts); \
}


/* tproc_mod count */

/* sp_macro back__p_SPEC_DECLARE_TPROC_MOD_COUNT_DB */
#define back__p_SPEC_DECLARE_TPROC_MOD_COUNT_DB \
  struct { back__p_spec_elem_index_t i; back__p_spec_proc_t p; } spec1cd;

/* sp_macro back__p_SPEC_DO_TPROC_MOD_COUNT_DB */
#define back__p_SPEC_DO_TPROC_MOD_COUNT_DB(_tp_, _tpd_, _b_, _cs_)  do { \
  for (spec1cd.i = 0; spec1cd.i < back__p_spec_elem_get_n(_b_); ++spec1cd.i) { \
    spec1cd.p = (_tp_)(back__p_spec_elem_get_buf(_b_), spec1cd.i, _tpd_, NULL); \
    if (spec1cd.p == back__p_SPEC_PROC_NONE) continue; \
    ++(_cs_)[spec1cd.p]; \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROC_MOD_COUNT_DB */
#define back__p_SPEC_FUNC_TPROC_MOD_COUNT_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_mod_count_db(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts) \
{ \
  back__p_SPEC_DECLARE_TPROC_MOD_COUNT_DB \
  back__p_SPEC_DO_TPROC_MOD_COUNT_DB(_tp_, tproc_data, s, counts); \
}

/* sp_macro back__p_SPEC_DECLARE_TPROC_MOD_COUNT_IP */
#define back__p_SPEC_DECLARE_TPROC_MOD_COUNT_IP \
  struct { back__p_spec_elem_index_t i, t; back__p_spec_proc_t p; } spec1ci;

/* sp_macro back__p_SPEC_DO_TPROC_MOD_COUNT_IP */
#define back__p_SPEC_DO_TPROC_MOD_COUNT_IP(_tp_, _tpd_, _b_, _cs_)  do { \
  spec1ci.t = 0; \
  for (spec1ci.i = 0; spec1ci.i < back__p_spec_elem_get_n(_b_); ++spec1ci.i) { \
    spec1ci.p = (_tp_)(back__p_spec_elem_get_buf(_b_), spec1ci.i, _tpd_, NULL); \
    if (spec1ci.p == back__p_SPEC_PROC_NONE) continue; \
    ++(_cs_)[spec1ci.p]; \
    if (spec1ci.t < spec1ci.i) back__p_spec_elem_copy_at((_b_), spec1ci.i, (_b_), spec1ci.t); \
    ++spec1ci.t; \
  } \
  back__p_spec_elem_set_n(_b_, spec1ci.t); \
} while (0)

/* sp_macro back__p_SPEC_FUNC_TPROC_MOD_COUNT_IP */
#define back__p_SPEC_FUNC_TPROC_MOD_COUNT_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_mod_count_ip(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts) \
{ \
  back__p_SPEC_DECLARE_TPROC_MOD_COUNT_IP \
  back__p_SPEC_DO_TPROC_MOD_COUNT_IP(_tp_, tproc_data, s, counts); \
}


/* tprocs count */

/* sp_macro back__p_SPEC_DECLARE_TPROCS_COUNT_DB */
#define back__p_SPEC_DECLARE_TPROCS_COUNT_DB \
  struct { back__p_spec_elem_index_t i; back__p_spec_int_t j, n; } spec2cd;

/* sp_macro back__p_SPEC_DO_TPROCS_COUNT_DB */
#define back__p_SPEC_DO_TPROCS_COUNT_DB(_tp_, _tpd_, _b_, _cs_, _ps_)  do { \
  for (spec2cd.i = 0; spec2cd.i < back__p_spec_elem_get_n(_b_); ++spec2cd.i) { \
    spec2cd.n = (_tp_)(back__p_spec_elem_get_buf(_b_), spec2cd.i, (_tpd_), (_ps_)); \
    for (spec2cd.j = 0; spec2cd.j < spec2cd.n; ++spec2cd.j) ++(_cs_)[(_ps_)[spec2cd.j]]; \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROCS_COUNT_DB */
#define back__p_SPEC_FUNC_TPROCS_COUNT_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_count_db(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts, back__p_spec_proc_t *procs) \
{ \
  back__p_SPEC_DECLARE_TPROCS_COUNT_DB \
  back__p_SPEC_DO_TPROCS_COUNT_DB(_tp_, tproc_data, s, counts, procs); \
}

/* sp_macro back__p_SPEC_DECLARE_TPROCS_COUNT_IP */
#define back__p_SPEC_DECLARE_TPROCS_COUNT_IP \
  struct { back__p_spec_elem_index_t i, t; back__p_spec_int_t j, n; } spec2ci;

/* sp_macro back__p_SPEC_DO_TPROCS_COUNT_IP */
#define back__p_SPEC_DO_TPROCS_COUNT_IP(_tp_, _tpd_, _b_, _cs_, _ps_)  do { \
  spec2ci.t = 0; \
  for (spec2ci.i = 0; spec2ci.i < back__p_spec_elem_get_n(_b_); ++spec2ci.i) { \
    spec2ci.n = (_tp_)(back__p_spec_elem_get_buf(_b_), spec2ci.i, (_tpd_), (_ps_)); \
    if (spec2ci.n <= 0) continue; \
    for (spec2ci.j = 0; spec2ci.j < spec2ci.n; ++spec2ci.j) ++(_cs_)[(_ps_)[spec2ci.j]]; \
    if (spec2ci.t < spec2ci.i) back__p_spec_elem_copy_at((_b_), spec2ci.i, (_b_), spec2ci.t); \
    ++spec2ci.t; \
  } \
  back__p_spec_elem_set_n(_b_, spec2ci.t); \
} while (0)

/* sp_macro back__p_SPEC_FUNC_TPROCS_COUNT_IP */
#define back__p_SPEC_FUNC_TPROCS_COUNT_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_count_ip(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts, back__p_spec_proc_t *procs) \
{ \
  back__p_SPEC_DECLARE_TPROCS_COUNT_IP \
  back__p_SPEC_DO_TPROCS_COUNT_IP(_tp_, tproc_data, s, counts, procs); \
}


/* tprocs_mod count */

/* sp_macro back__p_SPEC_DECLARE_TPROCS_MOD_COUNT_DB */
#define back__p_SPEC_DECLARE_TPROCS_MOD_COUNT_DB \
  struct { back__p_spec_elem_index_t i; back__p_spec_int_t j, n; } spec3cd;

/* sp_macro back__p_SPEC_DO_TPROCS_MOD_COUNT_DB */
#define back__p_SPEC_DO_TPROCS_MOD_COUNT_DB(_tp_, _tpd_, _b_, _cs_, _ps_)  do { \
  for (spec3cd.i = 0; spec3cd.i < back__p_spec_elem_get_n(_b_); ++spec3cd.i) \
  { \
    spec3cd.n = (_tp_)(back__p_spec_elem_get_buf(_b_), spec3cd.i, (_tpd_), (_ps_), NULL); \
    for (spec3cd.j = 0; spec3cd.j < spec3cd.n; ++spec3cd.j) ++(_cs_)[(_ps_)[spec3cd.j]]; \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROCS_MOD_COUNT_DB */
#define back__p_SPEC_FUNC_TPROCS_MOD_COUNT_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_mod_count_db(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts, back__p_spec_proc_t *procs) \
{ \
  back__p_SPEC_DECLARE_TPROCS_MOD_COUNT_DB \
  back__p_SPEC_DO_TPROCS_MOD_COUNT_DB(_tp_, tproc_data, s, counts, procs); \
}

/* sp_macro back__p_SPEC_DECLARE_TPROCS_MOD_COUNT_IP */
#define back__p_SPEC_DECLARE_TPROCS_MOD_COUNT_IP \
  struct { back__p_spec_elem_index_t i, t; back__p_spec_int_t j, n; } spec3ci;

/* sp_macro back__p_SPEC_DO_TPROCS_MOD_COUNT_IP */
#define back__p_SPEC_DO_TPROCS_MOD_COUNT_IP(_tp_, _tpd_, _b_, _cs_, _ps_)  do { \
  spec3ci.t = 0; \
  for (spec3ci.i = 0; spec3ci.i < back__p_spec_elem_get_n(_b_); ++spec3ci.i) { \
    spec3ci.n = (_tp_)(back__p_spec_elem_get_buf(_b_), spec3ci.i, (_tpd_), (_ps_), NULL); \
    if (spec3ci.n <= 0) continue; \
    for (spec3ci.j = 0; spec3ci.j < spec3ci.n; ++spec3ci.j) ++(_cs_)[(_ps_)[spec3ci.j]]; \
    if (spec3ci.t < spec3ci.i) back__p_spec_elem_copy_at((_b_), spec3ci.i, (_b_), spec3ci.t); \
    ++spec3ci.t; \
  } \
  back__p_spec_elem_set_n(_b_, spec3ci.t); \
} while (0)

/* sp_macro back__p_SPEC_FUNC_TPROCS_MOD_COUNT_IP */
#define back__p_SPEC_FUNC_TPROCS_MOD_COUNT_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_mod_count_ip(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts, back__p_spec_proc_t *procs) \
{ \
  back__p_SPEC_DECLARE_TPROCS_MOD_COUNT_IP \
  back__p_SPEC_DO_TPROCS_MOD_COUNT_IP(_tp_, tproc_data, s, counts, procs); \
}


/* tproc rearrange */

/* sp_macro back__p_SPEC_DECLARE_TPROC_REARRANGE_DB */
#define back__p_SPEC_DECLARE_TPROC_REARRANGE_DB \
  struct { back__p_spec_elem_index_t i; back__p_spec_proc_t p; } spec0d;

/* sp_macro back__p_SPEC_DO_TPROC_REARRANGE_DB */
#define back__p_SPEC_DO_TPROC_REARRANGE_DB(_tp_, _tpd_, _sb_, _db_, _ds_)  do { \
  for (spec0d.i = 0; spec0d.i < back__p_spec_elem_get_n(_sb_); ++spec0d.i) { \
    spec0d.p = (_tp_)(back__p_spec_elem_get_buf(_sb_), spec0d.i, _tpd_); \
    if (spec0d.p == back__p_SPEC_PROC_NONE) continue; \
    back__p_spec_elem_copy_at((_sb_), spec0d.i, (_db_), (_ds_)[spec0d.p]); \
    ++(_ds_)[spec0d.p]; \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROC_REARRANGE_DB */
#define back__p_SPEC_FUNC_TPROC_REARRANGE_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_rearrange_db(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tproc_data_t tproc_data, int *displs) \
{ \
  back__p_SPEC_DECLARE_TPROC_REARRANGE_DB \
  back__p_SPEC_DO_TPROC_REARRANGE_DB(_tp_, tproc_data, s, d, displs); \
}

/* sp_macro back__p_SPEC_DECLARE_TPROC_REARRANGE_IP */
#define back__p_SPEC_DECLARE_TPROC_REARRANGE_IP \
  struct { back__p_spec_elem_index_t e, i, j; back__p_spec_proc_t p, np; } spec0i;

/* sp_macro back__p_SPEC_DO_TPROC_REARRANGE_IP */
#define back__p_SPEC_DO_TPROC_REARRANGE_IP(_tp_, _tpd_, _b_, _xb_, _ds_, _cs_, _n_)  do { \
  for (spec0i.e = 0, spec0i.i = 0; spec0i.i < (_n_); ++spec0i.i) { \
    spec0i.e += (_cs_)[spec0i.i]; \
    spec0i.j = (_ds_)[spec0i.i]; \
    while (spec0i.j < spec0i.e) { \
      spec0i.p = (_tp_)(back__p_spec_elem_get_buf(_b_), spec0i.j, _tpd_); \
      while (spec0i.p != spec0i.i) { \
        spec0i.np = (_tp_)(back__p_spec_elem_get_buf(_b_), (_ds_)[spec0i.p], _tpd_); \
        if (spec0i.np != spec0i.p) back__p_spec_elem_exchange_at((_b_), (_ds_)[spec0i.p], (_b_), spec0i.j, (_xb_)); \
        ++(_ds_)[spec0i.p]; \
        spec0i.p = spec0i.np; \
      } \
      ++spec0i.j; \
    } \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROC_REARRANGE_IP */
#define back__p_SPEC_FUNC_TPROC_REARRANGE_IP(_name_, _tp_, _s_) \
_s_ void _name_##_tproc_rearrange_ip(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tproc_data_t tproc_data, int *displs, int *counts, back__p_spec_int_t n) \
{ \
  back__p_SPEC_DECLARE_TPROC_REARRANGE_IP \
  back__p_SPEC_DO_TPROC_REARRANGE_IP(_tp_, tproc_data, s, x, displs, counts, n); \
}


/* tproc_mod rearrange */

/* sp_macro back__p_SPEC_DECLARE_TPROC_MOD_REARRANGE_DB */
#define back__p_SPEC_DECLARE_TPROC_MOD_REARRANGE_DB \
  struct { back__p_spec_elem_index_t i; back__p_spec_proc_t p; } spec1d;

/* sp_macro back__p_SPEC_DO_TPROC_MOD_REARRANGE_DB */
#define back__p_SPEC_DO_TPROC_MOD_REARRANGE_DB(_tp_, _tpd_, _sb_, _db_, _ds_, _ib_)  do { \
  if (_ib_) { \
    for (spec1d.i = 0; spec1d.i < back__p_spec_elem_get_n(_sb_); ++spec1d.i) { \
      spec1d.p = (_tp_)(back__p_spec_elem_get_buf(_sb_), spec1d.i, _tpd_, back__p_spec_elem_get_buf(_ib_)); \
      if (spec1d.p == back__p_SPEC_PROC_NONE) continue; \
      back__p_spec_elem_copy_at((_ib_), 0, (_db_), (_ds_)[spec1d.p]); \
      ++(_ds_)[spec1d.p]; \
    } \
  } else { \
    for (spec1d.i = 0; spec1d.i < back__p_spec_elem_get_n(_sb_); ++spec1d.i) { \
      spec1d.p = (_tp_)(back__p_spec_elem_get_buf(_sb_), spec1d.i, _tpd_, NULL); \
      if (spec1d.p == back__p_SPEC_PROC_NONE) continue; \
      back__p_spec_elem_copy_at((_sb_), spec1d.i, (_db_), (_ds_)[spec1d.p]); \
      ++(_ds_)[spec1d.p]; \
    } \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROC_MOD_REARRANGE_DB */
#define back__p_SPEC_FUNC_TPROC_MOD_REARRANGE_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tproc_mod_rearrange_db(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tproc_data_t tproc_data, int *displs, back__p_spec_elem_t *mod) \
{ \
  back__p_SPEC_DECLARE_TPROC_MOD_REARRANGE_DB \
  back__p_SPEC_DO_TPROC_MOD_REARRANGE_DB(_tp_, tproc_data, s, d, displs, mod); \
}

/* sp_macro back__p_SPEC_DECLARE_TPROC_MOD_REARRANGE_IP */
#define back__p_SPEC_DECLARE_TPROC_MOD_REARRANGE_IP \
  struct { back__p_spec_elem_index_t e, i, j; back__p_spec_proc_t p, np; } spec1i;

/* sp_macro back__p_SPEC_DO_TPROC_MOD_REARRANGE_IP */
#define back__p_SPEC_DO_TPROC_MOD_REARRANGE_IP(_tp_, _tpd_, _b_, _xb_, _ds_, _cs_, _n_, _ib_)  do { \
  if (_ib_) { \
    for (spec1i.e = 0, spec1i.i = 0; spec1i.i < (_n_); ++spec1i.i) { \
      spec1i.e += (_cs_)[spec1i.i]; \
      spec1i.j = (_ds_)[spec1i.i]; \
      while (spec1i.j < spec1i.e) { \
        spec1i.p = (_tp_)(back__p_spec_elem_get_buf(_b_), spec1i.j, _tpd_, back__p_spec_elem_get_buf(_ib_)); \
        back__p_spec_elem_copy_at((_ib_), 0, (_b_), spec1i.j); \
        while (spec1i.p != spec1i.i) { \
          spec1i.np = (_tp_)(back__p_spec_elem_get_buf(_b_), (_ds_)[spec1i.p], _tpd_, back__p_spec_elem_get_buf(_ib_)); \
          if (spec1i.np != spec1i.p) { \
            back__p_spec_elem_copy_at((_b_), spec1i.j, (_b_), (_ds_)[spec1i.p]); \
            back__p_spec_elem_copy_at((_ib_), 0, (_b_), spec1i.j); \
          } else back__p_spec_elem_copy_at((_ib_), 0, (_b_), (_ds_)[spec1i.p]); \
          ++(_ds_)[spec1i.p]; \
          spec1i.p = spec1i.np; \
        } \
        ++spec1i.j; \
      } \
    } \
  } else { \
    for (spec1i.e = 0, spec1i.i = 0; spec1i.i < (_n_); ++spec1i.i) { \
      spec1i.e += (_cs_)[spec1i.i]; \
      spec1i.j = (_ds_)[spec1i.i]; \
      while (spec1i.j < spec1i.e) { \
        spec1i.p = (_tp_)(back__p_spec_elem_get_buf(_b_), spec1i.j, _tpd_, NULL); \
        while (spec1i.p != spec1i.i) { \
          spec1i.np = (_tp_)(back__p_spec_elem_get_buf(_b_), (_ds_)[spec1i.p], _tpd_, NULL); \
          if (spec1i.np != spec1i.p) back__p_spec_elem_exchange_at((_b_), (_ds_)[spec1i.p], (_b_), spec1i.j, (_xb_)); \
          ++(_ds_)[spec1i.p]; \
          spec1i.p = spec1i.np; \
        } \
        ++spec1i.j; \
      } \
    } \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROC_MOD_REARRANGE_IP */
#define back__p_SPEC_FUNC_TPROC_MOD_REARRANGE_IP(_name_, _tp_, _s_) \
_s_ void _name_##_tproc_mod_rearrange_ip(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tproc_data_t tproc_data, int *displs, int *counts, back__p_spec_int_t n, back__p_spec_elem_t *mod) \
{ \
  back__p_SPEC_DECLARE_TPROC_MOD_REARRANGE_IP \
  back__p_SPEC_DO_TPROC_MOD_REARRANGE_IP(_tp_, tproc_data, s, x, displs, counts, n, mod); \
}


/* tprocs rearrange */

/* sp_macro back__p_SPEC_DECLARE_TPROCS_REARRANGE_DB */
#define back__p_SPEC_DECLARE_TPROCS_REARRANGE_DB \
  struct { back__p_spec_elem_index_t i; back__p_spec_int_t j, n; } spec2d;

/* sp_macro back__p_SPEC_DO_TPROCS_REARRANGE_DB */
#define back__p_SPEC_DO_TPROCS_REARRANGE_DB(_tp_, _tpd_, _sb_, _db_, _ds_, _ps_)  do { \
  for (spec2d.i = 0; spec2d.i < back__p_spec_elem_get_n(_sb_); ++spec2d.i) { \
    spec2d.n = (_tp_)(back__p_spec_elem_get_buf(_sb_), spec2d.i, (_tpd_), (_ps_)); \
    for (spec2d.j = 0; spec2d.j < spec2d.n; ++spec2d.j) { \
      back__p_spec_elem_copy_at((_sb_), spec2d.i, (_db_), (_ds_)[(_ps_)[spec2d.j]]); \
      ++(_ds_)[(_ps_)[spec2d.j]]; \
    } \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROCS_REARRANGE_DB */
#define back__p_SPEC_FUNC_TPROCS_REARRANGE_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_rearrange_db(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tproc_data_t tproc_data, int *displs, back__p_spec_proc_t *procs) \
{ \
  back__p_SPEC_DECLARE_TPROCS_REARRANGE_DB \
  back__p_SPEC_DO_TPROCS_REARRANGE_DB(_tp_, tproc_data, s, d, displs, procs); \
}

/* sp_macro back__p_SPEC_DECLARE_TPROCS_REARRANGE_IP */
#define back__p_SPEC_DECLARE_TPROCS_REARRANGE_IP \
  struct { back__p_spec_elem_index_t e, j, fe, fc, le, lc; back__p_spec_int_t i, n, f, l, o; } spec2i;

/* sp_macro back__p_SPEC_DO_TPROCS_REARRANGE_IP */
#define back__p_SPEC_DO_TPROCS_REARRANGE_IP(_tp_, _tpd_, _b_, _xb_, _ds_, _cs_, _n_, _ps_)  do { \
  spec2i.f = 0; spec2i.fe = (_cs_)[0]; spec2i.fc = back__p_spec_elem_get_n(_b_); \
  while (spec2i.f + 1 < (_n_) && spec2i.fc >= spec2i.fe) { ++spec2i.f; spec2i.fe += (_cs_)[spec2i.f]; } \
  spec2i.l = 0; spec2i.le = (_cs_)[0]; spec2i.lc = back__p_spec_elem_get_n(_b_) - 1; \
  while (spec2i.lc >= spec2i.le) { ++spec2i.l; spec2i.le += (_cs_)[spec2i.l]; } \
  for (spec2i.e = 0, spec2i.i = 0; spec2i.i < (_n_); ++spec2i.i) { \
    spec2i.e += (_cs_)[spec2i.i]; \
    spec2i.j = (_ds_)[spec2i.i]; \
    while (spec2i.j < spec2i.e) { \
      spec2i.n = (_tp_)(back__p_spec_elem_get_buf(_b_), spec2i.j, (_tpd_), (_ps_)); \
      spec2i.o = -1; \
      while (spec2i.n > 0) { \
        --spec2i.n; \
        if ((_ps_)[spec2i.n] == spec2i.i && spec2i.o < 0) spec2i.o = spec2i.n; \
        else if ((_ds_)[(_ps_)[spec2i.n]] < spec2i.fc) { \
          spec2i.l = spec2i.f; spec2i.le = spec2i.fe; spec2i.lc = spec2i.fc; \
          if (spec2i.fc < spec2i.fe) { \
            back__p_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec2i.n]], (_b_), spec2i.fc); \
            ++spec2i.fc; \
          } else back__p_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec2i.n]], (_xb_), 0); \
        } else if ((_ds_)[(_ps_)[spec2i.n]] == spec2i.fc) ++spec2i.fc; \
        if (spec2i.j != (_ds_)[(_ps_)[spec2i.n]]) back__p_spec_elem_copy_at((_b_), spec2i.j, (_b_), (_ds_)[(_ps_)[spec2i.n]]); \
        ++(_ds_)[(_ps_)[spec2i.n]]; \
        while (spec2i.f + 1 < (_n_) && spec2i.fc >= spec2i.fe) { ++spec2i.f; spec2i.fe += (_cs_)[spec2i.f]; spec2i.fc = (_ds_)[spec2i.f]; } \
      } \
      if (spec2i.o < 0) { \
        if (spec2i.lc < spec2i.le) {  \
          back__p_spec_elem_copy_at((_b_), spec2i.lc, (_b_), spec2i.j); \
          spec2i.f = spec2i.l; spec2i.fe = spec2i.le; spec2i.fc = spec2i.lc; \
          --spec2i.lc; \
          while (spec2i.l > 0 && spec2i.lc < (_ds_)[spec2i.l]) { spec2i.le -= (_cs_)[spec2i.l]; spec2i.lc = spec2i.le - 1; --spec2i.l; } \
        } else back__p_spec_elem_copy_at((_xb_), 0, (_b_), spec2i.j); \
      } \
      spec2i.j = (_ds_)[spec2i.i]; \
    } \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROCS_REARRANGE_IP */
#define back__p_SPEC_FUNC_TPROCS_REARRANGE_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_rearrange_ip(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tproc_data_t tproc_data, int *displs, int *counts, back__p_spec_int_t n, back__p_spec_proc_t *procs) \
{ \
  back__p_SPEC_DECLARE_TPROCS_REARRANGE_IP \
  back__p_SPEC_DO_TPROCS_REARRANGE_IP(_tp_, tproc_data, s, d, displs, counts, n, procs); \
}


/* tprocs_mod rearrange */

/* sp_macro back__p_SPEC_DECLARE_TPROCS_MOD_REARRANGE_DB */
#define back__p_SPEC_DECLARE_TPROCS_MOD_REARRANGE_DB \
  struct { back__p_spec_elem_index_t i; back__p_spec_int_t j, n; } spec3d;

/* sp_macro back__p_SPEC_DO_TPROCS_MOD_REARRANGE_DB */
#define back__p_SPEC_DO_TPROCS_MOD_REARRANGE_DB(_tp_, _tpd_, _sb_, _db_, _ds_, _ps_, _ib_)  do { \
  if (_ib_) { \
    for (spec3d.i = 0; spec3d.i < back__p_spec_elem_get_n(_sb_); ++spec3d.i) { \
      spec3d.n = (_tp_)(back__p_spec_elem_get_buf(_sb_), spec3d.i, (_tpd_), (_ps_), back__p_spec_elem_get_buf(_ib_)); \
      for (spec3d.j = 0; spec3d.j < spec3d.n; ++spec3d.j) { \
        back__p_spec_elem_copy_at((_ib_), spec3d.j, (_db_), (_ds_)[(_ps_)[spec3d.j]]); \
        ++(_ds_)[(_ps_)[spec3d.j]]; \
      } \
    } \
  } else { \
    for (spec3d.i = 0; spec3d.i < back__p_spec_elem_get_n(_sb_); ++spec3d.i) { \
      spec3d.n = (_tp_)(back__p_spec_elem_get_buf(_sb_), spec3d.i, (_tpd_), (_ps_), NULL); \
      for (spec3d.j = 0; spec3d.j < spec3d.n; ++spec3d.j) { \
        back__p_spec_elem_copy_at((_sb_), spec3d.i, (_db_), (_ds_)[(_ps_)[spec3d.j]]); \
        ++(_ds_)[(_ps_)[spec3d.j]]; \
      } \
    } \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROCS_MOD_REARRANGE_DB */
#define back__p_SPEC_FUNC_TPROCS_MOD_REARRANGE_DB(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_mod_rearrange_db(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tproc_data_t tproc_data, int *displs, back__p_spec_proc_t *procs, back__p_spec_elem_t *mod) \
{ \
  back__p_SPEC_DECLARE_TPROCS_MOD_REARRANGE_DB \
  back__p_SPEC_DO_TPROCS_MOD_REARRANGE_DB(_tp_, tproc_data, s, d, displs, procs, mod); \
}

/* sp_macro back__p_SPEC_DECLARE_TPROCS_MOD_REARRANGE_IP */
#define back__p_SPEC_DECLARE_TPROCS_MOD_REARRANGE_IP \
  struct { back__p_spec_elem_index_t e, j, fe, fc, le, lc; back__p_spec_int_t i, n, f, l, o; } spec3i;

/* sp_macro back__p_SPEC_DO_TPROCS_MOD_REARRANGE_IP */
#define back__p_SPEC_DO_TPROCS_MOD_REARRANGE_IP(_tp_, _tpd_, _b_, _xb_, _ds_, _cs_, _n_, _ps_, _ib_)  do { \
  if (_ib_) { \
    spec3i.f = 0; spec3i.fe = (_cs_)[0]; spec3i.fc = back__p_spec_elem_get_n(_b_); \
    while (spec3i.f + 1 < (_n_) && spec3i.fc >= spec3i.fe) { ++spec3i.f; spec3i.fe += (_cs_)[spec3i.f]; } \
    spec3i.l = 0; spec3i.le = (_cs_)[0]; spec3i.lc = back__p_spec_elem_get_n(_b_) - 1; \
    while (spec3i.lc >= spec3i.le) { ++spec3i.l; spec3i.le += (_cs_)[spec3i.l]; } \
    for (spec3i.e = 0, spec3i.i = 0; spec3i.i < (_n_); ++spec3i.i) { \
      spec3i.e += (_cs_)[spec3i.i]; \
      spec3i.j = (_ds_)[spec3i.i]; \
      while (spec3i.j < spec3i.e) { \
        spec3i.n = (_tp_)(back__p_spec_elem_get_buf(_b_), spec3i.j, (_tpd_), (_ps_), back__p_spec_elem_get_buf(_ib_)); \
        spec3i.o = -1; \
        while (spec3i.n > 0) { \
          --spec3i.n; \
          if ((_ps_)[spec3i.n] == spec3i.i && spec3i.o < 0) spec3i.o = spec3i.n; \
          else if ((_ds_)[(_ps_)[spec3i.n]] < spec3i.fc) { \
            spec3i.l = spec3i.f; spec3i.le = spec3i.fe; spec3i.lc = spec3i.fc; \
            if (spec3i.fc < spec3i.fe) { \
              back__p_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec3i.n]], (_b_), spec3i.fc); \
              ++spec3i.fc; \
            } else back__p_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec3i.n]], (_xb_), 0); \
          } else if ((_ds_)[(_ps_)[spec3i.n]] == spec3i.fc) ++spec3i.fc; \
          back__p_spec_elem_copy_at((_ib_), spec3i.n, (_b_), (_ds_)[(_ps_)[spec3i.n]]); \
          ++(_ds_)[(_ps_)[spec3i.n]]; \
          while (spec3i.f + 1 < (_n_) && spec3i.fc >= spec3i.fe) { ++spec3i.f; spec3i.fe += (_cs_)[spec3i.f]; spec3i.fc = (_ds_)[spec3i.f]; } \
        } \
        if (spec3i.o < 0) { \
          if (spec3i.lc < spec3i.le) {  \
            back__p_spec_elem_copy_at((_b_), spec3i.lc, (_b_), spec3i.j); \
            spec3i.f = spec3i.l; spec3i.fe = spec3i.le; spec3i.fc = spec3i.lc; \
            --spec3i.lc; \
            while (spec3i.l > 0 && spec3i.lc < (_ds_)[spec3i.l]) { spec3i.le -= (_cs_)[spec3i.l]; spec3i.lc = spec3i.le - 1; --spec3i.l; } \
          } else back__p_spec_elem_copy_at((_xb_), 0, (_b_), spec3i.j); \
        } \
        spec3i.j = (_ds_)[spec3i.i]; \
      } \
    } \
  } else { \
    spec3i.f = 0; spec3i.fe = (_cs_)[0]; spec3i.fc = back__p_spec_elem_get_n(_b_); \
    while (spec3i.f + 1 < (_n_) && spec3i.fc >= spec3i.fe) { ++spec3i.f; spec3i.fe += (_cs_)[spec3i.f]; } \
    spec3i.l = 0; spec3i.le = (_cs_)[0]; spec3i.lc = back__p_spec_elem_get_n(_b_) - 1; \
    while (spec3i.lc >= spec3i.le) { ++spec3i.l; spec3i.le += (_cs_)[spec3i.l]; } \
    for (spec3i.e = 0, spec3i.i = 0; spec3i.i < (_n_); ++spec3i.i) { \
      spec3i.e += (_cs_)[spec3i.i]; \
      spec3i.j = (_ds_)[spec3i.i]; \
      while (spec3i.j < spec3i.e) { \
        spec3i.n = (_tp_)(back__p_spec_elem_get_buf(_b_), spec3i.j, (_tpd_), (_ps_), NULL); \
        spec3i.o = -1; \
        while (spec3i.n > 0) { \
          --spec3i.n; \
          if ((_ps_)[spec3i.n] == spec3i.i && spec3i.o < 0) spec3i.o = spec3i.n; \
          else if ((_ds_)[(_ps_)[spec3i.n]] < spec3i.fc) { \
            spec3i.l = spec3i.f; spec3i.le = spec3i.fe; spec3i.lc = spec3i.fc; \
            if (spec3i.fc < spec3i.fe) { \
              back__p_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec3i.n]], (_b_), spec3i.fc); \
              ++spec3i.fc; \
            } else back__p_spec_elem_copy_at((_b_), (_ds_)[(_ps_)[spec3i.n]], (_xb_), 0); \
          } else if ((_ds_)[(_ps_)[spec3i.n]] == spec3i.fc) ++spec3i.fc; \
          if (spec3i.j != (_ds_)[(_ps_)[spec3i.n]]) back__p_spec_elem_copy_at((_b_), spec3i.j, (_b_), (_ds_)[(_ps_)[spec3i.n]]); \
          ++(_ds_)[(_ps_)[spec3i.n]]; \
          while (spec3i.f + 1 < (_n_) && spec3i.fc >= spec3i.fe) { ++spec3i.f; spec3i.fe += (_cs_)[spec3i.f]; spec3i.fc = (_ds_)[spec3i.f]; } \
        } \
        if (spec3i.o < 0) { \
          if (spec3i.lc < spec3i.le) {  \
            back__p_spec_elem_copy_at((_b_), spec3i.lc, (_b_), spec3i.j); \
            spec3i.f = spec3i.l; spec3i.fe = spec3i.le; spec3i.fc = spec3i.lc; \
            --spec3i.lc; \
            while (spec3i.l > 0 && spec3i.lc < (_ds_)[spec3i.l]) { spec3i.le -= (_cs_)[spec3i.l]; spec3i.lc = spec3i.le - 1; --spec3i.l; } \
          } else back__p_spec_elem_copy_at((_xb_), 0, (_b_), spec3i.j); \
        } \
        spec3i.j = (_ds_)[spec3i.i]; \
      } \
    } \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TPROCS_MOD_REARRANGE_IP */
#define back__p_SPEC_FUNC_TPROCS_MOD_REARRANGE_IP(_name_, _tp_, _s_...) \
_s_ void _name_##_tprocs_mod_rearrange_ip(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tproc_data_t tproc_data, int *displs, int *counts, back__p_spec_int_t n, back__p_spec_proc_t *procs, back__p_spec_elem_t *mod) \
{ \
  back__p_SPEC_DECLARE_TPROCS_MOD_REARRANGE_IP \
  back__p_SPEC_DO_TPROCS_MOD_REARRANGE_IP(_tp_, tproc_data, s, x, displs, counts, n, procs, mod); \
}

/* sp_macro back__p_SPEC_DEFINE_TPROC */
#define back__p_SPEC_DEFINE_TPROC(_name_, _tp_, _s_...) \
  back__p_SPEC_FUNC_TPROC_COUNT_DB(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROC_COUNT_IP(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROC_REARRANGE_DB(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROC_REARRANGE_IP(_name_, _tp_, _s_)

/* sp_macro back__p_SPEC_DEFINE_TPROC_MOD */
#define back__p_SPEC_DEFINE_TPROC_MOD(_name_, _tp_, _s_...) \
  back__p_SPEC_FUNC_TPROC_MOD_COUNT_DB(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROC_MOD_COUNT_IP(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROC_MOD_REARRANGE_DB(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROC_MOD_REARRANGE_IP(_name_, _tp_, _s_)

/* sp_macro back__p_SPEC_DEFINE_TPROCS */
#define back__p_SPEC_DEFINE_TPROCS(_name_, _tp_, _s_...) \
  back__p_SPEC_FUNC_TPROCS_COUNT_DB(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROCS_COUNT_IP(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROCS_REARRANGE_DB(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROCS_REARRANGE_IP(_name_, _tp_, _s_)

/* sp_macro back__p_SPEC_DEFINE_TPROCS_MOD */
#define back__p_SPEC_DEFINE_TPROCS_MOD(_name_, _tp_, _s_...) \
  back__p_SPEC_FUNC_TPROCS_MOD_COUNT_DB(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROCS_MOD_COUNT_IP(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROCS_MOD_REARRANGE_DB(_name_, _tp_, _s_) \
  back__p_SPEC_FUNC_TPROCS_MOD_REARRANGE_IP(_name_, _tp_, _s_)

/* sp_macro back__p_SPEC_EXT_PARAM_TPROC back__p_SPEC_EXT_PARAM_TPROC_NULL back__p_SPEC_EXT_PARAM_TPROC_MOD back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL back__p_SPEC_EXT_PARAM_TPROCS back__p_SPEC_EXT_PARAM_TPROCS_NULL back__p_SPEC_EXT_PARAM_TPROCS_MOD back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL */
#define back__p_SPEC_EXT_PARAM_TPROC(_name_)       _name_##_tproc_count_db, _name_##_tproc_count_ip, _name_##_tproc_rearrange_db, _name_##_tproc_rearrange_ip
#define back__p_SPEC_EXT_PARAM_TPROC_NULL          NULL, NULL, NULL, NULL
#define back__p_SPEC_EXT_PARAM_TPROC_MOD(_name_)   _name_##_tproc_mod_count_db, _name_##_tproc_mod_count_ip, _name_##_tproc_mod_rearrange_db, _name_##_tproc_mod_rearrange_ip
#define back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL      NULL, NULL, NULL, NULL
#define back__p_SPEC_EXT_PARAM_TPROCS(_name_)      _name_##_tprocs_count_db, _name_##_tprocs_count_ip, _name_##_tprocs_rearrange_db, _name_##_tprocs_rearrange_ip
#define back__p_SPEC_EXT_PARAM_TPROCS_NULL         NULL, NULL, NULL, NULL
#define back__p_SPEC_EXT_PARAM_TPROCS_MOD(_name_)  _name_##_tprocs_mod_count_db, _name_##_tprocs_mod_count_ip, _name_##_tprocs_mod_rearrange_db, _name_##_tprocs_mod_rearrange_ip
#define back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL     NULL, NULL, NULL, NULL


/* sp_type back__p_spec_tproc_f back__p_spec_tproc_count_f back__p_spec_tproc_rearrange_db_f back__p_spec_tproc_rearrange_ip_f */
typedef back__p_spec_proc_t back__p_spec_tproc_f(back__p_spec_elem_buf_t b, back__p_spec_elem_index_t x, back__p_spec_tproc_data_t tproc_data);
typedef void back__p_spec_tproc_count_f(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts);
typedef void back__p_spec_tproc_rearrange_db_f(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tproc_data_t tproc_data, int *displs);
typedef void back__p_spec_tproc_rearrange_ip_f(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tproc_data_t tproc_data, int *displs, int *counts, back__p_spec_int_t n);

/* sp_type back__p_spec_tproc_mod_f back__p_spec_tproc_mod_count_f back__p_spec_tproc_mod_rearrange_db_f back__p_spec_tproc_mod_rearrange_ip_f */
typedef back__p_spec_proc_t back__p_spec_tproc_mod_f(back__p_spec_elem_buf_t b, back__p_spec_elem_index_t x, back__p_spec_tproc_data_t tproc_data, back__p_spec_elem_buf_t mod);
typedef void back__p_spec_tproc_mod_count_f(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts);
typedef void back__p_spec_tproc_mod_rearrange_db_f(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tproc_data_t tproc_data, int *displs, back__p_spec_elem_t *mod);
typedef void back__p_spec_tproc_mod_rearrange_ip_f(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tproc_data_t tproc_data, int *displs, int *counts, back__p_spec_int_t n, back__p_spec_elem_t *mod);

/* sp_type back__p_spec_tprocs_f back__p_spec_tprocs_count_f back__p_spec_tprocs_rearrange_db_f back__p_spec_tprocs_rearrange_ip_f */
typedef back__p_spec_int_t back__p_spec_tprocs_f(back__p_spec_elem_buf_t b, back__p_spec_elem_index_t x, back__p_spec_tproc_data_t tproc_data, back__p_spec_proc_t *procs);
typedef void back__p_spec_tprocs_count_f(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts, back__p_spec_proc_t *procs);
typedef void back__p_spec_tprocs_rearrange_db_f(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tproc_data_t tproc_data, int *displs, back__p_spec_proc_t *procs);
typedef void back__p_spec_tprocs_rearrange_ip_f(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tproc_data_t tproc_data, int *displs, int *counts, back__p_spec_int_t n, back__p_spec_proc_t *procs);

/* sp_type back__p_spec_tprocs_mod_f back__p_spec_tprocs_mod_count_f back__p_spec_tprocs_mod_rearrange_db_f back__p_spec_tprocs_mod_rearrange_ip_f */
typedef back__p_spec_int_t back__p_spec_tprocs_mod_f(back__p_spec_elem_buf_t b, back__p_spec_elem_index_t x, back__p_spec_tproc_data_t tproc_data, back__p_spec_proc_t *procs, back__p_spec_elem_buf_t mod);
typedef void back__p_spec_tprocs_mod_count_f(back__p_spec_elem_t *s, back__p_spec_tproc_data_t tproc_data, int *counts, back__p_spec_proc_t *procs);
typedef void back__p_spec_tprocs_mod_rearrange_db_f(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tproc_data_t tproc_data, int *displs, back__p_spec_proc_t *procs, back__p_spec_elem_t *mod);
typedef void back__p_spec_tprocs_mod_rearrange_ip_f(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tproc_data_t tproc_data, int *displs, int *counts, back__p_spec_int_t n, back__p_spec_proc_t *procs, back__p_spec_elem_t *mod);

/* sp_type back__p_spec_tproc_reset_f */
typedef void back__p_spec_tproc_reset_f(back__p_spec_tproc_data_t tproc_data);


/* enable tloc features */
#ifdef back__p_SPEC_TLOC

/* sp_macro back__p_SPEC_TLOC back__p_SPEC_LOC_NONE */


/* tloc rearrange */

/* sp_macro back__p_SPEC_DECLARE_TLOC_REARRANGE_DB */
#define back__p_SPEC_DECLARE_TLOC_REARRANGE_DB \
  struct { back__p_spec_int_t i, p; } spec0d;

/* sp_macro back__p_SPEC_DO_TLOC_REARRANGE_DB */
#define back__p_SPEC_DO_TLOC_REARRANGE_DB(_tl_, _tld_, _sb_, _db_)  do { \
  for (spec0d.i = 0; spec0d.i < back__p_spec_elem_get_n(_sb_); ++spec0d.i) { \
    spec0d.p = (_tl_)(back__p_spec_elem_get_buf(_sb_), spec0d.i, _tld_); \
    if (spec0d.p == back__p_SPEC_LOC_NONE) continue; \
    back__p_spec_elem_copy_at((_sb_), spec0d.i, (_db_), spec0d.p); \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TLOC_REARRANGE_DB */
#define back__p_SPEC_FUNC_TLOC_REARRANGE_DB(_name_, _tl_, _s_...) \
_s_ void _name_##_tloc_rearrange_db(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tloc_data_t tloc_data) \
{ \
  back__p_SPEC_DECLARE_TLOC_REARRANGE_DB \
  back__p_SPEC_DO_TLOC_REARRANGE_DB(_tl_, tloc_data, s, d); \
}

/* sp_macro back__p_SPEC_DECLARE_TLOC_REARRANGE_IP */
#define back__p_SPEC_DECLARE_TLOC_REARRANGE_IP \
  struct { back__p_spec_int_t i, p, np; } spec0i;

/* sp_macro back__p_SPEC_DO_TLOC_REARRANGE_IP */
#define back__p_SPEC_DO_TLOC_REARRANGE_IP(_tl_, _tld_, _b_, _xb_)  do { \
  for (spec0i.i = 0; spec0i.i < back__p_spec_elem_get_n(_b_); ++spec0i.i) { \
    spec0i.p = (_tl_)(back__p_spec_elem_get_buf(_b_), spec0i.i, _tld_); \
    if (spec0i.p == back__p_SPEC_LOC_NONE) continue; \
    while (spec0i.i != spec0i.p) { \
      spec0i.np = (_tl_)(back__p_spec_elem_get_buf(_b_), spec0i.p, _tld_); \
      if (spec0i.np == back__p_SPEC_LOC_NONE) { back__p_spec_elem_copy_at((_b_), spec0i.i, (_b_), spec0i.p); break; } \
      back__p_spec_elem_exchange_at((_b_), spec0i.i, (_b_), spec0i.p, (_xb_)); \
      spec0i.p = spec0i.np; \
    } \
  } } while (0)

/* sp_macro back__p_SPEC_FUNC_TLOC_REARRANGE_IP */
#define back__p_SPEC_FUNC_TLOC_REARRANGE_IP(_name_, _tl_, _s_) \
_s_ void _name_##_tloc_rearrange_ip(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tloc_data_t tloc_data) \
{ \
  back__p_SPEC_DECLARE_TLOC_REARRANGE_IP \
  back__p_SPEC_DO_TLOC_REARRANGE_IP(_tl_, tloc_data, s, x); \
}


/* tloc_mod_mod rearrange */

/* sp_macro back__p_SPEC_DECLARE_TLOC_MOD_REARRANGE_DB */
#define back__p_SPEC_DECLARE_TLOC_MOD_REARRANGE_DB \
  struct { back__p_spec_int_t i, p; } spec1d;

/* sp_macro back__p_SPEC_DO_TLOC_MOD_REARRANGE_DB */
#define back__p_SPEC_DO_TLOC_MOD_REARRANGE_DB(_tl_, _tld_, _sb_, _db_, _ib_)  do { \
  if (_ib_) { \
    for (spec1d.i = 0; spec1d.i < back__p_spec_elem_get_n(_sb_); ++spec1d.i) { \
      spec1d.p = (_tl_)(back__p_spec_elem_get_buf(_sb_), spec1d.i, _tld_, back__p_spec_elem_get_buf(_ib_)); \
      if (spec1d.p == back__p_SPEC_LOC_NONE) continue; \
      back__p_spec_elem_copy_at((_ib_), 0, (_db_), spec1d.p); \
    } \
  } else { \
    for (spec1d.i = 0; spec1d.i < back__p_spec_elem_get_n(_sb_); ++spec1d.i) { \
      spec1d.p = (_tl_)(back__p_spec_elem_get_buf(_sb_), spec1d.i, _tld_, NULL); \
      if (spec1d.p == back__p_SPEC_LOC_NONE) continue; \
      back__p_spec_elem_copy_at((_sb_), spec1d.i, (_db_), spec1d.p); \
    } \
  } } while (0) 

/* sp_macro back__p_SPEC_FUNC_TLOC_MOD_REARRANGE_DB */
#define back__p_SPEC_FUNC_TLOC_MOD_REARRANGE_DB(_name_, _tl_, _s_...) \
_s_ void _name_##_tloc_mod_rearrange_db(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tloc_data_t tloc_data, back__p_spec_elem_t *mod) \
{ \
  back__p_SPEC_DECLARE_TLOC_MOD_REARRANGE_DB \
  back__p_SPEC_DO_TLOC_MOD_REARRANGE_DB(_tl_, tloc_data, s, d, mod); \
}

/* sp_macro back__p_SPEC_DECLARE_TLOC_MOD_REARRANGE_IP */
#define back__p_SPEC_DECLARE_TLOC_MOD_REARRANGE_IP \
  struct { back__p_spec_int_t i, p, np; } spec1i;

/* sp_macro back__p_SPEC_DO_TLOC_MOD_REARRANGE_IP */
#define back__p_SPEC_DO_TLOC_MOD_REARRANGE_IP(_tl_, _tld_, _b_, _xb_, _ib_)  do { \
  if (_ib_) { \
    for (spec1i.i = 0; spec1i.i < back__p_spec_elem_get_n(_b_); ++spec1i.i) { \
      spec1i.p = (_tl_)(back__p_spec_elem_get_buf(_b_), spec1i.i, _tld_, back__p_spec_elem_get_buf(_ib_)); \
      if (spec1i.p == back__p_SPEC_LOC_NONE) continue; \
      while (spec1i.i != spec1i.p) { \
        spec1i.np = (_tl_)(back__p_spec_elem_get_buf(_b_), spec1i.p, _tld_, back__p_spec_elem_get_buf(_xb_)); \
        if (spec1i.np == back__p_SPEC_LOC_NONE) break; \
        back__p_spec_elem_copy_at((_ib_), 0, (_b_), spec1i.p); \
        back__p_spec_elem_copy_at((_xb_), 0, (_ib_), 0); \
        spec1i.p = spec1i.np; \
      } \
      back__p_spec_elem_copy_at((_ib_), 0, (_b_), spec1i.i); \
    } \
  } else { \
    for (spec1i.i = 0; spec1i.i < back__p_spec_elem_get_n(_b_); ++spec1i.i) { \
      spec1i.p = (_tl_)(back__p_spec_elem_get_buf(_b_), spec1i.i, _tld_, NULL); \
      if (spec1i.p == back__p_SPEC_LOC_NONE) continue; \
      while (spec1i.i != spec1i.p) { \
        spec1i.np = (_tl_)(back__p_spec_elem_get_buf(_b_), spec1i.p, _tld_, NULL); \
        if (spec1i.np == back__p_SPEC_LOC_NONE) { back__p_spec_elem_copy_at((_b_), spec1i.i, (_b_), spec1i.p); break; } \
        back__p_spec_elem_exchange_at((_b_), spec1i.i, (_b_), spec1i.p, (_xb_)); \
        spec1i.p = spec1i.np; \
      } \
    } \
 } } while (0) 

/* sp_macro back__p_SPEC_FUNC_TLOC_MOD_REARRANGE_IP */
#define back__p_SPEC_FUNC_TLOC_MOD_REARRANGE_IP(_name_, _tl_, _s_) \
_s_ void _name_##_tloc_mod_rearrange_ip(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tloc_data_t tloc_data, back__p_spec_elem_t *mod) \
{ \
  back__p_SPEC_DECLARE_TLOC_MOD_REARRANGE_IP \
  back__p_SPEC_DO_TLOC_MOD_REARRANGE_IP(_tl_, tloc_data, s, x, mod); \
}

/* sp_macro back__p_SPEC_DEFINE_TLOC */
#define back__p_SPEC_DEFINE_TLOC(_name_, _tl_, _s_...) \
  back__p_SPEC_FUNC_TLOC_REARRANGE_DB(_name_, _tl_, _s_) \
  back__p_SPEC_FUNC_TLOC_REARRANGE_IP(_name_, _tl_, _s_)

/* sp_macro back__p_SPEC_DEFINE_TLOC_MOD */
#define back__p_SPEC_DEFINE_TLOC_MOD(_name_, _tl_, _s_...) \
  back__p_SPEC_FUNC_TLOC_MOD_REARRANGE_DB(_name_, _tl_, _s_) \
  back__p_SPEC_FUNC_TLOC_MOD_REARRANGE_IP(_name_, _tl_, _s_)

/* sp_macro back__p_SPEC_EXT_PARAM_TLOC back__p_SPEC_EXT_PARAM_TLOC_NULL back__p_SPEC_EXT_PARAM_TLOC_MOD back__p_SPEC_EXT_PARAM_TLOC_MOD_NULL */
#define back__p_SPEC_EXT_PARAM_TLOC(_name_)      _name_##_tloc_rearrange_db, _name_##_tloc_rearrange_ip
#define back__p_SPEC_EXT_PARAM_TLOC_NULL         NULL, NULL
#define back__p_SPEC_EXT_PARAM_TLOC_MOD(_name_)  _name_##_tloc_mod_rearrange_db, _name_##_tloc_mod_rearrange_ip
#define back__p_SPEC_EXT_PARAM_TLOC_MOD_NULL     NULL, NULL


/* sp_type back__p_spec_tloc_f back__p_spec_tloc_rearrange_db_f back__p_spec_tloc_rearrange_ip_f */
typedef back__p_spec_elem_index_t back__p_spec_tloc_f(back__p_spec_elem_buf_t b, back__p_spec_elem_index_t x, back__p_spec_tloc_data_t tloc_data);
typedef void back__p_spec_tloc_rearrange_db_f(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tloc_data_t tloc_data);
typedef void back__p_spec_tloc_rearrange_ip_f(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tloc_data_t tloc_data);

/* sp_type back__p_spec_tloc_mod_f back__p_spec_tloc_mod_rearrange_db_f back__p_spec_tloc_mod_rearrange_ip_f */
typedef back__p_spec_elem_index_t back__p_spec_tloc_mod_f(back__p_spec_elem_buf_t b, back__p_spec_elem_index_t x, back__p_spec_tloc_data_t tloc_data, back__p_spec_elem_buf_t mod);
typedef void back__p_spec_tloc_mod_rearrange_db_f(back__p_spec_elem_t *s, back__p_spec_elem_t *d, back__p_spec_tloc_data_t tloc_data, back__p_spec_elem_t *mod);
typedef void back__p_spec_tloc_mod_rearrange_ip_f(back__p_spec_elem_t *s, back__p_spec_elem_t *x, back__p_spec_tloc_data_t tloc_data, back__p_spec_elem_t *mod);


#endif /* back__p_SPEC_TLOC */






#ifdef SL_USE_MPI
# include <mpi.h>
#endif


/* sl_type back__p_slint_t back__p_slint */
typedef back__p_sl_int_type_c back__p_slint_t, back__p_slint;  /* deprecated 'back__p_slint' */

#define back__p_slint_fmt   back__p_sl_int_type_fmt    /* sl_macro */

/* sl_type back__p_slindex_t */
typedef back__p_sl_index_type_c back__p_slindex_t;

#define back__p_sindex_fmt  back__p_sl_index_type_fmt  /* sl_macro */

/* sl_type back__p_slkey_t */
typedef back__p_sl_key_type_c back__p_slkey_t;

/* sl_type back__p_slkey_pure_t back__p_slpkey_t */
typedef back__p_sl_key_pure_type_c back__p_slkey_pure_t, back__p_slpkey_t;

/* DATAX_TEMPLATE_BEGIN */
/* sl_type back__p_sldata0_t */
#ifdef back__p_sl_data0_type_c
typedef back__p_sl_data0_type_c back__p_sldata0_t;
#endif
/* sl_type back__p_sldata1_t */
#ifdef back__p_sl_data1_type_c
typedef back__p_sl_data1_type_c back__p_sldata1_t;
#endif
/* sl_type back__p_sldata2_t */
#ifdef back__p_sl_data2_type_c
typedef back__p_sl_data2_type_c back__p_sldata2_t;
#endif
/* sl_type back__p_sldata3_t */
#ifdef back__p_sl_data3_type_c
typedef back__p_sl_data3_type_c back__p_sldata3_t;
#endif
/* sl_type back__p_sldata4_t */
#ifdef back__p_sl_data4_type_c
typedef back__p_sl_data4_type_c back__p_sldata4_t;
#endif
/* sl_type back__p_sldata5_t */
#ifdef back__p_sl_data5_type_c
typedef back__p_sl_data5_type_c back__p_sldata5_t;
#endif
/* sl_type back__p_sldata6_t */
#ifdef back__p_sl_data6_type_c
typedef back__p_sl_data6_type_c back__p_sldata6_t;
#endif
/* sl_type back__p_sldata7_t */
#ifdef back__p_sl_data7_type_c
typedef back__p_sl_data7_type_c back__p_sldata7_t;
#endif
/* sl_type back__p_sldata8_t */
#ifdef back__p_sl_data8_type_c
typedef back__p_sl_data8_type_c back__p_sldata8_t;
#endif
/* sl_type back__p_sldata9_t */
#ifdef back__p_sl_data9_type_c
typedef back__p_sl_data9_type_c back__p_sldata9_t;
#endif
/* sl_type back__p_sldata10_t */
#ifdef back__p_sl_data10_type_c
typedef back__p_sl_data10_type_c back__p_sldata10_t;
#endif
/* sl_type back__p_sldata11_t */
#ifdef back__p_sl_data11_type_c
typedef back__p_sl_data11_type_c back__p_sldata11_t;
#endif
/* sl_type back__p_sldata12_t */
#ifdef back__p_sl_data12_type_c
typedef back__p_sl_data12_type_c back__p_sldata12_t;
#endif
/* sl_type back__p_sldata13_t */
#ifdef back__p_sl_data13_type_c
typedef back__p_sl_data13_type_c back__p_sldata13_t;
#endif
/* sl_type back__p_sldata14_t */
#ifdef back__p_sl_data14_type_c
typedef back__p_sl_data14_type_c back__p_sldata14_t;
#endif
/* sl_type back__p_sldata15_t */
#ifdef back__p_sl_data15_type_c
typedef back__p_sl_data15_type_c back__p_sldata15_t;
#endif
/* sl_type back__p_sldata16_t */
#ifdef back__p_sl_data16_type_c
typedef back__p_sl_data16_type_c back__p_sldata16_t;
#endif
/* sl_type back__p_sldata17_t */
#ifdef back__p_sl_data17_type_c
typedef back__p_sl_data17_type_c back__p_sldata17_t;
#endif
/* sl_type back__p_sldata18_t */
#ifdef back__p_sl_data18_type_c
typedef back__p_sl_data18_type_c back__p_sldata18_t;
#endif
/* sl_type back__p_sldata19_t */
#ifdef back__p_sl_data19_type_c
typedef back__p_sl_data19_type_c back__p_sldata19_t;
#endif
/* DATAX_TEMPLATE_END */

#define SL_DATA_NMAX (0 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
 + 1 \
)

/* sl_type back__p_slweight_t */
typedef back__p_sl_weight_type_c back__p_slweight_t;

#define back__p_slweight_fmt  back__p_sl_weight_type_fmt  /* sl_macro */

#if defined(back__p_sl_elem_weight) && defined(back__p_sl_weight_intequiv)
typedef back__p_sl_weight_type_c back__p_slcount_t;       /* sl_type back__p_slcount_t */
# define back__p_slcount_fmt  back__p_sl_weight_type_fmt  /* sl_macro */
#else
typedef back__p_sl_int_type_c back__p_slcount_t;
# define back__p_slcount_fmt  back__p_sl_int_type_fmt
#endif


/* sl_type back__p__slpwkey_t back__p_slpwkey_t */
typedef struct back__p__slpwkey_t
{
  back__p_slpkey_t pkey;
  back__p_slweight_t weight;

} back__p_slpwkey_t;


/* sl_type back__p__elements_t back__p_elements_t */
typedef struct back__p__elements_t
{
  back__p_slint_t size, max_size;
  back__p_slkey_t *keys;

#ifdef back__p_SL_INDEX
  back__p_slindex_t *indices;
#endif

/* DATAX_TEMPLATE_BEGIN */
#ifdef back__p_SL_DATA0
  back__p_sldata0_t *data0;
#endif
#ifdef back__p_SL_DATA1
  back__p_sldata1_t *data1;
#endif
#ifdef back__p_SL_DATA2
  back__p_sldata2_t *data2;
#endif
#ifdef back__p_SL_DATA3
  back__p_sldata3_t *data3;
#endif
#ifdef back__p_SL_DATA4
  back__p_sldata4_t *data4;
#endif
#ifdef back__p_SL_DATA5
  back__p_sldata5_t *data5;
#endif
#ifdef back__p_SL_DATA6
  back__p_sldata6_t *data6;
#endif
#ifdef back__p_SL_DATA7
  back__p_sldata7_t *data7;
#endif
#ifdef back__p_SL_DATA8
  back__p_sldata8_t *data8;
#endif
#ifdef back__p_SL_DATA9
  back__p_sldata9_t *data9;
#endif
#ifdef back__p_SL_DATA10
  back__p_sldata10_t *data10;
#endif
#ifdef back__p_SL_DATA11
  back__p_sldata11_t *data11;
#endif
#ifdef back__p_SL_DATA12
  back__p_sldata12_t *data12;
#endif
#ifdef back__p_SL_DATA13
  back__p_sldata13_t *data13;
#endif
#ifdef back__p_SL_DATA14
  back__p_sldata14_t *data14;
#endif
#ifdef back__p_SL_DATA15
  back__p_sldata15_t *data15;
#endif
#ifdef back__p_SL_DATA16
  back__p_sldata16_t *data16;
#endif
#ifdef back__p_SL_DATA17
  back__p_sldata17_t *data17;
#endif
#ifdef back__p_SL_DATA18
  back__p_sldata18_t *data18;
#endif
#ifdef back__p_SL_DATA19
  back__p_sldata19_t *data19;
#endif
/* DATAX_TEMPLATE_END */

} back__p_elements_t;


/* sl_type back__p__packed_element_t back__p_packed_element_t */
typedef struct back__p__packed_element_t
{
  back__p_slkey_t key;

#ifdef back__p_SL_PACKED_INDEX
  back__p_slindex_t index;
#endif

/* DATAX_TEMPLATE_BEGIN */
#ifdef back__p_SL_DATA0
# ifdef back__p_sl_data0_flex
  back__p_sldata0_t data0[];
# else
  back__p_sldata0_t data0[back__p_sl_data0_size_c];
# endif
#endif
#ifdef back__p_SL_DATA1
# ifdef back__p_sl_data1_flex
  back__p_sldata1_t data1[];
# else
  back__p_sldata1_t data1[back__p_sl_data1_size_c];
# endif
#endif
#ifdef back__p_SL_DATA2
# ifdef back__p_sl_data2_flex
  back__p_sldata2_t data2[];
# else
  back__p_sldata2_t data2[back__p_sl_data2_size_c];
# endif
#endif
#ifdef back__p_SL_DATA3
# ifdef back__p_sl_data3_flex
  back__p_sldata3_t data3[];
# else
  back__p_sldata3_t data3[back__p_sl_data3_size_c];
# endif
#endif
#ifdef back__p_SL_DATA4
# ifdef back__p_sl_data4_flex
  back__p_sldata4_t data4[];
# else
  back__p_sldata4_t data4[back__p_sl_data4_size_c];
# endif
#endif
#ifdef back__p_SL_DATA5
# ifdef back__p_sl_data5_flex
  back__p_sldata5_t data5[];
# else
  back__p_sldata5_t data5[back__p_sl_data5_size_c];
# endif
#endif
#ifdef back__p_SL_DATA6
# ifdef back__p_sl_data6_flex
  back__p_sldata6_t data6[];
# else
  back__p_sldata6_t data6[back__p_sl_data6_size_c];
# endif
#endif
#ifdef back__p_SL_DATA7
# ifdef back__p_sl_data7_flex
  back__p_sldata7_t data7[];
# else
  back__p_sldata7_t data7[back__p_sl_data7_size_c];
# endif
#endif
#ifdef back__p_SL_DATA8
# ifdef back__p_sl_data8_flex
  back__p_sldata8_t data8[];
# else
  back__p_sldata8_t data8[back__p_sl_data8_size_c];
# endif
#endif
#ifdef back__p_SL_DATA9
# ifdef back__p_sl_data9_flex
  back__p_sldata9_t data9[];
# else
  back__p_sldata9_t data9[back__p_sl_data9_size_c];
# endif
#endif
#ifdef back__p_SL_DATA10
# ifdef back__p_sl_data10_flex
  back__p_sldata10_t data10[];
# else
  back__p_sldata10_t data10[back__p_sl_data10_size_c];
# endif
#endif
#ifdef back__p_SL_DATA11
# ifdef back__p_sl_data11_flex
  back__p_sldata11_t data11[];
# else
  back__p_sldata11_t data11[back__p_sl_data11_size_c];
# endif
#endif
#ifdef back__p_SL_DATA12
# ifdef back__p_sl_data12_flex
  back__p_sldata12_t data12[];
# else
  back__p_sldata12_t data12[back__p_sl_data12_size_c];
# endif
#endif
#ifdef back__p_SL_DATA13
# ifdef back__p_sl_data13_flex
  back__p_sldata13_t data13[];
# else
  back__p_sldata13_t data13[back__p_sl_data13_size_c];
# endif
#endif
#ifdef back__p_SL_DATA14
# ifdef back__p_sl_data14_flex
  back__p_sldata14_t data14[];
# else
  back__p_sldata14_t data14[back__p_sl_data14_size_c];
# endif
#endif
#ifdef back__p_SL_DATA15
# ifdef back__p_sl_data15_flex
  back__p_sldata15_t data15[];
# else
  back__p_sldata15_t data15[back__p_sl_data15_size_c];
# endif
#endif
#ifdef back__p_SL_DATA16
# ifdef back__p_sl_data16_flex
  back__p_sldata16_t data16[];
# else
  back__p_sldata16_t data16[back__p_sl_data16_size_c];
# endif
#endif
#ifdef back__p_SL_DATA17
# ifdef back__p_sl_data17_flex
  back__p_sldata17_t data17[];
# else
  back__p_sldata17_t data17[back__p_sl_data17_size_c];
# endif
#endif
#ifdef back__p_SL_DATA18
# ifdef back__p_sl_data18_flex
  back__p_sldata18_t data18[];
# else
  back__p_sldata18_t data18[back__p_sl_data18_size_c];
# endif
#endif
#ifdef back__p_SL_DATA19
# ifdef back__p_sl_data19_flex
  back__p_sldata19_t data19[];
# else
  back__p_sldata19_t data19[back__p_sl_data19_size_c];
# endif
#endif
/* DATAX_TEMPLATE_END */

} back__p_packed_element_t;


/* sl_type back__p__packed_elements_t back__p_packed_elements_t */
typedef struct back__p__packed_elements_t
{
  back__p_slint_t size, max_size;
  
  back__p_packed_element_t *elements;
  
} back__p_packed_elements_t;


#ifndef SLCINT_T
#define SLCINT_T
typedef long long int slcint_t;
#define slcint_fmt  "ll"
/*#define slcint_sfx  LL*/
#endif


#define SLCM_KEYS     (((slcint_t) 1) << 0)
#define SLCM_INDICES  (((slcint_t) 1) << 1)
#define SLCM_WEIGHTS  (((slcint_t) 1) << 2)

/* DATAX_TEMPLATE_BEGIN */
#define SLCM_DATA0    (((slcint_t) 1) << (3+0))
#define SLCM_DATA1    (((slcint_t) 1) << (3+1))
#define SLCM_DATA2    (((slcint_t) 1) << (3+2))
#define SLCM_DATA3    (((slcint_t) 1) << (3+3))
#define SLCM_DATA4    (((slcint_t) 1) << (3+4))
#define SLCM_DATA5    (((slcint_t) 1) << (3+5))
#define SLCM_DATA6    (((slcint_t) 1) << (3+6))
#define SLCM_DATA7    (((slcint_t) 1) << (3+7))
#define SLCM_DATA8    (((slcint_t) 1) << (3+8))
#define SLCM_DATA9    (((slcint_t) 1) << (3+9))
#define SLCM_DATA10    (((slcint_t) 1) << (3+10))
#define SLCM_DATA11    (((slcint_t) 1) << (3+11))
#define SLCM_DATA12    (((slcint_t) 1) << (3+12))
#define SLCM_DATA13    (((slcint_t) 1) << (3+13))
#define SLCM_DATA14    (((slcint_t) 1) << (3+14))
#define SLCM_DATA15    (((slcint_t) 1) << (3+15))
#define SLCM_DATA16    (((slcint_t) 1) << (3+16))
#define SLCM_DATA17    (((slcint_t) 1) << (3+17))
#define SLCM_DATA18    (((slcint_t) 1) << (3+18))
#define SLCM_DATA19    (((slcint_t) 1) << (3+19))
/* DATAX_TEMPLATE_END */

#define SLCM_DATA     (((slcint_t) 0) \
  |SLCM_DATA0 \
  |SLCM_DATA1 \
  |SLCM_DATA2 \
  |SLCM_DATA3 \
  |SLCM_DATA4 \
  |SLCM_DATA5 \
  |SLCM_DATA6 \
  |SLCM_DATA7 \
  |SLCM_DATA8 \
  |SLCM_DATA9 \
  |SLCM_DATA10 \
  |SLCM_DATA11 \
  |SLCM_DATA12 \
  |SLCM_DATA13 \
  |SLCM_DATA14 \
  |SLCM_DATA15 \
  |SLCM_DATA16 \
  |SLCM_DATA17 \
  |SLCM_DATA18 \
  |SLCM_DATA19 \
  )

#define SLCM_ALL      (~((slcint_t) 0))


/* sl_type back__p__classification_info_t back__p_classification_info_t back__p_classification_info */
typedef struct back__p__classification_info_t
{
  back__p_slint_t nclasses;
  back__p_slkey_pure_t *keys;
  back__p_slint_t *counts;
  back__p_slint_t *masks;

  /* */
  back__p_slint_t *all_local_sizes;
  back__p_slint_t *local_lt_eq_counts;
  back__p_slint_t *all_local_lt_eq_counts;

} back__p_classification_info_t, back__p_classification_info;  /* deprecated 'back__p_classification_info' */


/* key2class, sl_type back__p_key2class_f */
typedef back__p_slint_t (*back__p_key2class_f)(back__p_slkey_t *, back__p_slint, void *);

/* pivot-element, sl_type back__p_pivot_f */
typedef back__p_slint_t (*back__p_pivot_f)(back__p_elements_t *);

/* sorting-network, sl_type back__p_sortnet_f back__p_sortnet_data_t */
typedef void *back__p_sortnet_data_t;
typedef back__p_slint_t (*back__p_sortnet_f)(back__p_slint_t size, back__p_slint_t rank, back__p_slint_t stage, back__p_sortnet_data_t snd, back__p_slint_t *up);

/* merge2, sl_type back__p_merge2x_f back__p_merge2X_f */
typedef back__p_slint_t (*back__p_merge2x_f)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
typedef back__p_slint_t (*back__p_merge2X_f)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx, back__p_elements_t *t);

/* sl_type back__p__permute_generic_t back__p_permute_generic_t */
typedef struct back__p__permute_generic_t
{
  int type;

  back__p_spec_tloc_f *tloc;
  back__p_spec_tloc_rearrange_db_f *tloc_rearrange_db;
  back__p_spec_tloc_rearrange_ip_f *tloc_rearrange_ip;

  back__p_spec_tloc_mod_f *tloc_mod;
  back__p_spec_tloc_mod_rearrange_db_f *tloc_mod_rearrange_db;
  back__p_spec_tloc_mod_rearrange_ip_f *tloc_mod_rearrange_ip;

} back__p_permute_generic_t;

/* sl_macro back__p_PERMUTE_GENERIC_DEFINE_TLOC back__p_PERMUTE_GENERIC_INIT_TLOC back__p_PERMUTE_GENERIC_INIT_EXT_TLOC */
#define back__p_PERMUTE_GENERIC_DEFINE_TLOC(_tl_, _s_...)      back__p_SPEC_DEFINE_TLOC(_tl_, _tl_, _s_)
#define back__p_PERMUTE_GENERIC_INIT_TLOC(_tl_)                { 1, _tl_, back__p_SPEC_EXT_PARAM_TLOC_NULL,  NULL, back__p_SPEC_EXT_PARAM_TLOC_MOD_NULL }
#define back__p_PERMUTE_GENERIC_INIT_EXT_TLOC(_tl_)            { 1, _tl_, back__p_SPEC_EXT_PARAM_TLOC(_tl_), NULL, back__p_SPEC_EXT_PARAM_TLOC_MOD_NULL }

/* sl_macro back__p_PERMUTE_GENERIC_DEFINE_TLOC_MOD back__p_PERMUTE_GENERIC_INIT_TLOC_MOD back__p_PERMUTE_GENERIC_INIT_EXT_TLOC_MOD */
#define back__p_PERMUTE_GENERIC_DEFINE_TLOC_MOD(_tl_, _s_...)  back__p_SPEC_DEFINE_TLOC_MOD(_tl_, _tl_, _s_)
#define back__p_PERMUTE_GENERIC_INIT_TLOC_MOD(_tl_)            { 2, NULL, back__p_SPEC_EXT_PARAM_TLOC_MOD_NULL, _tl_, back__p_SPEC_EXT_PARAM_TLOC_MOD_NULL }
#define back__p_PERMUTE_GENERIC_INIT_EXT_TLOC_MOD(_tl_)        { 2, NULL, back__p_SPEC_EXT_PARAM_TLOC_MOD_NULL, _tl_, back__p_SPEC_EXT_PARAM_TLOC_MOD(_tl_) }

/* sl_type back__p__split_generic_t back__p_split_generic_t */
typedef struct back__p__split_generic_t
{
  int type;

  back__p_spec_tproc_f *tproc;
  back__p_spec_tproc_count_f *tproc_count_db, *tproc_count_ip;
  back__p_spec_tproc_rearrange_db_f *tproc_rearrange_db;
  back__p_spec_tproc_rearrange_ip_f *tproc_rearrange_ip;

  back__p_spec_tproc_mod_f *tproc_mod;
  back__p_spec_tproc_mod_count_f *tproc_mod_count_db, *tproc_mod_count_ip;
  back__p_spec_tproc_mod_rearrange_db_f *tproc_mod_rearrange_db;
  back__p_spec_tproc_mod_rearrange_ip_f *tproc_mod_rearrange_ip;

  back__p_spec_tprocs_f *tprocs;
  back__p_spec_tprocs_count_f *tprocs_count_db, *tprocs_count_ip;
  back__p_spec_tprocs_rearrange_db_f *tprocs_rearrange_db;
  back__p_spec_tprocs_rearrange_ip_f *tprocs_rearrange_ip;

  back__p_spec_tprocs_mod_f *tprocs_mod;
  back__p_spec_tprocs_mod_count_f *tprocs_mod_count_db, *tprocs_mod_count_ip;
  back__p_spec_tprocs_mod_rearrange_db_f *tprocs_mod_rearrange_db;
  back__p_spec_tprocs_mod_rearrange_ip_f *tprocs_mod_rearrange_ip;

  back__p_spec_tproc_reset_f *reset;

} back__p_split_generic_t;

/* sl_macro back__p_SPLIT_GENERIC_DEFINE_TPROC back__p_SPLIT_GENERIC_INIT_TPROC back__p_SPLIT_GENERIC_INIT_EXT_TPROC */
#define back__p_SPLIT_GENERIC_DEFINE_TPROC(_tp_, _s_...)         back__p_SPEC_DEFINE_TPROC(_tp_, _tp_, _s_)
#define back__p_SPLIT_GENERIC_INIT_TPROC(_tp_, _r_...)           { 1, _tp_, back__p_SPEC_EXT_PARAM_TPROC_NULL,  NULL, back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROCS_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }
#define back__p_SPLIT_GENERIC_INIT_EXT_TPROC(_tp_, _r_...)       { 1, _tp_, back__p_SPEC_EXT_PARAM_TPROC(_tp_), NULL, back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROCS_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }

/* sl_macro back__p_SPLIT_GENERIC_DEFINE_TPROC_MOD back__p_SPLIT_GENERIC_INIT_TPROC_MOD back__p_SPLIT_GENERIC_INIT_EXT_TPROC_MOD */
#define back__p_SPLIT_GENERIC_DEFINE_TPROC_MOD(_tp_, _s_...)     back__p_SPEC_DEFINE_TPROC_MOD(_tp_, _tp_, _s_)
#define back__p_SPLIT_GENERIC_INIT_TPROC_MOD(_tp_, _r_...)       { 2, NULL, back__p_SPEC_EXT_PARAM_TPROC_NULL, _tp_, back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL,  NULL, back__p_SPEC_EXT_PARAM_TPROCS_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }
#define back__p_SPLIT_GENERIC_INIT_EXT_TPROC_MOD(_tp_, _r_...)   { 2, NULL, back__p_SPEC_EXT_PARAM_TPROC_NULL, _tp_, back__p_SPEC_EXT_PARAM_TPROC_MOD(_tp_), NULL, back__p_SPEC_EXT_PARAM_TPROCS_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }

/* sl_macro back__p_SPLIT_GENERIC_DEFINE_TPROCS back__p_SPLIT_GENERIC_INIT_TPROCS back__p_SPLIT_GENERIC_INIT_EXT_TPROCS */
#define back__p_SPLIT_GENERIC_DEFINE_TPROCS(_tp_, _s_...)        back__p_SPEC_DEFINE_TPROCS(_tp_, _tp_, _s_)
#define back__p_SPLIT_GENERIC_INIT_TPROCS(_tp_, _r_...)          { 3, NULL, back__p_SPEC_EXT_PARAM_TPROC_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL, _tp_, back__p_SPEC_EXT_PARAM_TPROCS_NULL,  NULL, back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }
#define back__p_SPLIT_GENERIC_INIT_EXT_TPROCS(_tp_, _r_...)      { 3, NULL, back__p_SPEC_EXT_PARAM_TPROC_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL, _tp_, back__p_SPEC_EXT_PARAM_TPROCS(_tp_), NULL, back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }

/* sl_macro back__p_SPLIT_GENERIC_DEFINE_TPROCS_MOD back__p_SPLIT_GENERIC_INIT_TPROCS_MOD back__p_SPLIT_GENERIC_INIT_EXT_TPROCS_MOD */
#define back__p_SPLIT_GENERIC_DEFINE_TPROCS_MOD(_tp_, _s_...)    back__p_SPEC_DEFINE_TPROCS_MOD(_tp_, _tp_, _s_)
#define back__p_SPLIT_GENERIC_INIT_TPROCS_MOD(_tp_, _r_...)      { 4, NULL, back__p_SPEC_EXT_PARAM_TPROC_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROCS_NULL,  _tp_, back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL,  _r_ }
#define back__p_SPLIT_GENERIC_INIT_EXT_TPROCS_MOD(_tp_, _r_...)  { 4, NULL, back__p_SPEC_EXT_PARAM_TPROC_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL, NULL, back__p_SPEC_EXT_PARAM_TPROCS_NULL,  _tp_, back__p_SPEC_EXT_PARAM_TPROCS_MOD(_tp_), _r_ }

/* sl_type back__p_tloc_f back__p_tloc_mod_f */
typedef back__p_slint_t back__p_tloc_f(back__p_elements_t *b, back__p_slint_t x, void *tloc_data);
typedef back__p_slint_t back__p_tloc_mod_f(back__p_elements_t *b, back__p_slint_t x, void *tloc_data, back__p_elements_t *mod);

/* sl_type back__p_tproc_f back__p_tproc_mod_f back__p_tprocs_f back__p_tprocs_mod_f */
typedef int back__p_tproc_f(back__p_elements_t *b, back__p_slint_t x, void *tproc_data);
typedef int back__p_tproc_mod_f(back__p_elements_t *b, back__p_slint_t x, void *tproc_data, back__p_elements_t *mod);
typedef back__p_slint_t back__p_tprocs_f(back__p_elements_t *b, back__p_slint_t x, void *tproc_data, int *procs);
typedef back__p_slint_t back__p_tprocs_mod_f(back__p_elements_t *b, back__p_slint_t x, void *tproc_data, int *procs, back__p_elements_t *mod);

/* sl_type back__p_tproc_reset_f */
typedef void back__p_tproc_reset_f(void *tproc_data);

/* sl_macro back__p_TPROC_RESET_NULL */
#define back__p_TPROC_RESET_NULL  NULL

/* sl_type back__p__tproc_t back__p_tproc_t */
typedef struct back__p__tproc_t *back__p_tproc_t;

/* sl_type back__p__tproc_exdef back__p_tproc_exdef */
typedef struct back__p__tproc_exdef {
  int type;

  back__p_spec_tproc_count_f *tproc_count_db, *tproc_count_ip;
  back__p_spec_tproc_rearrange_db_f *tproc_rearrange_db;
  back__p_spec_tproc_rearrange_ip_f *tproc_rearrange_ip;

  back__p_spec_tproc_mod_count_f *tproc_mod_count_db, *tproc_mod_count_ip;
  back__p_spec_tproc_mod_rearrange_db_f *tproc_mod_rearrange_db;
  back__p_spec_tproc_mod_rearrange_ip_f *tproc_mod_rearrange_ip;

  back__p_spec_tprocs_count_f *tprocs_count_db, *tprocs_count_ip;
  back__p_spec_tprocs_rearrange_db_f *tprocs_rearrange_db;
  back__p_spec_tprocs_rearrange_ip_f *tprocs_rearrange_ip;

  back__p_spec_tprocs_mod_count_f *tprocs_mod_count_db, *tprocs_mod_count_ip;
  back__p_spec_tprocs_mod_rearrange_db_f *tprocs_mod_rearrange_db;
  back__p_spec_tprocs_mod_rearrange_ip_f *tprocs_mod_rearrange_ip;

} const *back__p_tproc_exdef;

/* sl_macro back__p_TPROC_EXDEF_NULL */
#define back__p_TPROC_EXDEF_NULL  NULL

/* sl_macro back__p_TPROC_EXDEF_DEFINE_TPROC back__p_TPROC_EXDEF_DEFINE_TPROC_MOD back__p_TPROC_EXDEF_DEFINE_TPROCS back__p_TPROC_EXDEF_DEFINE_TPROCS_MOD */
#define back__p_TPROC_EXDEF_DEFINE_TPROC(_name_, _tp_, _s_...) \
  back__p_SPEC_DEFINE_TPROC(_name_, _tp_, _s_) \
  _s_ const struct back__p__tproc_exdef _##_name_ = { 1, back__p_SPEC_EXT_PARAM_TPROC(_name_), back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL, back__p_SPEC_EXT_PARAM_TPROCS_NULL, back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL }, *_name_ = &_##_name_;

#define back__p_TPROC_EXDEF_DEFINE_TPROC_MOD(_name_, _tp_, _s_...) \
  back__p_SPEC_DEFINE_TPROC_MOD(_name_, _tp_, _s_) \
  _s_ const struct back__p__tproc_exdef _##_name_ = { 2, back__p_SPEC_EXT_PARAM_TPROC_NULL, back__p_SPEC_EXT_PARAM_TPROC_MOD(_name_), back__p_SPEC_EXT_PARAM_TPROCS_NULL, back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL }, *_name_ = &_##_name_;

#define back__p_TPROC_EXDEF_DEFINE_TPROCS(_name_, _tp_, _s_...) \
  back__p_SPEC_DEFINE_TPROCS(_name_, _tp_, _s_) \
  _s_ const struct back__p__tproc_exdef _##_name_ = { 3, back__p_SPEC_EXT_PARAM_TPROC_NULL, back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL, back__p_SPEC_EXT_PARAM_TPROCS(_name_), back__p_SPEC_EXT_PARAM_TPROCS_MOD_NULL }, *_name_ = &_##_name_;

#define back__p_TPROC_EXDEF_DEFINE_TPROCS_MOD(_name_, _tp_, _s_...) \
  back__p_SPEC_DEFINE_TPROCS_MOD(_name_, _tp_, _s_) \
  _s_ const struct back__p__tproc_exdef _##_name_ = { 4, back__p_SPEC_EXT_PARAM_TPROC_NULL, back__p_SPEC_EXT_PARAM_TPROC_MOD_NULL, back__p_SPEC_EXT_PARAM_TPROCS_NULL, back__p_SPEC_EXT_PARAM_TPROCS_MOD(_name_) }, *_name_ = &_##_name_;


/* deprecated, sl_type back__p_k2c_func back__p_pivot_func back__p_sn_func back__p_m2x_func back__p_m2X_func */
typedef back__p_key2class_f back__p_k2c_func;
typedef back__p_pivot_f back__p_pivot_func;
typedef back__p_sortnet_f back__p_sn_func;
typedef back__p_merge2x_f back__p_m2x_func;
typedef back__p_merge2X_f back__p_m2X_func;


/* sl_type back__p__mergek_t back__p_mergek_t */
typedef struct back__p__mergek_t
{
  back__p_sortnet_f sn;
  back__p_sortnet_data_t snd;

  back__p_merge2x_f m2x;
  back__p_elements_t *sx;

} back__p_mergek_t;


/* sl_type back__p_keys_init_type_t back__p_keys_init_data_t */
typedef back__p_slint_t back__p_keys_init_type_t;
typedef void *back__p_keys_init_data_t;

/* sl_type back__p_key_set_data_t back__p_key_set_f */
typedef void *back__p_key_set_data_t;
typedef void (*back__p_key_set_f)(back__p_slkey_pure_t *k, back__p_key_set_data_t d);


#undef SL_EKIT_SET
#define SL_EKIT_SET         1
#undef SL_EKIT_SET_FUNC
#define SL_EKIT_SET_FUNC    2
#undef SL_EKIT_RAND
#define SL_EKIT_RAND        3
#undef SL_EKIT_RAND_QUAD
#define SL_EKIT_RAND_QUAD   4
#undef SL_EKIT_RAND_AND
#define SL_EKIT_RAND_AND    5
#undef SL_EKIT_URAND
#define SL_EKIT_URAND       6
#undef SL_EKIT_NRAND
#define SL_EKIT_NRAND       7


#ifndef SL_EIK_OFFSET
# define SL_EIK_OFFSET     65536LL
#endif

#ifndef SL_EIK_SET
# define SL_EIK_SET        SL_EIK_OFFSET*1
#endif

#ifndef SL_EIK_RAND
# define SL_EIK_RAND       SL_EIK_OFFSET*2
#endif

#ifndef SL_EIK_RAND_QUAD
# define SL_EIK_RAND_QUAD  SL_EIK_OFFSET*3
#endif

#ifndef SL_EIK_RAND_AND
# define SL_EIK_RAND_AND   SL_EIK_OFFSET*4
#endif

#ifndef SL_EIK_RAND_NORM
# define SL_EIK_RAND_NORM  SL_EIK_OFFSET*5
#endif


/* back__p_elements_keys_stats */
#ifndef SL_EKS_MIN
# define SL_EKS_MIN   0
#endif

#ifndef SL_EKS_MAX
# define SL_EKS_MAX   1
#endif

#ifndef SL_EKS_SUM
# define SL_EKS_SUM   2
#endif

#ifndef SL_EKS_AVG
# define SL_EKS_AVG   3
#endif

#ifndef SL_EKS_STD
# define SL_EKS_STD   4
#endif

#ifndef SL_EKS_SIZE
# define SL_EKS_SIZE  5
#endif


#ifndef SL_SORTED_IN
# define SL_SORTED_IN   0x1LL
#endif

#ifndef SL_SORTED_OUT
# define SL_SORTED_OUT  0x2LL
#endif


#ifndef SL_MSEG_FM_EXACT
# define SL_MSEG_FM_EXACT         0
#endif
#ifndef SL_MSEG_FM_ALLORNOTHING
# define SL_MSEG_FM_ALLORNOTHING  1
#endif
#ifndef SL_MSEG_FM_MIDDLE
# define SL_MSEG_FM_MIDDLE        2
#endif


/* partition conditions, sl_type back__p__partcond2_t back__p_partcond2_t */
typedef struct back__p__partcond2_t
{
  int weighted;
  double min_count, max_count;
  double min_weight, max_weight;
  double min_cpart, max_cpart;
  double min_wpart, max_wpart;

} back__p_partcond2_t;


#ifndef SLPC_COUNTS_MM
# define SLPC_COUNTS_MM   0x1
#endif
#ifndef SLPC_COUNTS_LH
# define SLPC_COUNTS_LH   0x2
#endif
#ifndef SLPC_WEIGHTS_MM
# define SLPC_WEIGHTS_MM  0x4
#endif
#ifndef SLPC_WEIGHTS_LH
# define SLPC_WEIGHTS_LH  0x8
#endif

/* partition conditions, sl_type back__p__partcond_t back__p_partcond_t back__p_partcond_p */
typedef struct back__p__partcond_t
{
  back__p_slint_t pcm;
  double count_min, count_max;
  double count_low, count_high;
  double weight_min, weight_max;
  double weight_low, weight_high;

} back__p_partcond_t, *back__p_partcond_p;


/* internal partition conditions, sl_type back__p__partcond_intern_t back__p_partcond_intern_t back__p_partcond_intern_p */
typedef struct back__p__partcond_intern_t
{
  back__p_slint_t pcm;
  back__p_slint_t count_min, count_max;
  back__p_slint_t count_low, count_high;
#ifdef elem_weight
  back__p_slweight_t weight_min, weight_max;
  back__p_slweight_t weight_low, weight_high;
#endif

} back__p_partcond_intern_t, *back__p_partcond_intern_p;


/* sl_type back__p__parttype_t back__p_parttype_t back__p_parttype_p */
typedef struct back__p__parttype_t
{
  back__p_slint_t type;

} back__p_parttype_t, *back__p_parttype_p;


/* generic binning method */

/* sl_type back__p__bin_t back__p_bin_t */
typedef struct back__p__bin_t
{
  back__p_elements_t s;

#ifdef elem_weight
  back__p_slweight_t weight;
#endif

} back__p_bin_t;


/* sl_type back__p__splitter_t back__p_splitter_t */
typedef struct back__p__splitter_t
{
  back__p_slint_t n;

  int *displs;
  back__p_slkey_pure_t *s;
  back__p_slint_t *sn;

} back__p_splitter_t;


struct back__p__binning_t;

/* sl_type back__p_binning_pre_f back__p_binning_exec_f back__p_binning_refine_f back__p_binning_hit_f back__p_binning_finalize_f back__p_binning_post_f */
typedef back__p_slint_t (*back__p_binning_pre_f)(struct back__p__binning_t *bm);
typedef back__p_slint_t (*back__p_binning_exec_f)(struct back__p__binning_t *bm, back__p_bin_t *bin, back__p_slcount_t *counts, back__p_slweight_t *weights);
typedef back__p_slint_t (*back__p_binning_refine_f)(struct back__p__binning_t *bm, back__p_bin_t *bin, back__p_slint_t k, back__p_slcount_t *counts, back__p_slweight_t *weights, back__p_splitter_t *sp, back__p_slint_t s, back__p_bin_t *new_bin);
typedef back__p_slint_t (*back__p_binning_hit_f)(struct back__p__binning_t *bm, back__p_bin_t *bin, back__p_slint_t k, back__p_slcount_t *counts, back__p_splitter_t *sp, back__p_slint_t s);
typedef back__p_slint_t (*back__p_binning_finalize_f)(struct back__p__binning_t *bm, back__p_bin_t *bin, back__p_slint_t dc, back__p_slweight_t dw, back__p_slint_t lc_min, back__p_slint_t lc_max, back__p_slcount_t *lcs, back__p_slweight_t *lws, back__p_splitter_t *sp, back__p_slint_t s);
typedef back__p_slint_t (*back__p_binning_post_f)(struct back__p__binning_t *bm);


/* sl_type back__p__binning_data_t back__p_binning_data_t */
typedef union back__p__binning_data_t
{
  struct
  {
    back__p_slint_t rhigh, rlow, rwidth;
    back__p_slint_t rcurrent;
    back__p_slkey_pure_t bit_mask;

    back__p_elements_t sx;

  } radix;

} back__p_binning_data_t;


/* sl_type back__p__binning_t back__p_binning_t */
typedef struct back__p__binning_t
{
  back__p_slint_t nbins, max_nbins;
  
  back__p_binning_pre_f pre;
  back__p_binning_exec_f exec;
  back__p_binning_refine_f refine;
  back__p_binning_hit_f hit;
  back__p_binning_finalize_f finalize;
  back__p_binning_post_f post;

  back__p_slint_t sorted;

  back__p_slint_t docounts;
#ifdef elem_weight
  back__p_slint_t doweights;
#endif

  back__p_binning_data_t bd;

} back__p_binning_t;


/* sl_type back__p__local_bins_t back__p_local_bins_t */
typedef struct back__p__local_bins_t
{
  back__p_binning_t *bm;

  back__p_slint_t nbins, max_nbins;
  back__p_slint_t nelements;

  back__p_slint_t docounts;
#ifdef elem_weight
  back__p_slint_t doweights;
#endif

  back__p_slint_t nbinnings, max_nbinnings;

  back__p_slint_t nbins_new, last_new_b, last_new_k;
  back__p_bin_t *bins, *bins_new;
  back__p_bin_t *bins0, *bins1;

  back__p_slint_t *bcws;

#if defined(elem_weight) && defined(back__p_sl_weight_intequiv)
  back__p_slint_t cw_factor, w_index, bin_cw_factor;
  back__p_slweight_t *cws, *bin_cws;
  back__p_slweight_t *prefix_cws;
#else
  back__p_slint_t *cs, *bin_cs;
  back__p_slint_t *prefix_cs;
# ifdef elem_weight
  back__p_slweight_t *ws, *bin_ws;
  back__p_slweight_t *prefix_ws;
# endif
#endif

  back__p_slint_t last_exec_b;

} back__p_local_bins_t;


/* sl_type back__p__global_bins_t back__p_global_bins_t */
typedef struct back__p__global_bins_t
{
  back__p_binning_t *bm;
  
  back__p_local_bins_t lb;

  back__p_slint_t *bcws;

#if defined(elem_weight) && defined(back__p_sl_weight_intequiv)
  back__p_slweight_t *cws;
  back__p_slweight_t *prefix_cws;
#else
  back__p_slint_t *cs;
  back__p_slint_t *prefix_cs;
# ifdef elem_weight
  back__p_slweight_t *ws;
  back__p_slweight_t *prefix_ws;
# endif
#endif

} back__p_global_bins_t;


/* sl_type back__p_rti_cmc_t */
typedef struct
{
  back__p_slint_t cmp, movek, moved;

} back__p_rti_cmc_t;

#ifndef my_rti_ccmp
# define my_rti_ccmp(m)    m.cmc.cmp
# define my_rti_cmovek(m)  m.cmc.movek
# define my_rti_cmoved(m)  m.cmc.moved
#endif


/* sl_type back__p_rti_tim_t */
typedef struct
{
  double start, stop;
  double last, cumu;

  back__p_slint_t num;

} back__p_rti_tim_t[rti_tids];

#ifndef my_rti_tlast
# define my_rti_tlast(m, t)  m.tim[t].last
# define my_rti_tcumu(m, t)  m.tim[t].cumu
# define my_rti_tnum(m, t)   m.tim[t].num
#endif


/* sl_type back__p_rti_mem_t */
typedef struct
{
  back__p_slint_t nalloc, nfree;
  back__p_slint_t max, cur, cur_max;

} back__p_rti_mem_t;


/* sl_type back__p_rti_t */
typedef struct
{
  /* compare-move-counter */
  back__p_rti_cmc_t cmc;
  /* timer */
  back__p_rti_tim_t tim;
  /* memory */
  back__p_rti_mem_t mem;

} back__p_rti_t;

#ifndef my_rti_reset
# define my_rti_reset(m)  memset((void *) &m, 0, sizeof(m))
#endif


/* sl_type back__p__sl_context_t back__p_sl_context_t */
typedef struct back__p__sl_context_t
{

/* src/base/base.c */
  struct {
int dummy_rank;
  } sl;
#ifdef back__p_SL_USE_RTI
back__p_rti_t rti;
#endif
  struct {
back__p_slint_t ip_threshold;
back__p_slint_t db_threshold;
back__p_slint_t ma_threshold;
  } sr;
  struct {
back__p_slint_t threshold;
  } sri;
/* src/base_mpi/base_mpi.c */
#ifdef SL_USE_MPI
  struct {
MPI_Datatype int_datatype;
MPI_Datatype key_datatype;
MPI_Datatype pkey_datatype;
MPI_Datatype pwkey_datatype;
MPI_Datatype index_datatype;
MPI_Datatype weight_datatype;
MPI_Datatype data_datatype[SL_DATA_NMAX + 1];
int rank;
  } mpi;
#endif
#ifdef SL_USE_MPI
  struct {
void *sendrecv_replace_mem;
back__p_slint_t sendrecv_replace_memsize;
back__p_slint_t sendrecv_replace_mpi_maxsize;
  } me;
#endif
#ifdef SL_USE_MPI
  struct {
double t[2];
back__p_slint_t max_nprocs;
back__p_slint_t packed;
double overalloc;
  } meas;
#endif
#ifdef SL_USE_MPI
  struct {
back__p_slint_t packed;
back__p_slint_t db_packed;
back__p_slint_t ip_packed;
  } mea;
#endif
#ifdef SL_USE_MPI
  struct {
#ifdef back__p_MSEG_ROOT
int root;
#endif
#ifdef back__p_MSEG_BORDER_UPDATE_REDUCTION
double border_update_count_reduction;
double border_update_weight_reduction;
#endif
#ifdef back__p_MSEG_FORWARD_ONLY
back__p_slint_t forward_only;
#endif
#ifdef back__p_MSEG_INFO
back__p_slint_t info_rounds;
back__p_slint_t *info_finish_rounds;
double info_finish_rounds_avg;
back__p_slweight_t info_total_weights;
#endif
back__p_slint_t binnings;
back__p_slint_t finalize_mode;
  } mseg;
#endif
#ifdef SL_USE_MPI
  struct {
#ifdef back__p_MSS_ROOT
int root;
#endif
  } mss;
#endif
#ifdef SL_USE_MPI
  struct {
double t[4];
back__p_slint_t sync;
  } msm;
#endif
#ifdef SL_USE_MPI
  struct {
double t[4];
back__p_slint_t sync;
back__p_partcond_t *r_pc;
  } msp;
#endif
#ifdef SL_USE_MPI
  struct {
double i_t[3];
double p_t[3];
double b_t[3];
back__p_slint_t sync;
back__p_slint_t i_sync;
back__p_slint_t p_sync;
back__p_slint_t b_sync;
back__p_slint_t back_packed;
  } mssp;
#endif
} back__p_sl_context_t;






/* sl_macro back__p_elem_set_size back__p_elem_set_max_size back__p_elem_set_keys back__p_elem_set_indices */
#define back__p_elem_set_size(_e_, _s_)      ((_e_)->size = (_s_))
#define back__p_elem_set_max_size(_e_, _s_)  ((_e_)->max_size = (_s_))
#define back__p_elem_set_keys(_e_, _k_)      ((_e_)->keys = (_k_))
#define back__p_elem_set_indices(_e_, _i_)   ((_e_)->indices = (_i_))
/* DATAX_TEMPLATE_BEGIN */
#define back__p_elem_set_data0(_e_, _b_)     ((_e_)->data0 = (_b_))  /* sl_macro */
#define back__p_elem_set_data1(_e_, _b_)     ((_e_)->data1 = (_b_))  /* sl_macro */
#define back__p_elem_set_data2(_e_, _b_)     ((_e_)->data2 = (_b_))  /* sl_macro */
#define back__p_elem_set_data3(_e_, _b_)     ((_e_)->data3 = (_b_))  /* sl_macro */
#define back__p_elem_set_data4(_e_, _b_)     ((_e_)->data4 = (_b_))  /* sl_macro */
#define back__p_elem_set_data5(_e_, _b_)     ((_e_)->data5 = (_b_))  /* sl_macro */
#define back__p_elem_set_data6(_e_, _b_)     ((_e_)->data6 = (_b_))  /* sl_macro */
#define back__p_elem_set_data7(_e_, _b_)     ((_e_)->data7 = (_b_))  /* sl_macro */
#define back__p_elem_set_data8(_e_, _b_)     ((_e_)->data8 = (_b_))  /* sl_macro */
#define back__p_elem_set_data9(_e_, _b_)     ((_e_)->data9 = (_b_))  /* sl_macro */
#define back__p_elem_set_data10(_e_, _b_)     ((_e_)->data10 = (_b_))  /* sl_macro */
#define back__p_elem_set_data11(_e_, _b_)     ((_e_)->data11 = (_b_))  /* sl_macro */
#define back__p_elem_set_data12(_e_, _b_)     ((_e_)->data12 = (_b_))  /* sl_macro */
#define back__p_elem_set_data13(_e_, _b_)     ((_e_)->data13 = (_b_))  /* sl_macro */
#define back__p_elem_set_data14(_e_, _b_)     ((_e_)->data14 = (_b_))  /* sl_macro */
#define back__p_elem_set_data15(_e_, _b_)     ((_e_)->data15 = (_b_))  /* sl_macro */
#define back__p_elem_set_data16(_e_, _b_)     ((_e_)->data16 = (_b_))  /* sl_macro */
#define back__p_elem_set_data17(_e_, _b_)     ((_e_)->data17 = (_b_))  /* sl_macro */
#define back__p_elem_set_data18(_e_, _b_)     ((_e_)->data18 = (_b_))  /* sl_macro */
#define back__p_elem_set_data19(_e_, _b_)     ((_e_)->data19 = (_b_))  /* sl_macro */
/* DATAX_TEMPLATE_END */

/* sl_macro back__p_elem_get_size back__p_elem_get_max_size back__p_elem_get_keys back__p_elem_get_indices */
#define back__p_elem_get_size(_e_)           (_e_)->size
#define back__p_elem_get_max_size(_e_)       (_e_)->max_size
#define back__p_elem_get_keys(_e_)           (_e_)->keys
#define back__p_elem_get_indices(_e_)        (_e_)->indices
/* DATAX_TEMPLATE_BEGIN */
#define back__p_elem_get_data0(_e_)          (_e_)->data0  /* sl_macro */
#define back__p_elem_get_data1(_e_)          (_e_)->data1  /* sl_macro */
#define back__p_elem_get_data2(_e_)          (_e_)->data2  /* sl_macro */
#define back__p_elem_get_data3(_e_)          (_e_)->data3  /* sl_macro */
#define back__p_elem_get_data4(_e_)          (_e_)->data4  /* sl_macro */
#define back__p_elem_get_data5(_e_)          (_e_)->data5  /* sl_macro */
#define back__p_elem_get_data6(_e_)          (_e_)->data6  /* sl_macro */
#define back__p_elem_get_data7(_e_)          (_e_)->data7  /* sl_macro */
#define back__p_elem_get_data8(_e_)          (_e_)->data8  /* sl_macro */
#define back__p_elem_get_data9(_e_)          (_e_)->data9  /* sl_macro */
#define back__p_elem_get_data10(_e_)          (_e_)->data10  /* sl_macro */
#define back__p_elem_get_data11(_e_)          (_e_)->data11  /* sl_macro */
#define back__p_elem_get_data12(_e_)          (_e_)->data12  /* sl_macro */
#define back__p_elem_get_data13(_e_)          (_e_)->data13  /* sl_macro */
#define back__p_elem_get_data14(_e_)          (_e_)->data14  /* sl_macro */
#define back__p_elem_get_data15(_e_)          (_e_)->data15  /* sl_macro */
#define back__p_elem_get_data16(_e_)          (_e_)->data16  /* sl_macro */
#define back__p_elem_get_data17(_e_)          (_e_)->data17  /* sl_macro */
#define back__p_elem_get_data18(_e_)          (_e_)->data18  /* sl_macro */
#define back__p_elem_get_data19(_e_)          (_e_)->data19  /* sl_macro */
/* DATAX_TEMPLATE_END */

/* sl_macro back__p_elem_set_block back__p_elem_set_block_size back__p_elem_get_block back__p_elem_get_block_size */
#define back__p_elem_set_block(_e_, _b_)       ((_e_)->keys = (_b_), (_e_)->max_size = -1)
#define back__p_elem_set_block_size(_e_, _s_)  ((_e_)->size = (_s_))
#define back__p_elem_get_block(_e_)            ((void *) (((_e_)->max_size < 0)?(_e_)->keys:NULL))
#define back__p_elem_get_block_size(_e_)       (_e_)->size

/* sl_macro back__p_pelem_set_size back__p_pelem_set_max_size back__p_pelem_set_elements */
#define back__p_pelem_set_size(_e_, _s_)      ((_e_)->size = (_s_))
#define back__p_pelem_set_max_size(_e_, _s_)  ((_e_)->max_size = (_s_))
#define back__p_pelem_set_elements(_e_, _l_)  ((_e_)->elements = (_l_))

/* sl_macro back__p_pelem_get_size back__p_pelem_get_max_size back__p_pelem_get_elements */
#define back__p_pelem_get_size(_e_)           (_e_)->size
#define back__p_pelem_get_max_size(_e_)       (_e_)->max_size
#define back__p_pelem_get_elements(_e_)       (_e_)->elements

/* sl_macro back__p_SL_DEFCON */
#define back__p_SL_DEFCON(_v_)  (back__p_sl_default_context._v_)






/* src/base/base.c */
extern back__p_sl_context_t back__p_sl_default_context;
extern const int back__p_default_sl_dummy_rank;
#ifdef back__p_SL_USE_RTI
extern const back__p_rti_t back__p_default_rti;
#endif
extern const back__p_slint_t back__p_default_sr_ip_threshold;
extern const back__p_slint_t back__p_default_sr_db_threshold;
extern const back__p_slint_t back__p_default_sr_ma_threshold;
extern const back__p_slint_t back__p_default_sri_threshold;

/* src/base_mpi/base_mpi.c */
#ifdef SL_USE_MPI
extern const MPI_Datatype back__p_default_mpi_int_datatype;
extern const MPI_Datatype back__p_default_mpi_key_datatype;
extern const MPI_Datatype back__p_default_mpi_pkey_datatype;
extern const MPI_Datatype back__p_default_mpi_pwkey_datatype;
extern const MPI_Datatype back__p_default_mpi_index_datatype;
extern const MPI_Datatype back__p_default_mpi_weight_datatype;
extern const MPI_Datatype back__p_default_mpi_data_datatype[];
extern const int back__p_default_mpi_rank;
#endif
extern const void *back__p_default_me_sendrecv_replace_mem;
extern const back__p_slint_t back__p_default_me_sendrecv_replace_memsize;
extern const back__p_slint_t back__p_default_me_sendrecv_replace_mpi_maxsize;
extern const double back__p_default_meas_t[];
extern const back__p_slint_t back__p_default_meas_max_nprocs;
extern const back__p_slint_t back__p_default_meas_packed;
extern const double back__p_default_meas_overalloc;
extern const back__p_slint_t back__p_default_mea_packed;
extern const back__p_slint_t back__p_default_mea_db_packed;
extern const back__p_slint_t back__p_default_mea_ip_packed;
#ifdef back__p_MSEG_ROOT
extern const int back__p_default_mseg_root;
#endif
#ifdef back__p_MSEG_BORDER_UPDATE_REDUCTION
extern const double back__p_default_mseg_border_update_count_reduction;
extern const double back__p_default_mseg_border_update_weight_reduction;
#endif
#ifdef back__p_MSEG_FORWARD_ONLY
extern const back__p_slint_t back__p_default_mseg_forward_only;
#endif
#ifdef back__p_MSEG_INFO
extern const back__p_slint_t back__p_default_mseg_info_rounds;
extern const back__p_slint_t *back__p_default_mseg_info_finish_rounds;
extern const double back__p_default_mseg_info_finish_rounds_avg;
extern const back__p_slweight_t back__p_default_mseg_info_total_weights;
#endif
extern const back__p_slint_t back__p_default_mseg_binnings;
extern const back__p_slint_t back__p_default_mseg_finalize_mode;
#ifdef back__p_MSS_ROOT
extern const int back__p_default_mss_root;
#endif
extern const double back__p_default_msm_t[];
extern const back__p_slint_t back__p_default_msm_sync;
extern const double back__p_default_msp_t[];
extern const back__p_slint_t back__p_default_msp_sync;
extern const back__p_partcond_t *back__p_default_msp_r_pc;
extern const double back__p_default_mssp_i_t[];
extern const double back__p_default_mssp_p_t[];
extern const double back__p_default_mssp_b_t[];
extern const back__p_slint_t back__p_default_mssp_sync;
extern const back__p_slint_t back__p_default_mssp_i_sync;
extern const back__p_slint_t back__p_default_mssp_p_sync;
extern const back__p_slint_t back__p_default_mssp_b_sync;
extern const back__p_slint_t back__p_default_mssp_back_packed;






/* src/base/base.c */
back__p_slint_t SL_PROTO(back__p_binning_create)(back__p_local_bins_t *lb, back__p_slint_t max_nbins, back__p_slint_t max_nbinnings, back__p_elements_t *s, back__p_slint_t nelements, back__p_slint_t docounts, back__p_slint_t doweights, back__p_binning_t *bm);
back__p_slint_t SL_PROTO(back__p_binning_destroy)(back__p_local_bins_t *lb);
back__p_slint_t SL_PROTO(back__p_binning_pre)(back__p_local_bins_t *lb);
back__p_slint_t SL_PROTO(back__p_binning_exec_reset)(back__p_local_bins_t *lb, back__p_slint_t do_bins, back__p_slint_t do_prefixes);
back__p_slint_t SL_PROTO(back__p_binning_exec)(back__p_local_bins_t *lb, back__p_slint_t b, back__p_slint_t do_bins, back__p_slint_t do_prefixes);
back__p_slint_t SL_PROTO(back__p_binning_refine)(back__p_local_bins_t *lb, back__p_slint_t b, back__p_slint_t k, back__p_splitter_t *sp, back__p_slint_t s);
back__p_slint_t SL_PROTO(back__p_binning_hit)(back__p_local_bins_t *lb, back__p_slint_t b, back__p_slint_t k, back__p_splitter_t *sp, back__p_slint_t s);
back__p_slint_t SL_PROTO(back__p_binning_finalize)(back__p_local_bins_t *lb, back__p_slint_t b, back__p_slint_t dc, back__p_slweight_t dw, back__p_slint_t lc_min, back__p_slint_t lc_max, back__p_slcount_t *lcs, back__p_slweight_t *lws, back__p_splitter_t *sp, back__p_slint_t s);
back__p_slint_t SL_PROTO(back__p_binning_post)(back__p_local_bins_t *lb);
back__p_slint_t SL_PROTO(back__p_binning_radix_create)(back__p_binning_t *bm, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, back__p_slint_t sorted);
back__p_slint_t SL_PROTO(back__p_binning_radix_destroy)(back__p_binning_t *bm);
back__p_slint_t SL_PROTO(back__p_binning_radix_pre)(back__p_binning_t *bm);
back__p_slint_t SL_PROTO(back__p_binning_radix_exec)(back__p_binning_t *bm, back__p_bin_t *bin, back__p_slcount_t *counts, back__p_slweight_t *weights);
back__p_slint_t SL_PROTO(back__p_binning_radix_refine)(back__p_binning_t *bm, back__p_bin_t *bin, back__p_slint_t k, back__p_slcount_t *counts, back__p_slweight_t *weights, back__p_splitter_t *sp, back__p_slint_t s, back__p_bin_t *new_bin);
back__p_slint_t SL_PROTO(back__p_binning_radix_hit)(back__p_binning_t *bm, back__p_bin_t *bin, back__p_slint_t k, back__p_slcount_t *counts, back__p_splitter_t *sp, back__p_slint_t s);
back__p_slint_t SL_PROTO(back__p_binning_radix_finalize)(back__p_binning_t *bm, back__p_bin_t *bin, back__p_slint_t dc, back__p_slweight_t dw, back__p_slint_t lc_min, back__p_slint_t lc_max, back__p_slcount_t *lcs, back__p_slweight_t *lws, back__p_splitter_t *sp, back__p_slint_t s);
back__p_slint_t SL_PROTO(back__p_binning_radix_post)(back__p_binning_t *bm);
back__p_slint_t SL_PROTO(back__p_elements_alloc)(back__p_elements_t *s, back__p_slint_t nelements, slcint_t components);
back__p_slint_t SL_PROTO(back__p_elements_free)(back__p_elements_t *s);
back__p_slint_t SL_PROTO(back__p_elements_realloc)(back__p_elements_t *s, back__p_slint_t nelements, slcint_t components);
back__p_slint_t SL_PROTO(back__p_elements_alloca)(back__p_elements_t *s, back__p_slint_t nelements, slcint_t components);
back__p_slint_t SL_PROTO(back__p_elements_freea)(back__p_elements_t *s);
back__p_slint_t SL_PROTO(back__p_elements_alloc_from_blocks)(back__p_elements_t *s, back__p_slint_t nblocks, void **blocks, back__p_slint_t *blocksizes, back__p_slint_t alignment, back__p_slint_t nmax, slcint_t components);
back__p_slint_t SL_PROTO(back__p_elements_alloc_from_block)(back__p_elements_t *s, void *block, back__p_slint_t blocksize, back__p_slint_t alignment, back__p_slint_t nmax, slcint_t components);
back__p_slint_t SL_PROTO(back__p_elements_alloc_block)(back__p_elements_t *s, void **block, back__p_slint_t *blocksize, back__p_slint_t alignment, back__p_slint_t maxblocksize);
back__p_slint_t SL_PROTO(back__p_elements_copy)(back__p_elements_t *s, back__p_elements_t *d);
back__p_slint_t SL_PROTO(back__p_elements_copy_at)(back__p_elements_t *s, back__p_slint_t sat, back__p_elements_t *d, back__p_slint_t dat);
back__p_slint_t SL_PROTO(back__p_elements_ncopy)(back__p_elements_t *s, back__p_elements_t *d, back__p_slint_t n);
back__p_slint_t SL_PROTO(back__p_elements_nmove)(back__p_elements_t *s, back__p_elements_t *d, back__p_slint_t n);
back__p_slint_t SL_PROTO(back__p_elements_printf)(back__p_elements_t *s, const char *prefix);
back__p_slint_t SL_PROTO(back__p_elements_extract)(back__p_elements_t *src, back__p_slint_t nelements, back__p_elements_t *dst0, back__p_elements_t *dst1);
back__p_slint_t SL_PROTO(back__p_elements_touch)(back__p_elements_t *s);
back__p_slint_t SL_PROTO(back__p_elements_digest_sum)(back__p_elements_t *s, back__p_slint_t nelements, slcint_t components, unsigned int *sum);
unsigned int SL_PROTO(back__p_elements_crc32)(back__p_elements_t *s, back__p_slint nelements, back__p_slint_t keys, back__p_slint_t data);
back__p_slint_t SL_PROTO(back__p_elements_digest_hash)(back__p_elements_t *s, back__p_slint_t nelements, slcint_t components, void *hash);
back__p_slint_t SL_PROTO(back__p_elements_random_exchange)(back__p_elements_t *s, back__p_slint_t rounds, back__p_elements_t *xs);
back__p_slint_t SL_PROTO(back__p_elements_keys_init_seed)(unsigned long s);
back__p_slint_t SL_PROTO(back__p_elements_keys_init)(back__p_elements_t *s, back__p_keys_init_type_t t, back__p_keys_init_data_t d);
back__p_slint_t SL_PROTO(back__p_elements_keys_init_randomized)(back__p_elements_t *s, back__p_slint_t nkeys, back__p_keys_init_type_t t, back__p_keys_init_data_t d);
back__p_slint_t SL_PROTO(back__p_elements_keys_init_from_file)(back__p_elements_t *s, back__p_slint_t data, char *filename, back__p_slint_t from, back__p_slint_t to, back__p_slint_t const_bytes_per_line);
back__p_slint_t SL_PROTO(back__p_elements_keys_save_to_file)(back__p_elements_t *s, char *filename);
back__p_slint_t SL_PROTO(back__p_elements_validate_order)(back__p_elements_t *s, back__p_slint_t n);
back__p_slint_t SL_PROTO(back__p_elements_validate_order_bmask)(back__p_elements_t *s, back__p_slint_t n, back__p_slkey_pure_t bmask);
back__p_slint_t SL_PROTO(back__p_elements_validate_order_weight)(back__p_elements_t *s, back__p_slint_t n, back__p_slkey_pure_t weight);
back__p_slint_t SL_PROTO(back__p_elements_keys_stats)(back__p_elements_t *s, back__p_slkey_pure_t *stats);
back__p_slint_t SL_PROTO(back__p_elements_keys_stats_print)(back__p_elements_t *s);
back__p_slint_t SL_PROTO(back__p_elements_print_keys)(back__p_elements_t *s);
back__p_slint_t SL_PROTO(back__p_elements_print_all)(back__p_elements_t *s);
back__p_slweight_t SL_PROTO(back__p_elements_get_weight)(back__p_elements_t *s);
back__p_slint_t SL_PROTO(back__p_elements_get_minmax_keys)(back__p_elements_t *s, back__p_slint_t nelements, back__p_slkey_pure_t *minmaxkeys);
back__p_slint_t SL_PROTO(back__p_elements_alloc_packed)(back__p_packed_elements_t *s, back__p_slint_t nelements);
back__p_slint_t SL_PROTO(back__p_elements_free_packed)(back__p_packed_elements_t *s);
back__p_slint_t SL_PROTO(back__p_elements_alloc_packed_from_block)(back__p_packed_elements_t *s, void *block, back__p_slint_t blocksize, back__p_slint_t alignment, back__p_slint_t nmax);
back__p_slint_t SL_PROTO(back__p_elements_pack_indexed)(back__p_elements_t *s, back__p_packed_elements_t *d, back__p_slindex_t *rindx, back__p_slindex_t *windx);
back__p_slint_t SL_PROTO(back__p_elements_pack)(back__p_elements_t *s, back__p_packed_elements_t *d);
back__p_slint_t SL_PROTO(back__p_elements_pack_at)(back__p_elements_t *s, back__p_slint_t sat, back__p_packed_elements_t *d, back__p_slint_t dat);
back__p_slint_t SL_PROTO(back__p_elements_unpack_indexed)(back__p_packed_elements_t *s, back__p_elements_t *d, back__p_slindex_t *rindx, back__p_slindex_t *windx);
back__p_slint_t SL_PROTO(back__p_elements_unpack)(back__p_packed_elements_t *s, back__p_elements_t *d);
back__p_slint_t SL_PROTO(back__p_elements_unpack_at)(back__p_packed_elements_t *s, back__p_slint_t sat, back__p_elements_t *d, back__p_slint_t dat);
back__p_slint_t SL_PROTO(back__p_elements_unpack_keys)(back__p_packed_elements_t *s, back__p_slkey_t *k);
back__p_slint SL_PROTO(back__p_merge2_basic_auto_01_x)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint SL_PROTO(back__p_merge2_basic_01_x)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx, back__p_m2x_func _x0_1, back__p_m2x_func _0x_1);
back__p_slint SL_PROTO(back__p_merge2_basic_01_X)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx, back__p_elements_t *t, back__p_m2X_func _X0_1, back__p_m2X_func _0X_1);
back__p_slint SL_PROTO(back__p_merge2_simplify_s1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx, back__p_slint s1elements);
back__p_slint SL_PROTO(back__p_merge2_memory_adaptive)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_compo_hula)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *xs);
back__p_slint_t SL_PROTO(back__p_merge2_basic_sseq_x0_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_sseq_0x_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_sseq_01_x)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_sseq_01)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_merge2_basic_sbin_x0_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_sbin_0x_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_sbin_01_x)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_sbin_01)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_merge2_basic_shyb_x0_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_shyb_0x_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_shyb_01_x)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_shyb_01)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_merge2_basic_straight_x0_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_straight_0x_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_straight_01_x)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_straight_x_0_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_merge2_basic_straight_X0_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_merge2_basic_straight_0X_1)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_merge2_basic_straight_01_X)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_merge2_basic_straight_X0_1u)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_merge2_compo_tridgell)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_mergep_2way_ip_int)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t p, int *displs, back__p_merge2x_f m2x);
back__p_slint_t SL_PROTO(back__p_mergep_2way_ip_int_rec)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t p, int *displs, back__p_merge2x_f m2x);
back__p_slint_t SL_PROTO(back__p_mergep_heap_int)(back__p_elements_t *s, back__p_elements_t *d, back__p_slint_t p, int *displs, int *counts);
back__p_slint_t SL_PROTO(back__p_mergep_heap_int_idx)(back__p_elements_t *s, back__p_elements_t *d, back__p_slint_t p, int *displs, int *counts);
back__p_slint_t SL_PROTO(back__p_mergep_heap_idx)(back__p_elements_t *s, back__p_elements_t *d, back__p_slint_t p, back__p_slindex_t *displs, back__p_slindex_t *counts);
back__p_slint_t SL_PROTO(back__p_mergep_heap_unpack_idx)(back__p_packed_elements_t *s, back__p_elements_t *d, back__p_slint_t p, back__p_slindex_t *displs, back__p_slindex_t *counts);
back__p_slint_t SL_PROTO(back__p_mergep_heap_unpack_idxonly)(back__p_packed_elements_t *s, back__p_elements_t *d, back__p_slint_t p, back__p_slindex_t *displs, back__p_slindex_t *counts);
back__p_slint_t SL_PROTO(back__p_permute_generic_db)(back__p_elements_t *s, back__p_elements_t *d, back__p_permute_generic_t *pg, void *pg_data);
back__p_slint_t SL_PROTO(back__p_permute_generic_ip)(back__p_elements_t *s, back__p_elements_t *x, back__p_permute_generic_t *pg, void *pg_data);
back__p_slint SL_PROTO(back__p_sl_search_sequential_lt)(back__p_elements_t *s, back__p_slpkey_t k);
back__p_slint SL_PROTO(back__p_sl_search_sequential_le)(back__p_elements_t *s, back__p_slpkey_t k);
back__p_slint SL_PROTO(back__p_sl_search_sequential_gt)(back__p_elements_t *s, back__p_slpkey_t k);
back__p_slint SL_PROTO(back__p_sl_search_sequential_ge)(back__p_elements_t *s, back__p_slpkey_t k);
back__p_slint SL_PROTO(back__p_sl_search_p_sequential_lt)(back__p_elements_t *s, back__p_slpkey_t *k);
back__p_slint SL_PROTO(back__p_sl_search_p_sequential_le)(back__p_elements_t *s, back__p_slpkey_t *k);
back__p_slint SL_PROTO(back__p_sl_search_p_sequential_gt)(back__p_elements_t *s, back__p_slpkey_t *k);
back__p_slint SL_PROTO(back__p_sl_search_p_sequential_ge)(back__p_elements_t *s, back__p_slpkey_t *k);
back__p_slint SL_PROTO(back__p_sl_search_binary_lt)(back__p_elements_t *s, back__p_slpkey_t k);
back__p_slint SL_PROTO(back__p_sl_search_binary_le)(back__p_elements_t *s, back__p_slpkey_t k);
back__p_slint SL_PROTO(back__p_sl_search_binary_gt)(back__p_elements_t *s, back__p_slpkey_t k);
back__p_slint SL_PROTO(back__p_sl_search_binary_ge)(back__p_elements_t *s, back__p_slpkey_t k);
back__p_slint SL_PROTO(back__p_sl_search_p_binary_lt)(back__p_elements_t *s, back__p_slpkey_t *k);
back__p_slint SL_PROTO(back__p_sl_search_p_binary_le)(back__p_elements_t *s, back__p_slpkey_t *k);
back__p_slint SL_PROTO(back__p_sl_search_p_binary_gt)(back__p_elements_t *s, back__p_slpkey_t *k);
back__p_slint SL_PROTO(back__p_sl_search_p_binary_ge)(back__p_elements_t *s, back__p_slpkey_t *k);
back__p_slint_t SL_PROTO(back__p_sl_search_binary_lt_bmask)(back__p_elements_t *s, back__p_slpkey_t k, back__p_slpkey_t bmask);
back__p_slint_t SL_PROTO(back__p_sl_search_binary_le_bmask)(back__p_elements_t *s, back__p_slpkey_t k, back__p_slpkey_t bmask);
back__p_slint_t SL_PROTO(back__p_sl_search_binary_sign_switch)(back__p_elements_t *s);
back__p_slint SL_PROTO(back__p_sl_search_hybrid_lt)(back__p_elements_t *s, back__p_slpkey_t k, back__p_slint t);
back__p_slint SL_PROTO(back__p_sl_search_hybrid_le)(back__p_elements_t *s, back__p_slpkey_t k, back__p_slint t);
back__p_slint SL_PROTO(back__p_sl_search_hybrid_gt)(back__p_elements_t *s, back__p_slpkey_t k, back__p_slint t);
back__p_slint SL_PROTO(back__p_sl_search_hybrid_ge)(back__p_elements_t *s, back__p_slpkey_t k, back__p_slint t);
back__p_slint SL_PROTO(back__p_sl_search_p_hybrid_lt)(back__p_elements_t *s, back__p_slpkey_t *k, back__p_slint t);
back__p_slint SL_PROTO(back__p_sl_search_p_hybrid_le)(back__p_elements_t *s, back__p_slpkey_t *k, back__p_slint t);
back__p_slint SL_PROTO(back__p_sl_search_p_hybrid_gt)(back__p_elements_t *s, back__p_slpkey_t *k, back__p_slint t);
back__p_slint SL_PROTO(back__p_sl_search_p_hybrid_ge)(back__p_elements_t *s, back__p_slpkey_t *k, back__p_slint t);
back__p_slint SL_PROTO(back__p_ilog2c)(back__p_slint x);
back__p_slint SL_PROTO(back__p_ilog2f)(back__p_slint x);
back__p_slint SL_PROTO(back__p_print_bits)(back__p_slint v);
back__p_slint SL_PROTO(back__p_pivot_random)(back__p_elements_t *s);
back__p_slint_t SL_PROTO(back__p_counts2displs)(back__p_slint_t n, int *counts, int *displs);
back__p_slint_t SL_PROTO(back__p_displs2counts)(back__p_slint_t n, int *displs, int *counts, back__p_slint_t total_counts);
void SL_PROTO(back__p_get_displcounts_extent)(back__p_slint_t n, int *displs, int *counts, back__p_slint_t *lb, back__p_slint_t *extent);
void SL_PROTO(back__p_elem_set_data)(back__p_elements_t *e, ...);
back__p_slint_t SL_PROTO(back__p_elem_get_max_byte)();
back__p_slint_t SL_PROTO(back__p_elem_reverse)(back__p_elements_t *e, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_elem_nxchange_at)(back__p_elements_t *e0, back__p_slint_t at0, back__p_elements_t *e1, back__p_slint_t at1, back__p_slint_t n, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_elem_nxchange)(back__p_elements_t *e0, back__p_elements_t *e1, back__p_slint_t n, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_elem_nxchange_ro0)(back__p_elements_t *e0, back__p_elements_t *e1, back__p_slint_t n, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_elem_rotate)(back__p_elements_t *e, back__p_slint_t m, back__p_slint_t n, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_elem_rotate_ro0)(back__p_elements_t *e, back__p_slint_t m, back__p_slint_t n, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_elem_rotate_ro1)(back__p_elements_t *e, back__p_slint_t m, back__p_slint_t n, back__p_elements_t *t);
back__p_slint_t SL_PROTO(back__p_sort_counting_use_displs)(back__p_elements_t *s, back__p_elements_t *d, back__p_slint_t ndispls, back__p_slint_t *displs);
back__p_slint_t SL_PROTO(back__p_sort_counting_use_counts)(back__p_elements_t *s, back__p_elements_t *d, back__p_slint_t ncounts, back__p_slint_t *counts);
back__p_slint_t SL_PROTO(back__p_sort_counting_get_counts)(back__p_elements_t *s, back__p_elements_t *d, back__p_slint_t ncounts, back__p_slint_t *counts);
back__p_slint_t SL_PROTO(back__p_sort_counting)(back__p_elements_t *s, back__p_elements_t *d, back__p_slint_t ncounts);
back__p_slint SL_PROTO(back__p_sort_heap)(back__p_elements_t *s, back__p_elements_t *xs);
back__p_slint_t SL_PROTO(back__p_sort_insert_bmask_kernel)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slkey_pure_t bmask);
back__p_slint_t SL_PROTO(back__p_sort_insert)(back__p_elements_t *s, back__p_elements_t *sx);
back__p_slint_t SL_PROTO(back__p_sort_permute_forward)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t *perm, back__p_slint_t offset, back__p_slint_t mask_bit);
back__p_slint_t SL_PROTO(back__p_sort_permute_backward)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t *perm, back__p_slint_t offset, back__p_slint_t mask_bit);
back__p_slint SL_PROTO(back__p_sort_quick)(back__p_elements_t *s, back__p_elements_t *xs);
back__p_slint_t SL_PROTO(back__p_sort_radix_ip)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth);
back__p_slint_t SL_PROTO(back__p_sort_radix_db)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth);
back__p_slint_t SL_PROTO(back__p_sort_radix_ma)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth);
back__p_slint_t SL_PROTO(back__p_sort_radix)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth);
back__p_slint_t SL_PROTO(back__p_sort_radix_1bit_kernel)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t rhigh, back__p_slint_t rlow);
back__p_slint SL_PROTO(back__p_sort_radix_1bit)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t rhigh, back__p_slint_t rlow);
back__p_slint_t SL_PROTO(back__p_sort_radix_iter)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t presorted, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth);
back__p_slint SL_PROTO(back__p_sn_hypercube_lh)(back__p_slint size, back__p_slint rank, back__p_slint stage, void *snp, back__p_slint *up);
back__p_slint SL_PROTO(back__p_sn_hypercube_hl)(back__p_slint size, back__p_slint rank, back__p_slint stage, void *snp, back__p_slint *up);
back__p_slint SL_PROTO(back__p_sn_odd_even_trans)(back__p_slint size, back__p_slint rank, back__p_slint stage, void *snp, back__p_slint *up);
back__p_slint SL_PROTO(back__p_sn_odd)(back__p_slint size, back__p_slint rank, back__p_slint stage, void *snp, back__p_slint *up);
back__p_slint SL_PROTO(back__p_sn_even)(back__p_slint size, back__p_slint rank, back__p_slint stage, void *snp, back__p_slint *up);
back__p_slint SL_PROTO(back__p_sn_batcher)(back__p_slint size, back__p_slint rank, back__p_slint stage, void *snp, back__p_slint *up);
back__p_slint SL_PROTO(back__p_sn_bitonic)(back__p_slint size, back__p_slint rank, back__p_slint stage, void *snp, back__p_slint *up);
back__p_slint SL_PROTO(back__p_sn_connected)(back__p_slint size, back__p_slint rank, back__p_slint stage, void *snp, back__p_slint *up);
back__p_slint_t SL_PROTO(back__p_split_generic_db)(back__p_elements_t *s, back__p_elements_t *d, back__p_split_generic_t *sg, void *sg_data, back__p_slint_t n);
back__p_slint_t SL_PROTO(back__p_split_generic_ip)(back__p_elements_t *s, back__p_elements_t *d, back__p_split_generic_t *sg, void *sg_data, back__p_slint_t n);
back__p_slint_t SL_PROTO(back__p_split_generic_count_db)(back__p_elements_t *s, back__p_split_generic_t *sg, void *sg_data, int *counts, back__p_slint_t n);
back__p_slint_t SL_PROTO(back__p_split_generic_count_ip)(back__p_elements_t *s, back__p_split_generic_t *sg, void *sg_data, int *counts, back__p_slint_t n);
back__p_slint_t SL_PROTO(back__p_split_generic_rearrange_db)(back__p_elements_t *s, back__p_elements_t *d, back__p_split_generic_t *sg, void *sg_data, int *counts, back__p_slint_t n);
back__p_slint_t SL_PROTO(back__p_split_generic_rearrange_ip)(back__p_elements_t *s, back__p_elements_t *d, back__p_split_generic_t *sg, void *sg_data, int *counts, int *displs, back__p_slint_t n);
back__p_slint_t SL_PROTO(back__p_splitter_reset)(back__p_splitter_t *sp);
back__p_slint_t SL_PROTO(back__p_splitx_radix)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint_t nclasses, back__p_slint_t shl, back__p_slint_t *counts);
back__p_slint SL_PROTO(back__p_split2_lt_ge)(back__p_elements_t *s, back__p_slkey_pure_t *k, back__p_elements_t *t);
back__p_slint SL_PROTO(back__p_split2_le_gt)(back__p_elements_t *s, back__p_slkey_pure_t *k, back__p_elements_t *t);
back__p_slint SL_PROTO(back__p_split3_lt_eq_gt)(back__p_elements_t *s, back__p_slkey_pure_t *k, back__p_elements_t *t, back__p_slint *nlt, back__p_slint *nle);
back__p_slint SL_PROTO(back__p_split3_lt_eq_gt_old)(back__p_elements_t *s, back__p_slkey_pure_t *k, back__p_elements_t *t, back__p_slint *nlt, back__p_slint *nle);
back__p_slint SL_PROTO(back__p_split2_b)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slkey_pure_t bmask);
back__p_slint SL_PROTO(back__p_splitk_k2c_af)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint k, back__p_slint *c, back__p_k2c_func k2c, void *k2c_data);
back__p_slint SL_PROTO(back__p_splitk_k2c)(back__p_elements_t *s, back__p_elements_t *sx, back__p_slint k, back__p_slint *c, back__p_k2c_func k2c, void *k2c_data);
back__p_slint SL_PROTO(back__p_splitk_k2c_count)(back__p_elements_t *s, back__p_slint k, back__p_slint *c, back__p_k2c_func k2c, void *k2c_data);


#ifdef SL_USE_MPI





/* src/base_mpi/base_mpi.c */
back__p_slint_t SL_PROTO(back__p_mpi_binning_create)(back__p_global_bins_t *gb, back__p_slint_t max_nbins, back__p_slint_t max_nbinnings, back__p_elements_t *s, back__p_slint_t nelements, back__p_slint_t docounts, back__p_slint_t doweights, back__p_binning_t *bm, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_binning_destroy)(back__p_global_bins_t *gb, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_binning_pre)(back__p_global_bins_t *gb, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_binning_exec_reset)(back__p_global_bins_t *gb, back__p_slint_t do_bins, back__p_slint_t do_prefixes, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_binning_exec_local)(back__p_global_bins_t *gb, back__p_slint_t b, back__p_slint_t do_bins, back__p_slint_t do_prefixes, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_binning_exec_global)(back__p_global_bins_t *gb, back__p_slint_t do_bins, back__p_slint_t do_prefixes, back__p_slint_t root, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_binning_refine)(back__p_global_bins_t *gb, back__p_slint_t b, back__p_slint_t k, back__p_splitter_t *sp, back__p_slint_t s, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_binning_hit)(back__p_global_bins_t *gb, back__p_slint_t b, back__p_slint_t k, back__p_splitter_t *sp, back__p_slint_t s, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_binning_finalize)(back__p_global_bins_t *gb, back__p_slint_t b, back__p_slint_t dc, back__p_slweight_t dw, back__p_slint_t lc_min, back__p_slint_t lc_max, back__p_slcount_t *lcs, back__p_slweight_t *lws, back__p_splitter_t *sp, back__p_slint_t s, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_binning_post)(back__p_global_bins_t *gb, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_datatypes_init)();
back__p_slint_t SL_PROTO(back__p_mpi_datatypes_release)();
back__p_slint_t SL_PROTO(back__p_mpi_get_grid_properties)(back__p_slint_t ndims, back__p_slint_t *dims, back__p_slint_t *pos, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_subgroups_create)(back__p_slint_t nsubgroups, MPI_Comm *sub_comms, int *sub_sizes, int *sub_ranks, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_subgroups_delete)(back__p_slint_t nsubgroups, MPI_Comm *sub_comms, int size, int rank, MPI_Comm comm);
int SL_PROTO(back__p_sl_MPI_Allreduce)(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, int size, int rank);
int SL_PROTO(back__p_sl_MPI_Alltoall_int)(void *sendbuf, int sendcount, void *recvbuf, int recvcount, MPI_Comm comm, int size, int rank);
back__p_slint_t SL_PROTO(back__p_mpi_elements_keys_init_from_file)(back__p_elements_t *s, char *filename, back__p_slint from, back__p_slint to, back__p_slint const_bytes_per_line, back__p_slint root, int size, int rank, MPI_Comm comm);
back__p_slint SL_PROTO(back__p_mpi_elements_validate_order)(back__p_elements_t *s, back__p_slint n, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_linear_exchange_pure_keys)(back__p_slkey_pure_t *in, back__p_slkey_pure_t *out, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_check_order)(back__p_elements_t *s, back__p_slint_t nelements, back__p_slint_t *orders, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_check_global_order)(back__p_slkey_pure_t local_min, back__p_slkey_pure_t local_max, int root, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_digest_sum)(back__p_elements_t *s, back__p_slint_t nelements, slcint_t components, unsigned int *sum, int size, int rank, MPI_Comm comm);
unsigned int SL_PROTO(back__p_mpi_elements_crc32)(back__p_elements_t *s, back__p_slint_t n, back__p_slint_t keys, back__p_slint_t data, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_digest_hash)(back__p_elements_t *s, back__p_slint_t nelements, slcint_t components, void *hash, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_get_counts)(back__p_elements_t *s, back__p_slint_t *clocal, back__p_slint_t *cglobal, int root, int size, int rank, MPI_Comm comm);
back__p_slweight_t SL_PROTO(back__p_mpi_elements_get_weights)(back__p_elements_t *s, back__p_slweight_t *wlocal, back__p_slweight_t *wglobal, int root, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_get_counts_and_weights)(back__p_elements_t *s, back__p_slint_t nelements, back__p_slint_t *counts, back__p_slweight_t *weights, int root, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_sendrecv_replace)(back__p_elements_t *s, int count, int dest, int sendtag, int source, int recvtag, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_tproc_create_tproc)(back__p_tproc_t *tproc, back__p_tproc_f *tfn, back__p_tproc_reset_f *rfn, back__p_tproc_exdef exdef);
back__p_slint_t SL_PROTO(back__p_tproc_create_tproc_mod)(back__p_tproc_t *tproc, back__p_tproc_mod_f *tfn, back__p_tproc_reset_f *rfn, back__p_tproc_exdef exdef);
back__p_slint_t SL_PROTO(back__p_tproc_create_tprocs)(back__p_tproc_t *tproc, back__p_tprocs_f *tfn, back__p_tproc_reset_f *rfn, back__p_tproc_exdef exdef);
back__p_slint_t SL_PROTO(back__p_tproc_create_tprocs_mod)(back__p_tproc_t *tproc, back__p_tprocs_mod_f *tfn, back__p_tproc_reset_f *rfn, back__p_tproc_exdef exdef);
back__p_slint_t SL_PROTO(back__p_tproc_free)(back__p_tproc_t *tproc);
back__p_slint_t SL_PROTO(back__p_tproc_set_proclist)(back__p_tproc_t *tproc, back__p_slint_t nsend_procs, int *send_procs, back__p_slint_t nrecv_procs, int *recv_procs, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_tproc_verify)(back__p_tproc_t tproc, void *data, back__p_elements_t *s, int proc);
back__p_slint_t SL_PROTO(back__p_mpi_elements_alltoall_specific)(back__p_elements_t *sin, back__p_elements_t *sout, back__p_elements_t *xs, back__p_tproc_t tproc, void *data, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_alltoallv_db_packed)(back__p_elements_t *sbuf, int *scounts, int *sdispls, back__p_elements_t *rbuf, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_alltoallv_db)(back__p_elements_t *sbuf, int *scounts, int *sdispls, back__p_elements_t *rbuf, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_alltoallv_ip_packed)(back__p_elements_t *s, back__p_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_alltoallv_ip_double)(back__p_elements_t *s, back__p_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_alltoallv_ip_mpi)(back__p_elements_t *s, back__p_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_alltoallv_ip_dash)(back__p_elements_t *s, back__p_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_alltoallv_ip)(back__p_elements_t *s, back__p_elements_t *sx, int *scounts, int *sdispls, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_elements_packed_datatype_create)(MPI_Datatype *pdt, back__p_slint_t structured);
back__p_slint_t SL_PROTO(back__p_mpi_elements_packed_datatype_destroy)(MPI_Datatype *pdt);
back__p_slint_t SL_PROTO(back__p_mpi_find_exact_equal)(back__p_elements_t *s, back__p_slint_t other_rank, back__p_slint_t high_rank, back__p_slint_t *ex_start, back__p_slint_t *ex_size, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_find_exact)(back__p_elements_t *s, back__p_slint_t other_rank, back__p_slint_t high_rank, back__p_slint_t *dst_size, back__p_slint_t *ex_start, back__p_slint_t *ex_sizes, back__p_slint_t *nx_move, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_merge2)(back__p_elements_t *s, back__p_slint_t other_rank, back__p_slint_t high_rank, back__p_slint_t *dst_size, back__p_merge2x_f m2, back__p_elements_t *xs, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_mergek_equal)(back__p_elements_t *s, back__p_sortnet_f sn, back__p_sortnet_data_t snd, back__p_merge2x_f m2x, back__p_elements_t *xs, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_mergek_sorted)(back__p_elements_t *s, back__p_merge2x_f m2x, back__p_elements_t *xs, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_mergek)(back__p_elements_t *s, back__p_sortnet_f sn, back__p_sortnet_data_t snd, back__p_merge2x_f m2x, back__p_elements_t *xs, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_mergek_equal2)(back__p_elements_t *s, back__p_sortnet_f sn, back__p_sortnet_data_t snd, back__p_merge2x_f m2x, back__p_elements_t *xs, int *sizes, int *ranks, MPI_Comm *comms);
back__p_slint_t SL_PROTO(back__p_mpi_partition_exact_generic)(back__p_elements_t *s, back__p_partcond_t *pcond, back__p_binning_t *bm, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_partition_exact_radix)(back__p_elements_t *s, back__p_partcond_t *pcond, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, back__p_slint_t sorted, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_partition_exact_radix_ngroups)(back__p_elements_t *s, back__p_partcond_t *pcond, back__p_slint_t ngroups, MPI_Comm *group_comms, back__p_elements_t *sx, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_partition_exact_radix_2groups)(back__p_elements_t *s, back__p_partcond_t *pcond, MPI_Comm group_comm, back__p_elements_t *sx, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_partition_sample_regular)(back__p_elements_t *s, back__p_partcond_t *pcond, int *scounts, int *rcounts, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_rebalance)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_slint_t stable, back__p_slint_t *dst_size, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_rebalance_alltoallv)(back__p_elements_t *sbuf, int *scounts, int *sdispls, back__p_elements_t *rbuf, int *rcounts, int *rdispls, int size, int rank, MPI_Comm comm);
void SL_PROTO(back__p_mpi_partcond_set_even)(back__p_partcond_t *pcond, back__p_slint_t pcm, back__p_slint_t ntotal, double nimba, double wtotal, double wimba, int size, int rank);
back__p_slint_t SL_PROTO(back__p_init_partconds)(back__p_slint_t npconds, back__p_partcond_t *pconds, back__p_slint_t nparts, back__p_slint_t total_count, back__p_slweight_t total_weight);
back__p_slint_t SL_PROTO(back__p_init_partconds_intern)(back__p_slint_t npconds, back__p_partcond_intern_t *pci, back__p_partcond_t *pc, back__p_slint_t nparts, back__p_slint_t total_count, back__p_slweight_t total_weight);
back__p_slint_t SL_PROTO(back__p_merge_partconds)(back__p_partcond_t *pconds_in, back__p_slint_t npconds_in, back__p_partcond_t *pcond_out);
back__p_slint_t SL_PROTO(back__p_mpi_gather_partconds_grouped)(back__p_partcond_t *pcond_in, MPI_Comm pcond_in_comm, MPI_Comm pconds_out_comm, back__p_partcond_t *pconds_out, back__p_slint_t *npconds_out, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_gather_partconds)(back__p_partcond_t *pcond_in, back__p_partcond_t *pconds_out, int root, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_allgather_partconds)(back__p_partcond_t *pcond_in, back__p_partcond_t *pconds_out, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_bcast_partconds)(back__p_slint_t npconds, back__p_partcond_t *pconds, int root, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_post_check_partconds)(back__p_elements_t *s, back__p_slint_t nelements, back__p_slint_t nparts, back__p_partcond_t *pconds, int *sdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_post_check_partconds_intern)(back__p_elements_t *s, back__p_slint_t nelements, back__p_slint_t nparts, back__p_partcond_intern_t *pci, int *sdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_select_stats)(back__p_elements_t *s, back__p_slint_t nparts, int *sdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_select_exact_generic_bulk)(back__p_elements_t *s, back__p_slint_t nelements, back__p_slint_t nparts, back__p_partcond_t *pconds, back__p_binning_t *bm, back__p_splitter_t *sp, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_select_exact_generic_grouped)(back__p_elements_t *s, back__p_slint_t nelements, back__p_partcond_t *pcond, MPI_Comm pcond_comm, MPI_Comm group_comm, back__p_binning_t *bm, back__p_splitter_t *sp, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_select_exact_generic)(back__p_elements_t *s, back__p_slint_t nelements, back__p_slint_t nparts, back__p_partcond_t *pconds, back__p_binning_t *bm, back__p_splitter_t *sp, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_select_exact_radix)(back__p_elements_t *s, back__p_slint_t nelements, back__p_slint_t nparts, back__p_partcond_t *pconds, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, back__p_slint_t sorted, int *sdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_select_exact_radix_grouped)(back__p_elements_t *s, back__p_slint_t nelements, back__p_partcond_t *pcond, MPI_Comm pcond_comm, MPI_Comm group_comm, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, back__p_slint_t sorted, int *sdispls, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_select_sample_regular)(back__p_elements_t *s, back__p_slint_t nparts, back__p_partcond_t *pconds, back__p_slint_t nsamples, back__p_splitter_t *sp, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_merge)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *xs, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_merge2)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *xs, back__p_slint_t merge_type, back__p_slint_t sort_type, double *times, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_merge_radix)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *xs, back__p_slint_t merge_type, back__p_slint_t sort_type, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_partition)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *xs, back__p_slint_t part_type, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_partition_radix)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *xs, back__p_slint_t part_type, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_partition_exact_radix)(back__p_elements_t *s, back__p_elements_t *sx, back__p_partcond_t *pcond, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_partition_exact_radix_ngroups)(back__p_elements_t *s, back__p_elements_t *sx, back__p_partcond_t *pcond, back__p_slint_t ngroups, MPI_Comm *group_comms, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_partition_exact_radix_2groups)(back__p_elements_t *s, back__p_elements_t *sx, back__p_partcond_t *pcond, MPI_Comm group_comm, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_insert_radix)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *xs, back__p_slpkey_t *mmkeys, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_presorted_radix)(back__p_elements_t *s0, back__p_elements_t *s1, back__p_elements_t *xs, back__p_slint_t merge_type, back__p_slint_t rhigh, back__p_slint_t rlow, back__p_slint_t rwidth, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_sort_back)(back__p_elements_t *sin, back__p_elements_t *sout, back__p_elements_t *sx, back__p_slpkey_t *lh, back__p_slint_t ntotal, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_xcounts2ycounts_all2all)(int *xcounts, int *ycounts, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_xcounts2ycounts_sparse)(int *xcounts, int *ycounts, back__p_slint_t ytotal, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_xcounts2ycounts_grouped)(int *xcounts, back__p_slint_t nxcounts, int *ycounts, MPI_Comm group_comm, MPI_Comm master_comm, int size, int rank, MPI_Comm comm);
back__p_slint_t SL_PROTO(back__p_mpi_subxdispls2ycounts)(back__p_slint_t nsubs, int *sub_xdispls, back__p_slint_t *sub_sources, back__p_slint_t *sub_sizes, MPI_Comm sub_comm, int sub_size, int *ycounts, int size, int rank, MPI_Comm comm);


#endif /* SL_USE_MPI */


#undef SL_PROTO
#endif /* __SL_BACK__P_H__ */
