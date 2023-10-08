#include <iostream>
#include <fstream>
#include <C:\compartida\orchard\json.hpp>
#define MAX 10000
#define MAX_ITEM 100

using json = nlohmann::json;

struct Data
{
    int IR;
    int IR_Point_Num;
    std::string Point_Type;
    int Point_Num;
    int Row_Num;
    float Local_X;
    float Local_Y;
    float gpsLat;
    float gpsLong;
    std::string north;
    std::string south;
    std::string east;
    std::string west;
    std::string operations;
};
int main() {
    Data data_route[MAX];
    Data data_del[MAX_ITEM];
    Data data_new[MAX_ITEM];
    int j = 0, j_del = 0, j_new = 0; 
    // Nombre del archivo JSON
    std::string filename = "updated_data.json"; // Reemplaza con la ruta de tu archivo JSON

    // Abrir el archivo JSON para lectura
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

    // Verificar si el JSON contiene los campos "data", "deletedItems" y "newItems"
    if (jsonData.find("data") != jsonData.end() &&
        jsonData.find("deletedItems") != jsonData.end() &&
        jsonData.find("newItems") != jsonData.end()) {

        // Acceder a los datos dentro de los campos "data", "deletedItems" y "newItems"

        json data = jsonData["data"];
        json deletedItems = jsonData["deletedItems"];
        json newItems = jsonData["newItems"];

        // Puedes acceder a los elementos dentro de cada campo y realizar operaciones según sea necesario

        // Por ejemplo, imprimir los datos de "data"
        std::cout << "\nData:" << std::endl;
        for (const auto& item : data) {
            int irNumber = item["IR Number"];
            data_route[j].IR = irNumber;
            int irPointNum = item["IR Point Num"];
            data_route[j].IR_Point_Num = irPointNum;
            std::string pointType = item["Point Type"];
            data_route[j].Point_Type = pointType;
            int pointNum = item["Point Num"];
            data_route[j].Point_Num = pointNum;
            int rowNum = item["Row Num"];
            data_route[j].Row_Num = rowNum;
            int localX = item["Local X"];
            data_route[j].Local_X = localX;
            int localY = item["Local Y"];
            data_route[j].Local_Y = localY;
            double gpsLat = item["GPS lat"];
            data_route[j].gpsLat = gpsLat;
            double gpsLong = item["GPS long"];
            data_route[j].gpsLong = gpsLong;
            std::string north = ""; // Valor predeterminado si no se encuentra "North"
            if (item.find("North") != item.end()) {
                north = item["North"];
                data_route[j].north = north;
            }
            std::string south = ""; // Valor predeterminado si no se encuentra "South"
            if (item.find("South") != item.end()) {
                south = item["South"];
                data_route[j].south = south;
            }
            std::string east = ""; // Valor predeterminado si no se encuentra "East"
            if (item.find("East") != item.end()) {
                east = item["East"];
                data_route[j].east = east;
            }
            std::string west = ""; // Valor predeterminado si no se encuentra "West"
            if (item.find("West") != item.end()) {
                west = item["West"];
                data_route[j].west = west;
            }
            std::string operations = item["operations"];
            data_route[j].operations = operations;
            j++;

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
        }

        std::cout << "\nDeleted Items:" << std::endl;
        for (const auto& item : deletedItems) {
            int irNumber = item["IR Number"];
            data_del[j_del].IR = irNumber;
            int irPointNum = item["IR Point Num"];
            data_del[j_del].IR_Point_Num = irPointNum;
            std::string pointType = item["Point Type"];
            data_del[j_del].Point_Type = pointType;
            int pointNum = item["Point Num"];
            data_del[j_del].Point_Num = pointNum;
            int rowNum = item["Row Num"];
            data_del[j_del].Row_Num = rowNum;
            int localX = item["Local X"];
            data_del[j_del].Local_X = localX;
            int localY = item["Local Y"];
            data_del[j_del].Local_Y = localY;
            double gpsLat = item["GPS lat"];
            data_del[j_del].gpsLat = gpsLat;
            double gpsLong = item["GPS long"];
            data_del[j_del].gpsLong = gpsLong;
            std::string north = ""; // Valor predeterminado si no se encuentra "North"
            if (item.find("North") != item.end()) {
                north = item["North"];
                data_del[j_del].north = north;
            }
            std::string south = ""; // Valor predeterminado si no se encuentra "South"
            if (item.find("South") != item.end()) {
                south = item["South"];
                data_del[j_del].south = south;
            }
            std::string east = ""; // Valor predeterminado si no se encuentra "East"
            if (item.find("East") != item.end()) {
                east = item["East"];
                data_del[j_del].east = east;
            }
            std::string west = ""; // Valor predeterminado si no se encuentra "West"
            if (item.find("West") != item.end()) {
                west = item["West"];
                data_del[j_del].west = west;
            }
            std::string operations = item["operations"];
            data_del[j_del].operations = operations;
            j_del++;

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
        } 

        std::cout << "\nnewItems:" << std::endl;
        for (const auto& item : newItems) {
            int irNumber = item["IR Number"];
            data_new[j_new].IR = irNumber;
            int irPointNum = item["IR Point Num"];
            data_new[j_new].IR_Point_Num = irPointNum;
            std::string pointType = item["Point Type"];
            data_new[j_new].Point_Type = pointType;
            int pointNum = item["Point Num"];
            data_new[j_new].Point_Num = pointNum;
            int rowNum = item["Row Num"];
            data_new[j_new].Row_Num = rowNum;
            int localX = item["Local X"];
            data_new[j_new].Local_X = localX;
            int localY = item["Local Y"];
            data_new[j_new].Local_Y = localY;
            double gpsLat = item["GPS lat"];
            data_new[j_new].gpsLat = gpsLat;
            double gpsLong = item["GPS long"];
            data_new[j_new].gpsLong = gpsLong;
            std::string north = ""; // Valor predeterminado si no se encuentra "North"
            if (item.find("North") != item.end()) {
                north = item["North"];
                data_new[j_new].north = north;
            }
            std::string south = ""; // Valor predeterminado si no se encuentra "South"
            if (item.find("South") != item.end()) {
                south = item["South"];
                data_new[j_new].south = south;
            }
            std::string east = ""; // Valor predeterminado si no se encuentra "East"
            if (item.find("East") != item.end()) {
                east = item["East"];
                data_new[j_new].east = east;
            }
            std::string west = ""; // Valor predeterminado si no se encuentra "West"
            if (item.find("West") != item.end()) {
                west = item["West"];
                data_new[j_new].west = west;
            }
            std::string operations = item["operations"];
            data_new[j_new].operations = operations;
            j_new++;

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
        }

    //Delete
    int found = 0;
    int i = 0, j = 0;
    while(data_new[i].IR == data_route[i].IR)
    {
        while(data_new[j].IR_Point_Num == data_route[i].IR_Point_Num)
        {
            found =
        }
        j++;
    }
    while(data_route[i].IR == i)
    {
         
    }

        // Realizar operaciones similares para "deletedItems" y "newItems" si es necesario
    } else {
        std::cerr << "El archivo JSON no contiene los campos esperados." << std::endl;
    }

    return 0;
}