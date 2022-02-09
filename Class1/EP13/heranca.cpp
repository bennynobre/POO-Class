#include <iostream>
#include <string>


using namespace std;

class Animal {
private:
    bool m_vive {true};
    int idade {0};

public:
    Animal(){
        std::cout << "Animal nascendo" << std::endl;
    }
    void comer(){
        std::cout << "Animal comendo" << std::endl;
    }
    void morrer(){
        m_vive = false;
        std::cout << "Animal morreu" << std::endl;
    }
    bool vivo(){
        return m_vive;
    }
    friend ostream& operator<<(ostream& os, Animal& a) {
        os << "Animal vivo: " << a.vivo() << endl;
        return os;
    }
};

class Mascote : public Animal {
    string nome {""};
    
    public:
    Mascote(string nome) : nome(nome){
        cout << "Mascote nascendo" << std::endl;
    }
    void brincar(){
        if(vivo()){
            std::cout << "Mascote " << nome << " brincando" << std::endl;
        }
    }
    void comer(){
        cout << "Mascote comendo" << std::endl;
    }
};

class Cão : public Mascote {
    string nome {""};
    
    public:
    Cão(string nome) : Mascote(nome){
        cout << "Cão nascendo" << std::endl;
    }
    void brincar(){
        if(vivo()){
            std::cout << "Cão " << nome << " brincando" << std::endl;
        }
    }
    void comer(){
        cout << "Cão comendo" << std::endl;
    }
    friend ostream& operator<<(ostream& os, Cão& c) {
        os << "Cão vivo: " << c.vivo() << endl;
        return os;
    }
};

int main(){
    Mascote m("Mascote");
    Cão c("Cão");
    m.brincar();
    c.brincar();
    m.morrer();
    c.morrer();
    cout << m << endl;
    cout << c << endl;
    
    return 0;

}