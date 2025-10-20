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

#include "primitive_recursive_function.h"

class SuccessorFunction : public PrimitiveRecursiveFunction<unsigned> {
 public:
  auto Run(unsigned input) -> unsigned override { return input + 1; }
};

#endif // SUCCESSOR_FUNCTION_H