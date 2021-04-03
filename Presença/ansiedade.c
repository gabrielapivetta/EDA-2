#include <stdio.h>
#include <string.h>

int main(){

	char word[4];
	int count=0, triagem=0, total_triagens=0;
	
	while(scanf("%s", word) != EOF){
		count++;
		if(strcmp(word,"sim")==0)
			triagem++;
		if(count==10){
			if(triagem>=2){
				total_triagens++;
			}
			count = 0;
			triagem = 0;
		}
	}
	printf("%d\n", total_triagens);

return 0;
}
