#include "tic_tac_toe.h"
#include <iostream>

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

std::string TicTacToe::get_player() const
{
    return player;
}

void TicTacToe::display_board() const
{
    std::cout << "-------------\n";
    std::cout << "| " << pegs[0] << " | " << pegs[1] << " | " << pegs[2] << " |\n";
    std::cout << "-------------\n";
    std::cout << "| " << pegs[3] << " | " << pegs[4] << " | " << pegs[5] << " |\n";
    std::cout << "-------------\n";
    std::cout << "| " << pegs[6] << " | " << pegs[7] << " | " << pegs[8] << " |\n";
    std::cout << "-------------\n";
}

std::string TicTacToe::get_winner() const
{
    return winner;
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
    for (auto &peg : pegs)
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

bool TicTacToe::check_column_win() const
{
    for (int i = 0; i < 3; i++)
    {
        if (pegs[i] == pegs[i + 3] && pegs[i] == pegs[i + 6] && pegs[i] != " ")
        {
            return true;
        }
    }

    return false;
}

bool TicTacToe::check_row_win() const
{
    for (int i = 0; i < 9; i += 3)
    {
        if (pegs[i] == pegs[i + 1] && pegs[i] == pegs[i + 2] && pegs[i] != " ")
        {
            return true;
        }
    }

    return false;
}

bool TicTacToe::check_diagonal_win() const
{
    if (pegs[0] == pegs[4] && pegs[0] == pegs[8] && pegs[0] != " ")
    {
        return true;
    }
    else if (pegs[2] == pegs[4] && pegs[2] == pegs[6] && pegs[2] != " ")
    {
        return true;
    }
    else
    {
        return false;
    }
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

void TicTacToe::set_winner()
{
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        winner = player;
    }
    else if (check_board_full())
    {
        winner = "C";
    }
}
