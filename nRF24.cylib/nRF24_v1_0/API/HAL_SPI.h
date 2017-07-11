/****************************************************************************
* This file is part of the nRF24 Custom Component for PSoC Devices.
*
* Copyright (C) 2017 Carlos Diaz <carlos.santiago.diaz@gmail.com>
*
* Permission to use, copy, modify, and/or distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
****************************************************************************/

#ifndef `$INSTANCE_NAME`_HAL_SPI_H
#define `$INSTANCE_NAME`_HAL_SPI_H
    
#include <cytypes.h>
#include <cyfitter.h>
    
#include <string.h>
    
#include "`$INSTANCE_NAME`_REGS.h"

uint8_t `$INSTANCE_NAME`_ReadRegister(const NrfRegister reg);
void `$INSTANCE_NAME`_ReadLongRegister(const NrfRegister reg, uint8_t* data , const size_t size);
void `$INSTANCE_NAME`_WriteRegister(const NrfRegister reg, const uint8_t data);
void `$INSTANCE_NAME`_WriteLongRegister(const NrfRegister reg, const uint8_t* data, size_t size);
uint8_t `$INSTANCE_NAME`_ReadBit(const NrfRegister reg, uint8_t bit);
void `$INSTANCE_NAME`_WriteBit(const NrfRegister reg, const uint8_t bit, const uint8_t value);
void `$INSTANCE_NAME`_ClearBit(const NrfRegister reg, const uint8_t bit);
void `$INSTANCE_NAME`_SetBit(const NrfRegister reg, const uint8_t bit);
void `$INSTANCE_NAME`_SendCommand(const NrfCmd cmd);
void `$INSTANCE_NAME`_ReadRXPayloadCmd(uint8_t* data, const size_t size);
void `$INSTANCE_NAME`_WriteTXPayloadCmd(const uint8_t* data, const size_t size);
void `$INSTANCE_NAME`_FlushRxCmd(void);
void `$INSTANCE_NAME`_FlushTxCmd(void);
void `$INSTANCE_NAME`_ReuseTxPayloadCmd(void);
uint8_t `$INSTANCE_NAME`_ReadPayloadWidthCmd(void);
void `$INSTANCE_NAME`_WriteACKPayloadCmd(const NrfDataPipe pipe, const uint8_t* data, const size_t size);
void `$INSTANCE_NAME`_NoACKPayloadCmd(const uint8_t* data, const size_t size);
uint8_t `$INSTANCE_NAME`_NOPCmd(void);

#endif /* `$INSTANCE_NAME`_HAL_SPI_H */

/* [] END OF FILE */
