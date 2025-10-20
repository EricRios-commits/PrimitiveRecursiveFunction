/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Interactive menu system for primitive recursive functions.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef INTERACTIVE_MENU_H
#define INTERACTIVE_MENU_H

#include <string>
#include <vector>
#include "interactive/function_registry.h"

/**
 * @brief Interactive menu for executing primitive recursive functions.
 * 
 * Provides a user-friendly interface for selecting and executing
 * registered primitive recursive functions.
 */
class InteractiveMenu {
 public:
  /**
   * @brief Construct an interactive menu with a function registry.
   * @param registry Reference to the function registry
   */
  explicit InteractiveMenu(FunctionRegistry& registry);

  /**
   * @brief Run the interactive menu loop.
   */
  void Run();

 private:
  /**
   * @brief Display all available functions.
   */
  void DisplayFunctions() const;

  /**
   * @brief Execute a selected function.
   * @param function_name Name of the function to execute
   */
  void ExecuteFunction(const std::string& function_name);

  /**
   * @brief Read a vector of unsigned integers from user input.
   * @param count Number of values to read
   * @return Vector of input values
   */
  auto ReadInputs(size_t count) const -> std::vector<unsigned>;

  /**
   * @brief Read a single unsigned integer with validation.
   * @param prompt Prompt to display
   * @return The validated unsigned integer
   */
  auto ReadUnsigned(const std::string& prompt) const -> unsigned;

  FunctionRegistry& registry_;
};

#endif  // INTERACTIVE_MENU_H
