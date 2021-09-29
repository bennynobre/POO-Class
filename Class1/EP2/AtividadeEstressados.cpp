#include <iostream>
#include <vector>

bool existe (std::vector<int> vet, int valor){
    for (int i=0; i < (int)vet.size(); i++) 
        if (vet[i] == valor)
            return true;
    return false;
}

int main()
{
    std::cout << existe({1, 2, 3, 4, 5}, 0) << '\n';
    std::cout << existe({1, 2, 3, 4, 5}, 3) << '\n';

    return 0;
}