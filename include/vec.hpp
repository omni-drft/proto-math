#pragma once

#include <iostream>

namespace pm 
{
	template <typename T>
	class Vec
	{
	public:
		Vec(T* components, size_t size);
		
		T getComponent(size_t index);
		T* getComponents();
		size_t getSize();

		void setComponent(size_t index, T value);
		void setComponents(T* components);

		~Vec();

	private:
		T* components;
		size_t vecSize;
	};

}