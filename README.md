# Objektinis-programavimas
2023 metų ISI 1 kurso objektinio programavimo uždavinys

# Eksperimentiniai Vector tyrimai

Trys tyrimai, atlikti su nauja Vektorius klase. Repozitorijos failai:
1. source (aplankas): čia yra patobulinta V2.0 versija, realizuota su nauja Vektorius klase vietoje std::vector.
2. funciontality.cpp: kodas, skirtas parodyti, kad Vektorius ir std::vector veikia taip pat
3. speed.cpp: kodas, skirtas parodyti spartos palyginimus tarp šių dviejų konteinerių.

# 100 000 000 elementų užpildymas ir su std::vector, ir su class Vektorius pareikalavo resursų perskirstymo _27 kartus_

## Spartos palyginimas tarp mano Vektorius class ir std::vector su push_back:

|             | std::vector | Mano Vektorius |
|-------------|-------------|----------------|
| 10 000      | 0.00579     | 0.00035        |
| 100 000     | 0.00967     | 0.00372        |
| 1 000 000   | 0.06306     | 0.03215        |
| 10 000 000  | 0.58459     | 0.31156        |
| 100 000 000 | 5.69638     | 3.28554        |

## Funkcijų reserve(), shrink_to_fit(), erase(), pop_back(), resize() funkcionalumo palyginimas:

**Tikrinama reserve(100) <<<<<**
std::vector capacity pries reserve(100):     0
std::vector capacity po reserve(100):   10
--------------
Vektorius capacity pries reserve(100):     0
Vektorius capacity po reserve(100):   100

**Tikrinama shrink_to_fit() <<<<<**
std::vector capacity pries shrink_to_fit():   100
std::vector capacity po shrink_to_fit():   
--------------
Vektorius capacity pries shrink_to_fit():   100
Vektorius capacity po shrink_to_fit():     4

**Tikrinama erase() <<<<<**
std::vector pries istrinant 3 nari: 
1 2 3 4 
std::vector istrynus 3 nari: 
1 2 3 
--------------
Vektorius pries istrinant 3 nari: 
1 2 3 4 
Vektorius istrynus 3 nari: 
1 2 3 

**Tikrinama pop_back() <<<<<**
std::vector pries istrinant paskutini nari: 
1 2 3 
std::vector istrynus paskutini nari: 
1 2 
--------------
Vektorius pries istrinant paskutini nari: 
1 2 3 
Vektorius istrynus paskutini nari: 
1 2 

**Tikrinama resize() <<<<<**
 std::vector pries resize(3): 
1 2 1 2 3 4 
std::vector po resize(3): 
1 2 1 
--------------
Vektorius pries resize(3): 
1 2 1 2 3 4 
Vektorius po resize(3): 
1 2 1 

# Versija 2.0

## Dėmesio! Pritaikyta tiek **Windows**, tiek **MacOS** platformai
### Paleidimo instrukcija:
## Windows:

1. Parsisiųsti failus iš github repo
2. Paleisti failą "ProgramaLab.msi"
3. Praeiti instaliavimo žingsnius, leisti programai daryti pokyčius kompiuteryje
4. Jūsų programa vadinsis "ObjektinisInstaller.exe", paleiskite ją.

## MacOS:

1. Parsisiųsti failus iš github repo
2. Paleisti failą "Idiegimo_programa.dmg"
3. Kompiuterio Dekstop atsiras naujas disk image: paspauskite ant jo ir taip rasite Unix Executable file
5. Jūsų programa vadinsis "main", paleiskite ją.

### Programos funkcionalumas:

1.  Pirma programa parodo jau esamus studentų failus ir paklausia, ar norite tokį sukurti. Galite paspausti y/n mygtukus kaip "yes" arba "no"
2. Atspausdinamas failo kūrimo laikas, toliau klausiama, kurį failą norite nuskaityti
3. Pasirinktas failas yra nuskaitomas, visų studentų galutiniai balai apskaičiuojami ir išvedami į du rezultatų failus: viežlybieji ir nenaudėliai
4. Galite patikrinti programos laiką
 
# Versija 1.5
### Bazinės ir išvestinės klasės sukūrimas

Šioje versijoje atsiranda nauja klasė: *class zmogus*, kuri yra abstrakti ir atlieka bazinės klasės funkciją išvestinei klasei *class Studentas*. 

Jos abstrakčios funkcijos:
   1. string getVardas() const = 0; 
   2. double getGal_vid() const = 0;
   3. double getGal_med() const = 0;
   4. void galBalas() = 0;
Jos konstruktorius ir kintamieji yra *protected*, kad juos galėtų pasiekti išvestinės klasės, bet ne išorė.

# Versija 1.2
### Klasės papildymas

