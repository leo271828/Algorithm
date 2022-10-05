#include <bits/stdc++.h>

using namespace std;

int minKey(int key[], bool mstSet[], int V){
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void printMST(int parent[], int **graph, int V){
	int sum = 0;
    // cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
        sum += graph[i][parent[i]];
        
    printf("The highest possible quality is 1/%d.", sum);
		// cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}
void primMST(int **graph, int V){
	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	for (int count = 0; count < V - 1; count++){
		int u = minKey(key, mstSet, V);
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph, V);
}

int main(){
    int N, tmp;
    cin >> N;
    string str[N];
    for(int i=0;i<N;i++) {
		cin >> str[i];
	}
	cin >> tmp;

    int sum = 0, map[N][N], *p[N];
    
	for(int i=0;i<N;i++){
        p[i] = map[i];
		for(int j=0;j<N;j++) map[i][j] = 0;
    }
    
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			sum = 0;
			for(int k=0;k<7;k++) 
				if( str[i][k] != str[j][k] ) sum ++;
            map[i][j] = sum;
            map[j][i] = sum;
		}
	}
    // for(int i=0;i<N;i++, cout << endl)
    //     for(int j=0;j<N;j++)
    //         cout << map[i][j] << " ";
	primMST(p, N);

	return 0;
}
