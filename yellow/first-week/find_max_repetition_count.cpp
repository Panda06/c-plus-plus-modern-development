bool operator < (const Region& lhs, const Region rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
      tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const std::vector<Region>& regions) {
    int res = 0;
    map<Region, int> repetition_count;
    for (const auto& region: regions) {
        ++repetition_count[region];
        res = max(res, repetition_count[region]);
    }
    return res;
}
