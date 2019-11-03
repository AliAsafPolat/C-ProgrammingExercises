// Linear Probing - Hashing
#include<stdio.h>
#include<stdlib.h>



int func(int key,int tablesize){
	return (key*13)%tablesize+1;
}

void goster(int * hash,int n){
	int i;
	printf("--------------------------------------------------------------\n");
	for(i=0;i<n;i++)
		printf("%d\t",hash[i]);
		
	printf("\n\n");
}

void insert(int *hashtable,int tableSize,int key){
	int i;
	int addr=func(key,tableSize);
	if(hashtable[addr]==-1)
	hashtable[addr]=key;								// hangi adres hangi key e atanmýþ onu görmek istiyorum sadece.
	else{
		i=1;
	while(hashtable[(addr+i)%tableSize]!=-1&&i<tableSize)			// boþ yer bulana kadar git.
	i++;
	if(i!=tableSize)
	hashtable[(addr+i)%tableSize]=key;
	else
	printf("Table is full! \n");
	}
}

int search(int *hashtable,int tablesize,int key){
	int i;
	int addr=func(key,tablesize);
	
	if(hashtable[addr]==key)
	return addr;									// hangi indexte olduðunu döndürsün istiyorum.
	else{
		i=1;
		while(hashtable[(addr+i)%tablesize]!=key&&i<tablesize)
		i++;
		
		if(i==tablesize)							// sürekli aramasýn diye.bulamazsa sonsuz döngüye girecek yoksa.
		return -1;
		else
		return (addr+i)%tablesize;
	}
}

void delete(int *hashtable,int tablesize,int key){
	int i;
	int addr=func(key,tablesize);
	
	if(hashtable[addr]==key){
		hashtable[addr]=-1;
	}else{
		i=1;
		while(hashtable[(addr+i)%tablesize]!=key&&i<tablesize)
		i++;
		
		if(i==tablesize)
		printf("bura bos");							// sürekli aramasýn diye.bulamazsa sonsuz döngüye girecek yoksa.
		else
		hashtable[(addr+i)%tablesize]=-1;
	}
}

void menu(){
	printf("Islem seciniz:\n");
	printf("1-)Insert\n");
	printf("2-)Delete\n");
	printf("3-)Search\n");
	printf("4-)Hash Goster\n");
	printf("5-)Cikis\n");
}

int main(){
int tablesize=10;	
int *hashTable;
int i,deger,secim,ret,flag=1;

hashTable=(int*)malloc(sizeof(int)*tablesize);

for(i=0;i<tablesize;i++){
	hashTable[i]=-1;
}
/*
insert(hashTable,tablesize,19);
insert(hashTable,tablesize,17);
insert(hashTable,tablesize,1);
insert(hashTable,tablesize,9);
insert(hashTable,tablesize,54);
*/
while(flag){
menu();
scanf("%d",&secim);

printf("Deger giriniz : ");
scanf("%d",&deger);

switch(secim){
	case 1:
		insert(hashTable,tablesize,deger);
		break;
	case 2:
		delete(hashTable,tablesize,deger);
		break;
	case 3:
		ret=search(hashTable,tablesize,deger);
		if(ret!=-1)
		printf("Bulundugu index : %d\n",ret);	
		break;
	case 4:
		goster(hashTable,tablesize);
		break;
	case 5:
		flag=0;
		break;			
}

goster(hashTable,tablesize);

}

	return 0;
	
}
