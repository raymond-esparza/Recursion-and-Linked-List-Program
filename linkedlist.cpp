/*
Author: Raymond Esparza
Program: Recursion and Linked List Program
Section #02
File: linkedlist.cpp

This file contains the functions for the linkedlist type. It is intended to be included by main.cpp and includes linkedllist.h
*/

#include <fstream>
//#include <iostream>
#include "linkedlist.h"



//This function uses recursion to traverses the list and returns a counter of how many nodes it visits
double linkedlist::count(node *cnode) { //use recursion
	int counter = 0;
	node *next_node = cnode->next;
	if(next_node == NULL){
		return 1;
	}
	else{
		counter = count(next_node) + 1;
	}
//	cout << "Number of nodes: " << counter << endl;
	return counter;
}



//This function uses recursion to traverse the list and returns a running sum of all the nodes it visits
double linkedlist::sum(node *cnode, int curr_sum) { //use recursion
	node *next_node = cnode->next;
	if(next_node == NULL){
		return cnode->data + curr_sum;
	}
	else{
		curr_sum = sum(cnode->next, curr_sum) + cnode->data;
	}
//	cout << "Sum of nodes: " << curr_sum << endl;	
	return curr_sum;
}



//The constructor of the linkedlist class that sets the head of the list to null
linkedlist::linkedlist() {
	head = NULL;
}



//The destructor off the linkedlist class that traverses the list and releases all the memory of the created nodes in the list
linkedlist::~linkedlist() {
	node *cnode = head;
	node *next_node;
    while(cnode != NULL){
    	next_node = cnode->next;
    	delete cnode;
    	cnode = next_node;
    }
    return;
}



//This function takes in an integer and creates a node for it. It then adds the new node to the front of the list
void linkedlist::addToFront(int n) {
	node *newhead = new node;
	newhead->data = n;
	newhead->next = head;
	head = newhead;
	return;
}



//This function calls the count and sum functions and uses those values to find the average of all integers in the list
double linkedlist::average() {
	double average;
	double num_nodes = count(head);
	double sum_nodes = sum(head, 0);
	average = sum_nodes / num_nodes;
	return average;
}



//This function traverses the list and writes to a textfile the contents of the list that should already be in sorted order
void linkedlist::writeInorder(string &file) {
	node *cnode = head;
	ofstream outfile(file);
	while(cnode != NULL){
		outfile << cnode->data << " ";
		cnode = cnode->next;
	}
	outfile << endl;
	outfile.close();
	return;
}



//This function traverses the list using recursion and once the end of the list is reached, it writes the contents of the list
//in the reverse order
bool linkedlist::writeReversed(string &file, node *cnode) {
	bool lastnode = false;
    ofstream outfile;
    outfile.open(file, ios::app); //Opens the file for appending, rather than overwriting
    if (cnode == NULL){
    	return true;
    }
    else{
    	lastnode = writeReversed(file, cnode->next);
    }
    if(lastnode){
    	outfile << cnode->data << " ";
    }
    return lastnode;
}



node* linkedlist::getHead(){
	return head;
}



void linkedlist::changeHead(node *newhead){
	head = newhead;
}
