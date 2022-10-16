#include "Gnome.h"


Gnome::Gnome(int x,int y):Moving(x,y){

}


int Gnome::Move(vector <string> &m){
int flag=0;
    while (flag!=1)
    {
        int random= rand()%4;
        if(random==0 && prvy!=cy){
            if(m[cy-1][cx]!='*' && m[cy-1][cx]!='T')
            {   
                if (m[cy][cx]=='$')
                {
                    attron(COLOR_PAIR(4));
                    mvaddch(cy,cx,'$');
                }
                else if(m[cy][cx]=='&')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(cy,cx,'&');
                }                
                else if (m[cy][cx]=='P')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                    return 1;
                }
                else
                {             
                    mvaddch(cy,cx,' ');
                    m[cy][cx]=' ';
                }
                prvy=cy;
                cy--;
                if (m[cy][cx]=='$')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                }
                else if(m[cy][cx]=='&')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                }
                else if (m[cy][cx]=='P')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                    return 1;
                }
                else{
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                }
                flag=1;
            }
            else 
            {
                flag=0;
            }
        }
        else if(random==1 && prvy!=cy){
            if(m[cy+1][cx]!='*' && m[cy+1][cx]!='T')
            {
                if (m[cy][cx]=='$')
                {
                    attron(COLOR_PAIR(4));
                    mvaddch(cy,cx,'$');
                }
                else if(m[cy][cx]=='&')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(cy,cx,'&');
                }                
                else if (m[cy][cx]=='P')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                    return 1;
                }
                else
                {             
                    mvaddch(cy,cx,' ');
                    m[cy][cx]=' ';
                }
                prvy=cy;
                cy++;
               if (m[cy][cx]=='$')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                }
                else if(m[cy][cx]=='&')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                }
                else if (m[cy][cx]=='P')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                    return 1;
                }
                else{
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                }
                flag=1;
            }else 
            {
                flag=0;
            }
        }
        else if(random==2 && prvx!=cx){
            if(m[cy][cx+1]!='*' && m[cy][cx+1]!='T')
            {
                if (m[cy][cx]=='$')
                {
                    attron(COLOR_PAIR(4));
                    mvaddch(cy,cx,'$');
                }
                else if(m[cy][cx]=='&')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(cy,cx,'&');
                }                
                else if (m[cy][cx]=='P')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                    return 1;
                }
                else
                {             
                    mvaddch(cy,cx,' ');
                    m[cy][cx]=' ';
                }
                prvx=cx;
                cx++;
                if (m[cy][cx]=='$')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                }
                else if(m[cy][cx]=='&')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                }
                else if (m[cy][cx]=='P')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                    return 1;
                }
                else{
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                }
                flag=1;
            }else 
            {
                flag=0;
            }
        }
        else if(random==3 && prvx!=cx){
            if(m[cy][cx-1]!='*' && m[cy][cx-1]!='T')
            {
                if (m[cy][cx]=='$')
                {
                    attron(COLOR_PAIR(4));
                    mvaddch(cy,cx,'$');
                }
                else if(m[cy][cx]=='&')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(cy,cx,'&');
                }                
                else if (m[cy][cx]=='P')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                    return 1;
                }
                else
                {             
                    mvaddch(cy,cx,' ');
                    m[cy][cx]=' ';
                }
                prvx=cx;
                cx--;
                if (m[cy][cx]=='$')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                }
                else if(m[cy][cx]=='&')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                }
                else if (m[cy][cx]=='P')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                    return 1;
                }
                else{
                    attron(COLOR_PAIR(2));
                    mvaddch(cy,cx,'G');
                    m[cy][cx]='G';
                }
                flag=1;
            }else 
            {
                flag=0;
            }
        }
    }
}

