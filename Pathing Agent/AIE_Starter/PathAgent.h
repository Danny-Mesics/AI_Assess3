#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <string>

namespace AIForGames {
    struct Node;
    class NodeMap;
	class PathAgent
	{
    private:
        glm::vec2 m_position;

        std::vector<Node*> m_path;
        int m_currentIndex;
        Node* m_currentNode;

        float m_speed;
        NodeMap* nodeMap;

    public:
        void Update(float deltaTime);
        void GoToNode(Node* node);
        void Draw();

        void SetNode(Node* node);
        void SetSpeed(float speed);
        PathAgent(NodeMap* nodeMap);
    };


}


