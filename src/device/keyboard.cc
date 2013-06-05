/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                   Technische Informatik II                                    * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *                                                                                               * 
 *                                       K E Y B O A R D                                         * 
 *                                                                                               * 
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    INCLUDES                     #
\* * * * * * * * * * * * * * * * * * * * * * * * */
#include "device/keyboard.h"
#include "useful/plugbox.h"
#include "useful/kout.h"
#include "useful/pic.h"
extern int globalTaskChoice;

/* * * * * * * * * * * * * * * * * * * * * * * * *\
#                    METHODS                      # 
\* * * * * * * * * * * * * * * * * * * * * * * * */

Keyboard::Keyboard(){
}

void Keyboard::plugin(){
	plugbox.assign(33,*this);
	pic.allow(PIC::keyboard);
}

void Keyboard::trigger(){
	Key k = key_hit();
	
	if(k.ctrl()&&k.alt()&&(k.scancode()==83))
	{
		reboot();
	}
    else if(k.alt()&&k=='1')
    {
        globalTaskChoice = 1;
    }else if(k.alt()&&k=='2')
    {
        globalTaskChoice = 2;
    }

}

