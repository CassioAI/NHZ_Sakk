#include "babu.h"
#include "lepes.h"
#include "tabla.h"
#include <iostream>

bool table::move_validation(Lepes& chosen, int& sor_koor, int& oszlop_koor)
{
    int n=0;
    switch (chosen.collide)
    {
        case cant_collide:
            while(chosen.iter>=n)
            {
                if(base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]!=NULL)
                {
                    return false;
                }
                n++;

            }
            base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]=base_table[sor_koor][oszlop_koor];
            base_table[sor_koor][oszlop_koor]=NULL;
            return true;
         case can_collide:
            while(chosen.iter>=n)
            {
                if((base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]!=NULL && n!=chosen.iter) ||
                (base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]!=NULL &&
                base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]->get_color()==base_table[sor_koor][oszlop_koor]->get_color()))
                {
                    return false;
                }
                n++;
            }
            base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]=base_table[sor_koor][oszlop_koor];
            base_table[sor_koor][oszlop_koor]=NULL;
            return true;

         case has_to_collide:
            while(chosen.iter>=n)
            {
                if((base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]!=NULL && n!=chosen.iter)||
                (base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]!=NULL &&
                base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]->get_color()==base_table[sor_koor][oszlop_koor]->get_color()))
                {
                    return false;
                }
                if(base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]==NULL && n!=chosen.iter)
                {
                    return false;
                }
                n++;
            }
            base_table[sor_koor+chosen.direction[0]][oszlop_koor+chosen.direction[1]]=base_table[sor_koor][oszlop_koor];
            base_table[sor_koor][oszlop_koor]=NULL;
            return true;

    }
}

std::ostream& operator<<(std::ostream& os, table& rhs)
{
    for(int i=-1; i<=15; ++i)
    {
        for(int j=-1; j<=15; ++j)
        {
            if(i%2!=0)
            {
                os<<"--";
            }
            else
            {
                if(j%2!=0)
                {
                    os<<"|";
                }
                else
                {
                    if(rhs.base_table[i/2][j/2]==NULL)
                    {
                        os<<"  ";
                    }

                    else
                    {
                        os<<rhs.base_table[i/2][j/2]->get_nev()<<rhs.base_table[i/2][j/2]->get_color();
                    }
                }
            }
        }
        os<<std::endl;

    }
    return os;

}

table::table(std::istream& is)
{
    int peices;
    char type;
    char color;
    int sor;
    int oszlop;
    std::cout<<"Add meg a babukat: mennyi, milyen tipus,szin,sor, oszlop"<<' ';
    base_table= new Babu**[8];
    for(int i=0; i<=7; ++i)
    {
        base_table[i]= new Babu*[8];
    }
    for(int i=0; i<=7; ++i)
    {
       for(int j=0; j<=7; ++j)
       {
           base_table[i][j]=NULL;
       }
    }
    is>>peices;
    if(peices>64 or peices<1)
    {
        throw std::range_error("Too few or too much peices");
    }
    for(int i=1; i<=peices; ++i)
    {
        is>>type;
        is>>color;
        is>>sor;
        is>>oszlop;
        switch (type)
        {
        case 'B':
            base_table[sor][oszlop]= new Bishop(color,sor,oszlop);
            break;
        case 'R':
            base_table[sor][oszlop]= new Rook(color,sor,oszlop);
            break;
        case 'N':
            base_table[sor][oszlop]= new Knight(color,sor,oszlop);
            break;
        case 'Q':
            base_table[sor][oszlop]= new Queen(color,sor,oszlop);
            break;
        case 'K':
            base_table[sor][oszlop]= new King(color,sor,oszlop);
            break;
        case 'P':
            base_table[sor][oszlop]= new Pawn(color,sor,oszlop);
            break;

        }

    }

}
void table::tiszt_set(char color)
{
    int sor;
    if(color=='W')
    {
        for(int i=0; i<=7; ++i)
        {
            base_table[1][i]=new Pawn(color, 1,i);
        }
            base_table[0][4]= new King(color, 0,5);
            base_table[0][3]= new Queen(color, 0,5);
            sor=0;
    }
    else
    {
        for(int i=0; i<=7; ++i)
        {
            base_table[6][i]=new Pawn(color, 6,i);
        }
        sor=7;
        base_table[sor][3]= new King(color, 0,5);
        base_table[sor][4]= new Queen(color, 0,5);
    }
    base_table[sor][0]= new Rook(color, sor,0);
    base_table[sor][1]= new Knight(color, sor,1);
    base_table[sor][2]= new Bishop(color, sor,2);
    base_table[sor][5]= new Bishop(color, sor,5);
    base_table[sor][6]= new Knight(color, sor,6);
    base_table[sor][7]= new Rook(color, sor,7);
    return;
}
table::table()
{
    base_table= new Babu**[8];
    for(int i=0; i<=7; ++i)
    {
        base_table[i]= new Babu*[8];
    }
    for(int i=0; i<=7; ++i)
    {
       for(int j=0; j<=7; ++j)
       {
           base_table[i][j]=NULL;
       }
    }
    tiszt_set('W');
    tiszt_set('B');
}















