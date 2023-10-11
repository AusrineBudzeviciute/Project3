#include "my_lib.h"

int main()
{
    studentas stud;
    vector <studentas> grupe;
    char ivedimas1;
    cout<<"Iveskite 'f', jeigu norite nuskaityti faila; iveskite 'a',jeigu duomenys bus ivedami; iveskite 'k', jeigu failas generuojamas automatiskai:";
    cin>>ivedimas1;

try{
    if (ivedimas1 == 'f')
    {
        string pavadinimas;
        cout<<"Iveskite tekstinio failo pavadinima: ";
        cin>>pavadinimas;

        ifstream failas(pavadinimas);
        if(failas.fail())
        {
            cout<<"Failo atidarymo klaida."<<endl;
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

        sort(grupe.begin(), grupe.end());
        print_mean_median(grupe);
        failas.close();
    }


    else if (ivedimas1=='a')
    {
        int n;
        cout<<"Iveskite, kiek studentu yra sarase:"<<endl;
        cin>>n;
        tikrinimas(n);

        for (int i=0; i<n; i++)
        {
            cout<<"Iveskite varda ir pavarde: "<<endl;
            cin>>stud.vardas>>stud.pavarde;

            char duomived;
            cout<<"Iveskite '+', jeigu norite, kad studento pazymius bei egzamino rezultatus sugeneruotu automatiskai.Iveskite '-', jeigu juos ivesite patys: ";
            cin>>duomived;
            if (duomived == '+')
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

            else if (duomived == '-')
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
        char isvedimas;
        cout<<"Iveskite 'V', jeigu norite matyti vidurki, iveskite 'M', jeigu norite matyti mediana: ";
        cin>>isvedimas;
        if (isvedimas == 'V') print_mean(grupe);
        else print_median(grupe);
    }

    else
        Failo_kurimas(10);


}
    catch (const exception& e) {
            cerr << "Klaida: " << e.what() << endl;
            return 1;}

    system("pause");
    return 0;
}




