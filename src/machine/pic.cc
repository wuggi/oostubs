/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                   Technische Informatik II                                    * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *                                                                                               * 
 *                                            P I C                                              * 
 *                                                                                               * 
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    INCLUDES                     #
\* * * * * * * * * * * * * * * * * * * * * * * * */
#include "machine/pic.h"
#include "machine/io_port.h"
#include "useful/cpu.h"


/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    METHODS                      # 
\* * * * * * * * * * * * * * * * * * * * * * * * */

PIC::PIC(){
  IO_Port ctrl_1(0x20), ctrl_2(0xa0), mask_1(0x21), mask_2(0xa1);
  
  ctrl_1.outb(0x11);
  ctrl_2.outb(0x11);
  
  mask_1.outb(32);
  mask_2.outb(40);
  
  mask_1.outb(4);
  mask_2.outb(2);
  
  mask_1.outb(3);
  mask_2.outb(3);
  
  mask_1.outb(0xFB);
  mask_2.outb(0xFF);
}

void PIC::allow(Interrupts interrupt){
	IO_Port mask_1(0x21), mask_2(0xa1);  
	
	char OCW1;							//OCW1 Platzhalter für die Maske des gesperrten Interrupts
	
	if(interrupt <=8)					//PIC1 kann nur 8 Interrupt Quellen unterscheiden
	{
		OCW1=mask_1.inb();
		OCW1 &= ~(1<<interrupt);
		mask_1.outb(OCW1);
	}
	else
	{
		OCW1=mask_2.inb();
		OCW1&= ~(1<<(interrupt-8));
		mask_2.outb(OCW1);
	}
	
}


void PIC::forbid(Interrupts interrupt){
	IO_Port mask_1(0x21), mask_2(0xa1);  
	
	char OCW1;							//OCW1 Platzhalter für die Maske des gesperrten Interrupts
	
	if(interrupt <= 8)					//erstes PIC
	{
		OCW1=mask_1.inb();
		OCW1 |= ~(1 << interrupt);		//???
		mask_1.outb(OCW1);
	}
	else
	{
		OCW1=mask_2.inb();
		OCW1|= ~(1<<(interrupt-8));
		mask_2.outb(OCW1);
	}
	
}

void PIC::ack(bool secondPIC){
	IO_Port ctrl_1(0x20), ctrl_2(0xa0);	//Ports im I/O Adressraum
	
	if(secondPIC)
	{
		ctrl_1.outb(0x20);
		ctrl_2.outb(0x20);
	}
	else
	{
		ctrl_1.outb(0x20);
	}
	
}

unsigned char PIC::getISR(bool secondPIC){
	IO_Port ctrl_1(0x20), ctrl_2(0xa0);
	char ISR;
	
	if(secondPIC)
	{
		ctrl_2.outb(0x0b);	//OCW3 setzen, damit man an ISR kommt
		ISR=ctrl_2.inb();
	}
	else
	{
		ctrl_1.outb(0x0b);
		ISR = ctrl_1.inb();
	}
  
  
  return ISR;
}

