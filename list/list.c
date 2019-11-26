// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include<stdlib.h>
#include "list.h"

list_t *list_alloc() { 
    list_t *newPtr = (list_t*) malloc(sizeof(list_t));
  newPtr->head = NULL;
  return newPtr;
   }
void list_free(list_t *l) {
    node_t* tmp;

   while (l->head != NULL)
    {
       tmp = l->head;
       l->head = l->head->next;
       free(tmp);
    }
  printf("list is deallocated properly!\n");
}

void list_print(list_t *l) {
    node_t *current = l->head;
    printf("running list_print function\n");
  while(current!=NULL)
  {
    printf("%d", current->value);
    printf(" ");
    current = current->next;
  }
  printf("\n");  
}
int list_length(list_t *l) {  
  node_t *current = l->head;
  int counter = 0;
  while(current !=NULL)
  {
    counter++;
    current= current->next;
  }
    printf("The length of the linked list is: ");
    printf("%d",counter);
    printf(" \n");
  return counter; 
}

void list_add_to_back(list_t *l, elem value) {
  node_t *current= l->head;
  node_t *backNode = (node_t*) malloc(sizeof(node_t));
  backNode->value = value;
  backNode->next = NULL;
  if(current==NULL)
  {
	  current= backNode;
	  return;
  }
  while(current->next !=NULL)
  {
      current = current->next;
  }
   current->next= backNode;
   printf("Number added to the back of the list\n");
}
void list_add_to_front(list_t *l, elem value) {
    node_t *current = l->head;
  node_t *new_front_node = (node_t*) malloc(sizeof(node_t));
  new_front_node->value= value;
  new_front_node->next=l->head;
  l->head= new_front_node;
  printf(" New Number added to the front\n");
}
void list_add_at_index(list_t *l, elem value, int index) {
    node_t *current = l->head;
  node_t *addedNode= (node_t*) malloc(sizeof(node_t));
  addedNode->value=value;
  int i;
  for( i = 0; i<index; i++)
  {
    current= current->next;
  }
  addedNode->next= current->next;
  current->next = addedNode;
    printf("New number added to the index specified\n");
  return;
}

elem list_remove_from_back(list_t *l) { 
	elem node_value;
	node_t *current = l->head;
    node_t *previous = l->head;
	while(current->next !=NULL)
        current = current->next;
    while(previous->next->next != NULL)
        previous= previous->next;
	node_value= current->value;
	free(current);
    previous->next= NULL;
   	printf("Freed the last element which was: ");
	printf("%d",node_value);
	printf("\n");
	return node_value;
}
elem list_remove_from_front(list_t *l) { 
    elem node_value;
    node_t *current = l->head;
    node_value= current ->value;
    l->head = current->next;
    free(current);
    printf("Freed the first element which was: ");
	printf("%d",node_value);
	printf("\n");
  return node_value;
}
elem list_remove_at_index(list_t *l, int index) {
    elem node_value;
    node_t *current = l->head;
    node_t *tempNode = l->head;
    int i =0;
    for(i; i < index; i++){
        current = current->next;
    }
    int j =0;
    for (j; j < index - 1; j++){
        tempNode = tempNode->next;
    }
    node_value = current->value;
    tempNode->next = current->next;
    free(current);
    printf("Freed the element @ index ");
    printf("%d",index);
    printf(" and the value is: ");
	printf("%d",node_value);
	printf("\n");
    return node_value; 
}


bool list_is_in(list_t *l, elem value) { 
    node_t *current = l->head;
    while(current != NULL){
        if(current->value == value){
            printf("The value is in the linked list!\n");
            return true;
        }
        else{
            current = current->next;
        }
    }
    return false;
}
elem list_get_elem_at(list_t *l, int index) { 
    node_t *current = l->head;
    int i = 0;
    for(i; i <index; i++){
        current = current->next;
    }
    printf("This is the value at that index: ");
    printf("%d",current->value);
    printf("\n");
    return current->value;  
}
int list_get_index_of(list_t *l, elem value) { 
    node_t *current = l->head;
    int index = 0;
    while(current != NULL){
        if(current->value == value){
            printf("The value has been found in the linked list!\n");
            return index;
        }
        else{
            current = current-> next;
            index++;
        }
    }
   printf("Value is not in linked list :( ");
   return -1; 
}