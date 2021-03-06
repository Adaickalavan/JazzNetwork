// Question1.cpp

#include "pch.h"
#include <iostream>

using namespace std;

struct node_t {
	unsigned v;
	struct node_t* next; 
}; 

//Segements even and odd valued nodes into two linkedl lists by rerouting the pointers
struct node_t * even_nodes(struct node_t ** ptrRef) {
	struct node_t * headEven = nullptr;
	struct node_t * tailEven = nullptr;
	struct node_t * headOdd = nullptr;
	struct node_t * tailOdd = nullptr;
	struct node_t * ptrCur = *ptrRef;

	while (ptrCur != nullptr) {
		unsigned int val = ptrCur->v;
		//Node value is even
		if (val % 2 == 0) {
			if (headEven == nullptr) {
				headEven = ptrCur;
				tailEven = ptrCur;
			}
			else {
				tailEven->next = ptrCur;
				tailEven = tailEven->next;
			}
		}
		//Node value is odd
		else {
			if (headOdd == nullptr) {
				headOdd = ptrCur;
				tailOdd = ptrCur;
			}
			else {
				tailOdd->next = ptrCur;
				tailOdd = tailOdd->next;
			}
		}
		//Move ptrCur to next node
		ptrCur = ptrCur->next;
	}

	//Ensure the last node points to a nullptr
	if (tailEven != nullptr) {
		tailEven->next = nullptr;
	}
	if (tailOdd != nullptr) {
		tailOdd->next = nullptr;
	}

	//Reassign reference pointer to head of odd list
	*ptrRef = headOdd;

	return headEven;
}

//Creates a singly linked list of length n beginning at pointer location pointed by ptrRef
void createLinkedList(struct node_t ** ptrRef, int n) {
	struct node_t * head = nullptr;
	struct node_t * tail = *ptrRef;

	for (int ii = 1; ii <= n; ++ii) {
		unsigned int val = ii; //Fill member `v` with sequential numbers for testing purposes
		//unsigned int val = rand()%51; //Fill member `v` with random numbers between 0 and 50 inclusive
		
		struct node_t * newNode = new struct node_t;
		newNode->v = val;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}
	}

	//Reassign reference pointer to head of list
	*ptrRef = head;
}

//Prints a linked list
void display(struct node_t * ptr) {
	while (ptr != nullptr) {
		cout << ptr->v << "    ";
		ptr = ptr->next;
	}
	cout << "\n\n";
}

int main(){
	//Create an empty list with a null head pointer
	struct node_t * head = nullptr;

	//Create a singly linked list of length n
	//Length n=0 results in a null head pointer
	int n = 7;
	createLinkedList(&head, n);

	//Display the  original linked list
	cout << "Original linked list:" << "\n";
	display(head);

	//Call the even_nodes function
	struct node_t * headEven = even_nodes(&head);

	//Display the segmented odd and even list
	cout << "Original linked list after removal of even valued nodes:" << "\n";
	display(head);

	cout << "New linked list containing the removed even valued nodes:" << "\n";
	display(headEven);
}
