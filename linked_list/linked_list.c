//linked ilst implementation
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main()
{
    struct Node node1,node2,node3,node4;
    node1.data=10;
    node1.next=&node2;
    node2.data=20;
    node2.next=&node3;
    node3.data=30;
    node3.next=&node4;
    node4.data=40;
    node4.next=NULL;

    printf("my linked list is :\n");
    printf("%d->",node1.data);
    printf("%d->",node1.next->data);
    printf("%d->",node1.next->next->data);
    printf("%d->",node1.next->next->next->data);
    printf("\nmy linked list:");
    struct Node *temp=&node1;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    return 0;
}