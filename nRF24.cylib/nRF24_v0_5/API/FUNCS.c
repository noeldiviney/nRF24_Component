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

#include <`$SPI_INTERFACE`.h>
#include <`$SS_PIN`.h>
#include <`$CE_PIN`.h>

#if defined (CY_SCB_`$SPI_INTERFACE`_H)
	#include <`$SPI_INTERFACE`_SPI_UART.h>
#endif

#include "`$INSTANCE_NAME`_FUNCS.h"
#include "`$INSTANCE_NAME`_REGS.h"
#include "`$INSTANCE_NAME`_HAL_SPI.h"

// nRF24 Power-on-reset delay
#define `$INSTANCE_NAME`_POR_DELAY 100

// PSoC Component Functions

// Configure the radio and clear TX and RX FIFOs.
void `$INSTANCE_NAME`_Start(void)
{
    CyDelay(`$INSTANCE_NAME`_POR_DELAY);
    `$SPI_INTERFACE`_Start();
    `$SS_PIN`_Write(1);
    `$INSTANCE_NAME`_Init();
    `$INSTANCE_NAME`_FlushRxCmd();
    `$INSTANCE_NAME`_FlushTxCmd();
    // TODO: Listen or not based on the mode
}

// Configure the nRF24 registers with the data of the customizer.
void `$INSTANCE_NAME`_Init(void)
{
    `$INSTANCE_NAME`_WriteRegister(NRF_CONFIG_REG,
                (`$MASK_RX_DR` << NRF_CONFIG_MASK_RX_DR)
                | (`$MASK_TX_DS` << NRF_CONFIG_MASK_TX_DS)
                | (`$MASK_MAX_RT` << NRF_CONFIG_MASK_MAX_RT)
                | (`$EN_CRC` << NRF_CONFIG_EN_CRC)
                | (`$CRCO` << NRF_CONFIG_CRCO)
                | (`$PRIM_RX` << NRF_CONFIG_PRIM_RX));
    `$INSTANCE_NAME`_WriteRegister(NRF_EN_AA_REG,
                (`$ENAA_P5` << NRF_EN_AA_ENAA_P5)
                | (`$ENAA_P4` << NRF_EN_AA_ENAA_P4)
                | (`$ENAA_P3` << NRF_EN_AA_ENAA_P3)
                | (`$ENAA_P2` << NRF_EN_AA_ENAA_P2)
                | (`$ENAA_P1` << NRF_EN_AA_ENAA_P1) 
                | (`$ENAA_P0` << NRF_EN_AA_ENAA_P0));
    `$INSTANCE_NAME`_WriteRegister(NRF_EN_RXADDR_REG,
                (`$ERX_P5` << NRF_EN_RXADDR_ERX_P5)
                | (`$ERX_P4` << NRF_EN_RXADDR_ERX_P4)
                | (`$ERX_P3` << NRF_EN_RXADDR_ERX_P3)
                | (`$ERX_P2` << NRF_EN_RXADDR_ERX_P2)
                | (`$ERX_P1` << NRF_EN_RXADDR_ERX_P1)
                | (`$ERX_P0` << NRF_EN_RXADDR_ERX_P0));
    `$INSTANCE_NAME`_WriteRegister(NRF_SETUP_AW_REG, `$AW`);
    `$INSTANCE_NAME`_WriteRegister(NRF_SETUP_RETR_REG,
                (`$ARD` << NRF_SETUP_RETR_ARD_SHIFT)
                | `$ARC`);
    `$INSTANCE_NAME`_WriteRegister(NRF_RF_CH_REG, `$RF_CH`);
    `$INSTANCE_NAME`_WriteRegister(NRF_RF_SETUP_REG,
                (`$CONT_WAVE` << NRF_RF_SETUP_CONT_WAVE)
                | (`$RF_DATA_RATE` << NRF_RF_SETUP_RF_DR)
                | (`$RF_PWR` << NRF_RF_SETUP_RF_PWR));
    `$INSTANCE_NAME`_WriteRegister(NRF_DYNPD_REG,
                (`$DPL_P5` << NRF_DYNPD_DPL_P5)
                | (`$DPL_P4` << NRF_DYNPD_DPL_P4)
                | (`$DPL_P3` << NRF_DYNPD_DPL_P3)
                | (`$DPL_P2` << NRF_DYNPD_DPL_P2)
                | (`$DPL_P1` << NRF_DYNPD_DPL_P1)
                | (`$DPL_P0` << NRF_DYNPD_DPL_P0));
    `$INSTANCE_NAME`_WriteRegister(NRF_FEATURE_REG,
                (`$EN_DPL` << NRF_FEATURE_EN_DPL)
                | (`$EN_ACK_PAY` << NRF_FEATURE_EN_ACK_PAY) 
                | (`$EN_DYN_ACK` << NRF_FEATURE_EN_DYN_ACK));
}

