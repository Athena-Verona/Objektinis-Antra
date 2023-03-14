#include "mylib.h"
#include "calc.h"

int main(){
    int nd, sk;
    char uzklausa='y';
    namespace fs = std::filesystem;
    fs::path f{ "studentai1000.txt" };
    if (fs::exists(f)) {
        cout << "> Esami .txt failai aplankale: " << endl;
        char command[50] = "ls *.txt";
        system(command);
    } 
    else cout << "> Jusu aplankale nėra studentų failo. ";
    cout << "> Ar norėtumete generuoti studentų failą? (y/n)" << endl;
    cin >> uzklausa;
    if (uzklausa=='Y'||uzklausa=='y') {
      cout << "> Kokio dydžio failą reiktų generuoti? (Tarp 0 ir 10 000 000)" << endl;
      cin >> sk;
      do {
        try {
          if (sk<1||sk>10000000||cin.fail()) throw runtime_error("> Netinkamas studentu kiekis (Ne tarp 0 ir 10 000 000), iveskite iš naujo\n");
        }
        catch (const runtime_error& e) {
        cout << e.what();
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> sk;
        }
      } while (sk<1||sk>10000000||cin.fail());
      cout << "> Kiek pažymių generuoti?" << endl;
      cin >> nd;
      do {
        try {
          if (nd<1||cin.fail()) throw runtime_error("> Netinkamas namų darbu kiekis, įveskite iš naujo\n");
        }
        catch (const runtime_error &e) {
        cout << e.what();
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> nd;
        }
      } while (nd<1||cin.fail());
      gen_map(nd, sk);
    }
    cout << "> Dabar esantys .txt failai aplankale: " << endl;
    char command[50] = "ls *.txt";
    system(command);

    string read_pavadinimas;
    vector<studentas> mas;
    cout << "> Kurį failą norėtumėte atidaryti?" << endl;
    cin >> read_pavadinimas;
    FILE *open_f;
    open_f=fopen(read_pavadinimas.c_str(),"r");
    do{ 
        try{
            if (open_f==NULL) { 
                throw runtime_error("> Tokio failo nėra! Įveskite iš naujo.\n");
            }
        }
        catch (const runtime_error& e) {
            cout << e.what();
            cin >> read_pavadinimas;
            open_f=fopen(read_pavadinimas.c_str(),"r");
        }
    } while (open_f==NULL);
    cout << "> Failo skaitymas vyksta..." << endl;
    auto start_big = std::chrono::system_clock::now();
    nuskaitymas(read_pavadinimas, mas);
    int start_size = mas.size();
    auto start = std::chrono::system_clock::now();
    //rusiavimas prasideda cia
    vector<studentas> mas_bad;
    sort(mas.begin(),mas.end(), Palyginimas);
    for (int i = 0;i<mas.size();i++) {
      if (mas[i].gal_vid>=5){
        int size = (mas.size()-i);
        mas_bad.resize(size);
        auto start = mas.begin() + i;
        auto end = mas.end();
        copy(start, end, mas_bad.begin());
        mas.resize(i);
        break;
      }
    }
    //baigiasi cia
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;
    printf("> %i studentų rūšiavimas truko: %f sekundžių\n", start_size, diff.count());

    start = std::chrono::system_clock::now();
    spausd("viezlybieji.txt", mas_bad);
    spausd("nenaudeliai.txt", mas);
    end = std::chrono::system_clock::now();
    diff = end-start;
    printf("> %i studentų spausdinimas truko: %f sekundžių\n", start_size, diff.count());

    for (auto &i : mas) i.paz.clear();
    mas.clear();
    for (auto &i : mas_bad) i.paz.clear();
    mas_bad.clear();

    auto end_big = std::chrono::system_clock::now();
    std::chrono::duration<double> diff_big = end_big-start_big;
    printf("> Visos programos veikimas truko: %f sekundžių\n\n", diff_big.count());
}