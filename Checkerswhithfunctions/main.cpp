#include <iostream>
#include <cmath>
#include"board.h"
#include"logic_of_game.h"
using namespace std;
int main()
{
    bool isWhite = true;
    const int sizeCell = 3;
    generateBoard(topSymbol, bottomSymbol);
    printBoard(sizeCell);
    while (true)
    {
        isChange = makeStep(isWhite, sizeCell);
        if (isChange)
        {
            isWhite = !isWhite;
        }
        else
        {
            isWhite = isWhite;
        }
    }

}
    /*
    
    int countTopknockedout = 0, countBaseknockedout = 0;
    bool knocktop = false;
    bool knockbase = false;
    int copyWho = 0;
    bool permissionforChoosingFigTop = false;
    bool permissionforChoosingFigBase = false;

    while (true)
    {

        while (true)
        {

            char var = (who % 2 == 0 ? '=' : 'O');
            while (true)
            {
                if (who != copyWho || who == 0)
                {
                    cout << "Enter place of figure namely '" << var << "' by means of letter(a-q): ";
                    cin >> choicebyLetter;
                    cout << "Enter place of figure namely '" << var << "' by means of number(1-8): ";
                    cin >> choicebyNumber;
                    for (int i = 0; i < 8; i++)
                    {
                        if (choicebyLetter == letters[i])
                        {
                            convertorLetters = i;
                            break;
                        }
                    }
                    choicebyNumber = -(choicebyNumber - 8);
                    if (who % 2 == 0 && permissionforChoosingFigTop == true)
                    {
                        if ((choicebyNumber == choicebyNumberNecessaryTop1 && convertorLetters == convertorLettersNecessaryTop1)
                            || (choicebyNumber == choicebyNumberNecessaryTop2 && convertorLetters == convertorLettersNecessaryTop2))
                        {
                            permissionforChoosingFigTop = false;
                            break;
                        }
                        else
                        {
                            cout << "You can't choose this place.Please enter again!\n";
                            continue;
                        }
                    }

                    if (who % 2 != 0 && permissionforChoosingFigBase == true)
                    {
                        if ((choicebyNumber == choicebyNumberNecessaryBase1 && convertorLetters == convertorLettersNecessaryBase1)
                            || (choicebyNumber == choicebyNumberNecessaryBase2 && convertorLetters == convertorLettersNecessaryBase2))
                        {
                            permissionforChoosingFigBase = false;
                            break;
                        }
                        else
                        {
                            cout << "You can't choose this place.Please enter again!\n";
                            continue;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (who % 2 == 0)
            {

                if (matrix[choicebyNumber][convertorLetters] == '=' && ((matrix[choicebyNumber + 1][convertorLetters - 1] == 'O' && matrix[choicebyNumber + 2][convertorLetters - 2] == '*') ||
                    (matrix[choicebyNumber + 1][convertorLetters + 1] == 'O' && matrix[choicebyNumber + 2][convertorLetters + 2] == '*')))
                {
                    if (matrix[choicebyNumber + 1][convertorLetters - 1] == 'O' && matrix[choicebyNumber + 2][convertorLetters - 2] == '*')
                    {
                        matrix[choicebyNumber + 2][convertorLetters - 2] = '?';
                    }

                    if (matrix[choicebyNumber + 1][convertorLetters + 1] == 'O' && matrix[choicebyNumber + 2][convertorLetters + 2] == '*')
                    {
                        matrix[choicebyNumber + 2][convertorLetters + 2] = '?';
                    }
                    knocktop = true;
                    break;
                }
                else if (matrix[choicebyNumber][convertorLetters] == '=' &&
                    (matrix[choicebyNumber + 1][convertorLetters - 1] != '=' || matrix[choicebyNumber + 1][convertorLetters + 1] != '='))
                {
                    if (matrix[choicebyNumber + 1][convertorLetters - 1] == '*')
                    {
                        matrix[choicebyNumber + 1][convertorLetters - 1] = '?';

                    }
                    if (matrix[choicebyNumber + 1][convertorLetters + 1] == '*')
                    {
                        matrix[choicebyNumber + 1][convertorLetters + 1] = '?';
                    }
                    break;
                }

                else
                {
                    cout << "You can't choose this place.Please enter again!\n";
                    continue;

                }
            }
            else
            {
                if (matrix[choicebyNumber][convertorLetters] == 'O' && ((matrix[choicebyNumber - 1][convertorLetters + 1] == '='
                    && matrix[choicebyNumber - 2][convertorLetters + 2] == '*') || (matrix[choicebyNumber - 1][convertorLetters - 1] == '=' && matrix[choicebyNumber - 2][convertorLetters - 2] == '*')))
                {
                    if (matrix[choicebyNumber - 1][convertorLetters + 1] == '=' && matrix[choicebyNumber - 2][convertorLetters + 2] == '*')
                    {
                        matrix[choicebyNumber - 2][convertorLetters + 2] = '?';
                    }

                    if (matrix[choicebyNumber - 1][convertorLetters - 1] == '=' && matrix[choicebyNumber - 2][convertorLetters - 2] == '*')
                    {
                        matrix[choicebyNumber - 2][convertorLetters - 2] = '?';
                    }
                    knockbase = true;
                    break;
                }
                else if (matrix[choicebyNumber][convertorLetters] == 'O'
                    && (matrix[choicebyNumber - 1][convertorLetters - 1] != 'O' || matrix[choicebyNumber - 1][convertorLetters + 1] != 'O'))
                {
                    //------------------------------------------------matrix-----------------------------------------------------------
                    if (matrix[choicebyNumber - 1][convertorLetters - 1] == '*')
                    {
                        matrix[choicebyNumber - 1][convertorLetters - 1] = '?';

                    }
                    if (matrix[choicebyNumber - 1][convertorLetters + 1] == '*')
                    {
                        matrix[choicebyNumber - 1][convertorLetters + 1] = '?';

                    }


                    //------------------------------------------------matrix-----------------------------------------------------------
                    break;
                }
                else
                {
                    cout << "You can't choose this place.Please enter again!\n";
                    continue;
                }
            }

        }
        copyWho = who;
        cout << convertorLetters << "          choicebyLetter\n";
        cout << choicebyNumber << "          choicebyNumber\n";
        cout << matrix[choicebyNumber][convertorLetters] << "           matrix\n";
        cout << who << "             :who\n";
        cout << copyWho << "    copyWho" << "\n";

     
        //-------------------------------------------output desk end-------------------------------------------------------
        cout << "knocktop: " << knocktop << '\n';
        cout << "knockbase: " << knockbase << '\n';

        while (true)
        {
            cout << "Enter place where you want to move by means of letter(a-q): ";
            cin >> choicebyLetterMoveto;
            cout << "Enter place where you want to move by means of number(1-8): ";
            cin >> choicebyNumberMoveto;
            choicebyNumberMoveto = -(choicebyNumberMoveto - 8);
            for (int i = 0; i < 8; i++)
            {
                if (choicebyLetterMoveto == letters[i])
                {
                    convertorLettersMoveto = i;
                    break;

                }
            }

            if (who % 2 == 0)
            {
                if (matrix[choicebyNumberMoveto][convertorLettersMoveto] == '?')
                {
                    //------------------------------------------------matrix---------------------------------------------------------------

                    /*
                    if (matrix[choicebyNumberMoveto - 1][convertorLettersMoveto + 1] == 'O')
                    {
                        matrix[choicebyNumberMoveto - 1][convertorLettersMoveto + 1] = '*';
                        countBaseknockedout++;
                    }
                    if (matrix[choicebyNumberMoveto - 1][convertorLettersMoveto - 1] == 'O')
                    {
                        matrix[choicebyNumberMoveto - 1][convertorLettersMoveto - 1] = '*';
                        countBaseknockedout++;
                    }
                    
                    matrix[choicebyNumber][convertorLetters] = '*';
                    matrix[choicebyNumberMoveto][convertorLettersMoveto] = '=';
                    int convertorLettersKnockedTop = (convertorLettersMoveto - convertorLetters == 2 ? (convertorLetters + 1) : convertorLetters - 1);
                    if (knocktop == true)
                    {
                        matrix[choicebyNumber + 1][convertorLettersKnockedTop] = '*';
                        choicebyNumber = choicebyNumberMoveto;
                        convertorLetters = convertorLettersMoveto;
                        if ((matrix[choicebyNumber + 1][convertorLetters - 1] == 'O' && matrix[choicebyNumber + 2][convertorLetters - 2] == '*') ||
                            (matrix[choicebyNumber + 1][convertorLetters + 1] == 'O' && matrix[choicebyNumber + 2][convertorLetters + 2] == '*'))
                        {
                            who--;
                        }
                    }
                    knocktop = false; //expects for changing
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
                    //------------------------------------------------matrix---------------------------------------------------------------
                    break;
                }
                else
                {
                    cout << "You can't choose this place.Please enter again!\n";
                    continue;
                }
            }
            else
            {
                if (matrix[choicebyNumberMoveto][convertorLettersMoveto] == '?')
                {
                    //------------------------------------------------matrix---------------------------------------------------------------
                    /*
                    if (matrix[choicebyNumberMoveto + 1][convertorLettersMoveto + 1] == '=')
                    {
                        matrix[choicebyNumberMoveto + 1][convertorLettersMoveto + 1] = '*';
                        countTopknockedout++;
                    }
                    if (matrix[choicebyNumberMoveto + 1][convertorLettersMoveto - 1] == '=')
                    {
                        matrix[choicebyNumberMoveto + 1][convertorLettersMoveto - 1] = '*';
                        countTopknockedout++;

                    }
                    
                    matrix[choicebyNumber][convertorLetters] = '*';
                    matrix[choicebyNumberMoveto][convertorLettersMoveto] = 'O';
                    int convertorLettersKnockedBase = (convertorLettersMoveto - convertorLetters == 2 ? (convertorLetters + 1) : convertorLetters - 1);
                    if (knockbase == true)
                    {
                        matrix[choicebyNumber - 1][convertorLettersKnockedBase] = '*';
                        choicebyNumber = choicebyNumberMoveto;
                        convertorLetters = convertorLettersMoveto;
                        if ((matrix[choicebyNumber - 1][convertorLetters + 1] == '=' && matrix[choicebyNumber - 2][convertorLetters + 2] == '*') ||
                            (matrix[choicebyNumber - 1][convertorLetters - 1] == '=' && matrix[choicebyNumber - 2][convertorLetters - 2] == '*'))
                        {
                            who--;
                        }
                    }
                    knockbase = false; //expects for changing
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

                    //------------------------------------------------matrix---------------------------------------------------------------
                    break;
                }
                else
                {
                    cout << "You can't choose this place.Please enter again!\n";
                    continue;
                }

            }
        }
        if (who == copyWho && who % 2 == 0)
        {
            if (matrix[choicebyNumberMoveto + 1][convertorLettersMoveto - 1] == 'O' && matrix[choicebyNumberMoveto - 1][convertorLettersMoveto + 1] == '*')
            {
                permissionforChoosingFigBase = true;
                choicebyNumberNecessaryBase1 = choicebyNumberMoveto + 1;
                convertorLettersNecessaryBase1 = convertorLettersMoveto - 1;
            }
            if (matrix[choicebyNumberMoveto + 1][convertorLettersMoveto + 1] == 'O' && matrix[choicebyNumberMoveto - 1][convertorLettersMoveto - 1] == '*')
            {
                permissionforChoosingFigBase = true;
                choicebyNumberNecessaryBase2 = choicebyNumberMoveto + 1;
                convertorLettersNecessaryBase2 = convertorLettersMoveto + 1;
            }

        }
        else if (who == copyWho && who % 2 != 0)
        {
            if (matrix[choicebyNumberMoveto - 1][convertorLettersMoveto - 1] == '=' && matrix[choicebyNumberMoveto + 1][convertorLettersMoveto + 1] == '*')
            {
                permissionforChoosingFigTop = true;
                choicebyNumberNecessaryTop1 = choicebyNumberMoveto - 1;
                convertorLettersNecessaryTop1 = convertorLettersMoveto - 1;
            }
            if (matrix[choicebyNumberMoveto - 1][convertorLettersMoveto + 1] == '=' && matrix[choicebyNumberMoveto + 1][convertorLettersMoveto - 1] == '*')
            {
                permissionforChoosingFigTop = true;
                choicebyNumberNecessaryTop2 = choicebyNumberMoveto - 1;
                convertorLettersNecessaryTop2 = convertorLettersMoveto + 1;
            }
        }
        cout << choicebyNumberNecessaryBase1 << ": choicebyNumberNecessaryBase1\n";
        cout << convertorLettersNecessaryBase1 << ": convertorLettersNecessaryBase1\n";
        cout << choicebyNumberNecessaryBase2 << ": choicebyNumberNecessaryBase2\n";
        cout << convertorLettersNecessaryBase2 << ": convertorLettersNecessaryBase2\n";
        cout << "---------------------------------------------------------\n";
        cout << choicebyNumberNecessaryTop1 << ": choicebyNumberNecessaryTop1\n";
        cout << convertorLettersNecessaryTop1 << ": conconvertorLettersNecessaryTop1\n";
        cout << choicebyNumberNecessaryTop2 << ": choicebyNumberNecessaryTop2\n";
        cout << convertorLettersNecessaryTop2 << ": convertorLettersNecessaryTop2\n";

       
        who++;
    }
}








*/