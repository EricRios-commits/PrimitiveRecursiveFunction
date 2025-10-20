/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Implementation of the ProjectionFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include "functions/project_function.h"

ProjectionFunction::ProjectionFunction(size_t arity, size_t index)
    : arity_(arity), index_(index) {}

auto ProjectionFunction::Run(const std::vector<unsigned>& inputs) const -> unsigned {
  return inputs[index_];
}

auto ProjectionFunction::GetArity() const -> size_t {
  return arity_;
}
