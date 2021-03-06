#ifndef GRAPH_H_
#define GRAPH_H_

#include "../Utilities/defs.h"
#include "../Utilities/exceptions.h"
#include <vector>
#include <iostream>
#include <cstdlib>

#include "Node.h"


class Graph {
private:
public:

private:
	double boundLeft;
	double boundRight;
	double boundBot;
	double boundTop;
	std::vector< Node > nodes;

	// Get the index of the node with id 'id' , -1 if not found
	int getNodeIndex(u_int nodeId) const;

public:
	Graph();

	// Add a new node to the graph
	u_int addNode(double x, double y, const std::string& name);

	// Add a new edge connecting two nodes
	bool addEdge(u_int nodeId1 , u_int nodeId2 , const double & weight);

    // Add a new edge connecting two nodes
    bool addEdge(u_int nodeId1 , u_int nodeId2 , const double & weight, const std::string& name);

	// Returns a pair with the Edge value and a boolean that says if the node exists or not ;
	// if the boolean is false, value makes no sense
	std::pair<double,bool> getEdgeVal(u_int nodeId1 , u_int nodeId2) const;

	// Returns success / failure (failure is when the node does not exist)
	bool setEdgeVal(u_int nodeId1 , u_int nodeId2 , const double & newVal);

    // Get the node with id 'id' , returns a Node with id of -1 if not found
    Node getNodeById(u_int id) const;

	// Returns all connected nodes with edge values
    // If it can't find any Node with the given nodeId, it throws NodeNotFound exception
	const std::vector< Edge > &getEdges(u_int nodeId);

	// Returns the number of nodes in the graph
	u_int getNumNodes() const;

	// Returns the number of edges in the graph
	u_int getNumEdges() const;

    // Returns the minimum Node Y coordinate
	double getBoundBot() const;

    // Returns the maximum Node Y coordinate
	double getBoundTop() const;

    // Returns the minimum Node X coordinate
	double getBoundLeft() const;

    // Returns the maximum Node X coordinate
	double getBoundRight() const;
};


#endif /* GRAPH_H_ */
