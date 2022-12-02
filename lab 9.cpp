// lab 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<iostream>
#include"QueueADT.h"
#include"Traversals.h"
#include"StackADT.h"
#define ROWS 8
#define COL 8


int main()
{
    
    //Creation/Representation of graph using an adjecentary Matrix
    //we ignore the 0 row 

                           //  1 2 3 4 5 6 7
    int graph[ROWS][COL] = {{0,0,0,0,0,0,0,0 },
                   /*1*/    {0,0,1,1,1,0,0,0 },
                   /*2*/    {0,1,0,1,0,0,0,0 },
                   /*3*/    {0,1,1,0,1,0,0,0 },
                   /*4*/    {0,1,0,1,0,0,0,0 },
                   /*5*/    {0,0,0,1,1,0,1,1 },
                   /*6*/    {0,0,0,0,0,1,0,0 },
                   /*7*/    {0,0,0,0,0,1,0,0 } };


    QUEUE * values;
    STACK* values_2;

    values = createQueue();
    values_2 = createStack();
    printf("BFS Traversal: \n");
    BFS_traversal(values, graph);

    printf("DFS Traversal: \n");
    DFS_traversal(values_2, graph);
}


