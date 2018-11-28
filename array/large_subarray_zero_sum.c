/*
 * https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/
 * Find the length of largest subarray with 0 sum
 * Given an array of integers, find length of the largest subarray with sum equals to 0.
 * Examples :

   Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
   Output: 5
   The largest subarray with 0 sum is -2, 2, -8, 1, 7

   Input: arr[] = {1, 2, 3}
   Output: 0
   There is no subarray with 0 sum

   Input: arr[] = {1, 0, 3}
   Output: 1
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct linked_list_st {
    struct linked_list_st * next;
    int data;
    int index;
    bool is_seen;
} linked_list_;

linked_list_ * 
list_insert(linked_list_* node, int sum , int index) {
    linked_list_ * temp = NULL;
    linked_list_ * temp_head = node;
    temp = malloc(sizeof(linked_list_));
    temp->next = NULL;
    temp->data = sum;
    temp->index = index;
    temp->is_seen = false;
    if (node == NULL) {
        node = temp;
    }else {
        while(temp_head->next != NULL ){
	      temp_head = temp_head->next;
	}
        temp_head->next = temp;
    }
    return node;    
}

linked_list_ * 
list_search(linked_list_ * head, int sum) {
    linked_list_ * temp = head;	
    while(temp != NULL) {
          if(temp->data == sum) {
	        break;
          }
          temp= temp->next;	     
    }
    return temp;    
}	

int 
main (void) {
    //int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int arr[] = {1,0,3};
    int len = sizeof(arr)/sizeof(int);
    int iter = 0;
    int sum = 0;
    int max_len = 0;
    linked_list_ * head = NULL, *temp;
    for(iter;iter < len; iter++) {
	sum += arr[iter];    
        if((temp = list_search(head,sum)) != NULL) {
	   max_len = max_len > (iter - temp->index) ? max_len:(iter- temp->index);
	} else {
	  head = list_insert(head,sum,iter);
	}	
    }
    printf("%d\n",max_len);
    return 0;
}	
