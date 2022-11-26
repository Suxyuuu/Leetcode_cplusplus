/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

struct Node
{
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoubleLinkedList()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    };
    ~DoubleLinkedList();

    void push_front(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

    void erase(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node *back()
    {
        return tail->prev;
    }

    void pop_back()
    {
        erase(tail->prev);
    }
};

class LRUCache
{
private:
    int capacity;
    DoubleLinkedList *list;
    unordered_map<int, Node *> m;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        list = new DoubleLinkedList();
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        else
        {
            Node *node = m[key];
            list->erase(node);
            list->push_front(node);
            return node->val;
        }
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            Node *node = m[key];
            list->erase(node);
            list->push_front(node);
            node->val = value;
        }
        else
        {
            if (m.size() == capacity)
            {
                m.erase(list->back()->key);
                list->pop_back();
            }
            Node *node = new Node(key, value);
            list->push_front(node);
            m[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
