#include "babu.h"
#include "lepes.h"
#include "tabla.h"
#include <ctime>
#include <iostream>




int main()
{
    int sor, oszlop;
    table tablam;
    Lepes theStep;
    std::cout<<tablam;
    std::cin>>sor;
    std::cin>>oszlop;
    Lepes* steps=tablam.get_tabla()[sor][oszlop]->pattern_assign();
    do
    {
        theStep=tablam.get_tabla()[sor][oszlop]->move(steps);

    }while(tablam.move_validation(theStep, sor, oszlop)!=true);
    std::cout<<tablam;
    return 0;
}
