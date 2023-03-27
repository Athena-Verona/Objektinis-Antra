#include "mylib.h"

struct studentas{
    char vardas[31];
    vector<float> paz;
    int egz;
    float gal_vid, gal_med;
};

void gen_map(int N, int size);
void balas(studentas&);
void spausd(string, list<studentas>);
bool Palyginimas(const studentas&, const studentas&);
bool Palyginimas1(const studentas&);
