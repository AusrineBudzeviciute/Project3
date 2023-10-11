
#include "my_lib.h"

int generate_random()
{
    srand(time(0));
    return (rand()%10)+1;
}

float median(vector<int> pazymiai)
{
    float mediana;
    sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size()%2 == 0)
        mediana = (pazymiai[pazymiai.size()/2] + pazymiai[(pazymiai.size()/2)-1])/2.0;
    else
        mediana = pazymiai[(pazymiai.size()/2)];
    return mediana;
}


float mean(vector<int> pazymiai, int egzaminas)
{
    float suma=0, rezultatas;
    for (auto &a: pazymiai)
        suma = suma + a;
    rezultatas = (suma/pazymiai.size())*0.4 + egzaminas*0.6;
    return rezultatas;
}

void print_mean(vector<studentas> grupe)
{
    cout<<"Pavarde             "<<"Vardas              "<<"Galutinis (Vid.)"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for (auto &b: grupe)
        cout<<left<<setw(20)<<b.pavarde<<setw(20)<<b.vardas<<setw(5)<<fixed<<setprecision(2)<<b.rez<<endl;
}

void print_median(vector<studentas> grupe)
{
    cout<<"Pavarde             "<<"Vardas              "<<"Galutinis (Med.)"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for (auto &c: grupe)
        cout<<left<<setw(20)<<c.pavarde<<setw(20)<<c.vardas<<setw(5)<<fixed<<setprecision(2)<<c.mediana<<endl;
}

void print_mean_median (vector<studentas> grupe)
{
    cout<<"Pavarde             Vardas              Galutinis (Vid.)    Galutinis (Med.)"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    for (auto &d: grupe)
        cout<<left<<setw(20)<<d.pavarde<<setw(20)<<d.vardas<<setw(20)<<fixed<<setprecision(2)<<d.rez<<setw(5)<<d.mediana<<endl;
}


void tikrinimas(int& x)
{
    try{
        if (cin.fail() || x <= 0)
            throw invalid_argument("Pateiktas netinkamas skaicius.");}
    catch (const invalid_argument& e)
    {
        cerr<< e.what()<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Iveskite is naujo: ";
        cin>>x;
        tikrinimas(x);
    }
}


void Failo_kurimas (int studentusk)
{
    ofstream file ("studentai.txt");
    if (!file){cerr<<"Failo klaida."<<endl;}

    file << "Vardas              Pavarde             ND1  ND2  ND3  ND4  ND5  egz"<<endl;
    srand(time(0));
    for (int i = 1; i <= studentusk; i++)
    {
        vector <int> pazymiai;
        int rezultatas;

        for (int i = 1; i < 6; i++){
            pazymiai.push_back((rand()%10)+1);
        }
        rezultatas = (rand()%10)+1;

        file <<left<<setw(20)<<"Vardas"+to_string(i)<<left<<setw(20)<< "Pavarde"+to_string(i);
        for (auto &a: pazymiai)
            file <<left<<setw(5)<< a;
        file<<left<< setw(5) << rezultatas<<endl;
    }

    file.close();
}
