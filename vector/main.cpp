#include "mylib.h"
#include "calc.h"

template<typename C,
    typename T = std::decay_t<
        decltype(*begin(std::declval<C>()))>>
auto nuskaitymas(string read_vardas, C& container){
    FILE *open_f;
    char eil_r[1000]; //viena eilut
    studentas temp;
    open_f=fopen(read_vardas.c_str(),"r");
    fgets(eil_r,1000,open_f);
    string str(eil_r);
    int nd = 0;
    size_t position = str.find("ND");
    while (position != string::npos){
        nd++;
        position = str.find("ND", position + 1);
    }
    while (fgets(eil_r,1000,open_f) != 0){
        std::string::size_type sz;
        string str(eil_r); //char[] i string
        //pagal file struktura, pirmi 32 simboliai yra vardas ir pavarde
        for (int i=0;i<30;i++){
            temp.vardas[i]=str[0];
            str.erase(0, 1); 
        }
        temp.vardas[30] = '\0';
        //tada eina kazkiek tusciu simboliu
        while (str[0]==' ') str.erase(0, 1);
        //tada eina pazymiai, kiek ju buvo nuskaityta is pirmos eilutes
        for (int i=0;i<nd-1;i++){
            temp.paz.push_back(stof(str,&sz));
            str.erase(0, sz); 
            while (str[0]==' ') str.erase(0, 1);
        }
        temp.egz = stoi(str);
        balas(temp);
        container.push_back(temp);
        temp.paz.clear();
    }
    fclose(open_f);
}

int main(){
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
    nuskaitymas(read_pavadinimas, mas);
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
    printf("\n> %i studentų spausdinimas  truko: %f sekundžių\n", start_size, diff.count());
    
    for (auto &i : mas) i.paz.clear();
    mas.clear();
    for (auto &i : mas_bad) i.paz.clear();
    mas_bad.clear();
    //auto end_big = std::chrono::system_clock::now();
    //std::chrono::duration<double> diff_big = end_big-start_big;
    //printf("> Visos programos veikimas truko: %f sekundžių\n\n", diff_big.count());
}