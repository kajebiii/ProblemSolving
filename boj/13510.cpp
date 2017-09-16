// =====================================================================================
//
//       Filename:  13510.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  11/15/2016
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>
 
using namespace std;
 
typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}
 
const int MAX_N = 1e5 + 100, LOG_N = 20;
 
struct SegmentTree
{
    struct SegmentTreeNode
    {
        int first, last, maxValue;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int first, int last) :first(first), last(last), maxValue(-1)
        {
            if(first != last)
            {
                int mid = (first + last) >> 1;
                left  = new SegmentTreeNode(first, mid);
                right = new SegmentTreeNode(mid+1, last);
            }
        }
        void update(int pos, int value)
        {
            if(first == last) maxValue = value;
            else
            {
                int mid = (first + last) >> 1;
                if(pos <= mid) 
                    left  -> update(pos, value);
                else
                    right -> update(pos, value);
                maxValue = max(left -> maxValue, right -> maxValue);
            }
        }
        int query(int low, int high)
        {
            if(high < first || last < low) return -1;
            if(low <= first && last <= high) return maxValue;
            return max(left -> query(low, high), right -> query(low, high));
        }
    };
 
    SegmentTreeNode *root;
    SegmentTree(int N) :root(new SegmentTreeNode(0, N-1)) {}
    void update(int pos, int value) {root -> update(pos, value); }
    int query(int low, int high) {return root -> query(low, high); }
};
 
int N, Cost[MAX_N]; 
vector<int> Edge[MAX_N];
int Parent[MAX_N][LOG_N + 1], Depth[MAX_N], Size[MAX_N];
vector<int> HeavyPathIndex;
vector<vector<int> > HeavyPaths;
vector<SegmentTree> SegmentTrees;
int NrToNode[MAX_N];
 
void initDFS(int v, int p)
{
    Depth[v] = Depth[p] + 1;
    Size[v] = 1;
    Parent[v][0] = p;
    for(int i=1; i<=LOG_N; i++)
        Parent[v][i] = Parent[Parent[v][i-1]][i-1];
    for(int now : Edge[v])
    {
        if(now == p) continue;
        initDFS(now, v);
        Size[v] += Size[now];
    }
}
 
int inputEdge[MAX_N][3];
void getInitValue()
{
    cin >> N;
    for(int i=1; i<N; i++)
    {
        int x, y, c; scanf("%d%d%d", &x, &y, &c);
        inputEdge[i][0] = x;
        inputEdge[i][1] = y;
        inputEdge[i][2] = c;
        Edge[x].pb(y); Edge[y].pb(x);
    }
    initDFS(1, 0);
    for(int i=1; i<N; i++)
    {
        int (&K)[3] = inputEdge[i];
        if(Parent[K[0]][0] != K[1]) swap(K[0], K[1]);
        NrToNode[i] = K[0];
        Cost[K[0]] = K[2];
    }
}
void doHeavyLightDecomposition(int root)
{
    HeavyPaths.clear();
    HeavyPathIndex.resize(N+1, -1);
 
    queue<int> Q; Q.push(root);
    while(!Q.empty())
    {
        int now = Q.front(); Q.pop();
        for(int next : Edge[now]) if(next != Parent[now][0]) Q.push(next);
        if(now == root) continue;
 
        int parent = Parent[now][0];
 
        if(Size[now] * 2 >= Size[parent] && parent != root)
        {
            int index = HeavyPathIndex[parent];
            HeavyPaths[index].push_back(now);
            HeavyPathIndex[now] = index;
        }
        else
        {
            HeavyPathIndex[now] = HeavyPaths.size();
            HeavyPaths.push_back(vector<int>({parent, now}));
        }
    }
}
void makeInitTree()
{
    SegmentTrees.clear();
    SegmentTrees.reserve(HeavyPaths.size());
    for(const auto &path : HeavyPaths)
    {
        SegmentTrees.push_back(SegmentTree(path.size() - 1));
        for(int i=1; i<path.size(); i++)
            SegmentTrees.back().update(i-1, Cost[path[i]]);
    }
}
 
int findEdgeInPath(int path, int v)
{
    int root = HeavyPaths[path][0];
    return Depth[v] - Depth[root] - 1;
}
int getLCA(int u, int v)
{
    if(Depth[u] > Depth[v]) swap(u, v);
    //Depth[u] <= Depth[v]
    int diff = Depth[v] - Depth[u];
    for(int i=0; i<=LOG_N; i++)
        if(diff & (1 << i) ) v = Parent[v][i];
    if(u == v) return v;
    for(int i=LOG_N; i>=0; i--)
        if(Parent[v][i] != Parent[u][i])
        {
            v = Parent[v][i];
            u = Parent[u][i];
        }
    return Parent[v][0];
}
void update(int v, int c)
{
    int pathIx = HeavyPathIndex[v];
    int ix = findEdgeInPath(pathIx, v);
    SegmentTrees[pathIx].update(ix, c);
}
int getTopDown(int p, int v)
{
    if(p == v) return -1;
    int ix = HeavyPathIndex[v];
    int right = findEdgeInPath(ix, v);
    if(HeavyPathIndex[p] == ix)
    {
        int left  = findEdgeInPath(ix, p) + 1;
        return SegmentTrees[ix].query(left, right);
    }
 
    int top = HeavyPaths[ix][0];
    return max(getTopDown(p, top), SegmentTrees[ix].query(0, right));
}
int getQuery(int x, int y)
{
    int lca = getLCA(x, y);
    return max(getTopDown(lca, x), getTopDown(lca, y));
}
 
int main()
{
    if(debug) freopen("input.txt", "r", stdin);
    getInitValue();
    doHeavyLightDecomposition(1);
    makeInitTree();
    int Q; cin >> Q;
    for(int i=0; i<Q; i++)
    {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if(k == 1)
        {
            x = NrToNode[x];
            update(x, y);
        }
        else
            printf("%d\n", getQuery(x, y));
    }
    return 0;
}






