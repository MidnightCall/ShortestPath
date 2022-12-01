#include "Graph.h"

Graph::Graph(){
}

Graph::~Graph() {
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

Node::Node(int value, string name) {
	this->value = value;
	this->name = name;
}

Node::Node(int value, int in, int out, string name) {
	this->value = value;
	this->in = in;
	this->out = out;
	this->name = name;
}