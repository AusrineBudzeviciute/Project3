#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;


int main()
{
    struct studentas {
        string vardas, pavarde;
        vector <int> pazymiai;
        int egz;
        float rez;
    };

    studentas stud;
    vector <studentas> grupe;

    int n, m;
    cout<<"Iveskite, kiek studentu yra sarase:"<<endl;
    cin>>n;
    cout<<"Iveskite pazymiu skaiciu: "<<endl;
    cin>>m;

    for (int i=0; i<n; i++)
    {
        cout<<"Iveskite varda ir pavarde: "<<endl;
        cin>>stud.vardas>>stud.pavarde;
        for (int j=0; j<m; j++) {
            int p;
            cout<<"Iveskite "<<j+1<<" pazymi: ";
            cin>>p;
            stud.pazymiai.push_back(p);
        }
        cout<<"Iveskite egzamino rezultata: "<<endl;
        cin>>stud.egz;

        float suma=0;
        for (auto &k: stud.pazymiai)
            suma = suma + k;
        stud.rez = (suma/m)*0.4 + stud.egz*0.6;

        grupe.push_back(stud);
        stud.pazymiai.clear();
    }

    cout<<"Pavarde             "<<"Vardas              "<<"Galutinis (Vid.)"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    for (auto &a: grupe){
        cout<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.rez<<endl;
    }

}








