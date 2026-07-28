
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

void ShraniNaDat(int stSekund, int stPoskusov);

int main()
{
    std::cout << "\nWelcome to the Number Guessing Game!";
    while (true) {
        time_t curTime;
        time(&curTime);

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
                time_t newTime;
                time(&newTime);
                std::cout << "\nPorabil si " << newTime - curTime<< "sekund";
                ShraniNaDat(newTime - curTime, i + 1);

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
void ShraniNaDat(int stSekund, int stPoskusov){
        std::string readLine;
        std::ifstream MyRFile("NumberGuesingGameHighcore.txt");
    if (MyRFile.good()) {
        int stPosk2 = -1;
        int stSek2 = -1;
        getline(MyRFile, readLine);
        int indxVejice = readLine.find(',');
        stSek2 = stoi(readLine.substr(0, indxVejice));
        stPosk2 = stoi(readLine.substr(indxVejice + 1, readLine.length()));
        //MyRFile.close;
        if (stPoskusov < stPosk2 && stSekund < stSek2) {

            std::ofstream MyRFile("NumberGuesingGameHighcore.txt");;
            MyRFile << stSekund << ',' << stPoskusov;
        }
        MyRFile.close();
    }
    else {
        std::ofstream MyRFile("NumberGuesingGameHighcore.txt");;
        MyRFile << stSekund << ',' << stPoskusov;
        MyRFile.close();
    }    
}
