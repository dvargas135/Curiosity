#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

#include "./commands/en_cuadrante.hpp"
#include "./classes/command.hpp"
#include "./classes/system.hpp"
#include "./commands/ayuda.hpp"
#include "./commands/cargar.hpp"
#include "./commands/agregar.hpp"
#include "./commands/guardar.hpp"
#include "./commands/simular_comandos.hpp"
#include "./commands/ubicar_elementos.hpp"

int main() {
    System sys;
    bool entro=false;
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
    };
    
    std::string cmd;

    do {
        printf("$ ");
        getline(std::cin, cmd);

        if (cmd.empty()) {
            printf("Comando no encontrado! Intente nuevamente.\n");
            break;
        }

        std::stringstream sstream(cmd);
        std::string s;
        std::vector<std::string> seglist;
            
        while (std::getline(sstream, s, ' ')) {
            seglist.push_back(s);
        }

        std::vector<std::string>::iterator it;
        it = seglist.begin();

        size_t args = seglist.size() - 1;

        switch (cmd_map[*(it+0)]) {
            case 1: {
                if (args != 1) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                cargar_comandos(*(it+1), sys);
                break;
            }
            case 2:
                if (args != 1) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                cargar_elementos(*(it+1), sys);
                break;
            case 3:
                if (args != 3) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                agregar_movimiento(*(it+1), *(it+2), *(it+3), sys);
                break;
            case 4:
                if (args != 3) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                agregar_analisis(*(it+1), *(it+2), *(it+3), sys);
                break;
            case 5:
                if (args != 5) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                agregar_elemento(*(it+1), *(it+2), *(it+3), *(it+4), *(it+5), sys);
                break;
            case 6:
                if (args != 2) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                guardar(*(it+1), *(it+2), sys);
                break;
            case 7:
                if (args != 3) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                simular_comandos(*(it+1), *(it+2), *(it+3), sys);
                break;
            case 8:
                printf("\n\nTerminando proceso...\n");
                return 0;
            case 9:
                if (args != 0) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                ubicar_elementos(sys);
                break;
            case 10:
                if (args != 4 || entro!=true) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
             /*
                en_cuadrante(*(it+1), *(it+2), *(it+3), *(it+4));*/
                break;
            case 11:
                if (args != 1) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                //crear_mapa(*(it+1));
                break;
            case 12:
                if (args != 0) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                //ruta_mas_larga();
                break;
            case 13:
                if (args != 1) {
                    ayuda(cmd_map, *(it+0));
                    break;
                }
                ayuda(cmd_map, *(it+1));
                break;
            default:
                printf("Comando no encontrado! Intente nuevamente.\n");
                break;
        }
    } while (true);
    
    return 0;
}
