#include "ddlist.h"
#include "limits.h"
#include "debug.h"

Node * insertByMultiValue(Node** top, Node** tail,  unsigned long long key, unsigned long long value,unsigned long long value2  ,record * data){
   

    //search if it is exits
    Node * searchedItem = searchValue(*top, *tail , value);
    //if not in list , initial this dlist
    if (searchedItem == NULL){
        searchedItem = insert_seq_value(top, tail , key, value , NULL );
    }
    //insert into list
    return insert_seq_value( &(searchedItem->data.list_pointer.head) , &(searchedItem->data.list_pointer.tail) , key, value2  , data);
    
    
    
}
void ddlist_print(Node* top, Node* tail){
    Node * current = top;
	while(current != NULL){
        printf("value1: %llu\n", current->value );
		dlist_print(current->data.list_pointer.head, current->data.list_pointer.tail);
		current = current->next;
	}
}

void ddlist_clear(Node** top, Node** tail){
    Node * current = *top;
	while(current != NULL){
        
		dlist_clear( &(current->data.list_pointer.head ) , &(current->data.list_pointer.tail) );
		current = current->next;
	}
}

record * getValueTwoMin(Node** top, Node** tail){
    
    
    Node * current = *top;
    Node * target ;
    if (current ==NULL){
        
        return NULL;

    }


    record * rt = (record *) malloc (sizeof(record) );
    int recordSpeed = INT_MAX;
    
	while(current != NULL){
        
        Node * compareTarget = searchNumber(current->data.list_pointer.head , current->data.list_pointer.tail, 1);
        
        if (recordSpeed >  compareTarget->value ){
            
            recordSpeed = current->value;
            target = current;
        }
		
		current = current->next;
	}
    
    //record copy
    Node * tempnode =searchNumber(target->data.list_pointer.head , target->data.list_pointer.tail, 1);
    memcpy (rt , tempnode->data.content.ld , sizeof (record) );
    
    //delete it from list
    delete_front( &(target->data.list_pointer.head) , &(target->data.list_pointer.tail));
    if (target->data.list_pointer.head == NULL){
        delete_seq(top, tail, target->key );
    }
    
    return rt;
}

record * getValueOneMax(Node** top, Node** tail){
    if (*top ==NULL){
        return NULL;
    }
    Node * target =*tail;
    record * rt = (record *) malloc (sizeof(record) );
    
    
    Node * tempnode =searchNumber(target->data.list_pointer.head , target->data.list_pointer.tail, 1);
    memcpy (rt , tempnode->data.content.ld , sizeof (record) );
    
    delete_front( &(target->data.list_pointer.head) , &(target->data.list_pointer.tail));
    if (target->data.list_pointer.head == NULL){
        delete_seq(top, tail, target->key );
    }
    return rt;
}