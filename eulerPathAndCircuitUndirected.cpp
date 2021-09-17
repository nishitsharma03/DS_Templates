#include<bits/stdc++.h>
#define ll long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;


// 0-based indexing
// Time Complexity: O(V+ ElogE)
// Space Complexity: O(V+E)
class eulerUndirected
{

	vector<vector<int>> v;
	int n;
	set<pair<int, int>> visitedEdges;
public:
	eulerUndirected(int n)
	{
		this->n = n;
		this->v.resize(n);
	}

	void addEdge(int x, int y)
	{
		v[x].push_back(y);
		v[y].push_back(x);

	}

	bool isConnected()
	{

		vector<int> vis(n);

		this->checkConnected(0, vis);

		for (int i = 0; i < n; i++)
		{
			if (int(v[i].size()) > 0 and vis[i] == 0)
				return false;
		}

		return true;
	}

	void checkConnected(int src, vector<int> &vis)
	{
		vis[src] = true;
		for (auto &i : v[src])
		{
			if (!vis[i])
				checkConnected(i, vis);
		}
	}


	bool eulerCircuitExists()
	{
		for (int i = 0; i < n; i++)
		{
			if (int(v[i].size()) % 2)
			{
				return false;
			}
		}

		return this->isConnected();
	}


	bool eulerPathExists()
	{
		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			cnt += (int(v[i].size()) % 2);
			if (cnt > 2)
				return false;
		}
		return this->isConnected();
	}


	void dfs(int src, vector<int> &final, vector<int> &temp)
	{

		temp.push_back(src);
		while (int(v[src].size()) > 0)
		{
			int newNode = v[src].back();
			v[src].pop_back();
			if (visitedEdges.find({newNode, src}) == visitedEdges.end())
			{
				visitedEdges.insert({src, newNode});
				dfs(newNode, final, temp);
			}
		}
		final.push_back(temp.back());
		temp.pop_back();

	}


	vector<int> findEulerCircuit(int src = 0)
	{
		vector<int> temp, final;
		dfs(src, final, temp);

		reverse(final.begin(), final.end());
		return final;
	}


	// Not tested
	vector<int> findEulerPath()
	{
		int src = 0;
		for (int i = 0; i < n; i++)
		{
			if (int(v[i].size()) % 2)
			{
				src = i;
				break;
			}
		}

		vector<int> temp, final;
		dfs(src, final, temp);

		reverse(final.begin(), final.end());
		return final;
	}

};

int main()
{
	quick;

	int n, m;
	cin >> n >> m;
	eulerUndirected e(n);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		e.addEdge(x, y);
	}

	bool isPossible = e.eulerCircuitExists();

	if (!isPossible)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	vector<int> ans = e.findEulerCircuit();

	for (int &i : ans)
	{
		cout << i + 1 << " ";
	}





	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
