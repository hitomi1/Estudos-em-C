#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   //Variaveis
  	char str1[256], str2[256], aux;
  	int i, len1,len2, j;
   
   //Le as palavras que serao verificadas
   scanf("%[^\n]%*c", str1);
	printf("\n");
  	scanf("%[^\n]%*c", str2);
   
   //Le o tamanho do vetor
	len1 = strlen(str1);
	len2 = strlen(str2); 
	
   //Se o tamanho do vetor for diferente, então não é um anagrama
	 if(len1 != len2){
	    printf("0 - Não é um anagrama");
	    exit(0);
	 }
	 
    //Ordena as strings
	 for (i = 0; i < len1-1; i++) {
      for (j = i+1; j < len1; j++) {
         if (str1[i] > str1[j]) {
            aux = str1[i];
            str1[i] = str1[j];
            str1[j] = aux;
         }
         if (str2[i] > str2[j]) {
            aux = str2[i];
            str2[i] = str2[j];
            str2[j] = aux;
         }
      }
   }   
	
   //Verifica se a strings ordenadas tem todos os respectivos valores iguais, se um for diferente então não é um anagrama
	for(i = 0; i<len1; i++) {
      if(str1[i] != str2[i]) {    
         printf("0 - Não é um anagrama\n");
         return 0;
      }
   }    
	
  	printf("1 - É um anagrama\n");
  	
} 