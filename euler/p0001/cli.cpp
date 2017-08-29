#include "multiples_of.hpp"

#include <chrono>
#include <iostream>
#include <ratio>

using microsecs = std::chrono::duration<double, std::micro>;

int main() {
  int x{0}, y{0};
  long int ceiling{0};

  std::cout << "\nProblem: Find the sum of all the multiples of 3 and 5 below\n"
            << "1,000.\n\n"
            << "This cli generalizes the solution by asking for two\n"
            << "natural numbers, x and y, where x=3 and y=5 in the stated\n"
            << "problem, and a natural number, ceiling, where ceiling=1000\n"
            << "in the stated problem, up to which the sum is computed.\n\n"
            << "Enter three numbers (x y ceiling) then press <ENTER>: \n";

  std::cin >> x >> y >> ceiling;

  // we'll take the answer from the power sum function,
  // multiples_of_x_and_y_psum, but we need to run this
  // slower solution to get the timings for comparison
  auto start_brute = std::chrono::high_resolution_clock::now();
  multiples_of_x_and_y_brute(x, y, ceiling);
  auto end_brute = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed_brute = end_brute - start_brute;

  auto start_psum = std::chrono::high_resolution_clock::now();
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(x, y, ceiling);
  auto end_psum = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed_psum = end_psum - start_psum;

  if (rc == return_code::success) {
    std::cout << "The sum of all multiples of " << x << " and " << y;
    std::cout << ", below " << ceiling << ", is " << sum << "\n\n";
    std::cout << "Elapsed time comparison (microseconds):\n";
    std::cout << "Brute force:\t" << microsecs(elapsed_brute).count() << "\n";
    std::cout << "Power sum:\t" << microsecs(elapsed_psum).count() << "\n";

  } else if (rc == return_code::err_not_natural_nums) {
    std::cout << "Error: x, y, and ceiling must be natural numbers (>=1)\n";
  } else if (rc == return_code::err_ceiling_too_low) {
    std::cout << "Error: Ceiling must be greater than x and y\n";
  } else if (rc == return_code::err_x_equals_y) {
    std::cout << "Error: x cannot be same as y\n";
  } else {
    std::cout << "Unknown error\n";
  }
  return static_cast<int>(rc);
}
