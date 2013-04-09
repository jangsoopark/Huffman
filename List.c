#include "List.h"
#include <stdlib.h>
#include <string.h>

int Insert(char ascii, List* head)
{
	Node* pNew;

	if((pNew = (Node*)malloc(sizeof(Node))) == NULL)
		return -1;

	pNew->ascii		 = ascii;
	pNew->frequency	 = 0;
	pNew->lChild	 = NULL;
	pNew->rChild	 = NULL;
	pNew->pNext		 = NULL;

	// insert data to head
	pNew->pNext = head->pHead;
	head->pHead = pNew;

	return 1;
}

void Insert_N(Node* Data, List* head)
{
	Data->pNext = head->pHead;
	head->pHead = Data;
}

int Delete(char ascii, List* head)
{
	Node* pPre = 0x00;
	Node* pDel = 0x00;

	// if list is exist save value 
	// to node which is rounds list
	if(head->pHead)
	{
		pPre = head->pHead;
		pDel = pPre->pNext;
	}

	// find due for delete node
	while(pDel)
	{
		if(pDel->ascii == ascii)
			break;
		pPre = pPre->pNext;
		pDel = pPre->pNext;
	}

	// if program can't find data	return -1
	// and if find data  DELETE;;;
	if(pDel == 0x00)					return -1;
	if(pDel == head->pHead)				head->pHead = head->pHead->pNext;
	else if(pDel->pNext == 0x00)		pPre->pNext = 0x00;
	else								pPre->pNext = pDel->pNext;

	free(pDel);
	return 1;
}

// Search node from list
Node* Search(char ascii, List* head)
{
	Node* pCur = head->pHead;

	while(pCur)
	{
		if(pCur->ascii == ascii)
			return pCur;
		pCur = pCur->pNext;
	}

	return pCur;
}

// sort list in assending order
// insertion sort
void Sort (List* head)
{
	Node* pPreW = NULL;// pWalker의 앞에 있을 변수
	Node* pWalker = head->pHead; // pCur와 비교를 하기위해 리스트를 돌아다님
	Node* pPre = head->pHead;// pCur앞에 잇는 변수
	Node* pCur = pPre->pNext;//정렬 된곳과 안된곳을 구분지음

	while(pCur) //pCur != NULL
	{
		while(pWalker != pCur)// IF pWalker == pCur (YES) break;
		{
			if(pCur->frequency >= pWalker->frequency) //IF pCur < pWalker (NO)
			{//pPreW 와 pWalker이 한칸씩 이동
				pPreW = pWalker;
				pWalker = pWalker->pNext;
			}
			else if(pCur->frequency < pWalker->frequency) //IF pCur < pWalker (YES)
			{
				pPre->pNext = pCur->pNext; 
				pCur->pNext = pWalker;      // pCur의 앞뒤를 연결

				if(pPreW == NULL) // pCur이 가야할 자리가 맨 앞일 경우
				{
					head->pHead =pCur;
				}
				else //pCur이 가야할 자리가 중간일 경우
				{
					pPreW->pNext = pCur;
				}
				break;
			}
		}

		// pPreW와 pWalker을 처음으로 초기화
		pPreW = NULL; 
		pWalker = head->pHead;

		//pPre와 pCur은 한칸씩 뒤로 이동
		pPre = pCur;
		pCur = pPre->pNext;
	}
}

void Sort_code(List* head)
{	
	Node* pPreW = NULL;// pWalker의 앞에 있을 변수
	Node* pWalker = head->pHead; // pCur와 비교를 하기위해 리스트를 돌아다님
	Node* pPre = head->pHead;// pCur앞에 잇는 변수
	Node* pCur = pPre->pNext;//정렬 된곳과 안된곳을 구분지음

	int w_len, c_len;

	while(pCur) //pCur != NULL
	{
		while(pWalker != pCur)// IF pWalker == pCur (YES) break;
		{
			w_len = strlen(pWalker->Code);
			c_len = strlen(pCur->Code);

			if(c_len >= w_len) //IF pCur < pWalker (NO)
			{//pPreW 와 pWalker이 한칸씩 이동
				pPreW = pWalker;
				pWalker = pWalker->pNext;
			}
			else if(c_len < w_len) //IF pCur < pWalker (YES)
			{
				pPre->pNext = pCur->pNext; 
				pCur->pNext = pWalker;      // pCur의 앞뒤를 연결

				if(pPreW == NULL) // pCur이 가야할 자리가 맨 앞일 경우
				{
					head->pHead =pCur;
				}
				else //pCur이 가야할 자리가 중간일 경우
				{
					pPreW->pNext = pCur;
				}
				break;
			}
		}

		// pPreW와 pWalker을 처음으로 초기화
		pPreW = NULL; 
		pWalker = head->pHead;

		//pPre와 pCur은 한칸씩 뒤로 이동
		pPre = pCur;
		pCur = pPre->pNext;
	}
}

// destroy list
void Destroy(List* head)
{
	Node* pDel = head->pHead;
	while(head->pHead)
	{
		pDel = head->pHead;
		head->pHead = head->pHead->pNext;
		free(pDel);
	}

	head->pHead = NULL;
	head = NULL;
}