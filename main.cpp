#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>


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

    int n;
    cout<<"Iveskite, kiek studentu yra sarase:"<<endl;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        cout<<"Iveskite varda ir pavarde: "<<endl;
        cin>>stud.vardas>>stud.pavarde;


        char ivedimas;
        int skaicius, p, m=0;
        cout<<"Iveskite '+', jeigu norite, kad studento pazymius bei egzamino rezultatus sugeneruotu automatiskai. Iveskite '-', jeigu ivesite patys";
        cin>>ivedimas;
        if (ivedimas == '+')
        {
            cout<<"Iveskite, kiek pazymiu generuojama";
            cin>>skaicius;
            srand(time(0));
            for(int j=0;j<skaicius;j++)
                stud.pazymiai.push_back((rand()%10)+1);
            sort(stud.pazymiai.begin(), stud.pazymiai.end());

            stud.egz = (rand()%10) + 1;

            if (skaicius % 2 == 0) stud.mediana =( stud.pazymiai[skaicius/2] + stud.pazymiai[(skaicius/2)-1] )/2.0;
            else stud.mediana = stud.pazymiai[(skaicius/2)];


            float suma1=0;
            for (auto &k: stud.pazymiai)
                suma1 = suma1 + k;
            stud.rez = (suma1/skaicius)*0.4 + stud.egz*0.6;


        }

        else
        {
            cout<<"Iveskite pazymi (0 zymi pazymiu ivedimo pabaiga)";
            cin>>p;
            while (p != 0)
            {
                m++;
                stud.pazymiai.push_back(p);
                cout<<"Iveskite pazymi (0 zymi pazymiu ivedimo pabaiga)";
                cin>>p;
            }
            sort(stud.pazymiai.begin(), stud.pazymiai.end());

            cout<<"Iveskite egzamino rezultata: "<<endl;
            cin>>stud.egz;

            if (m % 2 == 0) stud.mediana =( stud.pazymiai[m/2] + stud.pazymiai[(m/2)-1] )/2.0;
            else stud.mediana = stud.pazymiai[(m/2)];

            float suma2=0;
            for (auto &k: stud.pazymiai)
                suma2 = suma2 + k;
            stud.rez = (suma2/m)*0.4 + stud.egz*0.6;

        }


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










