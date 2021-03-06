/************************************************************************************
 * arch/arm/src/lpc54xx/lpc54_lowputc.h
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_LPC54XX_LPC54_LOWPUTC_H
#define __ARCH_ARM_SRC_LPC54XX_LPC54_LOWPUTC_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>

/************************************************************************************
 * Public Types
 ************************************************************************************/

#ifdef HAVE_USART_DEVICE
/* This structure describes the configuration of an UART */

struct uart_config_s
{
  uint32_t baud;          /* Configured baud */
  uint32_t fclk;          /* Input Flexcomm function clock frequency */
  uint8_t  parity;        /* 0=none, 1=odd, 2=even */
  uint8_t  bits;          /* Number of bits (5-9) */
  uint8_t  txlevel;       /* TX level for event generation */
  uint8_t  rxlevel;       /* RX level for event generation */
  bool     stopbits2;     /* true: Configure with 2 stop bits instead of 1 */
#ifdef CONFIG_SERIAL_IFLOWCONTROL
  bool     iflow;         /* true: Input flow control supported */
#endif
#ifdef CONFIG_SERIAL_OFLOWCONTROL
  bool     oflow;         /* true: Output flow control supported. */
#endif
};
#endif

/************************************************************************************
 * Public Functions
 ************************************************************************************/

/************************************************************************************
 * Name: lpc54_lowsetup
 *
 * Description:
 *   Called at the very beginning of _start.  Performs low level initialization
 *   including setup of the console USART.  This USART initialization is done
 *   early so that the serial console is available for debugging very early in
 *   the boot sequence.
 *
 ************************************************************************************/

void lpc54_lowsetup(void);

/************************************************************************************
 * Name: lpc54_usart_configure
 *
 * Description:
 *   Configure a UART for non-interrupt driven operation
 *
 ************************************************************************************/

#ifdef HAVE_USART_DEVICE
void lpc54_usart_configure(uintptr_t base, FAR const struct uart_config_s *config);
#endif

/****************************************************************************
 * Name: lpc54_usart_disable
 *
 * Description:
 *   Disable a USART.  it will be necessary to again call
 *   lpc54_usart_configure() in order to use this USART channel again.
 *
 ****************************************************************************/

#ifdef HAVE_USART_DEVICE
void lpc54_usart_disable(uintptr_t base);
#endif

#endif /* __ARCH_ARM_SRC_LPC54XX_LPC54_LOWPUTC_H */
