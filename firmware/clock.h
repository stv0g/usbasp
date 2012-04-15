/*
 * clock.h - part of USBasp
 *
 * Autor..........: Thomas Fischl <tfischl@gmx.de>
 * Description....: Provides functions for timing/waiting
 * Licence........: GNU GPL v2 (see Readme.txt)
 * Creation Date..: 2005-02-23
 * Last change....: 2006-11-16
 */

#ifndef __clock_h_included__
#define	__clock_h_included__

#ifndef F_CPU /* should be defined in Makefile */
#define F_CPU           16000000L   /* 16MHz */
#endif

#define TIMERVALUE      TCNT0
#define CLOCK_T_320us	(320e-6*F_CPU/64) /* prescaler is 64 as defined below */


#ifdef __AVR_ATmega8__
#define TCCR0B  TCCR0
#endif

/* set prescaler to 64 */
#define clockInit()  TCCR0B = (1 << CS01) | (1 << CS00);

/* wait time * 320 us */
void clockWait(uint8_t time);

#endif /* __clock_h_included__ */
