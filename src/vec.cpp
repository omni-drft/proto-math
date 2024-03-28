#include "vec.hpp"

template<typename T>
pm::Vec<T>::Vec(T* components, size_t size)
	: components(new T[size]), size(size)
{
	for (size_t i{}; i < size; i++)
		this->components[i] = components[i];
}

template<typename T>
T pm::Vec<T>::getComponent(size_t index)
{
	if (index >= size)
		throw std::out_of_range("ProtoMath: Index out of range");
	return components[index];
}

template<typename T>
T* pm::Vec<T>::getComponents()
{
	return components;
}

template<typename T>
size_t pm::Vec<T>::getSize()
{
	return size;
}

template<typename T>
void pm::Vec<T>::setComponent(size_t index, T value)
{
	if (index >= size)
		throw std::out_of_range("ProtoMath: Index out of range");
	components[index] = value;
}

template<typename T>
void pm::Vec<T>::setComponents(T* components)
{
	for (size_t i{}; i < size; i++)
		this->components[i] = components[i];
}

template<typename T>
pm::Vec<T>::~Vec()
{
	delete[] components;
}


