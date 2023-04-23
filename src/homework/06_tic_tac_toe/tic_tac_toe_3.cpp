#include "tic_tac_toe_3.h"

bool TicTacToe3::check_column_win() const
{
    return (pegs[0] == pegs[3] && pegs[3] == pegs[6] && pegs[0] != " ") ||
           (pegs[1] == pegs[4] && pegs[4] == pegs[7] && pegs[1] != " ") ||
           (pegs[2] == pegs[5] && pegs[5] == pegs[8] && pegs[2] != " ");
}

bool TicTacToe3::check_row_win() const
{
    return (pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[0] != " ") ||
           (pegs[3] == pegs[4] && pegs[4] == pegs[5] && pegs[3] != " ") ||
           (pegs[6] == pegs[7] && pegs[7] == pegs[8] && pegs[6] != " ");
}

bool TicTacToe3::check_diagonal_win() const
{
    return (pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[0] != " ") ||
           (pegs[2] == pegs[4] && pegs[4] == pegs[6] && pegs[2] != " ");
}

