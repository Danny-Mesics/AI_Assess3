#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Pathfinding.h"
#include "PathAgent.h"
#include "Agent.h"
#include "GoToPointBehaviour.h"
#include "WanderBehaviour.h"
#include "FollowBehaviour.h"
#include "SelectorBehaviour.h"

using namespace AIForGames;

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1200;
    int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    std::vector<std::string> asciiMap;
    asciiMap.push_back("0000000000000000000");
    asciiMap.push_back("0101110111011011110");
    asciiMap.push_back("0101011101111110110");
    asciiMap.push_back("0111000001110110010");
    asciiMap.push_back("0101111110110111110");
    asciiMap.push_back("0100000011110110100");
    asciiMap.push_back("0111111100110111110");
    asciiMap.push_back("0100010111011110010");
    asciiMap.push_back("0111010001110111110");
    asciiMap.push_back("0101110000110100110");
    asciiMap.push_back("0100111111110110110");
    asciiMap.push_back("0111100011110111010");
    asciiMap.push_back("0000000000000000000");

    NodeMap nodeMap;
    nodeMap.Initialise(asciiMap, 50);

    std:vector<Agent*> agents;

    Node* start = nodeMap.GetNode(1, 1);
    Node* end = nodeMap.GetNode(10, 2);
    nodeMap.path = nodeMap.DijkstrasSearch(start, end);

    PathAgent agent = PathAgent(&nodeMap);
    agent.SetNode(start);
    agent.SetSpeed(64);
    

    float time = (float)GetTime();
    float deltaTime;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (IsMouseButtonPressed(0)) {
            Vector2 mousePos = GetMousePosition();
            start = nodeMap.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
            agent.GoToNode(start);
        }
        

        agent.Update(deltaTime);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        nodeMap.Draw();
        //nodeMap.DrawPath();
        agent.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}