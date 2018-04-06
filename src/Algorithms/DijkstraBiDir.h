//
// Created by reeckset on 31-03-2018.
//

#ifndef CAL_DIJKSTRABIDIR_H
#define CAL_DIJKSTRABIDIR_H

#include "Dijkstra.h"

typedef vector<Edge> EdgeList;

class DijkstraBiDir : public Dijkstra {
public:
    DijkstraBiDir(const Graph &graph);
    vector<u_int> calcOptimalPath(u_int startNodeId, u_int finishNodeId, const NodeHashTable & pois);
    void printSolution();
    Node getBestPOI();
    bool foundSolution() const;

private:
    vector<EdgeList> reversedEdges;
    set<DNode> pQueueReversed;
    DNode topDNodeReversed;
    DNodeHashTable checkedDNodesReversed;
    NodeHashTable pois;
    double bestPOIWeight = DBL_MAX;
    u_int bestPOIId = UINT_MAX;
    bool foundAPOI = false;


    // Clears the data structures for new calculation, populates DNodes pQueue and Reversed edges
    void initDataStructures();
    void populateReversedEdges();

    void populateReversedQueue();

    void updateReversedQueue();

    bool isReverseCheckedNode(u_int nodeId) const;

    bool isNodePOI(const Node & node) const;

    void updateReversedTopNode();

    void updateBestPoi(const DNode & commonNode);

    void buildPath();

    // Checks if the node on top of the queue is a dead end
    bool isReversedTopNodeDeadEnd() const;

    // Removes the topDNode from the pQueue
    void removeReversedTopNodeFromQueue();
};


#endif //CAL_DIJKSTRABIDIR_H