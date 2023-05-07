#include "mylib.h"

class studentas{
    private:
    string vardas;
    vector<double> paz;
    int egz;
    double gal_vid, gal_med;
    public:
    studentas() : egz(0){} //default
    studentas(string vardas_,int egz_,vector<double> paz_) : vardas{vardas_}, egz{egz_}, paz{paz_} { galBalas(); } //given
    studentas(const studentas& v) : vardas{v.vardas}, egz{v.egz}, paz{v.paz} { galBalas(); } //copy constructor
    studentas(studentas&& v) : vardas{std::move(v.vardas)}, egz{v.egz}, paz{std::move(v.paz)} { v.egz = 0; v.paz.clear(); galBalas(); } //move constructor
    studentas& operator=(const studentas& v); //copy assignment construcor
    studentas& operator=(studentas&& v); //move assignment constructor
    friend std::ostream& operator<<(std::ostream& out, const studentas& v); //out
    friend std::istream& operator>>(std::istream& in, studentas &v); //in
    inline string getVardas() const { return vardas; } //getter funkcijas visuomet tikslinga daryti const
    inline double getGal_vid() const { return gal_vid; }
    inline double getGal_med() const { return gal_med; }
    void galBalas();
    ~studentas() { paz.clear(); } //destruktorius
};

void gen_map(int, int);
void nuskaitymas(string, int, vector<studentas>&); 
void spausd(string, vector<studentas>);
bool Palyginimas(const studentas&, const studentas&); //Perduoti objects per nuoroda & yra good
bool Palyginimas1(const studentas&);
