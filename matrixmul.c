#include <stdio.h>

int main(int argc, char** argv){

	int a[3][3]= {
			{1,1,1},
			{2,2,2},
			{3,3,3}
			};
	int b[3][3]= {
			{1,2,3},
			{4,5,6},
			{7,8,9}
		};
	int c[3][3];
	int i,j,k,val;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				val+=a[i][k]*b[k][j];
				
			}
			c[i][j]=val;
			val=0;
			
		}	
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}


	return 0;
}
