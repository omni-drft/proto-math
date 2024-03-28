#pragma once

#include <iostream>

/// <summary>
/// The namespace that contains all the facilities of the ProtoMath library.
/// </summary>
namespace pm 
{
	
	template <typename T>
	/// <summary>
	/// Vector class that represents a mathematical vector. 
	/// It can store any amount of components of any numerical value.
	/// </summary
	class Vec
	{
	public:
		
		/// <summary>
		/// Vector constructor that initializes the vector with the given components and size.
		/// </summary>
		/// <param name="components">- Pointer to an array filled with numerical components.</param>
		/// <param name="size">- Amount of compontents that user wants to hold in vector.</param>
		Vec(T* components, size_t size);
		
		/// <summary>
		/// Function that returns the component of the vector at the given index.
		/// </summary>
		/// <param name="index">- index of component that will be returned (counting from 0).</param>
		/// <returns>Component of vector at the given index.</returns>
		T getComponent(size_t index);

		/// <summary>
		/// Function that returns the pointer to the array of components of the vector.
		/// </summary>
		/// <returns>Pointer to an array with components of vector.</returns>
		T* getComponents();

		/// <summary>
		/// Function that returns the size of the vector (amount of dimensions).
		/// </summary>
		/// <returns>Size of the vector.</returns>
		size_t getSize();

		/// <summary>
		/// Function that sets the component of the vector at the given index to the given value.
		/// </summary>
		/// <param name="index">- - Index of component which will be changed.</param>
		/// <param name="value">Value that component at given index will be changed to.</param>
		void setComponent(size_t index, T value);

		/// <summary>
		/// Function that sets the components of vector to 
		/// the components that are in the given array.
		/// </summary>
		/// <param name="components">- Pointer to an array that contains 
		/// future values of vector components</param>
		void setComponents(T* components);

		/// <summary>
		/// Destructor of the vector that deletes the dynamically allocated array of components.
		/// </summary>
		~Vec();

	private:

		/// <summary>
		/// Basic array that holds the components of the vector.
		/// </summary>
		T* components;

		/// <summary>
		/// Size of the vector (amount of components).
		/// </summary>
		size_t vecSize;
	};

}