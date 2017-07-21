#include <iostream>
#include <stdexcept>
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

    try
    {
        double m = median_temp(temps);
        std::cout << "The median temperature is " << m << "\n";
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
