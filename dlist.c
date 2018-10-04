#include "dlist.h"
#include "debug.h"
void swapNodeContent(Node *a, Node *b){
	unsigned long long temp;
	specif  tempdata;
	temp = a->key;
	a->key =b->key;
	b->key = temp;
	
	temp = a->value;
	a->value = b->value;
	b->value = temp;

	tempdata = a->data;
	a->data = b->data;
	b->data  = tempdata;
}


void NodeBublesort(Node **top, Node** tail){
    if (empty(*top)){
        return;
    }
    
	
    Node * start = *top;
    Node * over =  *tail;
    Node * ntemp;
    while(start != over){
        ntemp = start;
        while(ntemp != over){
            if (ntemp->value > ntemp->next->value ){
				swapNodeContent(ntemp, ntemp->next);
                

            }
            ntemp = ntemp ->next;
        };
        over = over->prev;
    };
}
Node* insert_seq(Node** top, Node** tail, unsigned long long key, unsigned long long value,  record * data){
    Node * temp;
    Node *newlist;
    if (empty(*top)){
        return insert_front(top, tail, key, value, data);
    }
    if (key >= (*tail)->key ){
		if (key == (*tail)->key  ){
			//fprintf(stderr, "Already has key");
			return NULL;
		}
        return insert_back(top, tail, key, value, data);;
    } 
    
    
    for(temp = *top; temp != *tail ; temp = temp->next  ){
        if ( key <= temp -> key) break;
    }
	if (key == (temp)->key  ){
			//fprintf(stderr, "Already has key %llu\n", key);
			return NULL;
	}
    if ( temp == *top ){
		
        
        return insert_front(top, tail, key, value, data);
    }
	
    newlist = make_dlistnode(key, value, data);
    newlist->next = temp;
    newlist->prev = temp->prev;
    temp->prev->next = newlist;
    temp->prev = newlist;
	return  newlist;
}

Node* insert_seq_value(Node** top, Node** tail, unsigned long long key, unsigned long long value,  record * data){
    Node * temp;
    Node *newlist;
    if (empty(*top)){
        return insert_front(top, tail, key, value, data);
    }
    if (value >= (*tail)->value ){
		if (value == (*tail)->value  ){
			//fprintf(stderr, "Already has key");
			return NULL;
		}
        return insert_back(top, tail, key, value, data);;
    } 
    
    
    for(temp = *top; temp != *tail ; temp = temp->next  ){
        if ( value <= temp -> value) break;
    }
	if (value == (temp)->value  ){
			//fprintf(stderr, "Already has key %llu\n", key);
			return NULL;
	}
    if ( temp == *top ){
		
        
        return insert_front(top, tail, key, value, data);
    }
	
    newlist = make_dlistnode(key, value, data);
    newlist->next = temp;
    newlist->prev = temp->prev;
    temp->prev->next = newlist;
    temp->prev = newlist;
	return  newlist;
}


Node* insert_front(Node** top, Node** tail, unsigned long long key, unsigned long long value, record * data){
	Node* temp =  make_dlistnode (key, value,data);
	if(temp == NULL){
		printf ("Error Memory Acess \n");
		return NULL;
	}
	else{
		
		temp->next = *top;
		if(*top != NULL){
			(*top)->prev = temp;
		}
		*top = temp;
		if(*tail == NULL){
			*tail = *top;
		}
        return temp;
	}
	return NULL;
}
Node* insert_back(Node** top, Node** tail, unsigned long long key, unsigned long long value,  record * data){
    Node* temp = make_dlistnode (key, value,data);
	if(temp == NULL){
		return NULL;
	}
	else{
		
		temp->prev = *tail;
		if(*tail != NULL){
			(*tail)->next = temp;
		}
		*tail = temp;
		if(*top == NULL){
			*top = *tail;
		}
        return temp;
	}
	return NULL;
}

