#include <stdio.h>

void exch(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int *v, int left, int right){
	for(int i=left; i<right; i++)
		for(int j=left+1; j<=right; j++)
			if (v[j] > v[j+1]) 
              exch(&v[j], &v[j+1]);
}

int main(){

	int v[1000], num, tam=0;
	while(scanf("%d", &num)!=EOF)
		v[tam++] = num;
		
	bubble_sort(v, -1, tam-2);
	
	for(int j=0; j<tam; j++)	
		printf("%d ", v[j]);
	printf("\n");
	
return 0;
}
