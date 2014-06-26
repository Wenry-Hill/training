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
#include "iostream"
#include "lib/helpers.h"

int main()
{
  seedRandomNumber();
  int a = getRandomNumber(2,100);
  std::cout << a << " THIS IS YOUR NUMBER\n";
  std::cout << "Determine if the number is prime or composite\n";
  std::cout << "If Prime type P\n";
  std::cout << "If Composite type C\n";
  
  std::string getLetter(bool ignoreCase=true, std::string min="C", std::string max="P");
  std::string Letter = getLetter("C", "P");

  
  if (Letter == "P")
  {
    std::vector<unsigned int> Answer = getPrimeFactorization(a);
    std::vector<unsigned int> getPrimeFactorization(unsigned int number);

    if (Answer.size() == 1)
    {
      std::cout << "You are correct =)\n";
    }

  }
  else
  {
    std::cout << "Why you so stupad?\n";
  }

  
  
  
  
    return 0;
}
