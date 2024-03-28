#include "vec.hpp"


template<typename T>
pm::Vec<T>::Vec(T* components, size_t size)
	: components(new T[size]), vecSize(size)
{
	for (size_t i{}; i < vecSize; i++) // copy components from given array to the vector
		this->components[i] = components[i];
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
