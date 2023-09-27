#include "my_lib.h"

int main()
{

    studentas stud;
    vector <studentas> grupe;
    int n;
    cout<<"Iveskite, kiek studentu yra sarase:"<<endl;
    cin>>n;


    for (int i=0; i<n; i++)
    {
        cout<<"Iveskite varda ir pavarde: "<<endl;
        cin>>stud.vardas>>stud.pavarde;

        char ivedimas;
        cout<<"Iveskite '+', jeigu norite, kad studento pazymius bei egzamino rezultatus sugeneruotu automatiskai. Iveskite '-', jeigu ivesite patys";
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
        }

        else
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
        }

        grupe.push_back(stud);
        stud.pazymiai.clear();
    }

    char isvedimas;
    cout<<"Iveskite 'V', jeigu norite matyti vidurki, iveskite 'M', jeigu norite matyti mediana";
    cin>>isvedimas;
    if (isvedimas == 'V') print_mean(grupe);
    else print_median(grupe);

}












