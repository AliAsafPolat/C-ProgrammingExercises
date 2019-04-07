#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//**Boyer Moore Algoritmas� **
#define CHARALP 256
#define BOYUT 50
int* buildBadMatchTable(char pat[],int patlen,int alphsize){	//Buras� tabloyu olu�turma k�sm�d�r.
int *alp;						
alp=(int *)malloc(alphsize*sizeof(int));						//Tabloya yer a��ld�.
		
int i;
for(i = 0;i<alphsize-1;i++){									//�nce alfabenin b�t�n elamanlar�na patternin uzunlu�u girilmelidir
alp[i]=patlen;													//��nk� alfabeden olmayan bir harf geldi�i zaman patternin uzunlu�u kadar bir z�plama yapacakt�r.
}

for(i=0;i<patlen-1;i++){
	alp[pat[i]-'a']=patlen-1-i;									//Burada patlen-1-i nin anlam� �udur ki e�er ayn� harften iki tane ge�iyor ise pattern de
}																//ikinci gelenin i de�eri daha b�y�k olaca�� i�in �nceden gelen de�erin �zerine yaz�l�r.
return alp;														//Olu�turdu�um tabloyu geri d�nd�r�yorum.
}

int horspool(char text[],int textlen,char pat[],int patlen,int alphsize){
	int i,j;
	int *table=buildBadMatchTable(pat,patlen,alphsize);			//Fonksiyonumdan tabloyu al�yorum.
	
	i=patlen-1;													//i burada kayd�rma durumunu tutan de�i�ken olarak g�rev al�r.
	while(i<textlen){											//E�er text in uzunlu�una gelmi�sek art�k durmas� gerekli.
		j=0;													//j burada e�le�me durumlar�n� tutmaktad�r.
		while(j<=patlen&&pat[patlen-1-j]==text[i-j])			//Bilindi�i �zere bu algoritmada kelime asaf ise �nce f harfi kar��la�t�r�l�r
		j++;													//E�le�me g�zlenirse a harfine ge�ilir.
		if(j==patlen){											//pat[patlen-1-j]==text[i-j] bu yaz�m�n mant��� da budur �nce patternin son harfi kontrol edilir.
		return i-patlen+1;										//E�er e�le�me var ise patternin ge�ti�i yeri d�nd�r.
		}else
		i=i+table[text[i]-'a'];									//E�le�me yoksa text deki i nin tablodaki kayd�rma miktar� kadar kayd�rma sa�lan�r.
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
