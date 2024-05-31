#pragma once

#include <cstdlib>

using namespace std;

class DoublyLinkedList
{
public:
	DoublyLinkedList(int maximumNodeCount)
	{
		this->handleParameterLessThanOrEqualToZeroError(maximumNodeCount);

		this->maximumNodeCount = maximumNodeCount;
		this->currentNodeCount = 0;
		this->firstNode = NULL;
		this->lastNode = NULL;
	}

	int getMaximumNodeCount()
	{
		return this->maximumNodeCount;
	}

	int getCurrentNodeCount()
	{
		return this->currentNodeCount;
	}

	int* getNodeValues()
	{
		int* nodeValues = new int[this->currentNodeCount];
		DoublyLinkedListNode* doublyLinkedListNode = firstNode;
		for (int index = 0; index < this->currentNodeCount; index += 1)
		{
			nodeValues[index] = doublyLinkedListNode->getValue();
			doublyLinkedListNode = doublyLinkedListNode->getNextNode();
		}
		return nodeValues;
	}

	int getFirstNodeValue()
	{
		if (this->firstNode == NULL)
		{
			return NULL;
		}

		DoublyLinkedListNode* doublyLinkedListNode = this->firstNode;
		return doublyLinkedListNode->getValue();
	}

	int getLastNodeValue()
	{
		if (this->lastNode == NULL)
		{
			return NULL;
		}

		DoublyLinkedListNode* doublyLinkedListItem = this->lastNode;
		return doublyLinkedListItem->getValue();
	}

	void appendAtFirstNode(int value)
	{
		this->handleContainerFullError();

		DoublyLinkedListNode* doublyLinkedListNode = new DoublyLinkedListNode(value);
		if (this->firstNode == NULL && this->lastNode == NULL)
		{
			this->firstNode = doublyLinkedListNode;
			this->lastNode = doublyLinkedListNode;
		}
		else
		{
			this->firstNode->linkPreviousNode(doublyLinkedListNode);
			doublyLinkedListNode->linkNextNode(this->firstNode);
			this->firstNode = doublyLinkedListNode;
		}

		currentNodeCount += 1;
	}

	void appendAtLastNode(int value)
	{
		this->handleContainerFullError();

		DoublyLinkedListNode* doublyLinkedListNode = new DoublyLinkedListNode(value);
		if (this->firstNode == NULL && this->lastNode == NULL)
		{
			this->firstNode = doublyLinkedListNode;
			this->lastNode = doublyLinkedListNode;
		}
		else
		{
			this->lastNode->linkNextNode(doublyLinkedListNode);
			doublyLinkedListNode->linkPreviousNode(this->lastNode);
			this->lastNode = doublyLinkedListNode;
		}

		currentNodeCount += 1;
	}

	void removeAtFirstNode()
	{
		this->handleContainerEmptyError();

		if (this->firstNode == this->lastNode)
		{
			delete this->firstNode;
			delete this->lastNode;
		}
		else
		{
			DoublyLinkedListNode* doublyLinkedListNode = this->firstNode;
			this->firstNode = this->firstNode->getNextNode();

			delete doublyLinkedListNode;
		}

		this->currentNodeCount -= 1;
	}

	void removeAtLastNode()
	{
		this->handleContainerEmptyError();

		if (this->firstNode == this->lastNode)
		{
			delete this->firstNode;
			delete this->lastNode;
		}
		else
		{
			DoublyLinkedListNode* doublyLinkedListNode = this->lastNode;
			this->lastNode = this->lastNode->getPreviousNode();

			delete doublyLinkedListNode;
		}

		this->currentNodeCount -= 1;
	}

	int indexOfNode(int value)
	{
		DoublyLinkedListNode* doublyLinkedListNode = this->firstNode;
		for (int index = 0; index < this->currentNodeCount; index += 1)
		{
			int nodeValue = doublyLinkedListNode->getValue();
			if (nodeValue == value)
			{
				return index;
			}

			doublyLinkedListNode = doublyLinkedListNode->getNextNode();
		}

		return -1;
	}

	void reverse()
	{
		DoublyLinkedListNode* node_a = this->firstNode;
		DoublyLinkedListNode* node_b = this->firstNode->getNextNode();
		DoublyLinkedListNode* node_c = this->firstNode->getNextNode()->getNextNode();
		node_b->unlinkNextNode();
		node_a->linkPreviousNode(node_b);
		while (node_c != NULL)
		{
			node_b->unlinkNextNode();
			node_b->linkNextNode(node_a);
			node_c->unlinkPreviousNode();
			node_b->linkPreviousNode(node_c);

			node_a = node_b;
			node_b = node_c;
			node_c = node_c->getNextNode();
		}

		node_b->linkNextNode(node_a);

		DoublyLinkedListNode* temp = this->firstNode;
		this->firstNode = this->lastNode;
		this->lastNode = temp;
	}

private:
	class DoublyLinkedListNode
	{
	public:
		DoublyLinkedListNode(int value)
		{
			this->value = value;
			this->nextNode = NULL;
			this->previousNode = NULL;
		}

		int getValue()
		{
			return this->value;
		}

		DoublyLinkedListNode* getNextNode()
		{
			return this->nextNode;
		}

		void linkNextNode(DoublyLinkedListNode* nextNode)
		{
			this->nextNode = nextNode;
		}

		void unlinkNextNode()
		{
			this->nextNode = NULL;
		}

		DoublyLinkedListNode* getPreviousNode()
		{
			return this->previousNode;
		}

		void linkPreviousNode(DoublyLinkedListNode* previousNode)
		{
			this->previousNode = previousNode;
		}

		void unlinkPreviousNode()
		{
			this->previousNode = NULL;
		}


	private:
		int value;
		DoublyLinkedListNode* nextNode;
		DoublyLinkedListNode* previousNode;
	};

	int maximumNodeCount;
	int currentNodeCount;
	DoublyLinkedListNode* firstNode;
	DoublyLinkedListNode* lastNode;

	void handleParameterLessThanOrEqualToZeroError(int maximumNodeCount)
	{
		if (maximumNodeCount <= 0)
		{
			cout << "ParameterLessThanOrEqualToZeroError";
			exit(1);
		}
	}

	void handleContainerFullError()
	{
		if (this->currentNodeCount >= this->maximumNodeCount)
		{
			cout << "ContainerFullError";
			exit(1);
		}
	}

	void handleContainerEmptyError()
	{
		if (this->currentNodeCount <= 0)
		{
			cout << "ContainerEmptyError";
			exit(1);
		}
	}
};