// Enable the nRF24 component.
void `$INSTANCE_NAME`_Enable(void)
{
    // TODO    
}

// Stop the nRF24 component, and all the internal components.
void `$INSTANCE_NAME`_Stop(void)
{
    // TODO
}

// Put the nRF24 component on Sleep mode also all the internal components.
void `$INSTANCE_NAME`_Sleep(void)
{
    // TODO
}

// Wakeup the nRF24 components, and restore the configuration.
void `$INSTANCE_NAME`_Wakeup(void)
{
    // TODO
}

// Save the nRF24 component configuration.
void `$INSTANCE_NAME`_SaveConfig(void)
{
    // TODO
}

// Restore the nRF24 component configuration.
void `$INSTANCE_NAME`_RestoreConfig(void)
{
    // TODO
}

// nRF24 Functions

// Configuration functions

void `$INSTANCE_NAME`_SetMode(const NRF_MODE_t mode)
{
#if 1
    NRF_MODE_TX == mode ?
        `$INSTANCE_NAME`_SetTxMode() :
        `$INSTANCE_NAME`_SetRxMode() ;
#else
    if( NRF_MODE_TX == mode )
    {
        `$INSTANCE_NAME`_SetTxMode();
    } else {
        `$INSTANCE_NAME`_SetRxMode();
    }
#endif
}

// In power down mode nRF24 is disabled using minimal current consumption.
// All register values available are maintained and the SPI is kept active,
// enabling change of configuration and the uploading/downloading of data
// registers.
// Power down mode is entered by setting the PWR_UP bit in the CONFIG register low.
void `$INSTANCE_NAME`_SetPowerDownMode(void)
{
    `$INSTANCE_NAME`_ClearBit(NRF_CONFIG_REG, NRF_CONFIG_PWR_UP);
}

// By setting the PWR_UP bit in the CONFIG register to 1, the device enters standby-I
// mode. Standby-I mode is used to minimize average current consumption while
// maintaining short start up times. In this mode only part of the crystal oscillator
// is active. Change to active modes only happens if CE is set high and when CE
// is set low, the nRF24 returns to standby-I mode from both the TX and RX modes.
void `$INSTANCE_NAME`_SetStandbyIMode(void)
{
	`$INSTANCE_NAME`_Listen(false);
    `$INSTANCE_NAME`_ClearBit(NRF_CONFIG_REG, NRF_CONFIG_PWR_UP);
}

// In standby-II mode extra clock buffers are active and more current is used
// compared to standby-I mode. nRF24 enters standby-II mode if CE is held high on
// a TX device with an empty TX FIFO.
// If a new packet is uploaded to the TX FIFO, the PLL immediately starts and the
// packet is transmitted after the normal PLL settling  delay (130us).
void `$INSTANCE_NAME`_SetStandbyIIMode(void)
{
    `$INSTANCE_NAME`_Listen(true);
    `$INSTANCE_NAME`_SetBit(NRF_CONFIG_REG, NRF_CONFIG_PWR_UP);
}

// RX mode is an active mode where the nRF24 radio is used as receiver. To
// enter this mode, the nRF24 must have the PWR_UP bit, PRIM_RX bit and the CE
// pin set high.
void `$INSTANCE_NAME`_SetRxMode(void)
{
    `$INSTANCE_NAME`_SetBit(NRF_CONFIG_REG, NRF_CONFIG_PRIM_RX);
}

// TX mode is an active mode for transmitting packets. To enter this mode,
// the nRF24 must have the PWR_UP bit set high, PRIM_RX bit set low, a payload
// in the TX FIFO and a high pulse on the CE for more than 10us.
void `$INSTANCE_NAME`_SetTxMode(void)
{
    `$INSTANCE_NAME`_ClearBit(NRF_CONFIG_REG, NRF_CONFIG_PRIM_RX);
}

void `$INSTANCE_NAME`_EnableAutoACK(const NRF_DATA_PIPE_t pipe)
{
    `$INSTANCE_NAME`_SetBit(NRF_EN_AA_REG, pipe);
}

