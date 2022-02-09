#include <iostream>
#include <list>
#include <sstream>
#include <memory>

using namespace std;
class Fone {
    private:
    string id;
    string numero;

    public:
    Fone(string id, string numero) {
        this->id = id;
        this->numero = numero;
    }
    static bool valido(std::string numero) {
        if (numero.size() != 11) {
            return false;
        }
        for (int i = 0; i < numero.size(); i++) {
            if (numero[i] < '0' || numero[i] > '9') {
                return false;
            }
        }
        return true;
    }
    string getId() {
        return id;
    }
    string getNumero() {
        return numero;
    }
    void setNumero(string numero) {
        this->numero = numero;
    }
    friend ostream& operator<<(ostream& os, Fone& fone) {
        os << "Id: " << fone.id << " Numero: " << fone.numero;
        return os;
    }
};

    class Contato{
        private:
        string nome;
        list<Fone> fones;

        public:
        Contato(string nome) {
            this->nome = nome;
        }
        void addFone(Fone fone) {
            fones.push_back(fone);
        }
        void removeFone(Fone fone) {
            if (fones.empty()) {
                cout << "Nao ha fones para remover" << endl;
            } else {
                for (auto it = fones.begin(); it != fones.end(); it++) {
                    if (it->getId() == fone.getId()) {
                        fones.erase(it);
                        break;
                    }
                }
            }
        }
        string getnome() {
            return nome;
        }
        list<Fone> getFones() {
            return fones;
        }
        void setnome(string nome) {
            this->nome = nome;
        }
        friend ostream& operator<<(ostream& os, Contato& contato) {
            os << "Nome: " << contato.nome << endl;
            for (auto it = contato.fones.begin(); it != contato.fones.end(); it++) {
                os << *it << endl;
            }
            return os;
        }
    };

    int main(){

    Contato contato("");

    while(true){

        string nome, id, numero;
        cout << "Digite o nome do contato: ";
        getline(cin, nome);
        contato.setnome(nome);
        cout << "Digite o id do fone: ";
        getline(cin, id);
        cout << "Digite o numero do fone: ";
        getline(cin, numero);
        if(Fone::valido(numero)){
            Fone fone(id, numero);
            contato.addFone(fone);
        }else{
            cout << "Numero invalido" << endl;
        }
        cout << "Deseja adicionar mais um fone? (s/n)" << endl;
        char resp;
        cin >> resp;
        if(resp == 'n'){
            break;
        }
    }

        cout << contato << endl;
        cout << "Digite o id do fone que deseja remover: ";
        string id;
        getline(cin, id);
        Fone fone(id, "");
        
        contato.removeFone(fone);
        cout << contato << endl;

        return 0;
    }