Šioje versijoje pilnai implementuota _"rule of five"_ klasei _studentas_, aprašytoje calc.h faile. Atsiradę funkcionalumai:

   1. Default constructor: **studentas()**
   2. Copy constructor: **studentas(const studentas& v)**
   3. Move constructor: **studentas(studentas&& v)**
   4. Copy assignment constructor: **studentas& operator=(const studentas& v)**
   5. Move assignment constructor: **studentas& operator=(studentas&& v)**

Taip pat realizuoti du operatoriai: išvedimo bei įvedimo:

   1. std::ostream& **operator<<**(std::ostream& out, const studentas& v)
   2. std::istream& **operator>>**(std::istream& in, studentas &v).

# Versija 1.1
Versija 1.1 jau naujoje repozitorijoje! Dabar header faile _calc.h_ aprašyta pati pirmoji šio projekto klasė: studentas. Naudojama kelios getter ir setter funkcijos, viena member funkcija.

### Spartos palyginimas tarp class ir struct 

| 100 000      | class   | struct  |
|--------------|---------|---------|
| nuskaitymas  | 0.34672 | 0.21614 |
| rūšiavimas   | 0.04536 | 0.00053 |
| skaidymas    | 0.01758 | 0.01987 |
| spausdinimas | 0.12556 | 0.11389 |

| 1 000 000    | class   | struct |
|--------------|---------|--------|
| nuskaitymas  | 3.25677 | 2.2087 |
| rūšiavimas   | 0.38579 | 0.0684 |
| skaidymas    | 0.17590 | 0.2584 |
| spausdinimas | 1.12573 | 1.0522 |

### Palyginimai tarp kompiliatoriaus flagų

| kompiliatorius         | **01**     | **02**     | **03**     |
|------------------------|--------|--------|--------|
| programa užima         | 145 KB | 61 KB  | 78 KB  |
| atminties išnaudojimas | 84 MB  | 130 MB | 130 MB |
| laikas                 | 7.1 s  | 5.06 s | 4.97 s |

# Galutinė 1.0 versija

Galutinė 1 projekto versija, apjungianti visas 5 praeitas versijas. Galima rasti du 
aplankus, kuriuose yra du skirtingi variantai. 

### Paleidimas
1. Pasirinkite aplanką ir paleiskite makefile parašius **make** į savo komandinę eilutę. 
2. Paleidimui parašykite **./main**
## Aplankas "vector"
Tai galutinė versija, optimizuota su sparčiais konteinerių algoritmais. Ankstesnėse 
versijose jau realizuota sparti versija, todėl palyginimo nėra.
## Aplankas "vector deque list"
Galima rinktis, kurį studentų skaidymo būdą rinktis ir galima pamatyti konteinerių 
spartos analizę.
### Spartos analizė
#### Skaidymas į du naujus konteinerius
|            | Vector | Deque | List |
|------------|--------|-------|------|
| 1000       |    0.000286    |    0.000185   |    0.000263  |
| 10 000     |    0.001677    |    0.005085   |   0.003295   |
| 100 000    |    0.032419    |   0.025153    |   0.054680   |
| 1 000 000  |     0.254413   |    0.591458   |   0.535757   |
| 10 000 000 |    3.570025    |    3.128859   |   6.356380   |

 **Užimta 2,5-3 GB atminties su 10 mil**

#### Skaidymas į vieną naują konteinerį

|            | Vector | Deque | List |
|------------|--------|-------|------|
| 1000       |  0.000266      |    0.000344   |  0.000260    |
| 10 000     |   0.002467    |    0.001799   |   0.004344   |
| 100 000    |    0.025050    |    0.024613   |    0.064135  |
| 1 000 000  |    0.240916    |    0.253827   |    0.757946  |
| 10 000 000 |    2.747569    |   2.935171    |  7.743919    |

 **Užimta 1,7-2 GB atminties su 10 mil**

# Penktoji versija
Šioje versijoje nebuvo daug kas pakeista, tik šie veiksmai - failo nuskaitymas, 
sortinimas didėjimo tvarka ir skaidymas į du failus - atliekami trimis skirtingais 
būdais: **std::vector, std::deque ir std::lis**t. Paleista programa automatiškai atlieka 
skaičiavimus visais trimis būdais.
Kadangi failai vienodi palyginus su praeita versija, čia pateikiami tik spartos 
išmatavimai. 
## Vector
|          | Skaitymas | Rūšiavimas | Skaidymas |
|----------|-----------|------------|-----------|
| 1000     |     0.002784      |      0.000075      |      0.000266     |
| 10000    |     0.023773      |       0.000476     |      0.002467     |
| 100000   |      0.196043     |      0.005073      |      0.025035     |
| 1000000  |      1.865709     |       0.063594     |      0.252097     |
| 10000000 |      18.743032     |     0.591280       |    3.129753      |
## Deque
|          | Skaitymas | Rūšiavimas | Skaidymas |
|----------|-----------|------------|-----------|
| 1000     |      0.002416     |     0.000079       |      0.000185     |
| 10000    |     0.019360      |       0.000588     |     0.001799      |
| 100000   |    0.186196       |       0.009757     |      0.027583     |
| 1000000  |      1.817097     |       0.068257     |        0.217228   |
| 10000000 |     18.010306     |      0.679888      |     2.835921      |
## List
|          | Skaitymas | Rūšiavimas | Skaidymas |
|----------|-----------|------------|-----------|
| 1000     |     0.002304      |      0.000093      |     0.000260      |
| 10000    |      0.022091     |     0.001753       |      0.003295     |
| 100000   |     0.190998      |       0.030831     |    0.030142       |
| 1000000  |     1.961710      |      0.600316      |     0.331130      |
| 10000000 |      18.590231     |      9.588606      |     3.551435      |

