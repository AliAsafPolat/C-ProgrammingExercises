#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int deger;
	struct node *left;
	struct node *right;
}Node;


Node* dugumOlustur(int veri){
	Node *dugum;
	dugum=(struct node*)malloc(sizeof(struct node));
	dugum->deger=veri;
	dugum->left=NULL;
	dugum->right=NULL;
	return dugum;
}

Node* insert(Node *node,int data){ 			//Buradaki node head i tutuyor.
	if(node==NULL)
	return dugumOlustur(data);
	
	if(node->deger>data)
	node->left=insert(node->left,data);
	else if(node->deger<data)
	node->right=insert(node->right,data);
	
	return node;
}

Node* minValNode(Node *node){
	Node *current;
	current=node;
	while(current->left!=NULL)
	current=current->left;
	return current;
}

Node* del(Node *root,int data){
if(root==NULL)
return root;

if(data<root->deger)				
root->left=del(root->left,data);	
else if(data>root->deger)
root->right=del(root->right,data);
else{
	if(root->left==NULL){
		Node *tmp=root->right;
		//free(root);
		return tmp;
	}else if(root->right==NULL){
		Node *tmp=root->left;
		//free(root);
		return tmp;
	}
	Node *tmp=minValNode(root->right);
	root->deger=tmp->deger;
	root->right=del(root->right,tmp->deger);
}
return root;

}

void preTraverse(Node *root){
	if(root==NULL)return;
	printf("%d ",root->deger);
	preTraverse(root->left);
	preTraverse(root->right);
	
}

void inTraverse(Node *root){
	if(root==NULL)return;
	inTraverse(root->left);
	printf("%d ",root->deger);
	inTraverse(root->right);
	
}


int main(){
	Node *root=dugumOlustur(10);
	insert(root,5);
	insert(root,20);
	printf("Agacin ilk hali : \n");
	preTraverse(root);
	printf("\n");
	
	Node *yeni=dugumOlustur(4);
	insert(root,yeni->deger);
	preTraverse(root);
	printf("\nYeni dizi : \n");
	insert(root,2);
	printf("\nYeni dizi : \n");
	preTraverse(root);
	insert(root,25);
	printf("\nYeni dizi : \n");
	preTraverse(root);
	insert(root,17);
	printf("\nYeni dizi : \n");
	preTraverse(root);
	insert(root,6);
	printf("\nYeni dizi : \n");
	preTraverse(root);
	insert(root,3);
	printf("\nYeni dizi : \n");
	preTraverse(root);

	
	printf("\n\nInTraverse : \n");
	inTraverse(root);
	
}
