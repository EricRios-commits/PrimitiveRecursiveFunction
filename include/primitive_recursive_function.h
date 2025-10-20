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
 * All primitive recursive functions map from ℕᵏ → ℕ (k-tuple of naturals to a natural).
 * This design follows the Composite Pattern, where:
 * - Leaf nodes are basic functions (Zero, Successor, Projection)
 * - Composite nodes are Composition and Recursion operations
 */
class PrimitiveRecursiveFunction {
 public:
  /**
   * @brief Execute the function with given inputs.
   * @param inputs Vector of natural numbers (ℕᵏ)
   * @return Result of the function (ℕ)
   */
  virtual auto Run(const std::vector<unsigned>& inputs) const -> unsigned = 0;

  /**
   * @brief Get the arity (number of arguments) of this function.
   * @return Number of expected input arguments
   */
  virtual auto GetArity() const -> size_t = 0;

  /**
   * @brief Virtual destructor for proper cleanup of derived classes.
   */
  virtual ~PrimitiveRecursiveFunction() = default;
};

#endif  // PRIMITIVE_RECURSIVE_FUNCTION_H