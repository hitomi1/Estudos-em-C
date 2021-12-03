#include "stdio.h"

int main(){

    //Variáveis
    float temp[7], soma, media;
    int cont, diasAcima = 0;
    

    // Scanner e calculo da soma
    for (cont = 0; cont <7; cont++) {
        scanf("%f", &temp[cont]);
        soma = soma + temp[cont];
    }

    //Calculo da media
    media = soma/7;

    //Compara os valores com a media e adiciona na quantidade de dias
    for (cont = 0; cont <7; cont++) {
        //printf("%.1f > %.1f\n", temp[cont], media);
        if (temp[cont]>media) {
            diasAcima++;
        }
    }

    printf("%d\n", diasAcima);

    return 0;

}
