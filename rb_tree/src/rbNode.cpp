/*
 * rbNode.cpp
 *
 *  Created on: Sep 2, 2022
 *      Author: jsaavedr
 */

#include "trees/rbNode.hpp"
#include <cmath>
#include <iostream>

namespace trees {

RBNode::RBNode():
		data(-1), ptrLeft(nullptr), ptrRight(nullptr),
		parent(nullptr), color(NodeColor::RED), type(NodeType::LEFT) {
	// TODO Auto-generated constructor stub
}

RBNode::RBNode(int val, RBNode* _parent):
		data(val), ptrLeft(nullptr), ptrRight(nullptr),
		parent(_parent), color(NodeColor::RED), type(NodeType::LEFT){
}

void RBNode::setLeft(RBNode* node){
	ptrLeft = node;
	if (ptrLeft!= nullptr){
		ptrLeft->setParent(this);
		ptrLeft->setType(NodeType::LEFT);
	}

}

void RBNode::setRight(RBNode* node){
	ptrRight = node;
	if (ptrRight!= nullptr){
		ptrRight->setParent(this);
		ptrRight->setType(NodeType::RIGHT);
	}
}

void RBNode::setColor(NodeColor c){
	color = c;
}

void RBNode::setType(NodeType t){
	type = t;
}

bool RBNode::isLeft(){
	return (type == NodeType::LEFT);
}

bool RBNode::isRight(){
	return (type == NodeType::RIGHT);
}

void RBNode::setData(int val){
	data = val;
}

void RBNode::setParent(RBNode* node){
	parent = node;
}

RBNode* RBNode::getLeft(){
	return ptrLeft;
}

RBNode* RBNode::getRight(){
	return ptrRight;
}

int RBNode::getData(){
	return data;
}

RBNode* RBNode::getParent(){
	return parent;
}

RBNode* RBNode::getUncle() {
    RBNode* grandparent = getGrandparent(); 
    if (grandparent == nullptr) {
        return nullptr; 
    }

    if (parent == grandparent->getLeft()) {
        return grandparent->getRight(); 
    } else {
        return grandparent->getLeft();  
    }
}


RBNode* RBNode::getGrandparent() {
    return (parent != nullptr) ? parent->getParent() : nullptr;
}


NodeColor RBNode::getUncleColor() {
    RBNode* grandparent = getGrandparent(); 
    if (grandparent == nullptr) {
        return NodeColor::BLACK; 
    }

    RBNode* uncle = (parent->isLeft()) ? grandparent->getRight() : grandparent->getLeft();

	if (uncle != nullptr){
		return uncle->getColor();
	} else {
		return NodeColor::BLACK;
	}

}

bool RBNode::isSameSideAsParent() {
    if (parent == nullptr || parent->getParent() == nullptr) {
        return false; 
    }

	if (parent->isLeft() && isLeft()){
		return true;
	} else if (parent->isRight() && isRight()){
		return true;
	} else {
		return false;
	}
}


void RBNode::invertColor(){
	if (color == NodeColor::RED){
		color = NodeColor::BLACK;
	} else {
		color = NodeColor::RED;
	}
}

NodeColor RBNode::getColor(){
	return color;
}

char RBNode::getType(){
	return isLeft()?'L':'R';
}


RBNode::~RBNode() {
	if (ptrLeft != nullptr){
		delete ptrLeft;
	}
	if (ptrRight != nullptr){
		delete ptrRight;
	}
}

} /* namespace trees */
