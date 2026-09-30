//linked ilst implementation
#include <stdio.h>
#include <stdlib.h>
//creating the structure of the node
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
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
void insert_at_pos(int input_data,int pos);
void delete_at_pos(int pos);

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
                printf("\nValue to input:\n");
                scanf("%d",&i);
                printf("\nEnter the position:\n");
                scanf("%d",&pos);
                insert_at_pos(i,pos);
                break;
            case 7:
                printf("\nEnter the position:\n");
                scanf("%d",&pos);
                delete_at_pos(pos);
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
  node->prev=NULL;
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

    if(head==NULL)
        tail=head=new_node;   
    else{
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
    }
}

void insert_at_tail(int input_data){
    struct Node *new_node=create_node(input_data);

    if(tail==NULL)
        head=tail=new_node;
    else{
        new_node->prev=tail;
        tail->next=new_node;
        tail=new_node;
    }
}
void delete_at_head(){
    struct Node *deleted=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    if (head->next==NULL)
        tail=head=NULL;
    else{
        head=head->next;
        head->prev=NULL;
        }
    printf("Deleted element is %d from begin\n",deleted->data);
    free(deleted);
}
void delete_at_tail(){
    struct Node *deleted=tail;
    if (tail==NULL){
        printf("List is empty\n");
        return;
    }
    if (head->next==NULL)
        head=tail=NULL;
    else{
        tail=tail->prev;
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
    printf("1.Insert at begin\n");
    printf("2.Insert at end\n");
    printf("3.Delete at begin\n");
    printf("4.Delete at end\n");
    printf("5.Display\n");
    printf("6.Insert at position\n");
    printf("7.Delete at position\n");
    printf("8.Search\n");
    printf("9.Exit\n");
}
void insert_at_pos(int input_data,int pos){
    struct Node *new_node=create_node(input_data);
    if (pos==1){
        insert_at_head(input_data);
    }
    else{
        struct Node *temp=head;
        int i=1;
        while(i<pos-1 && temp!=NULL){
            temp=temp->next;
            i++;
        }
        if (temp==NULL){
            printf("\n invalid position\n");
            return;
        }
        temp->next->prev=new_node;
        new_node->prev=temp;
        new_node->next=temp->next;
        temp->next=new_node;
        printf("\n %d inserted at position %d\n",input_data,pos);
    }
}
void delete_at_pos(int pos){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    else{
        if(pos==1){
            delete_at_head();
            return;
        }
        struct Node *temp=head;
        struct Node *del=NULL;
        int i=1;
        while(i<pos-1 && temp->next !=NULL){
            temp=temp->next;
            i++;
        }
        if (temp->next==NULL){
            printf("\n invalid position\n");
            return;
        }
        del=temp->next;
        printf("\n%d deleted from %d \n",del->data,pos);
        temp->next=del->next;
        temp->next->prev=temp;
        free(del);
    }
}