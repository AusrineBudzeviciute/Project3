#include "my_lib.h"
/*
auto start = std::chrono::high_resolution_clock::now(); // Paleisti
auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
std::chrono::duration<double> diff = end-start; // Skirtumas (s)
std::cout << "10 000 000 elementų užpildymas užtruko: "<< diff.count() << " s\n";
*/
int main()
{
    studentas stud;
    vector <studentas> grupe;
    int ivedimas1;
    cout<<"Iveskite: '1' - failo nuskaitymui; '2' - duomenu ivedimui; '3' - failo generavimui: ";
    cin>>ivedimas1;

try{
    if (ivedimas1 == 1)
    {
        string pav;
        cout<<"Iveskite failo pavadinima: ";
        cin>>pav;
        Failo_nuskaitymas(pav, stud, grupe);
        int pasirinkimas = rusiavimui();
        for (auto &a: grupe)
            a.x = pasirinkimas;
        sort(grupe.begin(), grupe.end());
        Failo_rusiavimas(grupe);
    }


    else if (ivedimas1==2)
    {
        int n;
        cout<<"Iveskite, kiek studentu yra sarase:"<<endl;
        cin>>n;
        tikrinimas(n);

        for (int i=0; i<n; i++)
        {
            cout<<"Iveskite varda ir pavarde: "<<endl;
            cin>>stud.vardas>>stud.pavarde;

            char ivedimas2;
            cout<<"Iveskite: '+' - duomenu generavimui; '-' - duomenu ivedimui: ";
            cin>>ivedimas2;
            if (ivedimas2 == '+')
            {
                int skaicius;
                cout<<"Iveskite, kiek pazymiu generuojama: ";
                cin>>skaicius;
                tikrinimas(skaicius);

                for(int j=0; j<skaicius; j++)
                    stud.pazymiai.push_back(generate_random());
                stud.egz = generate_random();
                stud.mediana = median(stud.pazymiai);
                stud.rez = mean(stud.pazymiai, stud.egz);
                grupe.push_back(stud);
                stud.pazymiai.clear();
            }

            else if (ivedimas2 == '-')
            {
                int p;
                cout<<"Iveskite pazymi (0 zymi pazymiu ivedimo pabaiga): ";
                cin>>p;

                if (cin.fail() || p < 0 || p > 10)
                    throw invalid_argument("Pateiktas netinkamas skaicius.");

                while (p != 0)
                {
                    stud.pazymiai.push_back(p);
                    cout<<"Iveskite pazymi (0 zymi pazymiu ivedimo pabaiga): ";
                    cin>>p;
                    if (cin.fail() || p < 0 || p > 10)
                        throw invalid_argument("Pateiktas netinkamas skaicius.");
                }

                cout<<"Iveskite egzamino rezultata: "<<endl;
                cin>>stud.egz;

                stud.mediana = median(stud.pazymiai);
                stud.rez = mean(stud.pazymiai, stud.egz);
                grupe.push_back(stud);
                stud.pazymiai.clear();
            }
        }
        sort(grupe.begin(), grupe.end());
        char ivedimas3;
        cout<<"Iveskite: 'V' - vidurkio isvedimui; 'M' - medianos isvedimui: ";
        cin>>ivedimas3;
        if (ivedimas3 == 'V') print_mean(grupe);
        else print_median(grupe);
    }

    else if (ivedimas1 == 3)
    {
        int studentusk;
        cout<<"Iveskite, kiek studentu generuojama: ";
        cin>>studentusk;
        Failo_kurimas(studentusk);
    }


}
    catch (const exception& e) {
            cerr << "Klaida: " << e.what() << endl;
            return 1;}

    system("pause");
    return 0;
}




