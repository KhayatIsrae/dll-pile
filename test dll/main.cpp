#include <iostream>
#include "pile.h"
#include "pile_ptr.h"
#include <string.h>
#include <chrono>

using namespace std;
int main() {
    char expr[100];

    cout << "Entrez une expression : ";
    cin.getline(expr, 100);

    auto debut = chrono::steady_clock::now();

    int resultat = est_correcte_ptr(expr);

    auto fin = chrono::steady_clock::now();

    auto duree = chrono::duration_cast<chrono::nanoseconds>(
        fin - debut
    ).count();

    if (resultat)
        cout << "Expression correcte" << endl;
    else
        cout << "Expression incorrecte" << endl;

    cout << "Temps d'execution : "
         << duree << " ns" << endl;

    return 0;
}
