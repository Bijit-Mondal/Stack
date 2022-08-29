#include<stdio.h>
#include<string.h>
#define MAX 50
char stack[MAX];
int tos = -1;
void push(char symbol){
    if(tos>MAX){
        printf("Stack overflow\n");
    }else{
        stack[++tos] = symbol;
    }
}
char pop(){
    char element;
    if(tos==-1){
        printf("Stack underflow\n");
    }else{
        element = stack[tos--];
    }
    return element;
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
    }
    return -1;
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
                while(precedence(stack[tos])>=precedence(symbol)){
                    temp = pop();
                    postfix[index++]=temp;
                }
                push(symbol);
                break;
            default:
                postfix[index++]=symbol;
                break;
        }
        i++;
    }
    while(tos>=0){
        temp = pop();
        postfix[index++]=temp;
    }
    postfix[++index]='\0';
    printf("%s",postfix);
}
int main(){
    char infinix[50];
    printf("\nEnter the infinix expression ");
    scanf("%[^\n]%*c",infinix);
    PostfixConversion(infinix);
    return 0;
}

