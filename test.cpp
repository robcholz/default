#include "include/default/default.hpp"

#include <cassert>

int main() {
  static_assert(rb::default_value<int>::value() == 0);
  static_assert(rb::default_value<float>::value() == 0.f);
  static_assert(rb::default_value<double>::value() == 0.);
  static_assert(rb::default_value<char>::value() == 0);
  static_assert(rb::default_value<const char *>::value() == nullptr);
  static_assert(rb::default_value<std::string>::value().empty());
  static_assert(rb::default_value<std::wstring>::value().empty());
  static_assert(rb::default_value<std::string_view>::value().empty());
  static_assert(rb::default_value<std::u8string>::value().empty());
  static_assert(rb::default_value<std::u16string>::value().empty());
  static_assert(rb::default_value<std::u32string>::value().empty());
  assert(rb::default_value<std::list<int>>::value().empty());
  assert(rb::default_value<std::forward_list<int>>::value().empty());
  assert(rb::default_value<std::initializer_list<int>>::value().empty());

  return 0;
}
