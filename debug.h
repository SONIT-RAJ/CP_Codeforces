#ifndef DEBUG_H
#define DEBUG_H
#include <bits/stdc++.h>
#include <iostream>
#include <type_traits>
#include <utility>
#include <iterator>
#include <string>

// ------------------ DEBUG HELPERS ------------------
#ifndef ONLINE_JUDGE

// print pair
template<typename T, typename U>
std::ostream& operator<<(std::ostream &os, const std::pair<T,U> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

// detect if a type is iterable (has begin/end), but exclude string
template<typename T, typename = void>
struct is_iterable : std::false_type {};

template<typename T>
struct is_iterable<T, std::void_t<
    decltype(std::begin(std::declval<T>())),
    decltype(std::end(std::declval<T>()))
>> : std::true_type {};

template<>
struct is_iterable<std::string, void> : std::false_type {};

// printing iterable containers
template <typename T>
std::enable_if_t<is_iterable<T>::value, std::ostream&>
print_iterable(std::ostream &os, const T &c) {
    os << '{';
    bool first = true;
    for (const auto &x : c) {
        if (!first) os << ", ";
        first = false;
        os << x;
    }
    return os << '}';
}

// fallback for non-iterables
template <typename T>
std::enable_if_t<!is_iterable<T>::value, std::ostream&>
print_iterable(std::ostream &os, const T &v) {
    return os << v;
}

// generic printer
inline void dbg_out() { std::cerr << '\n'; }

template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    print_iterable(std::cerr, H);
    if (sizeof...(T)) std::cerr << " | ";
    dbg_out(T...);
}

// debug macro
#define de(...) do { \
    std::cerr << "[" << __func__ << ":" << __LINE__ << "] "; \
    std::cerr << #__VA_ARGS__ << " = "; \
    dbg_out(__VA_ARGS__); \
} while(0)

#else
#define de(...)
#endif
// ---------------- END DEBUG HELPERS -----------------

#endif // DEBUG_H
