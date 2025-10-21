/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Implementation of the ZeroFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include "functions/zero_function.h"

ZeroFunction::ZeroFunction(size_t arity) : arity_(arity) {}

auto ZeroFunction::Run(const std::vector<unsigned>&) const -> unsigned {
  IncrementCallCount();
  return 0;
}

auto ZeroFunction::GetArity() const -> size_t {
  return arity_;
}
