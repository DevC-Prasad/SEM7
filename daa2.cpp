
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Structure representing a Huffman tree node
struct Node {
    char ch;
    int freq;

    Node* left;
    Node* right;

    // Constructor
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

// Comparator for Min-Priority Queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to build Huffman Tree
Node* buildHuffmanTree(vector<char> characters,
                       vector<int> frequencies, int n) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters into priority queue
    for (int i = 0; i < n; i++) {
        Node* node = new Node(characters[i], frequencies[i]);
        pq.push(node);
    }

    // Combine two minimum-frequency nodes
    while (pq.size() > 1) {

        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        // Create parent node
        Node* parent = new Node('\0', left->freq + right->freq);

        // Connect children to parent
        parent->left = left;
        parent->right = right;

        // Insert parent back into priority queue
        pq.push(parent);
    }

    // Return final root
    return pq.top();
}

// Function to generate Huffman Codes
void printCodes(Node* root, string code) {

    if (root == NULL)
        return;

    // Check if node is a leaf
    if (root->left == NULL && root->right == NULL) {

        // Handle single-character input
        if (code == "")
            code = "0";

        cout << root->ch << " : " << code << endl;
        return;
    }

    // Left traversal adds 0
    printCodes(root->left, code + "0");

    // Right traversal adds 1
    printCodes(root->right, code + "1");
}

// Function to free allocated memory
void deleteTree(Node* root) {

    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

// Main function
int main() {

    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of characters.";
        return 0;
    }

    vector<char> characters(n);
    vector<int> frequencies(n);

    cout << "Enter character and frequency:\n";

    for (int i = 0; i < n; i++) {
        cin >> characters[i] >> frequencies[i];

        if (frequencies[i] <= 0) {
            cout << "Frequency must be positive.";
            return 0;
        }
    }

    // Build Huffman Tree
    Node* root = buildHuffmanTree(characters, frequencies, n);

    // Generate and display Huffman Codes
    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    // Free memory
    deleteTree(root);

    return 0;
}

