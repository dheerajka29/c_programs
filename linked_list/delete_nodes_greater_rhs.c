#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
list_after_rhs_modif(node_st_ * node) {
    if(node == NULL)
	return node;
    if(node->next == NULL)
	return node;
    node_st_ * temp = node->next;
    node_st_ * prev = node;
    node_st_ * prev_prev = NULL;
    while(temp != NULL) {
         if(prev->data < temp->data){
	    if(prev == node) {
		free(prev);
		node = temp;
		prev = temp;
	    } else {
	       prev_prev->next = temp;
	       free(prev);
	       prev = temp ;	
	    }	
	 } else {
	   prev_prev = prev;
	   prev = temp;
	 }
	 temp = temp->next;
    }
    return node;
}

int 
main(void) {
    node_st_ * head = NULL;
    head = insert_linked_list(head,14);
    head = insert_linked_list(head,7);
    head = insert_linked_list(head,9);
    head = insert_linked_list(head,18);
    head = insert_linked_list(head,11);
    head = insert_linked_list(head,15);
    head = insert_linked_list(head,10);
    head = insert_linked_list(head,12);
    print_linked_list(head);
    head = list_after_rhs_modif(head);
    print_linked_list(head);
    destroy_linked_list(head);
    return 0;
}