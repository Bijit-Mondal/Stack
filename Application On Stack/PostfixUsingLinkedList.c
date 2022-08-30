#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct stack{
    char symbol;
    struct stack *next;
}stack;
stack *tos = NULL;
int paranthesis = 0;
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
char* PostfixConversion(char* ch){
    int i=0,size,index=0;
    size = strlen(ch);
    char* postfix=malloc(sizeof(char)*size);
    char symbol,temp;
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
                paranthesis++;
                break;
            case ')':
                if(paranthesis!=0){
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
                    paranthesis--;
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
    if(paranthesis == 0)
        return postfix;
    else
        return "Your Equation is seriously damaged!";
}
char* PrefixConversion(char* ch){
    int i=0,size,index=0;
    size = strlen(ch);
    char* postfix=malloc(sizeof(char)*size);
    char symbol,temp;
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
            case ')':
                push(symbol);
                paranthesis++;
                break;
            case '(':
                if(paranthesis!=0){
                    while(1){
                        if(peek()!=')'){
                            temp = pop();
                            postfix[index++]=temp;
                        }
                        else{
                            pop();
                            break;
                        }
                    }
                    paranthesis--;
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
    if(paranthesis == 0)
        return postfix;
    else
        return "Your Equation is seriously damaged!";
        
}

char* rev(char str[]){
    int i,j;
    int length = strlen(str);
    char *rev = (char*)malloc(sizeof(char)*length);
    for(i=(length-1),j=0;i>=0;i--,j++){
        rev[j] = str[i];
    }
    rev[j] = '\0';
    return rev;
}
int main(){
    char* infinix=(char*)malloc(sizeof(char));
    printf("Enter the infinix expression : ");
    scanf("%[^\n]%*c",infinix);
    printf("Postfix : %s\n",PostfixConversion(infinix));
    printf("Prefix : %s\n",rev(PrefixConversion(rev(infinix))));
    return 0;
}
