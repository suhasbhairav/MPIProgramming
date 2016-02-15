#include <stdio.h>
void temp(int* x){

	printf("%p -- %d\n",(void*)x, *x);


}


void temp_arr(int* b){
	int i=0;
	for(i=0;i<4;i++){
		printf("%d\n",*(b+i));
	}


}

void another_pointer_arr(int* b){
	int i=0;
	for(i=0;i<4;i++){
		printf("%d\n",*(b+i));

	}


}

void two_dimensional_pointer_arr(int *x[2][2]){
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\n", *(*(x+i)+j));
		}
	}




}
int main(int argc, char** argv){
	int a;
	int *p;
	a = 100;
	p =&a;
	printf("a=%d,p=%p, *p=%d, &a=%p\n", a,(void *)p, *p, (void *)&a);
	temp(&a);
	int arr[4]={1,2,3,4};
	temp_arr(&arr[0]);
	int b[4]={7,8,9,10};
	another_pointer_arr(&b[0]);
	int *c[2][2]={
			{1,2},
			{3,4}
			};
	two_dimensional_pointer_arr(c);
}
