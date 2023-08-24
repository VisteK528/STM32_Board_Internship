/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    quadspi.h
  * @brief   This file contains all the function prototypes for
  *          the quadspi.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __QUADSPI_H__
#define __QUADSPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

#include "mx25l512.h"

uint8_t CSP_QUADSPI_Init(void);
uint8_t CSP_QSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress);
uint8_t CSP_QSPI_Read(uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
uint8_t CSP_QSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size);
uint8_t CSP_QSPI_EnableMemoryMappedMode(void);
uint8_t CSP_QSPI_Erase_Chip (void);

/* USER CODE END Includes */

extern QSPI_HandleTypeDef hqspi;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_QUADSPI_Init(void);

/* USER CODE BEGIN Prototypes */

/*MX25L512 memory parameters*/
#define MEMORY_FLASH_SIZE               0x4000000 /* 512 MBits => 64MBytes */
#define MEMORY_BLOCK_SIZE               0x10000   /* 1024 sectors of 64KBytes */
#define MEMORY_SECTOR_SIZE              0x1000    /* 16384 subsectors of 4kBytes */
#define MEMORY_PAGE_SIZE                0x100     /* 262144 pages of 256 bytes */


/*MX25L512 commands */
#define WRITE_ENABLE_CMD 0x06
#define READ_STATUS_REG_CMD 0x05
#define READ_FLAG_STATUS_REG_CMD 0x70
#define WRITE_STATUS_REG_CMD 0x01
#define SECTOR_ERASE_CMD 0x20
#define CHIP_ERASE_CMD 0xC7
#define QUAD_IN_FAST_PROG_CMD 0x38
#define READ_CONFIGURATION_REG_CMD 0x15
#define QUAD_READ_IO_CMD 0xEC
#define QUAD_OUT_FAST_READ_CMD 0x6B
#define QPI_ENABLE_CMD 0x35
#define DUMMY_CLOCK_CYCLES_READ_QUAD 10
#define RESET_ENABLE_CMD 0x66
#define RESET_EXECUTE_CMD 0x99
#define DISABLE_QIP_MODE 0xf5

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __QUADSPI_H__ */

