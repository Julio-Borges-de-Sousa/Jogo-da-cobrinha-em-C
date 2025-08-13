#include <stdio.h>
#include <stdlib.h>  
#include <unistd.h>   
void receber(char *direcao){
     do{
        system("bash -c 'read -n1 -t 0.2 var && printf \"%s\" \"$var\" > keytmp'; ");
        FILE *fp;
        fp = fopen("keytmp", "r");
        *direcao = fgetc(fp);
        fclose(fp);
    }while(*direcao != 'w' && *direcao != 'd' && *direcao != 'a' && *direcao != 's');
}