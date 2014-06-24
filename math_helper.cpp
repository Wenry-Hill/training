/* This program will help students learn about prime factorization */

/*
 * When this program is started, the user will be shown a randomly selected
 * number between 2 and 100. The student must state rather the number is prime
 * or composite. When the student has answered, the program will determine
 * whether the student was correct. If the number was composite, the program
 * will display the prime factorization of the number.
 *
 * This will repeat until the student chooses to finish, at which point the
 * program will print out how many correct and incorrect answers there were, and
 * then exit.
 */

#include "lib/helpers.h"

#include <iostream>
#include <vector>

int main()
{
    int right = 0;
    int wrong = 0;

    std::string input;
    seedRandomNumber();

    while (true)
    {
        int number = getRandomNumber(2, 100);
        auto factors = getPrimeFactorization(number);

        bool isPrime = (factors.size() == 1);

        std::cout << "Is " << number << " prime?\n";
        std::cout << "[Y/N] > ";
        do {
            input = getLetter();
        } while (input != "Y" && input != "N");

        if (isPrime && input == "N" || ! isPrime && input == "Y")
        {
            std::cout << "Incorrect\n\n";
            wrong++;
        }
        else
        {
            std::cout << "Correct!\n\n";
            right++;
        }
        if ( ! isPrime)
        {
            std::cout << "The factors of " << number << " are:\n";
            bool firstRun = true;
            for (int i : factors)
            {
                if ( ! firstRun)
                {
                    std::cout <<  " * ";
                }
                std::cout << i;
                firstRun = false;
            }
            std::cout << "\n\n";
        }

        std::cout << "Would you like to try another?\n";
        std::cout << "[Y/N] > ";
        do {
            input = getLetter();
        } while (input != "Y" && input != "N");

        if (input == "N")
        {
            break;
        }
    }

    std::cout << "\n\n";

    std::cout << "Correct: " << right << "\n";
    std::cout << "Incorrect: " << wrong << "\n";
    if (right > 5 && wrong == 0)
    {
        std::cout << " ** FLAWLESS VICTORY **\n";
    }
    std::cout << "\n ~ Bye ~\n\n";

    return 0;
}
