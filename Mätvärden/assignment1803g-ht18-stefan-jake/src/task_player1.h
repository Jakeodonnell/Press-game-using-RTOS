/*
 * IncFile1.h
 *
 * Created: 2018-10-17 13:33:26
 *  Author: jake
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#define TASK_PLAYER1_STACK_SIZE (2048/ sizeof(portSTACK_TYPE)) 
#define TASK_PLAYER1_PRIORITY   (2)

void task_player1(void *pvParameters);


#endif /* INCFILE1_H_ */