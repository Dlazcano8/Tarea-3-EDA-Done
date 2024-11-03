#include "trees/avl.hpp"
#include <iostream>
#include <string>
#include <fstream>

#include <chrono>

int* readKeysFromFile(std::string filename, int* n_keys){
    std::ifstream  fin(filename, std::ios::binary); 
    char* val = new char[4];
    int n = 0;
    fin.read(val, 4);
    while (!fin.eof()){
        n = n + 1;        
        fin.read(val, 4);
    }
    fin.close();
    fin.open(filename, std::ios::binary); 
    int* keys = new int[n];
    for(int i=0; i < n; i++){
        fin.read(val, 4);
        keys[i] = *reinterpret_cast<int*>(val);
    }
    fin.close();
    *n_keys = n;
    delete[] val;
    return keys;
}


int main(int nargs, char** vargs){

	if (nargs < 2) {
        std::cerr << "Uso: " << vargs[0] << " <archivo.bin>" << std::endl;
        return 1;
    }

	std::string filename = vargs[1];
    int n_keys; // Variable para almacenar el número de claves

    int* keys = readKeysFromFile(filename, &n_keys);

	    if (keys != nullptr) {
        trees::AVL* tree = new trees::AVL();

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < n_keys; i++) {
            tree->insert(keys[i]);
        }

        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::cout << "Tiempo de inserción: " << duration.count() << " ms" << std::endl;

        // Liberar la memoria asignada
        delete[] keys;
        delete tree;
    } else {
        std::cerr << "Error al leer el archivo." << std::endl;
    }


	return 0;
}
