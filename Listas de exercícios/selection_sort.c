#include <stdio.h>  

int less(int *a, int *b){
	return *a < *b;
}

void exch(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void selection_sort(int *v, int l, int r){
	
	for(int i=l; i<=r; i++){
		int min = i;
		for(int j=i+1; j<=r; j++){
			if(less(&v[j], &v[min]))
				min=j;
		}
		exch(&v[i], &v[min]);
	}
}

int main (){
	
	int v[1000], num, tam=0;
	while(scanf("%d", &num)!=EOF)
		v[tam++] = num;
		
	selection_sort(v, 0, tam-1);
	
	for(int j=0; j<tam; j++)	
		printf("%d ", v[j]);
	printf("\n");

return 0;
}
