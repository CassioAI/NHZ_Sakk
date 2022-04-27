#ifndef BABU_H_INCLUDED
#define BABU_H_INCLUDED
#include "lepes.h"
class Babu
{
protected:
    char color;
    int oszlop;
    int sor;
//    static int pattern_s[dir];
//    static int pattern_o[dir];
public:
    //Babu(char c, char n, int o, int s, int d): nev(n), color(c), oszlop(o), sor(s), dir(d) {}
    Babu(char c, int o, int s): color(c), oszlop(o), sor(s) {};
    Babu(const Babu& peice);
    int get_oszlop();
    int  get_sor();
    virtual get_dir()=0;
    virtual char get_nev()=0;
    virtual Lepes* pattern_assign()=0;
    char get_color() {return color;}
    void set_coordinates();
    Lepes move(Lepes* steps);
    virtual Lepes* asess(int pat[][2], int cap);
};

class Pawn: public Babu
{
public:
    Pawn(char c, int s, int o);
    int get_dir(){return 3;};
    char get_nev(){return 'P';}
    Lepes* asses(int pat[][2], int cap);
    Lepes* pattern_assign();
};

class Rook: public Babu
{
public:
    Rook(char c, int s, int o);
    int get_dir(){return 4;}
    char get_nev(){return 'R';}
    Lepes* pattern_assign();
};
class Bishop: public Babu
{
public:
    Bishop(char c, int s, int o);
    Bishop(const Bishop& piece);
    int get_dir(){return 4;}
    char get_nev(){return 'B';}
    Lepes* pattern_assign();
};
class Knight: public Babu
{
public:
    Knight(char c, int s, int o);
    int get_dir(){return 8;}
    char get_nev(){return 'N';}
    Lepes* pattern_assign();
};
class Queen: public Babu
{
public:
    Queen(char c, int s, int o);
    int get_dir(){return 8;}
    char get_nev(){return 'Q';}
    Lepes* pattern_assign();
};
class King: public Babu
{
public:
    King(char c, int s, int o);
    int get_dir(){return 8;}
    char get_nev(){return 'K';}
    Lepes* pattern_assign();
};

#endif // BABU_H_INCLUDED
