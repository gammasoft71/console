/// @file
/// @brief Contains xtd::reset_color class.
#pragma once
#include "basic_console.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Represent reset color output manipulator class.
  /// @see xtd::basic_console<Char>::reset_color() method.
  class reset_color final {
  public:
    reset_color() = default;
    
    /// @cond
    template<typename Char>
    friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const reset_color&) {
      if (os.rdbuf() == __get_out_rdbuf<Char>() || os.rdbuf() == __get_err_rdbuf<Char>())
        basic_console<Char>::reset_color();
      return os;
    }
    /// @endcond
  };
}