/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Implementation of the RecursionFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include "functions/recursion_function.h"
#include <stdexcept>

RecursionFunction::RecursionFunction(
    std::unique_ptr<PrimitiveRecursiveFunction> base_case,
    std::unique_ptr<PrimitiveRecursiveFunction> recursive_case)
    : base_case_(std::move(base_case)),
      recursive_case_(std::move(recursive_case)) {
  
  arity_ = base_case_->GetArity() + 1;

  if (recursive_case_->GetArity() != base_case_->GetArity() + 2) {
    throw std::invalid_argument(
        "Recursive case must have arity = base_case_arity + 2");
  }
}

auto RecursionFunction::Run(const std::vector<unsigned>& inputs) const -> unsigned {
  // Recursion on the LAST (rightmost) parameter
  // h(x₁, ..., xₖ, 0) = f(x₁, ..., xₖ)
  // h(x₁, ..., xₖ, n+1) = g(x₁, ..., xₖ, n, h(x₁, ..., xₖ, n))
  
  unsigned n = inputs.back();  // Last parameter is recursion variable
  
  // All parameters except the last one
  std::vector<unsigned> remaining_args(inputs.begin(), inputs.end() - 1);

  base_case_->ResetCallCount();
  unsigned result = base_case_->Run(remaining_args);
  AddNestedCalls(base_case_->GetCallCount());
  
  if (n == 0) {
    return result;
  }
  
  for (unsigned i = 0; i < n; ++i) {
    // Build args: (x₁, ..., xₖ, i, result)
    std::vector<unsigned> recursive_args;
    recursive_args.reserve(remaining_args.size() + 2);
    recursive_args.insert(recursive_args.end(), remaining_args.begin(),
                          remaining_args.end());
    recursive_args.push_back(i);
    recursive_args.push_back(result);
    
    recursive_case_->ResetCallCount();
    result = recursive_case_->Run(recursive_args);
    AddNestedCalls(recursive_case_->GetCallCount());
  }

  return result;
}

auto RecursionFunction::GetArity() const -> size_t {
  return arity_;
}
