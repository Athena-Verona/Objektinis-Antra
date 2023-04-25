#include "mylib.h"
#include "calc.h"

int main(){
<<<<<<< Updated upstream
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
=======
    int nd=0, sk;
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
    //auto start_big = std::chrono::system_clock::now();
    vector<studentas> mas;
    cout << "> Failo skaitymas vyksta..." << endl << endl;
    auto start = std::chrono::system_clock::now();

    char eil_r[1000]; //viena eilut
    open_f=fopen(read_pavadinimas.c_str(),"r");
    fgets(eil_r,1000,open_f);
    string str(eil_r);
    nd = 0;
    size_t position = str.find("ND");
    while (position != string::npos){
        nd++;
        position = str.find("ND", position + 1);
    }
    while (fgets(eil_r,1000,open_f) != 0){
      string str(eil_r);
      nuskaitymas(eil_r, nd, mas); //kvieciama nuskaitymo funkcija
    }
    fclose(open_f);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;

    printf("\n> Failo skaitymas i vektorių truko: %f sekundžių\n", diff.count());

    start = std::chrono::system_clock::now();
    sort(mas.begin(),mas.end(), Palyginimas); //vector
    end = std::chrono::system_clock::now();
    diff = end-start;
    printf("> Rūšiavimas vektoriuje truko: %f sekundžių\n", diff.count());
    int start_size = mas.size();

    start = std::chrono::system_clock::now();
    auto i = std::find_if(mas.begin(), mas.end(),Palyginimas1);
    vector<studentas> mas_bad(i, mas.end());  
    mas.resize(mas.size()-mas_bad.size());
    end = std::chrono::system_clock::now();
    diff = end-start;
    printf("> Skaidymas vektoriuje truko: %f sekundžių\n", diff.count());

    start = std::chrono::system_clock::now();
    spausd("viezlybieji.txt", mas_bad);//galima un
    spausd("nenaudeliai.txt", mas);
    end = std::chrono::system_clock::now();
    diff = end-start;
    printf("\n> Studentų spausdinimas  truko: %f sekundžių\n", diff.count());
    
    mas.clear();
    mas_bad.clear();
    //auto end_big = std::chrono::system_clock::now();
    //std::chrono::duration<double> diff_big = end_big-start_big;
    //printf("> Visos programos veikimas truko: %f sekundžių\n\n", diff_big.count());
>>>>>>> Stashed changes
}