//
//  main.cpp
//  1031
//
//  Created by KJBS2 on 03/06/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 50 * 3;
const int INF = 0x7fffffff;

int N, M;
int Source, Sink;
int Capacity[MAX_N+2][MAX_N+2];
int Flow[MAX_N+2][MAX_N+2];
vector<int> parent;

bool findPathWithDFS(int nowNode, int sink) {
	if(nowNode == sink) return true;
	for(int nextNode = 1; nextNode <= N+M+1; nextNode++)
		if(Capacity[nowNode][nextNode] - Flow[nowNode][nextNode] > 0 && parent[nextNode] == -1) {
			parent[nextNode] = nowNode;
			if(findPathWithDFS(nextNode, sink)) return true;
		}
	return false;
}

bool DontTouch[MAX_N+2][MAX_N+2];
bool findPathWithDFS2(int nowNode, int sink) {
	if(nowNode == sink) return true;
	for(int nextNode = N + M + 1; nextNode >= 1; nextNode--)
		if(Capacity[nextNode][nowNode] - Flow[nextNode][nowNode] > 0 && parent[nextNode] == -1 && DontTouch[nextNode][nowNode] == false) {
			parent[nextNode] = nowNode;
			if(findPathWithDFS2(nextNode, sink)) return true;
		}
	return false;
}
bool findFlow(int source, int sink, int maxFlow) {
	memset(Flow, 0, sizeof(Flow));

	int totalFlow = 0;

	while(true) {
		parent = vector<int>(MAX_N+2, -1);

		parent[source] = source;
		if(!findPathWithDFS(source, sink)) break;

		int nowFlow = INF;
		for(int nowNode = sink; nowNode != source; nowNode = parent[nowNode]) {
			int pastNode = parent[nowNode];
			nowFlow = min(nowFlow, Capacity[pastNode][nowNode] - Flow[pastNode][nowNode]);
		}

		for(int nowNode = sink; nowNode != source; nowNode = parent[nowNode]) {
			int pastNode = parent[nowNode];
			Flow[pastNode][nowNode] += nowFlow;
			Flow[nowNode][pastNode] -= nowFlow;
		}
		totalFlow += nowFlow;
	}

	if(totalFlow == maxFlow) {
		for(int i = 1; i <= N; i++)
			for(int j = N + 1; j <= N + M; j++) {
				parent = vector<int>(MAX_N+2, -1);

				if(Capacity[j][i] - Flow[j][i] > 0 && parent[j] == -1) {
					if(!findPathWithDFS2(j, i)) {
						DontTouch[i][j] = DontTouch[j][i] = true;
						continue;
					}

					Flow[j][i] = 0;
					Flow[i][j] = 0;
					for(int nowNode = i; nowNode != j; nowNode = parent[nowNode]) {
						int pastNode = parent[nowNode];
						Flow[pastNode][nowNode] -= 1;
						Flow[nowNode][pastNode] += 1;
					}
				}
				DontTouch[i][j] = DontTouch[j][i] = true;
			}
		return true;
	}
	return false;

}

int main() {
	scanf("%d%d", &N, &M);

	Source = 0;
	Sink = N + M + 1;

	int sum1 = 0, sum2 = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &Capacity[Source][i]);
		sum1 += Capacity[Source][i];
	}
	for(int i = N + 1; i <= N + M; i++) {
		scanf("%d", &Capacity[i][Sink]);
		sum2 += Capacity[i][Sink];
	}
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			Capacity[i][N + j] = 1;


	if(sum1 == sum2 && findFlow(Source, Sink, sum1)) {
		for(int i = 1; i <= N; printf("\n"), i++)
			for(int j = 1; j <= M; printf("%d", Flow[i][N + j]), j++);
	}else{
		printf("-1");
	}
	return 0;
}







