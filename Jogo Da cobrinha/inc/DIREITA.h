#ifndef DIREITA_H
#define DIREITA_H

#include "struct.h"

void DIREITA(celula vet[], int I, int J, char corpo, int *vida){
    vet[  (I*30)+J  ].corpo = '|';
    vet[  (I*30)+J  ].ordem = 0;
    vet[  (I*30)+J  ].direcao_do_rabo = 0;
    if(J != 29){
        if( (vet[  (I*30)+(J+1)  ].corpo == 'C') && (corpo == 'O') )*vida = (*vida+1);
        if( (vet[  (I*30)+(J+1)  ].corpo == 'o') && (corpo == 'O') )*vida = 0;
        vet[  (I*30)+(J+1)  ].corpo = corpo;
        if(corpo == 'o'){
            vet[  (I*30)+(J+1)  ].ordem = 1;
            vet[  (I*30)+(J+1)  ].direcao_do_rabo = 'd';
        }else{
            vet[  (I*30)+(J+1)  ].ordem = 0;
            vet[  (I*30)+(J+1)  ].direcao_do_rabo = 0;
        }
    }else{
        if( (vet[  (I*30)  ].corpo == 'C') && (corpo == 'O') )*vida = (*vida+1);
        if( (vet[  (I*30)  ].corpo == 'o') && (corpo == 'O') )*vida = 0;
        vet[I*30].corpo = corpo;
        if(corpo == 'o'){
            vet[I*30].ordem = 1;
            vet[I*30].direcao_do_rabo = 0;
        }else{
            vet[I*30].ordem = 0;
            vet[I*30].direcao_do_rabo = 0;
        }
    }
}

#endif