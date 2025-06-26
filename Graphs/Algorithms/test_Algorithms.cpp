#include <gtest/gtest.h>
#include "../Structures/Graph.h"
#include "BFS.h"
#include "DFS.h"

using namespace dsa;


// ----------------------------
// BFS TESTS
// ----------------------------
TEST(BFSTest, EmptyGraph) {
    Graph<int> graph;
    EXPECT_THROW(bfs(graph, 0), std::invalid_argument);
}

TEST(BFSTest, SingleNodeGraph) {
    Graph<int> graph;
    graph.addVertex(1);
    auto result = bfs(graph, 1);
    EXPECT_EQ(result, std::vector<int>({1}));
}

TEST(BFSTest, ConnectedGraph) {
    Graph<int> graph;
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    auto result = bfs(graph, 1);
    // BFS can vary order depending on insertion, so we'll just check contents & size
    EXPECT_EQ(result.size(), 5);
    EXPECT_NE(std::find(result.begin(), result.end(), 4), result.end());
    EXPECT_NE(std::find(result.begin(), result.end(), 5), result.end());
}

TEST(BFSTest, DisconnectedGraph) {
    Graph<int> graph;
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(4, 5); // separate component

    auto result = bfs(graph, 1);
    EXPECT_EQ(result.size(), 3);  // Should not include 4 or 5
    EXPECT_NE(std::find(result.begin(), result.end(), 3), result.end());
    EXPECT_EQ(std::find(result.begin(), result.end(), 4), result.end());
}


// ----------------------------
// DFS RECURSIVE TESTS
// ----------------------------
TEST(DFSTest, EmptyGraph) {
    Graph<int> graph;
    EXPECT_THROW(dfs(graph, 0), std::invalid_argument);
}

TEST(DFSTest, SingleNode) {
    Graph<int> graph;
    graph.addVertex(5);
    std::vector<int> expected = {5};
    EXPECT_EQ(dfs(graph, 5), expected);
}

TEST(DFSTest, SimpleConnectedGraph) {
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    auto result = dfs(graph, 1);
    EXPECT_EQ(result.front(), 1);
    EXPECT_EQ(result.size(), 3);
    EXPECT_TRUE(std::find(result.begin(), result.end(), 2) != result.end());
    EXPECT_TRUE(std::find(result.begin(), result.end(), 3) != result.end());
}

TEST(DFSTest, DisconnectedGraph) {
    Graph<int> graph;
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

    auto result = dfs(graph, 1);
    EXPECT_EQ(result.size(), 2);
    EXPECT_TRUE(std::find(result.begin(), result.end(), 1) != result.end());
    EXPECT_TRUE(std::find(result.begin(), result.end(), 2) != result.end());
}


// ----------------------------
// DFS ITERATIVE TESTS
// ----------------------------
TEST(DFSIterativeTest, EmptyGraph) {
    Graph<int> graph;
    EXPECT_THROW(dfsIterative(graph, 0), std::invalid_argument);
}

TEST(DFSIterativeTest, SingleNode) {
    Graph<int> graph;
    graph.addVertex(42);
    std::vector<int> expected = {42};
    EXPECT_EQ(dfsIterative(graph, 42), expected);
}

TEST(DFSIterativeTest, LinearGraph) {
    Graph<int> graph;
    graph.addEdge(10, 20);
    graph.addEdge(20, 30);

    auto result = dfsIterative(graph, 10);
    EXPECT_EQ(result.front(), 10);
    EXPECT_EQ(result.size(), 3);
    EXPECT_TRUE(std::find(result.begin(), result.end(), 20) != result.end());
    EXPECT_TRUE(std::find(result.begin(), result.end(), 30) != result.end());
}

TEST(DFSIterativeTest, ComplexGraph) {
    Graph<int> graph;
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    auto result = dfsIterative(graph, 1);
    EXPECT_EQ(result.size(), 5);
    EXPECT_TRUE(std::find(result.begin(), result.end(), 4) != result.end());
    EXPECT_TRUE(std::find(result.begin(), result.end(), 5) != result.end());
}
