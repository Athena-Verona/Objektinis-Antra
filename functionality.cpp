#include "vector.h"
int main(){
    vector<int> A;
    Vektorius<int> B;
    //printf("\n> Failo skaitymas i vektorių truko: %f sekundžių\n", diff.count());
    printf("\n>>>>> Tikrinama reserve(100) <<<<<\n");
    printf("> std::vector capacity pries reserve(100): %5lu\n", A.capacity());
    A.reserve(100);
    printf("> std::vector capacity po reserve(100): %5lu\n", A.capacity());

    printf("\n> Vektorius capacity pries reserve(100): %5lu\n", B.capacity());
    B.reserve(100);
    printf("> Vektorius capacity po reserve(100): %5lu\n", B.capacity());


    printf("\n>>>>> Tikrinama shrink_to_fit() <<<<<\n");
    A.push_back(1); A.push_back(2);
    B.push_back(1); B.push_back(2);
    A.push_back(3); A.push_back(4);
    B.push_back(3); B.push_back(4);
    printf("> std::vector capacity pries shrink_to_fit(): %5lu\n", A.capacity());
    A.shrink_to_fit();
    printf("> std::vector capacity po shrink_to_fit(): %5lu\n", A.capacity());

    printf("\n> Vektorius capacity pries shrink_to_fit(): %5lu\n", B.capacity());
    B.shrink_to_fit();
    printf("> Vektorius capacity po shrink_to_fit(): %5lu\n", B.capacity());
    

    printf("\n>>>>> Tikrinama erase() <<<<<\n");
    printf("> std::vector pries istrinant 3 nari: \n");
    for (int a:A) printf("%i ", a);
    A.erase(A.begin()+3);
    printf("\n> std::vector istrynus 3 nari: \n");
    for (int a:A) printf("%i ", a);

    printf("\n\n> Vektorius pries istrinant 3 nari: \n");
    for (int a=0;a<B.size();a++) printf("%i ", B[a]);
    B.erase(B.begin()+3);
    printf("\n> Vektorius istrynus 3 nari: \n");
    for (int a=0;a<B.size();a++) printf("%i ", B[a]);
    cout << endl;


    printf("\n>>>>> Tikrinama pop_back() <<<<<\n");
    printf("> std::vector pries istrinant paskutini nari: \n");
    for (int a:A) printf("%i ", a);
    A.pop_back();
    printf("\n> std::vector istrynus paskutini nari: \n");
    for (int a:A) printf("%i ", a);

    printf("\n\n> Vektorius pries istrinant paskutini nari: \n");
    for (int a=0;a<B.size();a++) printf("%i ", B[a]);
    B.pop_back();
    printf("\n> Vektorius istrynus paskutini nari: \n");
    for (int a=0;a<B.size();a++) printf("%i ", B[a]);
    cout << endl;


    printf("\n>>>>> Tikrinama resize() <<<<<\n");
    A.push_back(1); A.push_back(2);
    B.push_back(1); B.push_back(2);
    A.push_back(3); A.push_back(4);
    B.push_back(3); B.push_back(4);
    printf("> std::vector pries resize(3): \n");
    for (int a:A) printf("%i ", a);
    A.resize(3);
    printf("\n> std::vector po resize(3): \n");
    for (int a:A) printf("%i ", a);

    printf("\n\n> Vektorius pries resize(3): \n");
    for (int a=0;a<B.size();a++) printf("%i ", B[a]);  
    B.resize(3);
    printf("\n> Vektorius po resize(3): \n");
    for (int a=0;a<B.size();a++) printf("%i ", B[a]);
    cout << endl;
}