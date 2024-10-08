#include "rezultatas.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Atspausdinam studentų duomenis
void spausdinti(const vector<Studentas>& studentai, bool choice) {
    string pasirinkimas_pav;
    double pasirinkimas;

    if (choice == 0) {
        pasirinkimas_pav = "(Vid.)";
    } else {
        pasirinkimas_pav = "(Med.)";
    }

    stringstream buffer;  // naudojam stringstream

    buffer << "\n----------------------------------------------\n";
    buffer << left << setw(15) << "Pavardė"
           << setw(15) << "Vardas"
           << "Galutinis "
           << pasirinkimas_pav << endl;
    buffer << "----------------------------------------------\n";

    for (const auto& studentas : studentai) {
        if (choice == 0) {
            pasirinkimas = vidurkis(studentas.nd, studentas.egz);
        } else {
            pasirinkimas = mediana(studentas.nd, studentas.egz);
        }
        buffer << left << setw(15) << studentas.pavarde
               << setw(15) << studentas.vardas
               << setw(20) << fixed << setprecision(2) << pasirinkimas
               << endl;
    }

    cout << buffer.str() << flush;  // visk1 atspausdinam vienu metu
}
