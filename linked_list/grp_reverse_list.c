/*
 * Reverse a Linked List in groups of given size | Set 1
   Given a linked list, write a function to reverse every k nodes (where k is an input to the function).
   Example:
   Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
   Output:  3->2->1->6->5->4->8->7->NULL. 

   Inputs:   1->2->3->4->5->6->7->8->NULL and k = 5
   Output:  5->4->3->2->1->8->7->6->NULL. 
   https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
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
grp_reverse_linked_list(node_st_ * head, int key) {
    int count = 0;
    node_st_ * temp = NULL;
    node_st_ * prev = NULL;
    node_st_ * forw = head;
    if(head == NULL)
       return head;
    if(head->next == NULL)
       return head;
    while(forw != NULL && count < key) {
          temp = forw->next;
	  forw->next = prev;
	  prev = forw;
	  forw = temp;
	  count++;
    }	
    head->next = grp_reverse_linked_list(forw,key);
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
    print_linked_list(head);
    head = grp_reverse_linked_list(head,2);
    print_linked_list(head);
    destroy_linked_list(head);
    head = NULL;
    return 0;
}	
