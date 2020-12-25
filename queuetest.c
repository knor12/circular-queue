#include <stdio.h>
#include <stdint.h>
#include "queue.h"




queue_t queue_unit64 = {0};

#define QUEUE_UINT64_NUMBER_ELEMENTS 11
#define QUEUE_UINT64_ELEMENT_SIZE sizeof(uint64_t)
#define  QUEUE_UINT64_BUFFER_SIZE (QUEUE_UINT64_ELEMENT_SIZE * QUEUE_UINT64_NUMBER_ELEMENTS)

uint8_t queue_unit64_buff[QUEUE_UINT64_BUFFER_SIZE] = {0};


int main(){
	
	uint64_t i =0;
	uint32_t err; 
	

	printf("Starting ..... \n");
	
	/*initialize queue*/
	if (QUEUE_NO_ERROR != queueInit(&queue_unit64 , 
									QUEUE_UINT64_ELEMENT_SIZE, 
									QUEUE_UINT64_NUMBER_ELEMENTS, 
									&queue_unit64_buff,
									QUEUE_UINT64_BUFFER_SIZE))
									{
										printf("Error Initializing the queue \n");
										return -1;
									}else {
										printf("Initializing the queue OK \n");
									}								
	
	/*Pushing elements into the queue*/
	printf("pushing 12 elements \n");
	for (i = 0;i<15 ;i++ ){
		//queuePrintStatus(&queue_unit64);
		err = queuePush(&queue_unit64 , (uint8_t*)(&i));

		if (QUEUE_NO_ERROR != err)
		{
			printf("Error pushig element 0x%X , error number 0x%X \n" , i , err);
		}else 
		{
			printf("success pushig element 0x%X , error number 0x%X \n" , i , err);
		}	
	}
	
	/*Popping elements into the queue*/
	printf("poping  4 elements \n");
	uint64_t element;
	for (i = 0;i<4 ;i++ ){
		//queuePrintStatus(&queue_unit64);
		err = queuePop(&queue_unit64 , (uint8_t*)&element);

		if (QUEUE_NO_ERROR != err)
		{
			printf("Error poping  element  , error number 0x%X \n" , err);
		}else 
		{
			printf("success poping element 0x%X , error number 0x%X \n" , element , err);
		}	
	}
	
	/*Pushing elements into the queue*/
	printf("pushing 8 elements \n");
	for (i = 0+15;i<8+15 ;i++ ){
		//queuePrintStatus(&queue_unit64);
		err = queuePush(&queue_unit64 , (uint8_t*)(&i));
		if (QUEUE_NO_ERROR != err)
		{
			printf("Error pushig element 0x%X , error number 0x%X \n" , i , err);
		}else 
		{
			printf("success pushig element 0x%X , error number 0x%X \n" , i , err);
		}	
	}


	/*Popping elements into the queue*/
	printf("poping  16 elements \n");
	for (i = 0;i<16 ;i++ ){
		//queuePrintStatus(&queue_unit64);
		err = queuePop(&queue_unit64 , (uint8_t*)&element);

		if (QUEUE_NO_ERROR != err)
		{
			printf("Error popping  element  , error number 0x%X \n" , err);
		}else 
		{
			printf("success popping element 0x%X , error number 0x%X \n" , element , err);
		}	
	}	
}
