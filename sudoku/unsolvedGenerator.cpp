#include <bits\stdc++.h>

using namespace std;

//functions related to solve the board
void addToSum(string &sum, string spot)
{
    for(int k=0; k<9; k++)
    {
        sum[k] += spot[k] - '0';
    }
}
string zoneFinder(int posX, int posY)
{
    if(0 <= posX && posX <= 2 && 0 <= posY && posY <= 2)
    {
        return "0202";
    }
    else if(0 <= posX && posX <= 2 && 3 <= posY && posY <= 5)
    {
        return "0235";
    }
    else if(0 <= posX && posX <= 2 && 6 <= posY && posY <= 8)
    {
        return "0268";
    }
    else if(3 <= posX && posX <= 5 && 0 <= posY && posY <= 2)
    {
        return "3502";
    }
    else if(3 <= posX && posX <= 5 && 3 <= posY && posY <= 5)
    {
        return "3535";
    }
    else if(3 <= posX && posX <= 5 && 6 <= posY && posY <= 8)
    {
        return "3568";
    }
    else if(6 <= posX && posX <= 8 && 0 <= posY && posY <= 2)
    {
        return "6802";
    }
    else if(6 <= posX && posX <= 8 && 3 <= posY && posY <= 5)
    {
        return "6835";
    }
    else if(6 <= posX && posX <= 8 && 6 <= posY && posY <= 8)
    {
        return "6868";
    }
    return "";
}
int zeroCounter(string spot)
{
    int counter = 0;
    for(int i=0; i<9; i++)
    {
        if(spot[i] == '0')
        {
            counter++;
        }
    }
    return counter;
}
bool isSolved(vector<vector<string>> board)
{
    bool solved = true;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(board[i][j] == "111111111")
            {
                solved = false;
                return solved;
            }
        }
    }
    return solved;
}
void whatNumbersCanBe(vector<vector<string>>&board, int posX, int posY)
{
    //checks in columns
    for(int i=0; i<9; i++)
    {
        if(i != posX && zeroCounter(board[i][posY]) == 8 )
        {
            for(int k=0; k<9; k++)
            {
                if(board[i][posY][k] == '1')
                {
                    board[posX][posY][k] = '0';
                    break;
                }
            }
        }
    }
    //checks in rows
    for(int j=0; j<9; j++)
    {
        if(j != posY && zeroCounter(board[posX][j]) == 8 )
        {
            for(int k=0; k<9; k++)
            {
                if(board[posX][j][k] == '1')
                {
                    board[posX][posY][k] = '0';
                    break;
                }
            }
        }
    }
    //checks in zone
    string zone = zoneFinder(posX, posY);
    int i1 = zone[0] - '0'; int i2 = zone[1] - '0'; int j1 = zone[2] - '0'; int j2 = zone[3] - '0';
    for(int i = i1; i <= i2; i++)
    {
        for(int j = j1; j <= j2; j++)
        {
            if((i != posX || j != posY) && zeroCounter(board[i][j]) == 8)
            {
                for(int k=0; k<9; k++)
                {
                    if(board[i][j][k] == '1')
                    {
                        board[posX][posY][k] = '0';
                        break;
                    }
                }
            }
        }
    }
}

