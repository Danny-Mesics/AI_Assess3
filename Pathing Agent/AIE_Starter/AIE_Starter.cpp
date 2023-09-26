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
    nodeMap.Intialise(asciiMap, 50);

    std::vector<Agent*> agents;

    Agent* agent = new Agent(&nodeMap, new GoToPointBehaviour());
    Node* start = nodeMap.GetNode(1, 1);
    agent->SetNode(start);
    agents.push_back(agent);

    agent = new Agent(&nodeMap, new WanderBehaviour());
    agent->SetNode(nodeMap.GetRandomNode());
    agent->SetSpeed(256);
    agents.push_back(agent);

    agent = new Agent(&nodeMap, new SelectorBehaviour(new FollowBehaviour(), new WanderBehaviour()));
    agent->SetTargetAgent(agents[1]);
    agent->SetSpeed(128);
    agent->SetNode(nodeMap.GetRandomNode());
    agents.push_back(agent);

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
        
        for (int i = 0; i < agents.size(); i++) {
            agents[i]->Update(deltaTime);
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        nodeMap.Draw();
        
        for (int i = 0; i < agents.size(); i++) {
            agents[i]->Draw();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    for (int i = 0; i < agents.size(); i++) {
        delete agents[i];
    }

    return 0;
}