#include <iostream>
#include <string>
#include <type_traits>

constexpr int EDAD_LIMITE = 18;
constexpr bool MODO_DEBUG = true;

enum class Opcion { INICIAR = 1, CONFIGURAR, SALIR };

struct Usuario {
    std::string nombre;
    int edad;
    bool activo;
};

void procesarOpcion(int op) {
    switch (op) {
        case 1: std::cout << "Iniciando...\n"; break;
        case 2: std::cout << "Configurando...\n"; break;
        case 3: std::cout << "Saliendo...\n"; break;
        default: std::cout << "Inválido\n";
    }
}

std::string verificarEdad(int edad) {
    return (edad >= EDAD_LIMITE) ? "Mayor de edad" : "Menor de edad";
}

template<typename T>
auto calcular(T a, T b) {
    if constexpr (std::is_integral_v<T>) {
        return a + b;
    } else {
        return a * b;
    }
}

int main() {
    Usuario u{"Ana", 25, true};
    
    if (u.activo && u.edad >= EDAD_LIMITE) {
        std::cout << verificarEdad(u.edad) << "\n";
        procesarOpcion(1);
    }
    
    if constexpr (MODO_DEBUG) {
        std::cout << "Debug: " << calcular(5, 3) << "\n";
    }
    
    return 0;
}