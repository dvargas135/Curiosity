#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "airport.h"

int main() {
    std::string airports_file = "../aeropuertos.csv";

    std::unordered_map<std::string, int> airports_index;

    std::vector<Airport> airports;

    std::ifstream infile(airports_file);

    if (infile.is_open()) {
        std::string line;

        std::getline(infile, line);

        while (std::getline(infile, line)) {
            std::stringstream ss(line);
            std::string city, code;
            double latitude, longitude;

            std::getline(ss, city, ',');
            std::getline(ss, code, ',');
            ss >> latitude;
            ss.ignore();
            ss >> longitude;

            Airport airport(city, code, latitude, longitude);
            airports.push_back(airport);

            airports_index[code] = airports.size() - 1;
        }
        infile.close();
    } else {
        std::cerr << "Unable to open file: " << airports_file << std::endl;
    }

    int index_of_ABE_airport = airports_index["ABE"];
    Airport ABE_airport = airports[index_of_ABE_airport];
    std::cout << ABE_airport.getCity() << std::endl;

    return 0;
}