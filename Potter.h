#ifndef POTTER_H
#define POTTER_H
#include "Moving.h"
#include <string>
#include <vector>

using namespace std;

class Potter : public Moving
{
    protected:

    public:
        Potter(int ,int );
        int Move(vector <string> &);
        void getGem();
};

#endif

