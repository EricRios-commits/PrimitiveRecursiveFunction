/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad computacional
 *
 *
 * @brief Header file for the PrimitiveRecursiveFunction class.
 * @author Eric Ríos Hamilton
 * @date 20-10-2025
 */

#ifndef PRIMITIVE_RECURSIVE_FUNCTION_H
#define PRIMITIVE_RECURSIVE_FUNCTION_H

template <typename Type>
class PrimitiveRecursiveFunction {
 public:
  virtual auto Run(Type input) -> Type;

 private:
  auto BaseCase(Type input) -> Type;
  auto RecursiveCase(Type input, Type successor) -> Type;
};

#endif  // PRIMITIVE_RECURSIVE_FUNCTION_H