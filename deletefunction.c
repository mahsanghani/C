#include <stdio.h>
#include <stdlib.h>

typedef struct intnode_t{
  int value;
  struct intnode_t *next;
}intnode;

//creates a new node when the function is called

intnode *intnode_construct(int value, intnode *next){
  intnode *ptr;

  ptr = malloc(sizeof(intnode));
  ptr->value = value;
  ptr->next = next;

  return ptr;
}

//deletes a node when the function is called

intnode *delete_node(intnode *head){
  intnode *node_to_delete;

  node_to_delete = head;
  head = head->next;
  free(node_to_delete);

  return head;

}

int main() {
  intnode *head = NULL;

  head = intnode_construct(30, head);
  head = intnode_construct(20, head);
  head = intnode_construct(10, head);

  //deletes all the nodes one by one as the function is called each time
  head = delete_node(head);
  head = delete_node(head);
  head = delete_node(head);

  return 0;
}
