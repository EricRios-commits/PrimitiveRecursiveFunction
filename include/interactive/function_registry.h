/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Registry for managing available primitive recursive functions.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef FUNCTION_REGISTRY_H
#define FUNCTION_REGISTRY_H

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "functions/primitive_recursive_function.h"

/**
 * @brief Information about a registered function.
 */
struct FunctionInfo {
  std::string name;
  std::string description;
  size_t arity;
  std::unique_ptr<PrimitiveRecursiveFunction> function;
};

/**
 * @brief Registry that manages available primitive recursive functions.
 */
class FunctionRegistry {
 public:
  /**
   * @brief Register a new function in the registry.
   * @param name Function name (identifier)
   * @param description Human-readable description
   * @param function The primitive recursive function
   */
  void RegisterFunction(const std::string& name, 
                       const std::string& description,
                       std::unique_ptr<PrimitiveRecursiveFunction> function);

  /**
   * @brief Get a function by name.
   * @param name Function name
   * @return Pointer to function, or nullptr if not found
   */
  auto GetFunction(const std::string& name) const -> const PrimitiveRecursiveFunction*;

  /**
   * @brief Get function information by name.
   * @param name Function name
   * @return Pointer to FunctionInfo, or nullptr if not found
   */
  auto GetFunctionInfo(const std::string& name) const -> const FunctionInfo*;

  /**
   * @brief Get all registered function names.
   * @return Vector of function names
   */
  auto GetAllFunctionNames() const -> std::vector<std::string>;

  /**
   * @brief Get number of registered functions.
   * @return Count of functions
   */
  auto Size() const -> size_t;

 private:
  std::map<std::string, FunctionInfo> functions_;
};

#endif  // FUNCTION_REGISTRY_H
