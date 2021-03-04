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

int busca_binaria(int x, int n, int *v){
	int e = -1; 
	int d = n;
	while(e < d-1){
		int m = (e+d)/2;
		if(v[m] == x)
			return v[m];
		else if(v[m] < x) 
			e = m;
		else
			d = m;
	}
	return v[d];
}

int main(){
 
	int tam_num, *nums_proibidos, check;
	scanf("%d", &tam_num);
	nums_proibidos = malloc (tam_num * sizeof(int));
	for(int i=0; i<tam_num; i++)
		scanf("%d", &nums_proibidos[i]);
		
	merge_sort(nums_proibidos, 0, tam_num-1);
		
	while(scanf("%d", &check) != EOF){
		if(check == busca_binaria(check, tam_num, nums_proibidos))
			printf("sim\n");
		else
			printf("nao\n");
	}

return 0;
}
