#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Article {
    string nom;
    double prixUnitaire;
    int quantite;
    double tva;
};

class Facture {
private:
    vector<Article> articles;

public:
    void ajouterArticle(string nom, double prix) {
        Article a = {nom, prix, 1, 0.0};
        articles.push_back(a);
    }

    void ajouterArticle(string nom, double prix, int quantite) {
        Article a = {nom, prix, quantite, 0.0};
        articles.push_back(a);
    }

    void ajouterArticle(string nom, double prix, int quantite, double tva) {
        Article a = {nom, prix, quantite, tva};
        articles.push_back(a);
    }

    void afficherTotal() const {
        double totalHT = 0.0;
        double totalTTC = 0.0;

        cout << "=== Détails de la facture ===" << endl;
        for (const auto& a : articles) {
            double sousTotal = a.prixUnitaire * a.quantite;
            double montantTVA = sousTotal * (a.tva / 100.0);
            double totalArticle = sousTotal + montantTVA;

            cout << "Article : " << a.nom
                 << " | Prix : " << a.prixUnitaire
                 << " | Qte : " << a.quantite
                 << " | TVA : " << a.tva << "%"
                 << " | Total : " << totalArticle << " DH" << endl;

            totalHT += sousTotal;
            totalTTC += totalArticle;
        }

        cout << "\nTotal HT : " << totalHT << " DH" << endl;
        cout << "Total TTC : " << totalTTC << " DH" << endl;
        cout << "=============================" << endl;
    }
};

int main() {
    Facture f;
    f.ajouterArticle("Stylo", 5.0);
    f.ajouterArticle("Cahier", 10.0, 3);
    f.ajouterArticle("Clé USB", 50.0, 2, 20.0);
    f.afficherTotal();
    return 0;
}
