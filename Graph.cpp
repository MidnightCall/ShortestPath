#include "Graph.h"

Graph::Graph(){
}

bool Edge::operator<(const Edge& other) const {
	return weight < other.weight;
}

Edge::Edge() {

}

Edge::Edge(int weight, Node* from, Node* to) {
	this->weight = weight;
	this->from = from;
	this->to = to;
}

bool Node::operator==(const Node& other) const {
	return name == other.name;
}

bool Node::operator!=(const Node& other) const {
	return name != other.name;
}

bool Node::operator<(const Node& other) const {
	return name < other.name;
}

Node::Node() {

}

Node::Node(string name) {
	this->name = name;
}
