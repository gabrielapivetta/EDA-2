#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int x, int n, int *v){
	int e = -1; 
	int d = n;
	while(e < d-1){
		int m = (e+d)/2;
		if(v[m] == x)
			return m;
		else if(v[m] < x) 
			e = m;
		else
			d = m;
	}
	return d;
}

int main(){
	int n, m, *v, check;
	scanf("%d %d", &n, &m);
	v = malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
		scanf("%d", &v[i]);
		
	for(int i=0; i<m; i++){
		scanf("%d", &check);
		check = busca_binaria(check, n, v);
		printf("%d\n", check);
	}

return 0;
}
