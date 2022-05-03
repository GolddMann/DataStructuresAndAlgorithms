#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnweightedUnorderedGraph
{
private:
    vector<vector<int>> list;

public:
    UnweightedUnorderedGraph() {}
    UnweightedUnorderedGraph(vector<vector<int>> list)
    {
        for (int i = 0; i < list.size(); i++)
        {
            this->list.push_back({});
            for (int j = 0; j < list[0].size(); j++)
            {
                this->list[i].push_back(list[i][j]);
                if (this->list.size() < list[i][j] && find(this->list[list[i][j]].begin(), this->list[list[i][j]].end(), i) == this->list[list[i][j]].end())
                    this->list[list[i][j]].push_back(i);
            }
        }
    }
    void addEdge(int node1, int node2)
    {
        while (this->list.size() <= node1 || this->list.size() <= node2)
            this->list.push_back({});

        if (find(this->list[node1].begin(), this->list[node1].end(), node2) == this->list[node1].end())
            this->list[node1].push_back(node2);
        if (find(this->list[node2].begin(), this->list[node2].end(), node1) == this->list[node2].end())
            this->list[node2].push_back(node1);
    }

    bool hasEdge(int node1, int node2)
    {
        return find(this->list[node1].begin(), this->list[node1].end(), node2) != this->list[node2].end() || find(this->list[node2].begin(), this->list[node2].end(), node1) != this->list[node2].end();
    }

    void deleteEdge(int node1, int node2)
    {
        if (this->list.size() < node1 || this->list.size() < node2)
            cout << "Deletion error, node doesn't exist!\n";

        vector<int>::iterator it = find(this->list[node1].begin(), this->list[node1].end(), node2);
        if (it != this->list[node1].end())
        {
            this->list[node1].erase(it);
            this->list[node2].erase(find(this->list[node2].begin(), this->list[node2].end(), node1));
        }
        else
        {
            cout << "Deletion error, node doesn't exist!\n";
        }
    }

    bool isGraphUnordered()
    {
        for (int i = 0; i < list.size(); i++)
        {
            for (int j = 0; j < list[i].size(); j++)
            {
                if (find(list[i].begin(), list[i].end(), list[i][j]) == list[i].end() || find(list[list[i][j]].begin(), list[list[i][j]].end(), i) == list[list[i][j]].end())
                    return false;
            }
        }
        return true;
    }

    ~UnweightedUnorderedGraph() {}
};

int main()
{
    vector<vector<int>> g = {{1}, {0}};
    UnweightedUnorderedGraph graph(g);
    graph.addEdge(2, 1);
    if (graph.isGraphUnordered())
    {
        cout << "Graph is Unordered!\n";
    }
    if (graph.hasEdge(1, 2))
    {
        cout << "Graph has edge (1,2)!\n";
    }
    return 0;
}
