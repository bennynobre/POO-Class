#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Medico;
class Paciente {
private:
    string diagnostico;
    string sender;
    map<string, Medico*> medicos;//ponteiro para o medico que o paciente esta atendendo e o seu diagnostico

public:
    Paciente(string sender) {//construtor da classe paciente que recebe o nome do paciente
        this->sender = sender;
        this-> diagnostico = "";
        this-> medicos = map<string, Medico*>();
    }

    void addMedico(string nome, Medico* medico) {
        medicos[nome] = medico;
    }

    void removeMedico(string nome) {
        medicos.erase(nome);
    }

    void setDiagnostico(string diagnostico) {
        this->diagnostico = diagnostico;
    }

    string getDiagnostico() {
        return diagnostico;
    }

    string getSender() {
        return sender;
    }

    string getMedicos() {
        stringstream ss;
        for (auto it = medicos.begin(); it != medicos.end(); it++) {
            ss << it->first << " ";
        }
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, Paciente& paciente) {
        os << "Paciente: " << paciente.getSender() << endl;
        os << "Diagnostico: " << paciente.getDiagnostico() << endl;
        return os;
    }
};

class Medico{
private:
    string nome;
    string classe;
    map<string, Paciente*> pacientes;//ponteiro para paciente para nao ter que criar um novo paciente   

public:
    Medico(string sender, string classe){
        this->nome = sender;
        this->classe = classe;
        this->pacientes = map<string, Paciente*>();
    }

    void addPaciente(string nome, Paciente* paciente) {
        pacientes[nome] = paciente;
    }

    void removePaciente(string nome) {
        pacientes.erase(nome);
    }

    string getClasse() {
        return classe;
    }

    string getSender() {//nome do medico que esta a enviar a mensagem para o paciente
        return nome;
    }

    string getPacientes() {
        stringstream ss;
        for (auto it = pacientes.begin(); it != pacientes.end(); it++) {
            ss << it->first << " ";
        }
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, Medico& medico) {//imprime o medico e os pacientes que o possuem associados a ele (se houver)
        os << "Medico: " << medico.getSender() << endl;
        os << "Classe: " << medico.getClasse() << endl;
        return os;
    }
};

class Hospital {
private:
    map<string, Medico*> medicos;
    map<string, Paciente*> pacientes;

public:
    Hospital() {
        this->medicos = map<string, Medico*>();
        this->pacientes = map<string, Paciente*>();
    }

    void addMedico(string nome, Medico* medico) {
        medicos[nome] = medico;
    }

    void removeMedico(string nome) {
        medicos.erase(nome);
    }

    void addPaciente(string nome, Paciente* paciente) {
        pacientes[nome] = paciente;
    }

    void removePaciente(string nome) {
        pacientes.erase(nome);
    }

    string getMedicos() {
        stringstream ss;
        for (auto it = medicos.begin(); it != medicos.end(); it++) {
            ss << it->first << " ";
        }
        return ss.str();
    }

    string getPacientes() {
        stringstream ss;
        for (auto it = pacientes.begin(); it != pacientes.end(); it++) {
            ss << it->first << " ";
        }
        return ss.str();
    }

    void vincular(string nomeMedico, string nomePaciente) {//vincula um paciente a um medico (se o medico existir e o paciente nao)
        if (medicos.find(nomeMedico) != medicos.end() && pacientes.find(nomePaciente) != pacientes.end()) {
            medicos[nomeMedico]->addPaciente(nomePaciente, pacientes[nomePaciente]);
            pacientes[nomePaciente]->addMedico(nomeMedico, medicos[nomeMedico]);
        }
    }

    string showAll(){//mostra todos os medicos e pacientes do hospital (se houver)
        stringstream ss;
        for (auto it = medicos.begin(); it != medicos.end(); it++) {
            ss << it->second << endl;
        }
        return ss.str();
    }
};

int main(){
    Hospital hospital;
    while(true){
        string comando;
        cin >> comando;
        if(comando == "addMedico"){
            string nome, classe;
            cin >> nome >> classe;
            Medico* medico = new Medico(nome, classe);
            hospital.addMedico(nome, medico);
        }
        else if(comando == "addPaciente"){
            string nome, sender;
            cin >> nome >> sender;
            Paciente* paciente = new Paciente(sender);
            hospital.addPaciente(nome, paciente);
        }
        else if(comando == "vincular"){
            string nomeMedico, nomePaciente;
            cin >> nomeMedico >> nomePaciente;
            hospital.vincular(nomeMedico, nomePaciente);
        }
        else if(comando == "showAll"){
            cout << hospital.showAll() << endl;
        }
        else if(comando == "exit"){
            break;
        }
    }

    return 0;
}