#include <map>
#include <string>
#include <queue>

class Cmds {
    public:
        std::queue<std::vector<std::string>> getCommands() const;
        void setCommands(const std::queue<std::vector<std::string>>& c);
        void addCommand(const std::vector<std::string>& v);
    private:
        std::queue<std::vector<std::string>> commands;
};

class Elmts {
    public:
        std::queue<std::vector<std::string>> getElements() const;
        void setElements(const std::queue<std::vector<std::string>>& e);
        void addElement(const std::vector<std::string>& v);
    private:
        std::queue<std::vector<std::string>> elements;
};

void cargar_comandos(std::string, Cmds&);
void cargar_elementos(std::string, Elmts&);
void agregar_movimiento(std::string, std::string, std::string, Cmds&);
void agregar_analisis(std::string, std::string, std::string, Cmds&);
void agregar_elemento(std::string, std::string, std::string, std::string, std::string, Elmts&);
void guardar(std::string, std::string, Cmds&, Elmts&);
void simular_comandos(std::string, std::string);
void ubicar_elementos();
void en_cuadrante(std::string, std::string, std::string, std::string);
void crear_mapa(std::string);
void ruta_mas_larga();
void ayuda(std::map<std::string, int>, std::string);
void simular(std::string, std::string, std::string, Cmds&);