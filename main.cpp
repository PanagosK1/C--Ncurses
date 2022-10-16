#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <panel.h>
#include <curses.h>
#include <vector>
#include <string.h>
#include "Engine.h"
#include "Moving.h"
#include "HiScore.h"
#include <exception>


using namespace std;

int main () {  
    
    string mapi ;
    string bina;
    int end=0;
    string name;
    char ans;
    do{
        int l=0;
        int score=0;
        int cat=1;
        Engine en;
        cout<<"Before we start, lets load the map." << endl;
        while(l!=1){
            cat=1;
            cout<< endl << "Insert the name of the map :" <<endl;
            cin >> mapi;
            try
            {
                en.getmap(mapi);
            }
            catch (std::ifstream::failure e) {
                cerr << "Error while trying to open the file.\nTry again!"<<endl;
                cat=0;
            }
            if(cat!=0){
                l=1;	
            }
        }
        en.loadmap();
        score=en.game();
        cout << "**************************" << endl ;
        cout << endl << endl ;
        cout<<"Thank you for playing our little adventure" << endl << "Insert your name below :" <<endl;
        cin >> name;
        cout << "**************************" << endl ;
        cout << endl << endl ;
        cout<<"Player : " << name << endl << "Final Score : " << score << endl;
        HiScore sc1;
        sc1<<name<<score;
        sc1.addScore();
        sc1.Print();
        l=0;
        while(l!=1){
            cat=1;
            cout<< endl << "Insert the binary file to write the scores :" <<endl;
            cin >> bina;
            try
            {
                sc1.Score2binary(bina);
            }
            catch (std::ofstream::failure e) {
                cerr << "Error while trying to open the file.\nTry again!"<<endl;
                cat=0;
            }
            if(cat!=0){
                l=1;	
            }
        }

        cout<<endl<<endl;
        cout<<"Have fun and enjoy!"<<endl;
        cout<<"Would you like to try again."<< endl;
        cout<<"Type Y/y for another try :"<<endl;
        cin >> ans;
        if (ans=='Y' || ans=='y')
        {
            end=1;
        }
        else
            end=0;
    } while(end!=0);

    
    return 0;
}