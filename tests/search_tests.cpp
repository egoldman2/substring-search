#include "search.hpp"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std::string_view_literals;
    const auto missing = std::string_view::npos;
    struct Case { std::string_view text, pattern; std::size_t expected; };
    const std::vector<Case> cases = {
        {"ABABABAC", "ABABAC", 2}, {"banana", "ban", 0},
        {"banana", "ana", 1}, {"banana", "nana", 2},
        {"banana", "apple", missing}, {"abc", "abcd", missing},
        {"", "", 0}, {"abc", "", 0}, {"", "a", missing},
        {"AAAAAAAB", "AAAAB", 3}, {"abc\0def"sv, "\0d"sv, 3}
    };
    for (const auto& test : cases) {
        assert(naive_search(test.text, test.pattern) == test.expected);
        assert(kmp_search(test.text, test.pattern) == test.expected);
    }

    // check every short binary string against the standard library
    std::vector<std::string> strings = {""};
    for (std::size_t i = 0; i < strings.size(); ++i) {
        if (strings[i].size() < 6) {
            const auto value = strings[i];
            strings.push_back(value + 'a');
            strings.push_back(value + 'b');
        }
    }
    for (const auto& text : strings) {
        for (const auto& pattern : strings) {
            const auto expected = text.find(pattern);
            assert(naive_search(text, pattern) == expected);
            assert(kmp_search(text, pattern) == expected);
        }
    }
    std::cout << "All search tests passed.\n";
}
