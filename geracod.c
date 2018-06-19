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


#include <string.h>
// #include <conio.h> /*funcao getch()*/


    // system("gcc -c code.s");
    // system("objdump -d code.o");
 

#include <stdio.h>
#include <stdlib.h>
#include "geracod.h"

#define codMaqRet 0xc3
#define codMaqGo
#define codMaqIf

 funcp geracod(FILE *f){
	unsigned char* array  = malloc((10*20)*sizeof(char)); /*10: tamanho arbitrario	20: num max de linhas*/
	int numLinha = 1, i = 0;
	while(leSB (f, numLinha) != NULL){
		array[i] = leSB (f, numLinha);
		i++;
	}
	funcp endereco = (funcp)array;
	return endereco;
 }



/*********** lendo o arquivo em SB ***********/
unsigned char* leSB (FILE *f, int numLinha){
	char comando;
	unsigned char* codMaq;
	if (fscanf(f, "%c",&comando) = "\n"){
		numLinha++;
	}
	else{

		switch (fscanf(f, "%c",&comando)){
			case 'ret':
				codMaq = codMaqRet;
				/*fscanf(f, " %c\n",&comando);*/	/*le o que retorna*/
			case 'if':
				codMaq = codMaqIf;
				/*fscanf(f, " %c",&comando);*/	/*le oq vai ser comparado com 0*/
				/*fscanf(f, " %c",&comando);*/	/*le linha do case se for menor que 0*/
				/*fscanf(f, " %c\n",&comando);*/	/*le linha do case se for igual a 0*/
			case 'go':
				codMaq = codMaqGo;
				/*fscanf(f, " %c\n",&comando);*/	/*le linha para onde vai pular*/
			case 'v':
	
				
				fscanf(f, "\n",&comando);
			case 'p':
	
	
				fscanf(f, "\n",&comando);
			default:
				printf("ERRO: COMANDO INVALIDO");
		}
	}
	return codMaq;	
}
	
/*********** lendo o arquivo em SB ***********/





/*interpretacao do arquivo em SB do prof*/
/*
static void error (const char *msg, int line) {
  fprintf(stderr, "erro %s na linha %d\n", msg, line);
  exit(EXIT_FAILURE);
}

int main (void) {
  int line = 1;
  int  c;
  FILE *myfp;

  if ((myfp = fopen ("programa", "r")) == NULL) {
    perror ("nao conseguiu abrir arquivo!");
    exit(1);
  }

  while ((c = fgetc(myfp)) != EOF) {
    switch (c) {
      case 'r': { /* retorno */
  /*      char var0;
        int idx0;
        if (fscanf(myfp, "et %c%d", &var0, &idx0) != 2)
          error("comando invalido", line);
        printf("%d ret %c%d\n", line, var0, idx0);
        break;
      }
      case 'v':
      case 'p': { /* atribuiÃ§Ã£o e op. aritmetica */
  /*      char var0 = c, var1, op;
        int idx0, idx1;

  /*      if (fscanf(myfp, "%d %c= %c%d", &idx0, &op, &var1, &idx1) != 4)
            error("comando invalido", line);
          printf("%d %c%d %c= %c%d\n", line, var0, idx0, op, var1, idx1);
        break;
      }
      case 'i': { /* desvio condicional */
    /*    char var0;
        int idx0, n1, n2;
        if (fscanf(myfp, "f %c%d %d %d", &var0, &idx0, &n1, &n2) != 4)
            error("comando invalido", line);
          printf("%d if %c%d %d %d\n", line, var0, idx0, n1, n2);
        break;
      }
      case 'g': { /* desvio incondicional */
    /*    int n1;
        if (fscanf(myfp, "o %d", &n1) != 1)
            error("comando invalido", line);
          printf("%d go %d\n", line, n1);
        break;
      }
      default: error("comando desconhecido", line);
    }
    line ++;
    fscanf(myfp, " ");
  }
  return 0;
}

*/








funcp geracodtest (){
    unsigned char* array  = malloc(3*sizeof(char));
    array[0] = 0x89; 
    array[1] = 0xf8;
    array[2] = 0xc3;
	funcp p = (funcp)array;
    /*
      0:	89 f8                	mov    %edi,%eax
      2:	c3                   	ret    
    */
         
    return p;
}

void liberacod(void *pf){
    free(pf); /*??*/
}
int main (void){
	funcp p = geracodtest();
    printf("end = %d\n", p(900) );
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



