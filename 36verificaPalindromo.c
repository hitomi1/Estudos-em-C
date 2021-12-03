#include "stdio.h"

int main(){

    //Variáveis
    int numero, reverso = 0, num_aux, aux;
    
    //Scanner
    scanf("%d",&numero);

    //Primeira verificação de palindromo eh ser divisivel por 11
    if (numero%11 == 0){
        printf("SIM E DIVISIVEL POR 11\n");
        return 0;
    }

    //Guarda o valor inicial
    num_aux = numero;

    //Inverte o numero inicial
    while (num_aux >0){
        aux = num_aux % 10;
        //printf("\n%d %d\n", num_aux, aux);
        reverso = reverso * 10 + aux;
        num_aux = num_aux / 10;
        //printf("%d %d\n", num_aux, reverso);
    }

    //Verifica se e palindromo, inicial = reverso
    if (numero == reverso){
        printf("SIM\n");
    }
        else {
            printf("NAO\n");
        }
    return 0;

}