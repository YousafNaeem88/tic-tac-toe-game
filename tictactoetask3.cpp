#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>> &board);
bool checkWin(const vector<vector<char>> &board, char player);
bool checkDraw(const vector<vector<char>> &board);
void switchPlayer(char &currentPlayer);

int main()
{

    vector<vector<char>> board(3, vector<char>(3, ' '));

    char currentPlayer = 'X';

    bool gameFinished = false;

    while (!gameFinished)
    {

        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer))
            {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameFinished = true;
            }
            else if (checkDraw(board))
            {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameFinished = true;
            }
            else
            {

                switchPlayer(currentPlayer);
            }
        }
        else
        {
            cout << "Invalid move! Try again." << endl;
        }
    }

    return 0;
}

void displayBoard(const vector<vector<char>> &board)
{
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>> &board, char player)
{

    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>> &board)
{

    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer)
{
    if (currentPlayer == 'X')
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'X';
    }
}
