class Solution {
public:
// Node struct to represent a character and its properties in the Disjoint-Set
struct Node{
    int id =-1; // id of the character, initialize it to -1 to represent uninitialized state
    char label=' '; // label of the character, initialize it to ' ' to represent uninitialized state
    Node* parent=this; // pointer to the parent node, initialize it to this to represent the root node
    int size=1; // size of the set, initialize it to 1 as it is the root node
    bool visted=0; // boolean to check if the node is visited, not used in this code
    vector<Node*> neighbours={}; // neighbours of the node, not used in this code
    Node(int _id, char _label):id(_id), label(_label){} // constructor to initialize the id and label of the node
};

// function to find the parent of a node in the Disjoint-Set
Node* getParentDSU(Node* node){
    if(node==node->parent) return node; // if the node is the root node, return it
    return node->parent=getParentDSU(node->parent); // else recursively find the parent and use path compression to update the parent
}

// function to join two nodes in the Disjoint-Set
void joinDSU(Node* src,Node* tar){
    src=getParentDSU(src); // find the parent of the source node
    tar=getParentDSU(tar); // find the parent of the target node
    if(src!=tar){ // if the two parents are different
        if(tar->label<src->label) swap(src,tar); // ensure the label of the parent is lexicographically smaller
        tar->parent=src; // set the parent of target to source
        src->size+=tar->size; // increment the size of the set
    }
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    // Create an array of nodes representing each character
    vector<Node*> nodes(26);
    for(int i=0;i<26;i++){
        nodes[i] =  new Node(i+1,'a'+i); // initialize the nodes with id and label
    }

    // For each pair of characters in s1 and s2, join their parents in the Disjoint-Set
    for(int i=0;i<s1.size();i++){
            joinDSU(nodes[s1[i]-'a'],nodes[s2[i]-'a']);
    }

    // For each character in baseStr, replace it with its equivalent parent in the Disjoint-Set
    for(int i=0;i<baseStr.size();i++){
        if(getParentDSU(nodes[baseStr[i]-'a'])->label<baseStr[i]){
            baseStr[i]=getParentDSU(nodes[baseStr[i]-'a'])->label;
        }
   
}

    return baseStr;
}
};