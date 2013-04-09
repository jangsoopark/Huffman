#include "Generator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Getfrequency(List* head, char* filename, char* outname)
{
	FILE* fIn  = NULL;
	FILE* fOut = NULL;

	Node* node;

	char chname[128]  = {0, };
	char symbol;
	int i;

	////////////////open input file////////////////////////////////
	if((fIn  = fopen(filename, "rt")) == NULL)	
		return -1;
	/////////////////////make output file's name//////////////////
	for(i=0; filename[i] != '.'; i++)	chname[i] = filename[i];
	chname[i] = '\0';
	sprintf(outname, "%s_table.txt", chname);
	///////////////open output file /////////////////////////////
	if((fOut = fopen(outname, "wt")) == NULL)
		return -1;

	/////////////////get symbol and frequency/////////////////
	while(feof(fIn) == 0)
	{
		symbol = fgetc(fIn);

		if(node = Search(symbol, head))
		{
			node->frequency++;
		}
		else
		{
			Insert(symbol, head);
			head->pHead->frequency++;
		}
	}

	////////////////sort list assending order///////////////////
	//Sort(head);

	///////////////write symbol and frequency to file///////////
	node = head->pHead;
	while(node)
	{
		fprintf(fOut, "'%c':%d\n", node->ascii, node->frequency);
		node = node->pNext;
	}

	////////////////destroy list and close file///////////////
	Destroy(head);

	fclose(fIn);
	fclose(fOut);

	return 1;
}

int getHuffmancode(Tree* root, Queue* head, char* filename, char* outname)
{
	FILE* fIn  = NULL;
	FILE* fOut = NULL;

	char chname[128]  = {0, };

	char Code[128]	  = {0, };

	int len = 0, deep = -1,
		i;

	//////////open input file///////////////////////////
	////// symbol:frequency////////////////////////////
	if((fIn = fopen(filename, "rt")) == NULL)
		return -1;
	/////////////// make out file's name////////////////////////
	for(i=0; filename[i] != '.'; i++)	chname[i] = filename[i];
	chname[i] = '\0';
	sprintf(outname, "%s_code.txt", chname);

	////////////open output file///////////////////
	////////////symbol:Huffman code///////////////
	if((fOut = fopen(outname, "wt")) == NULL ) 
		return -1;

	while(1)
	{
		///read symbol and frequency from text file
		// and save data to queue
		Node* pNew = (Node*)malloc(sizeof(Node));
		if(fscanf(fIn, "'%c':%d\n", &pNew->ascii, &pNew->frequency) == -1)
			break;
		pNew->lChild = NULL;
		pNew->rChild = NULL;
		Push(head, pNew);
		len++;
	}

	// make Huffman tree use Queue
	root = tree(root, head, len);
	codeSearch(fOut, root->Root, deep, Code);

	fclose(fIn);
	fclose(fOut);

	return 1;
}

int readTable(List* head, char* filename)
{
	FILE* fIn = NULL;
	char chname[128] = {0, };

	int i;

	for(i=0; filename[i] != '.'; i++)	chname[i] = filename[i];
	strcat(chname, "_table_code.txt");

	if((fIn = fopen(chname, "rt")) == NULL)	return -1;

	while(feof(fIn) == 0)
	{
		Node* Data = (Node*)malloc(sizeof(Node));
		fscanf(fIn, "'%c':%s\n", &Data->ascii, &Data->Code);
		Insert_N(Data, head);
	}

	Sort_code(head);

	fclose(fIn);
	return 1;
}