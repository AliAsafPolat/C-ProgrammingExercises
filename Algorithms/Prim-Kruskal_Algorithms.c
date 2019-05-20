#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	void primKod(int**matris,int boyut){
		int min,x,y,i,j,n=0;
		int marked[boyut];
		
		for(i=0;i<boyut;i++){					//Butun isaretlemeleri sifirla.
			marked[i]=0;	
		}
	
		marked[0]=1;							//Ilk node dan aramaya basla.
		
		while(n<boyut-1){						//Edge sayým node-1 sayidadir.
			min=322265;							
			x=y=0;								//x ve y min index tutuyor.
			for(i=0;i<boyut;i++){				
				if(marked[i]==1){				//Sectigim kenarlardan arastirmaya devam edebilirim.
					for(j=0;j<boyut;j++){		//Sectigim kenarlardan eger secilmemis kenarlara geliyorsam minimumunu seciyorum.
						if(marked[j]==0&&matris[i][j]>0&&min>matris[i][j]){
								min=matris[i][j];
								x=i;			//minimum kenar bulunup indisi alýnýyor.
								y=j;
						}
					}
				}
			}
			printf("%d\n",matris[x][y]);		//Buldugum minimum kenari yazdiriyorum.
			marked[y]=1;						//Bulunan min kenari isaretliyorum.
			n++;								//Kenar sayimi bir artiriyorum.
		}
		
	}


	void kruskalGo(int **matris,int boyut){			
		int marked[boyut],i,j,n=0,x,y;
		
		for(i=0;i<boyut;i++){					//Butun isaretlemeleri sifirliyorum.
			marked[i]=0;
		}
		
		while(n<boyut-1){						//Kenar sayim node-1 sayida olacaktir.
			int min=32565;
			x=y=0;
		for(i=0;i<boyut;i++){					//Tum grafý arayacagim.
				for(j=0;j<boyut;j++){			//Tüm grafta min kenari bulunca isaretliyorum indislerini alýyorum.
					if(marked[j]==0&&matris[i][j]<min&&matris[i][j]>0){
						min=matris[i][j];			
						x=i;
						y=j;
					}	
				}
			}
			printf("%d\n",min);					//Buldugum minimum edge nin iki nodeunu da isaretliyorum.
			marked[y]=1;
			marked[x]=1;
			n++;								//Bulunan kenar sayisini bir artýrýyorum.
		}	
			
		
	}
	int main(){
	
		int i,j,nodeSay,kenarSay,ilk,iki,uzunluk;
		int **graph;
		
		
		printf("Grafin node sayisini giriniz.");
		scanf("%d",&nodeSay);
		printf("Grafin kenar sayisini giriniz.");
		scanf("%d",&kenarSay);
		
		graph=(int**)malloc(sizeof(int*)*nodeSay);
		
		for(i=0;i<nodeSay;i++){
			graph[i]=(int*)malloc(sizeof(int)*nodeSay);
		}
		
		for(i=0;i<nodeSay;i++){
			for(j=0;j<nodeSay;j++){
				graph[i][j]=0;
			}
		}
		
		for(i=0;i<kenarSay;i++){
		printf("Kenarin bagli oldugu ilk dugum : ");
		scanf("%d",&ilk);
		printf("Kenarin bagli oldugu ikinci dugum : ");
		scanf("%d",&iki);	
		printf("Kenarin uzunlugu : ");
		scanf("%d",&uzunluk);
		graph[ilk][iki]=uzunluk;
		graph[iki][ilk]=uzunluk;
		}
		//Graf þuan elimde
		
		for(i=0;i<nodeSay;i++){
			for(j=0;j<nodeSay;j++){
				printf("%d  ",graph[i][j]);		
			}	
			printf("\n");
		}
		
		//goPrim(graph,nodeSay,kenarSay);
		//primKod(graph,nodeSay);
		kruskalGo(graph,nodeSay);
		
		
		return 0;
		
		
	}
