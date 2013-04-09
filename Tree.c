#include "Tree.h"

#include "Queue.h"
#include <stdlib.h>

Tree* tree(Tree* root, Queue* head, int len)
{
	Node* Left = 0x00;
	Node* Right = 0x00;
	Node* pNew = 0x00;

	int ind = 0;

	for(ind = 0; ind < len-1; ind++)
	{
		// get two node from queue
		Left  = Pop(head);
		Right = Pop(head);

		// memory allocate and initialize node data
		pNew = (Node*)malloc(sizeof(Node));
		pNew->lChild = Left;
		pNew->rChild = Right;
		pNew->frequency = Left->frequency + Right->frequency;
		pNew->ascii = 0; // subtree's root
		Push(head, pNew); //insert sub tree to queue
	}

	root->Root = Pop(head);
	return root;
}

Node* codeSearch(FILE* fp, Node* root, int deep, char* Code)
{
	Node* node = NULL;
	if(root)
	{
		deep++;				// depth index of tree
		Code[deep] = '0';	// left child
		node = codeSearch(fp, root->lChild, deep, Code);

		Code[deep] = '1';	// right child
		node = codeSearch(fp, root->rChild, deep, Code);

		Code[deep] = '\0'; // end of Huffman code

		// if node have child, that node is root of sub tree
		// so don't have to print out to file.
		// if node doesn't have any child 
		// this node have symbol character and priority  which is 
		// obtain from text file so print out to file.
		if((root->lChild == NULL || root->rChild == NULL) && root->ascii )
			fprintf(fp, "'%c':%s\n", root->ascii, Code);
	}
	free(node);
	return root;
}