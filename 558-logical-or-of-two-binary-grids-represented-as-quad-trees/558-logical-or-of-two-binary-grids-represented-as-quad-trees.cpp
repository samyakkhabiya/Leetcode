/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/


class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1 == nullptr) {
            return quadTree2;
        }
        if (quadTree2 == nullptr) {
            return quadTree1;
        }
        if (quadTree1->isLeaf && quadTree1->val) {
            return quadTree1;
        }
        if (quadTree2->isLeaf && quadTree2->val) {
            return quadTree2;
        }
        if (quadTree1->isLeaf) {
            return quadTree2;
        }
        if (quadTree2->isLeaf) {
            return quadTree1;
        }

        quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (quadTree1->topLeft->isLeaf && quadTree1->topRight->isLeaf && quadTree1->bottomLeft->isLeaf && quadTree1->bottomRight->isLeaf) {
            if (quadTree1->topLeft->val && quadTree1->topRight->val && quadTree1->bottomLeft->val && quadTree1->bottomRight->val) {
                quadTree1->isLeaf = true;
                quadTree1->val = true;
                quadTree1->topLeft = nullptr;
                quadTree1->topRight = nullptr;
                quadTree1->bottomLeft = nullptr;
                quadTree1->bottomRight = nullptr;
            } else if (!quadTree1->topLeft->val && !quadTree1->topRight->val && !quadTree1->bottomLeft->val && !quadTree1->bottomRight->val) {
                quadTree1->isLeaf = true;
                quadTree1->val = false;
                quadTree1->topLeft = nullptr;
                quadTree1->topRight = nullptr;
                quadTree1->bottomLeft = nullptr;
                quadTree1->bottomRight = nullptr;
            }
        } else {
            quadTree1->isLeaf = false;
            quadTree1->val = false;
        }

        return quadTree1;
    }
};

#if DEBUG
int main(int argc, char** argv) {
    return 0;
}
#endif