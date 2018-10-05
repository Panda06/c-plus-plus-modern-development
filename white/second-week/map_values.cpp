set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> values;
    for (auto& item: m) {
        values.insert(item.second);
    }
    return values;
}
