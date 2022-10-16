#ifndef HISCORE_H
#define HISCORE_H
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

class HiScore{ 
	protected:
        vector <HiScore *> scores;
        string name;
        int score;
        
	public:
		HiScore(const string,const int);
        HiScore();
		~HiScore();
        string getName(); 
	    int getScore() const; 
        HiScore & operator << (const string);
        HiScore & operator << (const int);
        void addScore();
        void Print();
        void Score2binary(const string);
};

#endif
