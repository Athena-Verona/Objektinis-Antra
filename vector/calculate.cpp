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
void spausd(string write_vardas, vector<studentas> studentai){
    out_f=fopen(write_vardas.c_str(),"w");
    char v[]="Vardas";
    char p[]="Pavarde";
    char g[]="Galutinis(Vid.)";
    char m[]="Mediana(Med.)";
    fprintf(out_f, "%-16s%16s   %15s%15s\n", v,p,g,m);
    fprintf(out_f, "-----------------------------------------------------------------\n");
    for (auto &i:studentai ) fprintf(out_f, "%-32s   %15.2f%15.2f\n", i.vardas, i.gal_vid, i.gal_med);
    fclose(out_f);
    studentai.resize(0);
}
bool Palyginimas(const studentas &a, const studentas &b)
{
    return a.gal_vid < b.gal_vid;
}
bool Palyginimas1(const studentas &a)
{
    return a.gal_vid >= 5;
}