/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jun 30 2020
 * @brief const after function states that this function does not change the object
 * Mark all functions that should not change the state of the object as const
 * Ensures that we can pass objects by a const reference and still call their functions
 * Substantially reduces number of errors
 *
 * If you compile this example you'll obtain an error:
 *     typical-const-error.cc: In function ‘void Print(const Student&)’:
 *     typical-const-error.cc:46:39: error: passing ‘const Student’ as ‘this’ argument discards qualifiers [-fpermissive]
 *     44  cout << "Student: " << student.name() << endl;
 *
 * The problem is that the Print function parameter is a const reference
 * and Print calls student.name() (the getter) but it has to be guaranteed that the object will not be modified
 * The solution is to declare const the name getter:
 *    const string& Name() const { return name_; }
 *
 * In this code, note the member initialization in the constructor
 * It uses the uniform initializer syntax, using braces {} 
 * @see http://www.cplusplus.com/doc/tutorial/classes/#member_initialization
 *
 * @see https://stackoverflow.com/questions/5973427/error-passing-xxx-as-this-argument-of-xxx-discards-qualifiers
 * @see https://isocpp.org/wiki/faq/const-correctness#const-member-fns
 */

#include <string>
#include <iostream>

class Student {
 public:
  Student(const std::string& name): name_{name} {}    // Constructor initializer list syntax (body is empty)
  std::string name() { return name_; }          // Getter
 private:
  std::string name_{""};
};

void Print(const Student& student) {
  std::cout << "Student: " << student.name() << std::endl;
}

int main() {
  Student student{"Albert Einstein"};
  Print(student);
  return 0;
}
