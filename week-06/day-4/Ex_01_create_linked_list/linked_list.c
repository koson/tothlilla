//
// Created by Lilla on 2019. 02. 28..
//
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node_t * linked_list_creator(int node_value)
{
  node_t * linked_list = (node_t*)malloc(sizeof(node_t));

  linked_list->value = node_value;
  linked_list->next = NULL;

  return linked_list;
}

void linked_list_dealloc(node_t * linked_list)
{
  node_t * node_to_free = linked_list; //create a temp node for deleting
  while(node_to_free != NULL){
    node_t * next_node = node_to_free->next;
    free(node_to_free);
    node_to_free = next_node;
  }
}
void linked_list_print(node_t * linked_list)
{
  node_t * it = linked_list;
  while (it != NULL){
    printf("%p: %d\n", it, it->value);
    it = it->next;
  }
}

void linked_list_push_back(node_t * linked_list, int new_node_value)
{
  node_t * new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = new_node_value;
  new_node->next = NULL;

  node_t * it = linked_list;
  while (it->next != NULL){
    it = it->next;
  }
  it->next = new_node;
}

void linked_list_push_front(node_t ** linked_list, int new_node_value)
{
  node_t * new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = new_node_value;
  new_node->next = *linked_list;
  *linked_list = new_node;
}

void linked_list_insert(node_t * linked_list_insert_after, int new_node_value)
{
  node_t * new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = new_node_value;
  new_node->next = linked_list_insert_after->next;
  linked_list_insert_after->next = new_node;
}

int linked_list_size(node_t * linked_list)
{
  node_t * temp = linked_list;
  int linked_link_size = 0;
  while (temp != NULL){
    linked_link_size++;
    temp = temp->next;
  }
  return linked_link_size;
}
int linked_list_empty(node_t * linked_list)
{
  return (linked_list == NULL) ? 1 : 0;
}

void linked_list_pop_front(node_t ** linked_list)
{
  node_t * temp = *linked_list;
  *linked_list = temp->next;
  free(temp);
}

int linked_list_remove(node_t ** linked_list, int searched_node_value)
{
  int removed_nodes = 0;
  node_t * previus = *linked_list;
  node_t * it = *linked_list;
  while(it != NULL) {
    if (it->value == searched_node_value){
      linked_list_pop_front(&it);
      previus->next = it;
      removed_nodes++;
    } else {
      previus = it;
      it = it->next;
    }
  }
  return removed_nodes;
}

node_t * linked_list_search(node_t * linked_list, int searched_node_value)
{
  node_t * node_memory_address = NULL;
  node_t * it = linked_list;
  while(it != NULL) {
    if (it->value != searched_node_value){
      node_memory_address = it;
      return node_memory_address;
    }
    it++;
  }
  return node_memory_address;
}