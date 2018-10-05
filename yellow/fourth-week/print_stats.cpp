void PrintStats(vector<Person> persons) {
    std::cout << "Median age = "
              << ComputeMedianAge(begin(persons), end(persons)) << '\n';
    auto it = partition(begin(persons), end(persons),
                        [](const Person person) {
                            return person.gender == Gender::FEMALE;});
    std::cout << "Median age for females = "
              << ComputeMedianAge(begin(persons), it) << '\n';
    std::cout << "Median age for males = "
              << ComputeMedianAge(it, end(persons)) << '\n';

    auto it2 = partition(begin(persons), it,
                        [](const Person person) {
                           return person.is_employed;});
    std::cout << "Median age for employed females = "
              << ComputeMedianAge(begin(persons), it2) << '\n';
    std::cout << "Median age for unemployed females = "
              << ComputeMedianAge(it2, it) << '\n';

    auto it3 = partition(it, end(persons),
                        [](const Person person) {
                           return person.is_employed;});
    std::cout << "Median age for employed males = "
              << ComputeMedianAge(it, it3) << '\n';
    std::cout << "Median age for unemployed males = "
              << ComputeMedianAge(it3, end(persons)) << '\n';
}
