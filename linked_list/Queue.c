//linked ilst implementation
#include <stdio.h>
#include <stdlib.h>
//creating the structure of the node
struct Node{
    int data;
    struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;

//functions for required operations
struct Node* create_node(int input_data);
void traverse();
void enqueue(int input_data);
void dequeue();
void search();
void peek_rear();
void peek_front();
void menu();

int main()
{  
    while(1){
        menu();
        int ch,i,pos;
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Value to input:");
                scanf("%d",&i);
                enqueue(i);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                search();
                break;
            case 5:
                peek_front();
                break;
            case 6:
                peek_rear();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
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

void traverse(){
    struct Node *temp=front;
    if (temp==NULL){
        printf("List is empty\n");
        return;
    }
    printf("\nElements of the Queue:\n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void enqueue(int input_data){
    struct Node *new_node=create_node(input_data);
    if(new_node==NULL) return;
    if(rear==NULL)
        front=new_node;
    else
        rear->next=new_node;
    rear=new_node;
}
void dequeue(){
    struct Node *deleted=front;
    if (front==NULL){
        printf("List is empty\n");
        return;
    }
    if (front->next==NULL)
        rear=NULL;
    front=front->next;
    printf("Deleted element is %d from begin\n",deleted->data);
    free(deleted);
}

void search(){
    int target;
    printf("enter the element to search");
    scanf("%d",&target);
    if(front==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp=front;
    int i=1;
    while(temp!=NULL){
        if(temp->data==target){
            printf("%d found at %d position in the list\n",target,i);
            return;
        }
        temp=temp->next;
        i++;
    }
    printf("Element %d not found in the list\n",target);
}
void menu(){
    printf("1.Insert\n");
    printf("2.Delete \n");
    printf("3.Display\n");
    printf("4.Search\n");
    printf("5.peek front\n");
    printf("6.peek rear\n");
    printf("7.Exit\n");
}
void peek_front(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n",front->data);
}
void peek_rear(){
    if(rear==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Rear element is %d\n",rear->data);
}