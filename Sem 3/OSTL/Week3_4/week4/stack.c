#include "stack_header.h"
#define MAX 10

void main()
{
    stack st;
    st.top = 0;
    printf("Pushing elements into stack\n");
    
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    printf("Stack after pushing\n");
    display(&st);
    
    
    printf("Popping element\n");
    printf("Element popped: %d\n", pop(&st));
    printf("Stack after popping\n");
    display(&st);
}