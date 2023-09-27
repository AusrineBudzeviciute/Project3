#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>


using namespace std;

struct studentas {
        string vardas, pavarde;
        vector <int> pazymiai;
        int egz;
        float rez, mediana;
    };

int generate_random();
float median(vector<int> pazymiai);
float mean(vector<int> pazymiai, int egzaminas);
void print_mean(vector<studentas> grupe);
void print_median(vector<studentas> grupe);

