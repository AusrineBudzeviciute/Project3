#include "my_lib.h"

int generate_random()
{
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
