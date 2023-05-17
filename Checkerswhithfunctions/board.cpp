#include "board.h"
#include"logic_of_game.h"
#include<iostream>
using namespace std;
//------------------------------------------------------------------Declaration------------------------------------------------------------------
char letters[8] = { 'a', 'b' , 'c', 'd', 'e', 'f', 'g', 'h' };
char matrix[rows][columns] = {};
void printLetters(int sizeCell, char letters[]);
void printLine(int sizeCell);
void printLineLetters(int sizeCell, char letters[], bool isBottom);
void matrixArray(char topSymbol, char bottomSymbol, int isPart); // 0 - top; 1 - middle; 2 -bottom
//------------------------------------------------------------------Declaration------------------------------------------------------------------
void generateBoard(char topSymbol, char bottomSymbol)
{
    matrixArray(topSymbol, bottomSymbol, 0);
    matrixArray(topSymbol, bottomSymbol, 1);
    matrixArray(topSymbol, bottomSymbol, 2);
}
void matrixArray(char topSymbol, char bottomSymbol, int isPart)
{
    char matrixVar;
    int rowValue, endArray;
    switch (isPart)
    {
    case 0: rowValue = 0; matrixVar = topSymbol; endArray = 3;
        break;
    case 1: rowValue = 3; matrixVar = '*'; endArray = 5;
        break;
    case 2: rowValue = rows - 3; matrixVar = bottomSymbol; endArray = 8;
        break;
    }

    for (rowValue; rowValue < endArray; rowValue++)
    {
        for (int column = 0; column < columns; column++)
        {
            ((rowValue + column) % 2 == 0)
                ? matrix[rowValue][column] = ' '
                : matrix[rowValue][column] = matrixVar;
        }
    }
}
void printBoard(int sizeCell)   
{
    int desksNumbers[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };
    printLineLetters(sizeCell, letters, false);
    for (int row = 0; row < rows; row++)
    {
        for (int rowCell = 0; rowCell < sizeCell; rowCell++)
        {
            cout << "|";
            if (rowCell % 3 == 1)
            {
                cout << desksNumbers[row] << " ";
            }
            else
            {
                cout << "  ";
            }
            for (int column = 0; column < columns; column++)

            {
                for (int columnCell = 0; columnCell < sizeCell; columnCell++)
                {
                    if ((row + column) % 2 == 0)
                    {
                        cout << "  ";
                    }
                    else
                    {
                        if (rowCell == sizeCell / 2 && columnCell == sizeCell / 2 && matrix[row][column] != ' ')
                        {
                            cout << matrix[row][column] << " ";
                        }
                        else
                        {
                            cout << "* ";
                        }
                    }
                }
            }
            if (rowCell % 3 == 1)
            {
                cout << desksNumbers[row] << " ";

            }
            else
            {
                cout << "  ";
            }
            cout << "|\n";
        }
    }
    printLineLetters(sizeCell, letters, true);
}
void printLineLetters(int sizeCell, char letters[], bool isBottom)
{
    if (!isBottom)
    {
        printLine(sizeCell);
        printLetters(sizeCell,letters);
    }
    else
    {
        printLetters(sizeCell, letters);
        printLine(sizeCell);
    }
}
void printLine(int sizeCell)
{
    for (int i = 0; i < columns * sizeCell * 2 + 6; i++)
    {
        cout << "-";
    }
    cout << "\n";
}
void printLetters(int sizeCell, char letters[])
{
    cout << "|  ";
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < sizeCell / 2; j++)
        {
            cout << "  ";
        }
        cout << letters[i] << " ";
        for (int j = 0; j < sizeCell / 2; j++)
        {
            cout << "  ";
        }
    }
    cout << "  |\n";
}