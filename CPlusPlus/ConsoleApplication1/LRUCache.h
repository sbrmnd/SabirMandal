#pragma once
#include <map>
#include <unordered_map>

using namespace std;

// } Driver Code Ends


// design the class:

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class LRUCache
{
private:
    static int cap;
    static unordered_map<int, int> mapcache;

    static Node* root;

    static Node* getNode(int key, int value)
    {
        Node* n = new Node();

        mapcache[key] = value;

        n->prev = NULL;
        n->next = NULL;
        n->data = key;

        return n;
    }

    static void AddInCache(Node* root, int key, int value)
    {
        Node* newN = getNode(key, value);

        if (cap > 0)
        {
            if (root == NULL)
            {
                root = newN;
            }

            newN->next = root;
            root = newN;

            cap--;
        }
        else
        {
            ClearCache(root);
            AddInCache(root, key, value);
        }
    }

    static void ClearCache(Node* root)
    {
        Node* prev = NULL;

        Node* curr = root;

        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }

        //prev->next = NULL;
        curr->prev = NULL;

        cap++;

        delete curr;
    }

   

public:
    LRUCache(int cap)
    {
        // constructor for cache
        this->cap = cap;
    }

    static int get(int key)
    {
        // this function should return value corresponding to key
        auto itr = mapcache.find(key);
        if (itr != mapcache.end())
        {
            return itr->second;
        }

        return -1;
    }

    static void set(int key, int value)
    {
        // storing key, value pair
        AddInCache(root, key, value);
    }
};

// { Driver Code Starts.

//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//
//        int capacity;
//        cin >> capacity;
//        LRUCache* cache = new LRUCache(capacity);
//
//        int queries;
//        cin >> queries;
//        while (queries--)
//        {
//            string q;
//            cin >> q;
//            if (q == "SET")
//            {
//                int key;
//                cin >> key;
//                int value;
//                cin >> value;
//                cache->set(key, value);
//            }
//            else
//            {
//                int key;
//                cin >> key;
//                cout << cache->get(key) << " ";
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}
// } Driver Code Ends