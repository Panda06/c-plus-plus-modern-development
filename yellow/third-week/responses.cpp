#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.buses.empty()) {
      os << "No stop" << endl;
  } else {
      for (const auto& bus : r.buses) {
          os << bus << " ";
      }
  }
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if (r.stops_for_bus.empty()) {
      os << "No bus" << endl;
  } else {
      for (const auto& stop_bus : r.stops_for_bus) {
          os << "Stop " << stop_bus.first << ":";
          if (stop_bus.second.size() == 1) {
              os << " no interchange" << endl;
          } else {
              for (const auto& bus : stop_bus.second) {
                  if (bus != r.bus) {
                      os << " " << bus;
                  }
              }
              os << endl;
          }
      }
  }
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.all_buses.empty()) {
      os << "No buses" << endl;
  } else {
      for (const auto& v : r.all_buses) {
          os << "Bus " << v.first << ":";
          for (const auto& stop : v.second) {
              os << " " << stop;
          }
          os << endl;
      }
  }
  return os;
}
