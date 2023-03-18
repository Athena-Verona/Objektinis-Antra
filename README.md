# Objektinis-programavimas
2023 metų ISI 1 kurso objektinio programavimo uždavinys
# Ketvirtoji versija
Ketvirta projekto versija, papildyta failų generatoriumi bei spartos matavimais.

### .cpp failai
1. _main.cpp_ - paleidžiamasis projekto failas, kuriame sukodinta programos eiga ir user input.
2. _calculate.cpp_ - čia aprašytos visos pagrindinės funkcijos (nuskaitymas, spausdinimas, balo skaičiavimas, rūšiavimas)
3. _generatorius.cpp_ - čia aprašyta tik viena - failo generavimo - funkcija, naudojanti map metodą ir C failo kūrimo metodą.
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
| **_TOTAL_**  | **0.006266** |**0.036453** |  **0.316182** |  **3.369767** | **33.458193** |

_Darbą atlieka S. Atėnė Vaicekauskaitė_
