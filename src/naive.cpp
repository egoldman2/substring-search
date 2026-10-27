#include "search.hpp"

std::size_t naive_search(std::string_view text, std::string_view pattern) {
    if (pattern.size() > text.size()) return std::string_view::npos;

    for (std::size_t start = 0; start <= text.size() - pattern.size(); ++start) {
        std::size_t matched = 0;
        while (matched < pattern.size() && text[start + matched] == pattern[matched]) {
            ++matched;
        }
        if (matched == pattern.size()) return start;
    }
    return std::string_view::npos;
}
