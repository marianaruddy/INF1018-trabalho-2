/*Esse arquivo deve conter as funções geracod e liberacod (e funções auxiliares, se for 
o caso).
Esse arquivo não deve conter a função main. */


/*FUNCAO GERACOD:
le um arquivo de entrada contendo o código fonte uma função na linguagem 
SB, gere o código de máquina correspondente, e retorne o endereço 
da região de memória que contém o código gerado (um bloco de memória 
alocado dinamicamente). O arquivo de entrada terá no máximo 
20 linhas, com um comando SB por linha.

O parâmetro f é o descritor de um arquivo texto, já aberto para leitura, 
de onde deve ser lido o código fonte da função escrita em SB. 

Implementacao:
deve alocar um bloco de memória onde armazenará o código gerado (lembre-se que as 
instruções de máquina ocupam um número variável de bytes na memória!). O endereço 
retornado por geracod será o endereço do início da memória alocada.

Para cada instrução SB imagine qual uma tradução possível para assembly. Além disso, 
lembre-se que a tradução de uma função SB deve começar com o prólogo usual (preparação 
do registro de ativação, incluindo o espaço para variáveis locais) e terminar com a 
finalização padrão (liberação do registro de ativação antes do retorno da função).

O código gerado deverá seguir as convenções de C/Linux quanto à passagem de parâmetros 
e valor de retorno. As variáveis locais deverão ser alocadas na pilha de execução.

Para ler e interpretar cada linha da linguagem SB, teste se a linha contém cada um dos 
formatos possíveis.

Não é necessário fazer tratamento de erros no arquivo de entrada, você pode supor que o 
código fonte SB desse arquivo sempre estará correto. 

O código gerado por geracod deverá ser um código de máquina x86-64, e não um código 
fonte assembly. Ou seja, você deverá descobrir o código de máquina que corresponde às 
instruções de assembly que implementam a tradução das instruções da linguagem SB. Para 
isso, você pode usar o programa objdump e, se necessário, uma documentação das 
instruções da Intel.

Por exemplo, para descobrir o código gerado por movl %eax, %ecx, você pode criar um 
arquivo meuteste.s contendo apenas essa instrução, traduzi-lo com o gcc (usando a opção 
-c) para gerar um arquivo objeto meuteste.o para ver o código de máquina gerado. 

Estratégia de Implementação:
Implemente sua solução passo a passo, testando cada passo implementado!

Por exemplo:

    Compile um arquivo assembly contendo uma função bem simples (por exemplo, uma função 
    que retorne o valor do seu parâmetro) usando:

    $ minhamaquina> gcc -c code.s

    e depois veja o código de máquina gerado usando:

    $ minhamaquina> objdump -d code.o

    Construa uma versão inicial da função geracod, que aloque uma área de memória, 
    coloque lá esse código, bem conhecido, e retorne o endereço da área alocada.

    Crie uma função main e teste esse primeiro passo.

    Implemente e teste a tradução da função SB equivalente:

    ret p1

    Pense em que informações você precisa extrair para poder traduzir as instruções 
    (quais são os operandos, qual é a operação, onde armazenar o resultado da operação).

    Continue sua implementação, implementando e testando uma instrução por vez. 
    Experimente usar constantes, parâmetros, variáveis locais, e combinações desses 
    tipos como operandos.

    Lembre-se que é necessário alocar espaço (na pilha) para as variáveis locais!

    Deixe para implementar a instrução de desvio apenas quando todo o resto estiver 
    funcionando!

    Pense em que informações você precisa guardar para traduzir essas instruções 
    (note que você precisa saber qual o endereço da instrução correspondente à linha 
    para onde o controle deve ser desviado...) 
*/


/*FUNCAO LIBERACOD:
responsável por liberar a memória 
alocada para armazenamento do código 
de máquina.
*/

/*************************** INICIO ***************************/

/* Heloisa Pessoa Matricula 3WA */ /*COMPLETA SEUS DADOS AQUI*/
/* Mariana Medeiros Ruddy Santos 1611397 3WA */

#include <stdlib.h>
#include <string.h>
// #include <conio.h> /*funcao getch()*/


    // system("gcc -c code.s");
    // system("objdump -d code.o");
 

#include <stdio.h>
#include "geracod.h"

funcp geracod(FILE *f){
    // funcp a;
    funcp array [3];
    array[0] = 0x89;
    array[1] = 0xf8;
    array[2] = 0xc3;
    return array;
}
void liberacod(void *pf){
    free(pf); /*??*/
}
int main (void){
    return 0;
}

// int main(int argc, char *argv[]) {
//   FILE *myfp;
//     funcp funcaoSB;
//     // int res;

//     /* Abre o arquivo fonte */
//     if ((myfp = fopen("programa", "r")) == NULL) {
//         perror("Falha na abertura do arquivo fonte");
//         exit(1);
//     }
//     /* compila a função SB */
//     funcaoSB = geracod(myfp);
//   fclose(myfp);

//   /* chama a função */
// //   res = (*funcaoSB) (/*....*/);  /* passando parâmetro apropriados */
// //   ...
//   liberacod(funcaoSB);
// //   ...

//     return 0;
// }
