//
// Created by lirisimagine on 18/08/2020.
//

#include "Patch.h"

Patch::Patch(Mat &image, int x, int y, bool traverse):m_patch(image),
m_positionX(x),m_positionY(y), m_traverse(traverse) {}

Patch::Patch() {
    Mat image;
    m_patch = image;
    m_positionX = 0;
    m_positionY = 0;
    m_traverse = false;
}

void Patch::setPositionX(int x) {
    m_positionX = x;
}
void Patch::setPositionY(int y) {
    m_positionY = y;
}

void Patch::setPatch(Mat &image) {
    m_patch = image;
}

Mat Patch::getPatch() {
    return m_patch;
}

int Patch::getPositionX() {
    return m_positionX;
}

int Patch::getPositionY() {
    return m_positionY;
}

void Patch::setTraverse(bool traverse) {
    m_traverse = traverse;
}

bool Patch::getTraverse() {
    return m_traverse;
}

Patch::~Patch() {}