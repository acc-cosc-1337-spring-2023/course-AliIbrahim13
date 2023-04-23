#include "tic_tac_toe.h"
#include "math.h"

using namespace std;

// TicTacToe class

TicTacToe::TicTacToe(int size) : pegs(size*size, " ") {}
TicTacToe::TicTacToe(vector<string> p, string win) : pegs(p), winner(win) {}

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

bool TicTacToe::check_board_full()
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

std::ostream &operator<<(std::ostream &out, const TicTacToe &game)
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

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    cout << "Enter position from 1 to " << game.pegs.size() << ": ";
    in >> position;
    game.mark_board(position);

    return in;
}
