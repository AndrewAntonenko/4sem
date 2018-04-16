#include <cmath>

class Vector3 {
    double x;
    double y;
    double z;
public:
    explicit Vector3(double xNew = 0, double yNew = 0, double zNew = 0);

    // fixit: деструктор можно не объявлять явно. компилятор сам это сгенерирует в данном случае
    ~Vector3() = default;

    // fixit: все операторы и просто методы, которые не модифицируют поля класса должны быть константными
    Vector3 operator+(const Vector3 &v);
    Vector3 operator-(const Vector3 &v);

    bool operator==(const Vector3 &other);

    Vector3 operator*(double alpha);

    // второй параметр лучше по константной ссылке передать
    friend Vector3 operator*(double alpha, Vector3 v);

    double operator*(const Vector3 &v);

    // обычно для векторного произведения оператор ^ перегружают
    Vector3 crossProduct(const Vector3 &v) const;

    // fixit: потерялся один const
    double mixedProduct(const Vector3 &v1, Vector3 &v2);

    double len();

    // кажется, что не нужно отдельно перегружать ofstream, т.к. он вроде наследник от ostream
    std::ostream &dump(std::ostream &out);

    std::ofstream &fdump(std::ofstream &out);

    void getCoordinates(std::istream &in);

    void getCoordinates(std::ifstream &in);

    bool isPerpendicular(const Vector3 &other) const;

    bool isCollinear(const Vector3 &other) const;

};

// кажется, что для fstream отдельно не нужно перегружать 
std::ostream &operator<<(std::ostream &out, Vector3 v);

std::istream &operator>>(std::istream &in, Vector3 &v);

std::ifstream &operator>>(std::ifstream &fIn, Vector3 v);

std::ofstream &operator<<(std::ofstream &fOut, Vector3 v);
