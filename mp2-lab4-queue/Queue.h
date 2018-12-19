#pragma once
template <class T>
class TQueue
{
private:
	int Size, MaxSize, first, last;
	T* ord;
public:
	TQueue(int _MaxSize = 10);
	TQueue(const TQueue <T> &queue);
	~TQueue();
	TQueue operator =(const TQueue  &queue);
	bool operator==(const TQueue <T> &queue) const;
	bool operator!=(const TQueue &queue) const;
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(const T elem);
	int GetSize() { return Size; }
	int GetMaxSize() { return MaxSize; }
	int First() { return first; }
	T Pop();
	T WhoIsFirst() const;
	T WhoIsLast()const;
	void Clear();

};

template <class T>
TQueue <T>::TQueue(int _MaxSize)
{
	if (_MaxSize <= 0)
		throw _MaxSize;
	MaxSize = _MaxSize;
	ord = new T[MaxSize];
	first = 0;
	last = -1;
	Size = 0;
}
template <class T>
TQueue <T> ::TQueue(const TQueue <T> & queue)
{
	MaxSize = queue.MaxSize;
	first = queue.first;
	last = queue.last;
	Size = queue.Size;
	ord = new T[MaxSize];
	for (int i = 0; i < MaxSize; i++)
		ord[i] = queue.ord[i];
}
template <class T>
TQueue<T> ::~TQueue()
{
	delete[] ord;
}

template <class T>
TQueue <T> TQueue <T>::operator=(const TQueue <T> &queue)
{
	if (MaxSize != queue.MaxSize)
	{
		delete[] ord;
		ord = new T[queue.MaxSize];
	}
	MaxSize = queue.MaxSize;
	first = queue.first;
	last = queue.last;
	Size = queue.Size;
	for (int i = 0; i < MaxSize; i++)
		ord[i] = queue.ord[i];
	return *this;
}
template <class T>
bool TQueue <T>::operator==(const TQueue  &queue) const
{
	if (!(MaxSize == queue.MaxSize && Size == queue.Size && first == queue.first && last && queue.last))
		return false;
	for (int i = 0; i < MaxSize; i++)
		if (ord[i] != queue.ord[i])
			return false;
	return true;
}
template <class T>
bool TQueue <T>::operator!=(const TQueue &queue) const
{
	return !(*this == queue);
}
template <class T>
bool  TQueue <T>::IsEmpty() const
{
	if (Size == 0)
		return true;
	else
		return false;
}
template <class T>
bool TQueue <T> ::IsFull() const
{
	if (Size == MaxSize)
		return true;
	else
		return false;
}
template <class T>
void TQueue <T>::Push(const T elem)
{
	if (this->IsFull())
		throw "Queue is full";
	if (last == MaxSize - 1)
		last = 0;
	else
		last++;
	ord[last] = elem;
	Size++;
}
template <class T>
T TQueue <T> ::Pop()
{
	if (this->IsEmpty())
		throw "Queue is empty";
	int tmp = first;
	first++;
	first = first % MaxSize;
	Size--;
	return ord[tmp];
}
template <class T>
T TQueue <T>::WhoIsFirst() const
{
	if (IsEmpty())
		throw "queue is empty";
	return ord[first];
}
template <class T>
T TQueue <T>::WhoIsLast() const
{
	return ord[last];
}
template <class T>
void TQueue<T>::Clear()
{
	delete[] ord;
	ord = new T[queue.MaxSize];
	first = 0;
	last = -1;
	Size = 0;

}