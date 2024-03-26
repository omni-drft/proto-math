#ifndef VECTOR2I_HPP
#define VECTOR2I_HPP

#include <iostream>

#include "Enum.hpp"

/// <summary>
/// Namespace pm is the main namespace for the ProtoMath library.
/// It contains all the classes and functions of the library.
/// </summary>
namespace pm 
    {

    /// <summary>
    /// Vector2i is a class that represents a 2D vector with integer components.
    /// It provides essential features for 2D vector manipulation.
    /// </summary>
    class Vector2i 
    {
        public:
            /// <summary>
            /// The empty constructor creates a new Vector2i with both components set to 0.
            /// </summary>
            Vector2i();

            /// <summary>
            /// A constructor that creates a new Vector2i with the given components.
            /// </summary>
            /// <param name="x"> - x coordinate</param>
            /// <param name="y"> - y coordinate</param>
            Vector2i(int x, int y);

            /// <summary>
            /// X coordinate getter.
            /// </summary>
            /// <returns>X coordinate</returns>
            int getX() const;

            /// <summary>
            /// Y coordinate getter.
            /// </summary>
            /// <returns>Y coordinate</returns>
            int getY() const;

            /// <summary>
            /// X coordinate setter.
            /// </summary>
            /// <param name="x"> - Value that will be set as X coordinate</param>
            /// <returns>Error codes for the operation. 0 if succesful, !=0 if error</returns>
            int setX(int x);

            /// <summary>
            /// Y coordinate setter.
            /// </summary>
            /// <param name="y"> - Value that will be set as Y coordinate</param>
            /// <returns>Error codes for the operation. 0 if succesful, !=0 if error</returns>
            int setY(int y);

            /// <summary>
            /// Print method that outputs the vector to the console in different formats.
            /// </summary>
            /// <param name="mode"> - The print mode that will be used to format the output.
            /// Default is PM_PRINT_DEFAULT. Possible values are:
            /// <para>
            /// PM_PRINT_DEFAULT - Prints the vector in the format "(x, y)\n".
            /// </para>
            /// <para>
            /// PM_PRINT_SIMPLEST - Prints the vector in the format "x y\n".
            /// </para>
            /// <para>
            /// PM_PRINT_POLAR - Prints the vector in the format "(r, angle)\n".
            /// </para>
            /// </param>
            /// <returns>Error codes for the operation. 0 if succesful, !=0 if error</returns>
            int print(pmEnum mode = PM_PRINT_DEFAULT) const;

            /// <summary>
            /// Enables simple addition of two vectors in the form of vector1 + vector2 using operator overloading.
            /// </summary>
            /// <param name="other>The vector that will be added to the current vector.</param>
            /// <returns>Sum of 2 vectors.</returns>
            Vector2i operator+(const Vector2i& other) const;

            /// <summary>
            /// Enables simple subtraction of two vectors in the form of vector1 - vector2 using operator overloading.
            /// </summary>
            /// <param name="other">The vector that will be subtracted from the current vector</param>
            /// <returns>Difference between two vectors as a vector.</returns>
            Vector2i operator-(const Vector2i& other) const;

            /// <summary>
            /// Enables simple multiplication of a vector by a scalar in the form of vector * scalar using operator overloading.
            /// </summary>
            /// <param name="scalar">The scalar that will be multiplied by the vector.</param
            /// <returns> The result of the multiplication as a vector.</returns>
            Vector2i operator*(int scalar) const;

            /// <summary>
            /// Enables simple division of a vector by a scalar in the form of vector / scalar using operator overloading.
            /// </summary>
            /// <param name="scalar"> The scalar that will divide the vector.</param>
            /// <returns> The result of the division as a vector.</returns>
            Vector2i operator/(int scalar) const;
        
        private:
            /// <summary>
            /// X coordinate of the vector.
            /// </summary>
            int x;

            /// <summary>
            /// Y coordinate of the vector.
            /// </summary>
            int y;
    };

    /// <summary>
    /// A namespace that contains functions for vector2i manipulation.
    /// </summary>
    namespace vector2i
    {
        Vector2i dotProduct(const Vector2i& vector1, const Vector2i& vector2);

        Vector2i crossProduct(const Vector2i& vector1, const Vector2i& vector2);
    }

}

#endif // VECTOR2I_HPP
