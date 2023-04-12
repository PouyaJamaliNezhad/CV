// NOTE : in barname ye jadval sudoku misaze va mide be user ta halesh koneh, har bar ye jadval jadid misaze
#include <bits\stdc++.h>
#include <windows.h>
#include "unsolvedGenerator.cpp"

using namespace std;

//new function
bool coardinatesPass(string x, string y, vector<vector<int>>unsolvedBoard)
{
    bool pass = false;
    if(x.size() == 1 && '1' <= x[0] && x[0] <= '9' && y.size() == 1 && '1' <= y[0] && y[0] <= '9')
    {
        int posX = x[0] - '0'-1;
        int posY = y[0] - '0'-1;
        if(unsolvedBoard[posX][posY] == 0)
        {
            pass = true;
        }
    }
    return pass;
}
bool choosingCommandPass(string command)
{
    bool pass = false;
    if((command.size() == 1 && '1' <= command[0] && command[0] <= '9') || command == "-")
    {
        pass = true;
    }
    return pass;
}
void howToPlay()
{
    cout << "how to play: " << endl;
    cout << "to put a number first choose the number you want to put then choose the coardinates of that spot" << endl;
    cout << "to delete a number enter (-) and then choose the spot you want to remove the its number" << endl;
    cout << "to stop deleting or choose another number enter (s)" << endl;
    cout << "good luck ;)" << endl;
}
bool solvedCheck(vector<vector<int>>board, vector<vector<int>>fullBoard)
{
    bool isSolved = true;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(board[i][j] != fullBoard[i][j])
            {
                isSolved = false;
                return isSolved;
            }
        }
    }
    return isSolved;
}
int colorOfSpot(int spotNumber)
{
    switch (spotNumber)
    {
    case 1:
        return 12;
    case 2:
        return 9;
    case 3:
        return 14;
    case 4:
        return 2;
    case 5:
        return 13;
    case 6:
        return 4;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 11;
    }
    return 0;
}
void printTheBoard(vector<vector<int>>board)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "  ";
    for(int i=1; i<10; i++)
    {
        cout << "   " << i << "  ";
    }
    cout << endl << "  ";
    for(int i=0; i<9; i++)
    {
        cout << " _____";
    }
    cout << endl << "  ";
    //////////////////////
    for(int j=0; j<9; j++)
    {
        // line 1
        cout << '|';
        for(int i=0; i<9; i++)
        {
            if(i == 2 || i == 5)
            {
                SetConsoleTextAttribute(hConsole, 6);
                cout << "     |";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                cout << "     |";
            }
        }
        cout << endl << j+1 << ' ';
        cout << '|';
        // line 2
        for(int i=0; i<9; i++)
        {
            if(i == 2 || i == 5)
            {
                cout << "  ";
                if(board[j][i] == 0)
                {
                    cout << ' ';
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, colorOfSpot(board[j][i]));
                    cout << board[j][i];
                    SetConsoleTextAttribute(hConsole, 7);
                }
                SetConsoleTextAttribute(hConsole, 6);
                cout << "  |";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                cout << "  ";
                if(board[j][i] == 0)
                {
                    cout << ' ';
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, colorOfSpot(board[j][i]));
                    cout << board[j][i];
                    SetConsoleTextAttribute(hConsole, 7);
                }
                cout << "  |";
            }
        }
        cout << endl << "  ";
        cout << '|';
        // line 3
        if(j == 2 || j == 5)
        {
            for(int i=0; i<9; i++)
            {
                if(i == 2 || i == 5)
                {
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << "_____|";
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << "_____";
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << '|';
                }
            }
        }
        else
        {
            for(int i=0; i<9; i++)
            {
                if(i == 2 || i == 5)
                {
                    cout << "_____";
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << '|';
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else
                {
                    cout << "_____|";
                }
            }
        }
        cout << endl << "  ";
    }
}
void printTheBoardForDeleting(vector<vector<int>>board, vector<vector<int>>unsolvedBoard)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "  ";
    for(int i=1; i<10; i++)
    {
        cout << "   " << i << "  ";
    }
    cout << endl << "  ";
    for(int i=0; i<9; i++)
    {
        cout << " _____";
    }
    cout << endl << "  ";
    //////////////////////
    for(int j=0; j<9; j++)
    {
        // line 1
        cout << '|';
        for(int i=0; i<9; i++)
        {
            if(i == 2 || i == 5)
            {
                SetConsoleTextAttribute(hConsole, 6);
                cout << "     |";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                cout << "     |";
            }
        }
        cout << endl << j+1 << ' ';
        cout << '|';
        // line 2
        for(int i=0; i<9; i++)
        {
            if(i == 2 || i == 5)
            {
                cout << "  ";
                if(board[j][i] == 0)
                {
                    cout << ' ';
                }
                else
                {
                    if(unsolvedBoard[j][i] == 0)
                    {
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << board[j][i];
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                    else
                    {
                        cout << board[j][i];
                    }
                }
                SetConsoleTextAttribute(hConsole, 6);
                cout << "  |";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                cout << "  ";
                if(board[j][i] == 0)
                {
                    cout << ' ';
                }
                else
                {
                    if(unsolvedBoard[j][i] == 0)
                    {
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << board[j][i];
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                    else
                    {
                        cout << board[j][i];
                    }
                }
                cout << "  |";
            }
        }
        cout << endl << "  ";
        cout << '|';
        // line 3
        if(j == 2 || j == 5)
        {
            for(int i=0; i<9; i++)
            {
                if(i == 2 || i == 5)
                {
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << "_____|";
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << "_____";
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << '|';
                }
            }
        }
        else
        {
            for(int i=0; i<9; i++)
            {
                if(i == 2 || i == 5)
                {
                    cout << "_____";
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << '|';
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else
                {
                    cout << "_____|";
                }
            }
        }
        cout << endl << "  ";
    }
}

int main()
{
    //setting everything up to start the game
    vector<vector<int>> board(9);
    vector<vector<int>> unsolvedBoard(9);
    vector<vector<int>> fullBoard(9);
    for(int i=0; i<9; i++)
    {
        board[i] = vector<int>(9);
        unsolvedBoard[i] = vector<int>(9);
        fullBoard[i] = vector<int>(9);
    }
    int emptySpotsNumber;
    string difficulty;
    choosingDifficulty:
    cout << "choose the difficulty between 1 to 4: "; cin >> difficulty;
    if(difficulty != "1" && difficulty != "2" && difficulty != "3" && difficulty != "4")
    {
        cout << "please choose a number between 1 or 2 or 3 or 4" << endl;
        goto choosingDifficulty;
    }
    int intDifficulty = difficulty[0] - '0';
    switch (intDifficulty)
    {
    case 1:
        emptySpotsNumber = 40;
        break;
    case 2:
        emptySpotsNumber = 45;
        break;
    case 3:
        emptySpotsNumber = 50;
        break;
    case 4:
        emptySpotsNumber = 55;
        break;
    }
    cout << "ok let's start the game :)" << endl;
    makeTheBoardReady(fullBoard, emptySpotsNumber, unsolvedBoard);
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            board[i][j] = unsolvedBoard[i][j];
        }
    }
    howToPlay();
    printTheBoard(board); cout << "\n";

    //the game starts
    while(solvedCheck(board, fullBoard) == false)
    {
        choosingComand:
        cout << "choose the number you want to put or choose deleting: "; string command; cin >> command;
        if(choosingCommandPass(command) == false)
        {
            cout << "please choose the command correctlly" << endl;
            goto choosingComand;
        }
        if(command == "-")
        {
            cout << "numbers you can remove are red" << endl;
            printTheBoardForDeleting(board, unsolvedBoard);
            while(command != "s")
            {
                cout << "choose the spot you want to delete its number: "; getline(cin, command);
                if(command.size() == 3 && '1' <= command[0] && command[0] <= '9' && command[1] == ' ' && '1' <= command[2] && command[2] <= '9')
                {
                    int posX = command[0] - '0' -1;
                    int posY = command[2] - '0' -1; 
                    if(unsolvedBoard[posX][posY] == 0)
                    {
                        board[posX][posY] = 0;
                        printTheBoardForDeleting(board, unsolvedBoard);
                    }
                    else
                    {
                        cout << "please choose the command correctlly" << endl;
                    }
                }
                else if(command == "s")
                {
                    break;
                }
                else
                {
                    cout << "please choose the command correctlly" << endl;
                }
            }
        }
        else
        {
            int choosenNumber = command[0] - '0';
            string coardinatesX, coardinatesY;
            while(command != "s")
            {
                cout << "choose the spot you want to fill: "; cin >> coardinatesX;
                if(coardinatesX == "s")
                {
                    break;
                }
                cin >> coardinatesY;
                if(coardinatesPass(coardinatesX, coardinatesY, unsolvedBoard) == true)
                {
                    int posX = coardinatesX[0]-'0'-1;
                    int posY = coardinatesY[0]-'0'-1;
                    board[posX][posY] = choosenNumber;
                    printTheBoard(board);
                }
                else
                {
                    cout << "please choose the command correctlly" << endl;
                }
            }
        }
        printTheBoard(board);
    }
    cout << "WOW you solved the puzzle!!!";
}