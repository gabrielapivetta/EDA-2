#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r){
	int *c=malloc(sizeof(int)*(r-l+1));
	int i=l,j=m+1,k=0;

	while(i<=m && j<=r){
	    if(v[i] <= v[j])
		    c[k++]=v[i++];
    	else
    		c[k++]=v[j++];
  	}

  	while(i<=m)
    	c[k++]=v[i++];
  	while(j<=r)
      	c[k++]=v[j++];

  	k=0;
  	for(i=l;i<=r;i++)
    	v[i]=c[k++];
  	free(c);
}

void merge_sort(int *v, int l, int r){
	if(l>=r)return; //criterio de parada
	int m = (l+r)/2;
	
	merge_sort(v, l, m);
	merge_sort(v, m+1, r);
	
	merge(v, l, m, r);
}

int remove_repeated(int *v, int t, int *y){
	int j=0;
	for(int i=0;i<t;i++){
		if(v[i]!=v[i+1]){
			y[j++] = v[i];
		}
	}
	return j;
}

int busca_binaria(int *v, int n, int x){
	int e = -1; 
	int d = n;
	int m = 0;
	while(e < d-1){
		m = (e+d)/2;
		if(v[m] == x){
			return 1;
		}
		else if(v[m] < x) 
			e = m;
		else
			d = m;
	}
	if(v[d] == x || v[e]==x){
		return 1;
	}
	return -1;
}

int main(){

	int tam, tam2, *nums_malucos, nums2[131072];
	
	scanf("%d", &tam);
	nums_malucos = malloc (tam * sizeof(int));
	for(int i=0; i<tam; i++)
		scanf("%d", &nums_malucos[i]);
		
	merge_sort(nums_malucos, 0, tam-1);
	tam2 = remove_repeated(nums_malucos, tam, nums2);
	
	free(nums_malucos);
	
	if(tam2 %2 !=0)
		nums2[tam2++] = 1000000000;
	
	int tam2_aux = tam2;
	for(int i=0; i<tam2_aux; i+=2){
		int aux = nums2[i] + nums2[i+1];
		if(busca_binaria(nums2, tam2_aux, aux)<0){
			nums2[tam2++] = aux;
		}
	}
	
	merge_sort(nums2, 0, tam2-1);

	for(int i=0; i<tam2; i+=4)
		printf("%d\n", nums2[i]);
	
	printf("Elementos: %d\n", tam2);

return 0;
}
