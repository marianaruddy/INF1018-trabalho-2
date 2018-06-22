#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "geracod.h"

#define codMaqRet 0xc3
#define codMaqGo 1    //valor de teste
#define codMaqIf 1    //valor de teste
#define codMaqVar 1   //valor de teste
#define codMaqP 1     //valor de teste
#define codMaqId 1    //valor de teste
#define codMaqLn 1    //valor de teste
#define codMaq 1      //valor de teste


static void error (const char *msg, int line) {
    fprintf(stderr, "erro %s na linha %d\n", msg, line);
    exit(EXIT_FAILURE);
}


void leSB (FILE *myfp, unsigned char* array){
    int line = 1;
    int  c;     //pq int e nao char?
    int posicaoArray = 0;
    if ((myfp = fopen ("programa", "r")) == NULL) {
        perror ("nao conseguiu abrir arquivo!");
        exit(1);
    }

    while ((c = fgetc(myfp)) != EOF) {
        switch (c) {
        case 'r': { /* retorno */
            char var0;
            int idx0;
            if (fscanf(myfp, "et %c%d", &var0, &idx0) != 2){
                error("comando invalido", line);
            }
            else{
                array[posicaoArray] = codMaqRet;
                posicaoArray++;
                array[posicaoArray] = codMaqVar;
                posicaoArray++;
                array[posicaoArray] = codMaqId; //???
                posicaoArray++;
            }
            break;      //precisa??

        }
        case 'v':           //nada??
        case 'p': { /* atribuiÃ§Ã£o e op. aritmetica */
            char var0 = c, var1, op;
            int idx0, idx1;

            if (fscanf(myfp, "%d %c= %c%d", &idx0, &op, &var1, &idx1) != 4){
                error("comando invalido", line);
            }
            else{
                array[posicaoArray] = codMaqId;
                posicaoArray++;
                array[posicaoArray] = codMaqId;
                posicaoArray++;
                array[posicaoArray] = codMaqVar;
                posicaoArray++;
                array[posicaoArray] = codMaqId;
                posicaoArray++;
            }
            break;          //precisa??
        }
        case 'i': { /* desvio condicional */
            char var0;
            int idx0, n1, n2;
            if (fscanf(myfp, "f %c%d %d %d", &var0, &idx0, &n1, &n2) != 4){
                error("comando invalido", line);
            }
            else{
                array[posicaoArray] = codMaqIf;
                posicaoArray++;
                array[posicaoArray] = codMaqVar;
                posicaoArray++;
                array[posicaoArray] = codMaqP;
                posicaoArray++;
                array[posicaoArray] = codMaqLn;
                posicaoArray++;
                array[posicaoArray] = codMaqLn;
                posicaoArray++;

            }
            break;          //precisa??
        }
        case 'g': { /* desvio incondicional */
            int n1;
            if (fscanf(myfp, "o %d", &n1) != 1){
                error("comando invalido", line);
            }
            else{
                array[posicaoArray] = codMaqGo;
                posicaoArray++;
                array[posicaoArray] = codMaqLn;
                posicaoArray++;

            }
            break; //precisa??
        }
        default: error("comando desconhecido", line);
        }
        line ++;
        fscanf(myfp, " ");
    }

}


int main (void) {
    FILE *myfp;
    unsigned char* array  = malloc((10*20)*sizeof(char)); /*10: tamanho arbitrario	20: num max de linhas*/
    
  
  return 0;
}
