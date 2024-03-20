#pragma once

#ifndef RB_DEFAULT_HPP
#define RB_DEFAULT_HPP

#include <cstdint>
#include <type_traits>
#include <string>
#include <string_view>
#include <list>
#include <array>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <forward_list>
#include <initializer_list>
#include <optional>

namespace rb {

// primitive types

/// @brief returns the default value of T
/// @tparam T the type to get the default value of
/// @return the default value of T
template<typename T, typename = void>
struct default_value {
  using type = T;
  static constexpr type value();
  default_value &operator=(const default_value &) = delete;
  default_value &operator=(default_value &&) = delete;
  default_value(const default_value &) = delete;
  default_value(default_value &&) = delete;
  ~default_value() = delete;
};

/// @brief returns the default value of all integer types
/// @return 0
template<typename T>
struct default_value<T, std::enable_if_t<std::is_integral_v<T>>> {
  using type = T;
  static constexpr type value() {
	return 0;
  }
};

/// @brief returns the default value of all floating point types
/// @return 0.f
template<typename T>
struct default_value<T, std::enable_if_t<std::is_floating_point_v<T>>> {
  using type = T;
  static constexpr type value() {
	return 0.f;
  }
};

/// @brief returns the default value of all pointer types
/// @return nullptr
template<typename T>
struct default_value<T, std::enable_if_t<std::is_pointer_v<T>>> {
  using type = T;
  static constexpr type value() {
	return nullptr;
  }
};

// std

/// @brief returns the default value of std::string, its variants and std::string_view
/// @return ""
template<typename T>
struct default_value<T, std::enable_if_t<std::disjunction_v<
	std::is_same<T, std::string>,
	std::is_same<T, std::wstring>,
	std::is_same<T, std::u8string>,
	std::is_same<T, std::u16string>,
	std::is_same<T, std::u32string>,
	std::is_same<T, std::string_view>
>>> {
  using type = T;
  static constexpr type value() {
	return type{};
  }
};

// list

/// @brief returns the default value of std::list
/// @return std::list<typename T::value_type>{}, an empty list
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::list<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::list<typename T::value_type>{};
  }
};

/// @brief returns the default value of std::forward_list
/// @return std::forward_list<typename T::value_type>{}, an empty forward_list
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::forward_list<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::forward_list<typename T::value_type>{};
  }
};

/// @brief returns the default value of std::initializer_list
/// @return std::initializer_list<typename T::value_type>{}, an empty initializer list
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::initializer_list<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::initializer_list<typename T::value_type>{};
  }
};

// array

/// @brief returns the default value of std::array
/// @return std::array<typename T::value_type, T::size()>{}, an empty array
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::array<typename T::value_type, T::size()>>>> {
  using type = T;
  static constexpr type value() {
	return std::array<typename T::value_type, T::size()>{};
  }
};

// vector

/// @brief returns the default value of std::vector
/// @return std::vector<typename T::value_type>{}, an empty vector
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::vector<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::vector<typename T::value_type>{};
  }
};

// queue

/// @brief returns the default value of std::queue
/// @return std::queue<typename T::value_type>{}, an empty queue
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::queue<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::queue<typename T::value_type>{};
  }
};

// deque

/// @brief returns the default value of std::deque
/// @return std::deque<typename T::value_type>{}, an empty deque
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::deque<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::deque<typename T::value_type>{};
  }
};

// stack

/// @brief returns the default value of std::stack
/// @return std::stack<typename T::value_type>{}, an empty stack
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::stack<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::stack<typename T::value_type>{};
  }
};

// map

/// @brief returns the default value of std::map
/// @return std::map<typename T::key_type, typename T::mapped_type>{}, an empty map
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::map<typename T::key_type, typename T::mapped_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::map<typename T::key_type, typename T::mapped_type>{};
  }
};

/// @brief returns the default value of std::multimap
/// @return std::multimap<typename T::key_type, typename T::mapped_type>{}, an empty multimap
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::multimap<typename T::key_type, typename T::mapped_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::multimap<typename T::key_type, typename T::mapped_type>{};
  }
};

/// @brief returns the default value of std::unordered_map
/// @return std::unordered_map<typename T::key_type, typename T::mapped_type>{}, an empty unordered_map
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::unordered_map<typename T::key_type, typename T::mapped_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::unordered_map<typename T::key_type, typename T::mapped_type>{};
  }
};

/// @brief returns the default value of std::unordered_multimap
/// @return std::unordered_multimap<typename T::key_type, typename T::mapped_type>{}, an empty unordered_multimap
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::unordered_multimap<typename T::key_type, typename T::mapped_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::unordered_multimap<typename T::key_type, typename T::mapped_type>{};
  }
};

// set

/// @brief returns the default value of std::set
/// @return std::set<typename T::value_type>{}, an empty set
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::set<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::set<typename T::value_type>{};
  }
};

/// @brief returns the default value of std::multiset
/// @return std::multiset<typename T::value_type>{}, an empty multiset
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::multiset<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::multiset<typename T::value_type>{};
  }
};

/// @brief returns the default value of std::unordered_set
/// @return std::unordered_set<typename T::value_type>{}, an empty unordered_set
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::unordered_set<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::unordered_set<typename T::value_type>{};
  }
};

/// @brief returns the default value of std::unordered_multiset
/// @return std::unordered_multiset<typename T::value_type>{}, an empty unordered_multiset
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::unordered_multiset<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::unordered_multiset<typename T::value_type>{};
  }
};

// optional

/// @brief returns the default value of std::optional
/// @return the default value of T::value_type wrapped in std::optional
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, std::optional<typename T::value_type>>>> {
  using type = T;
  static constexpr type value() {
	return std::make_optional<typename T::value_type>(default_value<typename T::value_type>::value());
  }
};

}

#endif //RB_DEFAULT_HPP
