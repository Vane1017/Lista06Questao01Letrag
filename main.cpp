#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int MFKnapsack(int ii, int jj, std::vector<int>& Valores, std::vector<int>& Peso){

    int F[Valores.size()+1][jj+1];

    int value;

    int kk, zz;

    for(kk=0; kk<=Valores.size(); kk++){
        for(zz=0; zz<=jj; zz++){

            if(kk==0 || zz == 0){
                F[kk][zz] = 0;
            }

            else{
                F[kk][zz] = -1;
            }
        }
    }

    if(F[ii][jj] < 0){
        if(jj < Peso[ii-1]){
            value = MFKnapsack(ii-1, jj, Valores, Peso);
        }

        else{
            value = max(MFKnapsack(ii-1, jj, Valores, Peso), Valores[ii-1] + MFKnapsack(ii-1, jj-Peso[ii-1], Valores, Peso));
        }

        F[ii][jj] = value;
    }

    return F[ii][jj];
}

int main(){
    cout << "Lista 06 - Questao 01 - Letra g" << endl;

    int NumItens = 4;
    int Capacidade = 5;

    std::vector<int> Pesos = {2, 1, 3, 2};
    std::vector<int> Valores = {12, 10, 20, 15};

    int Resultado;

    Resultado = MFKnapsack(NumItens, Capacidade, Valores, Pesos);

    cout << "Resposta: " << Resultado << endl;
}
