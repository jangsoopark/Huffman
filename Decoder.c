#include "Decoder.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Generator.h"

int Decoder(List* head, char* filename, char* outname)
{
	FILE* fIn  = NULL;
	FILE* fOut = NULL;

	Node* node = NULL;

	char chname[128]	  = {0, };
	char inname[128]	  = {0, };
	char line_buffer[256] = {0, };
	
	char* line_ptr		  = NULL;
	
	int len = 0;
	int i;

	readTable(head, filename);

	for(i=0; filename[i]!='.'; i++)	chname[i] = filename[i];
	sprintf(inname, "%s_encoded.txt", chname);
	if((fIn = fopen(inname, "rt")) == NULL)	return -1;

	sprintf(outname, "%s_decoded.txt", chname);
	if((fOut = fopen(outname, "wt")) == NULL)	return -1;

	while(feof(fIn) == 0)
	{
		fgets(line_buffer, 256, fIn);
		line_ptr = line_buffer;

		node = head->pHead;
		while(node)
		{
			len = strlen(node->Code);
			if(strncmp(line_ptr, node->Code, len) == 0)
			{
				fprintf(fOut, "%c", node->ascii);
				line_ptr += len;
				node = head->pHead;
			}
			else	node = node->pNext;
		}

	}

	Destroy(head);

	fclose(fIn);
	fclose(fOut);
	return 1;
}