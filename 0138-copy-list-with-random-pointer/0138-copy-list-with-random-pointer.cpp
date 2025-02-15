/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        temp = head;
        while (temp) {
            if (temp->random) 
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* newHead = head->next;
        Node* oldTemp = head;
        Node* newTemp = newHead;
        while (oldTemp) {
            oldTemp->next = oldTemp->next ? oldTemp->next->next : nullptr;
            newTemp->next = newTemp->next ? newTemp->next->next : nullptr;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        
        return newHead;
    }
};
