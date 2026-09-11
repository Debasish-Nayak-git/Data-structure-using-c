// infix to postfix evaluation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void infix_to_postfix(char infix[], char postfix[]);
int precedence(char op);
int is_operator(char c);
int value(char postfix[]);
void Push(int stack[], int *top, int item);
void Pop(int stack[], int *top, int *item);
void Display(int stack[], int top);
void Peek(int stack[], int top);
int isFull(int top);
int isEmpty(int top);

int main(void)
{
    char infix[SIZE], postfix[SIZE];
    printf("Enter the infix expression\n");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);
    printf("Postfix expression is %s\n", postfix);

    printf("The evaluated result is: %d\n", value(postfix));
    return 0;
}

void Push(int stack[], int *top, int item)
{
    if (isFull(*top))
    {
        printf("stack is full\n");
        return;
    }
    stack[++(*top)] = item;
}

void Pop(int stack[], int *top, int *item)
{
    if (isEmpty(*top))
    {
        printf("stack is empty\n");
        *item = 0;
        return;
    }
    *item = stack[(*top)--];
}

void Display(int stack[], int top)
{
    if (isEmpty(top))
    {
        printf("stack is empty\n");
        return;
    }

    printf("Elements of stack:\n");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

void Peek(int stack[], int top)
{
    if (isEmpty(top))
        printf("stack is empty\n");
    else
        printf("\n peek element=%d\n", stack[top]);
}

int isFull(int top)
{
    return top == SIZE - 1;
}

int isEmpty(int top)
{
    return top == -1;
}

int precedence(char op)
{
    switch (op)
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
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int value(char postfix[])
{
    int stack[SIZE], top = -1, a, b, result;
    char *token = strtok(postfix, " ");

    while (token != NULL)
    {
        if (isdigit((unsigned char)token[0]))
        {
            Push(stack, &top, atoi(token));
        }
        else if (is_operator(token[0]))
        {
            if (top < 1)
            {
                printf("Invalid postfix expression\n");
                return 0;
            }

            Pop(stack, &top, &a);
            Pop(stack, &top, &b);

            switch (token[0])
            {
                case '+':
                    result = b + a;
                    break;
                case '-':
                    result = b - a;
                    break;
                case '*':
                    result = b * a;
                    break;
                case '/':
                    result = b / a;
                    break;
                default:
                    printf("Unknown operator\n");
                    return 0;
            }
            Push(stack, &top, result);
        }
        else
        {
            printf("Invalid postfix expression\n");
            return 0;
        }

        token = strtok(NULL, " ");
    }

    if (top != 0)
    {
        printf("Invalid postfix expression\n");
        return 0;
    }

    return stack[top];
}

void infix_to_postfix(char infix[], char postfix[])
{
    char stack[SIZE];
    int top = -1, j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)infix[i]))
        {
            if (j > 0 && postfix[j - 1] != ' ')
                postfix[j++] = ' ';

            while (isdigit((unsigned char)infix[i]))
            {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = ' ';
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top != -1)
                top--;
        }
        else if (is_operator(infix[i]))
        {
            if (j > 0 && postfix[j - 1] != ' ')
                postfix[j++] = ' ';

            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = ' ';
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1)
    {
        postfix[j++] = ' ';
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}