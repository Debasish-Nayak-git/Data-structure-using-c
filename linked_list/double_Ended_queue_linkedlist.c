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
void insert_at_front(int input_data);
void insert_at_rear(int input_data);
void delete_at_front();
void delete_at_rear();
void search();
void menu();
void peek_rear();
void peek_front();

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
                insert_at_front(i);
                break;
            case 2:
                printf("Value to input:");
                scanf("%d",&i);
                insert_at_rear(i);
                break;
            case 3:
                delete_at_front();
                break;
            case 4:
                delete_at_rear();
                break;
            case 5:
                traverse();
                break;
            case 6:
                peek_front();
                break;
            case 7:
                peek_rear();
                break;
            case 8:
                search();
                break;
            case 9:
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
    int count=0;
    if (temp==NULL){
        printf("List is empty\n");
        return;
    }
    while(count==0 || temp!=rear){
        printf("%d->",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\n");
}

void insert_at_front(int input_data){
    struct Node *new_node=create_node(input_data);
    if(new_node==NULL) return;
    new_node->next=front;
    if(front==NULL){
        rear=front=new_node;
        rear->next=front;
    }
    else{
        new_node->next=front;
        front=new_node;
        rear->next=front;
    }
    
}

void insert_at_rear(int input_data){
    struct Node *new_node=create_node(input_data);
    if(new_node==NULL) return;
    if(rear==NULL){
        front=rear=new_node;
        rear->next=front;
    }
    else{
        rear->next=new_node;
        rear=new_node;
        rear->next=front;
    }
}
void delete_at_front(){
    struct Node *deleted=front;
    if (front==NULL){
        printf("List is empty\n");
        return;
    }
    if (front->next==front)
        rear=front=NULL;
    else{
        front=front->next;
        rear->next=front;
    }
    printf("Deleted element is %d from begin\n",deleted->data);
    free(deleted);
}
void delete_at_rear(){
    struct Node *deleted=rear,*temp=front;
    if (rear==NULL){
        printf("List is empty\n");
        return;
    }
    if (front->next==front)
        front=rear=NULL;
    else{
        while(temp->next!=rear){
            temp=temp->next;
        }
        rear=temp;
        rear->next=front;
    }
    printf("Deleted element is %d from end\n",deleted->data);
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
    do{
        if(temp->data==target){
            printf("%d found at %d position in the list\n",target,i);
            return;
        }
        temp=temp->next;
        i++;
    }while(temp!=front);
    printf("Element %d not found in the list\n",target);
}
void menu(){
    printf("1.Insert at front\n");
    printf("2.Insert at rear\n");
    printf("3.Delete at front\n");
    printf("4.Delete at rear\n");
    printf("5.Display\n");
    printf("6.peek front\n");
    printf("7.peek rear\n");
    printf("8.Search\n");
    printf("9.Exit\n");
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