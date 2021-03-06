#pragma once
#include "Node.h"
#include "Character.h"
#include <windows.h>
#include <stdio.h>
#define BLACK 0
#define BLUE 1
#define WHITE 15



class Map
{
public:
	Map(int widthSize, int heightSize); // conductor with size
	Node** GetMapData() const; // return all node
    Node* GetNode(int xOffset, int yOffset) const;	// Get data
	void PrintMap(Character* currentState); //printmap with
	Node GetMapData(int xOffset, int yOffset);	// Get data
	void SetMapData(int xOffset, int yOffset, Node value);	// Set data
	void PrintMap();	//Print All map
	int* GetMapSize();	// Return Map's width and height
	int* GetLocationOf(char data); //get location of special object

	// Destructor
	~Map();

private:
	// Size
	int width, height;
	// Data
	Node **mapData;		// 0 : empty, 1 : character, 2 : obstacle
	// Create Map
	void CreateMap();
};