void fillTheBoardZone(vector<vector<string>>&board)
{
    string zones[9] = {"0202", "0235", "0268", "3502", "3535", "3568", "6802", "6835", "6868"};
    for(int a = 0; a < 9; a++)
    {
        string currentZone = zones[a];
        int i1 = currentZone[0] - '0'; int i2 = currentZone[1] - '0'; int j1 = currentZone[2] - '0'; int j2 = currentZone[3] - '0';
        string sum = "000000000";
        bool aSpotCanBeFilled = false;
        bool halatKhas = false;
        int spotNumber;
        //now we have preperd everything
        // it's time to do the main job of our function

        //first we calculate our sum
        for(int i = i1; i <= i2; i++)
        {
            for(int j = j1; j <= j2; j++)
            {
                addToSum(sum, board[i][j]);
            }
        }
        //then we want to know if there is a spot that can be filled or not
        for(int k = 0; k < 9; k++)
        {
            if(sum[k] == '1')
            {
                aSpotCanBeFilled = true;
                spotNumber = k;
            }
        }
        //there is a halatKhas that will not work in our algorithm
        if(aSpotCanBeFilled == true)
        {
            for(int i = i1; i <= i2; i++)
            {
                for(int j = j1; j <= j2; j++)
                {
                    if(zeroCounter(board[i][j]) == 8 && board[i][j][spotNumber] == '1')
                    {
                        halatKhas = true;
                    }
                }
            }
            if(halatKhas == false)
            {
                for(int i = i1; i <= i2; i++)
                {
                    for(int j = j1; j <= j2; j++)
                    {
                        if(zeroCounter(board[i][j]) != 8 && board[i][j][spotNumber] == '1')
                        {
                            board[i][j] = "000000000";
                            board[i][j][spotNumber] = '1';
                        }
                    }
                }
            }
        }
    }
}
void fillTheRow(vector<vector<string>>&board, int row)
{
    string sum = "000000000";
    bool aSpotCanBeFilled = false;
    bool halatKhas = false;
    int spotNumber;

    for(int j=0; j<9; j++)
    {
        addToSum(sum, board[row][j]);
    }

    for(int k = 0; k < 9; k++)
    {
        if(sum[k] == '1')
        {
            aSpotCanBeFilled = true;
            spotNumber = k;
        }
    }

    if(aSpotCanBeFilled == true)
    {
        for(int j=0; j<9; j++)
        {
            if(zeroCounter(board[row][j]) == 8 && board[row][j][spotNumber] == '1')
            {
                halatKhas = true;
            }
        }
        if(halatKhas == false)
        {
            for(int j=0; j<9; j++)
            {
                if(zeroCounter(board[row][j]) != 8 && board[row][j][spotNumber] == '1')
                {
                    board[row][j] = "000000000";
                    board[row][j][spotNumber] = '1';
                }
            }
        }
    }
}
void fillTheColumn(vector<vector<string>>&board, int column)
{
    string sum = "000000000";
    bool aSpotCanBeFilled = false;
    bool halatKhas = false;
    int spotNumber;

    for(int i=0; i<9; i++)
    {
        addToSum(sum, board[i][column]);
    }

    for(int k = 0; k < 9; k++)
    {
        if(sum[k] == '1')
        {
            aSpotCanBeFilled = true;
            spotNumber = k;
        }
    }

    if(aSpotCanBeFilled == true)
    {
        for(int i=0; i<9; i++)
        {
            if(zeroCounter(board[i][column]) == 8 && board[i][column][spotNumber] == '1')
            {
                halatKhas = true;
            }
        }
        if(halatKhas == false)
        {
            for(int i=0; i<9; i++)
            {
                if(zeroCounter(board[i][column]) != 8 && board[i][column][spotNumber] == '1')
                {
                    board[i][column] = "000000000";
                    board[i][column][spotNumber] = '1';
                }
            }
        }
    }
}

void emptyTheRow(vector<vector<string>>&board, int row)
{
    for(int j=0; j<9; j++)
    {
        if(zeroCounter(board[row][j]) != 8)
        {
            board[row][j] = "111111111";
        }
    }
}
void emptyTheColumn(vector<vector<string>>&board, int column)
{
    for(int i=0; i<9; i++)
    {
        if(zeroCounter(board[i][column]) != 8)
        {
            board[i][column] = "111111111";
        }
    }
}
void emptyTheBoard(vector<vector<string>>&board)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(zeroCounter(board[i][j]) != 8)
            {
                board[i][j] = "111111111";
            }
        }
    }
}


//other functions
bool isValid(vector<vector<int>>board)
{
    bool isValid = true;
    string zones[9] = {"0202", "0235", "0268", "3502", "3535", "3568", "6802", "6835", "6868"};
    for(int a=0; a<9; a++)
    {
        string currentZone = zones[a];
        int i1 = currentZone[0] - '0'; int i2 = currentZone[1] - '0'; int j1 = currentZone[2] - '0'; int j2 = currentZone[3] - '0';
        for(int i = i1; i <= i2; i++)
        {
            for(int j = j1; j <= j2; j++)
            {
                for(int m = i1; m <= i2; m++)
                {
                    for(int n = j1; n <= j2; n++)
                    {
                        if(board[i][j] == board[m][n] && (i != m || j != n))
                        {
                            isValid = false;
                            return isValid;
                        }
                    }
                }
            }
        }
    }
    return isValid;
}
void generateTheFilledBoard(vector<vector<int>>&board)
{
    vector<int> helper;
    bool foundOne;
    int numberOfSwitches = 0;
    while(foundOne == false || numberOfSwitches < 10000)
    {
        foundOne = false;
        int rowOrColumn = rand()%2;
        //if rowOrColumn is 0 we go to switch rows and if it's 1 we go for columns
        if(rowOrColumn == 0)
        {
            choosingRows:
            int row1 = rand()%9;
            int row2 = rand()%9;
            if(row1 == row2)
            {
                goto choosingRows;
            }
            //filling the helper vector
            for(int j=0; j<9; j++)
            {
                helper.push_back(board[row1][j]);
            }
            for(int j=0; j<9; j++)
            {
                board[row1][j] = board[row2][j];
            }
            for(int j=0; j<9; j++)
            {
                board[row2][j] = helper[j];
            }
            helper.clear();
        }
        if(rowOrColumn == 1)
        {
            choosingColumns:
            int column1 = rand()%9;
            int column2 = rand()%9;
            if(column1 == column2)
            {
                goto choosingColumns;
            }
            //filling the helper vector
            for(int i=0; i<9; i++)
            {
                helper.push_back(board[i][column1]);
            }
            for(int i=0; i<9; i++)
            {
                board[i][column1] = board[i][column2];
            }
            for(int i=0; i<9; i++)
            {
                board[i][column2] = helper[i];
            }
            helper.clear();
        }
        if(isValid(board) == true)
        {
            foundOne = true;
        }
        numberOfSwitches++;
    }
}
void fillTheBoard(vector<vector<int>>defaultBoard, vector<vector<string>>&board)
{
   for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            board[i][j] = "000000000";
            int k = defaultBoard[i][j];
            board[i][j][k-1] = '1'; 
        }
    } 
}
void removeTheSpot(vector<int>&spotNumbers, int spot)
{
    auto sth = find(spotNumbers.begin(), spotNumbers.end(), spot);
    if (sth != spotNumbers.end()) spotNumbers.erase(sth);
}

