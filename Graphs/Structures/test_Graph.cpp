#include "gtest/gtest.h"
#include "Graph.h"

using namespace dsa;

TEST(GraphTest, AddAndHasVertex) {
    Graph<int> graph;
    EXPECT_TRUE(graph.isEmpty());
    graph.addVertex(1);
    EXPECT_TRUE(graph.hasVertex(1));
    EXPECT_FALSE(graph.hasVertex(2));
    EXPECT_EQ(graph.size(), 1);
}

TEST(GraphTest, AddAndHasEdgeDirected) {
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2, 5);  // directed
    EXPECT_TRUE(graph.hasEdge(1, 2));
    EXPECT_FALSE(graph.hasEdge(2, 1));
}

TEST(GraphTest, MakeUndirectedEdge) {
    Graph<int> graph;
    graph.makeUndirectedEdge(3, 4, 7);
    EXPECT_TRUE(graph.hasEdge(3, 4));
    EXPECT_TRUE(graph.hasEdge(4, 3));
}

TEST(GraphTest, RemoveVertex) {
    Graph<int> graph;
    graph.addVertex(10);
    graph.addVertex(11);
    graph.makeUndirectedEdge(10, 11, 2);
    EXPECT_TRUE(graph.hasEdge(10, 11));
    graph.removeVertex(11);
    EXPECT_FALSE(graph.hasVertex(11));
    EXPECT_FALSE(graph.hasEdge(10, 11));
}

TEST(GraphTest, RemoveEdge) {
    Graph<int> graph;
    graph.makeUndirectedEdge(1, 2, 3);
    EXPECT_TRUE(graph.hasEdge(1, 2));
    EXPECT_TRUE(graph.hasEdge(2, 1));
    graph.removeEdge(1, 2);
    EXPECT_FALSE(graph.hasEdge(1, 2));
    EXPECT_TRUE(graph.hasEdge(2, 1));  // still exists
    graph.removeEdge(2, 1);
    EXPECT_FALSE(graph.hasEdge(2, 1));
}

TEST(GraphTest, GetNeighbors) {
    Graph<std::string> graph;
    graph.makeUndirectedEdge("A", "B", 1);
    graph.addEdge("A", "C", 2);  // directed
    const auto& neighbors = graph.getNeighbors("A");
    EXPECT_EQ(neighbors.size(), 2);
    EXPECT_TRUE(neighbors.count("B"));
    EXPECT_TRUE(neighbors.count("C"));
}

TEST(GraphTest, GetAllVertices) {
    Graph<char> graph;
    graph.addVertex('X');
    graph.addVertex('Y');
    auto verts = graph.getAllVertices();
    EXPECT_EQ(verts.size(), 2);
    EXPECT_TRUE(std::find(verts.begin(), verts.end(), 'X') != verts.end());
    EXPECT_TRUE(std::find(verts.begin(), verts.end(), 'Y') != verts.end());
}

TEST(GraphTest, ClearGraph) {
    Graph<int> graph;
    graph.makeUndirectedEdge(1, 2, 1);
    graph.makeUndirectedEdge(2, 3, 2);
    EXPECT_FALSE(graph.isEmpty());
    graph.clear();
    EXPECT_TRUE(graph.isEmpty());
    EXPECT_EQ(graph.size(), 0);
}
