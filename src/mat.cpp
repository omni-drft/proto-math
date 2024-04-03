#include "mat.hpp"

template<typename T>
pm::Mat<T>::Mat(size_t n, size_t m)
	: n(n), m(m)
{
	mat = new T*[n];
	for (size_t i = 0; i < n; i++)
		mat[i] = new T[m];
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			mat[i][j] = 0;
}

template<typename T>
pm::Mat<T>::Mat(size_t n, size_t m, T** mat)
	: n(n), m(m)
{
	this->mat = new T*[n];
	for (size_t i = 0; i < n; i++)
		this->mat[i] = new T[m];
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			this->mat[i][j] = mat[i][j];
}

template<typename T>
pm::Mat<T>::Mat(const Mat& other)
	: n(other.n), m(other.m)
{
	mat = new T*[n];
	for (size_t i = 0; i < n; i++)
		mat[i] = new T[m];
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			mat[i][j] = other.mat[i][j];
}

template<typename T>
T pm::Mat<T>::getComponent(size_t i, size_t j) const
{
	return mat[i][j];
}

template<typename T>
T** pm::Mat<T>::getMat() const
{
	return mat;
}

template<typename T>
size_t pm::Mat<T>::getDimX() const
{
	return n;
}

template<typename T>
size_t pm::Mat<T>::getDimY() const
{
	return m;
}

template<typename T>
void pm::Mat<T>::setComponent(size_t i, size_t j, T value)
{
	mat[i][j] = value;
}

template<typename T>
void pm::Mat<T>::setMat(T** mat)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			this->mat[i][j] = mat[i][j];
}

template<typename T>
void pm::Mat<T>::print() const
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
			std::cout << mat[i][j] << " ";
		std::cout << std::endl;
	}
}

template<typename T>
pm::Mat<T> pm::Mat<T>::operator+(const Mat& other)
{
	if (n != other.n || m != other.m)
		throw std::invalid_argument("Matrices must have the same dimensions.");

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			mat[i][j] += other.mat[i][j];
}

template<typename T>
pm::Mat<T> pm::Mat<T>::operator-(const Mat& other)
{
	if (n != other.n || m != other.m)
		throw std::invalid_argument("Matrices must have the same dimensions.");

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			mat[i][j] -= other.mat[i][j];
}

template<typename T>
pm::Mat<T> pm::Mat<T>::operator*(const T& scalar)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			mat[i][j] *= scalar;
}

template<typename T>
pm::Mat<T> pm::Mat<T>::operator/(const T& scalar)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			mat[i][j] /= scalar;
}

template<typename T>
pm::Mat<T>::~Mat()
{
	for (size_t i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;
}

// Explicit instantiation
template class pm::Mat<int>;
template class pm::Mat<float>;
template class pm::Mat<double>;
template class pm::Mat<long>;
template class pm::Mat<long long>;
template class pm::Mat<unsigned int>;
template class pm::Mat<unsigned long>;
template class pm::Mat<unsigned long long>;