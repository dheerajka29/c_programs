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

/*
 * Assume that key are always present
 */
node_st_ *
swap_nodes(node_st_ * node, int key1 , int key2) {
	node_st_ * temp_1 = node, *prev_1 = NULL;
	node_st_ * temp_2 = node, *prev_2 = NULL;
	node_st_ * next_1 = NULL, *next_2 = NULL;
	if(node == NULL)
	   return node;
	while(temp_1 != NULL && temp_1->data != key1) {
	      prev_1 = temp_1;
	      temp_1 = temp_1->next;
	}
	while(temp_2 != NULL && temp_2->data != key2) {
	      prev_2 = temp_2;
	      temp_2 = temp_2->next;
 	}
	if(temp_1 == NULL || 
	   temp_2 == NULL )
	   return node;
	next_1 = temp_1->next;
	next_2 = temp_2->next;
	if(prev_1 == NULL){
	   node = temp_2;
	   temp_2->next = next_1;
	   prev_2->next = temp_1;
	   temp_1->next = next_2;
	   return node;
	}
	if(prev_2 == NULL){
	   node = temp_1;
	   temp_1->next = next_2;
	   prev_1->next = temp_2;
	   temp_2->next = next_1;
	   return node;
	}
	prev_1->next = temp_2;
	temp_2->next = next_1;
	prev_2->next = temp_1;
	temp_1->next = next_2;
	return node;
}

int 
main(void) {
    node_st_ * head = NULL, *head2 = NULL;
    head = insert_linked_list(head,5);
    head = insert_linked_list(head,10);
    head = insert_linked_list(head,15);
    head = insert_linked_list(head,20);
    head = insert_linked_list(head,25);
    print_linked_list(head);
    head = swap_nodes(head,25,5);
    print_linked_list(head);
    destroy_linked_list(head);
    head = NULL;
    return 0;
}