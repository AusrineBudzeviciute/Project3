#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <list>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <random>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <typeinfo>
#include <type_traits>


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
using std::stable_partition;
using std::copy;


class studentas {
    private:
      string vardas_, pavarde_;
      int egz_;
      vector<int> pazymiai;
      float rez_, mediana_;

    public:
      studentas() : egz_(0) { }
      ~studentas() {}
      string getVardas() const { return vardas_; }
      string getPavarde() const { return pavarde_; }
      vector<int> getPazymiai() const { return pazymiai; }
      int getEgz() const { return egz_; }
      float getRez() const { return rez_; }
      float getMediana() const { return mediana_; }

      void setVardas(string);
      void setPavarde(string);
      void setEgz(int);
      void setRez(float);
      void setMediana(float);
      void setPazymiai(int);
      void clearPazymiai();

};

bool pagalVarda(const studentas&, const studentas&);
bool pagalPavarde(const studentas&, const studentas&);
bool pagalRezultata(const studentas&, const studentas&);

int generate_random();
int rusiavimui();
void tikrinimas(int& x);
float median(vector<int> pazymiai);
float mean(vector<int> pazymiai, int egzaminas);
void print_mean(vector<studentas> grupe);
void print_median(vector<studentas> grupe);
void print_mean_median (vector<studentas> grupe);
void Failo_nuskaitymas (string pavadinimas, studentas stud, vector <studentas> &grupe);
void Failo_rusiavimas (vector<studentas> grupe);
void print_file(string pavadinimas, vector<studentas> studentai);

