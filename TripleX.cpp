#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print intro messages to the terminal
    std::cout << "Tou are a secret agent breaking into a level " << Difficulty << " secure server room...\n";
    std::cout << "Enter the correct code to continue...\n" << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    int NumA = rand() % Difficulty + Difficulty;
    int NumB = rand() % Difficulty + Difficulty;
    int NumC = rand() % Difficulty + Difficulty;

    int Sum = NumA + NumB + NumC;
    int Product = NumA * NumB * NumC;

    // Print sum and product to terminal
    std::cout << "*   There are 3 numbers in the code\n";
    std::cout << "*   The numbers add-up to: " << Sum << std::endl;
    std::cout << "*   The numbers multiply to give: " << Product << "\n" << std::endl;

    //Take player input
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC << "\n" << std::endl;

    //Check player Guess
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    if (GuessSum == Sum && GuessProduct == Product)
    {
        std::cout << " *** Code accepted, you secured a file! Keep Going! ***\n\n";
        return true;
    }
    else
    {
        std::cout << " *** Wrong code, try again! ***\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loops game until all levels completed
    {
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any errors
        std::cin.ignore(); //discards buffer
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\nGreat Work! You got all of the files!";
    std::cout << "GAME OVER --- YOU WIN!";

    return 0;
}
