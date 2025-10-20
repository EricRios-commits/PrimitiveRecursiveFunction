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

class ZeroFunction : public PrimitiveRecursiveFunction<unsigned> {
 public:
  auto Run(unsigned input) -> unsigned override { return 0; }
};

#endif  // ZERO_FUNCTION_H