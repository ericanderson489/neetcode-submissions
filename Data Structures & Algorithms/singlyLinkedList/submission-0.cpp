struct Node {
    int m_value;
    Node* m_next;

    Node(int value, Node* next = nullptr) : m_value(value), m_next(next) {}
};

class LinkedList {
private:
    Node* m_head;
    Node* m_tail;
    int m_size;
public:
    LinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
    ~LinkedList() {
        Node* current = m_head;
        while (current != nullptr) {
            Node* tempNode = current->m_next;
            delete current;
            current = tempNode;
        }
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }
    void insertHead(int value) {
        if (m_head == nullptr) {
            Node* newNode = new Node(value, m_head);
            m_head = newNode;
            m_tail = newNode;
            m_size++;
            return;
        }
        Node* newNode = new Node(value, m_head);
        m_head = newNode;
        m_size++;
    }
    void insertTail(int value) {
        if (m_head == nullptr) {
            insertHead(value);
            return;
        }
        Node* newNode = new Node(value, nullptr);
        m_tail->m_next = newNode;
        m_tail = newNode;
        m_size++;
    }
    int get(int i) {
        if (m_head == nullptr || i >= m_size || i < 0) return -1;
        Node* current = m_head;
        for (int n = 0; n < i; ++n) {
            current = current->m_next;
            if (current == nullptr) return -1;
        }
        return current->m_value;
    }
    bool remove(int i) {
        if (m_head == nullptr || i < 0 || i >= m_size) return false;
        Node* current = m_head;
        Node* prev = nullptr;
        if (i == 0) {
            m_head = m_head->m_next;
            delete current;
            if (m_head == nullptr) {
                m_tail = nullptr;
            }
        } else {
            for (int n = 0; n < i; ++n) {
                prev = current;
                current = current->m_next;
            }
            prev->m_next = current->m_next;
            if (current == m_tail) {
                m_tail = prev;
            }
            delete current;
            current = nullptr;
        }
        m_size--;
        return true;
    }
    std::vector<int> getValues() {
        std::vector<int> result;
        if (m_head == nullptr) return result;
        Node* current = m_head;
        while (current != nullptr) {
            result.push_back(current->m_value);
            current = current->m_next;
        }
        return result;
    }
};