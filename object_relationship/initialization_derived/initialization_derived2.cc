/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief Illustrates the role of constructors in the initialization of derived classes. 
 *        There is no way to initialize id_ when we create a Derived object
          What if we want to set both cost_ and id_ when we create a Derived object?
 *        Firtst attempt:  initialization_derived2.cc
 *        - Add an additional parameter to the Derived constructor
 *        - It doesn’t work because only non-inherited variables can be initialized in the initialization list
 *
 * @see https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
 */

#include <iostream>

class Base {
 public:
  Base(int id = 0) : id_{ id } {
    std::cout << "Constructor Base(int) llamado" << std::endl;
  }
  int id() const { return id_; }
  int id_;
};

class Derived: public Base {
 public:
  // does not work
  Derived(double cost = 0.0, int id = 0) : cost_{cost}, id_{id} { }
  double cost() const { return cost_; }
  double cost_;
};

int main() {
  Derived derived{1.3, 5}; // use Derived(double) constructor
  std::cout << "Derived Id: " << derived.id() << '\n';
  std::cout << "Derived Cost: " << derived.cost() << '\n';
  return 0;
}
