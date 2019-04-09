#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#define MAX 5
typedef enum {false,true} boolean;
int front=-1;
int rear=-1;
int size=-1;


void menu(){
	system("CLS");
	printf("\n\n********************************************************\nYapmak istediginiz islemi seciniz : \n1-Ekle\n2-Cikar\n\n********************************************************\n");
	
}

boolean isEmpty(){					//Eğer size -1 ise dizim şuan boş demektir
	if (size==-1)		
	return true;
	else return false;
	
}

boolean isFull(){					//Eğer size max belirlediğim alana ulaşmışsa fulldür.
	if(size==MAX)
	return true;
	else return false;
}

void diziEkle(int dizi[],int val){
	if(!isFull()){					//Eğer maximum alana ulaşılmamışsa üç seçenek vardır.
	if(size<0){					//Birincisi dizi tamamen boş olabilir.
		dizi[0]=val;				//Dizi tamamen boş ise ilk değeri ata
		front=rear=0;				//Baş ve son aynı yeri göstersin.
		size=1;						
	}else if(rear+1==MAX){				//İkinci bir durum ise kuyruk kısmı sonra ulaşmış demektir bu dizinin dolduğu anlamına gelmez.
		rear=0;					//Zaten yukarıda maximuma ulaşılmış mı kontrolü yapılmıştı.
		dizi[0]=val;				//Öyleyse tekrar gel başa ata.
		size++;					//Boyutu yine artır.
	}else{
		rear++;					//Üçüncü durum ise eğer dizi boş değil ve maximum kapasiteye ulaşılmamışsa
		dizi[rear]=val;				//demek ki her şey seyirinde gidiyor eklemeyi yap.Rear kısmını bir arttır boyutu bir arttır.
		size++;					//ve sıradaki yere değeri yaz.
	}
	
}else
		printf("Dizi suan doludur.\n");		//Eğer isFull den true dönerse demek ki doludur.

}

int diziSil(int dizi[]){
	int ret;
	if(isEmpty()){					//Silerken ise isEmpty ile boş mu kontrolü yapılıyor.
		printf("Dizi suanda bostur.\n");	//Boş ise hata mesajı ver.
		return;
	}else{						//Silme işlemleri hatırlarsak front üzerinden yapılıyordu.
		ret=dizi[front];			//Öndeki değeri alıyoruz ve ön değerimizi bir artırıyoruz.
		front++;
		
		if(front==MAX)				//Oluşabilecek durumlardan birisi de front umuzun maximum kapasiteye ulaşmış olması.
		front=0;				//Eğer front maximuma ulaşmış ise tekrar başa alıyoruz ve boyutu bir azaltıyoruz.
		size--;
		return ret;
	}
	
	
	
}


void kuyrukYazdir(int dizi[]){
	int i;
	printf("\n********************************************************\nKuyrugun durumu : \n");
	if(size>0){
	
	if(rear<front){					//Kuyruk yazdırmada oluşacak hatalardan biri rear ın yani kuyruk kısmının baştan büyük olması.
		for(i=front;i<MAX;i++){			//Böyle bir durum var ise frontdan dizinin sonuna kadar yazdır sonrasında dizinin başından itibaren 
		printf("%d ",dizi[i]);			//rear a kadar yazdır.
	}
	for(i=0;i<=rear;i++){
		printf("%d ",dizi[i]);
}
	printf("\n********************************************************\n");
	}else{
	
	for(i=front;i<=rear;i++){			//Eğer rear normal şekilde fronttan büyük ise front dan rear a kadar yazdırmak yeterli olacaktır.
		printf("%d ",dizi[i]);
	}
	printf("\n********************************************************\n");}
	}
		
	
	else{printf("Dizi suanda bos agacim\n");
	}
}

int main(){
	
	int dizi[MAX];
int islem,ekle,al;
while(1){

menu();
scanf("%d",&islem);
switch(islem){
	case 1:
		printf("Kuyruga eklemek istediginiz elemani giriniz.");
		scanf("%d",&ekle);
		diziEkle(dizi,ekle);
		kuyrukYazdir(dizi);
		break;
	case 2:
		al=diziSil(dizi);
		printf("Alinan eleman : %d",al);
		kuyrukYazdir(dizi);
		break;
	default:
		printf("Hatali secim");		
}
sleep(2);
}

	
	
	
	return 0;
}
