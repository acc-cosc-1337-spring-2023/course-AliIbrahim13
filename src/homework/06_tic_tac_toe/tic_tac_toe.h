#include <string>
#include <vector>

class TicTacToe
{
public:
    TicTacToe() = default;
    TicTacToe(std::vector<std::string> p, std::string win) : pegs{ p }, winner{ win } {};

    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player() const;
    void display_board() const;
    std::string get_winner() const;
    bool game_over();
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

private:
    void set_next_player();
    bool check_board_full() const;
    bool check_column_win() const;
    bool check_row_win() const;
    bool check_diagonal_win() const;
    std::vector<std::string> pegs{ 9, " " };
    std::string winner{ "" };
    std::string player{ "" };
    void clear_board();
    void set_winner();
};
