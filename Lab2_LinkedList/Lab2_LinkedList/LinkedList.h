#pragma once
#include <string>
#include "LinkedListInterface.h"

using namespace std;

template<class T>
class LinkedList : public LinkedListInterface <T>
{
private: 
	struct Node
	{
		T data;
		Node* next;
		Node(const T& data_item, Node* next_ptr = NULL) : data(data_item), next(next_ptr) {}
	};
	Node* head = NULL;
public:
	const int FOUND = 1;
	const int NOTFOUND = 0;
	int found_status = 0;
	int list_size;
	//255 or 257

	Node* findNode(T value)
	{
		Node* traversing_node = head;
		while (traversing_node->data != value)
		{
			traversing_node = traversing_node->next;
		}
		if (traversing_node->data == value)
		{
			return traversing_node;
		}
		return NULL;
		
	}

	int DuplicateCheck(T value)
	{
		Node* traversing_node = head;
		while (traversing_node!=NULL)
		{
			if (value == traversing_node->data)
			{
				return found_status = FOUND;
			}
			traversing_node = traversing_node->next;
		}
		return found_status = NOTFOUND;
	}
	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value)
	{
		DuplicateCheck(value);
		if (head != NULL)
		{
			if (found_status != FOUND)
			{
				Node* newNode = new Node(value, head);
				head = newNode;
				newNode->data = value;
			}
			else
			{
				return;
			}
		}
		else
		{
			Node* newNode = new Node(value, NULL);
			head = newNode;
			newNode->data = value;
		}

	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value)
	{
		//Perform duplication check. If there is a duplicate, found status will be 1.
		DuplicateCheck(value);
		if (found_status == FOUND) return;
		//Create a new node that points to Node. 
		Node* newNode = new Node(value, NULL);
		//Initialize a temporary variable **traversing_node** that will point to the beginning of the list.
		Node* traversing_node = head;
		//If head does not point to NULL(or in other words...more than one item in the list), then enter if statement.
		if (traversing_node != NULL)
		{
			//The traversing node poinnts to an object. If that object(which is another pointer), doesn't 
			//point to NULL, then enter the while loop. 
			while (traversing_node->next != NULL)
			{
				//move node pointer to next node. 
				traversing_node = traversing_node->next;
			}
			//Once it points to NULL, assign newNode to that pointer. 
			traversing_node->next = newNode;
			return;
		}
		else if (traversing_node = NULL)
		{
			//This could be non--functional.
			traversing_node = newNode;
		}

	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode)
	{
		DuplicateCheck(value);
		Node* found_node = findNode(insertionNode);

		if (found_node != NULL)
		{
			Node* newNode = new Node(value, NULL);
			newNode->next = found_node->next;
			found_node->next = newNode;

		}
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value)
	{
		DuplicateCheck(value);
		if (found_status == NOTFOUND) { return; }
		Node* traversing_node = head;
		while (traversing_node != NULL)
		{
			if (traversing_node->next->data == value)
			{
				Node * removeNode = traversing_node->next;
				traversing_node->next = traversing_node->next->next;
				delete removeNode;
				return;
			}
			traversing_node = traversing_node->next;
		}
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear()
	{
		while (head != NULL)
		{
			Node* traversing_node = head->next;
			delete head;
			head = traversing_node;
		}
		return;
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index)
	{
		//if (index < 0 || index >= size()) { throw out_of_range; };;
		int counter = 0;
		Node* traversing_node = head;
		while (counter < index)
		{
			counter++;
			traversing_node = traversing_node->next;
		}
		return traversing_node->data;
	}
	/*
	size

	Returns the number of nodes in the list.
	*/
	int size()
	{
		Node* traversing_node = head;
		while (traversing_node != NULL)
		{
			list_size++;
			traversing_node = traversing_node->next;
		}
		return list_size;
	}

};

