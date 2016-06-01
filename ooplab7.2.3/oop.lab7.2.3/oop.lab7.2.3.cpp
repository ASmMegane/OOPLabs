#include "stdafx.h"
#include <iostream>

template<typename T>
class CMyList
{
	struct Node
	{
		T value;
		Node* nextNode;
		Node* prevNode;
	};
public:
	CMyList() {};
	CMyList(const CMyList & sourceList) { fillAllContent(sourceList); };
	CMyList& operator=(const CMyList & sourceList)
	{ 
		fillAllContent(sourceList); 
		return *this;
	};
	class iterator
	{
	public:
		friend class CMyList<T>;
		iterator(Node* curNode) { curentNode = curNode; };

		T & operator*() const
		{
			if (curentNode != nullptr)
			{
				return curentNode->value;
			}
		}

		bool operator==(const iterator& otherItr) const
		{
			return (curentNode == otherItr.curentNode);
		}

		bool operator!=(const iterator& otherItr) const
		{
			return (curentNode != otherItr.curentNode);
		}

		iterator& operator++()
		{
			if (curentNode != nullptr)
			{
				curentNode = curentNode->nextNode;
			}
			return *this;
		}

		iterator& operator--()
		{
			if (curentNode != nullptr)
			{
				curentNode = curentNode->prevNode;
			}
			return *this;
		}
	private:
		Node* curentNode;
	};
	~CMyList();
	iterator begin() { return iterator(head); };
	iterator end() { return iterator(nullptr); };
	iterator rbegin() { return iterator(tail); };
	iterator rend() { return iterator(nullptr); };
	void addEnd(T);
	void addBegin(T);
	void insert(iterator&, T);
	iterator erase(iterator& itrForErase)
	{
		if (itrForErase.curentNode == nullptr)
		{
			return itrForErase;
		}
		if (itrForErase.curentNode == head && itrForErase.curentNode == tail)
		{
			delete itrForErase.curentNode;
			head = nullptr;
			tail = nullptr;
			size--;
			return iterator(nullptr);
		}
		if (itrForErase.curentNode == tail)
		{
			itrForErase.curentNode->prevNode->nextNode = itrForErase.curentNode->nextNode;
			tail = itrForErase.curentNode->prevNode;
			delete itrForErase.curentNode;
			size--;
			return iterator(tail->nextNode);

		}
		if (itrForErase.curentNode == head)
		{
			itrForErase.curentNode->nextNode->prevNode = itrForErase.curentNode->prevNode;
			head = itrForErase.curentNode->nextNode;
			delete itrForErase.curentNode;
			size--;
			return iterator(head);
		}
		itrForErase.curentNode->nextNode->prevNode = itrForErase.curentNode->prevNode;
		itrForErase.curentNode->prevNode->nextNode = itrForErase.curentNode->nextNode;
		iterator nextNodeItr(itrForErase.curentNode->nextNode);
		delete itrForErase.curentNode;
		size--;
		return nextNodeItr;
	};
	size_t getSize() { return size; };
private:
	void deleteAllContent();
	void fillAllContent(const CMyList&);
	size_t size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
};

template<typename T> void CMyList<T>::addBegin(T newElement)
{
	Node* newNode = new Node();
	newNode->value = newElement;
	newNode->prevNode = nullptr;
	newNode->nextNode = head;
	if (head != nullptr)
	{
		head->prevNode = newNode;		
	}
	else
	{
		tail = newNode;
	}
	head = newNode;
	size++;
}

template<typename T> void CMyList<T>::addEnd(T newElement)
{
	Node* newNode = new Node();
	newNode->value = newElement;
	newNode->prevNode = tail;
	newNode->nextNode = nullptr;
	if (tail != nullptr)
	{
		tail->nextNode = newNode;
	}
	else
	{
		head = newNode;
	}
	tail = newNode;
	size++;
}

template<typename T> CMyList<T>::~CMyList()
{
	deleteAllContent();
}

template<typename T> void CMyList<T>::deleteAllContent()
{
	Node* nextNode = nullptr;
	while (head != nullptr)
	{
		nextNode = head->nextNode;
		delete head;
		head = nextNode;
	}
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T> void CMyList<T>::insert(iterator & itrForInsert, T value)
{
	if (itrForInsert.curentNode == head)
	{
		addBegin(value);
	}
	else if (itrForInsert.curentNode == nullptr)
	{
		addEnd(value);
	}
	else
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->prevNode = itrForInsert.curentNode->prevNode;
		newNode->nextNode = itrForInsert.curentNode;
		itrForInsert.curentNode->prevNode->nextNode = newNode;
		itrForInsert.curentNode->prevNode = newNode;
		size++;
	}
}

template<typename T> void CMyList<T>::fillAllContent(const CMyList & sourceList)
{
	deleteAllContent();
	Node* currentNode = sourceList.head;
	while (currentNode != nullptr)
	{
		addEnd(currentNode->value);
		currentNode = currentNode->nextNode;
	}
}

/*template<typename T> 
CMyList<T>::iterator CMyList<T>::erase(iterator & itrForErase)
{
	if (itrForErase.curentNode == nullptr)
	{
		return itrForErase;
	}
	if (itrForErase.curentNode == head && itrForErase.curentNode == tail)
	{
		delete itrForErase.curentNode;
		head = nullptr;
		tail = nullptr;
		size--;
		return iterator(nullptr);
	}
	if (itrForErase.curentNode == tail)
	{
		itrForErase.curentNode->prevNode->nextNode = itrForErase.curentNode->nextNode;
		tail = itrForErase.curentNode->prevNode;
		delete itrForErase.curentNode;
		size--;
		return iterator(tail->nextNode);
		
	}
	if (itrForErase.curentNode == head)
	{
		itrForErase.curentNode->nextNode->prevNode = itrForErase.curentNode->prevNode;
		head = itrForErase.curentNode->nextNode;
		delete itrForErase.curentNode;
		size--;
		return iterator(head);
	}
	itrForErase->nextNode->prevNode = itrForErase->prevNode;
	itrForErase->prevNode->nextNode = itrForErase->nextNode;
	iterator nextNodeItr(itrForErase->nextNode);
	delete itrForerase;
	size--;
	return nextNodeItr;
}*/

int main()
{
	CMyList<int> myList;
	myList.addBegin(6);
	myList.addEnd(1);	
	std::cout << myList.getSize() <<std::endl;
	CMyList<int>::iterator itr = myList.begin();
	std::cout << *itr << std::endl;
	for (itr; itr != myList.end(); ++itr)
	{
		std::cout << *itr << std::endl;
	}
	itr = myList.begin();
	++itr;
	myList.insert(itr, 9);
	CMyList<int> myList2 = myList;
	myList.addBegin(4);
	CMyList<int> myList3(myList);
	itr = myList.erase(itr);
	std::cout << *itr << std::endl;
    return 0;
}

