/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 *
 * @brief Header file for the PrimitiveRecursiveFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef PRIMITIVE_RECURSIVE_FUNCTION_H
#define PRIMITIVE_RECURSIVE_FUNCTION_H

#include <vector>

/**
 * @brief Abstract base class for all primitive recursive functions.
 * 
 */
class PrimitiveRecursiveFunction {
 public:
  /**
   * @brief Execute the function with given inputs.
   * @param inputs Vector of natural numbers
   * @return Result of the function
   */
  virtual auto Run(const std::vector<unsigned>& inputs) const -> unsigned = 0;

  /**
   * @brief Get the arity (number of arguments) of this function.
   * @return Number of expected input arguments
   */
  virtual auto GetArity() const -> size_t = 0;

  /**
   * @brief Virtual destructor
   */
  virtual ~PrimitiveRecursiveFunction() = default;
};

#endif  // PRIMITIVE_RECURSIVE_FUNCTION_H