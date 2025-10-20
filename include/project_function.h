/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 *
 * @brief Header file for the ProjectionFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef PROJECT_FUNCTION_H
#define PROJECT_FUNCTION_H

#include "primitive_recursive_function.h"

/**
 * @brief Basic primitive recursive function: Pⁿᵢ(x₁, ..., xₙ) = xᵢ
 * 
 * The projection function returns the i-th argument from n arguments.
 * This is one of the three basic primitive recursive functions.
 * 
 * @note Index is 0-based (0 ≤ index < arity)
 */
class ProjectionFunction : public PrimitiveRecursiveFunction {
 public:
  /**
   * @brief Construct a projection function.
   * @param arity Total number of arguments
   * @param index Which argument to project (0-based)
   */
  ProjectionFunction(size_t arity, size_t index) 
      : arity_(arity), index_(index) {}

  auto Run(const std::vector<unsigned>& inputs) const -> unsigned override {
    return inputs[index_];
  }

  auto GetArity() const -> size_t override { return arity_; }

 private:
  size_t arity_;
  size_t index_;
};

#endif // PROJECT_FUNCTION_H