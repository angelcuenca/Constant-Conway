/*
 * 2014 Angel Emmanuel Sanchez Cuenca
 * Conway Constat
 *
 * The software was created by the person mentioned.
 * Guadalajara, Mexico
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char constante[20];
    char buffer[20];
    char seriesConway[20];
    int numero,c;
    int lenght,temp=0;
    int numeroEnCadena=0;
    int numeroEscribeCad=0;

    printf("Enter the initial number: ");
    fflush(stdin);
    gets(constante);
    strcpy(seriesConway,constante);

    printf("Enter the number of series: ");
    scanf("%d",&numero);

    for(c=0; c < numero ; c++){
        strcpy(constante,seriesConway);
        lenght=strlen(seriesConway);
        numeroEnCadena=0;
        numeroEscribeCad=0;

        while( lenght > 0 ){
            if( lenght == 1 && numeroEnCadena == 0){
                seriesConway[0]='1';
                seriesConway[1]=constante[0];
                seriesConway[2]='\0';
            }
            else{
                if( constante[numeroEnCadena] == constante[numeroEnCadena+1] && lenght!=1 ){
                    temp++;
                }
                else{
                    if(temp > 0){
                        itoa(temp+1,buffer,10);
                        seriesConway[numeroEscribeCad]= buffer[0];
                        numeroEscribeCad++;
                        seriesConway[numeroEscribeCad]= constante[numeroEnCadena];
                        numeroEscribeCad++;
                        temp=0;
                    }
                    else{
                        seriesConway[numeroEscribeCad]= '1';
                        numeroEscribeCad++;
                        seriesConway[numeroEscribeCad]= constante[numeroEnCadena];
                        numeroEscribeCad++;
                    }

                    if( lenght == 1){
                        seriesConway[numeroEscribeCad]= '\0';
                    }
                }
                numeroEnCadena++;
            }
            lenght--;

        }

        printf("\nSerie: %s",seriesConway);
    }

    return 0;
}
