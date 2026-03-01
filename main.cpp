#include <iostream>

constexpr int N_ELEMENTS = 100;

int main()
{
    int *b = new int[NELEMENTS]; // BUG: NELEMENTS helyett N_ELEMENTS kell (hiányzik az aláhúzás)
    std::cout << '1-100 ertekek duplazasa' // BUG: single quote helyett idézőjel kell, hiányzik a << std::endl;
    for (int i = 0;) // BUG: hiányzik a feltétel (i < N_ELEMENTS) és az inkrementálás (i++)
    {
        b[i] = i * 2;
    }
    for (int i = 0; i; i++) // BUG: feltétel hibás, i helyett i < N_ELEMENTS kell
    {
        std::cout << "Ertek:" // BUG: hiányzik << b[i] << std::endl; és a pontosvessző
    }    
    std::cout << "Atlag szamitasa: " << std::endl;
    int atlag; // BUG: nincs inicializálva, int atlag = 0; kellene
    for (int i = 0; i < N_ELEMENTS, i++) // BUG: vessző helyett pontosvessző kell
    {
        atlag += b[i] // BUG: hiányzik a pontosvessző
    }
    atlag /= N_ELEMENTS;
    std::cout << "Atlag: " << atlag << std::endl;
    // BUG: hiányzik a memória felszabadítás: delete[] b;
    return 0;
}
