#include <vector>
#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

class Grid{
    public:
        //Member functions declaration
        void print_vector();
        void make_move(int player_num);
        void start_game();
        void check_win1();
        void check_win2();
    
    //private:
        vector< vector<int> > state;
        int game_won;


        //Constructor definition
        Grid()
            : state(3, vector<int>(3)), game_won(0)
        {
            print_vector();
        }

};


//Member functions definitions
void Grid::print_vector(){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            //print out the row and column of the vector
            cout << "[" << i << "][" << j << "]: " << state[i][j];
            //some formatting
            if (j==2){
                cout << endl;
            }
            else{
                cout << setw(7);
            }
        }
    }
}

void Grid::make_move(int player_num){
    int row;
    int column;

    //Notify which player has a turn
    cout << "It is player " << player_num << "'s turn." << endl;
    //Ask for row input
    cout << "Which row do you want to play?";
    cin >> row;
    if(cin.fail()){
        cin.clear();//clear the buffer.
        cin.ignore(999, '\n');
        return make_move(player_num);}
    //check if the row is within the range of the grid.
    if(row!=0 && row!=1 && row!=2){
        cout << "That row does not exist. Please choose a different row." << endl;
        return make_move(player_num);
    }
    //Ask for column input
    cout << "Which column do you want to play?";
    cin >> column;
    if(cin.fail()){
        cin.clear();//clear the buffer.
        cin.ignore(999, '\n');
        return make_move(player_num);}
    //check if the column is within the range of the grid.
    if(column!=0 && column!=1 && column!=2){
        cout << "That column does not exist. Please choose a different column." << endl;
        return make_move(player_num);
    }

    //Check that the chosen field has not already been assigned a value.
    if(state[row][column]!=0){
        cout << "This field has already been chosen! Choose another field." << endl;
        return make_move(player_num);
    }
    //Change the chosen value to the player number.
    state[row][column] = player_num;
    //Show the game state after the move.
    print_vector();
 
}

void Grid::start_game(){
    int turn_count = 0;
    while(turn_count<9){
        if(game_won == 1){
            cout << "Congratulations Player 1! You won!" << endl;
            return;
        }
        else if(game_won ==2){
            cout << "Congratulations Player 2! You won!" << endl;
            return;
        }
        else if(turn_count<9){
            make_move(turn_count%2+1);
            check_win1();
            check_win2();
            turn_count++;
        }
    }
    //if 9 moves have been made and no game_won, then stalmate.
    cout << "stalmate!" << endl;
}

void Grid::check_win1(){
    //game states if Player 1 wins
    if(state[0][0]==1 && state[0][1]==1 && state[0][2]==1){
        game_won = 1;
    }
    else if(state[1][0]==1 && state[1][1]==1 && state[1][2]==1){
        game_won = 1;
    }
    else if(state[2][0]==1 && state[2][1]==1 && state[2][2]==1){
        game_won = 1;
    }
    else if(state[0][0]==1 && state[1][0]==1 && state[2][0]==1){
        game_won = 1;
    }
    else if(state[0][1]==1 && state[1][1]==1 && state[2][1]==1){
        game_won = 1;
    }
    else if(state[0][2]==1 && state[1][2]==1 && state[2][2]==1){
        game_won = 1;
    }
    else if(state[0][0]==1 && state[1][1]==1 && state[2][2]==1){
        game_won = 1;
    }
    else if(state[0][2]==1 && state[1][1]==1 && state[2][0]==1){
        game_won = 1;
    }
}
void Grid::check_win2(){
    //game states if Player 2 wins
    if(state[0][0]==2 && state[0][1]==2 && state[0][2]==2){
        game_won = 2;
    }
    else if(state[1][0]==2 && state[1][1]==2 && state[1][2]==2){
        game_won = 2;
    }
    else if(state[2][0]==2 && state[2][1]==2 && state[2][2]==2){
        game_won = 2;
    }
    else if(state[0][0]==2 && state[1][0]==2 && state[2][0]==2){
        game_won = 2;
    }
    else if(state[0][1]==2 && state[1][1]==2 && state[2][1]==2){
        game_won = 2;
    }
    else if(state[0][2]==2 && state[1][2]==2 && state[2][2]==2){
        game_won = 2;
    }
    else if(state[0][0]==2 && state[1][1]==2 && state[2][2]==2){
        game_won = 2;
    }
    else if(state[0][2]==2 && state[1][1]==2 && state[2][0]==2){
        game_won = 2;
    }
}

int main(){
    Grid NewGrid; //Declare a new grid of type Grid
    
    NewGrid.start_game();
    
    return 0;
}