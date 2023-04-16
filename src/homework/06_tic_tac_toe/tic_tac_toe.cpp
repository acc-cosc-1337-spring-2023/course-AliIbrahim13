#include "tic_tac_toe.h"

using namespace std;

// TicTacToe class

TicTacToe::TicTacToe(int size) : pegs(size*size, " ") {}

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

string TicTacToe::get_player() const
{
    return player;
}

string TicTacToe::get_winner() const
{
    return winner;
}

vector<string> TicTacToe::get_pegs() const
{
    return pegs;
}

void TicTacToe::set_next_player()
{
    if (player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

void TicTacToe::clear_board()
{
    for (auto& peg : pegs)
    {
        peg = " ";
    }
}

bool TicTacToe::check_board_full() const
{
    for (auto peg : pegs)
    {
        if (peg == " ")
        {
            return false;
        }
    }

    return true;
}

bool TicTacToe::game_over()
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
    else
    {
        return false;
    }
}

// Protected virtual functions

bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}

void TicTacToe::set_winner()
{
    winner = player;
}

// Overloaded stream operators

ostream& operator<<(ostream& out, const TicTacToe& game)
{
    int size = sqrt(game.pegs.size());

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            out << game.pegs[i * size + j] << " ";
        }
        out << "\n";
    }

    return out;
}

istream& operator>>(istream& in, TicTacToe& game)
{
    int position;
    cout << "Enter position from 1 to " << game.pegs.size() << ": ";
    in >> position;
    game.mark_board(position);

    return in;
}

// TicTacToe3 class

TicTacToe3::TicTacToe3() : TicTacToe(3) {}

bool TicTacToe3::check_column_win()
{
    for (int i = 0; i < 3; i++)
    {
        if (pegs[i] != " " && pegs[i] == pegs[i + 3] && pegs[i] == pegs[i + 6])
        {
            return true;
        }
    }

    return false;
}

bool TicTacToe3::check_row_win()
{
    for (int i = 0; i < 9; i += 3)
    {
        if (pegs[i] != " " && pegs[i] == pegs[i + 1] && pegs[i] == pegs[i + 2])
        {
            return true;
        }
    }

    return false;
}

bool TicTacToe3::check_diagonal_win()
{
        if (pegs[0] !=" " && pegs[0] == pegs[4] && pegs[0] == pegs[8])
        {
            return true;
        }

        if (pegs[2] != " " && pegs[2] == pegs[4] && pegs[2] == pegs[6])
        {
            return true;
        }

    return false;
}

// TicTacToe4 class

TicTacToe4::TicTacTooe4():TicTacToe(4) {}

bool TicTacToe4::check_column_win()
{
    for(int i = O; i < 4; i++)
    {
        if (pegs[i] !+ " " && pegs[i] ==pegs[i + 4] && pegs[i] == pegs[i + 8] && pegs[i] == pegs[i + 12])
        {
            return true;
        }
    }

    return false;
}

bool TicTacToe4::check_row_win()
{
    for (int i = 0; i < 16; i += 4)
    {
        if (pegs[i] != " " && pegs[i] == pegs[i + 1] && pegs[i] == pegs[i + 2] && pegs[i] == pegs[i + 3])
        {
            return true;
        }
    }

    return false;
}

bool TicTacToe3::check_diagonal_win()
{
        if (pegs[0] !=" " && pegs[0] == pegs[5] && pegs[0] == pegs[10] && pegs[0] == pegs[15])
        {
            return true;
        }

        if (pegs[3] != " " && pegs[3] == pegs[6] && pegs[3] == pegs[9] && pegs[3] == pegs[12])
        {
            return true;
        }

    return false;
}
