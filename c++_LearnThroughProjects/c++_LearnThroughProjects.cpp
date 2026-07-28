
#include <iostream>
#include <ctime>

int main()
{
    std::cout << "\nWelcome to the Number Guessing Game!";
    while (true) {
        srand(time(0));
        int randomNumber = rand()%100+1;

        std::cout << "\nI'm thinking of a number between 1 and 100.";

        std::cout << "Please select your difficulty level:";
        std::cout << "\n0. Quit\n1. Easy (10 chances)\n2. Medium(5 chances)\n3. Hard(3 chances)";
        std::cout << "\nEnter choice: ";
        int difChoice;
        try {
            std::cin >> difChoice;
        }
        catch(int errCode){
            std::cout << "\nInvalid Input";
            continue;
        }
        if (difChoice == 0) {
            std::cout << "\nThanks for playing!";
            break;
        }

        switch (difChoice) {
            case 1:
                std::cout << "\nGreat! You have selected the Easy difficulty level.";
                break;
            case 2:
                std::cout << "\nGreat! You have selected the Medium difficulty level.";
                break;
            case 3:
                std::cout << "\nGreat! You have selected the Hard difficulty level.";
                break;
            default:
                std::cout << "\nYou have selected an invalid difficulty level.";
                continue;
        }
        int numberOfChoices = 10/difChoice;
        std::cout << "\nLet's start the game! You have " << numberOfChoices << " attempts";

        for (int i = 0; i < numberOfChoices; i++) {
            std::cout << "\nEnter your guess: ";
            int guess;
            try {
                std::cin >> guess;
            }
            catch (int errCode) {
                std::cout << "\nInvalid Input";
                continue;
            }

            if (guess == randomNumber) {
                std::cout << "\nCongratulations! You guessed the correct number in" << (i+1) << "attempts.";
                break;
            }

            if ((i + 1) >= numberOfChoices) {
                std::cout << "\nYou ran out of attempts, the number was: " << randomNumber;
                break;
            }

            if (guess > randomNumber) {
                std::cout << "\nIncorrect! The number is less than " << guess;
            }
            else {
                std::cout << "\nIncorrect! The number is greater than " << guess;
            }

        }
    }
}
