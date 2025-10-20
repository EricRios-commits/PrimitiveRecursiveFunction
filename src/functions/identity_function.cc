/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Implementation of the IdentityFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include "functions/identity_function.h"

auto IdentityFunction::Run(const std::vector<unsigned>& inputs) const -> unsigned {
  return inputs[0];
}

auto IdentityFunction::GetArity() const -> size_t {
  return 1;
}
