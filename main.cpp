
#include "my_lib.h"

int main()
{
    studentas stud;
    vector <studentas> grupe;
    int ivedimas1;
    cout<<"Iveskite: '1' - failo nuskaitymui; '2' - duomenu ivedimui: ";
    cin>>ivedimas1;

try{
    if (ivedimas1 == 1)
    {
        string pav;
        cout<<"Iveskite failo pavadinima: ";
        cin>>pav;
        Failo_nuskaitymas(pav, stud, grupe);
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
            string vardas, pavarde;
            cout<<"Iveskite varda ir pavarde: "<<endl;
            cin>>vardas>>pavarde;
            stud.setVardas(vardas);
            stud.setPavarde(pavarde);

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
                    stud.setPazymiai(generate_random());
                stud.setEgz(generate_random());
                stud.setMediana(median(stud.getPazymiai()));
                stud.setRez(mean(stud.getPazymiai(), stud.getEgz()));
                grupe.push_back(stud);
                stud.clearPazymiai();
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
                    stud.setPazymiai(p);
                    cout<<"Iveskite pazymi (0 zymi pazymiu ivedimo pabaiga): ";
                    cin>>p;
                    if (cin.fail() || p < 0 || p > 10)
                        throw invalid_argument("Pateiktas netinkamas skaicius.");
                }
                int egz;
                cout<<"Iveskite egzamino rezultata: "<<endl;
                cin>>egz;
                stud.setEgz(egz);
                stud.setMediana(median(stud.getPazymiai()));
                stud.setRez(mean(stud.getPazymiai(), stud.getEgz()));
                grupe.push_back(stud);
                stud.clearPazymiai();
            }
        }
        sort(grupe.begin(), grupe.end(), pagalPavarde);
        char ivedimas3;
        cout<<"Iveskite: 'V' - vidurkio isvedimui; 'M' - medianos isvedimui: ";
        cin>>ivedimas3;
        if (ivedimas3 == 'V') print_mean(grupe);
        else print_median(grupe);
    }

    else if (ivedimas1==3) {
                studentas vienas;
                vienas.setVardas("Laima");
                vienas.setPavarde("Laiminga");
                studentas antras{vienas};
                studentas trecias = vienas;
                cout<<vienas<<endl;
                cout<<antras<<endl;
                cout<<trecias<<endl;
            }


}
    catch (const exception& e) {
            cerr << "Klaida: " << e.what() << endl;
            return 1;}

    system("pause");
    return 0;
}

