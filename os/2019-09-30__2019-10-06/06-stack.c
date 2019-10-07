//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: 10v
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: 06-stack.c
// FILE PURPOSE:
// Create a stack management library
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#define STACK_CAPACITY 100000

typedef struct {
    size_t size;
    size_t capacity;
    int *elements;
} stack;

void stack_init( stack *the_stack );
void stack_destroy( stack *the_stack );
int stack_empty( stack *the_stack );
void stack_push( stack *the_stack, int new);
int stack_top( stack *the_stack );
void stack_pop( stack *the_stack );
void stack_print( stack *the_stack );

int main() {
    stack the_stack;

    // Initializung the stack
    stack_init(&the_stack);

    // Checking if the stack is empty
    printf("%d\n", stack_empty(&the_stack));

    // Pushing 5 items to the stack
    for (int i = 0; i < the_stack.capacity / 2; i++) {
        stack_push(&the_stack, i);
    }

    // Prints the stack
    stack_print(&the_stack);

    // Printing the top element of the stack
    printf("%d\n", stack_top( &the_stack ));

    // Popping the top element of the stack
    stack_pop(&the_stack);

    // Printing the top element of the stack
    printf("%d\n", stack_top( &the_stack ));

    // Destroing the stack
    stack_destroy(&the_stack);

    return 0;
}

void stack_init( stack *the_stack ) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_init
    // Initializes the stack
    // PARAMETERS:
    // *the_stack - pointer to the stack address
    //------------------------------------------------------------------------
    
    the_stack->size = 0;
    the_stack->capacity = STACK_CAPACITY;
    the_stack->elements = NULL;
}

void stack_destroy( stack *the_stack ) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_destroy
    // Destroys the stack
    // PARAMETERS:
    // *the_stack - pointer to the stack address
    //------------------------------------------------------------------------

    free(the_stack->elements);
    the_stack = NULL;
}

int stack_empty( stack *the_stack ) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_destroy
    // Returns if the stack has any elements within
    // PARAMETERS:
    // *the_stack - pointer to the stack address
    //------------------------------------------------------------------------

    if(the_stack->size) return 0;
    return 1;
}

void stack_push( stack *the_stack, int new ) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_push
    // Pushes a new element to the stack
    // PARAMETERS:
    // *the_stack - pointer to the stack address
    // new - the element to be added to the stack
    //------------------------------------------------------------------------

    if(the_stack->size + 1 > the_stack->capacity) {
        fprintf(stderr, "Error! The stack is full...\n");
        return;
    }

    the_stack->elements = (int *)realloc(the_stack->elements, sizeof(int) * ++the_stack->size);
    the_stack->elements[the_stack->size - 1] = new;
}

int stack_top( stack *the_stack ) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_push
    // Returns the top element of the stack
    // PARAMETERS:
    // *the_stack - pointer to the stack address
    //------------------------------------------------------------------------

    return the_stack->elements[the_stack->size - 1];
}

void stack_pop( stack *the_stack ) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_push
    // Pops the top element from the stack
    // PARAMETERS:
    // *the_stack - pointer to the stack address
    //------------------------------------------------------------------------

    the_stack->elements = (int *)realloc(the_stack->elements, sizeof(int) * --the_stack->size);
}

void stack_print( stack *the_stack ) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_push
    // Prints the stack's elements
    // PARAMETERS:
    // *the_stack - pointer to the stack address
    //------------------------------------------------------------------------

    for (int i = 0; i < the_stack->size; i++) {
        printf("%d ", the_stack->elements[i]);
    }
    printf("\n");
}