#include "guardar.hpp"
#include "../util/util.hpp"
#include "../classes/command.hpp"
#include "../classes/element.hpp"

#include <fstream>
#include <queue>
#include <cstdio>

void guardar(std::string type, std::string filename, System& sys) {
    std::string errorMsg = "La información requerida no está almacenada en memoria.";
    if (type == "comandos") {
        std::string filepath = "textfiles/commands/" + filename;

        if (file_exists(filepath)) {
            printf("%s ya existe!", filename.c_str());
            return;
        }
        
        std::ofstream outfile(filepath);
        std::queue<Command*> command_list = sys.getCommands();

        if (command_list.empty()) { printf("%s\n", errorMsg.c_str()); }

        while (!command_list.empty()) {
            Command* s = command_list.front();
            Movement* m = dynamic_cast<Movement*>(s);
            Analysis* a = dynamic_cast<Analysis*>(s);
            if (m != nullptr) {
                outfile << m->getMovementType() << " " << m->getMagnitude() << " " << m->getMeasurementUnit() << "\n";
            } else if (a != nullptr) {
                outfile << a->getAnalysisType() << " " << a->getObject() << " " << a->getComment() << "\n";
            }
            command_list.pop();
        }
        outfile.close();

        printf("La información ha sido guardada en %s\n", filepath.c_str());
    } else if (type == "elementos") {
        std::string filepath = "textfiles/elements/" + filename;

        if (file_exists(filepath)) {
            printf("%s ya existe!", filename.c_str());
            return;
        }
        
        std::ofstream outfile(filepath);
        std::queue<Element> element_list = sys.getElements();

        if (element_list.empty()) { printf("%s\n", errorMsg.c_str()); }

        while (!element_list.empty()) {
            Element e = element_list.front();
            outfile << e.getType() << " " << e.getSize() << " " << e.getMeasurementUnit() << " " << e.getPosition().getX() << " " << e.getPosition().getY() << "\n";
            element_list.pop();
        }
        outfile.close();

        printf("La información ha sido guardada en %s\n", filepath.c_str());
    } else {
        printf("Tipo de archivo inválido\n");
        return;
    }
}