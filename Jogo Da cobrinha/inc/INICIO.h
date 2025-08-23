#include <stdlib.h>  

void INICIO(celula vet[]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 30; j++){
            vet[ (i*30) + j].corpo = '|';
            vet[ (i*30) + j].ordem = -1;
            vet[ (i*30) + j].direcao_do_rabo = 0;
        }
    }    
    
    vet[ (9*30) ].corpo = 'o';
    vet[ (9*30) ].ordem = 1;
    vet[ (9*30) ].direcao_do_rabo = 'd';

    vet[ (9*30) + 1].corpo = 'O';
    vet[ (9*30) + 1].ordem = 0;
    vet[ (9*30) + 1].direcao_do_rabo = 0;

    system("stty -echo;");
}