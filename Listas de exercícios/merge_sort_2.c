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


int main(){
 
	int tam = 1, *nums_proibidos, temp;
	while(scanf("%d", &temp)==1){
		if(tam==1){
			nums_proibidos = malloc (tam * sizeof(int));
			nums_proibidos[tam++] = temp;
		}
		else{
			nums_proibidos = realloc (nums_proibidos, tam++);
			nums_proibidos[tam-1] = temp;	
		}
	}
	
	merge_sort(nums_proibidos, 0, tam-1);
		
	for(int i=0; i<tam; i++)
		printf("%d ", nums_proibidos[i]);

return 0;
}
