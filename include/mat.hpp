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
		/// <param name="n"></param>
		/// <param name="m"></param>
		Mat(size_t n, size_t m);

		Mat(size_t n, size_t m, T** mat);
		Mat(const Mat& other);

		T getComponent(size_t i, size_t j) const;
		T** getMat() const;
		size_t getDimX() const;
		size_t getDimY() const;

		void setComponent(size_t i, size_t j, T value);
		void setMat(T** mat);
		
		void print() const;

		~Mat();
	private:
		T** mat;
		size_t n;
		size_t m;

	};

}
