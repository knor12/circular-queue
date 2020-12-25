#include "queue.h"
#include "queue_cfg.h"

uint32_t queueInit( queue_t * queue ,
					uint32_t sizeElement ,
					uint32_t maxNumberElements ,
					uint8_t  * queueBuffer ,
					uint32_t queuebufferSize )
{
	
	/*check if the buffer size is enough*/
	if (queuebufferSize < (sizeElement * maxNumberElements) ){
		return QUEUE_ERROR;
	}
	
	/*initialize*/
	queue->queuebufferSize =queuebufferSize;
	queue->sizeElement =sizeElement;
	queue->maxNumberElements = maxNumberElements;
	queue->currentNumberElements =0u;
	queue->queueBuffer = queueBuffer;
	queue->head =queueBuffer;
	queue->tail =queueBuffer;
	
#ifdef QUEUE_DEBUG
	//queuePrintStatus(queue);
#endif 		
	
	return QUEUE_NO_ERROR;
}


#ifdef QUEUE_DEBUG
	queuePrintStatus(queue_t * queue){
		printf("*************printing queue status************* \n");
		printf("sizeElement , 0x%X \n" , queue->sizeElement);
		printf("maxNumberElements , 0x%X \n" , queue->maxNumberElements);
		printf("queueBuffer , 0x%X \n" , queue->queueBuffer);
		printf("queuebufferSize , 0x%X \n" , queue->queuebufferSize);
		printf("head , 0x%X \n" , queue->head);
		printf("tail , 0x%X \n" , queue->tail);
		printf("number of elements , 0x%X \n" , queue->currentNumberElements);
		printf("head points to spot numpber 0x%X \n" , (queue->head-queue->queueBuffer)/queue->sizeElement);
		printf("tail points to spot numpber 0x%X \n"  , (queue->tail-queue->queueBuffer)/queue->sizeElement);
		
		printf("*************end of printing queue status************* \n");
	}

#endif

uint32_t queueIsFull(const queue_t * queue){

	if (queue->maxNumberElements <= queue->currentNumberElements){
		return QUEUE_IS_FULL;
	}else {
		return QUEUE_IS_NOT_FULL;
	}
}

uint32_t queuePush( queue_t * queue ,const uint8_t * element){
	uint32_t i ;
	uint8_t * src = element;
	uint8_t * dst;
	
	if (queueIsFull(queue)==QUEUE_IS_FULL){
		return QUEUE_IS_FULL;
	}
	
	
	if (queue->head==0u){
		queue->head = queue->queueBuffer;
	}
	
	if (queue->tail==0u){
		queue->tail = queue->queueBuffer;
	}
	
	dst =queue->head;
	for (i=0u ; i < queue->sizeElement;i++){
		*dst = * src ;
		dst ++;
		src++;
	}
	
	/*assign new head loop around*/
	if ((uint32_t)dst>((uint32_t)queue->queueBuffer + (uint32_t)queue->queuebufferSize)){
		queue->head = queue->queueBuffer;
	}else {
		queue->head=dst;
	}
	
	queue->currentNumberElements+=1;
	
#ifdef QUEUE_DEBUG
//queuePrintStatus(queue);
#endif 	
	
	return QUEUE_NO_ERROR;
}

uint32_t queuePop( queue_t * queue , uint8_t * element){
	
	uint32_t i ;
	uint8_t * src = queue->tail ;
	uint8_t * dst = element;
	
#ifdef QUEUE_DEBUG
//	queuePrintStatus(queue);
#endif 	

	if (queue->currentNumberElements<=0u){
		return QUEUE_IS_EMPTY;
	}
	
	for (i=0u ; i < queue->sizeElement;i++){
		*dst = * src ;
		dst ++;
		src++;
	}

	/*assign new tail loop around*/
	if ((uint32_t)src>((uint32_t)queue->queueBuffer + (uint32_t)queue->queuebufferSize)){
		queue->tail = queue->queueBuffer;
	}else {
		queue->tail=src;
	}
	queue->currentNumberElements-=1;
	
	return QUEUE_NO_ERROR;
}