void `$INSTANCE_NAME`_DisableAutoACK(const NRF_DATA_PIPE_t pipe)
{
    `$INSTANCE_NAME`_ClearBit(NRF_EN_AA_REG, pipe);
}

void `$INSTANCE_NAME`_SetChannel(uint8_t channel)
{
    // There's only 125 channels available
    if( 125 < channel )
    {
        channel = 125;
    }
    
    `$INSTANCE_NAME`_WriteRegister(NRF_RF_CH_REG, channel);
}

void `$INSTANCE_NAME`_SetRxAddress(const uint8_t* addr, size_t size)
{
    `$INSTANCE_NAME`_WriteLongRegister(NRF_RX_ADDR_P0_REG, addr, size);
}

void `$INSTANCE_NAME`_SetRxPipe0Address(const uint8_t* addr, size_t size)
{
    `$INSTANCE_NAME`_WriteLongRegister(NRF_RX_ADDR_P0_REG, addr, size);
}

void `$INSTANCE_NAME`_SetRxPipe1Address(const uint8_t* addr, size_t size)
{
    `$INSTANCE_NAME`_WriteLongRegister(NRF_RX_ADDR_P1_REG, addr, size);
}

void `$INSTANCE_NAME`_SetRxPipe2Address(const uint8_t addr)
{
    `$INSTANCE_NAME`_WriteRegister(NRF_RX_ADDR_P2_REG, addr);
}

void `$INSTANCE_NAME`_SetRxPipe3Address(const uint8_t addr)
{
    `$INSTANCE_NAME`_WriteRegister(NRF_RX_ADDR_P3_REG, addr);
}

void `$INSTANCE_NAME`_SetRxPipe4Address(const uint8_t addr)
{
    `$INSTANCE_NAME`_WriteRegister(NRF_RX_ADDR_P4_REG, addr);
}

void `$INSTANCE_NAME`_SetRxPipe5Address(const uint8_t addr)
{
    `$INSTANCE_NAME`_WriteRegister(NRF_RX_ADDR_P5_REG, addr);
}

void `$INSTANCE_NAME`_SetTxAddress(const uint8_t* addr, size_t size)
{
    `$INSTANCE_NAME`_WriteLongRegister(NRF_TX_ADDR_REG, addr, size);
}

void `$INSTANCE_NAME`_SetPayloadSize(const NRF_DATA_PIPE_t pipe , uint8_t size)
{
    if( 32 < size )
    {
        size = 32;
    }
    
    switch (pipe)
    {
    case NRF_DATA_PIPE0:
        `$INSTANCE_NAME`_WriteRegister(NRF_RX_PW_P0_REG, size);
        break;
    case NRF_DATA_PIPE1:
        `$INSTANCE_NAME`_WriteRegister(NRF_RX_PW_P1_REG, size);
        break;
    case NRF_DATA_PIPE2:
        `$INSTANCE_NAME`_WriteRegister(NRF_RX_PW_P2_REG, size);
        break;
    case NRF_DATA_PIPE3:
        `$INSTANCE_NAME`_WriteRegister(NRF_RX_PW_P3_REG, size);
        break;
    case NRF_DATA_PIPE4:
        `$INSTANCE_NAME`_WriteRegister(NRF_RX_PW_P4_REG, size);
        break;
    case NRF_DATA_PIPE5:
        `$INSTANCE_NAME`_WriteRegister(NRF_RX_PW_P5_REG, size);
        break;
    default:
        break;
    }
}

uint8_t `$INSTANCE_NAME`_GetPayloadSize(const NRF_DATA_PIPE_t pipe)
{
    switch (pipe)
    {
    case NRF_DATA_PIPE0:
        return `$INSTANCE_NAME`_ReadRegister(NRF_RX_PW_P0_REG);
        break;
    case NRF_DATA_PIPE1:
        return `$INSTANCE_NAME`_ReadRegister(NRF_RX_PW_P1_REG);
        break;
    case NRF_DATA_PIPE2:
        return `$INSTANCE_NAME`_ReadRegister(NRF_RX_PW_P2_REG);
        break;
    case NRF_DATA_PIPE3:
        return `$INSTANCE_NAME`_ReadRegister(NRF_RX_PW_P3_REG);
        break;
    case NRF_DATA_PIPE4:
        return `$INSTANCE_NAME`_ReadRegister(NRF_RX_PW_P4_REG);
        break;
    case NRF_DATA_PIPE5:
        return `$INSTANCE_NAME`_ReadRegister(NRF_RX_PW_P5_REG);
        break;
    default: 
        return 0;
    }
}

