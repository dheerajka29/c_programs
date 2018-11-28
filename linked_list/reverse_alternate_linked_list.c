/*
 * Reverse alternate K nodes in a Singly Linked List
 * Given a linked list, write a function to reverse every alternate k nodes 
 * (where k is an input to the function) in an efficient way. Give the complexity of your algorithm.
 * Example:
 * Inputs:   1->2->3->4->5->6->7->8->9->NULL and k = 3
 * Output:   3->2->1->4->5->6->9->8->7->NULL.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node_st {
    int data;	
    struct node_st *next;	
} node_st_;	

node_st_ *
mem_allocator(int data){
    node_st_ * temp = malloc(sizeof(node_st_));
    if(temp == NULL) {
       return NULL;
    } else {
      temp->data = data;
      temp->next = NULL; 
    }	    
    return temp;
}	

node_st_ *
insert_linked_list(node_st_ * head, int data) {
    node_st_ * temp = head;	
    if (temp == NULL) {
        temp = mem_allocator(data);
	head = temp;
    } else {
        while(temp->next != NULL)
	      temp = temp->next;
	temp->next = mem_allocator(data);      	      
    }	    
    return head;
}	

void
print_linked_list(node_st_ * head){
    while(head) {
          printf("%d->",head->data);
	  head = head->next;
    }
    printf("\n");    
}	

void
destroy_linked_list(node_st_ * head) {
    if(head){
          destroy_linked_list(head->next);
	  free(head);
    }	    
}

node_st_ *
node_traverse_frwd(node_st_ * temp, int key){
    node_st_ * prev = temp;	
    while(key && temp && temp->next != NULL){
          key--;
	  prev = temp;
	  temp = temp->next;
    }
    return prev;    
}	

node_st_ * 
reverse_linked_list(node_st_ * head, int key) {
    node_st_ * prev = NULL;
    node_st_ * forw = head;
    node_st_ * temp = NULL;
    int count = 0;
    if(head == NULL || head->next == NULL)
       return head;
    while( forw != NULL && 
	   count < key ) {
           temp = forw->next;
	   forw->next = prev;
	   prev = forw;
	   forw = temp;
	   count++;
    }	    
    count = 0;
    head->next = forw;
    temp = node_traverse_frwd(forw,key);
    if(temp != NULL)
       temp->next = reverse_linked_list(temp->next,key);
    return prev;    
}	

int 
main(void) {
    node_st_ * head = NULL;
    head = insert_linked_list(head,1);
    head = insert_linked_list(head,2);
    head = insert_linked_list(head,3);
    head = insert_linked_list(head,4);
    head = insert_linked_list(head,5);
    head = insert_linked_list(head,6);
    head = insert_linked_list(head,7);
    head = insert_linked_list(head,8);
    head = insert_linked_list(head,9);
    head = insert_linked_list(head,10);
    print_linked_list(head);
    head = reverse_linked_list(head,2);
    print_linked_list(head);
    destroy_linked_list(head);
    head = NULL;
    return 0;
}	
