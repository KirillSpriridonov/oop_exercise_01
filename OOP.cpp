//Спиридонов Кирилл М8О-207Б-19

#include <iostream>
#include <cmath>

class Vector3D {
private: //Приватная область
	double x, y, z; // Координаты вектора
public: //Публичная область
	Vector3D() {
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3D(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void setCords(double x, double y, double z) { //Метод установки координат
		this->x = x;
		this->y = y;
		this->z = z;
	}
	double getX() { return x; } //Методы
	double getY() { return y; } //Возращающие
	double getZ() { return z; } //Координаты векторы
	friend std::ostream& operator<< (std::ostream& out, const Vector3D& vec);//Дружественные
	friend std::istream& operator>> (std::istream& in, Vector3D& vec);//Функции
	Vector3D operator +(Vector3D& other) { //Сложение векторов
		Vector3D res(this->getX() + other.x, this->getY() + other.y, this->getZ() + other.z);
		return res;
	}
	Vector3D operator -(Vector3D& other) { //Вычитание векторов
		Vector3D res(this->getX() - other.x, this->getY() - other.y, this->getZ() - other.z);
		return res;
	}
	Vector3D operator -() { //Унарный минус
		this->x = -x;
		this->y = -y;
		this->z = -z;
		return *this;
	}
	Vector3D operator *(Vector3D& other) { //Векторное произведение
		double resx = (this->y * other.z - this->z * other.y);
		double resy = (this->x * other.z - this->z * other.x);
		double resz = (this->x * other.y - this->y * other.x);
		Vector3D res(resx, -resy, resz);
		return res;
	}
	Vector3D operator *(const double a) { //Умножение вектора на скаляр
		double resx = a * this->x;
		double resy = a * this->y;
		double resz = a * this->z;
		Vector3D res(resx, resy, resz);
		return res;
	}
	Vector3D operator =(const Vector3D& vec) { //Оператор присваивания
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
		return *this;
	}
	double Length() { //Длина вектора
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
};
double Scalar(Vector3D& a, Vector3D& b) {//Скалярное произведение векторов
	double res = a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
	return res;
}
Vector3D operator*(double a, Vector3D& b) {//Произведение скаляра на вектор
	return b * a;
}
void SameCords(Vector3D& a, Vector3D& b) {//Проверка на совпадение векторов
	std::cout << "Векторы имеют совпадающие координаты:";
	int count = 0;
	if (a.getX() == b.getX()) {
		std::cout << "x=" << a.getX();
		count++;
	}
	if (a.getY() == b.getY()) {
		std::cout << ", y=" << a.getY();
		count++;
	}
	if (a.getZ() == b.getZ()) {
		std::cout << ", z=" << a.getZ();
		count++;
	}
	if (count == 0)
		std::cout << "нигде";
	std::cout << "\n";
}
void CompareLength(Vector3D& a, Vector3D& b) {//Сравнение длины двух векторов
	if (a.Length() > b.Length()) {
		std::cout << "Длина vector1 больше длины vector2 на " << a.Length() - b.Length();
	}
	else if (b.Length() > a.Length()) {
		std::cout << "Длина vector2 больше длины vector1 на " << b.Length() - a.Length();
	}
	else {
		std::cout << "Длины векторов совпадают";
	}
}
double Angle(Vector3D& a, Vector3D& b) {//Угол между векторами
	double angle = acos(Scalar(a, b) / (a.Length() * b.Length()));
	return angle;
}
std::ostream& operator<< (std::ostream& out, const Vector3D& vec) {
	out << vec.x << " " << vec.y << " " << vec.z;
	return out;
}
std::istream& operator>>(std::istream& in, Vector3D& vec)
{
	in >> vec.x >> vec.y >> vec.z;
	return in;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Vector3D vec1, vec2;
	std::cout << "Введите vector1: ";
	std::cin >> vec1;
	std::cout << "Введите vector2: ";
	std::cin>>vec2;
	std::cout << "Сумма двух векторов: ("<<vec1<<")+("<<vec2<<") = " << vec1 + vec2<<"\n";
	std::cout << "Разность двух векторов: (" << vec1 << ")-(" << vec2 << ") = " << vec1 - vec2 << "\n";
	std::cout << "Противоположный вектору vector1: (" << -vec1 << ") \n";
	std::cout << "Противоположный вектору vector2: (" << -vec2 << ") \n";
	std::cout << "Векторное произведение двух векторов: (" << vec1 << ")*(" << vec2 << ")=" << "("<<vec1 * vec2<<")"<<"\n";
	int n, m;
	std::cout << "n: \n";
	std::cin >> n;
	std::cout << "m: \n";
	std::cin>> m;
	std::cout << "Умножение на скаляр: vector1*n: (" << vec1 << ")*" << n << "=(" << vec1 * n <<")"<< "\n";
	std::cout << "Умножение на скаляр: vector2*m: (" << vec2 << ")*" << m << "=(" << vec2 * m <<")"<< "\n";
	std::cout << "Скалярное произведение vector1*vector2: (" << vec1 << ")*("<< vec2 <<")="<< Scalar(vec1,vec2)<<"\n";
	std::cout << "Угол между веторами vector1 и vector2: cos=" << Angle(vec1, vec2) << "\n";
	SameCords(vec1, vec2);
	CompareLength(vec1, vec2);
}
// 1 2 3 
// 2 -3 9
//