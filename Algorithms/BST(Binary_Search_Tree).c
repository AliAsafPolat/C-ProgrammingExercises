#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int deger;
	struct node *left;
	struct node *right;
}Node;


Node* dugumOlustur(int veri){
	Node *dugum;							//Yeni düğüm oluştur.
	dugum=(struct node*)malloc(sizeof(struct node));
	dugum->deger=veri;						//Girilen veriyi ata.
	dugum->left=NULL;						//Kolları sıfırla.
	dugum->right=NULL;
	return dugum;							//Oluşturduğun düğümü döndür.
}

Node* insert(Node *node,int data){ 					//Buradaki node head i tutuyor.
	if(node==NULL)							//Eğer boş bir kola gelindiyse node u oluştur.
	return dugumOlustur(data);
	
	if(node->deger>data)						//Eğer data node dan küçükse node un sol koluna ilerle.
	node->left=insert(node->left,data);
	else if(node->deger<data)					//Eğer data node dan büyükse node un sağ koluna ilerle.
	node->right=insert(node->right,data);
	
	return node;							//En son node u döndür ki node->left ve node->right atamaları sağlanabilsin.
}

Node* minValNode(Node *node){
	Node *current;
	current=node;							//En düşük node u bulmak için adımlar..
	while(current->left!=NULL)					//Güncel node null olmakdıkça sola git.
	current=current->left;
	return current;							//En sola geldiğinde döndür.
}

Node* del(Node *root,int data){						//Bu kısımda düğüm silme fonksiyonu bulunmaktadır.
if(root==NULL)								//Recursive final case..
return root;	

if(data<root->deger)						//Eger data roottan küçükse sola ilerle.				
root->left=del(root->left,data);	
else if(data>root->deger)					//Eğer data roottan büyükse sağa ilerle.
root->right=del(root->right,data);
else{
	if(root->left==NULL){					//Silmede 3 durum vardır birincisi silinecek node un sag kolu dolu olabilir.
		Node *tmp=root->right;				//Eger böyle bir durum mevcut ise sağ kol dondurulur ve node serbest bırakılır.
		//free(root);					//Burada döndürmenin mantığı recursive bir yapı tasarlandığından root->right=del(root->right,data); 
		return tmp;					//kod parçasında root->right kısmına silinden node un sağ bacağı yerleşecek demektir.
	}else if(root->right==NULL){
		Node *tmp=root->left;				//İkinci bir durum sağ bacağın boş sol bacağın dolu olması durumudur.
		//free(root);					//Sol bacak döndürülür ve node silinir.
		return tmp;
	}
	Node *tmp=minValNode(root->right);			//Eğer silinecek node un her iki bacagı da doluysa node un sağ kolunda bulunan en küçük elemanın 
	root->deger=tmp->deger;					//bulunması gerekir.Bulunan bu değer node un yerine atanır.
	root->right=del(root->right,tmp->deger);		//Sağ alt ağaçtan alınan en küçük değerin silinmesi için tekrar recursive yapıya başvurulur.
}
return root;							//root->right=del(root->right,data); işlemlerinin sağlanması için recursive yapıda eksik olmamalı  

}

void preTraverse(Node *root){				//Agacı Node-Left-Right şeklinde yazdırmayı sağlar.
	if(root==NULL)return;
	printf("%d ",root->deger);
	preTraverse(root->left);
	preTraverse(root->right);
	
}

void inTraverse(Node *root){				//Agacı Left-Node-Right şeklinde yazdırmayı sağlar.
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
