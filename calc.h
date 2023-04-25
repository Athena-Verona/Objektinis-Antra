#include "mylib.h"

class studentas{
    private:
    string vardas;
    vector<double> paz;
    int egz;
    double gal_vid, gal_med;
    public:
    studentas() : egz(0){} //konstruktoriai, default ir inicializavimo sarasas
    studentas(string vardas_,int egz_,vector<double> paz_) : vardas{vardas_}, egz{egz_}, paz{paz_} {} 
    inline string getVardas() const { return vardas; } //getter funkcijas visuomet tikslinga daryti const
    inline double getGal_vid() const { return gal_vid; } //getteris
    inline double getGal_med() const { return gal_med; } //getteris
    void galBalas();
    ~studentas() { paz.clear(); } //destruktorius
};

void gen_map(int, int);
void nuskaitymas(string, int, vector<studentas>&); 
void spausd(string, vector<studentas>);
bool Palyginimas(const studentas&, const studentas&); //Perduoti objects per nuoroda & yra good
bool Palyginimas1(const studentas&);
