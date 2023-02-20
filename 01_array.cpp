#include "mylib.h"

struct studentas{
    string vardas, pavarde;
    int egz;
    int* paz;
    float gal_vid, gal_med;
    bool random = false;
};

struct studentu_masyvas{
    studentas *studentas;
    int dydis;
};

void mediana_balas(studentas *tmp, int size){
    //bubble sort
    for ( int i=0; i < size-1 ; i++ ){
        for ( int j=0 ; j < size-i-1 ; j++){
            if (tmp->paz[j]>tmp->paz[j+1]){
                swap(tmp->paz[j], tmp->paz[j+1]);
            }
        }
    }
    int vidurys=size/2;
    float mediana = size % 2 == 0 ? (tmp->paz[vidurys-1] + tmp->paz[vidurys]) / 2.0 : tmp->paz[vidurys];
    tmp->gal_med = 0.4*mediana + 0.6*tmp->egz;
}

void resize_int(int*& array, int size){
    int *newArray = new int[size];
    for (int i=0;i<size-1;i++){
        newArray[i]=array[i];
    }
    delete [] array;
    array = newArray;
}

void pild(studentas *tmp){
    char uzklausa = 'n';
    cout << "Iveskite varda: ";
    cin >> tmp->vardas;
    cout << "Ir pavarde: ";
    cin >> tmp->pavarde;
    cout << "Iveskite visus pazymius. Baige rasyti, iveskite bet kokia raide: ";
    float x, suma=0;
    int n = 0;
    tmp->paz = NULL;
        while (cin >> x){
            if (n == 0){
                tmp->paz = new int[1];
                tmp->paz[0] = x;
                suma+=x;
                ++n; //tampa n = 1, kad naujo ciklo metu praleistu if
            }
            else {
                suma+=x;
                ++n; // tampa n = 2
                resize_int(tmp->paz, n); //padarom nauja masyva, viena vieta didesni, kopijuojam
                tmp->paz[n-1] = x;
            }
        }
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    cout << "Iveskite egzamino pazymi: ";
    do {
        cin >> tmp->egz;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } while (tmp->egz==0);

    cout << "Idomumo delei, ar noretumete gauti atsitiktinius balo rezultatus? y/n ";
    cin >> uzklausa;
    if (uzklausa == 'y' || uzklausa == 'Y') {
        srand(time(NULL));
        tmp->gal_vid = (float)rand()/RAND_MAX*10;
        tmp->gal_med = (float)rand()/RAND_MAX*10;
    }
    else if (n > 0){
        tmp->gal_vid = 0.4*(suma/n) + 0.6*tmp->egz;
        mediana_balas(tmp, n);
    }
}
void resize(studentas*& array, int size){
    studentas *newArray = new studentas[size]; 
    for (int i=0;i<size-1;i++){
        newArray[i] = array[i];
    }
    delete [] array;
    array = newArray;
}

void spausd(studentas *tmp){
    cout << setw(10) << left << tmp->vardas << setw(15) << left << tmp->pavarde;
    cout << setw(17) << left << setprecision(3) << fixed << tmp->gal_vid << setw(3) << setprecision(3) << fixed << tmp->gal_med;
    cout << endl;
}

int main(){
    int max = 0;
    char uzklausa;
    studentu_masyvas Kursas;

    while (uzklausa!='n' && uzklausa!='N') {
        if (max == 0){ //pati pirma karta bus inicijuojamas masyvas
            Kursas.studentas = new studentas[1]; //duodame tik viena vieta
            ++max; //max tampa 1, kad loopas vel nesoktu i if{}
            Kursas.dydis = max;
            pild(&Kursas.studentas[0]); //uzpildome ta viena vieta
        }
        else { //visais kitais kartais
            ++max; //padidiname skaitliuka, (antra karta bus 2)
            resize(Kursas.studentas, max); //padidiname masyva
            pild(&Kursas.studentas[max-1]); //uzpildome ta suteikta vieta
        }
        if (Kursas.studentas[max-1].paz == NULL) { //leidzia viena karta pabandyti is naujo
            cout << "Panasu, kad neivedete jokio pazymio. Tai yra nedovanotina. Pabandykite is naujo ivesti studento duomenis." << endl;
            pild(&Kursas.studentas[max-1]);
        }
        Kursas.dydis = max;
        cout << "Baigti darba? Spausk n, testi - bet koks kitas klavisas" << endl;
        cin >> uzklausa;
    }

    cout << endl << endl << setw(10) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(17) << "Galutinis (Vid.) " << setw(18) << "/ Galutinis (Med.)";
    cout << endl << "------------------------------------------------------------" << endl;
    for (int i=0;i<Kursas.dydis;i++) {
        spausd(&Kursas.studentas[i]);
        delete [] Kursas.studentas[i].paz;
    }
    cout << endl;
    delete [] Kursas.studentas;
}