#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Variaveis necessarias para usar o metódo getline
    char *line = NULL;  // forca o getline a alocar memoria com malloc
    size_t len = 0;     // ignora quando line = NULL
    ssize_t read;       // variavel usada para não usar implicito na getline

    printf ("\nEscreva a molécula abaixo\n");

    //Le a string
    read = getline(&line, &len, stdin);

    //Cria uma string do mesmo tamanho 
    char complementar[strlen(line)-1];
    
    //Preenche a string complementar baseado no valor da string de entrada
    for (int i = 0; i < (strlen(line)); i++){

        if (line[i] == 'T'){
            complementar[i] = 'A';
        }
        else if (line[i] == 'A'){
            complementar[i] = 'T';
        }
        else if (line[i] == 'C'){
            complementar[i] = 'G';
        }
        else if (line[i] == 'G'){
            complementar[i] = 'C';
        }

    }

    //Imprime a string de entrada
    printf ("%s", line);

    //Imprime a string complementar
    printf("%s\n", complementar);

    // Libera a memória alocada pelo getline
    free (line);  
  
  	
} 