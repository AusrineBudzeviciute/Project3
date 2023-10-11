
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


void darbas_su_failu(string pavadinimas, struct studentas stud)
{
    ifstream failas(pavadinimas);
    if(failas.fail()) cout<<"Failo atidarymo klaida."<<endl;

    string antraste;
    for (int i = 0; i<1; i++) getline(failas,antraste);

    istringstream iss(antraste);
    string namudarbas;
    int sk = 0;

    while (iss >> namudarbas)
    {
        if (namudarbas.substr(0, 2) == "ND") sk++;
    }
            vector <studentas> gudruciai, vargsiukai;
    while(failas >> stud.vardas >> stud.pavarde)
    {
        for(int i=0; i<sk; i++)
        {
            int paz;
            if(!(failas>>paz)) throw invalid_argument("Netinkamas pazymys faile.");
            if (paz<=0 || paz>10) throw invalid_argument("Netinkamas pazymys faile.");
            stud.pazymiai.push_back(paz);
        }
        failas >> stud.egz;
        stud.rez = mean(stud.pazymiai, stud.egz);

        if (stud.rez >= 5)
        {
            gudruciai.push_back(stud);
        }
        else vargsiukai.push_back(stud);
        stud.pazymiai.clear();
        sort(gudruciai.begin(), gudruciai.end());
        sort(vargsiukai.begin(), vargsiukai.end());
    }

    print_studentai("gudruciai.txt",gudruciai);
    print_studentai("vargsiukai.txt",vargsiukai);

    failas.close();
}

void print_studentai(string pavadinimas, vector<studentas> studentai)
{
    ofstream g(pavadinimas);
    g<<"Pavarde             Vardas              Galutinis (Vid.)"<<endl;
    g<<"---------------------------------------------------------"<<endl;
    for (auto &a: studentai)
        g<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.rez<<endl;
}





