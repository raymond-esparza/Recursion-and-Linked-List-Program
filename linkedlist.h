/*
Author: Raymond Esparza
Program: Recursion and Linked List Program
Section #02
File: linkedlist.h

This file is the header file for the linkedlist class and the information for creating a node.
It is intended to be included by linkedlist.cpp. 
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct node {
    int data;
    node *next; //pointer to another node
};

class linkedlist {
private:
    node *head;
    double count(node *cnode); // RECURSIVE
    double sum(node *cnode, int curr_sum); // RECURSIVE

public:
    linkedlist();
    ~linkedlist(); // RECURSIVE
    void addToFront(int n); //done
    double average(); // uses sum and count functions
    void writeInorder(string &file);
    bool writeReversed(string &file, node *cnode);
    node* getHead();
    void changeHead(node *newhead);
};
#endif // end linkedlist.h