import java.util.*;
class Edge
{
    int source, dest;

    public Edge(int source, int dest)
    {
        this.source = source;
        this.dest = dest;
    }
}

class Graph
{
    List<List<Integer>> adjList = null;
    Graph(List<Edge> edges, int n)
{
    adjList = new ArrayList<>(n);
    for (int i = 0; i < n; i++) {
    adjList.add(new ArrayList<>());
}
    for (Edge edge: edges) {
        adjList.get(edge.source).add(edge.dest);
    }
}
}


class DisjointSet
{
    private Map<Integer, Integer> parent = new HashMap<>();
    public void makeSet(int n)
{
    for (int i = 0; i < n; i++) {

        parent.put(i, i);
    }
}
    public int ﬁnd(int k)
    {
        if (parent.get(k) == k) {
            return k;
        }
        return ﬁnd(parent.get(k));
    }

    public void union(int a, int b)
    {
        int x = ﬁnd(a);
        int y = ﬁnd(b);
        parent.put(x, y);
    }
}

class Q1
{
    public static boolean ﬁndCycle(Graph graph, int n)
    {
        DisjointSet ds = new DisjointSet();
        ds.makeSet(n);
        for (int u = 0; u < n; u++)
        {
            for (int v: graph.adjList.get(u))
            {
                int x = ds.ﬁnd(u);
                int y = ds.ﬁnd(v);
                if (x == y) {
                return true;
            }
            else {
                ds.union(x, y);
            }
            }
        }

        return false;
    }

    public static void main(String[] args)
    {
        List<Edge> edges = Arrays.asList(
                new Edge(0, 1),
                new Edge(0, 6),
                new Edge(0, 7),
                new Edge(1, 2),
                new Edge(1, 5),
                new Edge(2, 3),
                new Edge(2, 4),
                new Edge(7, 8),
                new Edge(7, 11),
                new Edge(8, 9),
                new Edge(8, 10),
                new Edge(10, 11)

        );
        int n = 12;
        Graph graph = new Graph(edges, n);
        if (ﬁndCycle(graph, n)) {
        System.out.println("Cycle Found");
    }
    else {
        System.out.println("No Cycle is Found");
    }
    }
}
