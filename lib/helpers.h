#ifndef HELPERS_H
#define HELPERS_H

#include <climits>
#include <string>
#include <vector>

/* Returns a non-zero length string from standard input with whitespace trimmed
 * from the beginning and end */
std::string getString();

/* Returns an integer with a value between min and max (inclusive) from standard
 * input */
int getInteger(int min=INT_MIN, int max=INT_MAX);

/* Returns a single letter from standard input. If ignoreCase is true, the
 * letter returned will always be upper cased. Non-letter values (numbers or
 * symbols) will never be returned, even if they exist between min and max */
std::string getLetter(bool ignoreCase=true, std::string min="A", std::string max="z");
std::string getLetter(std::string min, std::string max);

/* Returns a floating point number from standard input */
double getDecimal(double min=LONG_MIN, double max=LONG_MAX);

/* Given a number greater than 1, this function will return the prime
 * factorization of any composite number. If the number itself is prime, it will
 * be the only element in the vector.
 */
std::vector<unsigned int> getPrimeFactorization(unsigned int number);

/* Returns an integer chosen at random between min and max, inclusive */
int getRandomNumber(int min=1, int max=10);

/* Changes which random numbers will be generated. */
void seedRandomNumber();

#endif