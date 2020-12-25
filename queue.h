/*
 * queue.h
 *
 *      Author: nkessa
 */

#ifndef QUEUE_H_
#define QUEUE_H_


//#define QUEUE_DEBUG 1 /*enable for debugging*/

#include <stdint.h>

#define QUEUE_NO_ERROR 0
#define QUEUE_ERROR 1
#define QUEUE_IS_FULL 2
#define QUEUE_IS_NOT_FULL 3
#define QUEUE_IS_EMPTY 4

//#define QUEUE_DEBUG 1

typedef struct {
	
	uint32_t sizeElement;
	uint32_t currentNumberElements;
	uint32_t maxNumberElements;
	uint32_t queuebufferSize;
	uint8_t  * queueBuffer;
	uint8_t * head; 
	uint8_t * tail;	
	
} queue_t ;



uint32_t queueInit(queue_t * queue , /*handle of queue*/
					uint32_t sizeElement , /*The size in uint8_t of elements pushed popped from the queue*/
					uint32_t maxNumberElements , /*The maximum number of elements to be accepted in the queue*/
					uint8_t  * queueBuffer, /*pointer to a uint8_t buffer, this buffer needs to be at least of size = sizeElement x maxNumberElements to avoid overflow */
					uint32_t queuebufferSize /*the size of buffer queueBuffer needs to be greather than sizeElement x maxNumberElements */) ;
					
uint32_t queueIsFull(const queue_t * queue);
uint32_t queuePush( queue_t * queue ,const uint8_t * element);
uint32_t queuePop( queue_t * queue , uint8_t * element);

#endif  /* QUEUE_H_ */
