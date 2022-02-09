#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

//interface
class IMsg {

public:
    virtual std::string getSender() const = 0;
    virtual std::string getText() const = 0;
    virtual ~IMsg() {};
    friend std::ostream& operator<<(std::ostream& os, IMsg& msg);
};

std::ostream& operator<<(std::ostream& os, const IMsg& msg) {
    os << msg.getSender() << ": " << msg.getText();
    return os;
}

class Msg : public IMsg {
    std::string sender;
    std::string text;
public:
    Msg(std::string sender, std::string text) : sender(sender), text(text) {}
    std::string getSender() const override { return sender; }
    std::string getText() const override { return text; }
};

class User {
    std::string username; // chave
    std::vector<IMsg*> inbox;
    std::vector<IMsg*> sent;
public:
    void sendMsg(IMsg* msg, User& receiver) {
        receiver.inbox.push_back(msg);
        this->sent.push_back(msg);
    }
    std::string getInbox() {
        std::stringstream ss;
        for (auto msg : inbox) {
            ss << *msg << std::endl;
        }
        inbox.clear();
        return ss.str();
    }
};

class Manager {
    std::map<std::string, User> users;
    std::vector<IMsg*> messages;

    Manager() {
    }
    ~Manager() {
        for (auto msg : messages) {
            delete msg;
        }
    }

    void addUser(std::string nome) {
        auto it = users.find(nome);

        if (it == users.end()) {
            users[nome] = User(nome);
        } else {
            throw std::runtime_error("User already exists");
        }
    }

    User* getUser(std::string nome) {
        auto it = users.find(nome);

        if (it == users.end()) {
            throw std::runtime_error("User not found");
        } else {
            return &it->second;
        }
    }


    void sendMsg(std::string sender, std::string receiver, std::string text) {
        User* senderUser = getUser(sender);
        User* receiverUser = getUser(receiver);
        Msg* msg = new Msg(sender, text);
        senderUser->sendMsg(msg, *receiverUser);
        this->messages.push_back(msg);
    }

};