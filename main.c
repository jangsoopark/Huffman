#include "Generator.h"
#include "Encoder.h"
#include "Decoder.h"

#include <stdio.h>

int main(void)
{
	List head = {NULL};
	Tree root = {NULL};
	Queue qhead = {NULL};

	char outname[128]  = {0, };
	char codefile[128] = {0, };

	Getfrequency(&head, "Page 1.txt", outname);
	getHuffmancode(&root, &qhead, outname, codefile);
	Encoder(&head, "Page 1.txt", outname);
	Decoder(&head, "Page 1.txt", outname);

	return 0;
}