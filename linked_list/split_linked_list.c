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

void 
helper_func(node_st_ * temp1,
	    node_st_ * temp2) {
     if(temp1 == NULL || temp2 == NULL)
	return;
     temp1->next = temp2->next;
     if(temp2->next != NULL)
	temp2->next = temp2->next->next;
     helper_func(temp1->next,temp2->next);
}

void
split_alternate_nodes(node_st_* node,
		     node_st_ ** node_1,
		     node_st_ ** node_2) {
	if(node == NULL)
	   return;
	if(node->next == NULL)
	   return;
	*node_1 = node;	
	*node_2 = node->next;
	helper_func(*node_1,*node_2);
}

int 
main(void) {
    node_st_ * head = NULL,*head1 = NULL, *head2 = NULL;
    head = insert_linked_list(head,5);
    head = insert_linked_list(head,10);
    head = insert_linked_list(head,15);
    head = insert_linked_list(head,20);
    head = insert_linked_list(head,25);
    print_linked_list(head);
    split_alternate_nodes(head,&head1,&head2);
    print_linked_list(head1);
    print_linked_list(head2);
    destroy_linked_list(head1);
    destroy_linked_list(head2);
    head1 = NULL;
    head2 = NULL;
    return 0;
}