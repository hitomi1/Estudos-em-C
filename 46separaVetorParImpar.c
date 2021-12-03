#include "stdio.h"
#include "stdlib.h"

int main(){

    //Variáveis
    int tam, cont, numpar = 0, numimpar=0;

    //Scanner
    scanf("%d", &tam);
    
    //Atribuindo tamanho do vetor que ira ser lido
    int vet[tam];

    //Definindo tamanho dos vetores par e impar
    for (cont = 0; cont < tam; cont++){
        scanf("%d", &vet[cont]);
        if (vet[cont]%2==0){
            numpar++;
        }
        else {
            numimpar++;
        }
    }

    //Seta o tamanho dos vetores par e impar e também um novo contador
    int par[numpar], impar[numimpar], cont1=0, cont2=0; 

    //Atribui os valores aos vetores par e impar
    for (cont = 0; cont < tam; cont++){
        if (vet[cont]%2==0){
            par[cont1] = vet[cont];
            cont1 = cont1+1;
        }
        else {
            impar[cont2] = vet[cont];
            cont2 = cont2+1;
        }
    }
    //Printa o vetor par
    for (cont = 0; cont < cont1; cont++){
        printf("%d ", par[cont]);
    }
    printf("\n");
    //Printa o vetor impar
    for (cont = 0; cont < cont2; cont++){
        printf("%d ", impar[cont]);
    }

    return 0;

}