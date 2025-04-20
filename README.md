# CDN Server with Movie Searcher

An interactive Content Delivery Network (CDN) server application built using **C++** and **Qt**, designed to efficiently distribute and display movie posters. The application offers users the ability to browse popular movie images or search for specific titles, all tailored to their location for optimal performance.

## Table of Contents
- [Key Features](#key-features)
- [Project Layout](#project-layout)
- [Installation Guide](#installation-guide)
- [How to Use](#how-to-use)
- [Core Classes and Components](#core-classes-and-components)
- [Planned Enhancements](#planned-enhancements)

## Key Features
- **Location-Based Display**: Fetches and displays movie images from the CDN node closest to the user's input coordinates.
- **Search Functionality**: Allows users to search for movies by title, returning relevant images and information if found.
- **Responsive Grid Layout**: Presents movies in an adaptive 3x3 grid layout that adjusts according to the number of available entries.
- **Efficient CDN Handling**: The `CDNManager` class oversees CDN nodes and ensures fast access to frequently requested movies.

## Project Layout
The project is divided into the following components:

- **WelcomeWindow**: Initial interface for entering user coordinates.
- **ResultsPage**: Displays search results and movies based on the closest CDN node.
- **CDNManager**: Oversees server operations, node communication, and popular movie caching.
- **Movie**: A data class for movie details including title and image.
- **CDNNode**: Represents individual CDN nodes with geographic coordinates and a cache of popular movies.
- **MainServer**: Houses the complete movie database and handles image path requests.

## Installation Guide

### Requirements
1. **Qt Framework**: Download from [Qt's official site](https://www.qt.io/download-dev#eval-form) to support the graphical interface.
2. **C++ Compiler**: Use a compiler that supports C++11 or later.
3. **C++17 Support**: Ensure filesystem operations are compatible with C++17.

### Network Tip
For smoother performance, especially during data transfers, connect via LAN rather than WiFi.

### Steps to Install
1. **Clone the Repository**
    ```bash
    https://github.com/manan-ajmera/DSA-Project.git
    ```
2. **Load the Project in Qt Creator**
    - Open the `CDN_Optimization` folder and ensure all files are included in the project.
3. **Build the Application**
    - Use the **Build** option in Qt Creator to compile everything.
4. **Launch the Application**
    - Once built, hit **Run** to open the CDN server GUI.

## How to Use

### Startup Process
1. Launch the application and enter your coordinates (values between 0 and 200).
2. These inputs are used to determine your nearest CDN node.

### Browsing Movies
- The application will display a 3x3 grid of popular movie images from your closest node.

### Searching for a Movie
- Use the integrated search bar to find a movie by title. If available, the movie image and info will be shown.

## Core Classes and Components
- **WelcomeWindow**: Handles user input for coordinates and connects to the result view.
- **ResultsPage**: Shows movie posters from the nearest node and supports search functionality.
- **CDNManager**: Controls all CDN operations and optimizes data access.
- **CDNNode**: CDN nodes defined by (x, y) location and a list of nearby popular movies.
- **Movie**: Contains the movie name and image location.
- **MainServer**: Central source for all movies and their corresponding images.

## Planned Enhancements
- **Dynamic Caching Strategy**: Allow CDN nodes to adapt their caches based on trending requests.
- **Fuzzy Search**: Improve the search experience by allowing partial or typo-tolerant matches.
- **Advanced Image Caching**: Optimize image loading and performance through intelligent caching mechanisms.
