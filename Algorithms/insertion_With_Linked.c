#include<stdio.h>
#include<stdlib.h>

typedef struct link{
	int data;
	struct link *next;
	struct link *prev;
	
}Node;


Node* createNode (){
	Node *newNode=(Node *)malloc(sizeof(Node));
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}

int main(){
	
	int i,boyut,ilk;
	Node *p,*prev;
	Node *head=(Node*)malloc(sizeof(Node));
	head->prev=NULL;
	
	printf("Dizinin boyutunu giriniz : ");
	scanf("%d",&boyut);
	if(boyut>=1){
		
		
		for(p=head,i=0;i<boyut;i++,p=p->next){
		
			printf("%d. degeri giriniz : ",i+1);
			scanf("%d",&ilk);
	
			Node *yeni=createNode();
			p->data=ilk;
			yeni->prev=p;
			p->next=yeni;
			
	
			if(i==0){
			head=p;	
			}	
		
		}
		
		printf("Dizinin normal hali : \n");
		for(p=head;p->next!=NULL;p=p->next){
			printf("%d 	",p->data);
		}
	
	}else 
	printf("\nHatali deger girdiniz.Deger en az 1 olmali !\n");
	
	//DÝZÝ ALINDI LINKED HALÝNDE ELÝMDE
	
	int key;
	Node *y;
	for	(p=head->next;p->next!=NULL;p=p->next){
		key=p->data;
		y=p->prev;
		while(y!=NULL&&y->data>key){
			y->next->data=y->data;
			y->data=key;
			y=y->prev;
		}
	}
	
	printf("\nSiralanmis dizi : \n");
		for(p=head;p->next!=NULL;p=p->next){
			printf("%d 	",p->data);
		}
	
	
	
	
	
	
	
	return 0;
}
