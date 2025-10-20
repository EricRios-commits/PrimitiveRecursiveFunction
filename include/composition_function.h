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

#include "primitive_recursive_function.h"

/**
 * @brief Composition operator for primitive recursive functions.
 * 
 * Implements function composition: h(x₁, ..., xₖ) = f(g₁(x₁, ..., xₖ), ..., gₘ(x₁, ..., xₖ))
 * 
 * Where:
 * - f is an m-ary function (outer function)
 * - g₁, ..., gₘ are k-ary functions (inner functions)
 * - The result h is a k-ary function
 * 
 * This implements the Composite Pattern where composition itself is a PRF.
 * 
 * Example: To define addition using composition:
 *   h(x, y) = x + y can be built using composition and recursion
 */
class CompositionFunction : public PrimitiveRecursiveFunction {
 public:
  /**
   * @brief Construct a composition function.
   * @param outer The outer function f (takes m arguments)
   * @param inner Vector of inner functions g₁, ..., gₘ (each takes k arguments)
   */
  CompositionFunction(
      std::unique_ptr<PrimitiveRecursiveFunction> outer,
      std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> inner)
      : outer_(std::move(outer)), inner_(std::move(inner)) {
    
    // Validate: all inner functions must have the same arity
    if (!inner_.empty()) {
      arity_ = inner_[0]->GetArity();
      for (const auto& func : inner_) {
        if (func->GetArity() != arity_) {
          throw std::invalid_argument(
              "All inner functions must have the same arity");
        }
      }
    } else {
      arity_ = 0;
    }

    // Validate: outer function arity must match number of inner functions
    if (outer_->GetArity() != inner_.size()) {
      throw std::invalid_argument(
          "Outer function arity must match number of inner functions");
    }
  }

  /**
   * @brief Execute the composition: f(g₁(x), ..., gₘ(x))
   */
  auto Run(const std::vector<unsigned>& inputs) const -> unsigned override {
    // First, evaluate all inner functions with the same inputs
    std::vector<unsigned> intermediate_results;
    intermediate_results.reserve(inner_.size());
    
    for (const auto& func : inner_) {
      intermediate_results.push_back(func->Run(inputs));
    }

    // Then, apply the outer function to the intermediate results
    return outer_->Run(intermediate_results);
  }

  auto GetArity() const -> size_t override { return arity_; }

 private:
  std::unique_ptr<PrimitiveRecursiveFunction> outer_;
  std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> inner_;
  size_t arity_;
};

#endif  // COMPOSITION_FUNCTION_H
