#include <cmath>

class Vector3 {
    double x;
    double y;
    double z;
public:
    explicit Vector3(double xNew = 0, double yNew = 0, double zNew = 0);

    ~Vector3() = default;

    Vector3 operator+(const Vector3 &v);

    Vector3 operator-(const Vector3 &v);

    bool operator==(const Vector3 &other);

    Vector3 operator*(double alpha);

    friend Vector3 operator*(double alpha, Vector3 v);

    double operator*(const Vector3 &v);

    Vector3 crossProduct(const Vector3 &v) const;

    double mixedProduct(const Vector3 &v1, Vector3 &v2);

    double len();

    std::ostream &dump(std::ostream &out);

    std::ofstream &fdump(std::ofstream &out);

    void getCoordinates(std::istream &in);

    void getCoordinates(std::ifstream &in);

    bool isPerpendicular(const Vector3 &other) const;

    bool isCollinear(const Vector3 &other) const;

};

std::ostream &operator<<(std::ostream &out, Vector3 v);

std::istream &operator>>(std::istream &in, Vector3 &v);

std::ifstream &operator>>(std::ifstream &fIn, Vector3 v);

std::ofstream &operator<<(std::ofstream &fOut, Vector3 v);
