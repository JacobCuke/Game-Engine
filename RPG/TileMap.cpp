//
//  TileMap.cpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/24.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#include "TileMap.hpp"
#include "XMLParser/rapidxml.hpp"
#include "XMLParser/rapidxml_utils.hpp"
#include "XMLParser/rapidxml_print.hpp"
#include "TextureManager.hpp"
#include <string>
#include <vector>
#include <sstream>

TileMap::TileMap(const char* filename)
    : mapSource(filename)
{}

std::vector<std::shared_ptr<TileSet>> tilesetVector;

void TileMap::init()
{
    rapidxml::file<> testMap(mapSource);
    rapidxml::xml_document<> doc;
    doc.parse<0>(testMap.data());
    rapidxml::xml_node<> *rootNode = doc.first_node("map");
    
    // Build tilesets
    // TODO: Seperate out into another method
    for (rapidxml::xml_node<> *tilesetNode = rootNode->first_node("tileset"); tilesetNode; tilesetNode = tilesetNode->next_sibling("tileset"))
    {
        std::shared_ptr<TileSet> tileset = std::make_shared<TileSet>();
        tileset->firstID = std::atoi(tilesetNode->first_attribute("firstgid")->value());
        std::string filename = tilesetNode->first_attribute("source")->value();
        filename.erase(0, 3);
        
        // Open tileset file and get needed data
        rapidxml::file<> tilesetFile(filename.c_str());
        rapidxml::xml_document<> tilesetDoc;
        tilesetDoc.parse<0>(tilesetFile.data());
        rapidxml::xml_node<> *tilesetRoot = tilesetDoc.first_node("tileset");
        rapidxml::xml_node<> *imageNode = tilesetRoot->first_node("image");
        
        // Height
        tileset->height = std::atoi(imageNode->first_attribute("height")->value());
        
        // Width
        tileset->width = std::atoi(imageNode->first_attribute("width")->value());
        
        // Image source
        std::string imageSource = imageNode->first_attribute("source")->value();
        imageSource.erase(0, 3);
        
        // Texture
        tileset->texture = TextureManager::loadTexture(imageSource.c_str());
        
        // TODO: Collidable objects
        
        tilesetVector.emplace_back(tileset);
    }
    
    std::sort(tilesetVector.begin(), tilesetVector.end(), [](auto& a, auto& b)
    {
        return a->firstID < b->firstID;
    });
}

void TileMap::drawMap()
{
    rapidxml::file<> testMap(mapSource);
    rapidxml::xml_document<> doc;
    doc.parse<0>(testMap.data());
    rapidxml::xml_node<> *rootNode = doc.first_node("map");
    
    // For each layer
    for (rapidxml::xml_node<> *layerNode = rootNode->first_node("layer"); layerNode; layerNode = layerNode->next_sibling("layer"))
    {
        // Read data
        rapidxml::xml_node<> *dataNode = layerNode->first_node("data");
        const char* layerData = dataNode->value();
        
        std::stringstream fileStream(layerData);
        std::string substr;
        
        int count = 0;
        // For each tile
        while (fileStream.good())
        {
            std::getline(fileStream, substr, ',');
            count++;
            
            // Remove any special characters before converting to an int
            substr.erase(std::remove(substr.begin(), substr.end(), '\r'));
            substr.erase(std::remove(substr.begin(), substr.end(), '\n'));
            
            // Ignore transparent tiles
            int tileID = std::stoi(substr);
            if (tileID == 0) continue;
            
            // Figure out which tileset tile is in
            int tilesetIndex = -1;
            for (auto& tileset : tilesetVector)
            {
                if (tileID < tileset->firstID) break;
                tilesetIndex++;
            }
            
            auto& sourceTileset = tilesetVector[tilesetIndex];
            
            SDL_Rect srcRect, destRect;
            
            // Make tileID relative to the source tileset
            tileID = (tileID - sourceTileset->firstID) + 1;
            
            srcRect = getTilePosition(tileID, sourceTileset->width);
            destRect = getTilePosition(count, Game::GAME_WIDTH);
            
            TextureManager::drawTexture(sourceTileset->texture, srcRect, destRect);
        }
    }
}

SDL_Rect TileMap::getTilePosition(int tileID, int gridWidth)
{
    SDL_Rect rect;
    
    int numColumns = gridWidth / Game::TILE_SIZE;
    
    int row = 0;
    while (tileID > numColumns)
    {
        row++;
        tileID -= numColumns;
    }
    
    rect.x = Game::TILE_SIZE * (tileID - 1);
    rect.y = Game::TILE_SIZE * row;
    rect.w = rect.h = Game::TILE_SIZE;
    
    return rect;
}
