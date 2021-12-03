#include<stdio.h> 

int main()
{       

    int day, mon, year, numberDates, cont;
    char *months[] = {
                        "janeiro", "fevereiro", "marco", "abril",
                        "maio", "junho", "julho", "agosto", 
                        "setembro", "outubro", "novembro", "dezembro",
                      };

    scanf("%d", &numberDates);

    for (cont = 0 ; cont < numberDates ; cont++){

        scanf("%d/%d/%d", &day, &mon, &year);

        if (day > 31 || day <1 || mon > 12 || mon < 1 || year < 1){
            printf("\nDATA INVALIDA");
            continue;
        }
            else if (
                    day > 30 && (mon==2 || mon==4 || mon==6 || mon==9 || mon==11 || (mon == 2 && day > 29))
                    
                ){
                printf("\nDATA INVALIDA");
                continue;
            }

        if(mon == 2 && day == 29){
            if (year%400 == 0 || (year%4 == 0 && year%100 != 0)){
                printf("\n%d de %s de %d", day, months[mon - 1], year);
                continue;
            }
                else{
                printf("\nDATA INVALIDA");
                continue;
                }
            }
    
            printf("\n%.2d de %s de %.4d", day, months[mon - 1], year);

    }

    return 0;
}