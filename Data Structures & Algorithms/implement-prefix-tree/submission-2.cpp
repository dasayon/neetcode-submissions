class TrieNode
{
    public:
        bool isLeaf;
        TrieNode *children[26];
    
    TrieNode()
    {
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isLeaf=0;
    }
};
class PrefixTree {
public:
    TrieNode *root;
    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        int n=word.length();
        TrieNode *ptr=root;
        for(int i=0;i<n;i++)
        {
            int idx=word[i]-'a';
            if(!ptr->children[idx])
                ptr->children[idx]=new TrieNode();
            ptr=ptr->children[idx];
            
        }
        ptr->isLeaf=true;
    }
    
    bool search(string word) {
        int n=word.length();
        TrieNode *ptr=root;
        for(int i=0;i<n;i++)
        {
            int idx=word[i]-'a';
            if(ptr->children[idx])
                ptr=ptr->children[idx];
            else
                return 0;         
        }
       return ptr->isLeaf==true;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.length();
        TrieNode *ptr=root;
        for(int i=0;i<n;i++)
        {
            int idx=prefix[i]-'a';
            if(ptr->children[idx])
                ptr=ptr->children[idx];
            else
                return 0;         
        }
       return 1;
    }
};
