#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <random>

using namespace std;

bool compare(pair<pair<int, int>, int> rib1, pair<pair<int, int>, int> rib2) {
	return rib1.second < rib2.second;
}

class Graph {
	vector<int>::size_type row_count, column_count, ribs_count;
	vector<int> weights;
	vector<pair<int, int>> graph_ribs;
	vector<pair<pair<int, int>, int>> ribs_with_weights;
	vector<vector<int>> graph;
	multiset<pair<pair<int, int>, int>, bool (*) (pair<pair<int, int>, int>, pair<pair<int, int>, int>)> tree_ribs;

public:
	Graph(vector<int>::size_type rows, vector<int>::size_type columns, vector<int>::size_type ribs, int min, int max);
    void getRandomAdjacencyMatrix(int min, int max);
	pair<vector<pair<int, int>>, int> CruscullArray();
	pair<vector<pair<int, int>>, int> CruscullTree();
};
