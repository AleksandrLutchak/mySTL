#ifndef VECTOR_H
#define VECTOR_H

template <class V>
class Vector
{
	V *data;
	int Size;
	int Capacity;

public:
	Vector();
	Vector(const int);
	Vector(const Vector&);
	Vector(int, V);
	Vector<V>& operator=(const Vector&);
	V& operator [](int);

	V& at(int) const;
	V& front() const;
	V& back() const;
	int capacity() const;
	void push_back(const V&);
	bool empty() const;
	int size() const;
	void reserve(const int);
	void resize(const int);
	void resize(const int, const V&);

	~Vector(void);

};

template <class V>
Vector<V>::Vector()
	: data(nullptr)
	, Size(0)
	, Capacity(1)
{}

template <class V>
Vector<V>::Vector(const int newSize)
	: data(nullptr)
	, Size(newSize)
	, Capacity(newSize)
{
	if (this->data)
	{
		delete[] data;
	}

	data = new V[newSize];

	for (size_t i = 0; i < newSize; i++)
	{
		data[i] = NULL;
	}
}

template <class V>
Vector<V>::Vector(const Vector &vector) //copy constructor
	: data(nullptr)
	, Size(vector.Size)
	, Capacity(vector.Size)
{
	data = new V[Size];

	for (size_t i = 0; i < Size; i++)
	{
		data[i] = vector.data[i];
	}
}

template <class V>
Vector<V>::Vector(int currentSize, V newData)
	: Size(currentSize)
	, Capacity(currentSize)
{
	data = new V[Size];
	for (int i = 0; i < Size; i++)
	{
		data[i] = newData;
	}
}

template <class V>
Vector<V>& Vector<V>::operator=(const Vector<V>& newData)
{
	Size = newData.Size;
	for (size_t i = 0; i < Size; i++)
	{
		this->data[i] = newData[i];
	}
	return *this;
}

template <class V>
V& Vector<V>::operator[](int i)
{
#ifdef _DEBUG
	if (!data)
	{
		throw "Out of range!";
	}
#endif
	return data[i];
}

template <class V>
Vector<V>::~Vector(void)
{
	if (data)
	{
		delete[] data;
	}
}

template <class V>
inline V& Vector<V>::at(int index) const
{
	return data[index];
}

template <class V>
inline V& Vector<V>::front() const
{
	if (Size != 0)
	{
		return data[0];
	}
	else
	{
		std::cout << "Vector is empty." << std::endl;
	}
}

template <class V>
inline V& Vector<V>::back() const
{
	if (Size != 0)
	{
		return data[Size - 1];
	}
	else
	{
		std::cout << "Vector is empty." << std::endl;
	}
}

template<class V>
inline int Vector<V>::capacity() const
{
	return Capacity;
}

template <class V>
void Vector<V>::push_back(const V& newData)
{
	if (this->Capacity <= this->Size)
	{
		Capacity = Capacity + (Capacity / 2);
		V* tempData = new V[Capacity];
		for (size_t i = 0; i < Size; i++)
		{
			tempData[i] = data[i];
		}
		delete[] data;
		this->data = tempData;
	}
	data[Size] = newData;
	this->Size++;
}

template <class V>
bool Vector<V>::empty() const
{
	bool result;
	if (this->Size == 0)
	{
		result = true;
	}
	else if (this->Size != 0)
	{
		result = false;
	}

	return result;
}

template<class V>
inline int Vector<V>::size() const
{
	return Size;
}

template<class V>
inline void Vector<V>::reserve(const int newCapacity)
{
	if (this->Capacity < newCapacity)
	{
		this->Capacity = newCapacity;
		V* tempData = new V[Capacity];
		for (size_t i = 0; i < Size; i++)
		{
			tempData[i] = data[i];
		}
		delete[] data;
		this->data = tempData;
	}
}

template<class V>
inline void Vector<V>::resize(const int newSize)
{
	V* tempData = new V[Capacity];
	for (size_t i = 0; i < newSize; i++)
	{
		tempData[i] = this->data[i];
	}
	delete[] data;
	this->data = tempData;
}

template<class V>
inline void Vector<V>::resize(const int, const V&)
{
}

#endif VECTOR_H