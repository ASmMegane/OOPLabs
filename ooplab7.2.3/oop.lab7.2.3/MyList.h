#pragma once

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
	CMyList() : size(0), head(nullptr), tail(nullptr) {}
	CMyList(const CMyList & sourceList) : size(0), head(nullptr), tail(nullptr) { fillAllContent(sourceList); }
	//
	CMyList& operator=(const CMyList & sourceList)
	{
		fillAllContent(sourceList);
		return *this;
	};
	class iterator
	{
	public:
		friend class CMyList<T>;
		iterator(Node* curNode, bool isReverse = false) : isReverse(isReverse), curentNode(curNode) {}

		T & operator*() const
		{
			if (curentNode != nullptr)
			{
				return curentNode->value;
			}
		}

		Node* operator->()
		{
			return curentNode;
		}
		// TODO: add operator ->
		// it->field

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
				if (isReverse)
				{
					curentNode = curentNode->prevNode;
				}
				else
				{
					curentNode = curentNode->nextNode;
				}
			}
			return *this;
		}

		iterator& operator--()
		{
			if (isReverse)
			{
				curentNode = curentNode->nextNode;
			}
			else
			{
				curentNode = curentNode->prevNode;
			}
			return *this;
		}
	private:
		bool isReverse;
		Node* curentNode;
	};
	class iteratorConst : public iterator
	{
		const T & operator*() const
		{
			if (curentNode != nullptr)
			{
				return curentNode->value;
			}
		}

		const Node* operator->()
		{
			return curentNode;
		}
	};
	~CMyList();
	// TODO: add const version
	iterator begin() { return iterator(head, false); }
	iteratorConst begin() const { return iteratorConst(head, false); }

	iterator end() { return iterator(tail->nextNode, false); }
	iteratorConst end() const { return iteratorConst(tail->nextNode, false); }

	// TODO: fix reverse iterator reverse order traversing.
	iterator rbegin() { return iterator(tail, true); }
	iteratorConst rbegin() const { return iteratorConst(tail, true); }

	iterator rend() { return iterator(head->prevNode, true); }
	iteratorConst rend() const { return iteratorConst(head->prevNode, true); }

	void PushFront(const T); // todo: use const reference
	void PushBack(const T); // TODO: fix coding conventions violation.
	void insert(const iterator&, const T);
	iterator erase(iterator& itrForErase) {
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
		}
	}
	size_t GetSize() { return size; }
private:
	void deleteAllContent();
	void fillAllContent(const CMyList&);
	// TODO: fix coding style violation
	size_t size;
	Node* head;
	Node* tail;
};

// TODO: rename to PushFront or Prepend
template<typename T>
void CMyList<T>::PushFront(const T newElement)
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

// TODO: rename to PushBack or Append
template<typename T>
void CMyList<T>::PushBack(const T newElement)
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

template<typename T>
void CMyList<T>::deleteAllContent()
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

template<typename T>
CMyList<T>::~CMyList()
{
	deleteAllContent();
}

template<typename T> // TODO: add line break after template specification everywhere
void CMyList<T>::insert(const iterator & itrForInsert, const  T value) // TODO: fix `itrForInsert`, `value` constness.
{
	if (itrForInsert.curentNode == head)
	{
		PushFront(value);
	}
	else if (itrForInsert.curentNode == nullptr)
	{
		PushBack(value);
	}
	else
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->prevNode = itrForInsert.curentNode->prevNode;
		newNode->nextNode = itrForInsert.curentNode;
		itrForInsert.curentNode->prevNode->nextNode = newNode;
		itrForInsert.curentNode->prevNode = newNode;
		++size;
	}
}

template<typename T>
void CMyList<T>::fillAllContent(const CMyList & sourceList)
{
	deleteAllContent();
	Node* currentNode = sourceList.head;
	while (currentNode != nullptr)
	{
		PushBack(currentNode->value);
		currentNode = currentNode->nextNode;
	}
}
