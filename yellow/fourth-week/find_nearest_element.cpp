
set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
    const auto it = numbers.lower_bound(border);
    if (it == begin(numbers)) {
        return it;
    }
    const auto it2 = prev(it);
    if (it == end(numbers)) {
        return it2;
    }
    const auto nearest = (border - *it2 <= *it - border);
    return nearest ? it2 : it;
    }
