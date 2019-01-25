/*
 * task_player2.h
 *
 * Created: 2018-10-17 13:33:46
*  Author: jake & stefan
 */ 


#ifndef task_green_H_
#define task_green_H_
#define task_green_STACK_SIZE (2048/ sizeof(portSTACK_TYPE))
#define task_green_PRIORITY   (1)

void task_green(void *pvParameters);
extern uint32_t pressTime;


#endif /* TASK_PLAYER2_H_ */