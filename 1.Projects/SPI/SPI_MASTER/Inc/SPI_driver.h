/** @file SPI_driver.h
 *  @brief Function prototypes for the SPI driver.
 *
 *  This contains the function prototypes for the SPI driver
 *	and also macros, constants, variables needed.
 *
 *  @author 	Tran Nhat Duat (duattn)
 *	@version 	V0.1
 */

#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include <stdint.h>
#include "stm32f407xx.h"

/* SPI status flags */
#define SPI_I2S_FLAG_TXE				(0x01 << 1)
#define SPI_I2S_FLAG_RXNE				(0x01 << 0)
#define SPI_I2S_FLAG_BSY 				(0x01 << 7)

#define SPI_CLK		10	//PC10
#define SPI_MISO	11	//PC11
#define SPI_MOSI	12	//PC12

/* SPI mode */
#define SPI_SLAVE 							(0x00 << 2)
#define SPI_MASTER							(0x01 << 2)

/* SPI baudrate prescaler */
#define SPI_CLOCK_DIV_2 				(0x00 << 3)
#define SPI_CLOCK_DIV_4 				(0x01 << 3)
#define SPI_CLOCK_DIV_8 				(0x02 << 3)
#define SPI_CLOCK_DIV_16 				(0x03 << 3)
#define SPI_CLOCK_DIV_32 				(0x04 << 3)
#define SPI_CLOCK_DIV_64 				(0x05 << 3)
#define SPI_CLOCK_DIV_128 			(0x06 << 3)
#define SPI_CLOCK_DIV_256 			(0x07 << 3)

/* SPI direction*/
#define SPI_2_LINE_UNIDIRECTION 				(0x00 << 14)
#define SPI_1_LINE_BIDIRECTION					(0x01 << 14)

/* SPI clock phase */
#define SPI_FIRST_CLOCK 				(0x00 << 0)
#define SPI_SECOND_CLOCK				(0x01 << 0)

/* SPI clock polarity */
#define SPI_CK_TO_0 						(0x00 << 1)
#define SPI_CK_TO_1							(0x01 << 1)

/* SPI data size */
#define SPI_8BITS_DATA 					(0x00 << 11)
#define SPI_16BITS_DATA					(0x01 << 11)

/* SPI first bit mode */
#define SPI_MSB_FIRST 					(0x00 << 7)
#define SPI_LSB_FIRST 					(0x01 << 7)

/* SPI clock enable Macro functions */
#define _SPI1_CLK_ENABLE() 				(RCC->APB2ENR |= RCC_APB2ENR_SPI1EN)
#define _SPI2_CLK_ENABLE() 				(RCC->APB1ENR |= RCC_APB1ENR_SPI2EN)
#define _SPI3_CLK_ENABLE() 				(RCC->APB1ENR |= RCC_APB1ENR_SPI3EN)

/** @brief Configure a SPI.
 *
 *  @param SPIx The address of SPI used to send the character.
 *  @param mode The mode to be configured: Master or Slave.
 *  @param clockPrescaler The prescaler to apply for SPI clock speed.
 *  @param direction The direction mode to be selected.
 *  @param cpha The clock phase mode selection.
 *  @param cpol The clock polarity mode selection.
 *  @param size Selection of 8-bit or 16-bit data frame.
 *  @param firstBit Selection of tranferring MSB or LSB first.
 *
 *  @return void.
 */
void SPIInit(SPI_TypeDef *SPIx, uint32_t mode, uint32_t clockPrescaler, uint32_t direction, uint32_t cpha, uint32_t cpol, uint32_t size, uint32_t firstBit);

/** @brief Send a character over the SPI
 *
 *  @param SPIx The address of SPI used to send the character.
 *  @param data The character to be sent.
 *
 *  @return void.
 */
uint8_t SPISend(SPI_TypeDef *SPIx, uint8_t data);
#endif /*  SPI_DRIVER_H_ */