void `$INSTANCE_NAME`_PTX_ReuseLastTransmittedPayload(void)
{
    `$INSTANCE_NAME`_ReuseTxPayloadCmd();
    `$INSTANCE_NAME`_TransmitPulse();
}

void `$INSTANCE_NAME`_EnableDynamicPayload(const NRF_DATA_PIPE_t pipe)
{
    `$INSTANCE_NAME`_SetBit(NRF_EN_AA_REG, pipe);
    `$INSTANCE_NAME`_SetBit(NRF_FEATURE_REG, NRF_FEATURE_EN_ACK_PAY);
    `$INSTANCE_NAME`_SetBit(NRF_FEATURE_REG, NRF_FEATURE_EN_DPL);
    `$INSTANCE_NAME`_SetBit(NRF_DYNPD_REG, pipe);
}

void `$INSTANCE_NAME`_DisableDynamicPayload(const NRF_DATA_PIPE_t pipe)
{
    `$INSTANCE_NAME`_ClearBit(NRF_EN_AA_REG, pipe);
    `$INSTANCE_NAME`_ClearBit(NRF_FEATURE_REG, NRF_FEATURE_EN_ACK_PAY);
    `$INSTANCE_NAME`_ClearBit(NRF_FEATURE_REG, NRF_FEATURE_EN_DPL);
    `$INSTANCE_NAME`_ClearBit(NRF_DYNPD_REG, pipe);    
}

void `$INSTANCE_NAME`_EnableDynamicPayloadLength(void)
{
    `$INSTANCE_NAME`_SetBit(NRF_FEATURE_REG, NRF_FEATURE_EN_DPL);
}

void `$INSTANCE_NAME`_EnablePayloadWithACK(void)
{
    `$INSTANCE_NAME`_SetBit(NRF_FEATURE_REG, NRF_FEATURE_EN_ACK_PAY);
}

void `$INSTANCE_NAME`_EnablePayloadWithNoACKCmd(void)
{
    `$INSTANCE_NAME`_SetBit(NRF_FEATURE_REG, NRF_FEATURE_EN_DYN_ACK);
}

void `$INSTANCE_NAME`_DisableDynamicPayloadLength(void)
{
    `$INSTANCE_NAME`_ClearBit(NRF_FEATURE_REG, NRF_FEATURE_EN_DPL);
}

void `$INSTANCE_NAME`_DisablePayloadWithACK(void)
{
    `$INSTANCE_NAME`_ClearBit(NRF_FEATURE_REG, NRF_FEATURE_EN_ACK_PAY);
}

void `$INSTANCE_NAME`_DisablePayloadWithNoACKCmd(void)
{
    `$INSTANCE_NAME`_ClearBit(NRF_FEATURE_REG, NRF_FEATURE_EN_DYN_ACK);
}

// Data transfer functions

void `$INSTANCE_NAME`_StartListening(void)
{
    `$INSTANCE_NAME`_Listen(true);
}

void `$INSTANCE_NAME`_StopListening(void)
{
    `$INSTANCE_NAME`_Listen(false);
}

void `$INSTANCE_NAME`_TransmitPulse(void)
{
    `$CE_PIN`_Write(1);
    CyDelayUs(15);
    `$CE_PIN`_Write(0);
}

void `$INSTANCE_NAME`_Listen(const bool listen)
{
    listen ? `$CE_PIN`_Write(1) : `$CE_PIN`_Write(0);
}

uint8_t `$INSTANCE_NAME`_GetStatus(void)
{
    return `$INSTANCE_NAME`_NOPCmd();
}

uint8_t `$INSTANCE_NAME`_GetRetransmissionsCount(void)
{
    uint8_t count = `$INSTANCE_NAME`_ReadRegister(NRF_OBSERVE_TX_REG);
    count = count & NRF_OBSERVE_TX_ARC_CNT_MASK;
    return count;
}

uint8_t `$INSTANCE_NAME`_GetLostPacketsCount(void)
{
    uint8_t lostPackets = `$INSTANCE_NAME`_ReadRegister(NRF_OBSERVE_TX_REG);
    lostPackets = lostPackets & NRF_OBSERVE_TX_PLOS_CNT_MASK;
    lostPackets = lostPackets >> NRF_OBSERVE_TX_PLOS_CNT_POS;
    return lostPackets;
}

