template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    std::vector<T> v;
    for (auto it = begin(elements); it != end(elements); ++it) {
        if (border < *it) {
            v.push_back(*it);
        }
    }
    return v;
}
