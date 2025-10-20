/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 *
 * @brief Header file for the RecursionFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef RECURSION_FUNCTION_H
#define RECURSION_FUNCTION_H

#include <memory>
#include <vector>

#include "functions/primitive_recursive_function.h"

/**
 * @brief Primitive recursion operator for building recursive functions.
 */
class RecursionFunction : public PrimitiveRecursiveFunction {
 public:
  /**
   * @brief Construct a primitive recursion function.
   * @param base_case Function f 
   * @param recursive_case Function g
   */
  RecursionFunction(
      std::unique_ptr<PrimitiveRecursiveFunction> base_case,
      std::unique_ptr<PrimitiveRecursiveFunction> recursive_case);

  /**
   * @brief Execute the recursive function.
   * @param inputs 
   * @return the result of the recursion
   */
  auto Run(const std::vector<unsigned>& inputs) const -> unsigned override;

  auto GetArity() const -> size_t override;

 private:
  std::unique_ptr<PrimitiveRecursiveFunction> base_case_;
  std::unique_ptr<PrimitiveRecursiveFunction> recursive_case_;
  size_t arity_ = 0;
};

#endif  // RECURSION_FUNCTION_H
