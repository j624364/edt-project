#pragma once

// Custom array class to store data

#include "assert.hpp"

#define NODISCARD [[nodiscard]]

template <typename T, size_t size>
class Array
{

public:
	inline Array()
	{
	}

	inline Array(T* data)
		: m_Data(data)
	{
	}

	inline Array(const T* data)
		: m_Data(data)
	{
	}

	inline ~Array()
	{
	}

	NODISCARD const T& At(size_t index) const
	{
		assert(index < size, ErrorCode::OutOfBounds);
		return *m_Data[index];
	}

	NODISCARD T& At(size_t index)
	{
		assert(index < size, ErrorCode::OutOfBounds);
		return *m_Data[index];
	}

	NODISCARD static constexpr size_t Size()
	{
		return size;
	}

private:
	T m_Data[size];

};

