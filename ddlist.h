#ifndef _D_DLIST_H
#define _D_DLIST_H
#include "dlist.h"
Node * insertByMultiValue(Node** top, Node** tail, unsigned long long key, unsigned long long value, unsigned long long value2 ,record * data);
record * getValueTwoMin(Node** top, Node** tail);
record * getValueOneMax(Node** top, Node** tail);

void ddlist_print(Node* top, Node* tail);
void ddlist_clear(Node **head, Node **tail);
#endif
