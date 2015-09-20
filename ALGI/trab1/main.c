#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

#define debug 1

int main(){

/*-----Variaveis-----*/
char *entrada;

PILHA_DINAMICA *Pilha;

int i;

if(debug)
	printf("Insira os valores: ");
fegts("%s", &entrada);

for(i=0;entrada[i]!='\0';i++){
	//compara se a entrada é diferente de espaço
	if(entrada[i]!=' '){
		
	}
}

return 0;
}
