#include "mylib.h"

class zmogus{
    protected:
    string vardas;
    vector<double> paz; //o kodel ne? zmogus daro nd, bet tampa studentu tik atejes i egzamina :)
    zmogus(string v = "", vector<double> p={}) : vardas{v}, paz{p} {}
    public:
    virtual string getVardas() const = 0; //abstrakcios funkcijos
    virtual double getGal_vid() const = 0;
    virtual double getGal_med() const = 0;
    virtual void galBalas() = 0;
    virtual ~zmogus() { paz.clear(); }
};
class studentas: public zmogus{
    private:
    int egz;
    double gal_vid, gal_med;
    public:
    studentas() : zmogus{} {}
    studentas(string vardas, int egz_, vector<double> paz) : zmogus{vardas, paz}, egz{egz_} { galBalas(); } //default
    studentas(const studentas& v) : zmogus{v.vardas, v.paz}, egz{v.egz} { galBalas(); } //copy constructor
    studentas(studentas&& v) : zmogus{std::move(v.vardas), std::move(v.paz)}, egz{v.egz} { v.egz = 0; v.paz.clear(); galBalas(); } //move constructor
    studentas& operator=(const studentas& v); //copy assignment construcor
    studentas& operator=(studentas&& v); //move assignment constructor
    friend std::ostream& operator<<(std::ostream& out, const studentas& v); //out
    friend std::istream& operator>>(std::istream& in, studentas &v); //in
    inline string getVardas() const { return vardas; } //getter funkcijas visuomet tikslinga daryti const
    inline double getGal_vid() const { return gal_vid; }
    inline double getGal_med() const { return gal_med; }
    void galBalas();
    ~studentas() {} //destruktorius
    //using zmogus::getVardas; //kad gautume protected member funkcija is base klases kaip public is derived
};

void gen_map(int, int);
studentas nuskaitymas(string, int); 
void spausd(string, vector<studentas>);
bool Palyginimas(const studentas&, const studentas&); //Perduoti objects per nuoroda & yra good
bool Palyginimas1(const studentas&);
