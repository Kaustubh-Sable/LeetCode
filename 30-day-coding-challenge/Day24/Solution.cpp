struct Node
{
    int key;
    int value;
    Node *next;
    Node *prev;
    
    Node(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    Node *head,*tail;
    int capacity;
    unordered_map<int,Node*> umap;
public:
    LRUCache(int capacity) {
        head=NULL;
        tail=NULL;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(umap.find(key)==umap.end())
            return -1;
        else
        {
            Node *myNode=umap[key];
            
            if(myNode!=head)
            {
                Node *mynext=myNode->next;
                Node *myprev=myNode->prev;
                
                if(myNode==tail)
                    tail = tail->prev;
                
                myprev->next = mynext;
                if(mynext)
                    mynext->prev=myprev;
                
                myNode->next=head;
                head->prev=myNode;
                head=myNode;
                head->prev=NULL;
            }
            
            return myNode->value;
        }
    }
    
    void put(int key, int value) {

        if(umap.find(key)!=umap.end())
        {
            Node *temp = umap[key];
            temp->value=value;
            get(key);
        }else if(umap.size()<capacity)
        {
            Node *newNode = new Node(key,value);
            newNode->next = head;
            if(head)
            {
                head->prev = newNode;
            }
            else
            {
                tail = newNode;
            }
            head = newNode;
            umap[key]=newNode;
        }
        else
        {
            Node *temp=tail;
            if(head!=tail)
                tail = tail->prev;
            tail->next=NULL;
            umap.erase(temp->key);
            
            put(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
