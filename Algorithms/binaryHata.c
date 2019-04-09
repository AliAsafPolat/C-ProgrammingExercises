#include<stdio.h>
#include<stdlib.h>
//Soru binary tree de bir yerde hata yap�lm�� onu bulma sorusu.

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

int binaryHata(Node *head){					
	int ret;									//Hatan�n bulundu�u yeri d�nd�r�yorum.
	int static flag=0;							//Hata bulunduysa flag=1 yap�p ��k�yorum.
	if(head==NULL)								//E�er rootum null sa d�n. Recursive biti� kontrol�m budur.
	return;
	else{
	 if(head->left!=NULL){						//E�er sol aya��m bo� de�ilse kontrol et
		if(head->left->deger>head->deger){		//Soldaki de�erim sa�daki de�erimden b�y�k m�?
		flag=1;									//B�y�kse flag=1
		return head->deger;}					//Hatal� de�eri d�nd�r
		else
		ret=binaryHata(head->left);				//B�y�k de�ilse node un sol aya��n� tekrar bu fonksiyone yolla ve onun �ocuklar�na bak.
	}
	 if(flag==0&&head->right!=NULL){			//Flag kontrol�n� burada yapmam�n sebebi a�ac�n sol taraf�na daha �nce bak�ld��� i�in 
		if(head->right->deger<head->deger){		//orada bulunan ret de�eri burada bozulabiliyor fakat buradan sonra ba�ka kod par�as� olmad���ndan
		flag=1;									//left k�sm� buradaki veriyi bozam�yor.
		return head->deger;
		}else
		ret=binaryHata(head->right);
	}
}
	return ret;	
}

int main(){
	
	Node *root=dugumOlustur(3);
	root->left=dugumOlustur(2);
	//root->left->left=dugumOlustur(1);
	//root->left->left->right=dugumOlustur(0);
	//root->left->right=dugumOlustur(8);
	root->right=dugumOlustur(100);
	root->right->left=dugumOlustur(5);
	//root->right->left->left=dugumOlustur();
	root->right->right=dugumOlustur(91);
	root->right->right->right=dugumOlustur(101);
	root->right->right->left=dugumOlustur(11);
	
	
	int deger=binaryHata(root);
	printf("Hatali deger : %d",deger);
	
	
	return 0;
	
}
