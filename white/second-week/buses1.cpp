#include <iostream>
#include <map>
#include <string>
#include <vector>

#define NEW_BUS "NEW_BUS"
#define BUSES_FOR_STOP "BUSES_FOR_STOP"
#define STOPS_FOR_BUS "STOPS_FOR_BUS"
#define ALL_BUSES "ALL_BUSES"
#define mapvs std::map<std::string, std::vector<std::string>>

void printAllBuses(mapvs& stops_for_bus) {
    if (stops_for_bus.empty()) {
        std::cout << "No buses" << '\n';
        return;
    }
    for (auto& item: stops_for_bus) {
        std::cout << "Bus " << item.first << ": ";
        for (auto& stop: item.second) {
            std::cout << stop << ' ';
        }
        std::cout << '\n';
    }
}

void printStops(const mapvs& stops_for_bus, const mapvs& buses_for_stop) {
    std::string ibus;
    std::cin >> ibus;
    if (stops_for_bus.count(ibus) == 0) {
        std::cout << "No bus" << '\n';
        return;
    }
    for (auto& stop: stops_for_bus.at(ibus)) {
        std::cout << "Stop " << stop << ": ";
        if (buses_for_stop.at(stop).size() == 1) {
            std::cout << "no interchange" << '\n';
        }
        else {
            for (auto& bus: buses_for_stop.at(stop)) {
                if (bus != ibus) {
                    std::cout << bus << ' ';
                }
            }
            std::cout << std::endl;
        }
    }
}

void printBuses(mapvs& buses_for_stop) {
    std::string stop;
    std::cin >> stop;
    if (buses_for_stop.count(stop) == 0) {
        std::cout << "No stop" << std::endl;
    }
    else {
        auto buses = buses_for_stop[stop];
        for (auto &bus: buses) {
            std::cout << bus << ' ';
        }
    }
}
void addBus (mapvs& buses_for_stop, mapvs& stops_for_bus) {
    std::string bus;
    std::cin >> bus;
    int stop_counts;
    std::cin >> stop_counts;
    if (stops_for_bus.count(bus) == 0) {
        stops_for_bus[bus] = {};
    }
    for (size_t i = 0; i < stop_counts; i++) {
        std::string stop;
        std::cin >> stop;
        stops_for_bus[bus].push_back(stop);
        if (buses_for_stop.count(stop) == 0) {
            buses_for_stop[stop] = {bus};
        }
        else {
            buses_for_stop[stop].push_back(bus);
        }
    }
}
int main(int argc, char const *argv[]) {
    mapvs buses_for_stop;
    mapvs stops_for_bus;
    std::string command;
    int count_commands;
    std::cin >> count_commands;
    for (size_t i = 0; i < count_commands; i++) {
        std::cin >> command;
        if (command == NEW_BUS) {
            addBus(buses_for_stop, stops_for_bus);
        }
        else if (command == BUSES_FOR_STOP) {
            printBuses(buses_for_stop);
        }
        else if (command == STOPS_FOR_BUS) {
            printStops(stops_for_bus, buses_for_stop);
        }
        else if (command == ALL_BUSES) {
            printAllBuses(stops_for_bus);
        }
    }

    return 0;
}
