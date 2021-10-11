#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

vector<int> pegar_mulheres_calmas(const vector<int>& vet) {

    vector<int> mulheres {};
    
    for (int i=0; i < (int) vet.size() ; i++) {

        if(vet[i] < 0 and vet[i] >= -10){
        mulheres.push_back(vet[i] * -1);
        }
    }

    return mulheres;
}


vector<int> pegar_calmos(const vector<int>& vet) {

     vector<int> calmos {};
    
    for (int i=0; i < (int) vet.size() ; i++) {

        if (vet[i] > 0 and vet[i] <= 10){
        calmos.push_back(vet[i]);
        }
        else if (vet[i] < 0 and vet[i] >= -10) {
            calmos.push_back(vet[i] * -1);
        }
    }

    return calmos;
}


vector<int> pegar_homens(const vector<int>& vet) {

    vector<int> homens {};
    
    for (int i=0; i < (int) vet.size() ; i++) {

        if(vet[i] > 0){
        homens.push_back(vet[i]);
        }
    }

    return homens;

}

vector <int> clone(const vector<int>& vet) {

    vector<int> vet2 {};

    for (int i=0; i < (int) vet.size() ; i++) {
        vet2.push_back(vet[i]);
    }

    return vet2;

}


int main(){

    vector<int> vet = {5, 3, -1, -50, -5, -99};

    for( int i : clone( vet )){
        cout << i << " ";
    }

    cout << '\n';

    for( int i : pegar_homens( vet )){
        cout << i << " ";
    }

    cout << '\n';

    for( int i : pegar_calmos( vet )){
        cout << i << " ";
    }

    cout << '\n';

    for( int i : pegar_mulheres_calmas( vet )){
        cout << i << " ";
    }


    return 0;
}