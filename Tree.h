#ifndef __TREE_H__
#define __TREE_H__

#include "Node.h"
#include "Queue.h"
#include <stdio.h>

typedef struct 
{
	Node* Root;
} Tree;

// Tree* : root of tree
// Queue* : head of queue

Tree* tree(Tree* root, Queue* head, int len);
Node* codeSearch(FILE* fp, Node* root, int deep, char* Code);
#endif