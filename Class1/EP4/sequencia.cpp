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

int quantos_times(vector<int> v){

    int cont{ 0 };

    for(int i = 0; i < (int) v.size()-1; ){
        if(v[i] < 0 && v[i+1] < 0){
            cont+=1;
            while(v[i] < 0){
                i+=1;
            }
        }
        else{
            if(v[i] > 0 && v[i+1] > 0){
                cont+=1;
                while(v[i] > 0){
                    i+=1;
                }
            }
            else{
                i++;
            }

        }

    }
    return cont;
}
        
int maior_time(vector<int> v){

 int cont{ 0 };
 int aux{ 0 };

    for(int i = 0; i < (int) v.size()-1; ){
        if(v[i] < 0 && v[i+1] < 0){
            while(v[i] < 0){
                i+=1;
                aux += 1;
            }
        }
        else{
            if(v[i] > 0 && v[i+1] > 0){
                while(v[i] > 0){
                    i+=1;
                    aux+=1;
                }
            }
            else{
                i++;
            }

        }
        if(aux > cont){
            cont = aux;
        }
        aux = 0;

    }
    return cont;
}

int sozinho(vector<int> v ){

 int cont{ 0 };
 int aux{ 0 };

    for(int i = 0; i < (int) v.size()-1; ){
        if(v[i] < 0 && v[i+1] < 0){
            while(v[i] < 0){
                i+=1;
                aux += 1;
            }
        }
        else{
            if(v[i] > 0 && v[i+1] > 0){
                while(v[i] > 0){
                    i+=1;
                    aux+=1;
                }
            }
            else{
                i++;
            }

        
        }
    cont += aux;
    aux = 0;

    }
    return (int) v.size() - cont;
}

int main(){

    
    cout << "quantos_times: " << quantos_times({ 28, 26, 1, 6, 39} ) << "\n";

    cout << "maior_time: " << maior_time({-5, 3, 1, -15, -1, 99, -11, -1, -7 }) << "\n";

    cout << "sozinhos: " << sozinho({-5, 3, 1, 15, -1, -99, -11, -1, -7 }) << "\n";


    return 0;

}