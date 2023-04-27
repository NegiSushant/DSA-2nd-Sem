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
    return stack;
}

//is Full operations
int isFull(Stack *stack){
    return stack->top == stack->cap - 1;

}

//is Empty function
int isEmpty(Stack *stack){
    return stack->top == -1;
}

//pop function
void push(Stack *stack, int item){
    if(isEmpty(stack)){
        return;
    }
    stack->arr[++stack->top] = item;
    printf("%d id pushed in stack\n", item);
}

//push function
Stack pop(Stack *stack, int item){
    if(isFull(stack)){
        return;
    }
    stack = stack->arr[--stack->top];
    return stack;
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
}