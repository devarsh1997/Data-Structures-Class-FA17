/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */
#include <iostream>
#include "graph_tools.h"

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    /* Your code here! */
	vector<Vertex> edgeque = BFS(graph);
	int min = 10000;
	Vertex a;
	Vertex b;
	for (unsigned i = 0; i < edgeque.size()/2; i++) {
		if (min > graph.getEdgeWeight(edgeque[2*i], edgeque[2*i+1])) {
			min = graph.getEdgeWeight(edgeque[2*i], edgeque[2*i+1]);
			a = edgeque[2*i];
			b = edgeque[2*i+1];
		}
	}
	graph.setEdgeLabel(a, b, "MIN");
	return min;
}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& g, Vertex start, Vertex end)
{
    /* Your code here! */
    // initialize
    for (Vertex& v : g.getVertices()){
        g.setVertexLabel(v, "UNEXPLORED");
        for (Vertex& j : g.getAdjacent(v)){
            g.setEdgeLabel(v,j, "UNEXPLORED");
        }
    }
    // traversal
    unordered_map<Vertex, Vertex> parent;
    queue<Vertex> q;
    Vertex v = start;
    g.setVertexLabel(v, "VISITED");
    q.push(v);
    while (!q.empty()){
        v = q.front();
        q.pop();
        for (Vertex& j : g.getAdjacent(v)){
            if (g.getVertexLabel(j) == "UNEXPLORED"){
            	// this edge is DISCOVERY!!!
                g.setEdgeLabel(v, j, "DISCOVERY");
                g.setVertexLabel(j, "VISITED");
                parent[j] = v;
                q.push(j);
            }else if (g.getEdgeLabel(v, j) == "UNEXPLORED"){
                g.setEdgeLabel(v, j, "CROSS");
            }
        }
    }
    int dis = 0;
    while (end != start){
    	g.setEdgeLabel(end, parent[end], "MINPATH");
    	end = parent[end];
    	dis += 1;
    }
    return dis;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort instead of creating a priority queue.
 */
bool edge_compare(Edge a, Edge b){
	return a.weight < b.weight;
}




void GraphTools::findMST(Graph& g)
{
    /* Your code here! */
    // sort edges
    // vector<Edge> edges = g.getEdges();
    // std::sort (edges.begin(), edges.end(), edge_compare);

    // // create set
    // DisjointSets forest;
    // int num = g.getVertices().size();
    // forest.addelements(num);
    // int edge_num = 0;
    // for (Edge& e : edges){
    // 	Vertex a = e.source;
    // 	Vertex b = e.dest;
    // 	if (forest.find(a) != forest.find(b)){
    // 		forest.setunion(a,b);
    // 		g.setEdgeLabel(a,b, "MST");
    // 		edge_num += 1;
    // 	}
    // 	if (edge_num == num-1){
    // 		break;
    // 	}
    // }
    vector<Vertex> vertex = g.getVertices();
    int vertex_size = vertex.size();
    std::map<Vertex, bool> T;
    for (Vertex& v : vertex){
        g.d[v] = 99999;
        T[v] = false;
    }
    Vertex start = vertex[0];
    g.d[start] = 0;
    T[start] = true;

    for (int i=0; i<vertex_size-1; i++){
        Vertex m = vertex.front();
        vertex.erase(vertex.begin());
        for (Vertex& a : g.getAdjacent(m)){
            if (T[a] == false && g.getEdgeWeight(a,m)<g.d[a]){
                g.d[a] = g.getEdgeWeight(a,m);
                g.setEdgeLabel(a,m, "MST");
            }
        }
        std::sort (vertex.begin(), vertex.end(), g.d_compare);
    }
    g.savePNG("prims.png");
}


// void GraphTools::findMST_prims(Graph& g){
    
//     vector<Vertex> vertex = g.getVertices();
//     int vertex_size = vertex.size();
//     std::map<Vertex, bool> T;
//     for (Vertex& v : vertex){
//         d[v] = 99999;
//         T[v] = false;
//     }
//     Vertex start = vertex[0];
//     d[start] = 0;
//     T[start] = true;

//     for (int i=0; i<vertex_size-1; i++){
//         Vertex m = vertex.front();
//         vertex.pop();
//         for (Vertex& a : g.getAdjacent(m)){
//             if (T[a] == false) && g.getEdgeWeight(a,m)<d[a]{
//                 d[a] = g.getEdgeWeight(a,m);
//                 g.setEdgeLabel(a,m, "MST");
//             }
//         }
//         std::sort (vertex.begin(), vertex.end(), d_compare);
//     }
//     g.savePNG("prims.png");
// }

vector<Vertex> GraphTools::BFS(Graph& g){
    for (Vertex& v : g.getVertices()){
        g.setVertexLabel(v, "UNEXPLORED");
        for (Vertex& j : g.getAdjacent(v)){
            g.setEdgeLabel(v,j, "UNEXPLORED");
        }
    }

    for (Vertex& v : g.getVertices()){
        if (g.getVertexLabel(v) == "UNEXPLORED"){
            BFS_(g,v);
        }
    }
    vector<Vertex> inorder;
	for(Vertex& v : g.getVertices()) {
		for(Vertex& j : g.getAdjacent(v)) {
			if (g.getEdgeLabel(v,j) == "DISCOVERY") {
				inorder.push_back(v);
				inorder.push_back(j);
			}
		}
	}
    return inorder;
}

void GraphTools::BFS_(Graph& g, Vertex& v){

    queue<Vertex> q;
    g.setVertexLabel(v, "VISITED");
    q.push(v);

    while (!q.empty()){
        v = q.front();
        q.pop();
        for (Vertex& j : g.getAdjacent(v)){
            if (g.getVertexLabel(j) == "UNEXPLORED"){
                g.setEdgeLabel(v, j, "DISCOVERY");
                g.setVertexLabel(j, "VISITED");
                q.push(j);
            }else if (g.getEdgeLabel(v, j) == "UNEXPLORED"){
                g.setEdgeLabel(v, j, "CROSS");
            }
        }
    }
}









