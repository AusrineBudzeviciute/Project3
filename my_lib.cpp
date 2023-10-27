#include "my_lib.h"


int generate_random() {
    static std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}

int rusiavimui()
{
    int pasirinkimas;
    cout<<"Iveskite parametra, pagal kuri rusiuojamas failas (1- vardas, 2 - pavarde, 3 - rezultatas): ";
    cin>>pasirinkimas;
    return pasirinkimas;
}

float median(list<int> pazymiai)
{
    pazymiai.sort();
    int size = pazymiai.size();
    auto p = pazymiai.begin();
    advance(p, size/2);
    if (size%2 == 0){
        int med1 = *p;
        --p;
        int med2 = *p;
        return static_cast<float>(med1 + med2)/2;
    }
    else
        return static_cast<float>(*p);
}

float mean(list<int> pazymiai, int egzaminas)
{
    float suma=0, rezultatas;
    for (auto &a: pazymiai)
        suma = suma + a;
    rezultatas = (suma/pazymiai.size())*0.4 + egzaminas*0.6;
    return rezultatas;
}

void print_mean(list<stipendininkas> kursas)
{
    cout<<"Pavarde             "<<"Vardas              "<<"Galutinis (Vid.)"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for (auto &a: kursas)
        cout<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.rez<<endl;
}

void print_median(list<stipendininkas> kursas)
{
    cout<<"Pavarde             "<<"Vardas              "<<"Galutinis (Med.)"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for (auto &a: kursas)
        cout<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.mediana<<endl;
}

void print_mean_median (list<stipendininkas> kursas)
{
    cout<<"Pavarde             Vardas              Galutinis (Vid.)    Galutinis (Med.)"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    for (auto &a: kursas)
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


void Failo_nuskaitymas (string pavadinimas, struct stipendininkas stip, list <stipendininkas> &kursas)
{
    auto start = std::chrono::high_resolution_clock::now();
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

    while(failas >> stip.vardas >> stip.pavarde)
    {
        for(int i=0; i<sk; i++)
        {
            int paz;
            if(!(failas>>paz)) throw invalid_argument("Netinkamas pazymys faile.");
            if (paz<=0 || paz>10) throw invalid_argument("Netinkamas pazymys faile.");
            stip.pazymiai.push_back(paz);
        }
        failas >> stip.egz;
        stip.rez = mean(stip.pazymiai, stip.egz);
        stip.mediana = median(stip.pazymiai);
        kursas.push_back(stip);
        stip.pazymiai.clear();
    }
    failas.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Failo nuskaitymas uztruko: "<< diff.count() << " s\n";
}


void Failo_kurimas (int studentusk)
{
    auto start = std::chrono::high_resolution_clock::now();
    ofstream file ("studentai"+to_string(studentusk)+".txt");
    if (!file){cerr<<"Failo klaida."<<endl;}

    file << "Vardas              Pavarde             ND1  ND2  ND3  ND4  ND5  egz"<<endl;
    for (int i = 1; i <= studentusk; i++)
    {
        file <<left<<setw(20)<<"Vardas"+to_string(i)<<left<<setw(20)<< "Pavarde"+to_string(i);

        for (int i = 1; i < 6; i++){
            file <<left<<setw(5)<< generate_random();
        }
        file<<left<< setw(5) << generate_random() <<endl;
    }
    file.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Failo kurimas uztruko: "<< diff.count() << " s\n";
}

void Failo_rusiavimas (list <stipendininkas> kursas)
{
    list <stipendininkas> gudruciai, neismaneliai;
    auto start = std::chrono::high_resolution_clock::now();
    for (auto &a: kursas)
    {
        if (a.rez >= 5) gudruciai.push_back(a);
        else if (a.rez < 5) neismaneliai.push_back(a);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Failo rusiavimas uztruko: "<< diff.count() << " s\n";


    auto start2 = std::chrono::high_resolution_clock::now();
    print_file("gudruciai.txt", gudruciai);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2-start2;
    std::cout << "Gudruciu failo kurimas uztruko: "<< diff2.count() << " s\n";

    auto start3 = std::chrono::high_resolution_clock::now();
    print_file("neismaneliai.txt", neismaneliai);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3-start3;
    std::cout << "Neismaneliu failo kurimas uztruko: "<< diff3.count() << " s\n";
}


void print_file(string pavadinimas, list<stipendininkas> studentai)
{
    ofstream g(pavadinimas);
    g<<"Pavarde             Vardas              Galutinis (Vid.)"<<endl;
    for (auto &a: studentai)
        g<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.rez<<endl;
}




