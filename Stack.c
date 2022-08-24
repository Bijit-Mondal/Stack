#include<stdio.h>
#include "Stack.h"
int main(){
    int data,flag=1;
    MaxSize();
    while(flag){
        int option;
        printf("Enter 1 for push element\nEnter 2 for pop Element\nEnter 3 for Peek\nEnter 4 for Display\nEnter -1 for quit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter a data: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                if(peek()!=-1)
                    printf("The data in tos is %d\n",peek());
                break;
            case 4:
                display();
                break;
            case -1:
                flag=0;
                break;
            default:
                printf("Yupp! Focus Dear\n");
        }
    }
    return 0;
}
