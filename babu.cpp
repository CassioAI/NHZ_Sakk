#include "babu.h"
#include "lepes.h"
#include <ctime>
#include <iostream>
Bishop::Bishop(char c='W', int s=0, int o=2): Babu(c,o,s){}
Pawn::Pawn(char c='W', int s=1, int o=0): Babu(c,o,s){}
Queen::Queen(char c='W', int s=0, int o=3): Babu(c,o,s){}
King::King(char c='W', int s=0, int o=4): Babu(c,o,s){}
Rook::Rook(char c='W', int s=0, int o=0): Babu(c,o,s){}
Knight::Knight(char c='W', int s=0, int o=1): Babu(c,o,s){}

Lepes* Babu::asess(int pat[][2], int cap)
{
    Lepes* steps=new Lepes[get_dir()];
    int id=0;
    for(int i=0, j=0; i<get_dir(); ++i, ++j)
    {
        int n=0;
        while(n<=cap)
        {
            if( ((n+1)*pat[j][1]+oszlop)<0 ||(n+1)*pat[j][1]+oszlop>7 || (n+1)*pat[i][0]+sor<0 || (n+1)*pat[i][0]+sor>7 || cap==1)
            {
                steps[id].iter=n;
                steps[id].direction[1]=pat[j][1];
                steps[id].direction[0]=pat[i][0];
                steps[id].collide=can_collide;
                break;
            }
            ++n;
        }

            ++id;
    }
    return steps;
}
Lepes Babu::move(Lepes* steps)
{
    int random_variable;
    int random_it;
    std::srand(std::time(nullptr));
    do
    {
        do
        {
            random_variable = std::rand()%get_dir();
        }while(steps[random_variable].iter==0);
        random_it= std::rand()%steps[random_variable].iter;
    }while(random_it==0);


    Lepes chosen(steps[random_variable].direction[0],steps[random_variable].direction[1],random_it, steps[random_variable].collide);
    return chosen;

}

Lepes* Bishop::pattern_assign()
{

    int pat[get_dir()][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
    Lepes* steps = Babu::asess(pat, 7);
    return steps;
}
Lepes* Queen::pattern_assign()
{

    int pat[get_dir()][2]={{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{-1,0},{0,-1},{0,1}};
    Lepes* steps = Babu::asess(pat, 7);
    return steps;
}
Lepes* King::pattern_assign()
{

    int pat[get_dir()][2]={{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{-1,0},{0,-1},{0,1}};
    Lepes* steps = Babu::asess(pat, 1);
    return steps;
}
Lepes* Rook::pattern_assign()
{

    int pat[get_dir()][2]={{1,0},{-1,0},{0,-1},{0,1}};
    Lepes* steps = Babu::asess(pat, 7);
    return steps;
}
Lepes* Knight::pattern_assign()
{
    int pat[get_dir()][2]={{2,1},{2,-1},{-2,-1},{-2,1},{1,2},{-1,2},{1,-2},{-1,-2}};
    Lepes* steps = Babu::asess(pat, 1);
    return steps;
}

//1 az oszlop 0-ás a sor
Lepes* Pawn::asses(int pat[][2], int cap)
{
    Lepes* steps=new Lepes[get_dir()];
    int id=0;
    for(int i=0; i<get_dir(); ++i)
    {
        int n=0;
        while(n<=cap)
        {
            if( ((n+1)*pat[i][1]+oszlop)<0 ||(n+1)*pat[i][1]+oszlop>7 || (n+1)*pat[i][0]+sor<0 || (n+1)*pat[i][0]+sor>7 || cap==n)
            {
                steps[id].direction[1]=pat[i][1];
                steps[id].direction[0]=pat[i][0];

                steps[id].iter=n;
                if(pat[i][1]!=0)
                {
                    steps[id].collide=has_to_collide;
                    steps[id].iter=1;
                    break;
                }
                if(sor==6 || sor==1)
                {
                    steps[id].collide=cant_collide;
                    steps[id].iter=2;
                    break;
                }
                else
                {
                    steps[id].collide=can_collide;
                    steps[id].iter=1;
                    break;
                }

            }
            ++n;
        }
            ++id;
    }
    return steps;
}
Lepes* Pawn::pattern_assign()
{
    int patW[get_dir()][2]={{1,0},{1,1},{1,-1}};
    int patB[get_dir()][2]={{-1,0},{-1,1},{-1,-1}};
    Lepes* steps;
    if(get_color()=='W')
    {
        steps=Pawn::asses(patW,2);
    }
    else
    {
       steps=Pawn::asses(patB, 2);
    }
    return steps;
}















