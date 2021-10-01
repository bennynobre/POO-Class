#include <iostream>
#include <vector>

bool existe (std::vector<int> vet, int valor){
    for (int i=0; i < (int)vet.size(); i++) 
        if (vet[i] == valor)
            return true;
    return false;
}

int procurar_valor(std::vector<int> vet, int valor) {
    for (int i = 0; i < (int)vet.size(); i++)
        if(vet[i] == valor)
            return i;
    return -1;
}

int contar(std::vector<int> vet, int valor){
    int cont = 0;
    for (int i = 0; i < (int)vet.size(); i++)
        if(vet[i] == valor){
            cont++;
        }
    return cont;
   
}

int procurar_valor_apos(std::vector<int> vet, int valor, int posic){

    for (int i = posic; i < (int)vet.size(); i++)
        if(vet[i] == valor)
            return i;
    return -1;
   
}

int main()
{

    int posic = 2;

    std::cout << existe({1, 2, 3, 4, 5}, 0) << '\n';
    std::cout << procurar_valor({1, 2, 3, 4, 5}, 3) << '\n';
    std::cout << procurar_valor_apos({1, 4, 3, 4, 4}, 4, posic) << '\n';
    std::cout << contar({1, 4, 3, 5, 4}, 4) << '\n';

    return 0;
}