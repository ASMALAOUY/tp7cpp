#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    double solde;
    string codeSecurite;

public:
    CompteBancaire() {
        solde = 0.0;
        codeSecurite = "0000";
    }

    CompteBancaire(double s) {
        solde = s;
        codeSecurite = "0000";
    }

    CompteBancaire(double s, string code) {
        solde = s;
        codeSecurite = code;
    }

    void afficherSolde() const {
        cout << "Solde actuel : " << solde << " DH" << endl;
    }

    void retrait(double montant) {
        if (montant <= 0) {
            cout << "Montant invalide." << endl;
            return;
        }
        if (montant > solde) {
            cout << "Solde insuffisant." << endl;
            return;
        }
        solde -= montant;
        cout << "Retrait de " << montant << " DH effectue." << endl;
        afficherSolde();
    }

    void retrait(double montant, string code) {
        if (code != codeSecurite) {
            cout << "Code de securite incorrect." << endl;
            return;
        }
        retrait(montant);
    }
};

int main() {
    CompteBancaire c1;
    CompteBancaire c2(1000.0);
    CompteBancaire c3(2000.0, "1234");

    c1.afficherSolde();
    c2.afficherSolde();
    c3.afficherSolde();

    c2.retrait(200);
    c3.retrait(500, "1234");
    c3.retrait(300, "0000");

    return 0;
}
