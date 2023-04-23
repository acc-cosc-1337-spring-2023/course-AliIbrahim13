#include "tic_tac_toe_4.h"


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

