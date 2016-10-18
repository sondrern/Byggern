#pragma once
#include "MCP2515.h"



void can_init();
void can_message_send(struct data msg);
void can_error();
void can_transmit_complete();
void can_int_vect();
struct data can_data_receive();
