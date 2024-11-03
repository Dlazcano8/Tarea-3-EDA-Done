#include "trees/rb.hpp"
#include "trees/rbNode.hpp"
#include <string>
#include <fstream>
#include <iostream>

#include <chrono>

using namespace std;

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


int main(int nargs, char** vargs) {
    if (nargs < 2) {
        std::cerr << "Uso: " << vargs[0] << " <archivo.bin>" << std::endl;
        return 1;
    }

    std::string filename = vargs[1];
    int n_keys; // Variable para almacenar el número de claves

    int* keys = readKeysFromFile(filename, &n_keys);

    if (keys != nullptr) {
        trees::RB* tree = new trees::RB();

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

// int main(){

//     trees::RB* tree = new trees::RB();

//     tree->insert(42);
//     tree->insert(15);
//     tree->insert(70);
//     tree->insert(5);
//     tree->insert(20);
//     tree->insert(60);
//     tree->insert(80);
//     tree->insert(4);
//     tree->insert(7);
//     tree->insert(18);
//     tree->insert(30);
//     tree->insert(50);
//     tree->insert(65);
//     tree->insert(90);
//     tree->insert(67);

//     tree->insert(69);

//     tree->insert(62);

//     tree->insert(61);

//     // tree->traverse();

//     trees::RBNode* node = nullptr;
//     node = tree->find(67);

//     tree->printInfo(node);

//     tree->printInfo(tree->find(62));

//     delete tree;

//     return 0;
// }
