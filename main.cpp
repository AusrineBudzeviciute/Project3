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
}

catch (const exception& e) {
    cerr << "Klaida: " << e.what() << endl;
    return 1;}

    system("pause");
    return 0;

}
