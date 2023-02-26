#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "curiosity/commands/commands.h"
//#include "vector/vector.h"
#include "curiosity/curiosity.h"

//Vector position(0.0, 0.0);
Robot curiosity(0.0, 0.0, 0.0);

void init(Cmds&, Elmts&);

int main() {
    Cmds c;
    Elmts e;
    init(c, e);
    
    return 0;
}

void init(Cmds& c, Elmts& e) {
    std::string cmd;
    std::cout<<"$ ";
    getline(std::cin,cmd);

    if (cmd.empty()) {
        std::cout<<"Comando no encontrado! Intente nuevamente."<<std::endl;
        init(c, e);
    }

    std::stringstream sstream(cmd);
    std::string s;
    std::vector<std::string> seglist;
        
    while (std::getline(sstream, s, ' ')) {
        seglist.push_back(s);
    }

    std::vector<std::string>::iterator it;
    it = seglist.begin();
    
    std::map<std::string, int> cmd_map {
        {"cargar_comandos", 1},
        {"cargar_elementos", 2},
        {"agregar_movimiento", 3},
        {"agregar_analisis", 4},
        {"agregar_elemento", 5},
        {"guardar", 6},
        {"simular_comandos", 7},
        {"salir", 8},
        {"ubicar_elementos", 9},
        {"en_cuadrante", 10},
        {"crear_mapa", 11},
        {"ruta_mas_larga", 12},
        {"ayuda", 13},
        {"simular", 14}
    };

    int args = seglist.size() - 1;

    switch (cmd_map[*(it+0)]) {
        case 1: {
            if (args != 1) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            cargar_comandos(*(it+1), c);
            init(c, e);
        }
            
        case 2:
            if (args != 1) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            cargar_elementos(*(it+1), e);
            init(c, e);
        case 3:
            if (args != 3) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            agregar_movimiento(*(it+1), *(it+2), *(it+3), c);
            init(c, e);
        case 4:
            if (args != 3) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            agregar_analisis(*(it+1), *(it+2), *(it+3), c);
            init(c, e);
        case 5:
            if (args != 5) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            agregar_elemento(*(it+1), *(it+2), *(it+3), *(it+4), *(it+5), e);
            init(c, e);
        case 6:
            if (args != 2) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            guardar(*(it+1), *(it+2), c, e);
            init(c, e);
        case 7:
            if (args != 2) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            simular_comandos(*(it+1), *(it+2));
            init(c, e);
        case 8:
            std::cout<<"\n\nTerminando proceso..."<<std::endl;
            return;
        case 9:
            if (args != 0) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            ubicar_elementos();
            init(c, e);
        case 10:
            if (args != 4) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            en_cuadrante(*(it+1), *(it+2), *(it+3), *(it+4));
            init(c, e);
        case 11:
            if (args != 1) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            crear_mapa(*(it+1));
            init(c, e);
        case 12:
            if (args != 0) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            ruta_mas_larga();
            init(c, e);
        case 13:
            if (args != 1) {
                ayuda(cmd_map, *(it+0));
                init(c, e);
            }
            ayuda(cmd_map, *(it+1));
            init(c, e);
        case 14:
            simular(*(it+1), *(it+2), *(it+3), c);
            init(c, e);
        default:
            std::cout<<"Comando no encontrado! Intente nuevamente."<<std::endl;
            init(c, e);
    }
    /*
    while(true) {
        std::vector<std::string> cmds = {"cargar_comandos", "cargar_elementos", "agregar_movimiento", "agregar_analisis", "agregar_elemento", "guardar", "simular_comandos", "salir", "ubicar_elementos", "en_cuadrante", "crear_mapa", "ruta_mas_larga"};

        std::vector<std::string>::iterator it;
        it = seglist.begin();
        if (*(it+0) == "ayuda") {
            if (seglist.size()==1) {
                std::cout<<"Uso: ayuda <comando> \n\nLista comandos: cargar_comandos, cargar_elementos, agregar_movimiento, agregar_analisis, agregar_elemento, guardar, simular_comandos, salir, ubicar_elementos, en_cuadrante, crear_mapa, ruta_mas_larga"<<std::endl;
        }
    }
    */
}