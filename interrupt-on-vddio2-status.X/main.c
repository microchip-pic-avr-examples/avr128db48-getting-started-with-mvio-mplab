/*
 *  (c) 2020 Microchip Technology Inc. and its subsidiaries.
 *
 *  Subject to your compliance with these terms,you may use this software and
 *  any derivatives exclusively with Microchip products.It is your responsibility
 *  to comply with third party license terms applicable to your use of third party
 *  software (including open source software) that may accompany Microchip software.
 *
 *  THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 *  EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 *  WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 *  PARTICULAR PURPOSE.
 *
 *  IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 *  INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 *  WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 *  BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 *  FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 *  ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 *  THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 */

#define F_CPU 4000000ul

#include <avr/io.h>
#include <avr/interrupt.h>


void LED0_init(void) {
	PORTB.DIRSET = PIN3_bm;
}
void LED0_toggle(void) {
	PORTB.OUTTGL = PIN3_bm;
}

int main(void)
{
	/*Enable the VDDIO2 interrupt*/
	MVIO.INTCTRL |= MVIO_VDDIO2IE_bm;
	
	/*Enable Global interrupts*/
	sei();
	LED0_init();
	
	/* Replace with your application code */
	while (1)
	{
	}
}

ISR(MVIO_MVIO_vect)
{
	/* The VDDIO2 interrupt has been triggered */
	LED0_toggle();
	/* Clear the VDDIO2 interrupt flag */
	MVIO.INTFLAGS |= MVIO_VDDIO2IF_bm;
}