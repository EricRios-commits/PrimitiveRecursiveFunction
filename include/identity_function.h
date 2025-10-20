/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 *
 * @brief Header file for the IdentityFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef IDENTITY_FUNCTION_H
#define IDENTITY_FUNCTION_H

#include "primitive_recursive_function.h"

/**
 * @brief Identity function: Id(x) = x
 * 
 * This is simply a projection function P¹₁ that returns its single argument.
 * Included as a convenience alias for clarity in code.
 * Arity: 1 (unary function)
 */
class IdentityFunction : public PrimitiveRecursiveFunction {
 public:
  auto Run(const std::vector<unsigned>& inputs) const -> unsigned override {
    return inputs[0];
  }

  auto GetArity() const -> size_t override { return 1; }
};

#endif  // IDENTITY_FUNCTION_H