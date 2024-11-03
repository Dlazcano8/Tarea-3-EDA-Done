/*
 * abb.cpp
 *
 *  Created on: Sep 2, 2022
 *      Author: jsaavedr
 */

#include "trees/rb.hpp"
#include <iostream>


namespace trees {

RB::RB():root(nullptr) {
	// TODO Auto-generated constructor stub
}

void RB::balance(RBNode* node) {
    // Mientras el nodo no sea la raíz y el color de su padre sea rojo
    while (node != root && node->getParent()->getColor() == NodeColor::RED) {
        // Caso en el que el padre es el hijo izquierdo del abuelo
        if (node->getParent() == node->getGrandparent()->getLeft()) {
            RBNode* uncle = node->getGrandparent()->getRight(); // El tío de `node`

            // Caso 1: El tío es rojo
            if (uncle != nullptr && uncle->getColor() == NodeColor::RED) {
                node->getParent()->setColor(NodeColor::BLACK);
                uncle->setColor(NodeColor::BLACK);
                node->getGrandparent()->setColor(NodeColor::RED);
                node = node->getGrandparent();
            } else {
                // Caso 2: `node` es el hijo derecho
                if (node == node->getParent()->getRight()) {
                    node = node->getParent();
                    leftRotation(node);
                }
                // Caso 3: `node` es el hijo izquierdo
                node->getParent()->setColor(NodeColor::BLACK);
                node->getGrandparent()->setColor(NodeColor::RED);
                rightRotation(node->getGrandparent());
            }
        } else { // El caso simétrico cuando el padre es el hijo derecho del abuelo
            RBNode* uncle = node->getGrandparent()->getLeft(); // El tío de `node`

            // Caso 1: El tío es rojo
            if (uncle != nullptr && uncle->getColor() == NodeColor::RED) {
                node->getParent()->setColor(NodeColor::BLACK);
                uncle->setColor(NodeColor::BLACK);
                node->getGrandparent()->setColor(NodeColor::RED);
                node = node->getGrandparent();
            } else {
                // Caso 2: `node` es el hijo izquierdo
                if (node == node->getParent()->getLeft()) {
                    node = node->getParent();
                    rightRotation(node);
                }
                // Caso 3: `node` es el hijo derecho
                node->getParent()->setColor(NodeColor::BLACK);
                node->getGrandparent()->setColor(NodeColor::RED);
                leftRotation(node->getGrandparent());
            }
        }
    }
    // Asegúrate de que la raíz siempre sea negra
    root->setColor(NodeColor::BLACK);
}



void RB::insert_rec(int val, RBNode* node){

	if (val < node->getData()){
		if (node->getLeft() == nullptr){
			node->setLeft(new RBNode(val, node));
			node->getLeft()->setColor(NodeColor::RED);

		}
		else{
			insert_rec(val, node->getLeft());
		}

		if (node->getColor() == NodeColor::RED){
			balance(node->getLeft());
		}


	}
	else{
		if (node->getRight() == nullptr){
			node->setRight(new RBNode(val, node));
			node->getRight()->setColor(NodeColor::RED);
		}
		else{
			insert_rec(val, node->getRight());
		}

		if (node->getColor() == NodeColor::RED){
			balance(node->getRight());
		}
	}
}

void RB::insert(int data) {
    // Crear un nuevo nodo Rojo-Negro con el valor `data`
    RBNode* new_node = new RBNode(data);
    new_node->setColor(NodeColor::RED); // Por defecto, el nuevo nodo es rojo
    new_node->setLeft(nullptr);
    new_node->setRight(nullptr);

    RBNode* parent = nullptr;
    RBNode* current = root;

    // Inserción tipo BST (árbol binario de búsqueda)
    while (current != nullptr) {
        parent = current;
        if (new_node->getData() < current->getData()) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }

    // Establecer el padre del nuevo nodo
    new_node->setParent(parent);

    // Si el árbol estaba vacío, el nuevo nodo se convierte en la raíz
    if (parent == nullptr) {
        root = new_node;
    } else if (new_node->getData() < parent->getData()) {
        parent->setLeft(new_node);
    } else {
        parent->setRight(new_node);
    }

    // Si el nuevo nodo es la raíz, se debe establecer como negro
    if (new_node->getParent() == nullptr) {
        new_node->setColor(NodeColor::BLACK);
        return;
    }

    // Si el abuelo es nulo, no hay necesidad de balancear
    if (new_node->getGrandparent() == nullptr) {
        return;
    }

    // Llamar a la función de balanceo para mantener las propiedades del árbol Rojo-Negro
    balance(new_node);
}


RBNode* RB::find(int val, RBNode* node) {
    RBNode* ans = nullptr;
    if (node == nullptr) {
        return nullptr; // Si el nodo es nulo, retorna nullptr
    }

    if (node->getData() == val) {
        ans = node; // Si encontramos el valor, lo asignamos a ans
    } else {
        if (val < node->getData()) {
            ans = find(val, node->getLeft()); // Asignamos el resultado de la llamada recursiva
        } else {
            ans = find(val, node->getRight()); // Asignamos el resultado de la llamada recursiva
        }
    }
    return ans;
}

RBNode* RB::find(int val) {
    return find(val, root); // Llama a la función con el nodo raíz
}


void RB::traverse(RBNode* node, int label){
	if (node != nullptr){
		for (int i = 0; i < label; i++){
			std::cout << "*" << std::flush;
		}
		char T = node->isLeft()?'L':'R';
		char color = (node->getColor() == NodeColor::RED)?'R':'B';


		std::cout << node->getData() << "   " << T << "   " << color << std::endl;
		traverse(node->getLeft(), label + 1);
		traverse(node->getRight(), label + 1);
	}
}

void RB::traverse(){
	traverse(root, 1);
}

void RB::rightRotation(RBNode* node){

	//std::cout<<"***right rotation "<<node->getData()<<std::endl;
	RBNode* leftChild = node->getLeft();
	RBNode* parent = node->getParent();
	bool isLeft = node->isLeft();
	node->setLeft(leftChild->getRight());
	leftChild->setRight(node);

	if (node == root){
		root = leftChild;
	}
	else{
		if (isLeft){
			parent->setLeft(leftChild);
		}
		else{
			parent->setRight(leftChild);
		}
	}
}

void RB::leftRotation(RBNode* node){
	//std::cout<<"****left-rotation "<<node->getData()<<std::endl;
	RBNode* rightChild = node->getRight();
	RBNode* parent = node->getParent();
	bool isLeft = node->isLeft();
	node->setRight(rightChild->getLeft());
	rightChild->setLeft(node);

	if (node == root){
		root = rightChild;
	}
	else{
		if (isLeft){
			parent->setLeft(rightChild);
		}
		else{
			parent->setRight(rightChild);
		}
	}
}

void RB::printInfo(RBNode* node){
	std::cout << ">>Node: " << node->getData() << std::endl;
	std::cout << "\t>Color: " << (node->getColor() == NodeColor::RED ? "Red" : "Black") << std::endl;
	std::cout << ">>Parent: " << node->getParent()->getData() << std::endl;
	std::cout << "\t>Color: " << (node->getParent()->getColor() == NodeColor::RED ? "Red" : "Black") << std::endl;
	if (node->getRight() != nullptr){
		std::cout << ">>Right: " << node->getRight()->getData() << std::endl;
		std::cout << "\t>Color: " << (node->getRight()->getColor() == NodeColor::RED ? "Red" : "Black") << std::endl;
	} else {
		std::cout << ">>Right: nullptr" << std::endl;
	}
	if (node->getLeft() != nullptr){
		std::cout << ">>Left: " << node->getLeft()->getData() << std::endl;
		std::cout << "\t>Color: " << (node->getLeft()->getColor() == NodeColor::RED ? "Red" : "Black") << std::endl;
	} else {
		std::cout << ">>Left: nullptr" << std::endl;
	}
}



RB::~RB() {
	delete root;
}

} /* namespace trees */
