#include "Encoder.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Generator.h"

int Encoder(List* head, char* filename , char* outname)
{
	FILE* fIn  = NULL;
	FILE* fOut = NULL;

	Node* node = NULL;
	
	char chname[128] = {0, };
	char sym_key;

	int i;
	
	readTable(head, filename);
	if((fIn = fopen(filename, "rt")) == NULL)	return -1;
	for(i=0; filename[i]!='.'; i++)	chname[i] = filename[i];
	sprintf(outname, "%s_encoded.txt", chname);
	if((fOut = fopen(outname, "wt")) == NULL)	return -1;

	while(feof(fIn) == 0)
	{
		sym_key = fgetc(fIn);
		node = Search(sym_key, head);
		if(node)		fprintf(fOut, "%s", node->Code);
		else			continue;
	}

	Destroy(head);
	fclose(fIn);
	fclose(fOut);
	return 1;
}