#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     

void desespaw(int *vida, int *cont, celula vet[]){
    *cont = 0;
    *vida = (*vida-1);
                
    if(*vida != 0){
        int i = BUSCA_I(vet, 'C', 301);
        int j = BUSCA_J(vet, 'C', 301);
        vet[ (i*30)+j ].corpo = '|';
        vet[ (i*30)+j ].ordem = 0;
    }

    if(*vida == 0){
        system("stty echo;");
        system("clear");

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 30; j++){
                printf("%c ", vet[  (i*30)+j  ].corpo);
            }
            printf("\n");
        }
        printf("VOCE MATOU A COBRINHA DE FOME\n");
        printf("ESPERE 5 SEGUNDOS\n");
        sleep(5);
    }
}




























