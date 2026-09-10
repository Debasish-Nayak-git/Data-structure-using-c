//infix to postfix conversion
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void infix_to_postfix(char infix[], char postfix[]);
int precedence(char operator);
int is_operator(char c);

int main()
{
    char infix[20], postfix[20];
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    infix_to_postfix(infix,postfix);
    printf("Postfix expression is %s\n",postfix);
    return 0;
}

void infix_to_postfix(char infix[], char postfix[])
{
    char stack[20];
    int top=-1, j=0;
    for(int i=0; infix[i]!='\0'; i++)
    {
        if(isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if(infix[i]=='(')
        {
            stack[++top] = infix[i];
        }
        else if(infix[i]==')')
        {
            while(top!=-1 && stack[top]!='(')
            {
                postfix[j++] = stack[top--];
            }
            top--; // pop '(' from stack
        }
        else if(is_operator(infix[i]))
        {
            while(top!=-1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while(top!=-1)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0'; // null terminate the postfix expression
}
int precedence(char operator)
{
    switch(operator)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
int is_operator(char c)
{
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}