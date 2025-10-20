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

#include "functions/primitive_recursive_function.h"

/**
 * @brief Identity function: Id(x) = x (Alias for projection function P1,1)
 * 
 */
class IdentityFunction : public PrimitiveRecursiveFunction {
 public:
  auto Run(const std::vector<unsigned>& inputs) const -> unsigned override;

  auto GetArity() const -> size_t override;
};

#endif  // IDENTITY_FUNCTION_H