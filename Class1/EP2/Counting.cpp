#include<iostream>
#include<vector>

using namespace std;

string man_are_more_stress_than_wonman(vector<int> vet){

    int somaHomem = 0;
    int contHomem = 0;
    int contMulher = 0;
    int somaMulher = 0;
    int mediaHomem = 0;
    int mediaMulher = 0;

    for(int i=0; i < (int)vet.size(); i++){
        if(vet[i] > 0){
            somaHomem = somaHomem + vet[i];
            contHomem++;
        }
        else{
            somaMulher = somaMulher + vet[i];
            contMulher++;
        }
    }

    mediaHomem = somaHomem/contHomem;
    mediaMulher = somaMulher/contMulher;
    
    mediaMulher = mediaMulher * -1;

    if(mediaHomem > mediaMulher){
        return "Sim";
    }
    else if(mediaHomem < mediaMulher){
        return "Não";
    }
    else{
        return "Empate";
    }


}

string how_half_is_more_stress(vector<int> vet){

    int somaH = 0;
    int somaM = 0;

    for(int i=0; i < (int)vet.size(); i++){
        if(vet[i] > 0){
            somaH = somaH + vet[i];
        }
        else{
            somaM = somaM + vet[i];
        }
    }

    somaM = somaM * -1;

    if(somaH > somaM){
        return "Homens";
    }
    else if(somaH < somaM){
        return "Mulheres";
    }
    else{
        return "Empate";
    }

}

string more_man_or_woman(vector<int> vet){

    int contMan = 0;
    int contWon = 0;

    for(int i=0; i < (int)vet.size(); i++){
        if(vet[i] > 0){
            contMan++;
        }
        else{
            contWon++;
        }
    }

    
    if(contMan > contWon){
        return "Homens";
    }
    else if(contMan < contWon){
        return "Mulheres";
    }
    else{
        return "Empate";
    }

}

int calculate_stress(vector<int> vet){

    int media = 0;
    int total = 0;

    for(int i=0; i < (int)vet.size(); i++){
        
        media = vet[i] + media;
    }

    total = media/(int)vet.size();

    return total;

}

int main(){

    vector<int> vet = {5, 3, -1, -50, -1, -99};

    cout << calculate_stress(vet) << '\n';
    cout << more_man_or_woman(vet) << '\n';
    cout << how_half_is_more_stress(vet) << '\n';
    cout << man_are_more_stress_than_wonman(vet) << '\n';


    return 0;
}