#ifndef AUMENTAR_H
#define AUMENTAR_H

#include "struct.h"
#include "BUSCA.h"

void aumentar(celula vet[], int *tamanho_da_cobrinha){
    int linha_da_maca = BUSCA_I(vet, 301);
    int tam = (*tamanho_da_cobrinha);
    tam--;

    if(linha_da_maca == -1){

        int i = BUSCA_I(vet, tam);
        int j = BUSCA_J(vet, tam);
        char direcao = vet[  (i*30) + j  ].direcao_do_rabo;
        if(direcao == 'w'){
            if(i != 9){
                vet[  (i+1)*(30) + j  ].corpo = 'o';
                vet[  (i+1)*(30) + j  ].ordem = tam+1;
                vet[  (i+1)*(30) + j  ].direcao_do_rabo = direcao;
              
            }else{
                vet[j].corpo = 'o';
                vet[j].ordem = tam+1;
                vet[j].direcao_do_rabo = direcao;
            }
        }else if(direcao == 'd'){
            if(j != 0){
                vet[  (i*30) + (j-1)  ].corpo = 'o';
                vet[  (i*30) + (j-1)  ].ordem = tam+1;
                vet[  (i*30) + (j-1)  ].direcao_do_rabo = direcao;
            }else{
                vet[ (i*30) + 29 ].corpo = 'o';
                vet[ (i*30) + 29 ].ordem = tam+1;
                vet[ (i*30) + 29 ].direcao_do_rabo = direcao;
            }
        }else if(direcao == 'a'){
            if(j != 29){
                vet[  (i*30) + (j+1) ].corpo = 'o';
                vet[  (i*30) + (j+1) ].ordem = tam+1;
                vet[  (i*30) + (j+1) ].direcao_do_rabo = direcao;
            }else{
                vet[(i*30)].corpo = 'o';
                vet[(i*30)].ordem = tam+1;
                vet[(i*30)].direcao_do_rabo = direcao;
            }
        }else{
            if(i != 0){
                vet[  (i-1)*30 + j ].corpo = 'o';
                vet[  (i-1)*30 + j ].ordem = tam+1;
                vet[  (i-1)*30 + j ].direcao_do_rabo = direcao;
            }else{
                vet[ (9*30) + j ].corpo = 'o';
                vet[ (9*30) + j ].ordem = tam+1;
                vet[ (9*30) + j ].direcao_do_rabo = direcao;
            }
        }

        *tamanho_da_cobrinha = (*tamanho_da_cobrinha+1);
        
    }
    
}

#endif