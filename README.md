# v1.0 Pirma užduotėlė

Programa nuskaito duomenis iš failo, automatiškai sugeneruoja duomenis arba leidžia juos suvesti vartotojui. Skaičiuojami ir išvedami (pasirinktinai) mediana arba vidurkis. Programa taip pat matuoja laiką: failų generavimo, nuskaitymo, rūšiavimo (į 'gudručius' ir 'neišmanėlius') bei šių gautų failų kūrimo laiką. Sukurta galimybė pasirinkti, kokiame konteineryje talpinami duomenys (list ar vector), bei, kokia strategija vykdomas rūšiavimas (skaidymas).

**ANALIZĖ.** 

Analizei naudoti 5 failai, turintys skirtingą studentų skaičių: 1000, 10000, 100000, 1000000, 10000000. Šių failų generavimas atitinkamai užtruko 0,02s ; 0,06s ; 0,5s ; 5,15s ; 45,2s . Sugeneruoti failai buvo testuojami 5 kartus ir imamas matavimų vidurkis. Testavimas vykdomas keliais skiritingais scenarijais: naudojant 2 skirtingus konteinerius (list arba vector) bei keičiant failo rūšiavimo (skaidymo) metodą (3 skirtingos strategijos).

**_vector konteinerio rezultatai_**
|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo nuskaitymo vidutinis laikas            | 0,01 s  |  0,03 s | 0,19 s | 1,85 s  |  19,92 s  |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0,01 s | 0,03 s | 0,29 s  |  2,72 s   |
|  Neišmanėlių failo spausdinimo vidutinis laikas | 0 s     |  0,02 s | 0,13 s | 1,37 s  |  13,27 s  |
|  Gudručių failo spausdinimo vidutinis laikas  | 0,01 s  |  0,03 s | 0,19 s | 1,89 s  |  19,09 s  |
|  **Bendras laikas**                             | **0,02 s** |  **0,09 s** | **0,54 s** | **5,4 s** |  **55 s** |

**_list konteinerio rezultatai_**
|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo nuskaitymo vidutinis laikas            | 0,02 s  |  0,07 s | 0,71 s | 5,37 s  |  54,05 s  |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0,02 s | 0,08 s | 0,72 s  |  17,94 s   |
|  Neišmanėlių failo spausdinimo vidutinis laikas | 0 s     |  0,02 s | 0,20 s | 1,70 s  |  18,46 s  |
|  Gudručių failo spausdinimo vidutinis laikas  | 0,01 s  |  0,03 s | 0,28 s | 2,39 s  |  24,68 s  |
|  **Bendras laikas**                             | **0,02 s** |  **0,13 s** | **1,28 s** | **10,18 s** |  **115,13 s** |

**Strategijos.** _vector konteineris_
|                | 1 strategija | 2 strategija | 3 strategija |
| -------------- |:------------:|:------------:|:------------:|
|   1000         |     0 s      |     0 s      |     0 s      |
|   10000        |     0,01 s   |     0,01 s   |     0 s      |
|   100000       |     0,03 s   |     0,02 s   |     0,03 s   |
|   1000000      |     0,29 s   |     2,11 s   |     0,24 s   |
|   10000000     |     2,72 s   |     24,59 s  |     2,62 s   |

**Strategijos.** _list konteineris_
|                | 1 strategija | 2 strategija | 3 strategija |
| -------------- |:------------:|:------------:|:------------:|
|   1000         |     0 s      |     0 s      |     0 s      |
|   10000        |     0,02 s   |     0 s      |     0,01 s   |
|   100000       |     0,08 s   |     0,12 s   |     0,12 s   |
|   1000000      |     0,72 s   |     1,52 s   |     0,99 s   |
|   10000000     |     17,94 s  |     19,22 s  |     14,77 s  |

**ANALIZĖS REZULTATAI**

Didėjant studentų skaičiui (failų eilučių skaičiui), programa veikia sparčiau su vector konteineriu. Tiek minėto vector konteinerio, tiek list konteinerio atveju programa efektyviausia naudojant 3 rūšiavimo strategiją. Išvada: vector konteineris su 3 strategija veikia greičiausiai.

**ĮDIEGIMO, NAUDOJIMOSI INSTRUKCIJA**

Failai sukeliami į aplanką ir išskaidomi į dar 2 atskirus aplankus: 'src' aplanke patalpinami .cpp failai bei (jeigu yra poreikis) .txt failai; 'include' aplanke patalpinami .h failai; likę failai paliekami pagrindiniame aplanke. Atidaromas terminalas ir jame pasiekiamas sukurtas aplankas. Suvedama '.\RUNMEE.bat' ir programa pasileidžia.

**Testavimo sistemos parametrai:**

CPU: Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz, 2496 Mhz, 4 Core(s), 8 Logical Processor(s)

RAM: 8.00GB

SDD: 512GB SSD
