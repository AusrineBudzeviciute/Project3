#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stdexcept>


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

struct studentas {
        string vardas, pavarde;
        vector <int> pazymiai;
        int egz;
        float rez, mediana;

        bool operator<(const studentas& o) const
        {
            return pavarde < o.pavarde;
        }
    };



int generate_random();
float median(vector<int> pazymiai);
float mean(vector<int> pazymiai, int egzaminas);
void print_mean(vector<studentas> grupe);
void print_median(vector<studentas> grupe);
void print_mean_median (vector<studentas> grupe);
void tikrinimas(int& x);
void Failo_kurimas (int studentusk);
void darbas_su_failu(string pavadinimas, struct studentas stud);
void print_studentai(string pavadinimas, vector<studentas> studentai);






