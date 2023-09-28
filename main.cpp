#include "my_lib.h"

int main()
{

    studentas stud;
    vector <studentas> grupe;

    char ivedimas1;
    cout<<"Iveskite 'f', jeigu norite nuskaityti faila; iveskite 'a',jeigu duomenys bus ivedami";
    cin>>ivedimas1;

    if (ivedimas1 == 'f')
    {
        string pavadinimas;
        cout<<"Iveskite tekstinio failo pavadinima ";
        cin>>pavadinimas;

        ifstream failas(pavadinimas);
        if(failas.fail())
        {
            cout<<"Failo atidarymo klaida"<<endl;
            return 1;
        }

        string antraste;
        for (int i = 0; i<1; i++) getline(failas,antraste);

        istringstream iss(antraste);
        string namudarbas;
        int sk = 0;

        while (iss >> namudarbas)
        {
            if (namudarbas.substr(0, 2) == "ND") sk++;
        }

        while(failas >> stud.pavarde >> stud.vardas)
        {
            for(int i=0; i<sk; i++)
            {
                int paz;
                failas >> paz;
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

    else
    {
        int n;
        cout<<"Iveskite, kiek studentu yra sarase:"<<endl;
        cin>>n;

        for (int i=0; i<n; i++)
        {
            cout<<"Iveskite varda ir pavarde: "<<endl;
            cin>>stud.vardas>>stud.pavarde;

            char ivedimas;
            cout<<"Iveskite '+', jeigu norite, kad studento pazymius bei egzamino rezultatus sugeneruotu automatiskai.Iveskite '-', jeigu juos ivesite patys.";
            cin>>ivedimas;
            if (ivedimas == '+')
            {
                int skaicius;
                cout<<"Iveskite, kiek pazymiu generuojama";
                cin>>skaicius;
                for(int j=0; j<skaicius; j++)
                    stud.pazymiai.push_back(generate_random());
                stud.egz = generate_random();
                stud.mediana = median(stud.pazymiai);
                stud.rez = mean(stud.pazymiai, stud.egz);
                grupe.push_back(stud);
                stud.pazymiai.clear();

            }

            else if (ivedimas == '-')
            {
                int p;
                cout<<"Iveskite pazymi (0 zymi pazymiu ivedimo pabaiga)";
                cin>>p;
                while (p != 0)
                {
                    stud.pazymiai.push_back(p);
                    cout<<"Iveskite pazymi (0 zymi pazymiu ivedimo pabaiga)";
                    cin>>p;
                }

                cout<<"Iveskite egzamino rezultata: "<<endl;
                cin>>stud.egz;
                stud.mediana = median(stud.pazymiai);
                stud.rez = mean(stud.pazymiai, stud.egz);
                grupe.push_back(stud);
                stud.pazymiai.clear();
            }
        }


    }

    char isvedimas;
    cout<<"Iveskite 'V', jeigu norite matyti vidurki, iveskite 'M', jeigu norite matyti mediana";
    cin>>isvedimas;
    if (isvedimas == 'V') print_mean(grupe);
    else print_median(grupe);


}


