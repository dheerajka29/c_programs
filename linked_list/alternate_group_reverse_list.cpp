#include <bits/stdc++.h> 
using namespace std;

typedef struct node_st {
    int data;	
    struct node_st *next;	
} node_st_;	

node_st_ *
mem_allocator(int data){
    node_st_ * temp = (node_st_ *)malloc(sizeof(node_st_));
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
alternate_grp_reverse_linked_list(node_st_ * node, int key) {
    stack<node_st_ *> my_stack;
    node_st_ * prev = NULL;
    node_st_ * current = node;
    int k = 0;	
    if(node == NULL)
	return node;
    while(current != NULL) {
          while(current != NULL && k < key) {
                my_stack.push(current);
		current = current->next;
		k++;
	  }
	  while(my_stack.size() > 0){
		if(prev == NULL) {
	  	   prev = my_stack.top();
		   node = prev;
		} else {
	           prev->next = my_stack.top();
		   prev = prev->next;
		}  
		my_stack.pop();
	  }
	  k = 0;
	  while(current != NULL && k < key){
	        prev->next = current;
		current = current->next;
		prev = prev->next;
		k++;
	  }
    }
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
    head = insert_linked_list(head,30);
    print_linked_list(head);
    head = alternate_grp_reverse_linked_list(head,2);
    print_linked_list(head);
    destroy_linked_list(head);
    head = NULL;
    return 0;
}