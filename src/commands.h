#include <string>
#include <map>

void cargar_comandos(std::string);
void cargar_elementos(std::string);
void agregar_movimiento(std::string, std::string, std::string);
void agregar_analisis(std::string, std::string, std::string);
void agregar_elemento(std::string, std::string, std::string, std::string, std::string);
void guardar(std::string, std::string);
void simular_comandos(std::string, std::string);
void ubicar_elementos();
void en_cuadrante(std::string, std::string, std::string, std::string);
void crear_mapa(std::string);
void ruta_mas_larga();
void ayuda(std::map<std::string, int>, std::string);