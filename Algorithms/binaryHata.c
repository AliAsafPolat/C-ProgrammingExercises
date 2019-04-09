#include<stdio.h>
#include<stdlib.h>
//Soru Binary Tree de bir yerde hata yapılmış onu bulma sorusu.

typedef struct node{
	int deger;
	struct node *left;
	struct node *right;
}Node;


Node* dugumOlustur(int veri){
	Node *dugum;							//Yeni dügüm olustur.
	dugum=(struct node*)malloc(sizeof(struct node));
	dugum->deger=veri;						//Girilen veriyi ata.
	dugum->left=NULL;						//Kollari sıfırla.
	dugum->right=NULL;
	return dugum;							//Olusturdugun dügümü döndür.
}

int binaryHata(Node *head){					
	int ret;							//Hatanın bulundugu yeri döndürüyorum.
	int static flag=0;						//Hata bulunduysa flag=1 yapıp çıkıyorum.
	if(head==NULL)							//Eger rootum null sa dön. Recursive bitiş kontrolüm budur.
	return;
	else{
	 if(head->left!=NULL){						//Eger sol ayagım bos degilse kontrol et
		if(head->left->deger>head->deger){			//Soldaki değerim sağdaki değerimden büyük mü?
		flag=1;							//Büyükse flag=1
		return head->deger;}					//Hatalı değeri döndür
		else
		ret=binaryHata(head->left);				//Büyük değilse node un sol ayağını tekrar bu fonksiyone yolla ve onun çocuklarına bak.
	}
	 if(flag==0&&head->right!=NULL){				//Flag kontrolünü burada yapmamın sebebi ağacın sol tarafına daha önce bakıldığı için 
		if(head->right->deger<head->deger){			//orada bulunan ret değeri burada bozulabiliyor fakat buradan sonra baþka kod parçası olmadýðýndan
		flag=1;							//left kısmı buradaki veriyi bozamıyor.
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
