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
using std::istream;
using std::ostream;



class zmogus{
protected:
    string vardas_, pavarde_;
    zmogus() {}
public:
    virtual ~zmogus() {}
    virtual string getVardas() const {return vardas_;}
    virtual string getPavarde() const {return pavarde_;}
    virtual void setVardas(string vardas) {vardas_ = vardas;}
    virtual void setPavarde(string pavarde) {pavarde_ = pavarde;}

};


class studentas : public zmogus{
private:
    int egz_;
    vector<int> pazymiai;
    float rez_, mediana_;
    double *elem;
public:
    studentas() : zmogus(), egz_(0), rez_(0), mediana_(0), elem(nullptr) {}
    ~studentas(); //destruktorius
    studentas(const studentas& o); //kopijavimo konstruktorius
    studentas& operator=(const studentas& o); //priskyrimo operatorius

    friend istream& operator>>(istream& is, studentas &s){ //ivesties operatorius
          string vardas, pavarde;
          is>>vardas>>pavarde;
          s.setVardas(vardas);
          s.setPavarde(pavarde);
          return is;}

      friend ostream& operator<<(ostream& os, const studentas &s){ //isvesties operatorius
          os<<left<<setw(20)<<s.getVardas()<<setw(20)<<s.getPavarde();
          return os;}

    string getVardas() const { return zmogus::getVardas(); }
    string getPavarde() const { return zmogus::getPavarde(); }
    vector<int> getPazymiai() const { return pazymiai; }
    int getEgz() const { return egz_; }
    float getRez() const { return rez_; }
    float getMediana() const { return mediana_; }
    void setVardas(string vardas) { zmogus::setVardas(vardas); }
    void setPavarde(string pavarde) { zmogus::setPavarde(pavarde); }
    void setPazymiai(int);
    void setEgz(int);
    void setRez(float);
    void setMediana(float);
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
void Failo_nuskaitymas (string pavadinimas, studentas& stud, vector <studentas> &grupe);
void Failo_kurimas (int studentusk);
void Failo_rusiavimas (vector<studentas> grupe);
void print_file(string pavadinimas, vector<studentas> studentai);


