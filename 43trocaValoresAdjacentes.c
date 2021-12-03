#include "stdio.h"
#include "stdlib.h"

int main(){

    //Variáveis
    int tam, cont, aux;

    //Scanner
    scanf("%d", &tam);

    //Define o tamanho do vetor
    int vet[tam];

    //Atribui valores para o vetor
    for (cont = 0; cont < tam; cont++){
        scanf("%d", &vet[cont]);
    }
    
    cont = 0;
    if (tam%2 == 0){ //Se o vetor for par ele vai trocar de par em par o vetor de lugar
        while (cont < tam){
        aux = vet[cont];
        vet[cont] = vet[cont + 1];
        vet[cont+1] = aux;
        cont = cont + 2;
        } 
    }
    
    else { //Se o vetor for impar ele vai trocar de par em par o vetor de lugar, menos o ultimo valor
        while (cont < tam-1){
        aux = vet[cont];
        vet[cont] = vet[cont + 1];
        vet[cont+1] = aux;
        cont = cont + 2;
        } 

    }

    //Imprime vetor
    for (cont = 0; cont < tam; cont++){
        printf("%d ", vet[cont]);
    }
    return 0;

}