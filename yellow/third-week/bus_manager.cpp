#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops.insert(make_pair(bus, stops));
    for (const auto& stop : stops) {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    if (stops_to_buses.count(stop) == 0) {
        return BusesForStopResponse{vector<string>{}};
    }
    return BusesForStopResponse{stops_to_buses.at(stop)};
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    vector<pair<string, vector<string>>> res;
    if (buses_to_stops.count(bus)) {
        for (const auto& stop : buses_to_stops.at(bus)) {
            res.push_back(make_pair(stop, stops_to_buses.at(stop)));
        }
    }
    return StopsForBusResponse{bus, res};
}

AllBusesResponse BusManager::GetAllBuses() const {
  return AllBusesResponse{buses_to_stops};
}
