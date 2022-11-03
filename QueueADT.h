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

	if (queue->count == 0)
		// Inserting into null queue 
		queue->front = newPtr;
	else
		queue->rear->next = newPtr;

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
		return true;
	else
	{
		*itemPtr = queue->rear->dataPtr;
		return false;
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


void fillQueues(QUEUE*, QUEUE*, QUEUE*, QUEUE*);
void printQueues(QUEUE*, QUEUE*, QUEUE*, QUEUE*);

void printOneQueue(QUEUE* pQueue);

void fillQueues(QUEUE* q0to9, QUEUE* q10to19, QUEUE* q20to29, QUEUE* qOver29)
{
	//	Local Definitions 
	int  category;
	int  item;
	int* dataPtr;

	//	Statements 
	printf("Categorizing data:\n");
	srand(79);

	for (int i = 1; i <= 25; i++)
	{
		if (!(dataPtr = (int*)malloc(sizeof(int))))
			printf("Overflow in fillQueues\a\n"),
			exit(100);

		*dataPtr = item = rand() % 51;
		category = item / 10;
		printf("%3d", item);
		if (!(i % 11))
			// Start new line when line full 
			printf("\n");

		switch (category)
		{
		case 0: enqueue(q0to9, dataPtr);
			break;
		case 1: enqueue(q10to19, dataPtr);
			break;
		case 2: enqueue(q20to29, dataPtr);
			break;
		default: enqueue(qOver29, dataPtr);
			break;
		} // switch 
	} // for 
	printf("\nEnd of data categorization\n\n");
	return;
}	// fillQueues 

void printQueues(QUEUE* q0to9, QUEUE* q10to19,
	QUEUE* q20to29, QUEUE* qOver29)
{
	//	Statements 
	printf("Data   0.. 9:");
	printOneQueue(q0to9);

	printf("Data  10..19:");
	printOneQueue(q10to19);

	printf("Data  20..29:");
	printOneQueue(q20to29);

	printf("Data over 29:");
	printOneQueue(qOver29);

	return;
}	// printQueues 

void printOneQueue(QUEUE* pQueue)
{
	//	Local Definitions 
	int  lineCount;
	int* dataPtr;

	//	Statements 
	lineCount = 0;
	while (!emptyQueue(pQueue))
	{
		dequeue(pQueue, (void*)&dataPtr);
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

