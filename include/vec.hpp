#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <cmath>

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
		/// Copy constructor. It creates a new vector that is a copy of the given vector.
		/// WARNING: This constructor creates a deep copy of the vector.
		/// This means that the new vector will have its own array of components and destroying
		/// the older vector will not affect the new one.
		/// </summary>
		/// <param name="vec">- Vector reference that will be used to copy data from.</param>
		Vec(const Vec& vec);

		
		/// <summary>
		/// Function that returns the component of the vector at the given index.
		/// </summary>
		/// <param name="index">- Index of component that will be returned (counting from 0).</param>
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
		/// <param name="index">- Index of component which will be changed.</param>
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
		/// Function that calculates the magnitude of the vector.
		/// </summary>
		/// <returns>Magnitude of vector.</returns>
		T magnitude();

		/// <summary>
		/// Function that normalizes the vector. WARNING: This function changes the vector itself.
		/// </summary>
		void normalize();

		/// <summary>
		/// Function that returns the normalized vector. WARNING: This function does 
		/// not change the vector itself. It returns a new vector that is normalized. 
		/// If you want to normalize the vector itself, use the normalize() function.
		/// </summary>
		/// <returns>Normalized version of vector.</returns>
		Vec getNormalized();

		/// <summary>
		/// Operator that allows to add two vectors together in a simple way.
		/// </summary>
		/// <param name="vec">- Second vector that will be used in addition.</param>
		/// <returns>Result of addition.</returns>
		Vec operator+(const Vec& vec);

		/// <summary>
		/// Operator that allows simple vector subtraction.
		/// </summary>
		/// <param name="vec">- Vector that will be substracted.</param>
		/// <returns>Result of subtraction.</returns>
		Vec operator-(const Vec& vec);

		/// <summary>
		/// Operator that allows to multiply the vector by a scalar.
		/// </summary>
		/// <param name="scalar">- Scalar that will be used to multiply the vector.</param>
		/// <returns>Result of multiplication.</returns>
		Vec operator*(const T& scalar);	

		/// <summary>
		/// Operator that allows to divide the vector by a scalar.
		/// </summary>
		/// <param name="scalar">- Scalar that will be used to divide the vector.</param>
		/// <returns>Result of division.</returns>
		Vec operator/(const T& scalar);

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

	namespace vector
	{
		template<typename T>
		T dotProduct(Vec<T>& vec1, Vec<T>& vec2);

		template<typename T>
		Vec<T> crossProduct(Vec<T>& vec1, Vec<T>& vec2);
	}


}

#endif // !VEC_H