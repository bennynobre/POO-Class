#include <iostream>

struct Gato
{
  std::string nome{""};
  int vidas{0};

  Gato(const Gato &gato)
  { //copy constructor
    *this = gato;
  }

  Gato &operator=(const Gato &gato)
  { //atribuição por cópia
    std::cout << "copiando de " << gato.nome << std::endl;
    this->nome = gato.nome + " copiado";
    this->vidas = gato.vidas;
    return *this;
  }

  Gato(std::string nome = "Gato", int vidas = 7) : nome{nome}, vidas{vidas}
  {
    std::cout << this->nome << " nascendo \n";
  }

  ~Gato()
  {
    std::cout << this->nome << " morrendo \n";
  }
};

void mostrar(Gato &gato)
{
  std::cout << gato.nome << " tem " << gato.vidas << " vidas \n";
}

int main()
{
  Gato siriguela{"Siriguela", 3}; // memória stack
  // exemplo de heap == Gato * gato = new Gato {"Gato", 7}; (o gato na heap só morre quando ele é deletado)
  Gato &apelido{siriguela}; //apelido aponta para siriguela
  siriguela.vidas--;
  apelido.vidas--;
  {
    Gato &apelido2{siriguela}; // apelido2 aponta para siriguela
    auto &nome = apelido2.nome;
    nome = "Siri";
    Gato abacaxi{"Abacaxi", 7};
  }
  mostrar(siriguela);

  return 0;
}