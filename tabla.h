#ifndef TABLA_H_INCLUDED
#define TABLA_H_INCLUDED
#include "babu.h"
#include <iostream>
class table
{
private:
    Babu*** base_table;
public:
    table(std::istream& is);
    table();
    void tiszt_set(char color);
    Babu*** get_tabla() {return base_table;}
    void move_input();
    bool cm_check(Lepes& chosen);
    bool move_validation(Lepes& chosen, int& sor_koor, int& oszlop_koor);
    friend std::ostream& operator<<(std::ostream& os, table& rhs);
};



#endif // TABLA_H_INCLUDED
