#ifndef GNOME_H
#define GNOME_H
#include "Moving.h"
#include <string>
#include <vector>

using namespace std;

class Gnome : public Moving
{
    protected:
        int prvy,prvx=0;

    public:
        Gnome(int ,int );
        int Move(vector <string> &);
};

#endif

