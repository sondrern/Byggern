#pragma once
#include "MCP2515.h"



void can_init();
void can_message_send();
void can_error();
void can_transmit_complete();
void can_data_receive();
void can_int_vect();

