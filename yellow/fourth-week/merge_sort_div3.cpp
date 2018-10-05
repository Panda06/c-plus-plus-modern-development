
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    auto dist = distance(range_begin, range_end);
    if (dist < 2 ) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto it = begin(elements) + dist / 3;
    auto it2 = begin(elements) + dist * 2 / 3;

    MergeSort(begin(elements), it);
    MergeSort(it, it2);
    MergeSort(it2, end(elements));

    vector<typename RandomIt::value_type> tmp;

    merge(begin(elements), it, it, it2, back_inserter(tmp));
    merge(begin(tmp), end(tmp), it2, end(elements), range_begin);

}
