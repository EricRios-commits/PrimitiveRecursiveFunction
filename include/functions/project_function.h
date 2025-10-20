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

#include "functions/primitive_recursive_function.h"

/**
 * @brief Basic primitive recursive function
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
  ProjectionFunction(size_t arity, size_t index);

  auto Run(const std::vector<unsigned>& inputs) const -> unsigned override;

  auto GetArity() const -> size_t override;

 private:
  size_t arity_;
  size_t index_;
};

#endif // PROJECT_FUNCTION_H