#include <bits/stdc++.h>
using namespace std;


struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        this->left = NULL;
        this->right = NULL;
    }
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

Node* buildHuffmanTree(string text) {
    unordered_map<char, int> frequencyMap;
    for (char c : text) {
        frequencyMap[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto& entry : frequencyMap) {
        pq.push(new Node(entry.first, entry.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }
    return pq.top();
}

void encode(Node* root, string code, unordered_map<char, string>& codes) {
    if (root == NULL) return;

    if (root->data != '\0') {
        codes[root->data] = code;
    }

    encode(root->left, code + "0", codes);
    encode(root->right, code + "1", codes);
}

string encodeText(string text, unordered_map<char, string>& codes) {
    string encodedText = "";
    for (char c : text) {
        cout << c << " " << codes[c] << endl;
        encodedText += codes[c];
    }
    return encodedText;
}

string decodeText(Node* root, string encodedText) {
    string decodedText = "";
    Node* current = root;
    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->data != '\0') {
            decodedText += current->data;
            current = root;
        }
    }
    return decodedText;
}

int main() {
    string text;
    cin >> text;
    

    Node* root = buildHuffmanTree(text);

    unordered_map<char, string> codes;
    encode(root, "", codes);


    cout << "code initialise on the basis of frequency : " << endl;
    string encodedText = encodeText(text, codes);
    cout << "Encoded Text: " << encodedText << endl;


    string decodedText = decodeText(root, encodedText);
    cout << "Decoded Text: " << decodedText << endl;
    return 0;
}
