#ifndef DLIST_H
#define DLIST_H


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

typedef struct mylist Node;
typedef union DATA_TEST{
	struct{
		Node* head;
		Node* tail;
		unsigned long long num_ele;// this Node has how much element
		unsigned long long age;// this Node has how much element
	} list_pointer;
	struct{
		unsigned long long key;
		unsigned long long value;
		record* ld;
	} content;
} specif;


struct mylist{
	unsigned long long key;
	unsigned long long value;
	specif  data;
	struct mylist* next;
	struct mylist* prev; 
};



Node * insert_front(Node** top, Node** tail, unsigned long long key, unsigned long long value, record * data);
Node * insert_back(Node** top, Node** tail, unsigned long long key, unsigned long long value, record * data);
Node * insert_seq(Node** topm, Node** tail, unsigned long long key, unsigned long long value, record * data);
Node * insert_seq_value(Node** topm, Node** tail, unsigned long long key, unsigned long long value, record * data);
int empty(Node* top);

void delete_front(Node** top, Node** tail);
void delete_back(Node** top, Node** tail);
void delete_seq(Node** top, Node**tail ,unsigned long long key);

void dlist_print(Node* top, Node* tail);
void NodeBublesort(Node** top, Node** tail);

void Nodequicksort(Node** head, Node** tail );

Node * make_dlistnode(unsigned long long key, unsigned long long value, record * data);
Node* searchKey(Node* top, Node* tail, unsigned long long key);
Node* searchValue(Node* top, Node* tail, unsigned long long value);
Node* searchNumber(Node* top, Node* tail, int  value);
void update(Node** top, Node** tail,unsigned long long key_1, unsigned long long value_2);
void dlist_clear(Node** top, Node** tail);

#endif
