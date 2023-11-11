#include "my_lib.h"

float median_l(list<int> pazymiai)
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

float mean_l(list<int> pazymiai, int egzaminas)
{
    float suma=0, rezultatas;
    for (auto &a: pazymiai)
        suma = suma + a;
    rezultatas = (suma/pazymiai.size())*0.4 + egzaminas*0.6;
    return rezultatas;
}

void print_mean_l(list<stipendininkas> kursas)
{
    cout<<"Pavarde             "<<"Vardas              "<<"Galutinis (Vid.)"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for (auto &a: kursas)
        cout<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.rez<<endl;
}

void print_median_l(list<stipendininkas> kursas)
{
    cout<<"Pavarde             "<<"Vardas              "<<"Galutinis (Med.)"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for (auto &a: kursas)
        cout<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.mediana<<endl;
}

void print_mean_median_l (list<stipendininkas> kursas)
{
    cout<<"Pavarde             Vardas              Galutinis (Vid.)    Galutinis (Med.)"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    for (auto &a: kursas)
        cout<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(20)<<fixed<<setprecision(2)<<a.rez<<setw(5)<<a.mediana<<endl;
}

void Failo_nuskaitymas_l (string pavadinimas, struct stipendininkas stip, list <stipendininkas> &kursas)
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
        stip.rez = mean_l(stip.pazymiai, stip.egz);
        stip.mediana = median_l(stip.pazymiai);
        kursas.push_back(stip);
        stip.pazymiai.clear();
    }
    failas.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Failo nuskaitymas uztruko: "<< diff.count() << " s\n";
}

void Failo_rusiavimas1_l (list <stipendininkas> kursas)
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
    print_file_l("gudruciai.txt", gudruciai);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2-start2;
    std::cout << "Gudruciu failo kurimas uztruko: "<< diff2.count() << " s\n";

    auto start3 = std::chrono::high_resolution_clock::now();
    print_file_l("neismaneliai.txt", neismaneliai);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3-start3;
    std::cout << "Neismaneliu failo kurimas uztruko: "<< diff3.count() << " s\n";
}

void Failo_rusiavimas2_l (list<stipendininkas> kursas)
{
    list<stipendininkas> neismaneliai;

    for (auto &a: kursas)
            a.x = 3;
    kursas.sort();

    auto start = std::chrono::high_resolution_clock::now();
    while (!kursas.empty() && kursas.front().rez < 5)
    {
        neismaneliai.push_front(kursas.front());
        kursas.pop_front();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Failo rusiavimas uztruko: "<< diff.count() << " s\n";

    int pasirinkimas = rusiavimui();
    for (auto &a: kursas)
        a.x = pasirinkimas;
    kursas.sort();
    for (auto &b: neismaneliai)
        b.x = pasirinkimas;
    neismaneliai.sort();

    auto start2 = std::chrono::high_resolution_clock::now();
    print_file_l("gudruciai.txt", kursas);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2-start2;
    std::cout << "Gudruciu failo kurimas uztruko: "<< diff2.count() << " s\n";

    auto start3 = std::chrono::high_resolution_clock::now();
    print_file_l("neismaneliai.txt", neismaneliai);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3-start3;
    std::cout << "Neismaneliu failo kurimas uztruko: "<< diff3.count() << " s\n";
}


void print_file_l(string pavadinimas, list<stipendininkas> studentai)
{
    ofstream g(pavadinimas);
    g<<"Pavarde             Vardas              Galutinis (Vid.)"<<endl;
    for (auto &a: studentai)
        g<<left<<setw(20)<<a.pavarde<<setw(20)<<a.vardas<<setw(5)<<fixed<<setprecision(2)<<a.rez<<endl;
}




