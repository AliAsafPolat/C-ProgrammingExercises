#include<stdio.h>
#include<stdlib.h>

typedef struct  node{
	int number;
	
	struct node *next;
	
};
static struct node* head;

void addelement(struct node *eleman);
void addafter(struct node *eleman,struct node *liste1);


int main(){
	
struct node *liste0;
struct node *liste1;
struct node *liste2;
//struct node *head;
struct node *eleman;

//liste0=(node_t*)malloc(sizeof(node_t));
	liste0=(struct node*)malloc(sizeof(struct node));
	liste1=(struct node*)malloc(sizeof(struct node));
	liste2=(struct node*)malloc(sizeof(struct node));
	eleman=(struct node*)malloc(sizeof(struct node));
	
	liste0->number=1;
	liste0->next=liste1;
	
	liste1->number=2;
	liste1->next=liste2;
	
	liste2->number=3;
	liste2->next=NULL;
	
	eleman->number=1506;
	eleman->next=NULL;
	head=liste0;
	
	//addelement(eleman);
	addafter(eleman,liste1);
	
	while(head!=NULL){
		printf("%d",head->number);
		head=head->next;
	}
	
	
	return 0;
}


void addelement(struct node *eleman){
	struct node *p;
	
	for (p=head;p->next!=NULL;p=p->next);
	p->next=eleman;
	//eleman->next=NULL;
	
	
}

void addafter(struct node *eleman,struct node *liste1){
	struct node *p;
	if(eleman==NULL || liste1==NULL || eleman==liste1 || liste1->next == eleman){
	printf("insert_after(): Bad arguments \n");
	return;
    }
	
	for (p=head;p->next!=liste1;p=p->next);
	eleman->next=p->next->next;
	p->next->next=eleman;
	//eleman->next=p->next->next->next;
	//p->next->next=eleman;
	
	
	
	
}
