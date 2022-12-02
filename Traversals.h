#pragma once
#include <stdio.h>
#include <stdlib.h>
#include"QueueADT.h"
#include "StackADT.h"
#define ROWS 8
#define COL 8

void BFS_traversal(QUEUE* q, int graph[ROWS][COL]) {

	int node;
	int* data;
	data = (int*)malloc(sizeof(int));

	for (int i = 1; i <= ROWS; i++) {

		for (int j = 1; j <= COL; j++) {

			if (graph[i][j] == 1) {

			
				*data = i;
				printf("Item to be enqueued: %d \n", i);
				//the error is right here
				enqueue(q, data);
				//printOneQueue(q);
				//printf("front: %d\n", q->front);
				break;
			}
		}


	}
	puts("");
	//printOneQueue(q);


}


void DFS_traversal (STACK* s, int graph[ROWS][COL]) {

	printf("hola");
	int data;
	int top = 0;
	printf("top: %d", top);

	for (int i = 1; i <= ROWS; i++) {

		for (int j = 1; j <= COL; j++) {

			if (graph[i][j] == 1 && graph[i][j] != top ) {

				//go through each row, if there is a 1, then put it on the stack 
				//and go to the next row, compare if it was already added, if not keep going 
				
				data = i;
				pushStack(s, data);

				printf("Top of stack: %d\n", s->top->data);
				
				break;
			}
		}


	}
	puts("");
	while (!emptyStack(s)) {
		printf("%d", s->top->data);
		popStack(s);

	}


}