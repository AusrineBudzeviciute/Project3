
#include "my_lib.h"

int generate_random()
{
    srand(time(0));
    return (rand()%10)+1;
}

int rusiavimui()
{
    int pasirinkimas;
    cout<<"Iveskite parametra, pagal kuri rusiuojamas failas (1- vardas, 2 - pavarde, 3 - rezultatas): ";
    cin>>pasirinkimas;
    return pasirinkimas;
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
    for (auto &a: grupe)
        cout<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(20)<<fixed<<setprecision(2)<<a.rez<<setw(5)<<a.mediana<<endl;
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


void Failo_nuskaitymas (string pavadinimas, struct studentas stud, vector <studentas> &grupe)
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
        stud.mediana = median(stud.pazymiai);
        grupe.push_back(stud);
        stud.pazymiai.clear();
    }
    failas.close();
}


void Failo_kurimas (int studentusk)
{
    ofstream file ("studentai"+to_string(studentusk)+".txt");
    if (!file){cerr<<"Failo klaida."<<endl;}

    srand(time(0));
    file << "Vardas              Pavarde             ND1  ND2  ND3  ND4  ND5  egz"<<endl;
    for (int i = 1; i <= studentusk; i++)
    {
        file <<left<<setw(20)<<"Vardas"+to_string(i)<<left<<setw(20)<< "Pavarde"+to_string(i);

        for (int i = 1; i < 6; i++){
            file <<left<<setw(5)<< (rand()%10)+1;
        }
        file<<left<< setw(5) << (rand()%10)+1 <<endl;
    }
    file.close();
}

void Failo_rusiavimas (vector <studentas> grupe)
{
    vector <studentas> gudruciai, neismaneliai;
    for (auto &a: grupe)
    {
        if (a.rez >= 5) gudruciai.push_back(a);
        else if (a.rez < 5) neismaneliai.push_back(a);
    }
    sort(gudruciai.begin(), gudruciai.end());
    sort(neismaneliai.begin(), neismaneliai.end());
    print_file("gudruciai.txt", gudruciai);
    print_file("neismaneliai.txt", neismaneliai);
}


void print_file(string pavadinimas, vector<studentas> studentai)
{
    ofstream g(pavadinimas);
    g<<"Pavarde             Vardas              Galutinis (Vid.)"<<endl;
    for (auto &a: studentai)
        g<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.rez<<endl;
}




