#ifndef MOVING_H
#define MOVING_H
#include <string>
#include <vector>
#include <panel.h>
#include <curses.h>
#include <vector>


using namespace std;

class Moving{ 
	protected:
        int cx,cy;
	public:
		Moving(int, int);

        virtual int Move(vector <string> &);

};

#endif