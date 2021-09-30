#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define popIni 100
#define crom 10

typedef struct individuo
{
    int genes[crom];
    double fitness; //nao utilizado no momento
} individuo;

typedef struct populacao
{
    long int geracao;
    individuo *inds[popIni];
} populacao;

int main() {
    srand(time(NULL));
    individuo *begin = (individuo *)calloc(popIni,sizeof(individuo));
    for (int i = 0; i < popIni; i++){
        for(int j = 0; j < crom; j++){
            begin[i].genes[j] = rand() % 2;
        }
    }

    for (int i = 0; i < popIni; i++){
        printf("individuo %d: ", i+1);
        for(int j = 0; j < crom; j++){
        printf(" %d", begin[i].genes[j]);
        }
        printf("\n");
    }
}