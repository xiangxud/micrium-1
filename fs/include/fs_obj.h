/***************************************************************************//**
 * @file
 * @brief File System - Core Generic Object Operations
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.
 * The software is governed by the sections of the MSLA applicable to Micrium
 * Software.
 *
 ******************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MODULE
 ********************************************************************************************************
 *******************************************************************************************************/

#ifndef  FS_OBJ_H_
#define  FS_OBJ_H_

/********************************************************************************************************
 ********************************************************************************************************
 *                                           INCLUDE FILES
 ********************************************************************************************************
 *******************************************************************************************************/

#include  <cpu/include/cpu.h>

/********************************************************************************************************
 ********************************************************************************************************
 *                                               DATA TYPES
 ********************************************************************************************************
 *******************************************************************************************************/

typedef CPU_INT16U FS_OBJ_ID;

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MACRO'S
 ********************************************************************************************************
 *******************************************************************************************************/

#define   FS_OBJ_FOR_EACH(cur_obj_handle, func_prefix, type_prefix) \
  for (CPU_INT08U iter = 0u; iter <= 2u; iter++)                    \
    if (iter == 0u) {                                               \
    } else if (iter == 2u) {                                        \
      if (!type_prefix##_HANDLE_IS_NULL(cur_obj_handle)) {          \
        func_prefix##_Release(cur_obj_handle);                      \
      }                                                             \
    } else                                                          \
      for (cur_obj_handle = func_prefix##_FirstAcquire();           \
           !type_prefix##_HANDLE_IS_NULL(cur_obj_handle);           \
           cur_obj_handle = func_prefix##_NextAcquire(cur_obj_handle))

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MODULE END
 ********************************************************************************************************
 *******************************************************************************************************/

#endif
