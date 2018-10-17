#include <iostream>
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

    int ord[1000000];
	string teste = "mochila02.txt";
	ifstream in(teste.c_str());
	char num[10];
	int fim = 0;
	while(!in.eof()){
		in >> num;
		ord[fim] = atoi(num);
		fim++;
	}
	
	int nElementos = ord[0];
	int capacidadeMax = ord[1];
	int pesos[nElementos];
	int beneficio[nElementos];
	int count = 0;

	for (int i=2; i < 2*nElementos+2; i = i+2)
	{
		pesos[count] = ord[i];
		beneficio[count] = ord[i+1];
		count++;
	}

    cout << "Resultado utilizando " << teste << " = "<<  mochila(capacidadeMax,pesos,beneficio,nElementos) << endl;

    return 0;
}





