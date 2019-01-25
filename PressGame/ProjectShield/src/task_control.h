/*
 * control.h
 *
 * Created: 2018-10-19 12:23:32
*  Author: jake & stefan
 */ 


#ifndef task_control_H_
#define task_control_H_
#define task_control_STACK_SIZE (2048/ sizeof(portSTACK_TYPE))
#define task_control_PRIORITY   (1)

extern xSemaphoreHandle xSemaphoreBlue;
extern xSemaphoreHandle xSemaphoreGreen;
void task_control(void *pvParameters);
typedef enum {START, RUNNING, WINNER}state_t;
#endif /* CONTROL_H_ */