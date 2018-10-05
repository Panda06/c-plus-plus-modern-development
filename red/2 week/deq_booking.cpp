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
    int64_t time;
    std::string hotel_name;
    int rooms;
    int id;
};

class Booking {
public:
    int get_client_count(std::string hotel_name) {
        std::set<int> id;
        for (auto it = clients.begin(); it != clients.end(); ++it) {
            if (hotel_name == it->hotel_name) {
                id.insert(it->id);
            }
        }
        return id.size();
    }
    int get_room_count(std::string hotel_name) {
        int rooms = 0;
        for (auto it = clients.begin(); it != clients.end(); ++it) {
            if (hotel_name == it->hotel_name) {
                rooms += it->rooms;
            }
        }
        return rooms;
    }
    void Add(std::string hotel_name, int64_t time, int id, int c_rooms) {
        while (!clients.empty() && clients.front().time <= (time-day_seconds)) {
            clients.pop_front();
        }
        clients.push_back({time, hotel_name, c_rooms, id});
    }
private:
    std::deque<Client> clients;
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
