#include "graphType.h"

using namespace std;

int main(void)
{
	graphType graph(100);

	graph.createGraph();
	graph.printGraph();

	cout << "DepthFirstTraversal:" << endl;
	graph.depthFirstTraversal();
	cout << endl;

	cout << "BreadthFirstTraversal:" << endl;
	graph.breadthFirstTraversal();
	cout << endl;

	return 0;
}