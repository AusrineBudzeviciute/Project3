# v3.0 Trečia užduotėlė

## Programos diegimo failo naudojimosi instrukcija:
1. Atsisiunčiami failai, esantys 'setup' aplanke;
2. Paleidžiamas setup.exe failas ir įdiegiama programa;
3. Programa paleidžiama atsidarius "MyConsoleApp", esančią Desktop'e;
4. Toliau darbas vyksta pagal poreikį, atsižvelgiant į ekrane esančius reikalavimus.

## Aprašymas
Programa nuskaito duomenis iš failo, automatiškai sugeneruoja duomenis arba leidžia juos suvesti vartotojui. 
Skaičiuojami ir išvedami (pasirinktinai) mediana arba vidurkis. 
Analizei atlikti matuojamas laikas: failų generavimo, nuskaitymo, rūšiavimo bei gaunamų failų kūrimo laikas. 
Programoje realizuota „Rule of three“ ir įvesties/išvesties operatoriai. 
Sukurta galimybė pamatyti, kaip veikia minėti operatoriai, įvestis ir išvestis integruota į pačią programą: įvestis perdengta tiek rankiniu būdu vedamiems duomenims, tiek nuskaitant failą; išvestis perdengta į ekraną ir į failą spausdinamiems rezultatams. 
Programoje realizuotos dvi - bazinė (abstrakčioji) ir išvestinė - klasės.


### Rule of three realizavimas

![image](https://github.com/AusrineBudzeviciute/Project2/assets/145910900/a72a862c-e4e6-480f-ae71-95dfe7bad001)

![image](https://github.com/AusrineBudzeviciute/Project2/assets/145910900/afc4d8ad-5c2d-4aa2-a8e1-2de3b2388c78)

### Įvesties/išvesties operatoriai

![image](https://github.com/AusrineBudzeviciute/Project2/assets/145910900/fc7bdaef-fa06-4b8b-9853-947a5a3f563a)

## Analizė

Analizei naudoti 2 failai, turintys skirtingą studentų skaičių: 100000, 1000000. Sugeneruoti failai buvo testuojami 5 kartus ir imamas matavimų vidurkis. Testavimas vykdomas keliais skiritingais scenarijais: 
naudojant struktūrą arba klasę ir naudojant skirtingus flag'us (O1, O2, O3). Rezultatai lyginami su 1 užduoties analizės rezultatais.

**_struktūros rezultatai_**                                                 
|                                                 |  100000 | 1000000 |
| ---------------------------------------------   |:-------:|:-------:|
|  Failo nuskaitymo vidutinis laikas              | 0,27 s  |  1,83 s |
|  Failo išrūšiavimo vidutinis laikas             | 0,03 s  |  0,33 s |
|  Neišmanėlių failo spausdinimo vidutinis laikas | 0,19 s  |  2,2 s  |
|  Gudručių failo spausdinimo vidutinis laikas    | 0,26 s  |  1,38 s |

**_klasės rezultatai_** 
|                                                 |  100000 | 1000000 |
| ---------------------------------------------   |:-------:|:-------:|
|  Failo nuskaitymo vidutinis laikas              | 0,34 s  |  3,33 s |
|  Failo išrūšiavimo vidutinis laikas             | 0,04 s  |  0,42 s |
|  Neišmanėlių failo spausdinimo vidutinis laikas | 0,23 s  |  2,31 s |
|  Gudručių failo spausdinimo vidutinis laikas    | 0,32 s  |  3,25 s |

**Išvada:** programa veikia greičiau naudojant struktūrą.


**_struktūra su skirtingais flag'ais_**

|                                                 |    O1   |  100000 | 1000000 |    O2   |  100000 | 1000000 |    O3   |  100000 | 1000000 |
| ---------------------------------------------   |:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
|  Failo nuskaitymo vidutinis laikas              |         | 0,18 s  |  1,85 s |         | 0,2 s   | 1,84 s  |         | 0,2 s   | 1,83 s  |
|  Failo išrūšiavimo vidutinis laikas             |         | 0,03 s  |  0,25 s |         | 0,03 s  | 0,25 s  |         | 0,02 s  | 0,24 s  |
|  Neišmanėlių failo spausdinimo vidutinis laikas |         | 0,13 s  |  1,4 s  |         | 0,13 s  | 1,4 s   |         | 0,13 s  |  1,4 s  |
|  Gudručių failo spausdinimo vidutinis laikas    |         | 0,2 s   |  1,95 s |         | 0,18 s  | 1,4 s   |         | 0,19 s  |   2 s   |

**_klasė su skirtingais flag'ais_**

|                                                 |    O1   |  100000 | 1000000 |    O2   |  100000 | 1000000 |    O3   |  100000 | 1000000 |
| ---------------------------------------------   |:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
|  Failo nuskaitymo vidutinis laikas              |         | 0,34 s  |  1,98 s |         | 0,29 s  | 1,98 s  |         | 0,21 s  | 1,98 s  |
|  Failo išrūšiavimo vidutinis laikas             |         | 0,04 s  |  0,26 s |         | 0,03 s  | 0,25 s  |         | 0,02 s  | 0,25 s  |
|  Neišmanėlių failo spausdinimo vidutinis laikas |         | 0,23 s  |  1,37 s |         | 0,2 s   | 1,37 s  |         | 0,13 s  |  1,38 s |
|  Gudručių failo spausdinimo vidutinis laikas    |         | 0,31 s  |  1,9 s  |         | 0,28 s  | 1,9 s   |         | 0,19 s  |  1,9 s  |

**Išvada:** tiek naudojant struktūrą, tiek klasę su skirtingais flag'ais, sparta skiriasi nežymiai; klasės atveju O3 flag'as veikia sparčiausiai.

### Testavimo sistemos parametrai:

CPU: Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz, 2496 Mhz, 4 Core(s), 8 Logical Processor(s)

RAM: 8.00GB

SDD: 512GB SSD
