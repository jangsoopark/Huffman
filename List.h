#ifndef __LIST_H__
#define __LIST_H__

#include "Node.h"

typedef struct 
{
	Node* pHead;
} List;

//ascii : character's symbol
//List* : Head of list

int Insert(char ascii, List* head);
void Insert_N(Node* Data, List* head);
int Delete(char ascii, List* head);
Node* Search(char ascii, List* head);
void Sort (List* head);
void Sort_code(List* head);
void Destroy(List* head);

#endif