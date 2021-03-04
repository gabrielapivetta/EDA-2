#include <stdio.h>  

int less(int *a, int *b){
	return *a < *b;
}

void exch(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void insertion_sort(int *v, int l, int r){
	
	for(int i=r; i>l; i--){
		if(less(&v[i], &v[i-1]))	
			exch(&v[i], &v[i-1]);
	}
	for(int i=l+2; i<=r; i++){
		int j=i;
		int tmp=v[j];
		while(less(&tmp,&v[j-1])){
			v[j] = v[j-1];
			j--;
		}
		v[j]=tmp;
	}
} 

int main (){
	
	int v[50000], num, tam=0;
	while(scanf("%d", &num)!=EOF)
		v[tam++] = num;
		
	insertion_sort(v, 0, tam-1);
	
	for(int j=0; j<tam; j++)	
		printf("%d ", v[j]);
	printf("\n");

return 0;
}
