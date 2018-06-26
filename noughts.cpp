#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;



class Grid{
    public:
        //Member functions declaration
        void start_game();
        
        //Constructor definition
        Grid()
            : board(3, vector<int>(3)), _game_won(0)
        {
            print_grid();
        }
    
    private:
        vector< vector<int> > board;
        int _game_won;
        
        //Member functions declaration
        void print_grid();
        int input(string type, int var);
        void make_move(int player_num);
        void check_win(int player_num);
        string print_cell(int row, int column);   
};

//Member functions definitions

//Print the board as a 3 by 3 grid
void Grid::print_grid(){
    cout << print_cell(0,0) << " | " << print_cell(0,1) << " | " << print_cell(0,2) << endl;
    cout << "---------" << endl;
    cout << print_cell(1,0) << " | " << print_cell(1,1) << " | " << print_cell(1,2) << endl;
    cout << "---------" << endl;
    cout << print_cell(2,0) << " | " << print_cell(2,1) << " | " << print_cell(2,2) << endl;
}

//Determine the relevant characters to print in the grid
string Grid::print_cell(int row, int column){
    if (board[row][column] == 0){
        return " ";
    }
    if (board[row][column] == 1){
        return "O";
    }
    if (board[row][column] == 2){
        return "X";
    }
}

//Notifies relevant player, asks for row and column input, checks the move is valid and prints new state of the board.
void Grid::make_move(int player_num){
    int r;
    int c; 

    //Notify which player has a turn
    cout << "It is player " << player_num << "'s turn." << endl;
    
    r = input("row", r);
    c = input("column", c);

    //Check that the chosen field has not already been assigned a value.
    if(board[r][c] != 0)
    {
      cout << "This field has already been chosen! Choose another field." << endl;
      return make_move(player_num);
    }
    //Change the chosen value to the player number.
    board[r][c] = player_num;
    //Show the game board after the move.
    print_grid();
}

//Prompts player to input a move, checks the input is valid, returns chosen row/column.
int Grid::input(string type, int var){
    //Ask for row input
    cout << "Which " << type << " do you want to play?";
    cin >> var;
    //check if the input is an int.
    if(cin.fail()){
        cin.clear();//clear the buffer.
        cin.ignore(999, '\n');
        cout << "Input not valid. Please input an integer." << endl;
        return input(type, var);
        }
    //check if the row is within the range of the grid.
    if(var != 0 && var != 1 && var != 2){
        cout << "That row does not exist. Please choose a different row." << endl;
        return input(type, var);
    }
    return var;
} 

//Keeps track of number of turns to infer stalmate, assigns turns to players and checks for a winner.
void Grid::start_game(){
    int turn_count = 0;

    while(turn_count<9){
        if(_game_won == 1){
            cout << "Congratulations Player 1! You won!" << endl;
            return;
        }
        else if(_game_won ==2){
            cout << "Congratulations Player 2! You won!" << endl;
            return;
        }
        else {
            int player_num = turn_count%2+1;
            make_move(player_num);
            check_win(player_num);
            turn_count++;
        }
    }
    //if 9 moves have been made and no _game_won, then stalmate.
    cout << "stalmate!" << endl;
}

//Check whether the board is in one of the winning states, and if so, set _game_won to the player who won the game.
void Grid::check_win(int player_num){
    //game boards if winner
    if((board[0][0]==player_num && board[0][1]==player_num && board[0][2]==player_num) ||
      (board[1][0]==player_num && board[1][1]==player_num && board[1][2]==player_num) ||
      (board[2][0]==player_num && board[2][1]==player_num && board[2][2]==player_num) ||
      (board[0][0]==player_num && board[1][0]==player_num && board[2][0]==player_num) ||
      (board[0][1]==player_num && board[1][1]==player_num && board[2][1]==player_num) ||
      (board[0][2]==player_num && board[1][2]==player_num && board[2][2]==player_num) ||
      (board[0][0]==player_num && board[1][1]==player_num && board[2][2]==player_num) ||
      (board[0][2]==player_num && board[1][1]==player_num && board[2][0]==player_num)) {
          _game_won = player_num;
      }
}

//Runs the game.
int main(){
    Grid NewGrid; //Declare a new grid of type Grid
    
    NewGrid.start_game();
    
    return 0;
}