#include <string>
#include <vector>
#include <unordered_map>
#include <boost/concept_check.hpp>

int main()
{
    // You declare a variable by telling C++ what type it is, and what its name is
    int var;
    // Type is "int", which means a number without decimal places
    // Name is "var". You can now reference "var" other places below

    // You can also assign values to a variable you have declared.
    // Good variable assignments
    bool a = true;
    int b = 0;
    double c = 1.234;
    std::string d = "Hi";

    bool e = a;

    // Mathematical Operators
    // (Addition) +
    // (Subtraction) -
    // (Multiplication) *
    // (Division) /
    // (Remainder) % - (7 % 5 == 2)
    int f = b + 2;
    double g = c - 3.14159;

    std::string h = d + " there"; // Using + on strings joins them together


    // Bad variable assignments
    //int i = "0"; // syntax error: assigning a string to a numerical type
    //double j = "1.234";

    int k = 1.113; // double value will be truncated to 1

    bool l = 0; // will be interpreted as false


    // Logical Operators
    // (NOT) ! - True if the value it modifies is false
    ! false == true;

    // (OR) || - True if at least one argument before or after it is true
    true || true == true;
    true || false == true;
    false || true == true;
    false || false == false;

    // (AND) && - True if both arguments before and after it are true
    true && true == true;
    true && false == false;
    false && true == false;
    false && false == false;


    // Comparison operators
    // == - True if the arguments before and after it are equivalent
    // < - True if the argument before it is less than the argument after it
    // <= - True if the argument before it is less than or equal to the argument after it
    // > - True if the argument before it is greater than the argument after it
    // >= - True if the argument before it is greater than or equal to the argument after it
    // != - True if the arguments before and after it are not equal

    // Branching
    // You often need the computer to take a course of action based on current conditions
    // The easiest way to do this in C++ is to use the if statement

    if (true)
    {
        // This block runs.
    }

    if (false)
    {
        // This block does not run
    }

    // You can also use "else" after an if statement if you want to do something if the condition is not true
    if (b >= 0)
    {
        b = b * 2;
    }
    else
    {
        b = b + 2;
    }
    // What is the value of a now?


    // Scope:
    // Variable are only available in blocks where they have been declared.
    // Accessing a block before it is declared or after it has expired is an error
    if (true)
    {
        int m = 10; // Declared inside the curly braces
    }
    // accessing m after the matching brace closes is an error
    //int n = m; // syntax error: Unknown variable "m"


    // Containers
    // Sometimes you want to group multiple values together, but you don't know exactly how many.
    // Rather than do something stupid like int val1, val2, val3, ..., use STL containers
    // A vector can hold a list of variables:
    std::vector<int> n = {1, 2, 3, 4};
    n.push_back(5); // Add 5 to the end of the list

    // A map can hold values keyed to another value
    std::unordered_map<std::string, std::string> o = {{"Hi", "Hello"}, {"Sup?", "What is new?"}};
    o["lol"] = "That was very humorous.";

    // Often you will want to do something more than once, and usually an unknown number of times.
    // To accomplish this, C++ provides loops
    // The most basic type is the "while" loop. It acts like an if statement, but instead of running
    // only once if its condition is true, it runs until it's condition is false.
    // Beware of creating a loop that never ends!
    b = 1;
    while (b < 10)
    {
        b = b * 2;
    }

    // You can also loop over the objects in a container with a "for" loop
    for (int i : n)
    {
        b = b - i;
    }

    // Sometimes you might want to end a loop even when its condition is not false
    // To do that, use a break statement
    while (b != 10)
    {
        b = b + 3;
        if (b >= 11)
        {
            break;
        }
    }

    // Can also skip over the rest of a block inside a loop by using continue
    // The program will restart at evaluating the loop condition
    b = 1;
    while (b < 10)
    {
        if (b % 5 == 0)
        {
            b = b + 3;
            continue;
        }
        b = b + 1;
    }

    return 0;
}

// As you may have noticed, this file has become very long and it is becoming hard
// to remember where everything is. One helpful way to avoid this is to encapsulate
// parts of your program inside a function. A function will execute a series of
// commands when it is called from somewhere else in your code.
// A function has multiple parts:
// - return type: tells the program what type of value to expect the function to
//     equal when the function ends
// - name: gives other code a way of calling the function
// - argument list: the list of variables that can be passed to a function
int getSix(bool makeNegative=false)
{
    if (makeNegative)
    {
        return -6;
    }
    return 6;
}

// The "return" statement tells the program to set the value of the function. The
// value returned must be the same type as the function. If your function does not
// need to return anything, it can use the void type. Then a return statement is
// not required.
void doNothing()
{
}

// functions cannot be defined inside other functions. However, they can be called inside
// other functions, or even inside themselves (this is called recursion).
void callOtherFunctions()
{
    int a = getSix(); // Note these are not the same variables as those in main
    int b = getSix(true); // Each function has its own scope
    int c = getSix(false);

    doNothing();
}

// You cannot call a function in the file before it is defined. However, you will often
// see function prototypes (the first line of a function) without an implementation.
// This is enough information for the compiler to build your program, as long as it
// eventually finds the implementation of that function.

// Normally when you pass an argument to a function, a copy of that object is passed.
// If you want to pass the variable itself, so that modifications made in the function
// will still apply after the function has ended, you can pass your variable by reference
// using the & operator.
void swap(int& a, int& b)
{
    int tmp = b;
    b = a;
    a = tmp;
}