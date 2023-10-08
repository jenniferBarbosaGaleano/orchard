#include <iostream>
#include <fstream>
#include <C:\compartida\orchard\json.hpp>

using json = nlohmann::json;

int main() {
    // Nombre del archivo JSON
    std::string filename = "IncrementalRoutes.json";

    // Abrir el archivo JSON
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo JSON." << std::endl;
        return 1;
    }

    // Leer el contenido del archivo JSON en un objeto JSON
    json jsonData;
    file >> jsonData;

    // Cerrar el archivo
    file.close();

    // Verificar si el JSON es un arreglo
    if (jsonData.is_array()) {
        // Iterar a través de los objetos en el arreglo
        for (const auto& jsonObject : jsonData) {
            int irNumber = jsonObject["IR Number"];
            int irPointNum = jsonObject["IR Point Num"];
            std::string pointType = jsonObject["Point Type"];
            int pointNum = jsonObject["Point Num"];
            int rowNum = jsonObject["Row Num"];
            int localX = jsonObject["Local X"];
            int localY = jsonObject["Local Y"];
            double gpsLat = jsonObject["GPS lat"];
            double gpsLong = jsonObject["GPS long"];
            std::string north = ""; // Valor predeterminado si no se encuentra "North"
            if (jsonObject.find("North") != jsonObject.end()) {
                north = jsonObject["North"];
            }
            std::string south = ""; // Valor predeterminado si no se encuentra "South"
            if (jsonObject.find("South") != jsonObject.end()) {
                south = jsonObject["South"];
            }
            std::string east = ""; // Valor predeterminado si no se encuentra "East"
            if (jsonObject.find("East") != jsonObject.end()) {
                east = jsonObject["East"];
            }
            std::string west = ""; // Valor predeterminado si no se encuentra "West"
            if (jsonObject.find("West") != jsonObject.end()) {
                west = jsonObject["West"];
            }
            std::string operations = jsonObject["operations"];

            // Realizar operaciones con los datos, por ejemplo, imprimirlos
            std::cout << "IR Number: " << irNumber << std::endl;
            std::cout << "IR Point Num: " << irPointNum << std::endl;
            std::cout << "Point Type: " << pointType << std::endl;
            std::cout << "rowNum: " << rowNum << std::endl;
            std::cout << "localX: " << localX << std::endl;
            std::cout << "localY: " << localY << std::endl;
            std::cout << "gpsLat: " << gpsLat << std::endl;
            std::cout << "gpsLong: " << gpsLong << std::endl;
            std::cout << "north: " << north << std::endl;
            std::cout << "South: " << south << std::endl;
            std::cout << "east: " << east << std::endl;
            std::cout << "West: " << west << std::endl;
            std::cout << "operations: " << operations << std::endl;
            // Agregar más campos según sea necesario
        }
    } else {
        std::cerr << "El archivo JSON no contiene un arreglo de objetos." << std::endl;
    }

    return 0;
}
