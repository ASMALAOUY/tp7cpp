#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string numeroTelephone;
    string email;

public:

    Contact(string n) {
        nom = n;
        numeroTelephone = "Inconnu";
        email = "Inconnu";
    }


    Contact(string n, string num) {
        nom = n;
        numeroTelephone = num;
        email = "Inconnu";
    }


    Contact(string n, string num, string mail) {
        nom = n;
        numeroTelephone = num;
        email = mail;
    }
    void afficher() const {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << numeroTelephone << endl;
        cout << "Email : " << email << endl;
        cout << "------------------------" << endl;
    }
};

int main() {

    Contact c1("Asma");
    Contact c2("Youssef", "0612345678");
    Contact c3("Sara", "0712345678", "sara@gmail.com");

    c1.afficher();
    c2.afficher();
    c3.afficher();

    return 0;
}
