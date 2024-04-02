#pragma once

namespace pm 
{

	template <typename T>
	/// <summary>
	/// Class that represents a matrix of type T.
	/// The matrix is represented as a 2D array of type T.
	/// Type T is a template parameter, but it has to be a numeric type.
	/// </summary>
	class Mat
	{
	public:

		/// <summary>
		/// Constructor that creates a matrix of size n x m.
		/// The matrix is initialized with zeros.
		/// </summary>
		/// <param name="n">- number of rows of the matrix</param>
		/// <param name="m">- number of columns of the matrix</param>
		Mat(size_t n, size_t m);

		/// <summary>
		/// Constructor that creates a matrix of size n x m.
		/// The matrix is initialized with the values from the 2D array mat.
		/// </summary>
		/// <param name="n">- number of rows of the matrix</param>
		/// <param name="m">- number of columns of the matrix</param>
		/// <param name="mat">- 2D array of values that will be used to initialize the matrix</param>
		Mat(size_t n, size_t m, T** mat);

		/// <summary>
		/// Copy constructor that creates a deep copy of the given matrix.
		/// </summary>
		/// <param name="other">- The matrix that the values will be copied to new matrix.</param>
		Mat(const Mat& other);

		/// <summary>
		/// Method that return the value of the component at the given position.
		/// </summary>
		/// <param name="i">- row index</param>
		/// <param name="j">- column index</param>
		/// <returns>- value of the component at the given position</returns>
		T getComponent(size_t i, size_t j) const;

		/// <summary>
		/// Method that returns the 2D array that represents the matrix.
		/// </summary>
		/// <returns>- 2D array that represents the matrix</returns>
		T** getMat() const;

		/// <summary>
		/// Method that returns the number of rows of the matrix.
		/// </summary>
		/// <returns>- number of rows of the matrix</returns>
		size_t getDimX() const;

		/// <summary>
		/// Method that returns the number of columns of the matrix.
		/// </summary>
		/// <returns>- number of columns of the matrix</returns>
		size_t getDimY() const;

		/// <summary>
		/// Method that sets the value of the component at the given position.
		/// </summary>
		/// <param name="i">- row index</param>
		/// <param name="j">- column index</param>
		/// <param name="value">- value that will be set at the given position</param>
		void setComponent(size_t i, size_t j, T value);

		/// <summary>
		/// Method that sets the 2D array that represents the matrix.
		/// </summary>
		/// <param name="mat">- 2D array that represents the matrix</param>
		void setMat(T** mat);
		
		/// <summary>
		/// Method that prints the matrix.
		/// </summary>
		void print() const;

		/// <summary>
		/// Destructor that frees the memory allocated for the matrix.
		/// </summary>
		~Mat();
	private:
		/// <summary>
		/// Matrix of type T.
		/// </summary>
		T** mat;

		/// <summary>
		/// Number of rows of the matrix.
		/// </summary>
		size_t n;

		/// <summary>
		/// Number of columns of the matrix.
		/// </summary>
		size_t m;

	};

}
