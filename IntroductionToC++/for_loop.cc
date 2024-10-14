/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief for loop
 * Countdown using for
 *
 * @see https://www.learncpp.com/cpp-tutorial/for-statements/
 */

#include <iostream>

int main() {
  const int kNumberOfIterations{10};  // Play modifying this value

  for (int number{kNumberOfIterations}; number > 0; --number) {
    std::cout << number << ", ";
  }
  std::cout << "liftoff!" << std::endl;
}
