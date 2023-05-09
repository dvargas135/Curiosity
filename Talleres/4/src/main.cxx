#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "airport.h" // assume Airport class is defined in Airport.h header file

int main() {
    std::string airports_file = "../aeropuertos.csv";

    // Create an unordered map to store the index of each airport in the airports vector
    std::unordered_map<std::string, int> airports_index;

    // Create a vector to store all the airports
    std::vector<Airport> airports;

    std::ifstream infile(airports_file);

    if (infile.is_open()) {
        std::string line;

        // Read the header line
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

            // Create an Airport object and add it to the airports vector
            Airport airport(city, code, latitude, longitude);
            airports.push_back(airport);

            // Add the index of the airport to the airports_index map
            airports_index[code] = airports.size() - 1;
        }
        infile.close();
    } else {
        std::cerr << "Unable to open file: " << airports_file << std::endl;
    }

    // Now airports_index map should have all the entries from airports.csv
    // We can access the index of an airport using its code as the key, like this:
    int index_of_ABE_airport = airports_index["ABE"];
    Airport ABE_airport = airports[index_of_ABE_airport];
    std::cout << ABE_airport.getCity() << std::endl;


    return 0;
}