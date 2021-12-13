#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Time.h"

Graph::Graph(vector<int>::size_type rows, vector<int>::size_type columns, vector<int>::size_type ribs, int min, int max) :
    row_count(rows), column_count(columns), ribs_count(ribs), graph(row_count, vector<int>(column_count, 0)), 
    graph_ribs(row_count - 1), weights(row_count), tree_ribs(compare) {

    getRandomAdjacencyMatrix(min, max);

    for (vector<int>::size_type i = 0; i < this->row_count; i++) {
        for (vector<int>::size_type j = i + 1; j < this->column_count; j++) {
            if (i != j && graph[i][j]) {
                graph_ribs[i] = { i, j };
                weights[i] = graph[i][j];
                ribs_with_weights.push_back({ graph_ribs[i], weights[i] });
                tree_ribs.insert({ graph_ribs[i], weights[i] });
            }
        }
    }
}

void Graph::getRandomAdjacencyMatrix(int min, int max) {
    vector<int>::size_type r = ribs_count;
    for (vector<int>::size_type i = 0; i < this->row_count; i++) {
        for (vector<int>::size_type j = i+1; j < this->column_count; j++) {
            if (r == 0) {
                return;
            }
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = min + (min + (max - min)) * rand() / RAND_MAX;
                graph[j][i] = graph[i][j];
                r--;
            }
        }
    }
}

pair<vector<pair<int, int>>, int> Graph::CruscullArray() {
    if (ribs_count < row_count)
        return {};

    sort(ribs_with_weights.begin(), ribs_with_weights.end(), 
        [&](pair<pair<int, int>, int> first, pair<pair<int, int>, int> second)
        {return first.second < second.second; });

    //adding
    pair<vector<pair<int, int>>, int> res{ vector<pair<int,int>>(row_count - 1, {0,0}), 0};

    vector<int> tree(row_count, 0);
  
    // adding element with the smallest weight
    res.first[0] = ribs_with_weights[0].first;
    res.second += ribs_with_weights[0].second;
    tree[res.first[0].first] = 1;
    tree[res.first[0].second] = 1;
    
    for (int i = 1; i < row_count - 1; i++) {
        for (auto iterator = ribs_with_weights.begin(); iterator != ribs_with_weights.end(); iterator++) {
            if ((tree[(*iterator).first.first] + tree[(*iterator).first.second]) == 1) {
                res.first[i] = (*iterator).first;
                res.second += (*iterator).second;
                tree[res.first[i].first] = 1;
                tree[res.first[i].second] = 1;
                break;
            }
        }
    }

    return res;
}

pair<vector<pair<int, int>>, int> Graph::CruscullTree() {
    if (ribs_count < row_count)
        return {};

   //adding
    pair<vector<pair<int, int>>, int> res{ vector<pair<int,int>>(row_count - 1, {0,0}), 0 };

    vector<int> tree(row_count, 0);

    // adding element with the smallest weight
    res.first[0] = (*tree_ribs.begin()).first;
    res.second += (*tree_ribs.begin()).second;
    tree[res.first[0].first] = 1;
    tree[res.first[0].second] = 1;

    for (int i = 1; i < row_count - 1; i++) {
        for (auto iterator = tree_ribs.begin(); iterator != tree_ribs.end(); iterator++) {
            if ((tree[(*iterator).first.first] + tree[(*iterator).first.second]) == 1) {
                res.first[i] = (*iterator).first;
                res.second += (*iterator).second;
                tree[res.first[i].first] = 1;
                tree[res.first[i].second] = 1;
                break;
            }
        }
    }

    return res;
}

int main()
{
    int a = 1;
    cout << "1. Change ribs count\n2. Change vertexes count\n";
    cout << "Enter the operation number\n";
    cin >> a;
    if (a == 1) {
        ofstream CruscullArrayData("../CruscullArayRibs.txt");
        ofstream CruscullTreeData("../CruscullTreeRibs.txt");

        vector<int>::size_type vertexes, max_ribs, min_ribs, step, q, r;

        cout << "Vertexes count: ";
        cin >> vertexes;
        cout << "Maximum number of ribs: ";
        cin >> max_ribs;
        cout << "Minimum number of ribs: ";
        cin >> min_ribs;
        cout << "Step: ";
        cin >> step;
        cout << "Minimum weight: ";
        cin >> q;
        cout << "Maximum weight: ";
        cin >> r;

        CruscullArrayData << vertexes << ' ' << max_ribs << ' ' << min_ribs << ' ' << step;
        CruscullTreeData << vertexes << ' ' << max_ribs << ' ' << min_ribs << ' ' << step;

        Time time;
        for (vector<int>::size_type i = min_ribs; i <= max_ribs; i += step) {
            Graph GraphTest(vertexes, vertexes, i, q, r);

            time.resetTime();
            GraphTest.CruscullArray();
            auto CruscullArrayWorkingTime = time.getTime();

            time.resetTime();
            GraphTest.CruscullTree();
            auto CruscullTreeWorkingTime = time.getTime();

            CruscullArrayData << '\n' << CruscullArrayWorkingTime;
            CruscullTreeData << '\n' << CruscullTreeWorkingTime;
        }
    }
    else {
        if (a == 2) {
            ofstream CruscullArrayData("../CruscullArrayVertexes.txt");
            ofstream CruscullTreeData("../CruscullTreeVertexes.txt");

            int max_vertexes, min_vertexes, step, q, r;

            cout << "Maximum number of vertexes: ";
            cin >> max_vertexes;
            cout << "Minimum number of vertexes: ";
            cin >> min_vertexes;
            cout << "Step: ";
            cin >> step;
            cout << "Minimum weight: ";
            cin >> q;
            cout << "Maximum weight: ";
            cin >> r;

            min_vertexes = min_vertexes == 0 ? 1 : min_vertexes;

            CruscullArrayData << max_vertexes << ' ' << min_vertexes << ' ' << step;
            CruscullTreeData << max_vertexes << ' ' << min_vertexes << ' ' << step;

            Time time;
            for (int i = min_vertexes; i <= max_vertexes; i += step) {
                auto ribs = i > 0 ? i * (i - 1) / 2 : 1;
                Graph GraphTest(i, i, ribs, q, r);

                time.resetTime();
                GraphTest.CruscullArray();
                auto CruscullArrayWorkingTime = time.getTime();

                time.resetTime();
                GraphTest.CruscullTree();
                auto CruscullTreeWorkingTime = time.getTime();

                CruscullArrayData << '\n' << CruscullArrayWorkingTime;
                CruscullTreeData << '\n' << CruscullTreeWorkingTime;
            }
        }
    }
}