#include<stdio.h>
int reOrganize(int **mtr, int n, int m,int *non0){
	
	int **rMtr;
	int i,j,k;
	k=0;
	
	for (i = 0;i < n;i++ ){
		for ( j = 0;j < m ; j++) {
			if (mtr[i][j]>0)
			*non0+=1;
				}
		}
	
	rMtr=(int **)malloc (*non0 * sizeof ( int *));
	
	for (i=0;i<*non0;i++)
	rMtr[i]=(int*)malloc(3 * sizeof ( int ) );
	
	
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if (mtr[i][j]>0){
				rMtr[k][0]=i;
				rMtr[k][1]=j;
				rMtr[k][2]=mtr[i][j];
				k+=1;				
			}
		}
	}
	/*printf("Arranged matrix :\n");
	for (i=0;i<non0;i++){
		for (j=0;j<3;j++){
	
		printf("%3d",rMtr[i][j]);

		}
	printf("\n");
	
} */
	
	
	
	
return rMtr;
}





int main(){
	int **mtr,**newMtr;
	int i,j,n,m,non0;
	non0=0;
	
	printf("Enter number of row:  "); scanf("%d",&n);
	printf("\nEnter number of column:  "); scanf("%d",&m);
	
	mtr=(int **) malloc(n*sizeof(int *));
	
	for (i=0;i<n;i++){
		mtr[i]=(int *) malloc ( m* sizeof( int ));
	}
	
	for (i=0;i<n;i++){
		printf("\nEnter values of %d th row\n\t",i);
		for (j=0;j<m;j++){
			scanf("%d",&mtr[i][j]);
			printf("\t");
			
		}
	}
	
	printf("This is the matrix that you entered:\n");
	
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf("%3d",mtr[i][j]);		
		}
		printf("\n");
	}
	
	
	newMtr=reOrganize(mtr,n,m,&non0);
	
		printf("Arranged matrix :\n");
	for (i=0;i<non0;i++){
		for (j=0;j<3;j++){
	
		printf("%3d",newMtr[i][j]);			//Shows that expect 0 values and its destination.
											//first column is i values ; second j ; third mtr value.

		}
	printf("\n");
	
}
	
	
	return 0;
}
