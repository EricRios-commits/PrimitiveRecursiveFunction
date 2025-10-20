/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Implementation of FunctionBuilder class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include "functions/function_builder.h"

#include <vector>

#include "functions/composition_function.h"
#include "functions/project_function.h"
#include "functions/recursion_function.h"
#include "functions/successor_function.h"
#include "functions/zero_function.h"

static auto CreateAddition() -> std::unique_ptr<PrimitiveRecursiveFunction> {
  // Base: add(0, y) = y
  auto add_base = std::make_unique<ProjectionFunction>(1, 0);

  // Recursive: add(n+1, y) = S(add(n, y))
  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> add_inner;
  add_inner.push_back(std::make_unique<ProjectionFunction>(3, 1));
  auto add_recursive = std::make_unique<CompositionFunction>(
      std::make_unique<SuccessorFunction>(), std::move(add_inner));

  return std::make_unique<RecursionFunction>(std::move(add_base),
                                             std::move(add_recursive));
}

auto FunctionBuilder::BuildAddition()
    -> std::unique_ptr<PrimitiveRecursiveFunction> {
  return CreateAddition();
}

// Base: pred(0) = 0
// Recursive: pred(n+1) = n
auto FunctionBuilder::BuildPredecessor()
    -> std::unique_ptr<PrimitiveRecursiveFunction> {
  auto pred_base = std::make_unique<ZeroFunction>(0);
  auto pred_recursive = std::make_unique<ProjectionFunction>(2, 0);

  return std::make_unique<RecursionFunction>(std::move(pred_base),
                                             std::move(pred_recursive));
}

// Base: sub(x, 0) = x
// Recursive: sub(x, y+1) = pred(sub(x, y))
auto FunctionBuilder::BuildSubtraction()
    -> std::unique_ptr<PrimitiveRecursiveFunction> {
  auto sub_base = std::make_unique<ProjectionFunction>(1, 0);
  auto pred_base_inner = std::make_unique<ZeroFunction>(0);
  auto pred_recursive_inner = std::make_unique<ProjectionFunction>(2, 0);
  auto pred = std::make_unique<RecursionFunction>(
      std::move(pred_base_inner), std::move(pred_recursive_inner));

  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> sub_inner;
  sub_inner.push_back(std::make_unique<ProjectionFunction>(3, 1));

  auto sub_recursive = std::make_unique<CompositionFunction>(
      std::move(pred), std::move(sub_inner));

  return std::make_unique<RecursionFunction>(std::move(sub_base),
                                             std::move(sub_recursive));
}

// Base: mult(x, 0) = Z(X)
// Recursive: mult(x, y+1) = add(mult(x, y), x)
auto FunctionBuilder::BuildMultiplication()
    -> std::unique_ptr<PrimitiveRecursiveFunction> {
  auto mult_base = std::make_unique<ZeroFunction>(1);
  auto addition = CreateAddition();

  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> mult_inner;
  mult_inner.push_back(std::make_unique<ProjectionFunction>(3, 1));
  mult_inner.push_back(std::make_unique<ProjectionFunction>(3, 2));

  auto mult_recursive = std::make_unique<CompositionFunction>(
      std::move(addition), std::move(mult_inner));

  return std::make_unique<RecursionFunction>(std::move(mult_base),
                                             std::move(mult_recursive));
}

// Base: pow(x, 0) = 1 -> S(Z(x))
// Recursive: pow(x, y+1) = mult(pow(x, y), x)
auto FunctionBuilder::BuildPower()
    -> std::unique_ptr<PrimitiveRecursiveFunction> {
  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> one_inner;
  one_inner.push_back(std::make_unique<ZeroFunction>(1));
  auto pow_base = std::make_unique<CompositionFunction>(
      std::make_unique<SuccessorFunction>(), std::move(one_inner));

  auto multiplication = BuildMultiplication();

  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> pow_inner;
  pow_inner.push_back(std::make_unique<ProjectionFunction>(3, 1));
  pow_inner.push_back(std::make_unique<ProjectionFunction>(3, 2));

  auto pow_recursive = std::make_unique<CompositionFunction>(
      std::move(multiplication), std::move(pow_inner));

  return std::make_unique<RecursionFunction>(std::move(pow_base),
                                             std::move(pow_recursive));
}