/*
    is a beta version.
    classic game of life by nightmare01.
    type make to compile it.
*/
#include<ncurses.h>

int main()
{

    int i,j, x, ch,y,  count;
    initscr();
    char mat[LINES][COLS], mat2[LINES][COLS];
    for(i = 0;i < LINES;i++)
    {
        for(j = 0;j < COLS; j++)
        {
            mat[i][j] = ' ';
        }
    }
    start_color();
    noecho();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    attron(COLOR_PAIR(1));
    printw("i: Insert Neigh or erase Neigh\ns: play\nq/k: quit\nCreated by nightmare01\nPress any key to start.");
    getch();
    erase();
    for(i = 0;i < LINES;i++)
    {
        for(j = 0;j < COLS; j++)
        {
            mvprintw(i,j,"%c",mat[i][j]);
        }
    }
    move(0,0);
    do
    {
        keypad (stdscr, TRUE);
        getyx (stdscr, y, x);

        ch = getch();

        switch(ch)
        {

            case KEY_UP:
                move(y-1, x);
                break;
            case KEY_LEFT:
                move(y, x-1);
                break;
            case KEY_RIGHT:
                if(x != COLS)
                    move(y, x+1);
                break;
            case KEY_DOWN:
                if(y != LINES)
                    move(y+1,x);
                break;
            case  'i':
                if(mat[y][x] == 'o')
                    mat[y][x] = ' ';
                else
                    mat[y][x] = 'o';
                for(i = 0;i < LINES;i++)
                {
                    for(j = 0;j < COLS; j++)
                    {
                        mvprintw(i,j,"%c",mat[i][j]);
                    }
                }
                move(y,x);
                break;
            case 's':
                curs_set(0);
                timeout(200);
                while(getch() != 'q')
                {


                    for(i = 0;i < LINES;i++)
                    {
                        for(j = 0;j<COLS;j++)
                        {
                            mat2[i][j] = ' ';
                        }
                    }

                    for(i = 0;i < LINES;i++)
                    {
                        for(j = 0;j < COLS; j++)
                        {
                            count = 0;
                            if(mat[i-1][j-1] == 'o')
                                count++;
                            if(mat[i-1][j] == 'o')
                                count++;
                            if(mat[i-1][j+1] == 'o')
                                count++;
                            if(mat[i][j-1] == 'o')
                                count++;
                            if(mat[i][j+1] == 'o')
                                count++;
                            if(mat[i+1][j-1] == 'o')
                                count++;
                            if(mat[i+1][j] == 'o')
                                count++;
                            if(mat[i+1][j+1] == 'o')
                                count++;
                            if(count < 2)
                                mat2[i][j] = ' ';
                            if(count > 3)
                                mat2[i][j] = ' ';
                            if((count == 2 || count == 3) && mat[i][j] == 'o')
                            {
                                mat2[i][j] = 'o';
                            }
                            if(count == 3 && mat[i][j] == ' ')
                                mat2[i][j] = 'o';
                        }

                    }
                    for(i = 0;i < LINES;i++)
                    {
                        for(j = 0;j<COLS;j++)
                        {
                            mat[i][j] = mat2[i][j];
                        }
                    }
                    erase();
                    for(i = 0;i < LINES;i++)
                    {
                        for(j = 0;j < COLS; j++)
                        {
                            mvprintw(i,j,"%c",mat[i][j]);
                        }
                    }

                }
                break;
            case 'q':
                ch = -1;
        }
    }while(ch != -1);
    endwin();

    return 0;
}
