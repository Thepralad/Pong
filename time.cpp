#include <iostream>
#include <cstdlib>   // For rand() function
#include <ctime>     // For seeding the random number generator

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 6
    int randomNumber = (std::rand() % 6) + 1;

    // Print the random number
    std::cout << "Random Number: " << randomNumber << std::endl;

    return 0;
}
