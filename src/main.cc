/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Example usage of primitive recursive functions.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include <iostream>
#include <memory>
#include <vector>

#include "composition_function.h"
#include "identity_function.h"
#include "primitive_recursive_function.h"
#include "project_function.h"
#include "recursion_function.h"
#include "successor_function.h"
#include "zero_function.h"

/**
 * @brief Helper function to create and execute a function.
 */
void TestFunction(const std::string& name,
                  const PrimitiveRecursiveFunction& func,
                  const std::vector<unsigned>& inputs) {
  std::cout << name << "(";
  for (size_t i = 0; i < inputs.size(); ++i) {
    std::cout << inputs[i];
    if (i < inputs.size() - 1) std::cout << ", ";
  }
  std::cout << ") = " << func.Run(inputs) << std::endl;
}

int main() {
  std::cout << "=== Primitive Recursive Functions Demonstration ===\n\n";

  // ===== 1. Basic Functions =====
  std::cout << "1. Basic Functions:\n";
  std::cout << "-------------------\n";

  ZeroFunction zero(1);
  SuccessorFunction succ;
  IdentityFunction id;
  ProjectionFunction proj_2_1(2, 0);  // P²₁(x,y) = x
  ProjectionFunction proj_2_2(2, 1);  // P²₂(x,y) = y

  TestFunction("Zero", zero, {5});
  TestFunction("Successor", succ, {5});
  TestFunction("Identity", id, {42});
  TestFunction("Projection_2_1", proj_2_1, {10, 20});
  TestFunction("Projection_2_2", proj_2_2, {10, 20});

  // ===== 2. Composition Example =====
  std::cout << "\n2. Composition: f(g(x))\n";
  std::cout << "-------------------------\n";

  // Example: double(x) = S(S(x)) = x + 2
  // Using composition: S ∘ S
  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> inner_funcs;
  inner_funcs.push_back(std::make_unique<SuccessorFunction>());
  
  auto add_two = std::make_unique<CompositionFunction>(
      std::make_unique<SuccessorFunction>(),
      std::move(inner_funcs)
  );

  TestFunction("Add_Two (S∘S)", *add_two, {5});
  TestFunction("Add_Two (S∘S)", *add_two, {10});

  // ===== 3. Addition using Primitive Recursion =====
  std::cout << "\n3. Addition: add(x, y) = x + y\n";
  std::cout << "-------------------------------\n";
  std::cout << "Definition:\n";
  std::cout << "  add(0, y) = y                [base case: P¹₁]\n";
  std::cout << "  add(n+1, y) = S(add(n, y))   [recursive: S(P³₂)]\n\n";

  // Base case: add(0, y) = y → use projection P¹₁
  auto add_base = std::make_unique<ProjectionFunction>(1, 0);

  // Recursive case: add(n+1, y) = S(add(n, y))
  // g takes (n, add(n,y), y) and returns S(add(n,y))
  // So we need S(P³₂(n, r, y)) where P³₂ selects the middle argument (r)
  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> add_inner;
  add_inner.push_back(std::make_unique<ProjectionFunction>(3, 1));  // P³₂
  
  auto add_recursive = std::make_unique<CompositionFunction>(
      std::make_unique<SuccessorFunction>(),
      std::move(add_inner)
  );

  auto addition = std::make_unique<RecursionFunction>(
      std::move(add_base),
      std::move(add_recursive)
  );

  TestFunction("Addition", *addition, {0, 5});
  TestFunction("Addition", *addition, {3, 4});
  TestFunction("Addition", *addition, {7, 8});
  TestFunction("Addition", *addition, {10, 15});

  // ===== 4. Multiplication using Primitive Recursion =====
  std::cout << "\n4. Multiplication: mult(x, y) = x * y\n";
  std::cout << "--------------------------------------\n";
  std::cout << "Definition:\n";
  std::cout << "  mult(0, y) = 0               [base case: Z¹]\n";
  std::cout << "  mult(n+1, y) = add(mult(n, y), y)  [recursive]\n\n";

  // Base case: mult(0, y) = 0
  auto mult_base = std::make_unique<ZeroFunction>(1);

  // Recursive case: mult(n+1, y) = add(mult(n, y), y)
  // g takes (n, mult(n,y), y) and returns add(mult(n,y), y)
  // We need to create a version of addition that takes the right arguments
  
  // Create inner functions for composition: [P³₂, P³₃]
  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> mult_inner;
  mult_inner.push_back(std::make_unique<ProjectionFunction>(3, 1));  // mult(n,y)
  mult_inner.push_back(std::make_unique<ProjectionFunction>(3, 2));  // y

  // Recreate addition for composition
  auto add_base2 = std::make_unique<ProjectionFunction>(1, 0);
  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> add_inner2;
  add_inner2.push_back(std::make_unique<ProjectionFunction>(3, 1));
  auto add_recursive2 = std::make_unique<CompositionFunction>(
      std::make_unique<SuccessorFunction>(),
      std::move(add_inner2)
  );
  auto addition2 = std::make_unique<RecursionFunction>(
      std::move(add_base2),
      std::move(add_recursive2)
  );

  auto mult_recursive = std::make_unique<CompositionFunction>(
      std::move(addition2),
      std::move(mult_inner)
  );

  auto multiplication = std::make_unique<RecursionFunction>(
      std::move(mult_base),
      std::move(mult_recursive)
  );

  TestFunction("Multiplication", *multiplication, {0, 5});
  TestFunction("Multiplication", *multiplication, {3, 4});
  TestFunction("Multiplication", *multiplication, {5, 6});
  TestFunction("Multiplication", *multiplication, {7, 8});

  std::cout << "\n=== All tests completed successfully! ===\n";

  return 0;
}