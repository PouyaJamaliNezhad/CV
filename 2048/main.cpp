#include <bits\stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void swap(int &spot1, int &spot2)
{
    int lol = spot1;
    spot1 = spot2;
    spot2 = lol;
}

bool Wadd(vector<vector<int>> &board, int &score)
{
    bool isChangable = false;
    int currentSpot, nextSpot;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            currentSpot = board[j][i];
            for(int k=j+1; k<4; k++)
            {
                nextSpot = board[k][i];
                if(currentSpot == nextSpot && nextSpot != 0)
                {
                    score += board[j][i];
                    board[j][i] *= 2;
                    board[k][i] = 0;
                    isChangable = true;
                    break;
                }
                else if(currentSpot != nextSpot && nextSpot != 0)
                {
                    break;
                }
            }
        }
    }
    return isChangable;
}
bool Aadd(vector<vector<int>> &board, int &score)
{
    bool isChangable = false;
    int currentSpot, nextSpot;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            currentSpot = board[i][j];
            for(int k=j+1; k<4; k++)
            {
                nextSpot = board[i][k];
                if(currentSpot == nextSpot && nextSpot != 0)
                {
                    score += board[i][j];
                    board[i][j] *= 2;
                    board[i][k] = 0;
                    isChangable = true;
                    break;
                }
                else if(currentSpot != nextSpot && nextSpot != 0)
                {
                    break;
                }
            }
        }
    }
    return isChangable;
}
bool Sadd(vector<vector<int>> &board, int &score)
{
    bool isChangable = false;
    int currentSpot, nextSpot;
    for(int i=3; i>=0; i--)
    {
        for(int j=3; j>=1; j--)
        {
            currentSpot = board[j][i];
            for(int k=j-1; k>=0; k--)
            {
                nextSpot = board[k][i];
                if(currentSpot == nextSpot && nextSpot != 0)
                {
                    score += board[j][i];
                    board[j][i] *= 2;
                    board[k][i] = 0;
                    isChangable = true;
                    break;
                }
                else if(currentSpot != nextSpot && nextSpot != 0)
                {
                    break;
                }
            }
        }
    }
    return isChangable;
}
bool Dadd(vector<vector<int>> &board, int &score)
{
    bool isChangable = false;
    int currentSpot, nextSpot;
    for(int i=3; i>=0; i--)
    {
        for(int j=3; j>=1; j--)
        {
            currentSpot = board[i][j];
            for(int k=j-1; k>=0; k--)
            {
                nextSpot = board[i][k];
                if(currentSpot == nextSpot && nextSpot != 0)
                {
                    score += board[i][j];
                    board[i][j] *= 2;
                    board[i][k] = 0;
                    isChangable = true;
                    break;
                }
                else if(currentSpot != nextSpot && nextSpot != 0)
                {
                    break;
                }
            }
        }
    }
    return isChangable;
}

bool Wmove(vector<vector<int>> &board)
{
    bool isChangable = false;
    int currentSpot, nextSpot;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            currentSpot = board[j][i];
            if(currentSpot == 0)
            {
                for(int k=j+1; k<4; k++)
                {
                    nextSpot = board[k][i];
                    if(nextSpot != 0)
                    {
                        swap(board[j][i], board[k][i]);
                        isChangable = true;
                        break;
                    }
                }
            }
        }
    }
    return isChangable;
}
bool Amove(vector<vector<int>> &board)
{
    bool isChangable = false;
    int currentSpot, nextSpot;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            currentSpot = board[i][j];
            if(currentSpot == 0)
            {
                for(int k=j+1; k<4; k++)
                {
                    nextSpot = board[i][k];
                    if(nextSpot != 0)
                    {
                        swap(board[i][j], board[i][k]);
                        isChangable = true;
                        break;
                    }
                }
            }
        }
    }
    return isChangable;
}
bool Smove(vector<vector<int>> &board)
{
    bool isChangable = false;
    int currentSpot, nextSpot;
    for(int i=3; i>=0; i--)
    {
        for(int j=3; j>=1; j--)
        {
            currentSpot = board[j][i];
            if(currentSpot == 0)
            {
                for(int k=j-1; k>=0; k--)
                {
                    nextSpot = board[k][i];
                    if(nextSpot != 0)
                    {
                        swap(board[j][i], board[k][i]);
                        isChangable = true;
                        break;
                    }
                }
            }
        }
    }
    return isChangable;
}
bool Dmove(vector<vector<int>> &board)
{
    bool isChangable = false;
    int currentSpot, nextSpot;
    for(int i=3; i>=0; i--)
    {
        for(int j=3; j>=1; j--)
        {
            currentSpot = board[i][j];
            if(currentSpot == 0)
            {
                for(int k=j-1; k>=0; k--)
                {
                    nextSpot = board[i][k];
                    if(nextSpot != 0)
                    {
                        swap(board[i][j], board[i][k]);
                        isChangable = true;
                        break;
                    }
                }
            }
        }
    }
    return isChangable;
}

