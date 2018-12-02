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
remove_duplicates(node_st_ * node) {
    if(node == NULL)
       return node;
    if(node->next == NULL)
       return node;
    node_st_ * temp = node;
    node_st_ * free_node = NULL;
    while(temp != NULL && temp->next != NULL) {
          if(temp->data == temp->next->data){
             free_node = temp->next;
             temp->next = temp->next->next;
	     free(free_node);
	  } else {
 	     temp= temp->next;
	  }
    }
    return node;
}

int 
main(void) {
    node_st_ * head = NULL, *head2 = NULL;
    head = insert_linked_list(head,5);
    head = insert_linked_list(head,10);
    head = insert_linked_list(head,10);
    head = insert_linked_list(head,15);
    head = insert_linked_list(head,15);
    print_linked_list(head);
    head = remove_duplicates(head); 
    print_linked_list(head);
    destroy_linked_list(head);
    head = NULL;
    return 0;
}