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

#include "functions/primitive_recursive_function.h"

/**
 * @brief Basic primitive recursive function that returns zero for any input.
 */
class ZeroFunction : public PrimitiveRecursiveFunction {
 public:
  /**
   * @brief Construct a zero function with specified arity.
   * @param arity Number of arguments (default: 1)
   */
  explicit ZeroFunction(size_t arity = 1);

  auto Run(const std::vector<unsigned>&) const -> unsigned override;

  auto GetArity() const -> size_t override;

 private:
  size_t arity_;
};

#endif  // ZERO_FUNCTION_H