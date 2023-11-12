#include "my_lib.h"

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

void Failo_nuskaitymas (string pavadinimas, struct studentas stud, vector <studentas> &grupe)
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Failo nuskaitymas uztruko: "<< diff.count() << " s\n";
}

void Failo_rusiavimas1 (vector <studentas> grupe)
{
    vector <studentas> gudruciai, neismaneliai;
    auto start = std::chrono::high_resolution_clock::now();
    for (auto &a: grupe)
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

void Failo_rusiavimas2 (vector<studentas> grupe)
{
    vector<studentas> neismaneliai;

    auto start = std::chrono::high_resolution_clock::now();
    for (auto &a: grupe)
        a.x = 4;
    sort(grupe.begin(), grupe.end());
    while (!grupe.empty() && grupe.back().rez < 5)
    {
        neismaneliai.push_back(grupe.back());
        grupe.pop_back();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Failo rusiavimas uztruko: "<< diff.count() << " s\n";

    int pasirinkimas = rusiavimui();
    for (auto &a: grupe)
        a.x = pasirinkimas;
    sort(grupe.begin(), grupe.end());
    for (auto &b: neismaneliai)
        b.x = pasirinkimas;
    sort(neismaneliai.begin(), neismaneliai.end());

    auto start2 = std::chrono::high_resolution_clock::now();
    print_file("gudruciai.txt", grupe);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2-start2;
    std::cout << "Gudruciu failo kurimas uztruko: "<< diff2.count() << " s\n";

    auto start3 = std::chrono::high_resolution_clock::now();
    print_file("neismaneliai.txt", neismaneliai);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3-start3;
    std::cout << "Neismaneliu failo kurimas uztruko: "<< diff3.count() << " s\n";
}

void Failo_rusiavimas3 (vector<studentas> grupe)
{
    vector<studentas> neismaneliai, gudruciai;

    auto start = std::chrono::high_resolution_clock::now();

    auto partitionPoint = std::partition(grupe.begin(), grupe.end(), [](const auto& a) {
    return a.rez < 5;});
    gudruciai.insert(gudruciai.end(), partitionPoint, grupe.end());
    neismaneliai.insert(neismaneliai.end(), grupe.begin(), partitionPoint);
    grupe.erase(partitionPoint, grupe.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Failo rusiavimas uztruko: "<< diff.count() << " s\n";

    int pasirinkimas = rusiavimui();
    for (auto &a: gudruciai)
        a.x = pasirinkimas;
    sort(gudruciai.begin(), gudruciai.end());
    for (auto &b: neismaneliai)
        b.x = pasirinkimas;
    sort(neismaneliai.begin(), neismaneliai.end());

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

void print_file(string pavadinimas, vector<studentas> studentai)
{
    ofstream g(pavadinimas);
    g<<"Pavarde             Vardas              Galutinis (Vid.)"<<endl;
    for (auto &a: studentai)
        g<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.rez<<endl;
}




