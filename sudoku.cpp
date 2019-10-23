#include "sudoku.h"

sudoku::sudoku()
{
    randnum=number=81;
    rand_num = new int[randnum][2];
    set_game();
}
sudoku::sudoku(int n)
{
    number=n;
    if (n<LIMIT)
        randnum=LIMIT;
    else
        randnum=n;
    rand_num = new int[randnum][2];
    set_game();
}
sudoku::~sudoku()
{
    std::cout<<"oto dzielo zniszczenia!!!"<<std::endl;
    delete [] rand_num;
}

sudoku::sudoku(const sudoku& other)
{
    //copy ctor
}

sudoku& sudoku::operator=(const sudoku& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
bool sudoku::check_number(int tab[][10],int n, int row, int col)
{
    /*/ diagonals, need to change set_full_board()
    if (row==col)
        for (int i=1;i<10;i++)
            if (tab[row][col]==tab[i][i])
                return true;
    if (row+col==10) //think about when i==5 && j==5
        for (int i=1;i<10;i++)
            if (tab[row][col]==tab[i][10-i])
                return true;
    /*/
    for (int i=1;i<10;i++)
        if ((tab[row][i]==n)||(tab[i][col]==n))
            return true;
    row=((row-1)/3)*3+1;
    col=((col-1)/3)*3+1;
    for (int i=row;i<row+3;i++)
        for (int j=col;j<col+3;j++)
            if (tab[i][j]==n)
                return true;
    return false;
}
void sudoku::reset(int n)
{
    if (n==-1)
        for (int i=0;i<10;i++)
            for (int j=0;j<10;j++)
                full_board[i][j]=0;
    if (n==1) //zerowanie tablic game i result
        for (int i=0;i<10;i++)
            for (int j=0;j<10;j++)
                game[i][j]=result[i][j]=0;
    if (n==2) //kopiowanie game do result
        for (int i=0;i<10;i++)
            for (int j=0;j<10;j++)
                result[i][j]=game[i][j];
}
void sudoku::reset_rand_num()
{
    for (int i=0;i<randnum;i++)
        rand_num[i][0]=rand_num[i][1]=0;
}
void sudoku::set_full_board()
{
    int temp,sample,test;
    sample=0;
    start:
        reset(-1);
        test=0;
        /*/first set diagonals - have to change!!!
        //backslash
        for (int i=1;i<10;i++)
        {
            temp=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
            while (check_number(full_board,temp,i,i)&&test<1001)
            {
                temp=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
                test++;
            }
            if (test>1000)
            {
                ++sample;
                if (sample>1000000000)
                    goto theend;
                goto start;
            }
            full_board[i][i]=temp;
        }
        sample=test=0;
        //slash
        for (int i=1;i<10;i++)
        {
            if (i==5)
                continue;
            temp=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
            while (check_number(full_board,temp,i,10-i)&&test<1001)
            {
                temp=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
                test++;
            }
            if (test>1000)
            {
                ++sample;
                if (sample>1000000000)
                    goto theend;
                goto start;
            }
            full_board[i][10-i]=temp;
        }
        //diagnals end, need to change code below to work with diagonals*/
        for (int i=1;i<10;i++)
            for (int j=1;j<10;j++)
            {
                //if was set any number
                if (full_board[i][j]!=0)
                    continue;
                temp=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
                while(check_number(full_board,temp,i,j)&&test<1001)
                    {
                        temp=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
                        test++;
                    }
                if (test>1000)
                {
                    ++sample;
                    /* only chcecking
                    if (sample%1000000==0)
                        std::cout<<"sample no.: "<<sample<<std::endl;
                    */
                    if (sample>1000000000)
                            goto theend;
                    goto start;
                }
                full_board[i][j]=temp;
            }
    theend:
    if (sample>1000000000)
        std::cout<<"Error, game couldn't be set"<<std::endl;
    return;
}
void sudoku::show_sudoku(int n)
{
    std::cout<<"Widoczne liczby: "<<number<<std::endl;
    for (int i=1;i<10;i++)
    {
        for (int j=1;j<10;j++)
        {
            if (j==4||j==7)
                std::cout<<"| ";
            if (n==-1)
            {
                if (full_board[i][j]==0)
                    std::cout<<"_";
                else
                    std::cout<<full_board[i][j];
                if (j!=9)
                    std::cout<<" ";
            }
            if (n==1)
            {
                if (game[i][j]==0)
                    std::cout<<"_";
                else
                    std::cout<<game[i][j];
                if (j!=9)
                    std::cout<<" ";
            }
        }
        std::cout<<std::endl;
        if ((i%3==0)&&i<9)
            std::cout<<"---------------------"<<std::endl;
    }
    std::cout<<std::endl;
}
void sudoku::random_numbers()
{
    reset_rand_num();
    for (int i=0;i<randnum;i++)
    {
        rand_num[i][0]=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
        rand_num[i][1]=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
        for (int j=0;j<i;j++)
        {
            while ((rand_num[j][0]==rand_num[i][0])&&(rand_num[j][1]==rand_num[i][1]))
            {
                rand_num[i][0]=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
                rand_num[i][1]=rand()%9+1;//std::experimental::randint(1,9);//experimental/random
                j=0;
            }
        }
    }
}
void sudoku::show_rand() //helper
{
    for (int i=0;i<randnum;i++)
        std::cout<<rand_num[i][0]<<" "<<rand_num[i][1]<<std::endl;
}
 void sudoku::set_game()
 {
    if (number<LIMIT)
    {
        int n, m;
        m=0;
        do {
            do {
            set_full_board();
            random_numbers();
            reset(1); //zerowanie tablic game i result
            for (int i=0;i<randnum;i++)
                game[rand_num[i][0]][rand_num[i][1]]=full_board[rand_num[i][0]][rand_num[i][1]];
            } while (solve()==false);
            n=solve_super();
            //blok informacyjny
            m++;
            std::cout<<m<<" ";
            if (m%20==0)
                std::cout<<std::endl;
            //koniec bloku informacyjnego
        } while (n!=number);
        number=n;
    }
    else
    {
        do {
            set_full_board();
            random_numbers();
            reset(1);
            for (int i=0;i<randnum;i++)
                game[rand_num[i][0]][rand_num[i][1]]=full_board[rand_num[i][0]][rand_num[i][1]];
        } while (solve()==false);
    }
    save_to_file(number);
 }
 bool sudoku::solve()
 {
    reset(2);
    if (!solve_19()||!check_result())
        return false;
    reset(2);
    if (!solve_91()||!check_result())
        return false;
    reset(2);
    if (!solve_reverse_19()||!check_result())
        return false;
    reset(2);
    if (!solve_reverse_91()||!check_result())
        return false;
    return true;
 }
bool sudoku::back_19(int& a, int&b)
{
    do {
        b--;
        if (b<1)
            {
                a--;
                b=9;
                if (a<1)
                    return false;
            }
    } while (game[a][b]!=0);
    if (result[a][b]==9)
    {
        result[a][b]=0;
        back_19(a,b);
    }
    return true;
}
bool sudoku::back_91(int& a, int&b)
{
    do {
        b--;
        if (b<1)
            {
                a--;
                b=9;
                if (a<1)
                    return false;
            }
    } while (game[a][b]!=0);
    if (result[a][b]==1)
    {
        result[a][b]=0;
        back_91(a,b);
    }
    return true;
}
bool sudoku::back_reverse_19(int& a, int&b)
{
    do {
        b++;
        if (b>9)
            {
                a++;
                b=1;
                if (a>9)
                    return false;
            }
    } while (game[a][b]!=0);
    if (result[a][b]==9)
    {
        result[a][b]=0;
        back_reverse_19(a,b);
    }
    return true;
}
bool sudoku::back_reverse_91(int& a, int&b)
{
    do {
        b++;
        if (b>9)
            {
                a++;
                b=1;
                if (a>9)
                    return false;
            }
    } while (game[a][b]!=0);
    if (result[a][b]==1)
    {
        result[a][b]=0;
        back_reverse_91(a,b);
    }
    return true;
}
bool sudoku::solve_19()
{
    for (int i=1;i<10;i++)
    {
        for (int j=1;j<10;j++)
        {
            if (game[i][j]!=0)
                continue;
            for (int k=1;k<10;k++)
            {
                back19:
                if (result[i][j]!=0)
                    {
                        k=result[i][j]+1;
                        result[i][j]=0;
                    }
                if (check_number(result,k,i,j))
                {
                    if (k<9)
                      continue;
                    else
                    {
                        if (back_19(i,j))
                            goto back19;
                        else
                            return false;
                    }
                }
                else
                    {
                        result[i][j]=k;
                        break;
                    }
            }
        }
    }
    return true;
}
bool sudoku::solve_91()
{
    for (int i=1;i<10;i++)
    {
        for (int j=1;j<10;j++)
        {
            if (game[i][j]!=0)
                continue;
            for (int k=9;k>0;k--)
            {
                back91:
                if (result[i][j]!=0)
                    {
                        k=result[i][j]-1;
                        result[i][j]=0;
                    }
                if (check_number(result,k,i,j))
                {
                    if (k>1)
                      continue;
                    else
                    {
                        if (back_91(i,j))
                            goto back91;
                        else
                            return false;
                    }
                }
                else
                    {
                        result[i][j]=k;
                        break;
                    }
            }
        }
    }
    return true;
}
bool sudoku::solve_reverse_19()
{
    for (int i=9;i>0;i--)
    {
        for (int j=9;j>0;j--)
        {
            if (game[i][j]!=0)
                continue;
            for (int k=1;k<10;k++)
            {
                back_reverse19:
                if (result[i][j]!=0)
                    {
                        k=result[i][j]+1;
                        result[i][j]=0;
                    }
                if (check_number(result,k,i,j))
                    {
                        if (k<9)
                            continue;
                        else
                        {
                            if (back_reverse_19(i,j))
                                goto back_reverse19;
                            else
                                return false;
                        }
                    }
                else
                    {
                        result[i][j]=k;
                        break;
                    }
            }
        }
    }
    return true;
}
bool sudoku::solve_reverse_91()
{
    for (int i=9;i>0;i--)
    {
        for (int j=9;j>0;j--)
        {
            if (game[i][j]!=0)
                continue;
            for (int k=9;k>0;k--)
            {
                back_reverse91:
                if (result[i][j]!=0)
                    {
                        k=result[i][j]-1;
                        result[i][j]=0;
                    }
                if (check_number(result,k,i,j))
                    {
                        if (k>1)
                            continue;
                        else
                        {
                            if (back_reverse_91(i,j))
                                goto back_reverse91;
                            else
                                return false;
                        }
                    }
                else
                    {
                        result[i][j]=k;
                        break;
                    }
            }
        }
    }
    return true;
}
bool sudoku::check_result()
{
    for (int i=1;i<10;i++)
        for (int j=1;j<10;j++)
            if (full_board[i][j]!=result[i][j])
                return false;
    return true;
}
int sudoku::solve_super()
{
    int c=LIMIT-1;//indeks tablicy rand_num[][]
    int n=LIMIT;
    int temp;
    while (c>0&&n>number&&n>LIMIT_MIN)
    {
        reset(2);
        temp=game[rand_num[c][0]][rand_num[c][1]];
        game[rand_num[c][0]][rand_num[c][1]]=result[rand_num[c][0]][rand_num[c][1]]=0;
        if (!solve())
        {
            reset(2);
            game[rand_num[c][0]][rand_num[c][1]]=result[rand_num[c][0]][rand_num[c][1]]=temp;
        }
        else
            n--;
        c--;
    }
    return n;
}
void sudoku::save_to_file(int nr)
{
    std::fstream file;
    std::string fname=".txt";
    std::string no = std::to_string(nr);
    file.open((no+fname).c_str(),std::ios::out|std::ios::app);
    if (!file.good())
    {
        std::cout<<"File not open!"<<std::endl;
        return;
    }
    else
    {
        for (int i=1;i<10;i++)
        {
            for (int j=1;j<10;j++)
            {
                file<<game[i][j];
                if (j!=9)
                    file<<" ";
            }
            file<<std::endl;
        }
    }
    file<<std::endl;
    file.close();
}
