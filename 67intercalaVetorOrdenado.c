#include<stdio.h>
#include<stdlib.h>

int main(){
    //Le o tamanho do vetor 1
    int N, cont;
    scanf("%d", &N);

    //Preenche o vetor 1 com valores
    int vetorA[N];
    for(cont = 0; cont < N; cont++){
        scanf("%d", &vetorA[cont]);
    }

    //Le o tamanho do vetor 2
    int M;
    scanf("%d", &M);

    //Preenche o vetor 2 com valores   
    int vetorB[M];
    for(cont = 0; cont < M; cont++){
        scanf("%d", &vetorB[cont]);
    }

    //Cria o vetor C que sera o vetor 1+@
    int *vetorC;
    int j = 0;
    int k = 0;

    //Aloca memoria do vetor C
    vetorC = (int *)(malloc((N+M) * sizeof(int)));

    //Verifica se não há erros ao alocar memória
    if(vetorC == NULL){
        printf("\n Erro ao alocar memoria");
        system("pause");
        exit(1);
    }

    //Verifica se um dos vetores já chegou ao fim e começa a pular as verificações
    for(int i = 0; i < (M + N); i++){
        if (j == N) {
            // vetorA esgotado
            vetorC[i] = vetorB[k];
            k++;
        } else if (k == M) {
            // vetorB esgotado
            vetorC[i] = vetorA[j];
            j++;
            //Compara o valor dos vetores e insere no vetor C
        } else if (vetorA[j] <= vetorB[k]) {
            vetorC[i] = vetorA[j];
            j++;
        } else if (vetorB[k] < vetorA[j]){
            vetorC[i] = vetorB[k];
            k++;
        }
    }

    //Printa o vetor C
    for(int i = 0; i < (M + N); i++){
    printf("%d ", vetorC[i]);
  }
  printf("\n");
  //Libera espaço na memória
  free(vetorC);

}