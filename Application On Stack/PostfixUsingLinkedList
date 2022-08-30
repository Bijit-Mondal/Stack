#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #define MAX 50
// char stack[MAX];
typedef struct stack{
    char symbol;
    struct stack *next;
}stack;
stack *tos = NULL;
void push(char symbol){
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->symbol = symbol;
    if (!tos){
        newStack->next = NULL;
        tos = newStack;
    }
    else{
        newStack->next = tos;
        tos = newStack;
    }
}
char pop(){
    char element;
    stack *RIPstack = tos;
    if (!tos)
        printf("Stack Underflow\n");
    else{
        tos = tos->next;
        element = RIPstack->symbol;
        free(RIPstack);
    }
    return element;
}
char peek(){
    stack *TOstack = tos;
    if (!tos)
        return '\0';
    else
        return TOstack->symbol;
}
int precedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}
void PostfixConversion(char ch[]){
    int i=0,size,index=0;
    char postfix[50];
    char symbol,temp;
    size = strlen(ch);
    while(i<size){
        symbol = ch[i];
        switch(symbol){
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(precedence(peek())>=precedence(symbol)){
                    temp = pop();
                    postfix[index++]=temp;
                }
                push(symbol);
                break;
            case '(':
                push(symbol);
                break;
            case ')':
                while(1){
                    if(peek()!='('){
                        temp = pop();
                        postfix[index++]=temp;
                    }
                    else{
                        pop();
                        break;
                    }
                }
                break;
            default:
                postfix[index++]=symbol;
                break;
        }
        i++;
    }
    while(tos){
        temp = pop();
        postfix[index++]=temp;
    }
    postfix[++index]='\0';
    printf("%s\n",postfix);
}
int main(){
    char infinix[50];
    printf("Enter the infinix expression : ");
    scanf("%[^\n]%*c",infinix);
    PostfixConversion(infinix);
    return 0;
}
