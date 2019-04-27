#include<iostream>

#define V 4
#define INF 99999

void printSolution(int dist[][V]);

void shortest_path(int dist[][V], int x, int y);

void floydWarshall (int graph[][V], int x, int y)
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
    shortest_path(dist,x,y);
}

void printSolution(int dist[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void shortest_path(int dist[][V], int x, int y){
    std::cout << "distance between " << x << " & " << y << std::endl;
    if (dist[x][y] == INF)
        std::cout << "infinite distance" << std::endl;
    else
        std::cout << " : " << dist[x][y] << std::endl;
}

int main()
{
    /*
            10
    (0)------->(3)
        |		 /|\
    5 |		 |
        |		 | 1
    \|/		 |
    (1)------->(2)
            3		 */

    int graph[V][V] =
            {
                {   0,INF, -2,INF },
                {   4,  0,  3,INF },
                { INF,INF,  0,  2 },
                { INF, -1,INF,  0 }
            };

    floydWarshall(graph, 1, 2);
    return 0;
} 
