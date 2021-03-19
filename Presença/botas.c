#include <stdio.h>


void check_pair(int *l, int *r){
	int count=0;
	for(int i=0; i<65; i++){
		if(l[i] < r[i])
			count+=l[i];
		else
			count+=r[i];
	}
	printf("%d\n", count);
}

int main(){
	int tam=0, vet_left[65]={0}, vet_right[65]={0};
	char pe;
	while(scanf("%d %c", &tam, &pe) != EOF){
		if(pe == 'E')
			vet_left[tam]++;
			
		else if(pe == 'D')
			vet_right[tam]++;
	}
	
	check_pair(vet_left, vet_right);
	
return 0;
}
