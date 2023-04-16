#include "tic_tac_toe_4.h"

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/




/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/



/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/


using namespace std;

bool TicTacToe4::check_column_win() 
{
    for (std::size_t i = 0; i < 4; ++i) 
    {
        if (pegs[i] == pegs[i + 4] && pegs[i] == pegs[i + 8] && pegs[i] == pegs[i + 12] && pegs[i] != " ") 
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_row_win() 
{
    for (std::size_t i = 0; i < 16; i += 4) 
    {
        if (pegs[i] == pegs[i + 1] && pegs[i] == pegs[i + 2] && pegs[i] == pegs[i + 3] && pegs[i] != " ") 
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_diagonal_win() 
{
    bool left_diagonal{pegs[0] != " " && pegs[0] == pegs[5] && pegs[0] == pegs[10] && pegs[0] == pegs[15]};
    bool right_diagonal{pegs[3] != " " && pegs[3] == pegs[6] && pegs[3] == pegs[9] && pegs[3] == pegs[12]};
    
    return left_diagonal || right_diagonal;
}

TicTacToe4::TicTacToe4() : TicTacToe(4) {}

bool TicTacToe4::check_board_full() const
{
    for (std::size_t i = 0; i < 16; ++i)
    {
        if (pegs[i] == " ")
        {
            return false;
        }
    }
    return true;
}

bool TicTacToe4::game_over() 
{
    if (check_column_win() || check_row_win() || check_diagonal_win()) 
    {
        set_winner();
        return true;
    } 
    else if (check_board_full()) 
    {
        winner = "C";
        return true;
    }
    return false;
}
