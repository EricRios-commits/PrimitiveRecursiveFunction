/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 *
 * @brief Header file for the ProjectFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef PROJECT_FUNCTION_H
#define PROJECT_FUNCTION_H

#include <vector>

#include "primitive_recursive_function.h"

template<typename T>
class ProjectFunction : public PrimitiveRecursiveFunction<T> {
 public:
  explicit ProjectFunction(size_t index) : index_(index) {}
  auto Run(const std::vector<T>& inputs) -> T override {
    return inputs[index_];
  }
 private:
  size_t index_;
};

#endif // PROJECT_FUNCTION_H