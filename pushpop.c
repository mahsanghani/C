#include <stdio.h>
#include <stdlib.h>

typedef struct intnode {
    int value;
    struct intnode *next;
} intnode_t;

typedef struct {
    intnode_t *top;  // points to the node at the head of the stack's
                     // linked list; NULL if the stack is empty
    int size;        // # of items in the stack
                     // (# of nodes in the linked list)
} intstack_t;

intnode_t *intnode_construct(int value, intnode_t * next)
{
    intnode_t *ptr;

    ptr = malloc(sizeof(intnode_t));
    assert(ptr != NULL);
    ptr->value = value;
    ptr->next = next;
    return ptr;
}

/* Return a pointer to a new, empty stack. */
intstack_t *intstack_construct(void)
{
    intstack_t *ptr;

    ptr = malloc(sizeof(intstack_t));
    // assert(ptr != NULL);
    ptr->top = NULL;
    ptr->size = 0;
    return ptr;
}

/* Push value on the top of the stack.
 * Terminate via assert if stack is NULL.
 */
void intstack_push(intstack_t *stack, int value)
{
    assert(stack != NULL);

    stack->top = intnode_construct(value, stack->top);
    stack->size += 1;
}

/* Remove and return the value at the top of the stack.
 * Terminate via assert if stack is NULL or of the
 * stack is empty.
 */
int intstack_pop(intstack_t *stack)
{
    assert(stack != NULL);

    int popped;
    intnode_t *node_to_delete;

    popped = stack->top->value;
    node_to_delete = stack->top;
    stack->top = stack->top->next;
    free(node_to_delete);
    stack->size -= 1;

    return popped;
}

int main(void)
{
    intstack_t *my_stack;
    int item;

    my_stack = intstack_construct();

    intstack_push(my_stack, 30);
    intstack_push(my_stack, 20);
    intstack_push(my_stack, 10);


    item = intstack_pop(my_stack);
    item = intstack_pop(my_stack);
    item = intstack_pop(my_stack);

    return 0;
}
