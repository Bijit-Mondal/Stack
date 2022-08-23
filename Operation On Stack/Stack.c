#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int st[MAX], tos=-1;
void push(int val){
    if(tos==MAX-1){
        printf("\nStack overflow\n");
    }else{
        st[++tos] = val;
    }
}
int pop(){
    int val;
    if(tos == -1){
        printf("\nStack underflow\n");
        return -1;
    }else{
        val = st[tos--];
        return val;
    }
}
int peek(){
    if(tos==-1){
        printf("\nStack underflow\n");
        return -1;
    }else{
        return st[tos];
    }
}
void display(){
    if(tos == -1){
        printf("\nStack is empty\n");
    }else{
        for(int i=tos;i>=0;i--){
            printf("\n%d",st[i]);
        }
    }
}
int main(){
    int data;
    int flag=1;
    while(flag){
        printf("Enter 1 for push element to the stack\nEnter 2 for pop element from the stack\nEnter 3 for seek\nEnter 4 for display all elements\n");
        int option;
        scanf("%d",&option);
        switch(option){
            case 1: 
                printf("Enter data to push ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                printf("poping data is %d",pop());
                printf("\nNew Stack is \n");
                display();
                break;
            case 3:
                if(peek()!=-1)
                    printf("Last element is %d\n",peek());
                break;
            case 4:
                printf("Displaying Element ");
                display();
                break;
            default:
                flag = 0;
                break;
        }
    }
    return 0;
}
