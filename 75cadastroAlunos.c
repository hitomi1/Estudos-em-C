#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

struct ALUNOS{
    char nome[MAX];
    char sexo[MAX];
    char ra[MAX];
    char ingresso[MAX];
    char curso[MAX];
};
typedef struct ALUNOS Numero;

int main()
{
  Numero *p;
  int k = 1;

  p = (Numero*)malloc(k*sizeof(Numero));

  for (int x = 0; x < k; x++) {
    scanf("\n%[^\n]%*c", p[x].nome);
        if (strcmp(p[x].nome, "FIM")==0){
            break;
        }
        else{
            k++;
        }
    scanf("\n%[^\n]%*c", p[x].sexo);
        if (strcmp(p[x].sexo, "F")==0){
            strcpy(p[x].sexo, "Feminino");
        }
        else if (strcmp(p[x].sexo, "M")){
            strcpy(p[x].sexo, "Masculino");
        }
    scanf("\n%[^\n]%*c", p[x].ra);
    scanf("\n%[^\n]%*c", p[x].ingresso);
    scanf("\n%[^\n]%*c", p[x].curso);
  }


  
  for (int x = 0; x < k-1; x++) {
    
    printf("Registro %d:", x+1);
    printf ("\nNome: %s - Sexo: %s - RA: %s\n", p[x].nome, p[x].sexo, p[x].ra);
    printf ("Ingresso: %s - Curso: %s", p[x].ingresso, p[x].curso);
    printf ("\n==========\n");
    }
  
  return 0;
}

