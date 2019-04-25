#include <bits/stdc++.h>

using namespace std;

int N;
vector <pair <char, int> > Table;

struct Node
{
    char charr;
    int freq;
    Node *leftChild;
    Node *rightChild;
    Node (char ch, int freq)
    {
        charr = ch;
        freq = freq;
        leftChild = NULL;
        rightChild = NULL;
    }

    bool operator > (Node a) const
    {
        return freq > a.freq;
    }

};

struct comapare
{

    bool operator()(const Node* a,const  Node *b )
    {
        return a->freq > b->freq;
    }
};

void Input()
{
    cin >> N;


    char x;
    int y;
    for (int i = 0; i < N; ++i)

    {
        cin >> x >> y;
        Table.push_back(make_pair(x, y));
    }
}

Node* Huffmans ()
{

    priority_queue < Node*, vector<Node*>, comapare > priQ;
    for (int i = 0; i < N; ++i)
    {
        priQ.push(new Node(Table[i].first, Table[i].second));
    }

    while (priQ.size() > 1)
    {
        Node *leftChild = priQ.top();
        priQ.pop();
        Node *rightChild = priQ.top();
        priQ.pop();
        Node *newNode = new Node('%', leftChild->freq + rightChild->freq);

        newNode->leftChild = leftChild;
        newNode->rightChild = rightChild;
        priQ.push(newNode);
    }

    return priQ.top();

}

map <char, string> mapCode;

void Search(Node *node, string s)
{
    ///BASE CASE
    if (node->leftChild == NULL || node->rightChild == NULL)
    {
        mapCode[node->charr] = s;

        s = s.substr(0, s.size() - 1);
        return;
    }

    Search(node->leftChild, s + "0");
    Search(node->rightChild, s + "1");


}
void Print()
{
    Node *root = Huffmans();
    Search(root, "");

    for(int i = 0; i < Table.size(); i++)
    {
        cout << Table[i].first << " : " << mapCode[Table[i].first] << endl;
    }
}

int main()
{
    //freopen("inputGFG.txt", "r", stdin);
    Input();
    Print();
    return 0;
}