## Kompiuterio duomenys:

**CPU:** 2,3 GHz Dual-Core Intel Core i5
**RAM:** 8 GB 2133 MHz LPDDR3
**SSD:** 121,33 GB APPLE SSD AP0128J

# Ketvirtoji versija
Ketvirta projekto versija, papildyta failų generatoriumi bei spartos matavimais.

### .cpp failai
1. _main.cpp_ - paleidžiamasis projekto failas, kuriame sukodinta programos eiga ir user 
input.
2. _calculate.cpp_ - čia aprašytos visos pagrindinės funkcijos (nuskaitymas, 
spausdinimas, balo skaičiavimas, rūšiavimas)
3. _generatorius.cpp_ - čia aprašyta tik viena - failo generavimo - funkcija, naudojanti 
map metodą ir C failo kūrimo metodą.
### .h failai
1. _mylib.h_ - įtrauktos bilbiotekos ir šablonai.
2. _cac.h_ - funkcijų prototipai, aprašyta struktūra.
### .txt failai
1. _studentai1000.txt_ - pavyzdinis generatoriaus sukurtas studentų failas.
## Programos spartos analizė pagal įrašų kiekį, įvertinta **sekundėmis**.
|   | 1000 | 10 000  | 100 000  | 1 000 000  | 10 000 000  |
|---|---|---|---|---|---|
| **Generavimas** | 0.002524  |  0.020975 | 0.188590  |  1.967706 |  17.909841 |
| **Nuskaitymas**  | 0.003156  |  0.022608 |  0.191797 |  1.840811 |  18.620220 |
| **Rūšiavimas**  |  0.000220 |  0.001314 |  0.018996 |  0.234441 |  2.817948 |
| **Spausdinimas**  |  0.001736 | 0.011761 | 0.094345  | 1.126077  | 10.26588  |
| **_TOTAL_**  | **0.006266** |**0.036453** |  **0.316182** |  **3.369767** | **33.
458193** |

_Darbą atlieka S. Atėnė Vaicekauskaitė_

# Antroji ir trečioji projekto versijos
_**SVARBU! Ši projekto versija įgyvendina tiek v0.2, tiek v0.3 versijų reikalavimus, 
todėl įkeliamas vienas bendras projektas siekiant išvengti pasikartojimų tarp 
subrepozitorijų!!**_

# .h failai
1. mylib.h yra surašytos bibliotekos ir std funkcijos, kurios bus reikalingos visam 
projektui (pvz., sort(), vector).
2. calc.h yra surašytos funkcijų deklaracijos, reikalingos kodo vykdymui.

# .cpp failai
1. main.cpp yra paleidžiamasis failas, kuris tik kreipiasi į funkcijas.
2. calculate.cpp yra surašytos visos funkcijos, struktūros bei globalūs kintamieji.

# .txt failai
1. faile "kursiokai.txt" surašyti visi studentai, po 20 jų kiekvieno pažymių ir egzamino 
rezultatas. failo struktūra yra griežta, t.y. galima keisti skaičius ir duomenis tik 
jeigu eilutės lieka taip pat sulygiuotos.
2. kai paleisite programą, turi atsirasti failas "rezultatai.txt" su studentų 
galutiniais rezultatais.

# Failų skaitymo metodas
Failų skaitymo ir rašymo metodas buvo pasirinktas kaip C kalbos variantas (eilutė po 
eilutės). Taip buvo pasirinkta, nes programuotojos kompiuteryje šis būdas veikė bene 
triskart greičiau, nei bet kuris kitas būdas (10 000 eilučių su C užtruko 0.294896 
sekundės, su "greitu" variantu per buferį - 1.55617 sekundės").

_pasikeitimai: pataisyta, kad būtų nuskaitoma failo pirma eilutė ir iš jos sprendžiama, 
kiek namų darbų studentas turi_

# Pirmoji versija

Tai yra pirma versija ilgalaikės užduoties, atlikta dviem būdais

1. Kodas **01_array.cpp** atliktas naudojant **dinaminius masyvus**
2. Kodas **01_vector.cpp** atliktas naudojant **vektorius**
3. Abu jie kreipiasi į failą mylib.h

_Darbą atlieka S. Atėnė Vaicekauskaitė:)_
