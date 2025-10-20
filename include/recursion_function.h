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

#include "primitive_recursive_function.h"

/**
 * @brief Primitive recursion operator for building recursive functions.
 * 
 * Implements primitive recursion scheme:
 *   h(0, x₁, ..., xₖ) = f(x₁, ..., xₖ)                    [base case]
 *   h(n+1, x₁, ..., xₖ) = g(n, h(n, x₁, ..., xₖ), x₁, ..., xₖ)  [recursive case]
 * 
 * Where:
 * - f is a k-ary function (base case)
 * - g is a (k+2)-ary function (recursive case: takes n, h(n,...), x₁, ..., xₖ)
 * - h is the resulting (k+1)-ary function
 * 
 * The first argument is treated as the recursion variable.
 * 
 * Example: Addition add(x, y) can be defined as:
 *   - Base: add(0, y) = y              → f = P²₂(y)
 *   - Recursive: add(n+1, y) = S(add(n, y))  → g = S(P³₂(n, r, y))
 */
class RecursionFunction : public PrimitiveRecursiveFunction {
 public:
  /**
   * @brief Construct a primitive recursion function.
   * @param base_case Function f for h(0, x₁, ..., xₖ)
   * @param recursive_case Function g for h(n+1, x₁, ..., xₖ)
   */
  RecursionFunction(
      std::unique_ptr<PrimitiveRecursiveFunction> base_case,
      std::unique_ptr<PrimitiveRecursiveFunction> recursive_case)
      : base_case_(std::move(base_case)),
        recursive_case_(std::move(recursive_case)) {
    
    // Arity of h is one more than the arity of the base case
    // (base case is k-ary, result is (k+1)-ary)
    arity_ = base_case_->GetArity() + 1;

    // Validate: recursive case must be (k+2)-ary
    // It takes: n, h(n, x₁, ..., xₖ), x₁, ..., xₖ
    if (recursive_case_->GetArity() != base_case_->GetArity() + 2) {
      throw std::invalid_argument(
          "Recursive case must have arity = base_case_arity + 2");
    }
  }

  /**
   * @brief Execute the recursive function.
   * @param inputs (n, x₁, ..., xₖ) where n is the recursion variable
   * @return h(n, x₁, ..., xₖ)
   */
  auto Run(const std::vector<unsigned>& inputs) const -> unsigned override {
    unsigned n = inputs[0];  // Recursion variable
    
    // Extract remaining arguments (x₁, ..., xₖ)
    std::vector<unsigned> remaining_args(inputs.begin() + 1, inputs.end());

    // Base case: h(0, x₁, ..., xₖ) = f(x₁, ..., xₖ)
    if (n == 0) {
      return base_case_->Run(remaining_args);
    }

    // Recursive case: compute iteratively from 0 to n
    unsigned result = base_case_->Run(remaining_args);
    
    for (unsigned i = 0; i < n; ++i) {
      // Build arguments for g: (i, result, x₁, ..., xₖ)
      std::vector<unsigned> recursive_args;
      recursive_args.reserve(2 + remaining_args.size());
      recursive_args.push_back(i);           // Current iteration
      recursive_args.push_back(result);      // h(i, x₁, ..., xₖ)
      recursive_args.insert(
          recursive_args.end(),
          remaining_args.begin(),
          remaining_args.end());             // x₁, ..., xₖ

      result = recursive_case_->Run(recursive_args);
    }

    return result;
  }

  auto GetArity() const -> size_t override { return arity_; }

 private:
  std::unique_ptr<PrimitiveRecursiveFunction> base_case_;
  std::unique_ptr<PrimitiveRecursiveFunction> recursive_case_;
  size_t arity_;
};

#endif  // RECURSION_FUNCTION_H
