#include "search.hpp"

#include <vector>

std::size_t kmp_search(std::string_view text, std::string_view pattern) {
    if (pattern.empty()) return 0;

    std::vector<std::size_t> lps(pattern.size(), 0);
    for (std::size_t i = 1, length = 0; i < pattern.size();) {
        if (pattern[i] == pattern[length]) {
            lps[i++] = ++length;
        } else if (length > 0) {
            length = lps[length - 1];
        } else {
            lps[i++] = 0;
        }
    }

    for (std::size_t i = 0, matched = 0; i < text.size();) {
        if (text[i] == pattern[matched]) {
            ++i;
            ++matched;
            if (matched == pattern.size()) return i - matched;
        } else if (matched > 0) {
            // keep the longest prefix that is also a suffix
            matched = lps[matched - 1];
        } else {
            ++i;
        }
    }
    return std::string_view::npos;
}