void `$INSTANCE_NAME`_FillTxFIFO(const uint8_t* data, size_t size)
{
    `$INSTANCE_NAME`_WriteTXPayloadCmd(data, size);
}

void `$INSTANCE_NAME`_TxTransmit(const uint8_t* data, size_t size)
{
    if ( NULL == data )
    {
        return;
    }
    
    `$INSTANCE_NAME`_FillTxFIFO(data, size);
    `$INSTANCE_NAME`_TransmitPulse();
}

bool `$INSTANCE_NAME`_IsDataReady(void)
{
#if 1
    // TODO: check if is correct using & and not &&
    return NRF_STATUS_DATA_IS_RDY & `$INSTANCE_NAME`_GetStatus();
#else
    if( NRF_STATUS_DATA_IS_RDY & `$INSTANCE_NAME`_GetStatus() )
    {
        return true;
    }else{
        return false;    
    }
#endif
}

void `$INSTANCE_NAME`_GetRxPayload(uint8_t* data, const size_t size)
{
    `$INSTANCE_NAME`_ReadRXPayloadCmd(data, size);
}

void `$INSTANCE_NAME`_TxTransmitWaitNoACK(const uint8_t* data, size_t size)
{
    `$INSTANCE_NAME`_NoACKPayloadCmd(data, size);
    `$INSTANCE_NAME`_TransmitPulse();
}

void `$INSTANCE_NAME`_RxWritePayload(const NRF_DATA_PIPE_t pipe, uint8_t* data, size_t size)
{
    `$INSTANCE_NAME`_WriteACKPayloadCmd(pipe, data, size);
}

uint8_t `$INSTANCE_NAME`_GetDataPipeWithPayload(void)
{
    uint8_t pipe = `$INSTANCE_NAME`_ReadRegister(NRF_STATUS_REG);
    pipe = (pipe & 0x0Eu) >> 1;
    return pipe;
}

uint8_t `$INSTANCE_NAME`_PRX_ReceivedPowerDetector(void)
{
    return `$INSTANCE_NAME`_ReadBit(NRF_RPD_REG, NRF_RPD_RPD);
}

uint8_t `$INSTANCE_NAME`_IsTXFIFOFull(void)
{
    return `$INSTANCE_NAME`_ReadBit(NRF_FIFO_STATUS_REG, NRF_FIFO_STATUS_TX_FULL);
}

uint8_t `$INSTANCE_NAME`_IsTXFIFOEmpty(void)
{
    return `$INSTANCE_NAME`_ReadBit(NRF_FIFO_STATUS_REG, NRF_FIFO_STATUS_TX_EMPTY);
}

uint8_t `$INSTANCE_NAME`_IsRXFIFOFull(void)
{
    return `$INSTANCE_NAME`_ReadBit(NRF_FIFO_STATUS_REG, NRF_FIFO_STATUS_RX_FULL);
}

uint8_t `$INSTANCE_NAME`_IsRXFIFOEmpty(void)
{
    return `$INSTANCE_NAME`_ReadBit(NRF_FIFO_STATUS_REG, NRF_FIFO_STATUS_RX_EMPTY);
}

// IRQ Handle functions

void `$INSTANCE_NAME`_ClearIRQ(void)
{
    uint8_t sts = `$INSTANCE_NAME`_GetStatus();
    
    if ( NRF_STATUS_RX_DR_MASK & sts) // RX_DR: Data Received
    {
        `$INSTANCE_NAME`_SetBit(NRF_STATUS_REG, NRF_STATUS_RX_DR);
    } else if ( NRF_STATUS_TX_DS_MASK & sts ) { // TX_DS: Data Sent
        `$INSTANCE_NAME`_SetBit(NRF_STATUS_REG, NRF_STATUS_TX_DS);
    } else { // MAX_RT: Retry Timeout
        `$INSTANCE_NAME`_SetBit(NRF_STATUS_REG, NRF_STATUS_MAX_RT);    
    }
}

void `$INSTANCE_NAME`_ClearIRQFlag(uint8_t flag)
{
    `$INSTANCE_NAME`_SetBit(NRF_STATUS_REG, flag);
}

uint8_t `$INSTANCE_NAME`_GetIRQFlag(void)
{
    // TODO
    return 0;
}

/* [] END OF FILE */