bool isSolvable(vector<vector<string>>board)
{
    bool isSolvable = false;
    int numberOfTrys = 0;
    while(numberOfTrys < 6)
    {
        //STEP1 :

        //first we check what number the empty spots can be
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(zeroCounter(board[i][j]) != 8)
                {
                    whatNumbersCanBe(board, i, j);
                }
            }
        }

        //now we fill the spot that we know their numbers
        //fillTheBoard0(board) : note that some spot can be automaticlly filled because of how my solving way works
        fillTheBoardZone(board);

        //set's the board to try to solve it again
        emptyTheBoard(board);

        //STEP2 : 

        //we first go for the rows
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(zeroCounter(board[i][j]) != 8)
                {
                    whatNumbersCanBe(board, i, j);
                }
            }
            fillTheRow(board, i);
            emptyTheRow(board, i);
        }
        //now we go for columns
        for(int j=0; j<9; j++)
        {
            for(int i=0; i<9; i++)
            {
                if(zeroCounter(board[i][j]) != 8)
                {
                    whatNumbersCanBe(board, i, j);
                }
            }
            fillTheColumn(board, j);
            emptyTheColumn(board, j);
        }
        //checks if the sudoku is solved or not
        if(isSolved(board) == true)
        {
            isSolvable = true;
            break;
        }
        numberOfTrys++;
    }
    return isSolvable;
}

void makeTheBoardReady(vector<vector<int>>&fullBoard, int emptySpotsNumber, vector<vector<int>>&board)
{
    //making everything ready to start emptying our board
    srand(time(0));
    int emptySpotCounter = 0;
    bool ranOutOfSpots = false;
    vector<vector<string>> previousBoard(9);
    vector<vector<string>> currentBoard(9);
    for(int i=0; i<9; i++)
    {
        previousBoard[i] = vector<string>(9);
        currentBoard[i] = vector<string>(9);
    }
        vector<vector<int>>defaultBoard
        {
            {9, 8, 4, 7, 3, 5, 1, 6, 2},
            {6, 1, 5, 2, 8, 9, 7, 4, 3},
            {2, 3, 7, 1, 6, 4, 9, 8, 5},
            {4, 2, 8, 5, 1, 3, 6, 7, 9},
            {5, 6, 3, 9, 4, 7, 2, 1, 8},
            {7, 9, 1, 8, 2, 6, 3, 5, 4},
            {3, 7, 2, 4, 5, 1, 8, 9, 6},
            {1, 4, 6, 3, 9, 8, 5, 2, 7},
            {8, 5, 9, 6, 7, 2, 4, 3, 1}
        };
        generateTheFilledBoard(defaultBoard);
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9 ; j++)
            {
                fullBoard[i][j] = defaultBoard[i][j];
            }
        }
        fillTheBoard(defaultBoard, previousBoard);
        fillTheBoard(defaultBoard, currentBoard);
        vector<int>spotNumbers(81);
        for(int i=0; i<81; i++)
        {
            spotNumbers[i] = i;
        }

        //now everything is ready to do the main job
        while(emptySpotCounter != emptySpotsNumber && ranOutOfSpots == false)
        {
            int randomNumber = rand() % spotNumbers.size();
            int spotNumber = spotNumbers[randomNumber];
            removeTheSpot(spotNumbers, spotNumber);
            int i = spotNumber / 9;
            int j = spotNumber % 9;
            currentBoard[i][j] = "111111111";
            if(isSolvable(currentBoard) == true)
            {
                previousBoard[i][j] = "111111111";
                emptySpotCounter++;
            }
            else
            {
                currentBoard[i][j] = previousBoard[i][j];
            }
            if(spotNumbers.size() == 0)
            {
                ranOutOfSpots = true;
            }
        }
    
    //making the final board
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(currentBoard[i][j] == "111111111")
            {
                board[i][j] = 0;
            }
            else
            {
                for(int k=0; k<9; k++)
                {
                    if(currentBoard[i][j][k] == '1')
                    {
                        board[i][j] = k+1;
                    }
                }
            }
        }
    }
}