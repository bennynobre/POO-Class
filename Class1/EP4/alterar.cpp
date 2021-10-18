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

vector<int> remove(vector<int> v, int pos){

    vector<int> retorno{};

    for(int i = 0; i < (int) v.size(); i++){
        if( i == pos){
            continue;
        }
        retorno.push_back(v[i]);
    }

    return retorno;
}

vector<int> insert(vector<int> v, int x, int y ){

    vector<int> retorno{};

    for(int i = 0; i < (int) v.size(); i++){
        if( i == x){
            continue;
        }
        if( i == y){
            retorno.push_back(v[x]);
        }
        retorno.push_back(v[i]);
    }

    return retorno;
}

vector<int> dance(vector<int> v ){

    for(int i = 0; i < (int) v.size()-1; i++){
        if(v[i] == v[i+1]){
            v.erase( v.begin()+i, v.begin()+i+2);
            v = dance(v);
        }
    }

    return v;
}

int main(){

     cout << "remove: ";

    for( int i : remove( {-5, 3, 1, 15, -1, -99, -11, -1, -7 }, 4)){
        cout << i << " ";
    }

    cout << "\n";

    cout << "insert: ";
    for( int i : insert( {-5, 3, 1, 15, -1, -99, -11, -1, -7 }, 5, 4)){
        cout << i << " ";
    }

    cout << "\n";


    cout << "dance: ";

    for( int i : dance( {-5, 3, 1, 15, -99, -99, 15, -1, -7 })){
        cout << i << " ";
    }

    cout << "\n";    

    

    return 0;
}