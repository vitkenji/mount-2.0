#pragma once
#include "std.h"

namespace List
{
	template<class TL>
	class List
	{
	private:

		template<class TE>
		class Node
		{
		private:
			Node<TE>* pNext;
			TE* pData;

		public:
			Node()
			{
				pNext = nullptr;
				pData = nullptr;

			}

			~Node()
			{
				pNext = nullptr;
				pData = nullptr;

			}

			void setNext(Node<TE>* pNext) { this->pNext = pNext; }
			Node<TE>* getNext() { return this->pNext; }
			void setData(TE* pData) { this->pData = pData;  }
			TE* getData() { return pData; }

		};

		Node<TL>* pFirst;
		Node<TL>* pLast;
		unsigned int size;

	public:
		List();
		~List();
		void clear();
		unsigned int getSize() { return size; }
		TL* operator[](int index);
		void push(TL* pData);
		TL* pop(TL* pData);
		TL* pop(int index);

	private:
		void setNode(Node<TL>* pNode);
		Node<TL>* getPfirst() { return pFirst; }
		Node<TL>* getPlast() { return pLast; }

	};

	template<class TL>
	List<TL>::List() : pFirst(nullptr), pLast(nullptr), size(0){}

	template<class TL>
	List<TL>::~List() {}

	template<class TL>
	void List<TL>::clear()
	{
		Node<TL>* pAux1; Node<TL>* pAux2;
		pAux1 = pFirst; pAux2 = pAux1;
		int i = 0;

		while (pAux1 != nullptr && i < size)
		{
			delete(pAux1->getData());
			pAux2 = pAux1->getNext();
			delete(pAux1);
			pAux1 = pAux2;
			i++;

		}
		pFirst = nullptr;
		pLast = nullptr;
		size = 0;

	}

	template<class TL>
	void List<TL>::setNode(Node<TL>* pNode)
	{
		if (pNode != nullptr)
		{
			if (pFirst == nullptr)
			{
				pFirst = pNode;
				pLast = pNode;

			}
			else
			{
				pLast->setNext(pNode);
				pLast = pNode;
			}
			size++;

		}
		else { std::cout << "error on setnode" << std::endl; }

	}

	template<class TL>
	TL* List<TL>::operator[](int index)
	{
		if(index >= size || index < 0) { std::cout << "error : segmentation fault on list"; exit(1); }

		Node<TL>* pAux = pFirst;

		for (int i = 0; i < index; i++) { pAux = pAux->getNext(); }

		if (pAux == nullptr) { std::cout << "error: paux is nullptr"; exit(1); }

		return pAux->getData();

	}

	template<class TL>
	void List<TL>::push(TL* pData)
	{
		if (pData != nullptr)
		{
			Node<TL>* pNode = nullptr;
			pNode = new Node<TL>();
			pNode->setData(pData);
			setNode(pNode);

		}

		else { std::cout << "error" << std::endl; }

	}

	template<class TL>
	TL* List<TL>::pop(TL* pData)
	{
		Node<TL>* pAux = pFirst;
		Node<TL>* pPrev = nullptr;

		while (pAux != nullptr) {
			if (pAux->getData() == pData) {
				if (pAux == pFirst)
				{
					pFirst = pAux->getNext();

				}
				else if (pAux == pLast)
				{
					pLast = pPrev;
					pPrev->setNext(nullptr);
				
				}
				else
				{
					pPrev->setNext(pAux->getNext());

				}
				delete (pAux);
				size--;
				return pData;
			}

			pPrev = pAux;
			pAux = pAux->getNext();
		}
		return nullptr;
	}

	template<class TL>
	TL* List<TL>::pop(int index)
	{
		if (index >= size || size < 0) { std::cout << "error : invalid index" << std::endl; exit(1); }
		
		Node<TL>* pAux = pFirst;
		Node<TL>* pPrev = nullptr;

		for (int i = 0; i < index; i++)
		{
			pPrev = pAux;
			pAux = pAux->getNext();
		}

		if (pAux = pFirst) { pFirst = pAux->getNext(); }

		else if (pAux = pLast) { pLast = pPrev; pPrev->setNext(nullptr); }

		else { pPrev->setNext(pAux->getNext()); }

		TL* pData = pAux->getData();
		delete(pAux);
		size--;

		return pData;

	}
}