//linked ilst implementation
#include <stdio.h>
#include <stdlib.h>
//creating the structure of the node
struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;

//functions for required operations
struct Node* create_node(int input_data);
void traverse();
void insert_at_head(int input_data);
void insert_at_tail(int input_data);
void delete_at_head();
void delete_at_tail();
void search();
void menu();

int main()
{  
    while(1){
        menu();
        int ch,i;
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Value to input:");
                scanf("%d",&i);
                insert_at_head(i);
                break;
            case 2:
                printf("Value to input:");
                scanf("%d",&i);
                insert_at_tail(i);
                break;
            case 3:
                delete_at_head();
                break;
            case 4:
                delete_at_tail();
                break;
            case 5:
                traverse();
                break;
            case 6:
                search();
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
    struct Node *temp=head;
    if (temp==NULL){
        printf("List is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert_at_head(int input_data){
    struct Node *new_node=create_node(input_data);
    if(new_node==NULL) return;
    new_node->next=head;
    if(head==NULL)
        tail=new_node;
    head=new_node;
    
}

void insert_at_tail(int input_data){
    struct Node *new_node=create_node(input_data);
    if(new_node==NULL) return;
    if(tail==NULL)
        head=new_node;
    else
        tail->next=new_node;
    tail=new_node;
}
void delete_at_head(){
    struct Node *deleted=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    if (head->next==NULL)
        tail=NULL;
    head=head->next;
    printf("Deleted element is %d from begin\n",deleted->data);
    free(deleted);
}
void delete_at_tail(){
    struct Node *deleted=tail,*temp=head;
    if (tail==NULL){
        printf("List is empty\n");
        return;
    }
    if (head->next==NULL)
        head=tail=NULL;
    else{
        while(temp->next!=tail){
            temp=temp->next;
        }
        tail=temp;
        tail->next=NULL;
    }
    printf("Deleted element is %d from end\n",deleted->data);
    free(deleted);
}
void search(){
    int target;
    printf("enter the element to search");
    scanf("%d",&target);
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp=head;
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
    printf("1.Insert at begin\n");
    printf("2.Insert at end\n");
    printf("3.Delete at begin\n");
    printf("4.Delete at end\n");
    printf("5.Display\n");
    printf("6.Search\n");
    printf("7.Exit\n");
}