bool addSpots(vector<vector<int>> &board, int &score, char input)
{
    if(input == 'w')
    {
        return Wadd(board, score);
    }
    else if(input == 'a')
    {
        return Aadd(board, score);
    }
    else if(input == 's')
    {
        return Sadd(board, score);
    }
    else if(input == 'd')
    {
        return Dadd(board, score);
    }
    return false;
}
bool moveSpots(vector<vector<int>> &board, char input)
{
    if(input == 'w')
    {
        return Wmove(board);
    }
    else if(input == 'a')
    {
        return Amove(board);
    }
    else if(input == 's')
    {
        return Smove(board);
    }
    else if(input == 'd')
    {
        return Dmove(board);
    }
    return false;
}
void addNumber2(vector<vector<int>> &board)
{
    srand(time(0));
    vector<int> emptySpots;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(board[i][j] == 0)
            {
                int spot = (i+1)*10 + (j+1);
                emptySpots.push_back(spot);
            }
        }
    }
    int randomNumb = rand()%emptySpots.size();
    int randomSpot = emptySpots[randomNumb];
    board[(randomSpot/10)-1][(randomSpot%10)-1] = 2;
}

bool lostCheck(vector<vector<int>> board)
{
    // first we check if there are any zeros or not
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(board[i][j] == 0) return false;
        }
    }

    //then we check if there are any possible moves or not
    for(int i=0; i<4; i++) //checking vertical
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == board[i][j+1]) return false;
        }
    }
    for(int i=0; i<4; i++) //checking horizantal
    {
        for(int j=0; j<3; j++)
        {
            if(board[j][i] == board[j+1][i]) return false;
        }
    }
    return true;
}
bool winCheck(vector<vector<int>> board)
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(board[i][j] == 2048) return true;
        }
    }
    return false;
}

int colorOfSpot(int spotNumber)
{
    switch (spotNumber)
    {
    case 2:
        return 13;
    case 4:
        return 11;
    case 8:
        return 9;
    case 16:
        return 2;
    case 32:
        return 6;
    case 64:
        return 4;
    default:
        return 12;
    }
    return 0;
}
void printTheBoard(vector<vector<int>>board, int score)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "score: " << score << endl;
    for(int i=0; i<4; i++)
    {
        cout << " ________";
    }
    cout << endl;
    //////////////////////
    for(int i=0; i<4; i++)
    {
        //line1
        cout << '|';
        for(int j=0; j<4; j++)
        {
            cout << "        |";
        }
        cout << endl;
        //line2
        cout << '|';
        for(int j=0; j<4; j++)
        {
            cout << "  ";
            if(board[i][j] == 0)
            {
                cout << "    ";
            }
            else
            {
                SetConsoleTextAttribute(hConsole, colorOfSpot(board[i][j]));
                if(board[i][j] <10) cout << "   ";
                else if(board[i][j] < 100) cout << "  ";
                else if(board[i][j] < 1000) cout << ' ';
                cout << board[i][j];
                SetConsoleTextAttribute(hConsole, 7);
            }
            cout << "  |";
        }
        cout << endl;
        //line3
        cout << '|';
        for(int j=0; j<4; j++)
        {
            cout << "________|";
        }
        cout << endl;
    }
}


int main()
{
    // setting up the board and everything we need
    vector<vector<int>> board(4);
    for(int i=0; i<4; i++)
    {
        board[i] = vector<int>(4);
    }
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            board[i][j] = 0;
        }
    }
    int score = 0;
    char input;
    // the player enters his name to save his best score
    

    // now we start the game
    addNumber2(board);
    printTheBoard(board, score);
    while(true)
    {
        enteringInput :
        cout << ">> "; input = getch();
        if(input != 'w' && input != 'a' && input != 's' && input != 'd')
        {
            cout << "wrong input you idiot !" << endl;
            goto enteringInput;
        }

        bool boardIsChangableCheck1 = addSpots(board, score, input);
        bool boardIsChangableCheck2 = moveSpots(board, input);
        if(boardIsChangableCheck1 == false && boardIsChangableCheck2 == false)
        {
            cout << "can't do anythings you idiot" << endl;
            goto enteringInput;
        }

        addNumber2(board);
        cout << endl;
        printTheBoard(board, score);
        //check win or lost
        if(lostCheck(board) == true)
        {
            cout << "you lost :(" << endl;
            break;
        }
        if(winCheck(board) == true)
        {
            cout << "wow you won you reached 2048 :)" << endl;
            break;
        }
    }
}