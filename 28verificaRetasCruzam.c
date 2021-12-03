#include "stdio.h"

int main(){

    //Variáveis start1 = ponto inicial, vel = velocidade, startdiff = diferenca posicao inicial
    int start1, start2, startdiff;
    int vel1, vel2, veldiff;
    int cruzamentoint, cruzamentoPositivo;
    
    //Scanner
    scanf("%d %d",&start1, &vel1);
    scanf("%d %d",&start2, &vel2);

    startdiff = start1-start2;  //Diferença entre as posições iniciais 
    veldiff = vel1 - vel2;      //Diferença entre as velocidades iniciais
    if (veldiff == 0 && startdiff != 0) {
        return (printf("NAO\n"));
    }
    //Calcula se o momento que eles cruzam é inteiro
    cruzamentoint = startdiff%(veldiff*(-1));
    //Calcula se o momento que eles cruzam é valido, ou seja >0
    cruzamentoPositivo = startdiff/(veldiff*(-1));
    
    //Faz as verificações
    if (cruzamentoint == 0 && cruzamentoPositivo >0){
        printf ("SIM\n");
        }
        else {
        printf ("NAO\n");
        } 
            
    return 0;

}