#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include "GraphAdjacencyList.hpp"
#include "Util.hpp"

int main() {
    std::unordered_map<int, Airport*> airports = read_airports();
    std::vector<Flight*> flights = read_flights(airports);

    std::string filename = "command.txt";
    std::string filepath = "../" + filename;
    if (!file_exists(filepath)) {
        printf("%s no se encuentra o no puede leerse.\n", filename.c_str());
        return 0;
    }

    std::ifstream infile(filepath);

    if (file_is_empty(infile)) {
            printf("%s no contiene comandos.\n", filename.c_str());
        return 0;
    }

    const std::string& fastest = "fastest";
    const std::string& cheapest = "cheapest";
    const std::string& shortest = "shortest";

    GraphAdjacencyList<std::string> gTime(flights, airports, fastest);
    gTime.print();
    GraphAdjacencyList<std::string> gPrice(flights, airports, cheapest);
    GraphAdjacencyList<std::string> gDist(flights, airports, shortest);

    // GraphAdjacencyListTime gTime(flights, airports);
    // GraphAdjacencyListPrice gPrice(flights, airports);
    // GraphAdjacencyListDistance gDist(flights, airports);
    // graph.print();

    std::string line;
    while (getline(infile, line)) {
        std::string col1, col2, col3;

        std::stringstream ss(line);
        ss >> col1 >> col2 >> col3;

        if (!(col1 == "camino_rapido" || col1 == "camino_barato" || col1 == "ruta_corta")) {
            printf("Comando incorrecto. Saltando línea: `%s`.\n", line.c_str());
            continue;
        }

        auto source_result = searchAirportByCode(airports, col2);
        auto dest_result = searchAirportByCode(airports, col3);

        if (source_result.second == -1) {
            printf("Aeropuerto de origen no encontrado. Saltando línea: `%s`.\n", line.c_str());
            continue;
        } else if (dest_result.second == -1) {
            printf("Aeropuerto de destino no encontrado. Saltando línea: `%s`.\n", line.c_str());
            continue;
        }

        if (col1 == "camino_rapido") {
            std::vector<Airport*> fastest = gTime.dijkstra(col2, col3);
            printf("%s :: ", line.c_str());
            nate(fastest);
        } else if (col1 == "camino_barato") {
            std::vector<Airport*> cheapest = gPrice.dijkstra(col2, col3);
            printf("%s :: ", line.c_str());
            nate(cheapest);
        } else if (col1 == "ruta_corta") {
            std::vector<Airport*> shortest = gDist.dijkstra(col2, col3);
            printf("%s :: ", line.c_str());
            nate(shortest);
        }    
    }
    infile.close();

    for (auto flight : flights) {
        delete flight;
    }
    
    for (const auto& it : airports) {
        delete it.second;
    }

    exit(1);
    return 0;
}