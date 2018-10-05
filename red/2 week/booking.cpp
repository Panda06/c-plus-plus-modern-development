#include <iomanip>
#include <iostream>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <cstdint>
#include <vector>
#include <utility>

struct Client {
    int rooms;
    int id;
};
class Booking {
public:
    int get_client_count(std::string hotel_name) {
        std::set<int> id;
        if (clients.count(hotel_name)) {
            for (auto it = clients[hotel_name].upper_bound(_time-day_seconds);
                 it != clients[hotel_name].end(); ++it) {
                     id.insert(it->second.id);
                 }
        }
        return id.size();
    }
    int get_room_count(std::string hotel_name) {
        int rooms = 0;
        if (clients.count(hotel_name)) {
            for (auto it = clients[hotel_name].upper_bound(_time-day_seconds);
                 it != clients[hotel_name].end(); ++it) {
                     rooms += it->second.rooms;
                 }
        }
        return rooms;
    }
    void Add(std::string hotel_name, int64_t time, int id, int c_rooms) {
        _time = time;
        clients[hotel_name].insert({ time,  { c_rooms, id } });
    }
private:
    std::map<std::string, std::multimap<int64_t, Client>> clients;
    int64_t _time;
    int day_seconds = 86400;
};

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Booking b;
    uint64_t n = 0;
    std::cin >> n;
    for (uint64_t i = 0; i < n; ++i) {
        std::string command;
        std::string hotel_name;
        std::cin >> command;
        if (command == "BOOK") {
            std::string hotel_name;
            int64_t time;
            int client_id, rooms;
            std::cin >> time >> hotel_name >> client_id >> rooms;
            b.Add(hotel_name, time, client_id, rooms);
        } else if (command == "CLIENTS"){
            std::cin >> hotel_name;
            std::cout << b.get_client_count(hotel_name) << '\n';
        } else if (command == "ROOMS") {
            std::cin >> hotel_name;
            std::cout << b.get_room_count(hotel_name) << '\n';
        }
    }
    return 0;
}
