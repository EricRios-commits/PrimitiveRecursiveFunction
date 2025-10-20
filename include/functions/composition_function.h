/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 *
 * @brief Header file for the CompositionFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef COMPOSITION_FUNCTION_H
#define COMPOSITION_FUNCTION_H

#include <memory>
#include <vector>

#include "functions/primitive_recursive_function.h"

/**
 * @brief Composition operator for primitive recursive functions.
 */
class CompositionFunction : public PrimitiveRecursiveFunction {
 public:
  /**
   * @brief Construct a composition function.
   * @param outer The outer function f
   * @param inner Vector of inner functions (each takes k arguments)
   */
  CompositionFunction(
      std::unique_ptr<PrimitiveRecursiveFunction> outer,
      std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> inner);

  /**
   * @brief Execute the composition
   */
  auto Run(const std::vector<unsigned>& inputs) const -> unsigned override;

  auto GetArity() const -> size_t override;

 private:
  std::unique_ptr<PrimitiveRecursiveFunction> outer_;
  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> inner_;
  size_t arity_;
};

#endif  // COMPOSITION_FUNCTION_H
