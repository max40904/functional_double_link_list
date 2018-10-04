#include "ddlist.h"
#include "debug.h"

static Node * buf_head;
static Node * buf_tail;
int main ( ) { 
    buf_head = NULL;
    buf_tail = NULL;
   
    record * temp = (record* )malloc( sizeof(record));
    temp->value = 10;
    insertByMultiValue (&buf_head, &buf_tail, 1, 1,5, temp);

    
    
    temp = (record* )malloc( sizeof(record));
    temp->value = 30;   
    insertByMultiValue (&buf_head, &buf_tail, 3, 2,4, temp);
    
    
    temp = (record* )malloc( sizeof(record));
    temp->value = 40;
    insertByMultiValue (&buf_head, &buf_tail, 4, 2,3, temp);

    temp = (record* )malloc( sizeof(record));
    temp->value = 70;
    insertByMultiValue (&buf_head, &buf_tail, 5, 3,8, temp);

    temp = (record* )malloc( sizeof(record));
    temp->value = 80;
    insertByMultiValue (&buf_head, &buf_tail, 6, 1,2, temp);

    temp = (record* )malloc( sizeof(record));
    temp->value = 90;
    insertByMultiValue (&buf_head, &buf_tail, 7, 1,7, temp);

    temp = (record* )malloc( sizeof(record));
    temp->value = 20;
    insertByMultiValue (&buf_head, &buf_tail, 2, 1,4, temp);


     temp = (record* )malloc( sizeof(record));
    temp->value = 20;
    insertByMultiValue (&buf_head, &buf_tail, 8, 1,0, temp);
    ddlist_print(buf_head, buf_tail);
    for (int i = 0 ; i < 2 ; i++){
        temp = getValueOneMax(&buf_head, &buf_tail );
        
        debug_print ("%llu\n",temp->value );
        free(temp);
    }
   
    
    
    ddlist_print(buf_head, buf_tail);
    ddlist_clear(&buf_head, &buf_tail);
    return 0;
}