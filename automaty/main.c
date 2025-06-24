#include "led.h"
#include "keyboard.h"


void Delay(int iDelayInMS){
    int iLoopCounter;
    iDelayInMS = iDelayInMS*12000;
   
    for(iLoopCounter=0; iLoopCounter < iDelayInMS; iLoopCounter++) {}
}

int main(){
	
		enum LedState{STATE_STOP, STATE_RIGHT, STATE_LEFT, STATE_WIPER};
		enum LedState eLedState = STATE_RIGHT;

		unsigned char ucWiperCounter = 0;

		LedInit();
		KeyboardInit();

		while(1){
				
				switch(eLedState){
					
						case STATE_RIGHT:
								if(eKeyboardRead() == BUTTON_1){
										eLedState = STATE_STOP;
								}
								else{
										LedStepRight();
										eLedState = STATE_RIGHT;
								}
								break;								
								
						case STATE_LEFT:
								if(eKeyboardRead() == BUTTON_1){
										eLedState = STATE_STOP;
								}
								else if(eKeyboardRead() == BUTTON_3){
									
										eLedState = STATE_WIPER;
										ucWiperCounter = 0;
								}
								else{
										LedStepLeft();
										eLedState = STATE_LEFT;
								}
								break;
						
						case STATE_STOP:
								if(eKeyboardRead() == BUTTON_0){
										eLedState = STATE_LEFT;
								}
								else if(eKeyboardRead() == BUTTON_2){
										eLedState = STATE_RIGHT;
								}
								else{
										eLedState = STATE_STOP;
								}
								break;
								
						case STATE_WIPER:
								if(ucWiperCounter == 4){
									
										eLedState = STATE_RIGHT;
								}
								else{
		
										if((ucWiperCounter % 2) == 0){
												LedStepRight();
										}
										else{
												LedStepLeft();
										}
										ucWiperCounter ++;
										eLedState = STATE_WIPER;
								}
								break;
								
						default:
								break;
						
				}
				Delay(300);
		}
}		
		



