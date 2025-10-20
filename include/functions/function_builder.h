/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Factory for building common primitive recursive functions.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef FUNCTION_BUILDER_H
#define FUNCTION_BUILDER_H

#include <memory>
#include "functions/primitive_recursive_function.h"

/**
 * @brief Factory class for building primitive recursive functions.
 */
class FunctionBuilder {
 public:
  /**
   * @brief Build addition function: add(x, y) = x + y
   * @return Unique pointer to addition function
   */
  static auto BuildAddition() -> std::unique_ptr<PrimitiveRecursiveFunction>;

  /**
   * @brief Build subtraction function: sub(x, y) = max(0, x - y)
   * @return Unique pointer to subtraction function (proper subtraction)
   */
  static auto BuildSubtraction() -> std::unique_ptr<PrimitiveRecursiveFunction>;

  /**
   * @brief Build multiplication function: mult(x, y) = x * y
   * @return Unique pointer to multiplication function
   */
  static auto BuildMultiplication() -> std::unique_ptr<PrimitiveRecursiveFunction>;

  /**
   * @brief Build integer division function: div(x, y) = x / y
   * @return Unique pointer to division function
   */
  static auto BuildDivision() -> std::unique_ptr<PrimitiveRecursiveFunction>;

  /**
   * @brief Build power function: pow(x, y) = x^y
   * @return Unique pointer to power function
   */
  static auto BuildPower() -> std::unique_ptr<PrimitiveRecursiveFunction>;

  /**
   * @brief Build predecessor function: pred(x) = max(0, x - 1)
   * @return Unique pointer to predecessor function
   */
  static auto BuildPredecessor() -> std::unique_ptr<PrimitiveRecursiveFunction>;
};

#endif  // FUNCTION_BUILDER_H
