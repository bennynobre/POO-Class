#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Contato {
    string nome;
public:
    Contato(string nome)
};

class Agenda {
    map<string, Contato> contatos;

public:
    void adciciona(string nome) {
        auto it = contatos.find(nome);
        if (it == contatos.end()) {
            contatos[nome] = make_shared<Contato>(nome);
        }
    }
    void remover(string nome) {
        auto it = contatos.find(nome);
        if (it != contatos.end()) {
            contatos.erase(it);
        }
    }

    shared_ptr<Contato> find(string nome) {
        auto it = contatos.find(nome);
        if (it != contatos.end()) 
            return it->second;
        throw runtime_error("fail: Contato não encontrado");
    }

    friend ostream& operator<<(ostream& os, Agenda& ag);
};
ostream& operator<<(ostream& os, Agenda& ag) {
    for (auto& c : ag.contatos) {
        os << c.second->getNome() << endl;
    }
    return os;
}