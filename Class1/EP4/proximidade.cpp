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

int briga(vector<int> v){

    vector<int> vetor_aux{vetor_abs(v)};
    int cont{ 0 };

    for(int i = 1; i < (int) vetor_aux.size()-1; i+= 1){
            if(vetor_aux[i] > 50 && vetor_aux[i-1] > 30 && vetor_aux[i+1] > 30){
                cont += 1;
            }            
    }
    return cont;

}

vector<int> apaziguado( vector<int> v){

    vector<int> vetor_aux{ vetor_abs(v) };
    vector<int> retorno{};
    
    if( vetor_aux[0] > 80 && vetor_aux[1] < 10){
        retorno.push_back(0);
    }
    if( vetor_aux[vetor_aux.size()-1] > 80 && vetor_aux[vetor_aux.size()-2] < 10){
        retorno.push_back(vetor_aux.size()-1);
    }

    for(int i = 1; i < (int) vetor_aux.size()-1; i+= 1){
        if(vetor_aux[i] > 80 && (vetor_aux[-1] < 10 || vetor_aux[+1] < 10)){
            retorno.push_back(i);
        }
    }

    return retorno;
}

int main(){

    
    cout << "briga: " << briga( {50, -98, 31, -51, 31, -99} ) << "\n";

    cout << "apaziguado: ";
    for (int i : apaziguado( {83, -4, 65, 8, -99, 12 } ) ){
        cout << i << " ";
    }

    cout << "\n";



    return 0;

}