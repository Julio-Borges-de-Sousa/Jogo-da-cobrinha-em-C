#ifndef BUSCA_H
#define BUSCA_H

#include "struct.h"

int BUSCA_I(celula vet[], int ordem){
    int I = -1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 30; j++){
            if(vet[(i*30)+j].ordem == ordem){
                I = i;
                i = 10;
                j = 30;
            }
        }
    }
    return I;
}

int BUSCA_J(celula vet[], int ordem){
    int J = -1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 30; j++){
            if( vet[(i*30)+j].ordem == ordem ){
                J = j;
                i = 10;
                j = 30;
            }
        }
    }
    return J;
}

#endif