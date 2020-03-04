/***************************************************************************//**
 * @file
 * @brief CPU - Arm Cortex-M Port
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.  This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/****************************************************************************************************//**
 * @note     (1) This driver targets the following:
 *                   Core      : ARMv7M and ARMv8M Cortex-M
 *                   Mode      : Thumb-2 ISA
 *                   Toolchain : IAR EWARM
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                               INCLUDE FILES
 ********************************************************************************************************
 *******************************************************************************************************/

#define    MICRIUM_SOURCE
#include  "armv7m_cpu_port.h"
#include  <cpu/include/cpu.h>
#include  <common/include/lib_utils.h>

#ifdef __cplusplus
extern  "C" {
#endif

/********************************************************************************************************
 ********************************************************************************************************
 *                                               LOCAL DEFINES
 ********************************************************************************************************
 *******************************************************************************************************/

#define  CPU_INT_SRC_POS_MAX                  ((((CPU_REG_NVIC_NVIC + 1) & 0x1F) * 32) + 16)

#define  CPU_BIT_BAND_SRAM_REG_LO                 0x20000000
#define  CPU_BIT_BAND_SRAM_REG_HI                 0x200FFFFF
#define  CPU_BIT_BAND_SRAM_BASE                   0x22000000

#define  CPU_BIT_BAND_PERIPH_REG_LO               0x40000000
#define  CPU_BIT_BAND_PERIPH_REG_HI               0x400FFFFF
#define  CPU_BIT_BAND_PERIPH_BASE                 0x42000000

/********************************************************************************************************
 ********************************************************************************************************
 *                                           LOCAL CONSTANTS
 ********************************************************************************************************
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                           LOCAL DATA TYPES
 ********************************************************************************************************
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                               LOCAL TABLES
 ********************************************************************************************************
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                       LOCAL GLOBAL VARIABLES
 ********************************************************************************************************
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                       LOCAL FUNCTION PROTOTYPES
 ********************************************************************************************************
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                       LOCAL CONFIGURATION ERRORS
 ********************************************************************************************************
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                           GLOBAL FUNCTIONS
 ********************************************************************************************************
 *******************************************************************************************************/

/****************************************************************************************************//**
 *                                               CPU_BitBandClr()
 *
 * @brief    Clear bit in bit-band region.
 *
 * @param    addr        Byte address in memory space.
 *
 * @param    bit_nbr     Bit number in byte.
 *
 * @note     (1) This function is DEPRECATED and will be removed in a future version of this product.
 *
 * @deprecated
 *******************************************************************************************************/
void CPU_BitBandClr(CPU_ADDR   addr,
                    CPU_INT08U bit_nbr)
{
  CPU_ADDR bit_word_off;
  CPU_ADDR bit_word_addr;

  if ((addr >= CPU_BIT_BAND_SRAM_REG_LO)
      && (addr <= CPU_BIT_BAND_SRAM_REG_HI)) {
    bit_word_off = ((addr - CPU_BIT_BAND_SRAM_REG_LO) * 32) + (bit_nbr * 4);
    bit_word_addr = CPU_BIT_BAND_SRAM_BASE   + bit_word_off;

    *(volatile CPU_INT32U *)(bit_word_addr) = 0;
  } else if ((addr >= CPU_BIT_BAND_PERIPH_REG_LO)
             && (addr <= CPU_BIT_BAND_PERIPH_REG_HI)) {
    bit_word_off = ((addr - CPU_BIT_BAND_PERIPH_REG_LO) * 32) + (bit_nbr * 4);
    bit_word_addr = CPU_BIT_BAND_PERIPH_BASE + bit_word_off;

    *(volatile CPU_INT32U *)(bit_word_addr) = 0;
  }
}

/****************************************************************************************************//**
 *                                               CPU_BitBandSet()
 *
 * @brief    Set bit in bit-band region.
 *
 * @param    addr        Byte address in memory space.
 *
 * @param    bit_nbr     Bit number in byte.
 *
 * @note     (1) This function is DEPRECATED and will be removed in a future version of this product.
 *
 * @deprecated
 *******************************************************************************************************/
void CPU_BitBandSet(CPU_ADDR   addr,
                    CPU_INT08U bit_nbr)
{
  CPU_ADDR bit_word_off;
  CPU_ADDR bit_word_addr;

  if ((addr >= CPU_BIT_BAND_SRAM_REG_LO)
      && (addr <= CPU_BIT_BAND_SRAM_REG_HI)) {
    bit_word_off = ((addr - CPU_BIT_BAND_SRAM_REG_LO) * 32) + (bit_nbr * 4);
    bit_word_addr = CPU_BIT_BAND_SRAM_BASE   + bit_word_off;

    *(volatile CPU_INT32U *)(bit_word_addr) = 1;
  } else if ((addr >= CPU_BIT_BAND_PERIPH_REG_LO)
             && (addr <= CPU_BIT_BAND_PERIPH_REG_HI)) {
    bit_word_off = ((addr - CPU_BIT_BAND_PERIPH_REG_LO) * 32) + (bit_nbr * 4);
    bit_word_addr = CPU_BIT_BAND_PERIPH_BASE + bit_word_off;

    *(volatile CPU_INT32U *)(bit_word_addr) = 1;
  }
}

#ifdef __cplusplus
}
#endif