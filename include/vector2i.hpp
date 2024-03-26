/**
* @file Vector2i.hpp
* @brief The Vector2i class definition.
* 
* This file contains the Vector2i class. It is a class that represents a 2D vector with integer components.
* The implementation of all member methods is done in src/Vector2i.cpp. 
*/

#ifndef VECTOR2I_HPP
#define VECTOR2I_HPP

#include <iostream>

#include "Enum.hpp"

/// <summary>
/// Namespace pm is the main namespace for the ProtoMath library.
/// It contains all the classes and functions of the library.
/// </summary>
namespace pm {

    /// <summary>
    /// Vector2i is a class that represents a 2D vector with integer components.
    /// It provides essential features for 2D vector manipulation.
    /// </summary>
    class Vector2i {
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
            void setX(int x);

            /// <summary>
            /// Y coordinate setter.
            /// </summary>
            /// <param name="y"> - Value that will be set as Y coordinate</param>
            void setY(int y);

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
            void print(pmEnum mode = PM_PRINT_DEFAULT) const;
        
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
}

#endif // VECTOR2I_HPP
