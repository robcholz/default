# libdefault

a header only c++ library for setting default values in a rust manner.

## Install

- add `include` directory to your include path.

## Usage

```cpp
#include <default/default.hpp>

struct your_custom_type{
};

namespace rb{
template<typename T>
struct default_value<T, std::enable_if_t<std::is_same_v<T, your_custom_type>>> {
  using type = T;
  static constexpr type value() {
	return your_custom_type{};
  }
};
}

int main() {
  your_custom_type a = rb::default_value<your_custom_type>::value();
  return 0;
}
```

