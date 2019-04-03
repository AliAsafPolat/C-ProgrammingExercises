#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int deger;
	struct node *left;
	struct node *right;
}Node;


Node* dugumOlustur(int veri){
	Node *dugum;							//Yeni d���m olu�tur.
	dugum=(struct node*)malloc(sizeof(struct node));
	dugum->deger=veri;						//Girilen veriyi ata.
	dugum->left=NULL;						//Kollar� s�f�rla.
	dugum->right=NULL;
	return dugum;							//Olu�turdu�un d���m� d�nd�r.
}

Node* insert(Node *node,int data){ 			//Buradaki node head i tutuyor.
	if(node==NULL)							//E�er bo� bir kola gelindiyse node u olu�tur.
	return dugumOlustur(data);
	
	if(node->deger>data)					//E�er data node dan k���kse node un sol koluna ilerle.
	node->left=insert(node->left,data);
	else if(node->deger<data)				//E�er data node dan b�y�kse node un sa� koluna ilerle.
	node->right=insert(node->right,data);
	
	return node;							//En son node u d�nd�r ki node->left ve node->right atamalar� sa�lanabilsin.
}

Node* minValNode(Node *node){
	Node *current;
	current=node;							//En d���k node u bulmak i�in ad�mlar..
	while(current->left!=NULL)				//G�ncel node null olmakd�k�a sola git.
	current=current->left;
	return current;							//En sola geldi�inde d�nd�r.
}

Node* del(Node *root,int data){				//Bu k�s�mda d���m silme fonksiyonu bulunmaktad�r.
if(root==NULL)								//Recursive final case..
return root;	

if(data<root->deger)						//Eger data roottan k���kse sola ilerle.				
root->left=del(root->left,data);	
else if(data>root->deger)					//E�er data roottan b�y�kse sa�a ilerle.
root->right=del(root->right,data);
else{
	if(root->left==NULL){					//Silmede 3 durum vard�r birincisi silinecek node un sag kolu dolu olabilir.
		Node *tmp=root->right;				//Eger b�yle bir durum mevcut ise sa� kol dondurulur ve node serbest b�rak�l�r.
		//free(root);						//Burada d�nd�rmenin mant��� recursive bir yap� tasarland���ndan root->right=del(root->right,data); 
		return tmp;							//kod par�as�nda root->right k�sm�na silinden node un sa� baca�� yerle�ecek demektir.
	}else if(root->right==NULL){
		Node *tmp=root->left;				//�kinci bir durum sa� baca��n bo� sol baca��n dolu olmas� durumudur.
		//free(root);						//Sol bacak d�nd�r�l�r ve node silinir.
		return tmp;
	}
	Node *tmp=minValNode(root->right);		//E�er silinecek node un her iki bacag� da doluysa node un sa� kolunda bulunan en k���k eleman�n 
	root->deger=tmp->deger;					//bulunmas� gerekir.Bulunan bu de�er node un yerine atan�r.
	root->right=del(root->right,tmp->deger);//Sa� alt a�a�tan al�nan en k���k de�erin silinmesi i�in tekrar recursive yap�ya ba�vurulur.
}
return root;								//root->right=del(root->right,data); i�lemlerinin sa�lanmas� i�in recursive yap�da eksik olmamal�  

}

void preTraverse(Node *root){				//Agac� Node-Left-Right �eklinde yazd�rmay� sa�lar.
	if(root==NULL)return;
	printf("%d ",root->deger);
	preTraverse(root->left);
	preTraverse(root->right);
	
}

void inTraverse(Node *root){				//Agac� Left-Node-Right �eklinde yazd�rmay� sa�lar.
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
