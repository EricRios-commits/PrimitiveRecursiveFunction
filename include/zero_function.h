/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 *
 * @brief Header file for the ZeroFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef ZERO_FUNCTION_H
#define ZERO_FUNCTION_H

#include "primitive_recursive_function.h"

/**
 * @brief Basic primitive recursive function: Z(x₁, ..., xₙ) = 0
 * 
 * The zero function returns 0 regardless of input.
 * This is one of the three basic primitive recursive functions.
 */
class ZeroFunction : public PrimitiveRecursiveFunction {
 public:
  /**
   * @brief Construct a zero function with specified arity.
   * @param arity Number of arguments (default: 1)
   */
  explicit ZeroFunction(size_t arity = 1) : arity_(arity) {}

  auto Run(const std::vector<unsigned>&) const -> unsigned override { 
    return 0;
  }

  auto GetArity() const -> size_t override { return arity_; }

 private:
  size_t arity_;
};

#endif  // ZERO_FUNCTION_H