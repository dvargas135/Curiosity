#include "guardar.h"
#include "../../util/util.h"

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

void guardar(std::string type, std::string fileName, Cmds& c, Elmts& e) {
    if (type == "comandos") {
        std::string filepath = "src/motion_files/movement/" + fileName;

        if (file_exists(filepath)) {
            std::cout << fileName << " ya existe!" << std::endl;
            return;
        }

        std::ofstream outfile(filepath);

        std::queue<std::vector<std::string>> data = c.getCommands();

        if (data.empty()) {
            std::cout << " La información requerida no está almacenada en memoria." << std::endl;
            return;
        }
        
        while (!data.empty()) {
            std::vector<std::string> row = data.front();

            for (std::string column : row) {
                outfile << column << " ";
            }
            outfile << std::endl;
            data.pop();
        }
        outfile.close();

        std::cout << " La información ha sido guardada en " << fileName << "." << std::endl;
    } else if (type == "elementos") {
        std::string filepath = "src/motion_files/analysis/" + fileName;

        if (file_exists(filepath)) {
            std::cout << fileName << " ya existe!" << std::endl;
            return;
        }
        
        std::ofstream outfile(filepath);

        std::queue<std::vector<std::string>> data = e.getElements();

        if (data.empty()) {
            std::cout << " La información requerida no está almacenada en memoria." << std::endl;
            return;
        }
        
        while (!data.empty()) {
            std::vector<std::string> row = data.front();

            for (std::string column : row) {
                outfile << column << " ";
            }
            outfile << std::endl;
            data.pop();
        }
        outfile.close();
    } else {
        std::cout << " tipo de archivo inválido!" << std::endl;
        return;
    }
}