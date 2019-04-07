#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//**Boyer Moore Algoritması **
#define CHARALP 256
#define BOYUT 50
int* buildBadMatchTable(char pat[],int patlen,int alphsize){			//Burası tabloyu oluşturma kısmıdır.
int *alp;						
alp=(int *)malloc(alphsize*sizeof(int));					//Tabloya yer açıldı.
		
int i;
for(i = 0;i<alphsize-1;i++){							//Önce alfabenin bütün elamanlarına patternin uzunluğu girilmelidir
alp[i]=patlen;									//çünkü alfabeden olmayan bir harf geldiği zaman patternin uzunluğu kadar bir zıplama yapacaktır.
}

for(i=0;i<patlen-1;i++){
	alp[pat[i]-'a']=patlen-1-i;						//Burada patlen-1-i nin anlamı şudur ki eğer aynı harften iki tane geçiyor ise pattern de
}										//ikinci gelenin i değeri daha büyük olacağı için önceden gelen değerin üzerine yazılır.
return alp;									//Oluşturduğum tabloyu geri döndürüyorum.
}

int horspool(char text[],int textlen,char pat[],int patlen,int alphsize){
	int i,j;
	int *table=buildBadMatchTable(pat,patlen,alphsize);			//Fonksiyonumdan tabloyu alıyorum.
	
	i=patlen-1;								//i burada kaydırma durumunu tutan değişken olarak görev alır.
	while(i<textlen){							//Eğer text in uzunluğuna gelmişsek artık durması gerekli.
		j=0;								//j burada eşleşme durumlarını tutmaktadır.
		while(j<=patlen&&pat[patlen-1-j]==text[i-j])			//Bilindiği üzere bu algoritmada kelime asaf ise önce f harfi karşılaştırılır
		j++;								//Eşleşme gözlenirse a harfine geçilir.
		if(j==patlen){							//pat[patlen-1-j]==text[i-j] bu yazımın mantığı da budur önce patternin son harfi kontrol edilir.
		return i-patlen+1;						//Eğer eşleşme var ise patternin geçtiği yeri döndür.
		}else
		i=i+table[text[i]-'a'];						//Eşleşme yoksa text deki i nin tablodaki kaydırma miktarı kadar kaydırma sağlanır.
	}
	return -1;
}

int main(){
char text[BOYUT],pat[BOYUT];
int textlen,patlen;
int ret;
printf("Texti giriniz : ");
scanf("%s",text);	
textlen=strlen(text);
printf("Aradiginiz patterni giriniz : ");
scanf("%s",pat);
patlen=strlen(pat);
	
ret=horspool(text,textlen,pat,patlen,28);
if(ret!=-1){
	printf("Deger text in %d inci indisinde bulundu.\n",ret);
}else
printf("Deger yok\n");
	
return 0;	
}
