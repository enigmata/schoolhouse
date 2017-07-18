#include <iostream>
#include <vector>
#include "median_temp.hpp"

int main()
{
    std::cout << "\nExercise: Print the median temperature, a number so that\n"
              << "exactly as many elements come before it in the sequence\n"
              << "as come after it.\n\n"
              << "Enter one or more temperatures, then enter Ctrl-D to exit:\n";

    std::vector<double> temps;

    for (double temp; std::cin >> temp;)
        temps.push_back(temp);

    if (temps.empty())
    {
        std::cout << "Error: No temperatures were entered\n";
        return 1;
    }

    std::cout << "The median temperature is " << median_temp(temps) << "\n";
    
    return 0;
}
