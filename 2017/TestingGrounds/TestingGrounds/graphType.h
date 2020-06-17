#pragma once

#include <iostream>
#include <fstream>
#include "UnorderedLinkedList.h"
#include "linkedQueueType.h"

class graphType
{
public:
	bool isEmpty() const;

	void createGraph();

	void clearGraph();

	void printGraph() const;

	void depthFirstTraversal();

	void dftAtVertex(int vertex);

	void breadthFirstTraversal();

	graphType(int size = 0);

	~graphType();

private:
	int maxSize;
	int gSize;
	UnorderedLinkedList<int>* graph;

	void dft(int v, bool visited[]);
};

bool graphType::isEmpty() const
{
	return (gSize == 0);
}

void graphType::createGraph()
{
	std::ifstream infile;
	char fileName[50];

	int vertex;
	int adjacentVertex;

	if (gSize != 0)
	{
		clearGraph(); // If the graph is not empty...clear it!
	}

	std::cout << "Enter input file name: ";
	std::cin >> fileName;
	std::cout << std::endl;

	infile.open(fileName);
	if (!infile)
	{
		std::cout << "Cannot open input file. " << fileName << std::endl;
		return;
	}

	infile >> gSize; // Read the amount of vertices

	for (int index = 0; index < gSize; index++)
	{
		infile >> vertex;
		infile >> adjacentVertex;

		while (adjacentVertex != -999)
		{
			graph[vertex].insertLast(adjacentVertex);
			infile >> adjacentVertex;
		}
	}

	infile.close();
}

void graphType::clearGraph()
{
	for (int index = 0; index < gSize; index++)
	{
		graph[index].destroyList();
	}
	gSize = 0;
}

void graphType::printGraph() const
{
	for (int index = 0; index < gSize; index++)
	{
		std::cout << index << " ";
		graph[index].print();
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void graphType::depthFirstTraversal()
{
	bool* visited;

	visited = new bool[gSize];

	for (int index = 0; index < gSize; index++)
		visited[index] = false;

	for (int index = 0; index < gSize; index++)
	{
		if (!visited[index])
			dft(index, visited);
	}

	delete[] visited;
}

void graphType::dftAtVertex(int vertex)
{
	bool* visited;
	visited = new bool[gSize];

	for (int index = 0; index < gSize; index++)
		visited[index] = false;

	dft(vertex, visited);

	delete[] visited;
}

void graphType::breadthFirstTraversal()
{
	linkedQueueType<int> queue;

	bool* visited = new bool[gSize];
	for (int ind = 0; ind < gSize; ind++)
		visited[ind] = false;

	linkedListIterator<int> graphIt;

	for (int index = 0; index < gSize; index++)
	{
		if (!visited[index])
		{
			queue.addQueue(index);
			visited[index] = true;
			std::cout << " " << index << " ";

			while (!queue.isEmptyQueue())
			{
				int u = queue.front();
				queue.deleteQueue();

				for (graphIt = graph[u].begin(); graphIt != graph[u].end(); ++graphIt)
				{
					int w = *graphIt;
					if (!visited[w])
					{
						queue.addQueue(w);
						visited[w] = true;
						std::cout << " " << w << " ";
					}
				}
			}
		}
	}

	delete[] visited;
}

graphType::graphType(int size)
{
	maxSize = size;
	gSize = 0;
	graph = new UnorderedLinkedList<int>[size];
}

graphType::~graphType()
{
	clearGraph();
}

void graphType::dft(int v, bool visited[])
{
	visited[v] = true;
	std::cout << " " << v << " ";

	linkedListIterator<int> graphIt;

	for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
	{
		int w = *graphIt;
		if (!visited[w])
		{
			dft(w, visited);
		}
	}
}
