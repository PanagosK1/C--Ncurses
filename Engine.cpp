#include "Engine.h"
#include <iostream>


void Engine::getmap(const string str) {
    string line;
    ifstream myfile (str);
    if (!myfile.is_open()) {
        throw std::ios::failure("Error opening file");
    }

    while (getline(myfile,line)) {
        map.push_back(line);
        line.clear();
    }
    myfile.close();
}


void Engine::loadmap(){
    int px, py=0;

	initscr ();
    clear ();
    noecho();
    start_color();
	keypad (stdscr,TRUE);
    refresh();
    curs_set(false);
    init_pair (1, COLOR_WHITE, COLOR_BLACK);
    init_pair (2, COLOR_RED, COLOR_BLACK);
    init_pair (3, COLOR_CYAN, COLOR_BLACK);
    init_pair (4, COLOR_GREEN, COLOR_BLACK);
    init_pair (5, COLOR_YELLOW, COLOR_BLACK);
    color_set (1, 0);
    for (int i=0; i<map.size();i++)
    {
        for(int j=0;j<map[i].size();j++)
        {
            if(map[i][j]=='*')
                mvaddch(i,j,map[i][j]+177);
            else
                mvaddch(i,j,map[i][j]);
        }
    }
    addGems();
    addMonsters();
    addPotter();
}


void Engine::addGems(){
    int j;
    int x,y=0;
    srand(time(NULL));
    x=rand() % (map[0].size()-1);
    y=rand() % (map.size()-1) ; 
    for(j=0; j<10 ;j++){
        do
        {
            x=rand() % (map[0].size()-1);
            y=rand() % (map.size()-1) ; 
        } while (map[y][x]=='*' || map[y][x]=='$');
        attron(COLOR_PAIR(4));
        mvaddch(y,x,'$');
        map[y][x]='$';
    }
    refresh();
}



void Engine::GetRandomPos(int &x,int &y){
    x=rand() % (map[0].size()-1);
    y=rand() % (map.size()-1) ; 
    while (map[y][x]=='*' || map[y][x]=='G' || map[y][x]=='T' || map[y][x]=='P'){
        x=rand() % (map[0].size()-1);
        y=rand() % (map.size()-1) ; 
    }
}

void Engine::addMonsters(){
    int j;
    int x,y=0;
    attron(COLOR_PAIR(2));
    GetRandomPos(x,y);
    mvaddch(y,x,'G');
    map[y][x]='G';

    GetRandomPos(x,y);
    mvaddch(y,x,'T');
    map[y][x]='T';
}

void Engine::getPos(int &x ,int &y,const char c){
    for(int i=0;i<map.size();i++){
        for (int j = 0; j < map[0].size(); j++)
        {
            if(map[i][j]==c)
            {
                x=j;
                y=i;
            }
        }    
    }
}

void Engine::addPotter(){
    int x,y=0;
    GetRandomPos(x,y);
    mvaddch(y,x,'P');
    map[y][x]='P';
}

int Engine::Score(int check){
    int gems=10;
    int perg=1;
    int sum=0;
    if(check!=1){
        for(int i=0;i<map.size();i++){
            for (int j = 0; j < map[0].size(); j++)
            {
                if(map[i][j]=='$')
                {
                    gems--;
                }
            }    
        }
        return sum = (gems * 10);
    }
    else{
        for(int i=0;i<map.size();i++){
            for (int j = 0; j < map[0].size(); j++)
            {
                if(map[i][j]=='&')
                {
                    perg--;
                }
            }    
        }
        return sum = 100 + (perg*100);
    }
}


int Engine::game(){
    int px,py,gx,gy,tx,ty=0;
    int score=0;
    int ch;
    int round=1;
    int perg=0;
    int end=0;
    int dead=0;
    int alive=0;
    int esc=0;
    getPos(gx,gy,'G');
    Gnome g(gx,gy);
    getPos(tx,ty,'T');
    Traal t(tx,ty);
    getPos(px,py,'P');
    Potter p(px,py);
    refresh();
    do
    {
        if ((dead=g.Move(map))==1)
        {
            end=1;
        }
        if ((dead=t.Move(map))==1)
        {
            end=1;
        }
        color_set(1,0);
        mvprintw(0,55,"POTTERS ADVENTURE");
        mvprintw(1,55,"Tips : ");
        mvprintw(2,55,"1)You can move only with the arrows. ");
        mvprintw(3,55,"2)Press Escape to quit the game. ");
        mvprintw(4,55,"3)Press Space to stay still. ");
        mvprintw(5,55,"4)Collect all the green gems to spawn the scroll ");
        mvprintw(6,55,"5)If you manage to collect them all, Congrats !");
        mvprintw(7,55,"6)WARNING:");
        mvprintw(8,55,"Dont get near the monsters....THEY ARE NOT FRIENDLY ");
        mvprintw(10,55,"GL & HF :D");
        mvprintw(25,0,"Current Round : %d" ,round);
        mvprintw(26,0,"Score : %d" ,score=Score(perg));
        round++;
        if(Score(perg)==100 && perg!=1){
            perg=spawnPerg();
        }
        if (Score(perg)==200)
        {
            end=1;
            alive=1; 
            score=200;          
        }
    } while (end!=1 && !(esc=p.Move(map))); 
    endwin ();

    if (esc == 1)
    {
        cout << endl<<endl<<endl;
        cout << "**********************" << endl;
        cout << "*** Player Quitted ***" <<endl ;
        cout << "**********************" << endl;
    }else if(alive==1){
        cout << endl<<endl<<endl;
        cout << "**************" << endl;
        cout << "*** WINNER ***" << endl ;
        cout << "**************" << endl;
        cout<< " Potter won the labyrinth !!" << endl;
    }
    else    
    {   
        cout << endl<<endl<<endl;
        cout << "**************" << endl;
        cout << "*** LOSSER ***" << endl ;
        cout << "**************" << endl;
        cout<< " Potter died to monsters !!" << endl;
    }

    return score;
}

int Engine::spawnPerg(){
    int x,y=0;
    GetRandomPos(x,y);
    attron(COLOR_PAIR(5));
    mvaddch(y,x,'&');
    map[y][x]='&';
    return 1;
}