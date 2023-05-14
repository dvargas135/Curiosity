#include "Util.hpp"

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

std::pair<Airport*, int> searchAirportByCode(const std::unordered_map<int, Airport*>& airports, const std::string& code) {
    int index = -1;
    Airport* airport = nullptr;

    for (const auto& p : airports) {
        if (p.second->code == code) {
            index = p.first;
            airport = p.second;
            break;
        }
    }
    return std::make_pair(airport, index);
}

std::unordered_map<int, Airport*> read_airports() {
    std::unordered_map<int, Airport*> airports;

    std::ifstream file("../aeropuertos.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open aeropuertos.csv" << std::endl;
        return airports;
    }

    std::string line;
    int index = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, code;
        double latitude, longitude;
        if (!(std::getline(iss, name, ',') &&
                std::getline(iss, code, ',') &&
                (iss >> latitude) &&
                (iss.ignore() &&
                (iss >> longitude)))) {
            std::cerr << "Failed to parse line: " << line << std::endl;
            continue;
        }
        Airport* obj = new Airport(name, code, latitude, longitude);
        airports[index++] = obj;

        //delete airport object in the map reminder
    }
    file.close();
    return airports;
}

std::vector<Flight*> read_flights(std::unordered_map<int, Airport*>& airports) {
    std::vector<Flight*> flights;
    
    std::ifstream file("../vuelos.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open vuelos.csv" << std::endl;
        return flights;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string source_code, dest_code;
        double avg_time, price;
        if (!(std::getline(iss, source_code, ',') &&
                std::getline(iss, dest_code, ',') &&
                (iss >> avg_time) &&
                (iss.ignore() &&
                (iss >> price)))) {
            std::cerr << "Failed to parse line: " << line << std::endl;
            continue;
        }

        auto src = searchAirportByCode(airports, source_code);
        Airport* source = src.first;

        auto dst = searchAirportByCode(airports, dest_code);
        Airport* dest = dst.first;

        if (source == nullptr || dest == nullptr) {
            std::cerr << "Error: could not find source or destination airport for line \"" << line << "\"" << std::endl;
            continue;
        }

        Flight* new_flight = new Flight;
        new_flight->source = source;
        new_flight->dest = dest;
        new_flight->avg_time = avg_time;
        new_flight->price = price;
        flights.push_back(new_flight);

        // delete new_flight reminder
    }
    file.close();
    return flights;
}

void nate(std::vector<Airport*> v) {
    for (int i = 0; i  < v.size(); i++) {
        std::cout << v[i]->code;
        if (i != v.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

bool file_exists(const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

bool file_is_empty(std::ifstream& pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}