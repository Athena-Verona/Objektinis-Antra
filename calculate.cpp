#include "calc.h"

FILE *open_f, *out_f;

void studentas::galBalas(){
    int size = paz.size();
    sort(paz.begin(),paz.end());
    int vidurys=size/2;
    double med = size % 2 == 0 ? (paz[vidurys-1] + paz[vidurys]) / 2.0 : paz[vidurys];
    gal_med = 0.6 * egz + 0.4 * med;
    double vid = std::accumulate(paz.begin(), paz.end(), 0.0)/paz.size();
    gal_vid = 0.6 * egz + 0.4 * vid;
}
//nuskaitymas NERA MEMBER FUNKCIJA, bet iskviecia studento konstruktoriu tai pagalbine
void nuskaitymas(string str, int nd, vector<studentas>& studentai){
    vector<double> paz;
    char vardas[31];
    int egz;
    std::string::size_type sz;
    //pagal file struktura, pirmi 32 simboliai yra vardas ir pavarde
    for (int i=0;i<30;i++){
        vardas[i]=str[0];
        str.erase(0, 1); 
    }
    vardas[30] = '\0';
    //tada eina kazkiek tusciu simboliu
    while (str[0]==' ') str.erase(0, 1);
    //tada eina pazymiai, kiek ju buvo nuskaityta is pirmos eilutes
    for (int i=0;i<nd-1;i++){
        paz.push_back(stof(str,&sz));
        str.erase(0, sz); 
        while (str[0]==' ') str.erase(0, 1);
    }
    egz = stoi(str);
    string vardas_(vardas);
    studentas temp(vardas_, egz, paz); //suveikia konstruktorius
    temp.galBalas();
    studentai.push_back(temp); 
    paz.clear();
}
void spausd(string write_vardas, vector<studentas> studentai){
    out_f=fopen(write_vardas.c_str(),"w");
    char v[]="Vardas";
    char p[]="Pavarde";
    char g[]="Galutinis(Vid.)";
    char m[]="Mediana(Med.)";
    fprintf(out_f, "%-16s%16s   %15s%15s\n", v,p,g,m);
    fprintf(out_f, "-----------------------------------------------------------------\n");
    for (auto &i:studentai ) fprintf(out_f, "%-32s   %15.2f%15.2f\n", (i.getVardas()).c_str(), i.getGal_vid(), i.getGal_med());
    fclose(out_f);
}
bool Palyginimas(const studentas &a, const studentas &b)
{
    return a.getGal_vid() < b.getGal_vid();
}
bool Palyginimas1(const studentas &a)
{
    return a.getGal_vid() >= 5;
}