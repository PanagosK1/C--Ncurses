#ifndef TRAAL_H
#define TRAAL_H
#include "Moving.h"
#include <string>
#include <vector>

using namespace std;

class Traal : public Moving
{
    protected:
        int prvy,prvx=0;

    public:
        Traal(int ,int );
        int Move(vector <string> &);
};

#endif

