#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

// FUNÇÕES AUXILIARES

bool verificar_existencia(vector<int> vetor, int num){

    for( int i = 0; i < (int) vetor.size(); i++){
        if(num == vetor[i]){
            return true;
        }
    }
    
    return false;
}

bool verificar_repeticao(vector<int> vetor, int num){

    int rep{ 0 };
    for( int i = 0; i < (int) vetor.size(); i++){
        if(num == vetor[i]){
            rep += 1;
        }
    }
    
    if( rep > 1){
        return true;
    }

    return false;

}

vector<int> vetor_abs(vector<int> vetor){

    vector<int> retorno{};
    for(int i = 0; i < (int) vetor.size(); i++){
        retorno.push_back( abs( vetor[i] ) );
    }

    return retorno;
}

int verificar_ocorrencias(vector<int> vetor){

    int retorno{ 0 };

    for(int i = 0; i < (int) vetor.size(); i++){
    int qtd_rep{0};
        for(int a = 0; a < (int) vetor.size(); a++){
            if(vetor[i] == vetor[a]){
                qtd_rep += 1;
            }
            if(qtd_rep > retorno){
                retorno = qtd_rep;
            }
        }
    }
    return retorno;
}

vector<int> verificar_dois_mais_recorrentes(vector<int> vetor){
    sort(vetor.begin(), vetor.end());
    vector<int> retorno{0,0};
    int aux{0};


    for(int i = 0; i < (int) vetor.size(); i+=1 ){
        int conta{0};
        for(int a = 0; a < (int) vetor.size(); a+=1){
            if( vetor[i] == vetor[a]) {
                conta += 1;
            }                
        }
        if( conta >= aux && vetor[i] != retorno[0]){
            aux = conta;
            retorno[1] = retorno[0];
            retorno[0] = vetor[i];
        }
    }
    return retorno;
}

//////////////////////////////////////////// FIM DOS AUXILIARES ////////////////////////////////////////////////////

vector<int> sozinhos(const vector<int>& v){

    vector<int> v_abs{};    
    vector<int> aux{};

    for( int i : vetor_abs(v)){
        v_abs.push_back(i);        
    }

    for( int i = 0; i < (int) v_abs.size(); i++){
        if(!verificar_repeticao(v_abs, v_abs[i])){
            aux.push_back(v_abs[i]);
        }
    }


    return aux;
}

int mais_ocorrencias(vector<int> v){

    vector<int> vet{vetor_abs(v)};    
    return verificar_ocorrencias(vet);
}

vector<int> mais_recorrentes(vector<int> v){

    vector<int> vet{vetor_abs(v)};    
    return verificar_dois_mais_recorrentes(vet);
}


int main(){

    cout << "sozinho: ";
    for( int i : sozinhos( {1, 3, 4, 3, -1, -2, -2} )){
        cout << i << " ";
    }
    cout << "\n";

    cout << "mais_ocorrencias: " << mais_ocorrencias({1, 3, 4, 5, -1, -5, -5}) << "\n";

    cout << "mais_recorrentes: ";
    for( int i : mais_recorrentes({1, 3, 4, 5, -1, -5, -5, 3, -3})){
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}

