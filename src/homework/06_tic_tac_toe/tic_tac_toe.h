#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>
#include <iostream>

class TicTacToe
{
public:
    TicTacToe(int size);
    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player() const;
    std::string get_winner() const;
    std::vector<std::string> get_pegs() const;
    TicTacToe(std::vector<std::string> p, std::string win);

    friend std::istream& operator>>(std::istream& in,  TicTacToe& game);
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);

protected:
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();
    bool check_board_full();
    void set_winner();
    void set_next_player();
    void clear_board();
    std::vector<std::string> pegs; // Declare the pegs variable here

private:
    std::string player;
    std::string winner;
};


#endif // TICTACTOE_H
