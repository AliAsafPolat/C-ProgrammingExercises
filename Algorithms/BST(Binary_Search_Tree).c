#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int deger;
	struct node *left;
	struct node *right;
}Node;


Node* dugumOlustur(int veri){
	Node *dugum;							//Yeni düðüm oluþtur.
	dugum=(struct node*)malloc(sizeof(struct node));
	dugum->deger=veri;						//Girilen veriyi ata.
	dugum->left=NULL;						//Kollarý sýfýrla.
	dugum->right=NULL;
	return dugum;							//Oluþturduðun düðümü döndür.
}

Node* insert(Node *node,int data){ 			//Buradaki node head i tutuyor.
	if(node==NULL)							//Eðer boþ bir kola gelindiyse node u oluþtur.
	return dugumOlustur(data);
	
	if(node->deger>data)					//Eðer data node dan küçükse node un sol koluna ilerle.
	node->left=insert(node->left,data);
	else if(node->deger<data)				//Eðer data node dan büyükse node un sað koluna ilerle.
	node->right=insert(node->right,data);
	
	return node;							//En son node u döndür ki node->left ve node->right atamalarý saðlanabilsin.
}

Node* minValNode(Node *node){
	Node *current;
	current=node;							//En düþük node u bulmak için adýmlar..
	while(current->left!=NULL)				//Güncel node null olmakdýkça sola git.
	current=current->left;
	return current;							//En sola geldiðinde döndür.
}

Node* del(Node *root,int data){				//Bu kýsýmda düðüm silme fonksiyonu bulunmaktadýr.
if(root==NULL)								//Recursive final case..
return root;	

if(data<root->deger)						//Eger data roottan küçükse sola ilerle.				
root->left=del(root->left,data);	
else if(data>root->deger)					//Eðer data roottan büyükse saða ilerle.
root->right=del(root->right,data);
else{
	if(root->left==NULL){					//Silmede 3 durum vardýr birincisi silinecek node un sag kolu dolu olabilir.
		Node *tmp=root->right;				//Eger böyle bir durum mevcut ise sað kol dondurulur ve node serbest býrakýlýr.
		//free(root);						//Burada döndürmenin mantýðý recursive bir yapý tasarlandýðýndan root->right=del(root->right,data); 
		return tmp;							//kod parçasýnda root->right kýsmýna silinden node un sað bacaðý yerleþecek demektir.
	}else if(root->right==NULL){
		Node *tmp=root->left;				//Ýkinci bir durum sað bacaðýn boþ sol bacaðýn dolu olmasý durumudur.
		//free(root);						//Sol bacak döndürülür ve node silinir.
		return tmp;
	}
	Node *tmp=minValNode(root->right);		//Eðer silinecek node un her iki bacagý da doluysa node un sað kolunda bulunan en küçük elemanýn 
	root->deger=tmp->deger;					//bulunmasý gerekir.Bulunan bu deðer node un yerine atanýr.
	root->right=del(root->right,tmp->deger);//Sað alt aðaçtan alýnan en küçük deðerin silinmesi için tekrar recursive yapýya baþvurulur.
}
return root;								//root->right=del(root->right,data); iþlemlerinin saðlanmasý için recursive yapýda eksik olmamalý  

}

void preTraverse(Node *root){				//Agacý Node-Left-Right þeklinde yazdýrmayý saðlar.
	if(root==NULL)return;
	printf("%d ",root->deger);
	preTraverse(root->left);
	preTraverse(root->right);
	
}

void inTraverse(Node *root){				//Agacý Left-Node-Right þeklinde yazdýrmayý saðlar.
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
