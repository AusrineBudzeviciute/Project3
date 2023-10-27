#include "my_lib.h"


int main()
{
try{

    stipendininkas stip;
    list <stipendininkas> kursas;
    int ivedimas1;
    cout<<"Iveskite: '1' - failo nuskaitymui; '2' - duomenu ivedimui; '3' - failo generavimui: ";
    cin>>ivedimas1;

    if(ivedimas1 == 1)
    {
        string pav;
        cout<<"Iveskite failo pavadinima: ";
        cin>>pav;
        Failo_nuskaitymas(pav, stip, kursas);
        int pasirinkimas = rusiavimui();
        for (auto &a: kursas)
            a.x = pasirinkimas;
        kursas.sort();
        Failo_rusiavimas(kursas);
    }

    else if (ivedimas1 == 2)
    {
        int n;
        cout<<"Iveskite, kiek studentu yra sarase:"<<endl;
        cin>>n;
        tikrinimas(n);

        for (int i=0; i<n; i++)
        {
            cout<<"Iveskite varda ir pavarde: "<<endl;
            cin>>stip.vardas>>stip.pavarde;

            char ivedimas2;
            cout<<"Iveskite: '+' - duomenu generavimui; '-' - duomenu ivedimui: ";
            cin>>ivedimas2;
            if (ivedimas2 == '+')
            {
                int skaicius;
                cout<<"Iveskite, kiek pazymiu generuojama: ";
                cin>>skaicius;
                tikrinimas(skaicius);

                for(int j=0; j<skaicius; j++) stip.pazymiai.push_back(generate_random());
                stip.egz = generate_random();
                stip.mediana = median(stip.pazymiai);
                stip.rez = mean(stip.pazymiai, stip.egz);
                kursas.push_back(stip);
                stip.pazymiai.clear();
            }

            else if (ivedimas2 == '-')
            {
                int p;
                cout<<"Iveskite pazymi (0 zymi pazymiu ivedimo pabaiga): ";
                cin>>p;

                if (cin.fail() || p < 0 || p > 10) throw invalid_argument("Pateiktas netinkamas skaicius.");

                while (p != 0)
                {
                    stip.pazymiai.push_back(p);
                    cout<<"Iveskite pazymi (0 zymi pazymiu ivedimo pabaiga): ";
                    cin>>p;
                    if (cin.fail() || p < 0 || p > 10) throw invalid_argument("Pateiktas netinkamas skaicius.");
                }

                cout<<"Iveskite egzamino rezultata: "<<endl;
                cin>>stip.egz;

                stip.mediana = median(stip.pazymiai);
                stip.rez = mean(stip.pazymiai, stip.egz);
                kursas.push_back(stip);
                stip.pazymiai.clear();
            }
        }
        kursas.sort();
        char ivedimas3;
        cout<<"Iveskite: 'V' - vidurkio isvedimui; 'M' - medianos isvedimui: ";
        cin>>ivedimas3;
        if (ivedimas3 == 'V') print_mean(kursas);
        else print_median(kursas);
    }

}

catch (const exception& e) {
    cerr << "Klaida: " << e.what() << endl;
    return 1;}

    system("pause");
    return 0;

}
