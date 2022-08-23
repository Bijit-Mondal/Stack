#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int data;
    struct stack *next;
}stack;
stack *tos = NULL;
void push(int data){
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->data = data;
    if(!tos){
        newStack->next = NULL;
        tos = newStack;
    }else{
        newStack->next = tos;
        tos = newStack;
    }
}
void pop(){
    stack *RIPstack = tos;
    if(!tos)
        printf("Stack Underflow\n");
    else{
        tos = tos->next;
        printf("The value being deleted: %d\n", RIPstack->data);
        free(RIPstack);
    }
}
int peek(){
    if(!tos)
        return -1;
    else
        return tos->data;
}
void display(){
    stack *current = tos;
    if(!tos)
        printf("Stack is Empty\n");
    else{
        while(current!=NULL){
            printf("%d\n",current->data);
            current = current->next;
        }
    }
}
