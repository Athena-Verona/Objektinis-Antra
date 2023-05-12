#include "calc.h"

void gen_map(int N, int size){
  FILE *F;
  string pav = "studentai" + std::to_string(size) + ".txt";
  F=fopen(pav.c_str(),"w");

  mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
  int_distribution dist(100, 109);
  map<int, string> vardai, pavardes_m, pavardes_v;
  
  vardai[100]="Gabrisele";
  vardai[101]="Agatsa";
  vardai[102]="Laurisa";
  vardai[103]="Vistorija";
  vardai[104]="Sinsija";
  vardai[105]="Mastas";
  vardai[106]="Dovysdas";
  vardai[107]="Luskas";
  vardai[108]="Aslanas";
  vardai[109]="Slimonas";

  pavardes_m[200]="Baituke";
  pavardes_m[201]="Informaityte";
  pavardes_m[202]="Dvejetaityte";
  pavardes_m[203]="Astuntainyte";
  pavardes_m[204]="Sesioliktaityte";
  pavardes_m[205]="Bugovaite";
  pavardes_m[206]="Aritmetikaite";
  pavardes_m[207]="Indeksaite";
  pavardes_m[208]="Grafikyte";
  pavardes_m[209]="Bitaite";

  pavardes_v[300]="Baitenis";
  pavardes_v[301]="Informatikas";
  pavardes_v[302]="Dvejetaitis";
  pavardes_v[303]="Astuntaitis";
  pavardes_v[304]="Sesioliktaitis";
  pavardes_v[305]="Bugovas";
  pavardes_v[306]="Aritmetikas";
  pavardes_v[307]="Indeksaitis";
  pavardes_v[308]="Grafikis";
  pavardes_v[309]="Bitaitis";

  cout<<"> Vardų ir pavardžių generavimas vyksta..."<<endl;
  auto start = std::chrono::system_clock::now();

  string tekstas[4] = {"Vardas", "Pavarde", "ND", "Egzaminas"};
  fprintf (F ,"%-15s%15s", tekstas[0].c_str(), tekstas[1].c_str());
  for (int i=0;i<N;i++) { fprintf (F ,"%14s%i", tekstas[2].c_str(), i+1 ); }
  fprintf (F ,"%15s\n", tekstas[3].c_str());

  string pavarde, vardas;
  int paz[N], egz;

  for (int i=0;i<size;i++) {
    vardas=vardai[dist(mt)];
    switch(*vardas.rbegin()){
      case 's': 
        pavarde=pavardes_v[200+dist(mt)];
        break;
      default: 
        pavarde=pavardes_m[100+dist(mt)];
        break;  
    };
    for (auto &i:paz) i=dist(mt)+1-100;
    egz=dist(mt)+1-100;

    fprintf(F ,"%-15s%15s", vardas.c_str() ,pavarde.c_str());
    for (auto &a:paz) { fprintf (F ,"%15i", a); }
    fprintf (F ,"%15i\n", egz);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> diff = end-start;
  printf("> %i elementų užpildymas truko: %f sekundžių\n", size, diff.count());
  fclose(F);
}
