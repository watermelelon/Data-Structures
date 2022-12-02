#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>

//	Queue ADT Type Defintions 
typedef struct node
{
	void* dataPtr;
	struct node* next;
} QUEUE_NODE;
typedef struct
{
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
	int         count;
	int			sum;
} QUEUE;

//	Prototype Declarations 
QUEUE* createQueue(void);
QUEUE* destroyQueue(QUEUE* queue);

bool  dequeue(QUEUE* queue, void** itemPtr);
bool  enqueue(QUEUE* queue, void* itemPtr);
bool  queueFront(QUEUE* queue, void** itemPtr);
bool  queueRear(QUEUE* queue, void** itemPtr);
int   queueCount(QUEUE* queue);


bool  emptyQueue(QUEUE* queue);
bool  fullQueue(QUEUE* queue);
//	End of Queue ADT Definitions 

QUEUE* createQueue(void)
{
	//	Local Definitions 
	QUEUE* queue;

	//	Statements 
	queue = (QUEUE*)malloc(sizeof(QUEUE));
	if (queue)
	{
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
		queue->sum = 0;
	} // if 
	return queue;
}	// createQueue 

bool enqueue(QUEUE* queue, void* itemPtr)
{

	//	Local Definitions 
	QUEUE_NODE* newPtr;

	//	Statements 
	if (!(newPtr =
		(QUEUE_NODE*)malloc(sizeof(QUEUE_NODE))))
		return false;

	newPtr->dataPtr = itemPtr;
	newPtr->next = NULL;


	if (queue->count == 0) {
		// Inserting into null queue 
		queue->front = newPtr;
		
	}
	else {
		queue->rear->next = newPtr;
	}
		(queue->count)++;
		queue->rear = newPtr;
	

	return true;

}	// enqueue 


bool dequeue(QUEUE* queue, void** itemPtr)
{
	//	Local Definitions 
	QUEUE_NODE* deleteLoc;

	//	Statements 
	if (!queue->count)
		return false;

	*itemPtr = queue->front->dataPtr;
	deleteLoc = queue->front;
	if (queue->count == 1)
		// Deleting only item in queue 
		queue->rear = queue->front = NULL;
	else
		queue->front = queue->front->next;
	(queue->count)--;
	free(deleteLoc);

	return true;
}	// dequeue 

bool queueFront(QUEUE* queue, void** itemPtr)
{
	//	Statements 
	if (!queue->count)
		return false;
	else
	{
		*itemPtr = queue->front->dataPtr;
		return true;
	} // else 
}	// queueFront 

bool queueRear(QUEUE* queue, void** itemPtr)
{
	//	Statements 
	if (!queue->count)
		return false;
	else
	{
		*itemPtr = queue->rear->dataPtr;
		return true;
	} // else 
}	// queueRear

bool emptyQueue(QUEUE* queue)
{
	//	Statements 
	return (queue->count == 0);
}	// emptyQueue 

bool fullQueue(QUEUE* queue)
{
	//	Local Definitions *
	QUEUE_NODE* temp;

	//	Statements 
	temp = (QUEUE_NODE*)malloc(sizeof(*(queue->rear)));
	if (temp)
	{
		free(temp);
		return true;
	} // if 
 // Heap full 
	return false;
}	// fullQueue 

int queueCount(QUEUE* queue)
{
	//	Statements 
	return queue->count;
}	// queueCount 

QUEUE* destroyQueue(QUEUE* queue)
{
	//	Local Definitions 
	QUEUE_NODE* deletePtr;

	//	Statements 
	if (queue)
	{
		while (queue->front != NULL)
		{
			free(queue->front->dataPtr);
			deletePtr = queue->front;
			queue->front = queue->front->next;
			free(deletePtr);
		} // while 
		free(queue);
	} // if 
	return NULL;
}	// destroyQueue 


void fillQueue(QUEUE*);
void printQueues(QUEUE*, QUEUE*, QUEUE*, QUEUE*);
void printOneQueue(QUEUE* pQueue);

void fillQueue(QUEUE* q)
{
	//	Local Definitions 
	int  item;
	int* dataPtr;

	//	Statements 
	printf("Initializing data:\n");
	srand(49);

	for (int i = 1; i <= 25; i++)
	{
		if (!(dataPtr = (int*)malloc(sizeof(int))))
			printf("Overflow in fillQueues\a\n"),
			exit(100);

		*dataPtr = item = rand() % 51;
		enqueue(q, dataPtr);
		q->sum += item;

		//printf("Item added to queue: ");
		printf("%3d", item);
		if (!(i % 11))
			// Start new line when line full 
			printf("\n");
	} // for 
	//printf("\nEnd of data insertion\n");
	return;
}	// fillQueues 

void printOneQueue(QUEUE* pQueue)
{
	//	Local Definitions 
	int  lineCount;
	int* dataPtr;

	//	Statements 
	lineCount = 0;
	while (!emptyQueue(pQueue))
	{
		dequeue(pQueue, (void**)&dataPtr);
		if (lineCount++ >= 10)
		{
			lineCount = 1;
			printf("\n             ");
		} // if 
		printf("%3d ", *dataPtr);
	} // while !emptyQueue 
	printf("\n");

	return;
}	// printOne Queue 

