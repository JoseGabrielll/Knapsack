#include <iostream>
#include <string.h>
#include <utility>
#include <algorithm>
#include <fstream>

using namespace std;


int mochila(int capacidadeMax, int  pesos[], int beneficio[], int nElementos){
    int V[nElementos+1][capacidadeMax+1]; //tabela q sera preenchida
    int i, j, k, w;

    for(i=0 ; i<=capacidadeMax ; i++){
        V[0][i] = 0;
    }
    for(j=0 ; j<=nElementos ; j++){
        V[j][0] = 0;
    }

    for(k=1; k<=nElementos ; k++){
        for(w=1 ; w<=capacidadeMax ; w++){
            if(pesos[k-1] <= w){ //se satisfaz essa condição pode fazer parte da solução
                if((beneficio[k-1] + V[k-1][w - pesos[k-1]]) > V[k-1][w]){ //max
                    V[k][w] = (beneficio[k-1] + V[k-1][w - pesos[k-1]]);
                }
                else{
                    V[k][w] = V[k-1][w];
                }

            }
            else{
                V[k][w] = V[k-1][w];
            }
        }
    }

    return V[nElementos][capacidadeMax];
}

int main(){

    // Teste sem o arquivo

    /*int capacidadeMax = 20;
    int nElementos = 5;
    int beneficio[] = {3, 5, 8, 4, 10};
    int pesos[] = {2 ,4 ,5 ,3 ,9};
    int valorMax = mochila(capacidadeMax, pesos, beneficio, nElementos);*/

    FILE *arquivo;
    arquivo = fopen("instancias/mochila01.txt", "r"); //abre arquivo em modo leitura

    if (arquivo == NULL){
        puts("arquivo nao encontrado");
        exit(1);
    }

    int QuantidadeLinhas = 0;
    int nElementos;
    char linha[999];
    char *token;
    int capacidadeMax;


    while(1){
        fgets(linha, 999, arquivo);
        if (feof(arquivo)){
            break;
        }
        if(QuantidadeLinhas == 1)
            break;

        token = strtok(linha, " ");

        int k = 0;
        while(token!=NULL){
            if(QuantidadeLinhas == 0){
                if(k == 0)
                    nElementos = atoi(token);
                else
                    capacidadeMax = atoi(token);
            }
            token = strtok(NULL, " ");
            k++;
        }
        QuantidadeLinhas++;
    }

    int beneficio[nElementos];
    int pesos[nElementos];

    while(1){
        fgets(linha, 999, arquivo);
        if (feof(arquivo)){
            break;
        }

        token = strtok(linha, " ");

        int k = 0;
        while(token!=NULL){
            if(!k)
                pesos[QuantidadeLinhas - 1] = atoi(token);
            else
                beneficio[QuantidadeLinhas - 1] = atoi(token);

            token = strtok(NULL, " ");
            k++;
        }
        QuantidadeLinhas++;
    }
    
    fclose(arquivo);

    int valorMax = mochila(capacidadeMax, pesos, beneficio, nElementos);    
    cout << "Valor máximo " << valorMax << endl;

    return 0;
}




