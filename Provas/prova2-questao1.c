#include <stdio.h>
#include <stdlib.h>

void exch(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void cmp_exch(int *a, int *b){
	if(*a>*b) exch(a, b);
}

int separa(int *v, int l, int r){
	int c = v[r];
	int j=l;
	for(int k=l;k<r;k++){
		if(v[k] <= c){
			exch(&v[k], &v[j]);
			j++;
		}
	}
	exch(&v[j], &v[r]);
	return j;
}

void quick_select(int *v, int l, int r, int k){
	int i;
	if(r<=l) return;
	
	cmp_exch(&v[(l+r)/2], &v[r]);
	cmp_exch(&v[l], &v[(l+r)/2]);
	cmp_exch(&v[r], &v[(l+r)/2]);
	
	i = separa(v, l, r);
	if(i>k)
		quick_select(v, l, i-1, k);
	if(i<k)
		quick_select(v, i+1, r, k);
}

void quicksort(int *v, int l, int r){
	int j;
	if(r<=l) return;

	cmp_exch(&v[l+r/2], &v[r]);
	cmp_exch(&v[l], &v[l+r/2]);
	cmp_exch(&v[r], &v[l+r/2]);
	
	j = separa(v, l, r);
	quicksort(v, l, j-1);
	quicksort(v, j+1, r);
}

int main() {

	int n, p, x;
	scanf("%d %d %d", &n, &p, &x);
    int *v = malloc(n * sizeof(int));
	for(int i=0; i<n; i++){
    	scanf("%d", &v[i]);
    }
    
	int fim_p = p*x+x-1;
	if(fim_p >= n)
		fim_p = n-1;
    quick_select(v, 0, n-1, (fim_p));
    quick_select(v, 0, fim_p-1, (p*x));
    
    quicksort(v, p*x, fim_p);
    
    for(int i=p*x; i<=fim_p; i++){
    	printf("%d\n", v[i]);
    }

return 0; 
}
