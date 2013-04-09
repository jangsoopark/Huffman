#ifndef __NODE_H__
#define __NODE_H__

typedef struct Node_
{
	char ascii;
	int frequency;
	char Code[128];

	struct Node_* pNext;

	struct Node_* lChild;
	struct Node_* rChild;

} Node;

#endif