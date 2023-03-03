#include "calc.h"

FILE *open_f, *out_f;

void balas(studentas &temp){
    //vidurkis
    float vid = 0;
    int size = temp.paz.size();
    for (float &i:temp.paz) vid+=i;
    vid/=size;
    temp.gal_vid = 0.4*vid + 0.6*temp.egz;
    //mediana
    sort(temp.paz.begin(),temp.paz.end());
    int vidurys=size/2;
    float mediana = size % 2 == 0 ? (temp.paz[vidurys-1] + temp.paz[vidurys]) / 2.0 : temp.paz[vidurys];
    temp.gal_med = 0.4*mediana + 0.6*temp.egz;
}

void nuskaitymas(string read_vardas, vector<studentas>& studentai){
    char eil_r[257]; //viena eilute
    studentas temp;
    open_f=fopen(read_vardas.c_str(),"r");

    do{ 
        try{
            if (open_f==NULL) { 
                throw runtime_error("Failas nebuvo atidarytas. Suveskite pavadinima failo, kuri norite perduoti (nepamirskite .txt!)\n");
            }
        }
        catch (const runtime_error& e) {
            string name;
            cout << e.what();
            cin >> name;
            open_f=fopen(name.c_str(),"r");
        }
    } while (open_f==NULL);

    fgets(eil_r,257,open_f);
    string str(eil_r);
    int nd = 0;
    size_t position = str.find("ND");
    while (position != string::npos){
        nd++;
        position = str.find("ND", position + 1);
    }
    while (fgets(eil_r,257,open_f) != 0){
        std::string::size_type sz;
        string str(eil_r); //char[] i string
        //pagal file struktura, pirmi 32 simboliai yra vardas ir pavarde
        for (int i=0;i<32;i++){
            temp.vardas[i]=str[0];
            str.erase(0, 1); 
        }
        temp.vardas[32] = '\0';
        //tada eina kazkiek tusciu simboliu
        while (str[0]==' ') str.erase(0, 1);
        //tada eina pazymiai, kiek ju buvo nuskaityta is pirmos eilutes
        for (int i=0;i<nd;i++){
            temp.paz.push_back(stof(str,&sz));
            str.erase(0, sz); 
            while (str[0]==' ') str.erase(0, 1);
        }
        //tada eina egz rezultatas
        temp.egz = stoi(str);
        balas(temp);
        studentai.push_back(temp);
        temp.paz.clear();
    }
    fclose(open_f);
}

void spausd(string write_vardas, vector<studentas> studentai){
    out_f=fopen(write_vardas.c_str(),"w");
    char v[]="Vardas";
    char p[]="Pavarde";
    char g[]="Galutinis(Vid.)";
    char m[]="Mediana(Med.)";
    fprintf(out_f, "%-16s%16s   %15s%15s\n", v,p,g,m);
    fprintf(out_f, "-----------------------------------------------------------------\n");
    for (auto &i:studentai ) fprintf(out_f, "%-32s   %15.2f%15.2f\n", i.vardas, i.gal_med, i.gal_vid);
    fclose(out_f);
    studentai.resize(0);
}

bool Palyginimas(const studentas &a, const studentas &b)
{
    return a.vardas[0] < b.vardas[0];
}