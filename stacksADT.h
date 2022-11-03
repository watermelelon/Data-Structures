#pragma once
#include <stdio.h>
#include <stdlib.h>

//	Stack ADT Type Defintions 
typedef struct node2
{
	void* dataPtr;
	struct node2* link;
} STACK_NODE;

typedef struct
{
	int         count;
	STACK_NODE* top;
} STACK;

/*	=============== createStack ============== */
STACK* createStack(void)
{
	//	Local Definitions 
	STACK* stack;

	//	Statements 
	stack = (STACK*)malloc(sizeof(STACK));
	if (stack)
	{
		stack->count = 0;
		stack->top = NULL;
	} // if 
	return stack;
}	// createStack 


/*	================= pushStack ================*/
bool pushStack(STACK* stack, void* dataInPtr)
{
	//	Local Definitions 
	STACK_NODE* newPtr;

	//	Statements 
	newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (!newPtr)
		return false;

	newPtr->dataPtr = dataInPtr;

	newPtr->link = stack->top;
	stack->top = newPtr;

	(stack->count)++;
	return true;
}	// pushStack 

/*	=================== popStack ==================*/
void* popStack(STACK* stack)
{
	//	Local Definitions 
	void* dataOutPtr;
	STACK_NODE* temp;

	//	Statements 
	if (stack->count == 0)
		dataOutPtr = NULL;
	else
	{
		temp = stack->top;
		dataOutPtr = stack->top->dataPtr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
	} // else 
	return dataOutPtr;
}	// popStack 

/*	================== stackTop ================= */
void* stackTop(STACK* stack)
{
	//	Statements 
	if (stack->count == 0)
		return NULL;
	else
		return stack->top->dataPtr;
}	// stackTop 

/*	================= emptyStack ================*/
bool emptyStack(STACK* stack)
{
	//	Statements 
	return (stack->count == 0);
}	// emptyStack 

/*	================== fullStack =================*/
bool fullStack(STACK* stack)
{
	//	Local Definitions 
	STACK_NODE* temp;

	//	Statements 
	if ((temp =
		(STACK_NODE*)malloc(sizeof(*(stack->top)))))
	{
		free(temp);
		return false;
	} // if 

 // malloc failed 
	return true;
}	// fullStack 

/*	================== stackCount =================*/
int stackCount(STACK* stack)
{
	//	Statements 
	return stack->count;
}	// stackCount 

/*	================== destroyStack =================*/
STACK* destroyStack(STACK* stack)
{
	//	Local Definitions 
	STACK_NODE* temp;

	//	Statements 
	if (stack)
	{
		// Delete all nodes in stack 
		while (stack->top != NULL)
		{
			// Delete data entry 
			free(stack->top->dataPtr);

			temp = stack->top;
			stack->top = stack->top->link;
			free(temp);
		} // while 

	 // Stack now empty. Destroy stack head node. 
		free(stack);
	} // if stack 
	return NULL;
}	// destroyStack 



