#ifndef GRAPH_H
#define GRAPH_H

struct Vertex {
	double coordinate_x = 0.0;
	double coordinate_y = 0.0;

	Vertex(double x = 0.0, double y = 0.0) : coordinate_x(x), coordinate_y(y) {}
};

struct Edge {
	int weight = 0;

	Edge(int weight = 0) : weight(weight) {}
};


class Graph {

public:
	Graph() {};
	~Graph() {};

private:
	
	std::vector<Vertex*> vertices;
	std::vector<Edge*> edges;
};

#endif // GRAPH_H