#include <iostream>
#include <ctime>

void PrintIntroduction(int Dificulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Dificulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Dificulty)
{
    PrintIntroduction(Dificulty);

    const int CodeA = Dificulty + rand() % Dificulty;
    const int CodeB = Dificulty + rand() % Dificulty;
    const int CodeC = Dificulty + rand() % Dificulty;
    std::cout << CodeA << CodeB << CodeC;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add-up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

    if (GuessSum == CodeSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n*** Well done agent! You have extract a file! keep going! ***" << std::endl;
        return true;
    }
    else
    {
        std::cout << "\n*** You Entred a wrong code! Carefully agent! Try again! *** " << std::endl;
        return false;
    }
}

int main()
{
    srand(time(NULL));

    int LevelDificulty = 1;
    int const MaxDificulty = 5;
    while (LevelDificulty <= MaxDificulty)
    {
        bool bLevelComplete = PlayGame(LevelDificulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            LevelDificulty++;
        }
    }

    std::cout << "\n*** Great work agent! You got all files! Now get out of there! ***\n";
    return 0;
}
