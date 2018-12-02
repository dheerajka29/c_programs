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

bool
are_list_identical(node_st_ * list1,
		   node_st_ * list2) {
	if(list1 == NULL && list2 == NULL)
	   return true;
	if (list1 == NULL)
	    return false;
	if (list2 == NULL)
	    return false;
	if(list1->data != list2->data)
	   return false;
	else
	   return are_list_identical(list1->next,list2->next);
}

int 
main(void) {
    node_st_ * head = NULL,*head1 = NULL;
    head = insert_linked_list(head,5);
    head = insert_linked_list(head,10);
    head = insert_linked_list(head,15);
    head = insert_linked_list(head,20);
    head = insert_linked_list(head,25);
    head1 = insert_linked_list(head,5);
    head1 = insert_linked_list(head,10);
    head1 = insert_linked_list(head,15);
    head1 = insert_linked_list(head,20);
    head1 = insert_linked_list(head,25);
    print_linked_list(head);
    printf("%s\n",are_list_identical(head,head1)?"Identical":"Non Identical");
    destroy_linked_list(head);
    return 0;
}