#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

void ordenar(std::vector<int>& vet){

    sort(vet.begin(), vet.end());

}

void embaralhar(vector<int>& vet){

    for (int i = 0; i < (int) vet.size(); i++){
       swap(vet[i], vet[rand() % (int) vet.size()]);    
    }
}

int sort_aleatorio(const std::vector<int>& vet){

    srand(time(NULL));

    int i { rand() % ((int) vet.size() -1) };

    return vet[i];    
}

void inverter_inplace(std::vector<int>& vet){

    int vet_clone{ (int)vet.size() -1 };
    int *V{};


    for( int i = vet_clone; i >= 0; i--){
        V = &vet[i];
        vet.push_back(*V);
    }

    for( int i = 0; i < (int) vet.size(); i++){
        vet.erase(vet.begin()+0);
    }

}

vector<int> inverter_com_copia(const vector<int>& vet) {

    vector<int> vet_clone {};

    for (int i= (int) vet.size() -1 ; i >= 0 ; i--) {
        vet_clone.push_back(vet[i]);
    }

    return vet_clone;

}

int main(){

    vector<int> vet = {5, 3, -1, -50, -5, -99};

    for( int i : inverter_com_copia( vet )){
        cout << i << " ";
    }

    cout << '\n';

    inverter_inplace( vet );
    for( int i = 0; i < (int) vet.size(); i++){
        cout << vet[i] << " ";
    }

    cout << '\n';

    cout << sort_aleatorio( {5, 3, -1, -50, -5, -99} ) << "\n";

    embaralhar( vet );
    for( int i = 0; i < (int) vet.size(); i++){
        cout << vet[i] << " ";
    }

    cout << '\n';

    ordenar( vet );
    for( int i = 0; i < (int) vet.size(); i++){
        cout << vet[i] << " ";
    }

    cout << '\n';

    return 0;
}