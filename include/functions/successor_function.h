/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 *
 * @brief Header file for the SuccessorFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef SUCCESSOR_FUNCTION_H
#define SUCCESSOR_FUNCTION_H

#include "functions/primitive_recursive_function.h"

/**
 * @brief Basic primitive recursive function: S(x) = x + 1
 */
class SuccessorFunction : public PrimitiveRecursiveFunction {
 public:
  auto Run(const std::vector<unsigned>& inputs) const -> unsigned override;

  auto GetArity() const -> size_t override;
};

#endif // SUCCESSOR_FUNCTION_H