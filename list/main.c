#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
 
  list_t *linked_list = list_alloc(); 
  printf("List properly allocated!\n");
  list_free(linked_list);
  list_t* real_Linked_list =list_alloc();
  int i;
  for (i =0; i<10;i++)
  {
    list_add_to_front(real_Linked_list, i);
  }
  list_print(real_Linked_list);
  list_add_to_back(real_Linked_list, 9);
  list_print(real_Linked_list);
  list_add_at_index(real_Linked_list,8,2);
  list_print(real_Linked_list);
  list_length(real_Linked_list);
  list_remove_from_back(real_Linked_list);
  list_print(real_Linked_list);
  list_remove_from_front(real_Linked_list);
  list_print(real_Linked_list);
  list_remove_at_index(real_Linked_list, 4);
  list_print(real_Linked_list);
  list_is_in(real_Linked_list, 0);
  list_is_in(real_Linked_list, 5);
  list_get_elem_at(real_Linked_list,3);
  list_get_index_of(real_Linked_list, 2);
  list_print(real_Linked_list);
  return 0;
}