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

int separa2(int *v, int left, int right){
    int i = left-1, j = right;
    int c = v[right];
    while(1){
        while(v[++i] < c);
        while(c < v[--j])
            if(j==left)
                break;
        if(i >= j)
            break;
        exch(&v[i], &v[j]);
    }
    exch(&v[i], &v[right]);
    return i;
}

void quicksort(int *v, int l, int r){
	int j;
	if(r<=l) return;

	cmp_exch(&v[l+r/2], &v[r]);
	cmp_exch(&v[l], &v[l+r/2]);
	cmp_exch(&v[r], &v[l+r/2]);
	
	j = separa2(v, l, r);
	quicksort(v, l, j-1);
	quicksort(v, j+1, r);
}

int main(){

	int n, *v;
	scanf("%d", &n);
	v = malloc(sizeof(int)*n);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}

	quicksort(v, 0, n-1);

	for(int i=0; i<n-1; i++)
		printf("%d ", v[i]);
	printf("%d\n", v[n-1]);

return 0;
}
