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
        }

};





int rusiavimui();
int generate_random();
float median(vector<int> pazymiai);
float mean(vector<int> pazymiai, int egzaminas);
void print_mean(vector<studentas> grupe);
void print_median(vector<studentas> grupe);
void print_mean_median (vector<studentas> grupe);
void tikrinimas(int& x);
void Failo_nuskaitymas (string pavadinimas, struct studentas stud, vector <studentas> &grupe);
void Failo_kurimas (int studentusk);
void darbas_su_failu(string pavadinimas, struct studentas stud);
void print_file(string pavadinimas, vector<studentas> studentai);
void Failo_rusiavimas (vector <studentas> grupe);







