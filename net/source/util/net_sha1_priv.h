/***************************************************************************//**
 * @file
 * @brief Network Crypto Sha1 Utility
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

#ifndef  _NET_SHA1_PRIV_H_
#define  _NET_SHA1_PRIV_H_

/********************************************************************************************************
 ********************************************************************************************************
 *                                               INCLUDE FILES
 ********************************************************************************************************
 *******************************************************************************************************/

#include  "../tcpip/net_priv.h"

#include  <common/include/lib_mem.h>

/********************************************************************************************************
 ********************************************************************************************************
 *                                                   DEFINES
 ********************************************************************************************************
 *******************************************************************************************************/

#define  NET_SHA1_HASH_SIZE                 20

#define  NET_SHA1_INTERMEDIATE_HASH_SIZE    NET_SHA1_HASH_SIZE / 4

/********************************************************************************************************
 ********************************************************************************************************
 *                                               DATA TYPES
 ********************************************************************************************************
 *******************************************************************************************************/

typedef struct net_sha1_context {
  CPU_INT32U  Intermediate_Hash[NET_SHA1_INTERMEDIATE_HASH_SIZE];

  CPU_INT32U  Length_Low;                                       // Message length in bits
  CPU_INT32U  Length_High;                                      // Message length in bits

  //                                                               Index into message block array
  CPU_INT16U  Message_Block_Index;
  CPU_INT08U  Message_Block[64];                                // 512-bit message blocks

  CPU_BOOLEAN Computed;                                         // Is the digest computed?
  RTOS_ERR    Corrupted;                                        // Is the message digest corrupted?
} NET_SHA1_CTX;

/********************************************************************************************************
 ********************************************************************************************************
 *                                           FUNCTION PROTOTYPES
 ********************************************************************************************************
 *******************************************************************************************************/

CPU_BOOLEAN NetSHA1_Reset(NET_SHA1_CTX *p_ctx,
                          RTOS_ERR     *p_err);

CPU_BOOLEAN NetSHA1_Input(NET_SHA1_CTX   *p_ctx,
                          const CPU_CHAR *p_msg,
                          CPU_INT32U     len,
                          RTOS_ERR       *p_err);

CPU_BOOLEAN NetSHA1_Result(NET_SHA1_CTX *p_ctx,
                           CPU_CHAR     *p_msg_digest,
                           RTOS_ERR     *p_err);

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MODULE END
 ********************************************************************************************************
 *******************************************************************************************************/

#endif  // _NET_SHA1_PRIV_H_