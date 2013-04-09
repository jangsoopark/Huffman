#include "Queue.h"

void Push(Queue* head, Node* Data)
{
	Node* pCur= 0x00;
	Node* pNew = 0x00;

	pNew			= Data;
	pNew->pNext		= 0x00;

	// if Queue is empty push the New Data to head of Queue
	if(head->pHead == 0x00)
	{
		head->pHead  = pNew;
	}
	// if New Data's priority is higher than head's 
	// Put New Data to head of Queue
	else if(head->pHead->frequency > pNew->frequency)
	{
		pNew->pNext = head->pHead;
		head->pHead = pNew;
	}
	// Compare priority of New Data with element of Queue
	// and put New Data to proper location
	else
	{
		pCur = head->pHead;
		while(pCur->pNext)
		{
			if(pCur->pNext->frequency <= pNew->frequency)
				pCur = pCur->pNext;
			else
			{
				pNew->pNext = pCur->pNext;
				pCur->pNext = pNew;
				break;
			}
		}
		//in case of the New Data has lowest priority
		if(pCur->pNext == 0x00)
			pCur->pNext = pNew;
	}
}
Node* Pop(Queue* head)
{
	// pop head element of Queue
	Node* pCur = head->pHead;
	head->pHead = head->pHead->pNext;

	return pCur;
}