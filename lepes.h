#ifndef LEPES_H_INCLUDED
#define LEPES_H_INCLUDED
enum CollisionRule
{
can_collide,
has_to_collide,
cant_collide,
};


struct Lepes
{
    int iter;
    CollisionRule collide;
    int direction[2];
    Lepes():iter(), collide(), direction() {}
    Lepes(int d1, int d2, int it, CollisionRule co): iter(it), collide(co){direction[0]=d1; direction[1]=d2;}
};


#endif // LEPES_H_INCLUDED
