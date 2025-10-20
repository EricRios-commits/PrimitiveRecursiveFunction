/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Implementation of FunctionRegistry class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include "interactive/function_registry.h"
#include <algorithm>

void FunctionRegistry::RegisterFunction(
    const std::string& name,
    const std::string& description,
    std::unique_ptr<PrimitiveRecursiveFunction> function) {
  
  size_t arity = function->GetArity();
  
  FunctionInfo info{
      name,
      description,
      arity,
      std::move(function)
  };
  
  functions_[name] = std::move(info);
}

auto FunctionRegistry::GetFunction(const std::string& name) const 
    -> const PrimitiveRecursiveFunction* {
  auto it = functions_.find(name);
  if (it != functions_.end()) {
    return it->second.function.get();
  }
  return nullptr;
}

auto FunctionRegistry::GetFunctionInfo(const std::string& name) const 
    -> const FunctionInfo* {
  auto it = functions_.find(name);
  if (it != functions_.end()) {
    return &it->second;
  }
  return nullptr;
}

auto FunctionRegistry::GetAllFunctionNames() const -> std::vector<std::string> {
  std::vector<std::string> names;
  names.reserve(functions_.size());
  
  for (const auto& pair : functions_) {
    names.push_back(pair.first);
  }
  
  return names;
}

auto FunctionRegistry::Size() const -> size_t {
  return functions_.size();
}
