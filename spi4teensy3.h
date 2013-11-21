/*
 * File:   spi4teensy3.h
 * Author: xxxajk
 *
 * Created on November 21, 2013, 10:54 AM
 */

#ifndef SPI4TEENSY3_H
#define	SPI4TEENSY3_H
#ifdef __MK20DX128__
#include <mk20dx128.h>
#include <core_pins.h>
#include <sys/types.h>

#ifndef SPI_SR_RXCTR
#define SPI_SR_RXCTR 0XF0
#endif
#ifndef SPI_PUSHR_CONT
#define SPI_PUSHR_CONT 0X80000000
#endif
#ifndef SPI_PUSHR_CTAS
#define SPI_PUSHR_CTAS(n) (((n) & 7) << 28)
#endif


namespace spi4teensy3 {
        void init();
        void init(uint8_t cpol, uint8_t cpha);
        void send(uint8_t b);
        void send(void *bufr, size_t n);
        uint8_t receive();
        void receive(void *bufr, size_t n);

        // cached ctars for speed
        //uint32_t ctar0;
        //uint32_t ctar1;
        void updatectars();
};
#endif /* __MK20DX128__ */
#endif	/* SPI4TEENSY3_H */
