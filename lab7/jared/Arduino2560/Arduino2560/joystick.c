#include "joystick.h"
#include "can.h"

void printbutton(uint8_t buttons ){
	
		if(buttons=0xb00000000){
			printf("X=N \n Y=N");
			
		}
		else if(buttons= 0xb00000001){
			printf("X=N \n Y=U");
		}
		else if(buttons= 0xb00000010){
			printf("X=N \n Y=D");
		}
		else if(buttons= 0xb00000011){
			printf("X=U \n Y=N");
		}
		else if (buttons= 0Xb00000100){
			printf("X=U \n Y= D");
			
		}
		else if (buttons= 0xb00000110){
			printf("X=D \n Y=N");
		}
		else if(buttons=0xb00000111){
			printf("X=D \n Y=U");
		}
		else if(buttons= 0xb00001000){
			printf("X=D \n Y=D");
		}
		else{
		printf("failed in printbutton");
		}
	
	
	
	
}
void buttonrecieve(void){
	struct data button;
	
	button= can_data_receive();
	
	printbutton(button.data);
	
	
	
	
	
	
	
}