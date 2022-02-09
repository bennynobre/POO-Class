#include <iostream>
#include <list>
#include <memory>
#include <sstream>

class Kid {
    private:
        int age;
        std::string name;

    public:
        Kid(std::string name = "", int age = 0) : age{age}, name{name}{}

        friend std::ostream &operator<<(std::ostream& os, Kid &kid){
            os << kid.name << ":" << kid.age;

            return os;
        }

        int getAge(){
            return this->age;
        }

        std::string getName(){
            return this->name;
        }

        void setAge(int age){
            this->age = age;
        }

        void setName(std::string name){
            this->name = name;
        }
};

class JumpJump{

    private:
        std::list <std::shared_ptr<Kid>> playing;
        std::list <std::shared_ptr<Kid>> waiting;

        Kid remove_kid(std::string name, std::list<std::shared_ptr<Kid>>& kids){
            Kid kid(name);
            Kid kidFail;
            
            if(kids.empty()){
                std::cout << "empty queue\n";
                return kidFail;
            }else{
                bool find = false;
                
                for(auto it = kids.begin(); it != kids.end(); it++){
                    if(it->get()->getName() == kid.getName()){
                        kids.erase(it);
                        find = true;
                    }
                }

                if(find) return kid;

                return kidFail;
            }
        }

    public:
        JumpJump(){

        }

        friend std::ostream &operator<<(std::ostream& os, const JumpJump &jumpjump){
            os << "=> ";
            if(!jumpjump.waiting.empty()){
                for(auto it = jumpjump.waiting.rbegin();  it != jumpjump.waiting.rend(); it++){
                    os << *it->get() << " ";
                }
            }
            
             os << "=> [ ";

             if(!jumpjump.playing.empty()){
                for(auto jt = jumpjump.playing.rbegin();  jt != jumpjump.playing.rend(); jt++){
                     os << *jt->get() << " ";
                }
            }

            os << "]\n";

            return os;
        }

        void arrive(const std::shared_ptr<Kid>& kid){
            this->waiting.push_back(kid);
        }

        void in(){
            if(this->waiting.empty()){
                std::cout << "empty queue\n";
            }else{
                this->playing.push_back(this->waiting.front());
                this->waiting.pop_front();
            }
        }

        void out(){
            if(this->playing.empty()){
                std::cout << "JumpJump's empty\n";
            }else{
                this->waiting.push_back(this->playing.front());
                this->playing.pop_front();
            }
        }

        Kid remove(std::string name){
            return this->remove_kid(name, this->waiting);
        }


};


void controle(JumpJump &jumpjump){
    std::string linha{""};

    while(true){
        std::cout << "$";
        getline(std::cin, linha);

        std::stringstream ss(linha);
        std::string comando;

        ss >> comando;

        if(comando == "arrive"){
            std::string name = "";
            int age = 0;

            ss >> name >> age;

            jumpjump.arrive(std::make_shared<Kid>(name, age));
        }

        else if(comando == "show"){
            std::cout << jumpjump;
        }

        else if(comando == "in"){
            jumpjump.in();
        }

        else if(comando == "out"){
            jumpjump.out();
        }
        
        else if(comando == "remove"){
            std::string name;

            ss >> name;

            Kid kid = jumpjump.remove(name);

            if(kid.getName() != "") std::cout << kid.getName() << " gonna out\n";
            else std::cout << "unable to remove the child\n";
        }

        else if(comando == "end"){
            break;
        }

        else{
            std::cout << "command doesn't exist\n";
        }
    }
}

int main(){
    JumpJump jumpjump;

    controle(jumpjump);

    return 0;
}