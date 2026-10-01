//linked ilst implementation
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* create_node(int );
void Push(int);
void Pop();
void Display();
void Peek();
int Menu();

struct Node *top=NULL;

int main()
{int ch,item;
while(1)
{
ch=Menu();
switch(ch){
    case 1:
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        Push(item);
        break;
    case 2:
        Pop();
        break;
    case 3:
        Display();
        break;
    case 4:
        Peek();
        break;
    case 5:
        return 0;
    default:
        printf("invalid choice\n");
    }
}
return 0;
}

int Menu()
{int ch;
printf("\n1.Push\n");
printf("2.Pop\n");
printf("3.Display\n");
printf("4.Peek\n");
printf("5.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
return ch;
}
struct Node* create_node(int input_data)
{ struct Node *node=(struct Node *)malloc(sizeof(struct Node));
  if(node==NULL){
      printf("Memory allocation failed\n");
      return NULL;
  }  
  node->data=input_data;
  node->next=NULL;
  return node;  
}

void Push(int item){
    struct Node *new_node=create_node(item);
    if(new_node==NULL){
        return;
    }
    new_node->next=top;
    top=new_node;
}

void Pop(){
    if(top==NULL){
        printf("stack is empty\n");
        return;
    }
    struct Node *temp=top;
    int item=temp->data;
    top=top->next;
    free(temp);
    printf("Deleted element:%d\n",item);
}

void Display(){
    struct Node *temp=top;
    if (temp==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("\nElements of stack:\n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Peek(){
    if(top==NULL){
        printf("stack is empty\n");
        return;
    }
    printf("\n peek element=%d\n",top->data);
}