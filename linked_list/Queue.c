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
void insert(int input_data);
void delete();
void search();
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
                insert(i);
                break;
            case 2:
                printf("Value to input:");
                scanf("%d",&i);
                delete(i);
                break;
            case 3:
                traverse();
                break;
            case 4:
                search();
                break;
            case 5:
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

void insert(int input_data){
    struct Node *new_node=create_node(input_data);
    if(new_node==NULL) return;
    if(rear==NULL)
        front=new_node;
    else
        rear->next=new_node;
    rear=new_node;
}
void delete(){
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
    int i=0;
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
    printf("5.Exit\n");
}