int empty(Node* top){
	if(top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void delete_front(Node** top, Node** tail){
	Node *temp = *top;
	if(*top == NULL){
		return;
	}
	else{
		if(*tail == *top){
			*top = NULL;
			*tail = NULL;
		}
		else{
			*top = (*top)->next;
			(*top)->prev = NULL;
		}
		
        free(temp->data.content.ld);
		free(temp);
	}
}

void delete_back(Node** top, Node** tail){
	Node* temp = *tail;
	if(*tail == NULL){
		return;
	}
	else{
		if(*top == *tail){
			*tail = NULL;
			*top = NULL;
		}
		else{
			*tail = (*tail)->prev;
			(*tail)->next = NULL;
		}
		
		
        free((temp->data.content.ld) ) ;
		
		free(temp);
	}
}

void delete_seq(Node** top, Node**tail, unsigned long long key){
	
	Node* temp = *top;
	while(temp != NULL){
		if (key == temp->key ){
			break;
		}
		 
		temp = temp->next;
		
	}
	if (*top ==*tail){
		delete_front(top,tail);
	}
	else if (temp ==*top ){
		delete_front(top,tail);

	}
	else if (temp == *tail){
		delete_back(top,tail);
	}
	else{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		
		free(temp->data.content.ld);
		free(temp);
	}
	
}

void dlist_print(Node* top, Node* tail){
	Node* current = top;
	while(current != NULL){
		printf("%llu %llu |", current->key, current->value);
		current = current->next;
	}
	printf("\n");
}

void update(Node** top, Node** tail,unsigned long long key_1, unsigned long long value_2){
	Node * current = *top;
	while(current != NULL){
		if (current->key ==key_1){
			
			current->value = value_2;
		}
		current = current->next;
	}
	
}
Node* searchKey(Node* top, Node* tail, unsigned long long key){
	Node * current = top;
	while(current != NULL){
		if (current->key ==key){
			
			return current;
		}
		current = current->next;
	}
	return NULL;
}
Node* searchValue(Node* top, Node* tail, unsigned long long value){
	Node * current = top;
	while(current != NULL){
		if (current->value ==value){
			
			return current;
		}
		current = current->next;
	}
	return NULL;
}

Node* searchNumber(Node* top, Node* tail, int value){
	Node * current = top;
	
	for (int i = 0 ; i < value - 1; i++ ){
		
		if (current == NULL){
				return NULL;
		}
	    
		current = current->next;
	}
	
	return current;
}

Node * make_dlistnode(unsigned long long key, unsigned long long value, record * data){
	record * newrcord = NULL;
    Node *newlist = (Node *) malloc(sizeof(Node) );
    newlist->next = NULL;
    newlist->prev = NULL;
    newlist->key = key;
    newlist->value = value; 
	if (data !=NULL){
		memset( &(newlist->data) , 0x00, sizeof(specif));
		newrcord =  (record*) malloc (sizeof (record) );
		memcpy (newrcord, data, sizeof(record) );
		free(data);
	}
	
	
    newlist->data.content.ld = newrcord;
	return newlist;
	
}

void dlist_clear(Node** top, Node** tail){
	
	while(*top != NULL){
		
		delete_back(top, tail);
	}
}

Node* partition(Node *l, Node *h) 
{ 
    // set pivot as h element 
    unsigned long long x  = h->value; 
  
    // similar to i = l-1 for array implementation 
    Node *i = l->prev; 
  
    // Similar to "for (int j = l; j <= h- 1; j++)" 
    for (Node *j = l; j != h; j = j->next) 
    { 
        if (j->value <= x) 
        { 
            // Similar to i++ for array 
            i = (i == NULL)? l : i->next; 
  
            //swap(&(i->data), &(j->data)); 
			swapNodeContent(i, j);


        } 
    } 
    i = (i == NULL)? l : i->next; // Similar to i++ 
    //swap(&(i->value), &(h->value)); 
	swapNodeContent(i, h);
    return i; 
} 

void _Node_quicksort(Node* l, Node*  h ){
	
	if (h != NULL && l != h && l != h->next) 
    { 
        Node *p = partition(l, h); 
        _Node_quicksort(l, p->prev); 
        _Node_quicksort(p->next, h); 
    } 
	
}
void Nodequicksort(Node** head, Node** tail ){
	_Node_quicksort( &(**head) , &(**tail) ); 
	
}