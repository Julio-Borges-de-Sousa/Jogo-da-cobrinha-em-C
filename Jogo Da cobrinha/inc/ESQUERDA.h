void ESQUERDA(celula vet[], int I, int J, char corpo, int *vida, int ordem){
    vet[  (I*30)+J  ].corpo = '|';
    vet[  (I*30)+J  ].ordem = -1;
    vet[  (I*30)+J  ].direcao_do_rabo = 0;
    if(J != 0){
        if( (vet[ (I*30)+(J-1) ].corpo == 'C') && (corpo == 'O') )*vida = (*vida+1);
        if( (vet[ (I*30)+(J-1) ].corpo == 'o') && (corpo == 'O') )*vida = 0;
        vet[ (I*30)+(J-1) ].corpo = corpo;
        if(corpo == 'o'){
            vet[ (I*30)+(J-1) ].ordem = ordem;
            vet[ (I*30)+(J-1) ].direcao_do_rabo = 'a';
        }
        else{
            vet[ (I*30)+(J-1) ].ordem = 0;
            vet[ (I*30)+(J-1) ].direcao_do_rabo = 0;
        }
    }else{
        if( (vet[  (I*30)+(29)  ].corpo == 'C') && (corpo == 'O') )*vida = (*vida+1);
        if( (vet[  (I*30)+(29)  ].corpo == 'o') && (corpo == 'O') )*vida = 0;
        vet[  (I*30)+(29)  ].corpo = corpo;
        if(corpo == 'o'){
            vet[  (I*30)+(29)  ].ordem = ordem;
            vet[  (I*30)+(29)  ].direcao_do_rabo = 'a';
        }else{
            vet[  (I*30)+(29)  ].ordem = 0;
            vet[  (I*30)+(29)  ].direcao_do_rabo = 0;
        }
    }
}