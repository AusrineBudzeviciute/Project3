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

struct studentas {
        string vardas, pavarde;
        vector <int> pazymiai;
        int egz;
        float rez, mediana;

        int x;
        bool operator<(const studentas& o) const{
            if(x == 1) return vardas < o.vardas;
            else if (x == 2) return pavarde < o.pavarde;
            else if (x == 3) return rez < o.rez;
            else if (x == 4) return o.rez < rez;
        }
};

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
void tikrinimas(int& x);
void Failo_kurimas (int studentusk);

/* VEKTORIUS */
int vektorius();
float median(vector<int> pazymiai);
float mean(vector<int> pazymiai, int egzaminas);
void print_mean(vector<studentas> grupe);
void print_median(vector<studentas> grupe);
void print_mean_median (vector<studentas> grupe);
void Failo_nuskaitymas (string pavadinimas, struct studentas stud, vector <studentas> &grupe);
void Failo_rusiavimas1 (vector <studentas> grupe);
void Failo_rusiavimas2 (vector<studentas> &grupe);
void print_file(string pavadinimas, vector<studentas> studentai);

/* LISTAS */
int listas();
float median_l(list<int> pazymiai);
float mean_l(list<int> pazymiai, int egzaminas);
void print_mean_l(list<stipendininkas> kursas);
void print_median_l(list<stipendininkas> kursas);
void print_mean_median_l (list<stipendininkas> kursas);
void Failo_nuskaitymas_l (string pavadinimas, struct stipendininkas stip, list <stipendininkas> &kursas);
void Failo_rusiavimas1_l (list <stipendininkas> kursas);
void Failo_rusiavimas2_l (list<stipendininkas> kursas);
void print_file_l(string pavadinimas, list<stipendininkas> studentai);
