#include <iostream>

class Tempo {
    int hora;
    int minuto;
    int segundo;

    void setIntervalo(int &var, int value, int inf, int sup) {
      if (var >= inf && var <= sup) {
        var = value;
      } else {
        std::cout << "Valor invalido" << std::endl;
      }
    }

public:
    Tempo(int h, int m, int s);

    int getHora() {
        return hora;
    }
    void setHora(int h) {
        setIntervalo(hora, h, 0, 23);
    }

    int getMinuto() {
        return minuto;
    }

    void setMinuto(int m) {
        setIntervalo(minuto, m, 0, 59);
    }

    int getSegundo() {
        return segundo;
    }

    void setSegundo(int s) {
        if (s >= 0 && s <= 59) {
            segundo = s;
        } else {
            std::cout << "Segundo invalido" << std::endl;
        }
    }

    void passarSegundo(){
        segundo++;
        if (segundo == 60) {
            segundo = 0;
            minuto++;
            if (minuto == 60) {
                minuto = 0;
                hora++;
                if (hora == 24) {
                    hora = 0;
                }
            }
        }
    }
};