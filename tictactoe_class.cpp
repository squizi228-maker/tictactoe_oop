#include <iostream>
#include <vector>

class Game {
    private:
    std::vector<char> board;
    char currentPlayer='X';
    int scoreX=0;
    int scoreO=0;
    public:
    Game() {
        board.resize(9,'.');
        currentPlayer='X';
    }
    void run() {
        while (true) {
            drawBoard();
            int input;
            std::cout<<"welcome to my game,player "<<currentPlayer<<" enter the coordinate (0-9) : \n";
            std::cin>>input;
            int pos=input - 1;

            char player = currentPlayer;
            if (!makeMove(pos)) {
                std::cout<<"error\n";
                continue;
            }

            if (checkWin(player)) {
                std::cout<<player<<" Wins!\n";
                return;
            }

            if (isDraw()) {
                drawBoard();
                std::cout<<"draw\n";
                return;
            }
        }
    }
    void drawBoard()const {
        for (int i=0; i<9; ++i) {
            std::cout<<board[i];
            if (i%3==2) std::cout<<'\n';
        }
        std::cout<<'\n';
    }
    bool makeMove(int pos) {
        if (pos<0 || pos>=9) return false;
        if (board[pos] != '.') return false;
        board[pos]=currentPlayer;
        if (currentPlayer=='X') {
            currentPlayer='O';
        }else if (currentPlayer=='O') {
            currentPlayer='X';
        }
        return true;

    }
    bool checkWin(char player) const {
        if( board[0]==player && board[3]==player && board[6]==player){return true;}
        if (board[1]==player && board[4]==player && board[7]==player){return true;}
        else if (board[2]==player && board[5]==player && board[8]==player) {return true;}

        else if(board[0]==player && board[4]==player && board[8]==player){return true;}
        else if(board[2]==player && board[4]==player && board[6]==player){return true;}

        else if(board[3]== player && board[4]== player && board[5]== player){return true;}
        else if(board[0]== player && board[1]== player && board[2]== player) {return true;}
        else if(board[6]== player && board[7]== player && board[8]== player){return true;}
        return false;
    }
    bool isDraw() const {
        for (char c : board) {
            if (c=='.') return false;
        }
        return true;
    }
    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}