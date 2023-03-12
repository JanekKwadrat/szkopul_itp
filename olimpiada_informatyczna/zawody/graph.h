template<class X, class D>
class Graph {
    public:
    bool edge_exists(X, X);
    D edge_value(X, X);

    bool adjacent(X, X);
    int degree(X);
    int neighbor(X, int);
    void add_vertex(X);
    void remove_vertex(X);
    void add_edge(X, X, D);
};