/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Implementation of the CompositionFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include "functions/composition_function.h"
#include <stdexcept>

CompositionFunction::CompositionFunction(
    std::unique_ptr<PrimitiveRecursiveFunction> outer,
    std::vector<std::unique_ptr<PrimitiveRecursiveFunction>> inner)
    : outer_(std::move(outer)), inner_(std::move(inner)) {
  
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

  if (outer_->GetArity() != inner_.size()) {
    throw std::invalid_argument(
        "Outer function arity must match number of inner functions");
  }
}

auto CompositionFunction::Run(const std::vector<unsigned>& inputs) const -> unsigned {
  std::vector<unsigned> intermediate_results;
  intermediate_results.reserve(inner_.size());
  
  for (const auto& func : inner_) {
    func->ResetCallCount();
    intermediate_results.push_back(func->Run(inputs));
    AddNestedCalls(func->GetCallCount());
  }

  outer_->ResetCallCount();
  unsigned result = outer_->Run(intermediate_results);
  AddNestedCalls(outer_->GetCallCount());
  
  return result;
}

auto CompositionFunction::GetArity() const -> size_t {
  return arity_;
}
