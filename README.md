# v02. Pirma užduotėlė

Programa nuskaito duomenis iš failo, automatiškai sugeneruoja duomenis arba leidžia juos suvesti vartotojui. Skaičiuojami ir išvedami (pasirinktai) mediana arba vidurkis. Programa taip pat matuoja laiką: failų generavimo, nuskaitymo, rūšiavimo (į 'gudručius' ir 'neišmanėlius') bei šių failų kūrimo.

Analizei naudoti 5 failai, turintys skirtingą studentų skaičių: 1000, 10000, 100000, 1000000, 10000000. Šių failų generavimas atitinkamai užtruko 0,02s ; 0,06s ; 0,5s ; 5,15s ; 45,2s .
Sugeneruoti failai buvo testuojami 5 kartus ir imamas matavimų vidurkis.
1. Failų nuskaitymas užtruko: 0,01s ; 0,03s ; 0,19s ; 1,85s ; 19,92s ;
2. Failų rūšiavimas į 'gudručius' ir 'neišmanėlius' užtruko: 0s ; 0,01s ; 0,03s ; 0,29s ; 2,72s ;
3. Gudručių failo kūrimas užtruko: 0,01s ; 0,03s ; 0,19s ; 1,89s ; 19,09s ;
4. Neišmanėlių failo kūrimas užtruko: 0s ; 0,02s ; 0,13s ; 1,37s ; 13,27s .

Taigi, darbas su 1000 studentų failu užtruko 0,03s ;
       darbas su 10000 studentų failu užtruko 0,15s ;
       darbas su 100000 studentų failu užtruko 1,04s ;
       darbas su 1000000 studentų failu užtruko 10,54s ;
       darbas su 10000000 studentų failu užtruko 100,19s .

