#include <iostream>
#include <fstream>
using namespace std;

struct Datas{
    int IR;
    int IR_point_num;
    char type[2];
    int num;
    int ROW_num;
    float x;
    float y;
};

int main()
{
    ifstream archivo("datos.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error opening the file" << std::endl;
        return 1; // Exit with a error code
    }

    string nombre;
    int edad;

    // Lee datos desde el archivo
    while (archivo >> nombre >> edad) {
        // Procesa los datos leídos
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << std::endl;
    }

    // Cierra el archivo después de su uso
    archivo.close();

    return 0;    
}