#include "vector.h"

int main(){
    unsigned int sz = 10000;   // 100000, 1000000, 10000000, 100000000
    vector<int> v1;
    Vektorius<int> v2;

    for (int i = 0; i < 5; i++){
        auto start_1 = std::chrono::system_clock::now();
        v1.resize(sz);
        for (int i = 1; i <= sz; ++i)
            v1.push_back(i);
        auto end_1 = std::chrono::system_clock::now();
        std::chrono::duration<double> diff_1 = end_1-start_1;

        printf("\n> %i elementu uzpildymas i STL vektoriu truko: %f sekundziu\n", sz, diff_1.count());
        
        auto start_2 = std::chrono::system_clock::now();
        v2.resize(sz);
        for (int i = 1; i <= sz; ++i)
            v2.push_back(i);
        auto end_2 = std::chrono::system_clock::now();
        std::chrono::duration<double> diff_2 = end_2-start_2;

        printf("> %i elementu uzpildymas i mano vektoriu truko: %f sekundziu\n\n", sz, diff_2.count());

        sz *= 10;

        v1.clear();
        v2.clear();
    }
}