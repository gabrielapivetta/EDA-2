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
	
	for(int i=l+1; i<=r; i++){
		for(int j=i; j>l; j--){
			if(less(&v[j], &v[j-1]))	
				exch(&v[j], &v[j-1]);
		}
	}
}

int main (){
	
	int v[1000], num, tam=0;
	while(scanf("%d", &num)!=EOF)
		v[tam++] = num;
		
	insertion_sort(v, 0, tam-1);
	
	for(int j=0; j<tam; j++)	
		printf("%d ", v[j]);
	printf("\n");

return 0;
}
