#include <iostream>
#include <assert.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Node {
public:
	string data;
	Node* next;

	Node()
	{
		data = "";
		next = NULL;
	}

	Node(string data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList {
	Node* head;
	Node* sorted;

public:
	LinkedList() { head = NULL; }
	int counter = 0;
	string element;
	void insertNode(string);
	void printList();
	void deleteNode(int);
	void getIndex(string);
	void getNth(int);
	int returnIndex();
	string returnData();
};

int LinkedList::returnIndex()
{
    return counter;
}

string LinkedList::returnData()
{
    return element;
}

// Method to delete Node at given index
void LinkedList::deleteNode(int index)
{
	Node *temp1 = head, *temp2 = NULL;
	int listLen = 0;

    // Check if the list is empty
	if (head == NULL)
    {
		cout << "List is empty." << endl;
		return;
	}

	// Get list length
	while (temp1 != NULL)
    {
		temp1 = temp1->next;
		listLen++;
	}

    temp1 = head;
	listLen -= 1;

	// Check if the index is out of range
	if (listLen < index)
    {
		cout << "Index out of range" << endl;
		return;
	}

	// Delete head.
	if (index == 0)
    {
		// Update head
		head = head->next;
		delete temp1;
		return;
	}

	// Traverse the list to find the node to be deleted.
	while (index > 0)
    {
		temp2 = temp1;
		temp1 = temp1->next;
		index--;
	}

	// Change the next pointer
	// of the previous node.
	temp2->next = temp1->next;

	// Delete the node
	delete temp1;
}

// Function to insert a new node.
void LinkedList::insertNode(string data)
{
	// Create new Node.
	Node* newNode = new Node(data);

	// Assign to head
	if (head == NULL) {
		head = newNode;
		return;
	}

	// Traverse till end of list
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	// Insert data to the last.
	temp->next = newNode;
}

// Method to print list's elements
void LinkedList::printList()
{
	Node* temp = head;

	// Check if the list is empty
	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	// Traverse and print
	// all element of the list.
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

// Method to get index of element x
void LinkedList::getIndex(string x)
{
    Node* temp = head;
    counter = 0;
    string tempElement;

    // Check if the list is empty
    if (head == NULL)
        cout << "List is empty" << endl;

    // Increase counter to match
    // the searched Node's index
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            tempElement = temp->data;
            break;
        }
        else
        {
            temp = temp->next;
            counter += 1;
        }
    }

    if (tempElement != x)
    {
        cout << "Not Found" << endl;
        counter = NULL;
    }
}

// Method to get element at index N
void LinkedList::getNth(int index)
{
    Node* temp = head;
    int listLen = 0;
    counter = 0;
    element = "";

    while (temp != NULL)
    {
		temp = temp->next;
		listLen++;
	}

    temp = head;
	listLen -= 1;

    if (listLen < index)
    {
		cout << "Index out of range" << endl;
		return;
	}

    // Loop to check if the current index
    // is equal to the index searched
    while (temp != NULL)
    {
        if (counter == index)
            element = temp->data;
        counter++;
        temp = temp->next;
    }
}
