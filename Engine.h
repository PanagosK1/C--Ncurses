#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <panel.h>
#include <curses.h>
#include <vector>
#include "Moving.h"
#include "Potter.h"
#include "HiScore.h"
#include "Gnome.h"
#include "Traal.h"
#include <exception>



#define ROUNDS 1000


using namespace std;

class Engine{
    protected:
        std::vector <std::string> map;

    public:
        void getmap(const string) ;
        void loadmap();
        void addGems();
        void addMonsters();
        void addPotter();
        void GetRandomPos(int &,int &);
        void getPos(int &,int & , const char);
        int Score(int);
        int game();
        int spawnPerg();

};

#endif