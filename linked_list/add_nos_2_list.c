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
add_linked_list(node_st_ * list_1,
		node_st_ * list_2) {
    if(list_1 == NULL ||
       list_2 == NULL)
	return NULL;
    int carry = 0;
    int sum = 0;
    node_st_ * temp = NULL , *iter = NULL;
    while(list_1 != NULL ||
	  list_2 != NULL) {
          sum = (list_1 ? list_1->data : 0) +
		(list_2 ? list_2->data : 0) +
		carry;
	  carry = 0;
	  if(sum/10) {
	     sum = sum%10;
	     carry = 1;
	  }
	  if(list_1 != NULL)
	     list_1 = list_1->next;
	  if(list_2 != NULL)
	     list_2 = list_2->next;
	  if(temp == NULL){
	     temp = mem_allocator(sum);
	     iter = temp;
	  }
	  else {
	     iter->next = mem_allocator(sum);
	     iter = iter->next;
	  }
    }
    if(carry > 0) {
       if(iter != NULL)
	  iter->next = mem_allocator(carry);
    }
    return temp;
}

int 
main(void) {
    node_st_ * head = NULL;
    node_st_ * head2 = NULL;
    head = insert_linked_list(head,7);
    head = insert_linked_list(head,5);
    head = insert_linked_list(head,9);
    head = insert_linked_list(head,4);
    head = insert_linked_list(head,6);
    head2 = insert_linked_list(head2,8);
    head2 = insert_linked_list(head2,4);
    head2 = insert_linked_list(head2,3);
    print_linked_list(head);
    print_linked_list(head2);
    head = add_linked_list(head,head2);
    print_linked_list(head);
    destroy_linked_list(head);
    return 0;
}