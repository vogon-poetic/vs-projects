#include "LinkedList.h"
#include "graph1.h"

LinkedList::LinkedList()
{
	this->first = NULL;
}
void LinkedList::addNode(GenPoint point)
{
	Node* last = new Node;
	Node* current = NULL;

	last->point.setPoint(point.getX(), point.getY());
	last->next = NULL;

	if (first == NULL) {
		first = last;
	} else {
		current = first;
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = last;
	}
}

void LinkedList::draw()
{
	displayBMP("arkansas1.bmp", 0, 0);
	Node* p = this->first;
	while (p != NULL) {
		int x = p->point.getX();
		int y = p->point.getY();
		
		// draw the filled circle
		for (int r = 0; r <= 10; ++r) {
			setColor(drawCircle(r, x, y), 0, 0, 0);
		}

		// increment p
		p = p->next;
	}
}
