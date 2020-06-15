#pragma once

#include <iostream>
#include <fstream>
#include "UnorderedLinkedList.h"

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