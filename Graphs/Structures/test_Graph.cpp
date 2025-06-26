#include <gtest/gtest.h>
#include "Graph.h"

using namespace dsa;

TEST(GraphTest, AddAndHasVertex) {
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);

    EXPECT_TRUE(graph.hasVertex(1));
    EXPECT_TRUE(graph.hasVertex(2));
    EXPECT_FALSE(graph.hasVertex(3));
}

TEST(GraphTest, AddAndHasEdge) {
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2);

    EXPECT_TRUE(graph.hasEdge(1, 2));
    EXPECT_TRUE(graph.hasEdge(2, 1));  // undirected
}

TEST(GraphTest, RemoveEdge) {
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2);
    graph.removeEdge(1, 2);

    EXPECT_FALSE(graph.hasEdge(1, 2));
    EXPECT_FALSE(graph.hasEdge(2, 1));
}

TEST(GraphTest, RemoveVertex) {
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2);
    graph.removeVertex(2);

    EXPECT_FALSE(graph.hasVertex(2));
    EXPECT_FALSE(graph.hasEdge(1, 2));
}

TEST(GraphTest, GetNeighbors) {
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);

    const auto& neighbors = graph.getNeighbors(1);
    EXPECT_EQ(neighbors.size(), 2);
    EXPECT_TRUE(neighbors.count(2));
    EXPECT_TRUE(neighbors.count(3));
}

TEST(GraphTest, IsEmptyAndSize) {
    Graph<int> graph;
    EXPECT_TRUE(graph.isEmpty());

    graph.addVertex(10);
    EXPECT_FALSE(graph.isEmpty());
    EXPECT_EQ(graph.size(), 1);

    graph.addVertex(20);
    graph.addEdge(10, 20);
    EXPECT_EQ(graph.size(), 2);
}

TEST(GraphTest, GetAllVertices) {
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);

    auto allVertices = graph.getAllVertices();
    EXPECT_EQ(allVertices.size(), 3);
    EXPECT_TRUE(std::find(allVertices.begin(), allVertices.end(), 1) != allVertices.end());
    EXPECT_TRUE(std::find(allVertices.begin(), allVertices.end(), 2) != allVertices.end());
    EXPECT_TRUE(std::find(allVertices.begin(), allVertices.end(), 3) != allVertices.end());
}