#include<stdio.h>
#include<stdlib.h>

struct liste{
	int id;
	struct liste *next;
	
};
typedef struct liste ELEMAN;

static ELEMAN *head;

/* ******************************* */
ELEMAN *eleman_olustur(void){
	ELEMAN *p;
	p=(ELEMAN*)malloc(sizeof(ELEMAN));
	p->next=NULL;
	
	return p;
}
/* ******************************* */


void sona_ekle(int id){
ELEMAN *p,*yeni;

yeni=eleman_olustur();
yeni->id=id;

if (head==NULL){
head=yeni;
return;}
else {
	for (p=head;p->next!=NULL;p=p->next);
	p->next=yeni;
}

}


/* ******************************* */
void istek_sonra(int id, int istekid ){
	
	ELEMAN *p,*yeni;
	yeni=eleman_olustur();
	yeni->id=id;
	
	if(head==NULL){
		printf("Listemiz bostur isteginizi yerine getiremedik :( \n");
	return;
	}
	
	
	for(p=head;p->next!=NULL&&p->id!=istekid;p=p->next);
	if(p->next==NULL){
	printf("Istediginiz eleman listede bulunamadi.\n\n");
	return;
	} 
	yeni->next=p->next;
	p->next=yeni;
	
}

/* ******************************* */
void eleman_sil(int id){
	ELEMAN *p;
	
	if(head->id==id){
		head=head->next;
		return;
	}
	
	
	for (p=head;p->next!=NULL&&p->next->id!=id;p=p->next);
	if(p->next==NULL){
	
	printf("***Silmek istenen eleman bulunamadi\n\n");
	return;}
	else
	p->next=p->next->next;
	
}



/* ******************************* */
void menu(void){
	printf("Hosgeldiniz!\nSeciminiz nedir?\n1-Listeye eleman ekle\n2-Listeden eleman sil\n3-Cikis\nSeciminiz:");
}
/********************************* */

int main(){
	head=NULL;
	ELEMAN *p;
	int n,i,j;
	int id;
	int istekid;

while(n!=3){

	menu();
	scanf("%d",&n);
	
	switch(n){
		case 1:
			printf("Eklemek istediginiz elemanin idsini giriniz.Talebiniz var ise kimden sonra geleceginizi seciniz.\nID:");
			scanf("%d",&id);
			printf("Kimden sonra gelmek istiyorsunuz? Rastgele girmek icin(-1 tuslayin.):");
			scanf("%d",&istekid);
			if (istekid==-1){
				sona_ekle(id);
			}else 
				istek_sonra(id,istekid);
			break;	
		
		case 2:
			printf("Silmek istediginiz elemani seciniz.");
			scanf("%d",&id);
			eleman_sil(id);
			break;
		case 3:
			exit(1);
			break;
	}
	
	for (i=0,p=head;p!=NULL;p=p->next,i++){
		printf("%d inci elaman: %d\n\n",i+1,p->id);
	}
}

return 0;
}
