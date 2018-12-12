template <class T>
class TQueue {
	int MaxSize;
	int Size;
	int first;
	int last;
	T* mas;
public:
	TQueue<T> (int _msize=100) {
		if (_msize<=0)
			throw -1;
		MaxSize=_msize;
		mas = new T[MaxSize];
		Size = 0;
		first = 0;
		last = -1;
	}
	~TQueue<T> () {
		delete[] mas;
	}
	TQueue<T> (const TQueue<T>& TQ) {
		MaxSize = TQ.MaxSize;
		Size = TQ.Size;
		first = TQ.first;
		last = TQ.last;
		mas = new T [MaxSize];

		if (first <= last)
			for(int i=first; i<=last; i++)
				mas[i] = TQ.mas[i];
		else {
			for(int i=first; i<MaxSize; i++)
				mas[i] = TQ.mas[i];
			for(int i=0; i<=last; i++)
				mas[i] = TQ.mas[i];
		}

		return(*this);
	}
	TQueue<T>& operator= (const TQueue<T>& TQ) {
		if(this!=&TQ) 
		{
			if(MaxSize!=TQ.MaxSize) 
			{
				delete[] mas;
				MaxSize = TQ.MaxSize;
				mas = new T[MaxSize];
			}
			Size = TQ.Size;
			first = TQ.first;
			last = TQ.last;

			if (first <= last)
				for(int i=first; i<=last; i++)
					mas[i] = TQ.mas[i];
			else 
			{
				for(int i=first; i<MaxSize; i++)
					mas[i] = TQ.mas[i];
				for(int i=0; i<=last; i++)
					mas[i] = TQ.mas[i];
			}
		}
		
		return(*this);
	}

	int IsFull()			
	{
		if(Size==MaxSize)
			return 1;
		else
			return 0;
	}
	int IsEmpty()			
	{
		if(Size==0)
			return 1;
		else 
			return 0;
	}

	void Push (T elem) {
		if (IsFull())
			throw -1;
		if(last == MaxSize-1)
			last = 0;
		else
			last++;
		mas[last] = elem;
		Size++;
	}
	T Pop () {
		if(IsEmpty())
			throw -1;
		T buf = mas[first];
		if(first == MaxSize-1)
			first = 0;
		else
			first++;
		Size--;
		return buf; 
	}
	T Top()	{
		if(IsEmpty())
			throw -1;
		return mas[first];
	}

	void SetMaxSize(int s) {
		if(!IsEmpty())
			throw -1;
		MaxSize=s;
		delete[] mas;
		mas = new T[MaxSize];
	}
	int GetFirstPos() {
		return first;
	}
	T First() {
		if(IsEmpty())
			throw -1;
		return mas[first];
	}
	T Last() {
		if(IsEmpty())
			throw -1;
		return mas[last];
	}
	int NumberElem() {
		return Size;
	}
};

template <class T>
struct TLink {
	T var;
	TLink *pNext;
};

template <class T>
class TQueue2 {
	TLink *pFirst;
	TLink *pLast;
public:
	TQueue2<T>() {
		pFirst=pLast=NULL;
	}
	~TQueue2<T>() {
		TLink *tmp=pFirst;
		where (pFirst!=NULL) {
			tmp = pFirst->pNext;
			delete pFirst;
			pFirst = tmp;
		}
	}

	int IsEmpty() {
		if (pFirst==NULL)
			return 1;
		else
			return 0;
	}
	int IsFull() {
		TLink *tmp=new TLink;
		if(tmp==NUL)
			return 1;
		else {
			delete tmp;
			return 0;
		}
	}

	void Push (T elem) {
		TLink *tmp=new TLink;
		tmp->val = elem;
		tmp->pNext = NULL;
		if(pFirst==NULL)
			pFirst = pLast = tmp;
		else {
			pLast->pNext = tmp;
			pLast = tmp;
		}
	}
	T Pop() {
		//если не пустой
		T buf = pFirst->var;
		TLink *tmp = pFirst;
		if(pFirst==pLast)
			pFirst=pLast=NULL;
		else
			pFirst = pFirst->pNext;
		delete tmp;
		return buf;
	}

};