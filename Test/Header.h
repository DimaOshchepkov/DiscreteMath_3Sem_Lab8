#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>

void CreateFile(std::string name = "graph.txt");

std::vector<std::list<int>> ReadFile(std::string name = "graph.txt");

std::vector<std::list<int>> CountConnectivityComponent(std::vector<std::list<int>> graph);



