// infix to postfix evaluation
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 20

void infix_to_postfix(char infix[], char postfix[]);
int precedence(char op);
int is_operator(char c);
int value(char postfix[]);
void push(int stack[], int *top, int item);
void pop(int stack[], int *top, int *item);

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

void push(int stack[], int *top, int item)
{
    if (*top >= SIZE - 1)
    {
        printf("stack is full\n");
        return;
    }

    stack[++(*top)] = item;
}

void pop(int stack[], int *top, int *item)
{
    if (*top < 0)
    {
        printf("stack is empty\n");
        *item = 0;
        return;
    }

    *item = stack[(*top)--];
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
    int stack[SIZE], top = -1;
    int i = 0, a, b, result;

    while (postfix[i] != '\0')
    {
        if (postfix[i] == ' ')
        {
            i++;
            continue;
        }

        if (isdigit((unsigned char)postfix[i]))
        {
            int num = 0;
            while (isdigit((unsigned char)postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(stack, &top, num);
        }
        else if (is_operator(postfix[i]))
        {
            if (top < 1)
            {
                printf("Invalid postfix expression\n");
                return 0;
            }

            pop(stack, &top, &a);
            pop(stack, &top, &b);

            switch (postfix[i])
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

            push(stack, &top, result);
            i++;
        }
        else
        {
            printf("Invalid postfix expression\n");
            return 0;
        }
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
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top != -1)
                top--;
        }
        else if (is_operator(infix[i]))
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1)
    {
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}
