# v2.0 Antra užduotėlė

**APRAŠYMAS**

Programa sukurta pirmos užduoties pagrindu, tačiau vietoje struktūros, naudojama klasė; palikta greičiausiai veikianti rūšiavimo strategija: vector konteineris + 3 strategija. Programoje realizuota „Rule of three“ ir įvesties/išvesties operatoriai. Sukurta galimybė pamatyti, kaip veikia minėti operatoriai, įvestis ir išvestis integruota į pačią programą: įvestis perdengta tiek rankiniu būdu vedamiems duomenims, tiek nuskaitant failą; išvestis perdengta į ekraną ir į failą spausdinamiems rezultatams. Programa papildyta nauja 'zmogus' klase, taigi dabar egzistuoja dvi - bazinė (abstrakčioji) ir išvestinė - klasės. Sukurta programos dokumentacija, patalpinta html.zip (index.html failas su programos aprašu).



**RULE OF THREE REALIZAVIMAS**

![image](https://github.com/AusrineBudzeviciute/Project2/assets/145910900/a72a862c-e4e6-480f-ae71-95dfe7bad001)

![image](https://github.com/AusrineBudzeviciute/Project2/assets/145910900/afc4d8ad-5c2d-4aa2-a8e1-2de3b2388c78)

**ĮVESTIES/IŠVESTIES OPERATORIAI**

![image](https://github.com/AusrineBudzeviciute/Project2/assets/145910900/5e6a0bbc-a9b2-4578-9827-65bb3bfc873c)


**ANALIZĖ** 

Analizei naudoti 2 failai, turintys skirtingą studentų skaičių: 100000, 1000000. Sugeneruoti failai buvo testuojami 5 kartus ir imamas matavimų vidurkis. Testavimas vykdomas keliais skiritingais scenarijais: 
naudojant struktūrą arba klasę ir naudojant skirtingus flag'us (O1, O2, O3).

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

**ĮDIEGIMO, NAUDOJIMOSI INSTRUKCIJA**

_Reikalavimai_: kompiuteryje turi būti įdiegta cMake (minimalus reikalavimas - 3.28 versija). Sukuriamas naujas aplankas, jame dar du nauji aplankai - 'src' ir 'include'. Toliau darbas su failais vyksta taip: 
1. .cpp failai įkeliami į aplanką 'src', esant poreikiui šis aplankas papildomas tekstiniais testavimo failais;
2. .h failai įkeliami į aplanką 'include';
3. Likę failai (CMakeLists.txt ir RUNMEE.bat) paliekami pagrindiniame aplanke.

_Naudojimasis_: atidaroma Windows PowerShell ir pasiekiamas anksčiau sukurtas aplankas (įvestis: cd aplanko_pavadinimas). Suvedama .\RUNMEE.bat. Toliau darbas vyksta pagal gautus nurodymus ekrane.



**TESTAVIMO SISTEMOS PARAMETRAI**

CPU: Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz, 2496 Mhz, 4 Core(s), 8 Logical Processor(s)

RAM: 8.00GB

SDD: 512GB SSD
