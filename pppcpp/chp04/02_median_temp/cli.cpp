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

    auto && [ m, rc ] = median_temp(temps);

    if (rc == return_code::success) {
      std::cout << "The median temperature is " << m << "\n";
    } else if (rc == return_code::err_no_temps) {
      std::cout << "Error: At least one temperature is required!\n";
    } else {
      std::cout << "Error: Unknown!\n";
    }

    return static_cast<int>(rc);
}
