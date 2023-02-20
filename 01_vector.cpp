#include "mylib.h"

struct studentas{
    string vardas, pavarde;
    vector<float> paz;
    int egz;
    float gal_vid, gal_med;
};

void balas(studentas &temp){
    //vidurkis
    float vid = 0;
    int size = temp.paz.size();
    for (float &i:temp.paz) vid+=i;
    vid/=size;
    temp.gal_vid = 0.4*vid + 0.6*temp.egz;
    //mediana
    //bubble sort
    for ( int i=0; i < size-1 ; i++ ){
        for ( int j=0 ; j < size-i-1 ; j++){
            if (temp.paz[j]>temp.paz[j+1]){
                swap(temp.paz[j], temp.paz[j+1]);
            }
        }
    }
    int vidurys=size/2;
    float mediana = size % 2 == 0 ? (temp.paz[vidurys-1] + temp.paz[vidurys]) / 2.0 : temp.paz[vidurys];
    temp.gal_med = 0.4*mediana + 0.6*temp.egz;
}

void pild(studentas &temp){
    char uzklausa = 'n';
    cout << "Iveskite varda: ";
    cin >> temp.vardas;
    cout << "Ir pavarde: ";
    cin >> temp.pavarde;
    cout << "Iveskite visus pazymius. Baige rasyti, iveskite bet kokia raide: ";
    float x;
    while (cin >> x){
       temp.paz.push_back(x);
    }
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout << "Iveskite egzamino pazymi: ";
    do { //neleidzia ivesti raides
        cin >> temp.egz;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } while (temp.egz==0);
    cout << "Idomumo delei, ar noretumete gauti atsitiktinius balo rezultatus? y/n ";
    cin >> uzklausa;
    if (uzklausa == 'y' || uzklausa == 'Y') {
        srand(time(NULL));
        temp.gal_vid = (float)rand()/RAND_MAX*10;
        temp.gal_med = (float)rand()/RAND_MAX*10;
    }
    else if (!temp.paz.empty()) {
        balas(temp);
    }
}

void spausd(studentas &temp){ 
    cout << setw(10) << left << temp.vardas << setw(15) << left << temp.pavarde;
    cout << setw(17) << left << setprecision(3) << fixed << temp.gal_vid << setw(3) << setprecision(3) << fixed << temp.gal_med;
    cout << endl;
}

int main(){
    vector<studentas> mas;
    studentas tempas;
    char uzklausa='n';
    
    do {
        pild(tempas);
        if (tempas.paz.empty()) {
            cout << "Panasu, kad neivedete jokio pazymio. Tai yra nedovanotina. Pabandykite is naujo ivesti studento duomenis." << endl;
            tempas.paz.clear();
            pild(tempas);
        }
        mas.push_back(tempas);
        tempas.paz.clear();      //reikia isvalyti vektoriu pries sekanti panaudojima
        cout << "Baigti darba? Spausk n, testi - bet koks kitas klavisas" << endl;
        cin >> uzklausa;
    }  while ( uzklausa!='n' && uzklausa!='N' );
    cout << endl << endl << setw(10) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(17) << "Galutinis (Vid.) " << setw(18) << "/ Galutinis (Med.)";
    cout << endl << "------------------------------------------------------------" << endl;
    for (auto &i : mas) spausd(i);
    cout << endl;
    for (auto &i : mas) i.paz.clear();
    mas.clear();
}