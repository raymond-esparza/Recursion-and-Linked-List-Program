/*
Author: Raymond Esparza
Program: Recursion and Linked List Program
Section #02
File: main.cpp

This program is simply intended to read in a line of integers from a textfile and sort them in numerical order using
a linked list. It then counts how many integers it read, calulates the sum of the integers, and finds the average of
all of them. 
*/

#include <iostream>
#include <string>
#include <fstream>
#include "linkedlist.cpp"

using namespace std;

void readFile(linkedlist&, string&);
bool sortNodes(linkedlist&);

int main() {

	linkedlist list;
	string file = "list.txt";

	readFile(list, file);
	cout << "The average is: " << list.average() << endl;
	list.writeInorder(file);
	node* headnode = list.getHead();
	list.writeReversed(file, headnode );
	
    return 0;
}



//This function reads in integers from the input file, creates a node for it, and adds the node to the front of the linked list
//then it continually calls a sorting function until the list is sorted
void readFile(linkedlist &list, string &file) {
	int num;
	bool node_added = false;
	bool sorted;
	ifstream readfile(file);
	if(readfile.is_open() ){
		while(readfile >> num){
	 		list.addToFront(num);
	 		node_added = true;
	 	}
	 }
	 else cout << "readfile wasn't opened.\n";
	if(node_added){
	 	do{
	 		sorted = sortNodes(list);
	 	} while(!sorted);
	 }
	 readfile.close();
	 return;
}



//This function keeps track of previous, current, and next nodes in the list, compares the data in adjoining nodes, and swaps if
//necessary. It then returns a bool value to the calling function that it can use to determine if the list is sorted, or if it needs
//more sorting
bool sortNodes(linkedlist &list){
	node *cnode = list.getHead(); //current node starts off at the head of the list
	node *prev_node;
	node *next_node;
	bool sorted = true; //if the list must be reorganized, there is a possiblity that there are still elements out of order, thus requiring another call to this sorting function
	if(cnode->next == NULL){
		return sorted; //true
	}
	// else cnode->next != NULL
	next_node = cnode->next;
	
	if(cnode->data > next_node->data){ //test if the first node is bigger than the second node, if so, swap and change the head
		cnode->next = next_node->next;
		list.changeHead(next_node);
		next_node->next = cnode;
		prev_node = next_node;
		next_node = cnode->next;
		sorted = false;
	}
	else{
		prev_node = cnode;
		cnode = next_node;
		next_node = next_node->next;
	}

	 while(next_node != NULL){   //as long as there are remaining nodes in the list
		if(cnode->data > next_node->data){   //test if current node is larger than the next node, if true
			prev_node->next = next_node;	//swap nodes and redirect prev_node, cnode, and next_node accordingly
			cnode->next = next_node->next;
			next_node->next = cnode;
			next_node = cnode->next;
			prev_node = prev_node->next;
			sorted = false;     //this loop only tests for adjoining order, so if any swaps are made, there is a possibility
								//that the list is still unsorted, requiring another function call
		}
		else{
			prev_node = cnode;
			cnode = next_node;
			next_node = next_node->next;
		}
	 }
	return sorted;
}
