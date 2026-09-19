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

int main()
{   insert_at_head(10);
    traverse();
    insert_at_head(20);
    traverse();
    insert_at_tail(30);
    traverse();
    
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
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert_at_head(int input_data){
    struct Node *new_node=create_node(input_data);
    if(new_node==NULL) return;
    if(head==NULL){
        head=new_node;
        tail=new_node;
    }
    else{
        new_node->next=head;
        head=new_node;
    }
}

void insert_at_tail(int input_data){
    struct Node *new_node=create_node(input_data);
    if(new_node==NULL) return;
    if(tail==NULL){
        head=new_node;
        tail=new_node;
    }
    else{
        tail->next=new_node;
        tail=new_node;
    }
}