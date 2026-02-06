// Ejemplo práctico combinando los 3 puntos
#include <vector>
#include <algorithm>
#include <iostream>

void imprimir(int n) { std::cout << "Entero: " << n << "\n"; }
void imprimir(bool b) { std::cout << "Booleano: " << (b ? "true" : "false") << "\n"; }

int main() {
    std::vector<bool> flags = { true, false, true };

    // 1. Sobrecarga funciona correctamente
    imprimir(5);      // Llama a versión int
    imprimir(true);   // Llama a versión bool

    // 2. Tamaño eficiente (1 byte por elemento)
    std::cout << "Size: " << sizeof(bool) << " byte\n";

    // 3. Compatibilidad con algoritmos STL
    bool todos_true = std::all_of(flags.begin(), flags.end(),
        [](bool b) { return b; });
}