#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int RandomNumber(int From, int To)
{
    // Generate a random number between 0 and (To - From) using rand(),
    int random = rand() % (To - From + 1) + From;
    return random;
}
int FnRandomComputerChoice()
{

    return RandomNumber(1, 3);
}
short FnPlayerChoice()
{
    short PlayerChoice = 0;
    do
    {
        cout << "What Is Your Choice: [1]Stone , [2]Paper , [3]Scissor? : ";
        cin >> PlayerChoice;

    } while (!(PlayerChoice > 0 && PlayerChoice <= 3));
    return PlayerChoice;
}
short ReadHowManyRound()
{
    short Round = 0;
    do
    {

        cout << "How Many Round You Want To Play (Enter Positive Number)\n";
        cin >> Round;

    } while (!(Round > 0));
    return Round;
}
string choiceName(short Choice)
{

    string ChoiceName[] = {"", "Stone", "Paper", "Scissor"};
    return ChoiceName[Choice];
}
string WhatIsResult(short PlayerChoice, short RandomComputerChoice)
{

    if (PlayerChoice == RandomComputerChoice)
    {
        return "Draw";
    }

    else if ((PlayerChoice == 1 && RandomComputerChoice == 3) ||
             (PlayerChoice == 2 && RandomComputerChoice == 1) ||
             (PlayerChoice == 3 && RandomComputerChoice == 2))
    {
        return "Player";
    }

    return "Computer";
}
void YellowResult(short PlayerChoice, short RandomComputerChoice)
{
    system("color E0");
    cout << "                  Player Choice   : " << choiceName(PlayerChoice) << endl;
    cout << "                  Computer Choice : " << choiceName(RandomComputerChoice) << endl;
    cout << "                  No Winner\n";
    cout << "                  ______________________________\n\n";
}
void RedResult(short PlayerChoice, short RandomComputerChoice, short &ComputerResult)
{
    system("color 4F");
    Beep(750, 300);
    ComputerResult++;
    cout << "                  Player Choice   : " << choiceName(PlayerChoice) << endl;
    cout << "                  Computer Choice : " << choiceName(RandomComputerChoice) << endl;
    cout << "                  Round Winner : [Computer]\n";
    cout << "                  ______________________________\n\n";
}
void GreenResult(short PlayerChoice, short RandomComputerChoice, short &PlayerResult)
{
    system("color 20");
    PlayerResult++;
    cout << "                  Player Choice   : " << choiceName(PlayerChoice) << endl;
    cout << "                  Computer Choice : " << choiceName(RandomComputerChoice) << endl;
    cout << "                  Round Winner : [Player]\n";
    cout << "                  ______________________________\n\n";
}
void GameResult(short &PlayerChoice, short &PlayerResult, short &ComputerResult, short &RandomComputerChoice)
{

    if (WhatIsResult(PlayerChoice, RandomComputerChoice) == "Draw")
    {
        YellowResult(PlayerChoice, RandomComputerChoice);
    }

    else if (WhatIsResult(PlayerChoice, RandomComputerChoice) == "Player")
    {
        GreenResult(PlayerChoice, RandomComputerChoice, PlayerResult);
    }

    else
    {
        RedResult(PlayerChoice, RandomComputerChoice, ComputerResult);
    }
}
void GameOverTable(short &Round, short &PlayerResult, short &ComputerResult, short &Draw)
{
    cout << "___________________________________________________________________\n\n";
    cout << "                         *** GAME OVER ***                         \n";
    cout << "___________________________________________________________________\n\n";
    cout << "__________________________ { GAME Results } ________________________\n\n";
    cout << "Game Rounds           : " << Round << endl;
    cout << "Player Won Rounds     : " << PlayerResult << endl;
    cout << "Computer Won Rounds   : " << ComputerResult << endl;
    cout << "Draw Times            : " << Draw << endl;
}
void GameOver(short &Round, short &PlayerResult, short &ComputerResult)
{

    short Draw = abs(Round - PlayerResult - ComputerResult);
    GameOverTable(Round, PlayerResult, ComputerResult, Draw);

    if (ComputerResult == PlayerResult)
    {
        cout << "Final Winner :         " << "No Winner" << endl;
        system("color E0");
    }

    else if (ComputerResult > PlayerResult)
    {
        cout << "Final Winner :         " << "Computer" << endl;
        Beep(750, 300);
        system("color 4F");
    }
    else
    {
        cout << "Final Winner :         " << "Player" << endl;
        system("color 20");
    }
}
char GameRestart()
{
    char Restart;
    cout << "Do You Want To Play Again Y/N : ";
    cin >> Restart;
    if (Restart == 'Y' || Restart == 'y')
    {

        system("cls");
        system("color 07");
    }
    return Restart;
}

void About()
{
    cout << "This is a simple game of Rock, Paper, Scissor\n";

    cout << "The rules are simple, you have to choose either Rock, Paper or Scissor\n";
    cout << "Rock beats Scissor, Scissor beats Paper and Paper beats Rock\n";

    cout << "Created by Yazan Brijawe\n";
    cout << "Github: https://github.com/YazanBrijawe\n";
    cout << "Game source code available at: " << endl;
}

void GameStart()

{
    char Restart = 'Y';
    do
    {

        short PlayerResult = 0, ComputerResult = 0;
        short Round = ReadHowManyRound();

        for (int i = 1; i <= Round; i++)
        {
            cout << "                  Round [" << i << "]" << "begin\n\n";
            short PlayerChoice = FnPlayerChoice();
            cout << "\n                  __________ " << "Round [" << i << "]" << " __________                  \n\n";
            short RandomComputerChoice = FnRandomComputerChoice();
            GameResult(PlayerChoice, PlayerResult, ComputerResult, RandomComputerChoice);
        }

        GameOver(Round, PlayerResult, ComputerResult);
        Restart = GameRestart();

    }

    while (Restart == 'Y' || Restart == 'y');
}

int main()
{
    int Menu;
    srand((unsigned)time(NULL));
    cout << "1. Start\n2. About    \n3.Exit" << endl;
    ;

    cin >> Menu;

    if (Menu == 1)
    {
        cout << endl;
        GameStart();
        cout << endl;
    }

    else if (Menu == 2)
    {
        cout << endl;
        About();
        cout << endl;
    }

    else
    {
        cout << "\nBye";
        return 0;
    }
}