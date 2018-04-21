#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "GenPoint.h"

struct Node
{
	GenPoint point;
	Node* next;
};

class LinkedList
{
private:
	Node* first;

public:
	LinkedList();
	void addNode(GenPoint point);
	void draw();


};

#endif
