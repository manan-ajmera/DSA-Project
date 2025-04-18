#ifndef CDNMANAGER_H
#define CDNMANAGER_H

#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include "CDN_Node.hpp"
#include "MainServer.hpp"

// Custom comparator for priority queue to sort CDN nodes by distance
struct DistanceComparator {
    double userX, userY;

    DistanceComparator(double x, double y) : userX(x), userY(y) {}

    bool operator()(std::pair<CDNNode*, double> node1, std::pair<CDNNode*, double> node2) {
        double dx1 = node1.first->getX() - userX;
        double dy1 = node1.first->getY() - userY;
        double dist1 = std::sqrt(dx1 * dx1 + dy1 * dy1);

        double dx2 = node2.first->getX() - userX;
        double dy2 = node2.first->getY() - userY;
        double dist2 = std::sqrt(dx2 * dx2 + dy2 * dy2);

        return dist1 > dist2;  // Min-heap: node with the least distance has higher priority
    }
};

class CDNManager {
private:
    std::unordered_map<std::string, CDNNode*> cdnNodes; // Stores all CDN nodes
    std::unordered_map<std::string, int> requestCount;  // Stores request count for each movie per CDN node
    MainServer mainServer;

    // Helper functions
    std::priority_queue<std::pair<CDNNode*, double>, std::vector<std::pair<CDNNode*, double>>, DistanceComparator> findCDNNodesInRadius(double userX, double userY, double radius); // Modified function
    void initializeCDNNodeWithPopularMovies(CDNNode* cdnNode, int numMovies); // New function

    static const int requestThreshold = 5;  // Threshold for adding popular movies to CDN nodes

public:
    // Constructor and Destructor
    CDNManager();
    ~CDNManager();

    // CDN Node and Movie management
    void addCDNNode(double x, double y);  // Adds a new CDN node at (x, y)
    void addMovieToMainServer(const std::string& movieName, std::string imagepath);  // Adds movie to main server
    void markMovieAsPopular(const std::string& movieName , CDNNode*& node); // Marks a movie as popular across CDN nodes
    CDNNode* getNearestNode(int userx, int usery, double radius);
    std::vector<Movie*> getTopMoviesForNode(CDNNode* node);
    void initializeRequestCount();
    // Movie request handler
    std::pair<Movie*, std::string> requestMovie(const std::string& movieName, double userX, double userY, double radius);
};

#endif 
