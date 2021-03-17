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

void quicksort(int *v, int l, int r){
	int j;
	if(r<=l) return;
	
	cmp_exch(&v[l+r/2], &v[r]);
	cmp_exch(&v[l], &v[l+r/2]);
	cmp_exch(&v[r], &v[l+r/2]);
	
	j = separa(v, l, r);
	quicksort(v, l, j-1);
	quicksort(v, j+1, l);
}

int find_color(int *v, int n){
	int rep=0, rep_aux=0, cor, i;
	for(i=1; i<n; i++){
		if(v[i]==v[i-1]){
			rep_aux++;
		}
		else{
			if(rep_aux>rep){
				rep = rep_aux;
				cor = v[i-1];
			}
			rep_aux = 0;
		}
	}
	if(rep_aux>rep){
		rep = rep_aux;
		cor = v[i-1];
	}
	return cor;
}

int main(){

	int n=0, v[5000];
	scanf("%d", &n);	
	while(n!=0){	
		for(int i=0; i<n; i++){
			scanf("%d", &v[i]);
		}
		quicksort(&v[0], 0, n-1);
		int cor = find_color(&v[0], n);
		
		printf("%d\n", cor);
		scanf("%d", &n);
	}

return 0;
}
