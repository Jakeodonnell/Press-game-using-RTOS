/*
 * task_player2.h
 *
 * Created: 2018-10-17 13:33:46
 *  Author: jake
 */ 


#ifndef TASK_PLAYER2_H_

#define TASK_PLAYER2_H_
#define TASK_PLAYER2_STACK_SIZE (2048/ sizeof(portSTACK_TYPE))
#define TASK_PLAYER2_PRIORITY   (1)

void task_player2(void *pvParameters);


#endif /* TASK_PLAYER2_H_ */