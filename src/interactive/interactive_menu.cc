/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 * @brief Implementation of InteractiveMenu class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#include "interactive/interactive_menu.h"
#include <iostream>
#include <limits>
#include <iomanip>

InteractiveMenu::InteractiveMenu(FunctionRegistry& registry)
    : registry_(registry) {}

void InteractiveMenu::Run() {
  std::string command;
  
  std::cout << "Primitive Recursive Functions\n";
  DisplayFunctions();
  std::cout << "Type 'help' for commands.\n";
    
  while (true) {
    std::cout << "> ";
    std::getline(std::cin, command);
    
    if (command.empty()) {
      continue;
    }
    
    if (command == "quit" || command == "q" || command == "exit") {
      break;
    } else if (command == "list" || command == "l") {
      DisplayFunctions();
    } else if (command == "stats" || command == "s") {
      DisplayCallStats();
    } else if (command == "reset" || command == "r") {
      ResetCallStats();
      std::cout << "Call counters reset\n";
    } else if (command == "help" || command == "h") {
      std::cout << "\nCommands:\n";
      std::cout << "  list    - List available functions\n";
      std::cout << "  stats   - Show call statistics\n";
      std::cout << "  reset   - Reset call counters\n";
      std::cout << "  help    - Show this help\n";
      std::cout << "  quit    - Exit\n";
      std::cout << "  <name>  - Execute function\n\n";
    } else {
      ExecuteFunction(command);
    }
  }
}

void InteractiveMenu::DisplayFunctions() const {
  auto names = registry_.GetAllFunctionNames();
  
  if (names.empty()) {
    std::cout << "No functions registered.\n";
    return;
  }
  
  std::cout << "\nAvailable functions:\n";
  for (const auto& name : names) {
    auto info = registry_.GetFunctionInfo(name);
    if (info) {
      std::cout << "  " << name << " (" << info->arity << ") - " << info->description << "\n";
    }
  }
  std::cout << "\n";
}

void InteractiveMenu::ExecuteFunction(const std::string& function_name) {
  auto info = registry_.GetFunctionInfo(function_name);
  
  if (!info) {
    std::cout << "Error: function '" << function_name << "' not found\n";
    return;
  }
  
  auto inputs = ReadInputs(info->arity);
  
  try {
    info->function->ResetCallCount();
    unsigned result = info->function->Run(inputs);
    unsigned long calls = info->function->GetCallCount();
    
    std::cout << function_name << "(";
    for (size_t i = 0; i < inputs.size(); ++i) {
      std::cout << inputs[i];
      if (i < inputs.size() - 1) std::cout << ", ";
    }
    std::cout << ") = " << result;
    std::cout << " [" << calls << " calls]\n";
    
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << "\n";
  }
}

auto InteractiveMenu::ReadInputs(size_t count) const -> std::vector<unsigned> {
  std::vector<unsigned> inputs;
  inputs.reserve(count);
  
  for (size_t i = 0; i < count; ++i) {
    std::string prompt = "Enter argument " + std::to_string(i + 1) + ": ";
    inputs.push_back(ReadUnsigned(prompt));
  }
  
  return inputs;
}

auto InteractiveMenu::ReadUnsigned(const std::string& prompt) const -> unsigned {
  while (true) {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    
    try {
      if (!input.empty() && input[0] == '-') {
        throw std::invalid_argument("negative");
      }
      
      size_t pos;
      unsigned long value = std::stoul(input, &pos);
      
      if (pos != input.length()) {
        throw std::invalid_argument("invalid format");
      }
      
      if (value > std::numeric_limits<unsigned>::max()) {
        throw std::out_of_range("too large");
      }
      
      return static_cast<unsigned>(value);
      
    } catch (const std::exception&) {
      std::cout << "Invalid input\n";
    }
  }
}

void InteractiveMenu::DisplayCallStats() const {
  auto names = registry_.GetAllFunctionNames();
  
  if (names.empty()) {
    std::cout << "No functions registered.\n";
    return;
  }
  
  std::cout << "\nCall statistics:\n";
  for (const auto& name : names) {
    auto info = registry_.GetFunctionInfo(name);
    if (info) {
      unsigned long calls = info->function->GetCallCount();
      std::cout << "  " << name << ": " << calls << " calls\n";
    }
  }
  std::cout << "\n";
}

void InteractiveMenu::ResetCallStats() {
  auto names = registry_.GetAllFunctionNames();
  for (const auto& name : names) {
    auto info = registry_.GetFunctionInfo(name);
    if (info) {
      info->function->ResetCallCount();
    }
  }
}
