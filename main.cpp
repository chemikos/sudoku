#include <iostream>
#include "sudoku.h"

using namespace std;

int main()
{
    srand(time(NULL));
    int ile_liczb;
    clock_t start, stop;
    double czas;
    for (;;)
    {
        cout<<"Podaj ile liczb ma byc widoczne (od 17 do 80): ";
        while (!((cin>>ile_liczb).good())||ile_liczb>80||ile_liczb<17)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Jestes Yeti, wpisz jeszcze raz: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n' );
        start = clock();
        sudoku test(ile_liczb);
        stop = clock();
        czas = (double)(stop-start)/CLOCKS_PER_SEC;
        cout<<"czas generowania: "<<czas<<"s"<<endl;
        test.show_sudoku();
    }
    return 0;
}
