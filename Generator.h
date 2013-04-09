#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include "List.h"
#include "Tree.h"
#include "Queue.h"

//List*	: head of list
//Tree* : root of tree
//Queue*: head of queue
//filename : 
//			Getfrequency()	: general text file's name
//			getHuffmancode(): symbol:frequency table's name
//outname :
//			Getfrequency()	: symbol:frequency table's name
//			getHuffmancode(): symbol:Huffmancode table's name


int Getfrequency(List* head, char* filename, char* outname);
int getHuffmancode(Tree* root, Queue* head, char* filename, char* outname);
int readTable(List* head, char* filename);

#endif