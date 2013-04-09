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
	Node* pPreW = NULL;// pWalker�� �տ� ���� ����
	Node* pWalker = head->pHead; // pCur�� �񱳸� �ϱ����� ����Ʈ�� ���ƴٴ�
	Node* pPre = head->pHead;// pCur�տ� �մ� ����
	Node* pCur = pPre->pNext;//���� �Ȱ��� �ȵȰ��� ��������

	while(pCur) //pCur != NULL
	{
		while(pWalker != pCur)// IF pWalker == pCur (YES) break;
		{
			if(pCur->frequency >= pWalker->frequency) //IF pCur < pWalker (NO)
			{//pPreW �� pWalker�� ��ĭ�� �̵�
				pPreW = pWalker;
				pWalker = pWalker->pNext;
			}
			else if(pCur->frequency < pWalker->frequency) //IF pCur < pWalker (YES)
			{
				pPre->pNext = pCur->pNext; 
				pCur->pNext = pWalker;      // pCur�� �յڸ� ����

				if(pPreW == NULL) // pCur�� ������ �ڸ��� �� ���� ���
				{
					head->pHead =pCur;
				}
				else //pCur�� ������ �ڸ��� �߰��� ���
				{
					pPreW->pNext = pCur;
				}
				break;
			}
		}

		// pPreW�� pWalker�� ó������ �ʱ�ȭ
		pPreW = NULL; 
		pWalker = head->pHead;

		//pPre�� pCur�� ��ĭ�� �ڷ� �̵�
		pPre = pCur;
		pCur = pPre->pNext;
	}
}

void Sort_code(List* head)
{	
	Node* pPreW = NULL;// pWalker�� �տ� ���� ����
	Node* pWalker = head->pHead; // pCur�� �񱳸� �ϱ����� ����Ʈ�� ���ƴٴ�
	Node* pPre = head->pHead;// pCur�տ� �մ� ����
	Node* pCur = pPre->pNext;//���� �Ȱ��� �ȵȰ��� ��������

	int w_len, c_len;

	while(pCur) //pCur != NULL
	{
		while(pWalker != pCur)// IF pWalker == pCur (YES) break;
		{
			w_len = strlen(pWalker->Code);
			c_len = strlen(pCur->Code);

			if(c_len >= w_len) //IF pCur < pWalker (NO)
			{//pPreW �� pWalker�� ��ĭ�� �̵�
				pPreW = pWalker;
				pWalker = pWalker->pNext;
			}
			else if(c_len < w_len) //IF pCur < pWalker (YES)
			{
				pPre->pNext = pCur->pNext; 
				pCur->pNext = pWalker;      // pCur�� �յڸ� ����

				if(pPreW == NULL) // pCur�� ������ �ڸ��� �� ���� ���
				{
					head->pHead =pCur;
				}
				else //pCur�� ������ �ڸ��� �߰��� ���
				{
					pPreW->pNext = pCur;
				}
				break;
			}
		}

		// pPreW�� pWalker�� ó������ �ʱ�ȭ
		pPreW = NULL; 
		pWalker = head->pHead;

		//pPre�� pCur�� ��ĭ�� �ڷ� �̵�
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