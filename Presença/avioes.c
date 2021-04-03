#include <stdio.h>


void check(int *aeroporto, int *a){
	int biggest = aeroporto[1];
	int count=0, biggest_index=1;
	
	for(int i=2; i<=*a; i++){
		if(aeroporto[i] > aeroporto[i-1] && aeroporto[i] > biggest){
			biggest = aeroporto[i];
			biggest_index = i;
		}
	}
	
	printf("%d ", biggest_index);
		for(int i = biggest_index+1; i<=*a; i++){
			if(aeroporto[i]==biggest)
				printf("%d ", i);
		}
	
	printf("\n");
}

int main(){
	int a=0, v=0, aeroporto[101]={0}, rounds=0;
	int a1, a2;
	scanf("%d %d", &a, &v);
	while(a !=0 && v !=0){
		rounds++;
		for(int i=0; i<v; i++){
			scanf("%d %d", &a1, &a2);
			aeroporto[a1]++;
			aeroporto[a2]++;
		}

		printf("Teste %d\n", rounds);
		check(&aeroporto[0], &a);
		for(int i =0; i<=a; i++)
			aeroporto[i] = 0;
		scanf("%d %d", &a, &v);
	}
		
return 0;
}
