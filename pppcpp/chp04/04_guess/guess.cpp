#include <cctype>
#include <iostream>

const char YES = 'y', NO = 'n';

int main(void) {
  int upper_limit = 100, lower_limit = 1, less_than = 100, num_guesses = 0;
  char answer = YES;

  std::cout << "\nPick a number between 1 and 100, inclusive,\n"
            << "and I will guess it.\n\n";

  while (true) {
    less_than = ((upper_limit - lower_limit) / 2) + lower_limit;

    do {
      std::cout << "Is your number less than " << less_than << "? (y or n) ";

      if (!(std::cin >> answer)) {
        std::cout << "Invalid input. Exiting.\n";
        return 1;
      }

      answer = std::tolower(answer);
    } while (answer != 'y' && answer != 'n');

    if (answer == 'y')
      upper_limit = less_than - 1;
    else
      lower_limit = less_than;

    num_guesses += 1;

    if (upper_limit - lower_limit == 1) {
      std::cout << "Is your number " << lower_limit << "? (y or n) ";
      if (!(std::cin >> answer)) {
        std::cout << "Invalid input. Exiting.\n";
        return 1;
      }
      if (answer == 'y' || answer == 'Y') {
        std::cout << "Thought so ;-) (" << num_guesses << " guesses)\n";
        break;
      } else {
        lower_limit = upper_limit;
      }
    }

    if (upper_limit == lower_limit) {
      std::cout << "Your number is " << upper_limit << " (" << num_guesses
                << " guesses)\n";
      break;
    }
  }

  return 0;
}
