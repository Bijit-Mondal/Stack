#include<stdio.h>
int stk[10];
int tos=-1;
int pop(){
    if(tos==-1)
        return -1;
    else
        return stk[tos--];
}
void push(int data){
    stk[++tos] = data;
}
int main(){
    int val,i;
    int arr[10];
    printf("Enter 10 elements in the array: ");
    for(i=0; i<10; i++){
        scanf("%d",&arr[i]);
        push(arr[i]);
    }
    for(i=0; i<10; i++){
        val = pop();
        arr[i] = val;
    }
    printf("\nThe reverse array is: ");
    for(i=0; i<10; i++){
        printf("\n%d",arr[i]);
    }
    return 0;
}

