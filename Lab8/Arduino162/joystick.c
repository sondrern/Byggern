#include "joystick.h"
#include "can.h"

void printbutton(uint8_t buttons ){
	
		if(buttons==0b00000000){
			printf("X=N \n Y=N\n");
			}
		else if(buttons== 0b00000001){
			printf("X=N \n Y=U\n");
		}
		else if(buttons==0b00000010){
			printf("X=N \n Y=D\n");
		}
		else if(buttons== 0b00000011){
			printf("X=L \n Y=N\n");
		}
		else if (buttons== 0b00000100){
			printf("X=L \n Y= U\n");
		}
			
		else if (buttons== 0b00000101){
				printf("X=L \n Y= D\n");
			}
		else if (buttons== 0b00000110){
			printf("X=R \n Y=N\n");
		}
		else if(buttons==0b00000111){
			printf("X=R \n Y=U\n");
		}
		else if(buttons== 0b00001000){
			printf("X=R \n Y=D\n");
		}
		else{
		printf("failed in printbutton");
		}
	
	
	
	
}
void buttonrecieve(void){
	struct data button;
	
	button= can_data_receive();
	
	printbutton(button.data[0]);
	
	
	
	
	
	
	
}
