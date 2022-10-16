#include "Potter.h"


Potter::Potter(int x,int y):Moving(x,y){

}

int Potter::Move(vector <string> &map){
    int err=0;
    int ch;

        ch = getch();
        switch (ch)
        {
        case KEY_UP:
            if(map[cy-1][cx]!='*'){ 
                mvaddch(cy,cx,' ');
                map[cy][cx]=' ';
                cy--;
                }
            break;
        case KEY_DOWN : 
            if(map[cy+1][cx]!='*'){ 
                mvaddch(cy,cx,' ');
                map[cy][cx]=' ';
                cy++;
                }
            break;
        case KEY_RIGHT : 
            if(map[cy][cx+1]!='*'){ 
                mvaddch(cy,cx,' ');
                map[cy][cx]=' ';
                cx++;
                }
            break;
        case KEY_LEFT : 
            if(map[cy][cx-1]!='*'){ 
                mvaddch(cy,cx,' ');
                map[cy][cx]=' ';
                cx--;
                }
            break;
        case 32 : 
            break;
        case 27 :
            return 1;
            break;
        default:
            break;
        }
        attron(COLOR_PAIR(3));
        mvaddch(cy,cx,'P');
        map[cy][cx]='P';
        refresh();

    return 0;
}

