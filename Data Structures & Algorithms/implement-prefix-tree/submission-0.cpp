class TrieNode{
public:
    TrieNode *children[26];
    bool isLeaf;
    TrieNode() {
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isLeaf = false;
    }

};
class PrefixTree{

    TrieNode *root;

    public:
        PrefixTree()
        {
            root=new TrieNode();
        }
        void insert(string word) 
        {
            int n=word.length();
            TrieNode *ptr=root;
            for(int i=0;i<n;i++)
                {
                    int idx=word[i]-'a';
                    if(ptr->children[idx]==NULL)
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
                    if(!ptr->children[idx])
                        return 0;
                    else
                        ptr=ptr->children[idx];
                }
            return ptr&&ptr->isLeaf;
        }
        
        bool startsWith(string prefix) {
            int n=prefix.length();
            TrieNode *ptr=root;
            for(int i=0;i<n;i++)
                {
                    int idx=prefix[i]-'a';
                    if(!ptr->children[idx])
                        return 0;
                    else
                        ptr=ptr->children[idx];
                }
            return ptr;
        }
};
