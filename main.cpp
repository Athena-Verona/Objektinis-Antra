#include "mylib.h"
#include "calc.h"

int main(){
    vector<studentas> mas;
    nuskaitymas("kursiokai.txt", mas);
    try{
    if (mas.empty()) { 
        throw runtime_error("Panasu, jusu failas tuscias. Pabandykite is naujo i ji suvesti duomenis\n");
        }
    }
    catch (const runtime_error& e) {
        cout << e.what();
        return 0;
    }
    sort(mas.begin(),mas.end(), Palyginimas);
    spausd("rezultatai.txt", mas);
    for (auto &i : mas) i.paz.clear();
    mas.clear();
}