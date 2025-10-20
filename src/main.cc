/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Interactive shell for primitive recursive functions.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include <iostream>
#include <memory>

#include "functions/function_builder.h"
#include "interactive/function_registry.h"
#include "interactive/interactive_menu.h"

/**
 * @brief Initialize the function registry with predefined functions.
 * @param registry Reference to the registry to populate
 */
void InitializeFunctions(FunctionRegistry& registry) {
  registry.RegisterFunction(
      "add",
      "Addition: add(x, y) = x + y",
      FunctionBuilder::BuildAddition()
  );
  
  registry.RegisterFunction(
      "sub",
      "Proper Subtraction: sub(x, y) = max(0, x - y)",
      FunctionBuilder::BuildSubtraction()
  );
  
  registry.RegisterFunction(
      "mult",
      "Multiplication: mult(x, y) = x * y",
      FunctionBuilder::BuildMultiplication()
  );
  
  registry.RegisterFunction(
      "pow",
      "Power: pow(x, y) = x^y",
      FunctionBuilder::BuildPower()
  );
    
  registry.RegisterFunction(
      "pred",
      "Predecessor: pred(x) = max(0, x - 1)",
      FunctionBuilder::BuildPredecessor()
  );
}

int main() {
  FunctionRegistry registry;
  
  // Initialize with predefined functions
  InitializeFunctions(registry);
  
  // Create and run interactive menu
  InteractiveMenu menu(registry);
  menu.Run();
  
  return 0;
}
