/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Implementation of the SuccessorFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include "functions/successor_function.h"
#include <stdexcept>

auto SuccessorFunction::Run(const std::vector<unsigned>& inputs) const -> unsigned {
  if (inputs.size() != 1) {
    throw std::invalid_argument("SuccessorFunction expects exactly one argument");
  }
  return inputs[0] + 1;
}

auto SuccessorFunction::GetArity() const -> size_t {
  return 1;
}
