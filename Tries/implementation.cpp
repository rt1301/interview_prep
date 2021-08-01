#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    class Node
    {
    public:
        bool end = false;
        Node *next[26];
        Node()
        {
            end = true;
            for (int i = 0; i < 26; i++)
                next[i] = nullptr;
        }
    };
    Node *trie;
    Trie()
    {
        trie = new Node();
    }
    void insert(string word)
    {
        int i = 0;
        Node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == nullptr)
            {
                it->next[word[i] - 'a'] = new Node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }

    bool search(string word)
    {
        int i = 0;
        Node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == nullptr)
                return false;
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};

int main()
{
    Trie *newTrie = new Trie();
    vector<string>words = {"ants","egg","eggs","and"};
    for(auto w:words){
        newTrie->insert(w);
    }
    vector<string>searchWords = {"ants","cricket","Egg","egg","and","eggs"};
    for(auto w:searchWords){
        if(newTrie->search(w)){
            cout<<w<<" is found\n";
        }else{
            cout<<w<<" is not found\n";
        }
    }
    return 0;
}