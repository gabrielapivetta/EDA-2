#include <stdio.h>  
#include <stdlib.h>

int *intercala_sort(int *a, int la, int ra, int *b, int lb, int rb){
	int ta = (ra-la+1);
	int tb = (rb-lb+1);
	int *c = malloc(sizeof(int)*(ta+tb));
	int lc=0;
	int rc=(ta+tb-1); 
	int ia = la;
	int ib = lb;
	int ic = 0;
	
	while(ia<=ra && ib<=rb){
		if(a[ia] <= b[ib])
			c[ic++] = a[ia++];
		else
			c[ic++] = b[ib++];
	}
	while(ia<=ra)
		c[ic++] = a[ia++];
	while(ib<=rb)
		c[ic++] = b[ib++];
		
	return c;
}

int main() {
	
	int loops = 8, leituras, *v_temp, *v_total, len_total=0;
	
	while(loops>=1){
		scanf("%d", &leituras);
		if(leituras!=0){
			v_temp = malloc (leituras * sizeof(int));
			for(int i=0; i<leituras; i++)
				scanf("%d", &v_temp[i]);
			
			if(loops==8){
				v_total = v_temp;
				printf(" vtotal = ");
				for(int i=0; i<leituras; i++)
					printf("%d ", v_total[i]);
			}
			else{
				v_total = intercala_sort(v_total, 0, len_total-1, v_temp, 0, leituras-1);
				printf("\n");
				printf(" vtotal 2 = ");
				for(int i=0; i<len_total+leituras; i++)
					printf("%d ", v_total[i]);
			}
			len_total += leituras;
			printf("\n Len Total: %d \n", len_total);
			free(v_temp);	
		}
		loops--;
	}
	printf("Total:\n");
	for(int i=0; i<len_total; i++)
		printf("%d ", v_total[i]);
	
return 0;
}







