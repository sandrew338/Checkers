#include<iostream>
#include "logic_of_game.h"
#include "board.h"
using namespace std;
//------------------------------------------------------------------Declaration------------------------------------------------------------------
int rowStep(char var, bool moveTo = false);
int columnStep(char var, bool moveTo = false);
bool moveTo = false, canBeat;
bool isChange = true;
char topSymbol = '-', bottomSymbol = 'o', topSymbolHigh = '=', bottomSymbolHigh = 'O';
int choicebyLetter, choicebyNumber;
int choicebyNumberMovetoCopy;
int choicebyLetterMoveto—opy;
int SuggestGoSign(bool isWhite);
void cleaningSug();
bool beyondNumber(int num1, int num2);
bool suggestGo(int choicebyNumber, int choicebyLetter, char var, char varEnemy, bool isWhite);
bool Moveto(int choicebyNumberMoveto, int choicebyLetterMoveto, int choicebyNumber, int choicebyLetter, char var, char varEnemy, bool isWhite);
//------------------------------------------------------------------Declaration------------------------------------------------------------------
bool makeStep(bool isWhite, int sizeCell)
{
    char var = isWhite == true ? bottomSymbol : topSymbol;
    char varEnemy = isWhite == true ? topSymbol : bottomSymbol;
    int choicebyNumberMoveto, choicebyLetterMoveto;
    if (isChange)
    {
        //suggestions
        while (true)
        {

            choicebyLetter = rowStep(var);
            choicebyNumber = columnStep(var);
            if (!beyondNumber(choicebyLetter, choicebyNumber) && (suggestGo(choicebyNumber, choicebyLetter, var, varEnemy, isWhite)))
            {
                printBoard(sizeCell);
                break;
            }
        }
    }
    else
    {
        choicebyNumber = choicebyNumberMovetoCopy;
        choicebyLetter = choicebyLetterMoveto—opy;
        suggestGo(choicebyNumber, choicebyLetter, var, varEnemy, isWhite);
        printBoard(sizeCell);
    }
    isChange = true;
   
    do{
        choicebyLetterMoveto = rowStep(var, true);
        choicebyNumberMoveto = columnStep(var, true);
    } while (matrix[choicebyNumberMoveto][choicebyLetterMoveto] != '?');
    choicebyNumberMovetoCopy = choicebyNumberMoveto;
    choicebyLetterMoveto—opy = choicebyLetterMoveto;
    Moveto(choicebyNumberMoveto, choicebyLetterMoveto, choicebyNumber, choicebyLetter, var, varEnemy, isWhite);
    printBoard(sizeCell);
    return(Moveto(choicebyNumberMoveto, choicebyLetterMoveto, choicebyNumber, choicebyLetter, var, varEnemy, isWhite));
} 
bool suggestGo(int choicebyNumber,int choicebyLetter,char var, char varEnemy,bool isWhite)
{
    bool isElseFigures = false;
    int sign = SuggestGoSign(isWhite);
    bool done = true;
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if ((matrix[i][j] == var && matrix[i - 1 * sign][j - 1 * sign] == varEnemy && matrix[i - 2 * sign][j - 2 * sign] == '*')
                ||(matrix[i][j] == var && matrix[i - 1 * sign][j + 1 * sign] == varEnemy && matrix[i - 2 * sign][j + 2 * sign] == '*'))
            {
                if (choicebyNumber == i && choicebyLetter == j)
                {
                    done = true;
                    cout << "i: " << i << "j: " << j << "\n";
                    break;
                }
                else
                {
                    done = false;
                }
            }
        }
    }
    if (done)
    {
        if (matrix[choicebyNumber][choicebyLetter] == var && ((matrix[choicebyNumber - 1 * sign][choicebyLetter + 1 * sign] == varEnemy
            && matrix[choicebyNumber - 2 * sign][choicebyLetter + 2 * sign] == '*') || (matrix[choicebyNumber - 1 * sign][choicebyLetter - 1 * sign] == varEnemy && matrix[choicebyNumber - 2 * sign][choicebyLetter - 2 * sign] == '*')))
        {
            if (matrix[choicebyNumber - 1 * sign][choicebyLetter + 1 * sign] == varEnemy && matrix[choicebyNumber - 2 * sign][choicebyLetter + 2 * sign] == '*')
            {
                matrix[choicebyNumber - 2 * sign][choicebyLetter + 2 * sign] = '?';
            }

            if (matrix[choicebyNumber - 1 * sign][choicebyLetter - 1 * sign] == varEnemy && matrix[choicebyNumber - 2 * sign][choicebyLetter - 2 * sign] == '*')
            {
                matrix[choicebyNumber - 2 * sign][choicebyLetter - 2 * sign] = '?';
            }
        }
        else if (matrix[choicebyNumber][choicebyLetter] == var
            && (matrix[choicebyNumber - 1 * sign][choicebyLetter - 1 * sign] != var || matrix[choicebyNumber - 1 * sign][choicebyLetter + 1 * sign] != var))
        {
            if (matrix[choicebyNumber - 1 * sign][choicebyLetter - 1 * sign] == '*')
            {
                matrix[choicebyNumber - 1 * sign][choicebyLetter - 1 * sign] = '?';

            }
            if (matrix[choicebyNumber - 1 * sign][choicebyLetter + 1 * sign] == '*')
            {
                matrix[choicebyNumber - 1 * sign][choicebyLetter + 1 * sign] = '?';

            }
        }
        else
        {
            done = false;
        }
    }
    return done;
}
bool Moveto(int choicebyNumberMoveto, int choicebyLetterMoveto, int choicebyNumber, int choicebyLetter, char var, char varEnemy, bool isWhite)
{
    bool knock = false;
    int sign = SuggestGoSign(isWhite);
    if (matrix[choicebyNumberMoveto][choicebyLetterMoveto] == '?')
    {
        //------------------------------------------------matrix---------------------------------------------------------------

        if (matrix[choicebyNumberMoveto + 1 * sign][choicebyLetterMoveto + 1 * sign] == varEnemy)
        {
            matrix[choicebyNumberMoveto + 1 * sign][choicebyLetterMoveto + 1 * sign] = '*';
            knock = true;
            //countTopknockedout++;
        }
        if (matrix[choicebyNumberMoveto + 1 * sign][choicebyLetterMoveto - 1 * sign] == varEnemy)
        {
            matrix[choicebyNumberMoveto + 1 * sign][choicebyLetterMoveto - 1 * sign] = '*';
            knock = true;
            //countTopknockedout++;
        }

        matrix[choicebyNumber][choicebyLetter] = '*';
        matrix[choicebyNumberMoveto][choicebyLetterMoveto] = var;
        cleaningSug();

        if (knock == true && ((matrix[choicebyNumberMoveto - 1 * sign][choicebyLetterMoveto + 1 * sign] == varEnemy && matrix[choicebyNumberMoveto - 2 * sign][choicebyLetterMoveto + 2 * sign] == '*') ||
            (matrix[choicebyNumberMoveto - 1 * sign][choicebyLetterMoveto - 1 * sign] == varEnemy && matrix[choicebyNumberMoveto - 2 * sign][choicebyLetterMoveto - 2 * sign] == '*')))
        {
            isChange = false;
        }
    }
    return isChange;
}
int rowStep(char var, bool moveTo)
{
    char convertorLetters;
    moveTo == false ? cout << "Enter place of figure namely '" << var << "' by means of letter(a-h): " :
    cout << "Enter place where you want to move (from'" << var << "') by means of letter(a-h): ";
    cin >> convertorLetters;
    return (int)convertorLetters - 97;
}
int columnStep(char var, bool moveTo)
{
    int convertorNumbers;
    moveTo == false ? cout << "Enter place of figure namely '" << var << "' by means of number(1-8): " :
        cout << "Enter place where you want to move (from'" << var << "') by means of number(1-8): ";
    cin >> convertorNumbers;
    return columns - convertorNumbers;
}
int SuggestGoSign(bool isWhite)
{
    int sign;
    sign = isWhite == true ? 1 : -1;
    return sign;
}
void cleaningSug()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (matrix[row][column] == '?')
            {
                matrix[row][column] = '*';
            }
        }
    }
}
bool beyondNumber(int num1, int num2)
{
    bool isBeyondNumber = false;
    if ((num1 > 8 && num1 < 0) || (num2 > 8 && num2 < 0))
    {
        isBeyondNumber = true;
    }
    return isBeyondNumber;
}