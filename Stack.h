#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int data;
    struct stack *next;
}stack;
stack *tos = NULL;
int size=0;
int MAX_SIZE;
void MaxSize(){
    printf("Enter the maximum size ");
    scanf("%d",&MAX_SIZE);
}
void push(int data){
    if(size<MAX_SIZE){ 
        stack *newStack = (stack *)malloc(sizeof(stack));
        newStack->data = data;
        if(!tos){
            newStack->next = NULL;
            tos = newStack;
            ++size;
        }else{
            newStack->next = tos;
            tos = newStack;
            ++size;
        }
    }else{
        printf("Stack Overflow\n");
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
        --size;
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
        while(current){
            printf("%d\n",current->data);
            current = current->next;
        }
    }
}