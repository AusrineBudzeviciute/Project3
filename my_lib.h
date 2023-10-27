#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <random>
#include <ctime>
#include <algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;
using std::ifstream;
using std::istringstream;
using std::invalid_argument;
using std::cerr;
using std::exception;
using std::ofstream;
using std::to_string;
using namespace std::chrono;

struct stipendininkas {
    string vardas, pavarde;
    list<int> pazymiai;
    int egz;
    float rez, mediana;
    int x;

    bool operator<(const stipendininkas& o) const {
        if (x == 1) return vardas < o.vardas;
        else if (x == 2) return pavarde < o.pavarde;
        else if (x == 3) return rez < o.rez;
    }
};


int generate_random();
int rusiavimui();
float median(list<int> pazymiai);
float mean(list<int> pazymiai, int egzaminas);
void print_mean(list<stipendininkas> kursas);
void print_median(list<stipendininkas> kursas);
void print_mean_median (list<stipendininkas> kursas);
void tikrinimas(int& x);
void Failo_nuskaitymas (string pavadinimas, struct stipendininkas stip, list <stipendininkas> &kursas);
void Failo_kurimas (int studentusk);
void Failo_rusiavimas (list <stipendininkas> kursas);
void print_file(string pavadinimas, list<stipendininkas> studentai);









