#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//Structure to represent stack;
typedef struct stksturck{
    int top;
    unsigned cap;
    int *arr;
}Stack;

// function of creating Stack
Stack *createStack(unsigned cap){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->cap * sizeof(int));
    return stack;
}
//Check function wether it is Empty or not!
int isEmpty(Stack *stack){
    return stack->top == -1;
}


//Check function wether stack is full or not!!!
int isFull(Stack *stack){
    return stack->top == stack->cap - 1;
}

//POP operation 
int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("\nCannot pop from an empty stack!!");
        return 0;
    }
    return stack->arr[stack->top--];
}

//Push Operation
void push(Stack *stack, int item){
    if(isFull(stack)){
        printf("Stack is Full!");
        return;
    }
    stack->arr[++stack->top] = item;
    printf("%d id pushed in stack\n", item);
}

//Peek of Stack function
int peek(Stack *stack){
    if(isEmpty(stack)){
        return INT_MIN;
    }
    return stack->arr[stack->top];
}

void main(){
    Stack *stcak = createStack(10);
    push(stcak, 'a');
    push(stcak, 200);
    push(stcak, 300);
    push(stcak, 100);
    push(stcak, 200);
    push(stcak, 300);
    push(stcak, 100);
    push(stcak, 200);
    push(stcak, 's');
    

    printf("\nItem is poped %d", pop(stcak));
    printf("\nItem is poped %d", pop(stcak));
    printf("\nItem is poped %d", pop(stcak));
    printf("\nItem is poped %d", pop(stcak));
    printf("\nItem is poped %d", pop(stcak));
    printf("\nItem is poped %d", pop(stcak));
    printf("\nItem is poped %d", pop(stcak));
    printf("\nItem is poped %d", pop(stcak));
    printf("\nItem is poped %d", pop(stcak));
    
    printf("\nItem is poped %d", pop(stcak));
    printf("\nItem is poped %d", pop(stcak));
    
}