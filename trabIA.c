#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define popIni 100
#define crom 10

typedef struct individuo
{
    char genes[crom];
    int fitness;
} individuo;

typedef struct populacao
{
    long int geracao;
    individuo *inds[popIni];
} populacao;

char * converte_para_binary(int converter){
    int c, k, pos=0;
    char * result = (char *)calloc(32, sizeof(char));

    for (c = 31; c >= 0; c--)
    {
        k = converter >> c;

        if (k & 1){
            result[pos] = '1';
        }
        else {
            result[pos] = '0';
        }
        pos++;
    }

    return result;
}


char ** encode(individuo * array, int size){
    char ** matrix = (char **)calloc(size, sizeof(char*));
    
    for(int i = 0; i < size; i++) {
        matrix[i] = (char*)calloc(32, sizeof(char));
        matrix[i] = converte_para_binary(array[i].fitness);
    }
    return matrix;
}

int * decode(char ** decodificar, int size){
    int * array = (int *)calloc(size, sizeof(int));

    for(int i = 0; i < size; i++){
        array [i] = (int) strtol(decodificar[i], NULL, 2);
    }

    return array;
}

float avaliacao(char * target, char * compare){
    if (strlen(target) != strlen(compare)) {
        return 0.0;
    }
    int len = strlen(target);
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(target[i] == compare[i]) {
            count++;
        }
    }

    return ((float)count*100.0/(float)len);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    individuo *begin = (individuo *)calloc(popIni,sizeof(individuo));
    int cromossomo[] = {20, 30, 18, INT_MAX}; //porcentagem de acerto
    int * decoded;
    char objetivo[crom];
    char atual[10];

    for (int i = 0; i < popIni; i++){
        // begin = cria_individuo(begin);
        for(int j = 0; j < crom; j++){
            begin[i].genes[j] = rand()%(90-65)+65;
        }
    }

    for (int i = 0; i < popIni; i++){
        // begin = cria_individuo(begin);
        for(int j = 0; j < crom; j++){
            printf("%c", begin[i].genes[j]);
        }
        printf("\n");
    }

    printf("%d\n", strlen(begin[1].genes));

    scanf("%s", objetivo);
    // objetivo[strlen(objetivo) - 1] = '\0';

    printf("%d\n", strlen(objetivo));

    for(int i = 0; i<popIni; i++){
        begin[i].fitness = avaliacao(objetivo, begin[i].genes);
    }


    printf("\n");
    for(int i = 0; i < popIni; i++){
        printf("%d ", begin[i].fitness);
    }
    printf("\n");
    printf("\n");

    char ** resultado = encode(begin, popIni);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 32; j++){
            printf("%c ", resultado[i][j]);
        }
        printf("\n");
    }

    decoded = decode(resultado, popIni);

    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d ", decoded[i]);
    }

    printf("\n");

    

    return 0;
}