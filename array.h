#pragma once

// Custom array class to store data

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
		return *m_Data[index];
	}

	NODISCARD T& At(size_t index)
	{
		return *m_Data[index];
	}

	NODISCARD inline constexpr size_t Size()
	{
		return size;
	}

private:
	T m_Data[size];

};

