#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Message {
private:
    string text;
    int id; 

public:
    Message() : text(""), id(0) {} 
    Message(const string& txt, int msg_id) : text(txt), id(msg_id) {}

    const string& get_text() const {
        return text;
    }

    bool operator<(const Message& other) const {
        return id < other.id;
    }
};

class MessageFactory {
private:
    int current_id;

public:
    MessageFactory() : current_id(0) {}

    Message create_message(const string& text) {
        return Message(text, current_id++);
    }
};

class Recipient {
private:
    vector<Message> messages;

public:
    void receive(const Message& msg) {
        messages.push_back(msg);
    }

    void fix_order() {
        sort(messages.begin(), messages.end());
    }

    void print_messages() {
        for (const auto& msg : messages) {
            cout << msg.get_text() << endl;
        }
    }
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        random_shuffle(messages.begin(), messages.end());
        for (const auto& msg : messages) {
            recipient.receive(msg);
        }
    }
};

int main() {
    MessageFactory message_factory;
    Recipient recipient;

    vector<Message> messages;
    string text;

    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }

    Network::send_messages(messages, recipient);

    recipient.fix_order();
    recipient.print_messages();

    return 0;
}
