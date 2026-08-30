#include "gameOfLife.h"

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[10][10], int boardSize)
{
    for (int i = 0; i < boardSize*boardSize; i++)
    {
        Cell* deargod = (Cell*)malloc(sizeof(Cell));
        deargod -> x = i%10;
        deargod -> y = i/10;
        deargod -> state = 0;
        board[i/10][i%10] = deargod;
    }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{
    cout << "Enter the name of the file to read: ";
    string filename;
    cin >> filename;
    ifstream f(filename);
    
    string s;
    int Ycount = 0;
    while (std::getline(f, s))
    {
        for(int i = 0; i < boardSize; i++)
        {
        Cell* deargod = (Cell*)malloc(sizeof(Cell));
        deargod -> x = i;
        deargod -> y = Ycount;

        if(s[i] == '0')
        {
            deargod -> state = 0;
        }

        else
        {
            deargod -> state = 1;
        }
        
        board[i][Ycount] = deargod;
        }
        Ycount++;
    }
}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            cout << board[j][i]->state;
        }
        cout << endl;
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{
    int numberofhorses = 0;
    int currentx = curCell -> x;
    int currenty = curCell -> y;
    currentx = currentx-1; 
    if(currentx >= 0)
    if(board[currentx][currenty] -> state == 1)
    numberofhorses++;
    currentx = curCell -> x;
    currentx = currentx+1;
    if(currentx <= 9)
    if(board[currentx][currenty] -> state == 1)
    numberofhorses++;
    currentx = curCell -> x;
    
    currenty = currenty-1; 
    if(currenty >= 0)
    if(board[currentx][currenty] -> state == 1)
    numberofhorses++;
    currenty = curCell -> y;
    currenty = currenty+1;
    if(currenty <= 9)
    if(board[currentx][currenty] -> state == 1)
    numberofhorses++;
    currenty = curCell -> y;

    currentx = currentx-1;
    currenty = currenty-1;
    if(currentx >= 0 && currenty >= 0)
    if(board[currentx][currenty] -> state == 1)
    numberofhorses++;
    currenty = curCell -> y;
    currentx = curCell -> x;

    currentx = currentx+1;
    currenty = currenty-1;
    if(currentx <= 9 && currenty >= 0)
    if(board[currentx][currenty] -> state == 1)
    numberofhorses++;
    currenty = curCell -> y;
    currentx = curCell -> x;

    currentx = currentx-1;
    currenty = currenty+1;
    if(currentx >= 0 && currenty <= 9)
    if(board[currentx][currenty] -> state == 1)
    numberofhorses++;
    currenty = curCell -> y;
    currentx = curCell -> x;

    currentx = currentx+1;
    currenty = currenty+1;
    if(currentx <= 9 && currenty <= 9)
    if(board[currentx][currenty] -> state == 1)
    numberofhorses++;
    currenty = curCell -> y;
    currentx = curCell -> x;

    curCell -> numLiveNeighbors = numberofhorses;
}

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], int boardSize) 
{
    bool return_value = false;

    for (int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            findNumNeighbors(board, boardSize, board[j][i]);
        }
        
    }

    for (int m = 0; m < boardSize; m++)
    {
        for(int k = 0; k < boardSize; k++)
        {
            if(board[k][m]->numLiveNeighbors < 2 && board[k][m]->state == 1)
            {
            board[k][m]->state = 0;
            return_value = true;
            }

            if((board[k][m]->numLiveNeighbors == 2 || board[k][m]->numLiveNeighbors == 3) && board[k][m]->state == 1)
            board[k][m]->state = 1;

            if(board[k][m]->numLiveNeighbors > 3 && board[k][m]->state == 1)
            {
            board[k][m]->state = 0;
            return_value = true;
            }

            if(board[k][m]->numLiveNeighbors == 3 && board[k][m]->state == 0)
            {
            board[k][m]->state = 1;
            return_value = true;
            }
        }
        
    }
    return return_value;
}
