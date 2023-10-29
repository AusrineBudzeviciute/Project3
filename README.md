# v03. Pirma užduotėlė

Programa nuskaito duomenis iš failo, automatiškai sugeneruoja duomenis arba leidžia juos suvesti vartotojui. Skaičiuojami ir išvedami (pasirinktinai) mediana arba vidurkis. Programa taip pat matuoja laiką: failų generavimo, nuskaitymo, rūšiavimo (į 'gudručius' ir 'neišmanėlius') bei šių gautų failų kūrimo laiką.

**Analizė.** _eiga_

Analizei naudoti 5 failai, turintys skirtingą studentų skaičių: 1000, 10000, 100000, 1000000, 10000000. Šių failų generavimas atitinkamai užtruko 0,02s ; 0,06s ; 0,5s ; 5,15s ; 45,2s . Sugeneruoti failai buvo testuojami 5 kartus ir imamas matavimų vidurkis. Gauti rezultatai lyginami su antros versijos matavimais: šiuo atveju naudojamas list konteineris lyginamas su ankstesnės versijos vector konteineriu.

**Analizė.** _vector konteinerio rezultatai_
|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo nuskaitymo vidutinis laikas            | 0,01 s  |  0,03 s | 0,19 s | 1,85 s  |  19,92 s  |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0,01 s | 0,03 s | 0,29 s  |  2,72 s   |
|  Neišmanėlių failo spausdinimo vidutinis laikas | 0 s     |  0,02 s | 0,13 s | 1,37 s  |  13,27 s  |
|  Gudručių failo spausdinimo vidutinis laikas  | 0,01 s  |  0,03 s | 0,19 s | 1,89 s  |  19,09 s  |
|  **Bendras laikas**                             | **0,02 s** |  **0,09 s** | **0,54 s** | **5,4 s** |  **55 s** |

**Analizė.** _list konteinerio rezultatai_
|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo nuskaitymo vidutinis laikas            | 0,02 s  |  0,07 s | 0,71 s | 5,37 s  |  54,05 s  |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0,02 s | 0,08 s | 0,72 s  |  17,94 s   |
|  Neišmanėlių failo spausdinimo vidutinis laikas | 0 s     |  0,02 s | 0,20 s | 1,70 s  |  18,46 s  |
|  Gudručių failo spausdinimo vidutinis laikas  | 0,01 s  |  0,03 s | 0,28 s | 2,39 s  |  24,68 s  |
|  **Bendras laikas**                             | **0,02 s** |  **0,13 s** | **1,28 s** | **10,18 s** |  **115,13 s** |

**Analizė.** _palyginimas_

Didėjant studentų skaičiui (failų eilučių skaičiui), programa veikia sparčiau su vector konteineriu.

**Testavimo sistemos parametrai:**

CPU: Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz, 2496 Mhz, 4 Core(s), 8 Logical Processor(s)

RAM: 8.00GB

SDD: 512GB SSD
