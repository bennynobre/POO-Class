#include <iostream>
#include <vector>
#include <algorithm> // std::min_element
#include <iterator>  // std::begin, std::end

using namespace std;

int procurar_menor(vector<int> vet){
    
    auto min = min_element(begin(vet), end(vet));
    if (end(vet) != min)
        return *min;
    return -1;

}

int procurar_maior(vector<int> vet){

    auto max = max_element(begin(vet), end(vet));
    if (end(vet) != max)
        return *max;
    return -1;
}

int procurar_menor_pos(vector<int> vet){

    auto min = min_element(begin(vet), end(vet));
    for (int i = 0; i < (int)vet.size(); i++)
        if(vet[i] == *min)
            return i;
    return -1;

}

int procurar_menor_pos_apos(vector<int> vet, int P){
    
    if(vet.size() == 0){
        return -1;
    }

    int menor = vet[P];

    for (int i = P; i < (int)vet.size(); i++)
        if( vet[i] < menor ){
            menor = i;
        }

    return menor;

}

int procurar_melhor_se(vector<int> vet, int P){

    if(vet.size() == 0){
        return -1;
    }

    int HomemCalmo = vet[P];

    for (int i = 0; i < (int)vet.size(); i++)
        if( vet[i] > 0 ){
            
            HomemCalmo = i;
        }

    if(HomemCalmo < 0){
        return -1;
    }
    else {
        return HomemCalmo;
    }


}

int main() {

    vector<int> vet = {5, 3, -1, -50, -1, -99};
    int P = 0;

    cout << procurar_menor(vet) << '\n';
    cout << procurar_maior(vet) << '\n';
    cout << procurar_menor_pos(vet) << '\n';
    cout << procurar_menor_pos_apos(vet, P) << '\n';
    cout << procurar_melhor_se(vet, P) << '\n';


    return 0;
}