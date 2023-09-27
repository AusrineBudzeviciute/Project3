#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    struct studentas {
        string vardas, pavarde;
        vector <int> pazymiai;
        int egz;
        float rez, mediana;
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
        sort(stud.pazymiai.begin(), stud.pazymiai.end());

        cout<<"Iveskite egzamino rezultata: "<<endl;
        cin>>stud.egz;

        float suma=0;
        for (auto &k: stud.pazymiai)
            suma = suma + k;
        stud.rez = (suma/m)*0.4 + stud.egz*0.6;


        if (m % 2 == 0)
            stud.mediana =( stud.pazymiai[m/2] + stud.pazymiai[(m/2)-1] )/2.0;
        else
            stud.mediana = stud.pazymiai[(m/2)];

        grupe.push_back(stud);
        stud.pazymiai.clear();
    }


    char isvedimas;
    cout<<"Iveskite 'V', jeigu norite matyti vidurki, iveskite 'M', jeigu norite matyti mediana";
    cin>>isvedimas;
    if (isvedimas == 'V')
    {
        cout<<"Pavarde             "<<"Vardas              "<<"Galutinis (Vid.)"<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        for (auto &a: grupe)
            cout<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.rez<<endl;
    }
    else
    {
        cout<<"Pavarde             "<<"Vardas              "<<"Galutinis (Med.)"<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        for (auto &a: grupe)
            cout<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.mediana<<endl;
    }





}









