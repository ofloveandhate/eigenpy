/// Copyright (c) 2024, INRIA
///

#ifndef __eigenpy_std_map_hpp__
#define __eigenpy_std_map_hpp__

#include "eigenpy/map.hpp"
#include "eigenpy/deprecated.hpp"
#include <map>

namespace eigenpy {

/**
 * @brief Expose an std::map from a type given as template argument.
 *
 * @param[in] T          Type to expose as std::map<T>.
 * @param[in] Compare    Type for the Compare in std::map<T,Compare,Allocator>.
 * @param[in] Allocator  Type for the Allocator in
 * std::map<T,Compare,Allocator>.
 * @param[in] NoProxy    When set to false, the elements will be copied when
 * returned to Python.
 */
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T> >,
          bool NoProxy = false>
struct StdMapPythonVisitor
    : GenericMapVisitor<std::map<Key, T, Compare, Allocator>, NoProxy> {};

namespace python {
// fix previous mistake (deprecated using-decl)
using ::eigenpy::StdMapPythonVisitor EIGENPY_DEPRECATED;
}  // namespace python
}  // namespace eigenpy

#endif  // ifndef __eigenpy_std_map_hpp__
