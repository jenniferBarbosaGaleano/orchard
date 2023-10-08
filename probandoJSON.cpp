#include <iostream>
#include <fstream>
#include <C:\compartida\orchard\json.hpp>

using json = nlohmann::json;

int main() {
    // Cargar la lista de objetos JSON desde un archivo
    std::ifstream input_file("IncrementalRoutes_copy.json");
    if (!input_file.is_open()) {
        std::cerr << "Error al abrir el archivo JSON." << std::endl;
        return 1;
    }

    json lista_json;
    input_file >> lista_json;
    input_file.close();

    // Definir las condiciones para eliminar una estructura
    std::string clave_condicion = "IR Number";
    int valor_condicion = 3;

    // Crear una nueva lista sin las estructuras que cumplen con la condición
    json lista_actualizada;
    for (auto& elemento : lista_json) {
        if (!(elemento.count(clave_condicion) && elemento[clave_condicion] == valor_condicion)) {
            lista_actualizada.push_back(elemento);
        }
    }

    // Guardar la lista actualizada en un archivo JSON
    std::ofstream output_file("tu_archivo_actualizado.json");
    if (!output_file.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }

    output_file << lista_actualizada.dump(4);  // El 4 indica formato indentado
    output_file.close();

    std::cout << "Estructuras eliminadas y archivo actualizado." << std::endl;

    return 0;
}



