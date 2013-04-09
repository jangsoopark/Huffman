#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "Node.h"

typedef struct Queue
{
	Node* pHead;
} Queue;

//Queue* : Queue list
//Node*  : new data

void Push(Queue* head, Node* pNew);
Node* Pop(Queue* head);				

#endif