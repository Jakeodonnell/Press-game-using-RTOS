/*
 * IncFile1.h
 *
 * Created: 2018-10-17 13:33:26
 *  Author: jake & stefan
 */ 


#ifndef task_blue_H_
#define task_blue_H_
#define task_blue_STACK_SIZE (2048/ sizeof(portSTACK_TYPE)) 
#define task_blue_PRIORITY   (1)

void task_blue(void *pvParameters);

#endif /* INCFILE1_H_ */