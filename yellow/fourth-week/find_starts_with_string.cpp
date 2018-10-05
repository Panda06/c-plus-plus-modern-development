string get_next_prefix(const string& s) {
    auto new_string = s;
    ++new_string[new_string.size()-1];
    return new_string;
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {
        auto left =
             lower_bound(range_begin, range_end, prefix);
        auto right =
             lower_bound(range_begin, range_end, get_next_prefix(prefix));
        return {left, right};
    }
