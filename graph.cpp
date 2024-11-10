#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <unordered_map>
#include <climits>
#include <unordered_set>
using namespace std;
class graph
{
public:
    unordered_map<string, vector<pair<string, int>>> adjlist;
    graph() {}
    void add(const string &newone)
    {
        adjlist[newone] = vector<pair<string, int>>();
    }
    void link(const string &from, const string &to, int length = INT_MAX)
    {
        adjlist[from].push_back(make_pair(to, length));
    }
    void remove(const string &from, const string &to)
    {
        auto it = adjlist[from].begin();
        while (it != adjlist[from].end())
        {
            if (it->first == to)
            {
                it = adjlist[from].erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
    void topsort()
    {
        unordered_map<string, int> indegree;
        for (const auto &pair : adjlist)
            indegree[pair.first] = 0;
        for (const auto &pair : adjlist)
        {
            for (const auto &edge : pair.second)
            {
                indegree[edge.first] += 1;
            }
        }
        queue<string> myqueue;
        for (const auto &pair : indegree)
        {
            if (pair.second == 0)
                myqueue.push(pair.first);
        }
        while (!myqueue.empty())
        {
            string tmp = myqueue.front();
            cout << tmp << "->";
            myqueue.pop();
            for (const auto &edge : adjlist[tmp])
            {
                if (indegree[edge.first] != 0)
                    indegree[edge.first] -= 1;
                if (indegree[edge.first] == 0)
                    myqueue.push(edge.first);
            }
        }
    }
    void dijkstra(const string start)
    {
        unordered_map<string, int> dist;
        for (const auto &pair : adjlist)
        {
            dist[pair.first] = INT_MAX;
        }
        dist[start] = 0;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> myqueue;
        myqueue.push(make_pair(0, start));
        while (!myqueue.empty())
        {
            string u = myqueue.top().second;
            int d = myqueue.top().first;
            myqueue.pop();
            if (d > dist[u])
                continue;
            for (const auto &edge : adjlist[u])
            {
                string v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    myqueue.push(make_pair(dist[v], v));
                }
            }
        }
        for (const auto &pair : adjlist)
        {
            string node = pair.first;
            if (dist[node] == INT_MAX)
                cout << "the shortest distance from " << start << " to " << node << " is infinity\n";
            else
                cout << "the shortest distance from " << start << " to " << node << " is " << dist[node] << "\n";
        }
    }
    void floyd()
    {
        unordered_map<string, int> nodeindice;
        int index = 0;
        for (const auto &pair : adjlist)
        {
            nodeindice[pair.first] = index++;
        }
        int n = nodeindice.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (const auto &pair : adjlist)
        {
            int uindex = nodeindice[pair.first];
            for (const auto &edge : pair.second)
            {
                int vindex = nodeindice[edge.first];
                dist[uindex][vindex] = edge.second;
            }
        }
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        for (const auto &pair1 : nodeindice)
        {
            for (const auto &pair2 : nodeindice)
            {
                string u = pair1.first;
                string v = pair2.first;
                if (u == v)
                    ;
                else if (dist[pair1.second][pair2.second] == INT_MAX)
                    cout << "no way from " << u << " to " << v << "\n";
                else
                    cout << "the shortest way from " << u << " to " << v << " is " << dist[pair1.second][pair2.second] << "\n";
            }
        }
    }
    void prim(const string &start)
    {
        unordered_set<string> mst;
        unordered_map<string, int> key;
        unordered_map<string, string> parent;
        for (const auto &pair : adjlist)
        {
            key[pair.first] = INT_MAX;
            parent[pair.first] = "";
        }
        key[start] = 0;
        for (int i = 0; i < adjlist.size(); ++i)
        {
            string u;
            int minkey = INT_MAX;
            for (const auto &pair : key)
            {
                if (mst.find(pair.first) == mst.end() && pair.second < minkey)
                {
                    u = pair.first;
                    minkey = pair.second;
                }
            }
            mst.insert(u);
            for (const auto &edge : adjlist[u])
            {
                string v = edge.first;
                int weight = edge.second;
                if (mst.find(v) == mst.end() && weight < key[v])
                {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }
        int totalweight = 0;
        for (const auto &pair : key)
        {
            if (pair.second != INT_MAX)
                totalweight += pair.second;
        }
        cout << "smallest totalweight is " << totalweight << endl;
    }
};
int main()
{
    graph test = graph();
    test.add("season");
    test.add("melin");
    test.add("feybur");
    test.add("zangji");
    test.add("seki");
    test.link("season", "melin", 5);
    test.link("melin", "season", 5);
    test.link("season", "feybur", 4);
    test.link("feybur", "season", 4);
    test.link("season", "zangji", 10);
    test.link("zangji", "season", 10);
    test.link("feybur", "zangji", 2);
    test.link("zangji", "feybur", 2);
    test.link("seki", "zangji", 2);
    test.link("zangji", "seki", 2);
    test.prim("season");
    return 1;
}