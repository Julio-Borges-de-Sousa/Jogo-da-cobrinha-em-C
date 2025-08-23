#ifndef AUMENTAR_H
#define AUMENTAR_H

#include "struct.h"
#include "BUSCA.h"

void aumentar(celula vet[]){

    int i = BUSCA_I(vet, 1);
    int j = BUSCA_J(vet, 1);
    char direcao = vet[  (i*30) + j  ].direcao_do_rabo;
    if(direcao == 'w'){
        if(i != 9){
            vet[  (i+1)*(30) + j  ].corpo = 'o';
            vet[  (i+1)*(30) + j  ].ordem = 2;
        }else{
            vet[j].corpo = 'o';
            vet[j].ordem = 2;
        }
    }else if(direcao == 'd'){
        if(j != 0){
            vet[  (i*30) + (j-1)  ].corpo = 'o';
            vet[  (i*30) + (j-1)  ].ordem = 2;
        }else{
            vet[ (i*30) + 29 ].corpo = 'o';
            vet[ (i*30) + 29 ].ordem = 2;
        }
    }else if(direcao == 'a'){
        if(j != 29){
            vet[  (i*30) + (j+1) ].corpo = 'o';
            vet[  (i*30) + (j+1) ].ordem = 2;
        }else{
            vet[(i*30)].corpo = 'o';
            vet[(i*30)].ordem = 2;
        }
    }else{
        if(i != 0){
            vet[  (i-1)*30 + j ].corpo = 'o';
            vet[  (i-1)*30 + j ].ordem = 2;
        }else{
            vet[ (9*30) + j ].corpo = 'o';
            vet[ (9*30) + j ].ordem = 2;
        }
    }
}

#endif