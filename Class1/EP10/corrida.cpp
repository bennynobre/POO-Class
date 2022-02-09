#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

class Corredor {
protected:
    float x {0};
    std::string nome;
public:
    Corredor(std::string nome) : nome(nome) {}
    float getx() {
        return x;
    }
    virtual void correr() = 0;
};

class Penelope : public Corredor {
public:
    void correr() override {
        x += 1;
    }
};

class Mutley : public Corredor {
public:
    void correr() override {
        if(rand() % 2 == 0) {
            x += 2;
        }
    }
};

class Xerife : public Corredor {
    float vel = 0.1;
public:
    void correr() override {
        x += vel;
        vel += 0.01;
    }
};

class Corrida {
    std::vector<std::unique_ptr<Corredor>> corredores;
    float distancia;
public:
    Corrida(float distancia) : distancia(distancia) {}
    void adicionaCorredor(std::unique_ptr<Corredor> corredor) {
        corredores.push_back(corredor);
    }
    void darLargada() {
        while (!temGanhador()) {
            for (auto corredor : corredores) {
                corredor->correr();
            }
        }
    }
};