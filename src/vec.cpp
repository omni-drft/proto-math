#include "vec.hpp"

#pragma warning(push)
#pragma warning(disable: 4244) 
#pragma warning(disable: 4661)

template<typename T>
pm::Vec<T>::Vec(T* components, size_t size)
	: components(new T[size]), vecSize(size)
{
	for (size_t i{}; i < vecSize; i++) // copy components from given array to the vector
		this->components[i] = components[i];
}


template<typename T>
pm::Vec<T>::Vec(const Vec<T>& vec)
	: components(new T[vec.vecSize]), vecSize(vec.vecSize)
{
	for (size_t i{}; i < vecSize; i++) // copy components from given vector to the vector
		components[i] = vec.components[i];
}

template<typename T>
T pm::Vec<T>::getComponent(size_t index)
{
	if (index >= vecSize) // if index is out of range
		throw std::out_of_range("ProtoMath: Index out of range");
	return components[index]; // return component at given index
}


template<typename T>
T* pm::Vec<T>::getComponents()
{
	return components; // return pointer to the array of components
}


template<typename T>
size_t pm::Vec<T>::getSize()
{
	return vecSize; // return size of the vector
}


template<typename T>
void pm::Vec<T>::setComponent(size_t index, T value)
{
	if (index >= vecSize) // if index is out of range
		// throw an exception
		throw std::out_of_range("ProtoMath: Index out of range");
	components[index] = value; // set component at given index to the given value
}


template<typename T>
void pm::Vec<T>::setComponents(T* components)
{
	for (size_t i{}; i < vecSize; i++) // copy components from given array to the vector
		this->components[i] = components[i];
}


template<typename T>
T pm::Vec<T>::magnitude()
{
	T sum{}; // sum of squares of components
	for (size_t i{}; i < vecSize; i++) // iterate over components
		sum += components[i] * components[i]; // add square of component to sum
	return sqrt(sum); // return square root of sum
}

template<typename T>
void pm::Vec<T>::normalize()
{
	T mag = magnitude(); // get magnitude of the vector
	for (size_t i{}; i < vecSize; i++) // iterate over components
		components[i] /= mag; // divide component by magnitude)
}

template<typename T>
pm::Vec<T> pm::Vec<T>::getNormalized()
{
	Vec<T> normalized(*this); // create a copy of the vector
	normalized.normalize(); // normalize the copy
	return normalized; // return the copy
}

template<typename T>
pm::Vec<T> pm::Vec<T>::operator+(const Vec<T>& vec)
{
	Vec<T> sum(*this); // create a copy of the vector

	for (size_t i{}; i < vecSize; i++) // iterate over components
		// add component of the given vector to the component of the copy
		sum.components[i] += vec.components[i]; 

	return sum;
}

template<typename T>
pm::Vec<T> pm::Vec<T>::operator-(const Vec<T>& vec)
{
	Vec<T> diff(*this); // create a copy of the vector

	for (size_t i{}; i < vecSize; i++) // iterate over components
		// subtract component of the given vector from the component of the copy
		diff.components[i] -= vec.components[i];

	return diff;
}

template <typename T>
pm::Vec<T> pm::Vec<T>::operator*(const T& scalar)
{
	Vec<T> scaled(*this); // create a copy of the vector

	for (size_t i{}; i < vecSize; i++) // iterate over components
		// multiply component of the copy by the scalar
		scaled.components[i] *= scalar;

	return scaled;
}

template<typename T>
pm::Vec<T> pm::Vec<T>::operator/(const T& scalar)
{
	Vec<T> scaled(*this); // create a copy of the vector

	for (size_t i{}; i < vecSize; i++) // iterate over components
		// divide component of the copy by the scalar
		scaled.components[i] /= scalar;

	return scaled;
}

template<typename T>
pm::Vec<T>::~Vec()
{
	delete[] components; // delete the array of components
}


// Explicit instantiation of Vec class for different types
template class pm::Vec<int>; 
template class pm::Vec<float>;
template class pm::Vec<double>;
template class pm::Vec<long>;
template class pm::Vec<long long>;
template class pm::Vec<unsigned int>;
template class pm::Vec<unsigned long>;
template class pm::Vec<unsigned long long>;

#pragma warning(pop)
