#pragma once

#include <string_view>

// return the first match, or std::string_view::npos if there is no match
// an empty pattern matches at index 0
std::size_t naive_search(std::string_view text, std::string_view pattern);
std::size_t kmp_search(std::string_view text, std::string_view pattern);
