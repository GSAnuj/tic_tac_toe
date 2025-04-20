#include <iostream>
using namespace std;

bool gameover(char bo[][3])
{
    // Check Rows and Columns
    for (int i = 0; i < 3; i++)
    {
        // Row check
        if (bo[i][0] == bo[i][1] && bo[i][1] == bo[i][2])
        {
            cout << "Player " << (bo[i][0] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
            return true;
        }

        // Column check
        if (bo[0][i] == bo[1][i] && bo[1][i] == bo[2][i])
        {
            cout << "Player " << (bo[0][i] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
            return true;
        }
    }

    // Diagonal checks
    if (bo[0][0] == bo[1][1] && bo[1][1] == bo[2][2])
    {
        cout << "Player " << (bo[0][0] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
        return true;
    }

    if (bo[0][2] == bo[1][1] && bo[1][1] == bo[2][0])
    {
        cout << "Player " << (bo[0][2] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
        return true;
    }


    bool boardFull = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (bo[i][j] != 'X' && bo[i][j] != 'O')
            {
                boardFull = false;
                break;
            }
        }
    }

    if (boardFull)
    {
        cout << "It's a draw!\n";
        return true;
    }

    return false; 
}

void Displayboard(char bo[][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << bo[i][j] << " ";
        }
        cout << endl;
    }
}
void game(char bo[][3], int &count)
{
    int play = 0;
    bool validMove = false;
    cout << "Enter the number on the board to place your marker: ";
    cin >> play;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (bo[i][j] == (play + '0'))
            {
                bo[i][j] = (count % 2 == 0) ? 'O' : 'X';
                validMove = true;
                count++;
                break;
            }
        }
        if (validMove)
            break;
    }

    if (!validMove)
        cout << "Input a valid number that is on the board :)\n";

    Displayboard(bo);
}

int main()
{
    bool gameov = false;
    int count = 1;
    char bo[3][3] = {
        {'1','2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    Displayboard(bo);
    while (!gameov)
    {
        game(bo, count);
        gameov = gameover(bo);
    }
    return 0;
}
