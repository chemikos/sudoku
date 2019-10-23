#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <ctime>
#include <random>
#include <fstream>
#include <string>
//#include <experimental/random>

const int LIMIT = 35;
const int LIMIT_MIN = 17;

class sudoku
{
    public:
        /** Default constructor */
        sudoku();
        sudoku(int n);
        /** Default destructor */
        ~sudoku();
        /** Copy constructor
         *  \param other Object to copy from
         */
        sudoku(const sudoku& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        sudoku& operator=(const sudoku& other);

        void set_full_board();// ------------------------------------------------------- ok
        void set_game();// ------------------------------------------------------------- ok
        void show_sudoku(int n=1); // -------------------------------------------------- ok
        void show_rand();// ------------------------------------------------------------ ok
        void save_to_file(int n);// ---------------------------------------------------- ok
        bool solve();// ---------------------------------------------------------------- ok
        int solve_super();// ----------------------------------------------------------- ok
        bool solve_19();// ------------------------------------------------------------- ok
        bool solve_91();// ------------------------------------------------------------- ok
        bool solve_reverse_19();// ----------------------------------------------------- ok
        bool solve_reverse_91();// ----------------------------------------------------- ok
        bool back_19(int& a, int& b);// ------------------------------------------------ ok
        bool back_91(int& a, int& b);// ------------------------------------------------ ok
        bool back_reverse_19(int& a, int& b);// ---------------------------------------- ok
        bool back_reverse_91(int& a, int& b);// ---------------------------------------- ok
//    protected:

    private:
        int full_board[10][10];// ----------------------------------------------------- ok
        int game[10][10];// ----------------------------------------------------------- ok
        int result[10][10];// --------------------------------------------------------- ok
        int randnum;// ---------------------------------------------------------------- ok
        int number;// ----------------------------------------------------------------- ok
        int (*rand_num)[2];// --------------------------------------------------------- ok
        void reset(int n);// ---------------------------------------------------------- ok
        void reset_rand_num();// ------------------------------------------------------ ok
        bool check_number(int tab[][10], int n, int row, int col);//------------------- ok
        void random_numbers(); // ----------------------------------------------------- ok
        bool check_result();// -------------------------------------------------------- ok
};

#endif // SUDOKU_H
