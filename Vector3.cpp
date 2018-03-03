#include <iostream>
#include <fstream>
#include "Vector3.h"

Vector3::Vector3(double xNew, double yNew, double zNew) :
        x(xNew),
        y(yNew),
        z(zNew) {}


double Vector3::len() {
    return sqrt(x * x + y * y + z * z);
}

bool Vector3::isPerpendicular(const Vector3 &other) const {
    return !(Vector3(x, y, z) * other);
}

bool Vector3::isCollinear(const Vector3 &other) const {
    return (x / other.x == y / other.y) && (y / other.y == z / other.z);
}

void Vector3::getCoordinates(std::istream &in) {
    in >> x >> y >> z;
}

void Vector3::getCoordinates(std::ifstream &in) {
    in >> x >> y >> z;
}

std::ostream &Vector3::dump(std::ostream &out) {
    return out << "[" << x << ", " << y << ", " << z << "]\n";
}

std::ofstream &Vector3::fdump(std::ofstream &out) {
    out << "[" << x << ", " << y << ", " << z << "]\n";
    return out;
}

double Vector3::mixedProduct(const Vector3 &v1, Vector3 &v2) {
    return Vector3(x, y, z) * v1.crossProduct(v2);
}

Vector3 Vector3::crossProduct(const Vector3 &v) const {
    return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

bool Vector3::operator==(const Vector3 &other) {
    return ((x == other.x) && (y == other.y) && (z == other.z));
}

Vector3 Vector3::operator+(const Vector3 &v) {
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3 &v) {
    return Vector3(x - v.x, y - v.y, z - v.z);
}

double Vector3::operator*(const Vector3 &v) {
    return v.x * x + v.y * y + v.z * z;
}


Vector3 Vector3::operator*(double alpha) {
    return Vector3(x * alpha, y * alpha, z * alpha);
}

Vector3 operator*(double alpha, Vector3 v) {
    return Vector3(v.x * alpha, v.y * alpha, v.z * alpha);
}


std::ofstream &operator<<(std::ofstream &fOut, Vector3 v) {
    return v.fdump(fOut);
}

std::ifstream &operator>>(std::ifstream &fIn, Vector3 v) {
    v.getCoordinates(fIn);
    return fIn;
}

std::istream &operator>>(std::istream &in, Vector3 &v) {
    v.getCoordinates(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, Vector3 v) {
    return v.dump(out);

}
