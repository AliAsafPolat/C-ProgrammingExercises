#include<stdlib.h>
#include<stdio.h>

struct Node{
int data;
struct Node *next;
};

void printList(struct Node *n) 
{ 
  while (n != NULL) 		//while n=NULL n=n->next
  { 
     printf(" %d ", n->data); 
     n = n->next; 
  } 
} 

int main(){
struct Node *head;
struct Node *second;
struct Node *third;

head =(struct Node*)malloc(sizeof(struct Node));
second=(struct Node*)malloc(sizeof(struct Node));
third=(struct Node*)malloc(sizeof(struct Node));

head->data=1;
head->next=second;

second->data=5;
second->next=third;

third->data=7;
third->next=NULL;


printList(head);

return 0;



}
