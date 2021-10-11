#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

bool verificar_exist(vector<int> vet, int num){

    for (int i=0; i < (int) vet.size(); i++){
        if (num == vet[i]){
            return true;
        }
    }

    return false;

}

bool verificar_repet(vector<int> vet, int num){

    int repet {0};

    for (int i=0; i < (int) vet.size(); i++){
        if (num == vet[i]){
            repet += 1;
        }
    }

    if (repet > 1){
        return true;
    }

    return false;
}

vector<int> exclusivos(const vector<int>& vet){

    vector<int> aux{};

    for( int i = 0; i < (int) vet.size(); i++){
        if( !verificar_exist(aux, vet[i])){
            aux.push_back(vet[i]);
        }
    }
    return aux;
}

vector<int> diferentes(const vector<int>& vet){

    vector<int> aux{};

    for( int i = 0; i < (int) vet.size(); i++){
        if( !verificar_exist(aux, abs(vet[i]))){
            aux.push_back(abs(vet[i]));
          }
    }
    return aux;
}

vector<int> abandonados(const vector<int>& vet){

    vector<int> aux{};

    for( int i = 0; i < (int) vet.size(); i++){
        if( verificar_repet(vet, vet[i]) && !verificar_exist(aux,vet[i])){
            aux.push_back(vet[i]);       
        }
    }
    return aux;
}


int main(){

    vector<int> vet = {5, 3, -1, -50, -5, -99};

    for( int i : exclusivos( {5, 3, -1, -50, -5, -99} )){
        cout << i << " ";
    }
    
    cout << "\n";

    for( int i : diferentes( {5, 3, -1, -50, -5, -99} )){
        cout << i << " ";
    }
    
    cout << "\n";

    for( int i : abandonados( {1, 3, 4, 3, -1, -2, -2} )){
        cout << i << " ";
    }
    
    cout << "\n";


    return 0;
}