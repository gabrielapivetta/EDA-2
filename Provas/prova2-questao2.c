#include <stdio.h>
#include <stdlib.h>

typedef struct nota{
    int nota;
    int quantidade;
} nota;

int cmp(nota a, nota b){
    if (a.quantidade > b.quantidade)
        return 1;
        
    else if (a.quantidade == b.quantidade){
        if (a.nota > b.nota) return 1;
        else return 0;
    }
    return 0;
}

void exch(nota *a, nota *b){
    nota aux = *a;
    *a = *b;
    *b = aux;
}

void cmp_exch(nota *a, nota *b){
	if(a>b) exch(a, b);
}

int separa(nota *v, int l, int r){
    int aux_left = l-1;
    int aux_right = r;
    nota x = v[r];
    while(1){
        while(cmp(v[++aux_left], x));
        while(cmp(x, v[--aux_right])){
            if(aux_right == l)
                break;
        }
        if(aux_left >= aux_right)
            break;
        exch(&v[aux_left], &v[aux_right]);
    }
    exch(&v[aux_left], &v[r]);
    return aux_left;
}

void quick_sort(nota *v, int l, int r){
    if (r <= l) return;
    int j;
    
    cmp_exch(&v[l+r/2], &v[r]);
	cmp_exch(&v[l], &v[l+r/2]);
	cmp_exch(&v[r], &v[l+r/2]); 
	
    j = separa(v, l, r);
    quick_sort(v, l, j - 1);
    quick_sort(v, j + 1, r);
}


int main() {

	int n, aux;
    nota *notas = calloc(1000, sizeof(nota));
	while (scanf("%d", &n) != EOF){
    	for(int i=0; i<n; i++){
    		scanf("%d", &aux);
	    	notas[aux].nota = aux;
    	    notas[aux].quantidade++;
    	}
    }
    
    quick_sort(notas, 0, 1000);
	printf("%d\n", notas[0].nota);

return 0; 
}
