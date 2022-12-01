#include <istream>
#include <ostream>

template <typename T>
struct Node{
Node(T val) {
value = val;
next = nullptr;
prev = nullptr;
}
Node* next;
Node* prev;
T value;
};

template <typename T>
class List {
public:
bool empty();
void push_front(T val);
void push_back(T val);
void insert(T val);
void pop_front();
void pop_back();
void erase();
void next();
void prev();
template<typename T2>
friend std::ostream& operator<< (std::ostream& out, List<T2> list);
List() {
head = nullptr;
end = nullptr;
cur = nullptr;
}
T pointerValue();
int pointerPosition();
private:
Node<T>* head;
Node<T>* end;
Node<T>* cur;
};

template<typename T>
bool List<T>::empty() {
return (head != nullptr);
}

template<typename T>
void List<T>::push_front(T val) {
if (!head) {
head = end = cur = new Node<T>(val);
return;
}
if (head == end) {
head = new Node<T>(val);
head->next = end;
end->prev = head;
return;
}
Node<T>* tmp = new Node<T>(val);
tmp->next = head;
head->prev = tmp;
head = tmp;
}

template<typename T>
void List<T>::push_back(T val) {
if (!head) {
head = end = cur = new Node<T>(val);
return;
}
if (head == end) {
end = new Node<T>(val);
head->next = end;
end->prev = head;
return;
}
Node<T>* tmp = new Node<T>(val);
tmp->prev = end;
end->next = tmp;
end = tmp;
}

template<typename T>
void List<T>::insert(T val) {
if (cur == head) {
push_front(val);
return;
}

Node<T>* tmp = new Node<T>(val);
cur->prev->next = tmp;
tmp->prev = cur->prev;
cur->prev = tmp;
tmp->next = cur;
}

template<typename T>
void List<T>::pop_front() {
if (head == end) {
delete head;
head = end = cur = nullptr;
return;
}
if (cur == head) {
cur = cur->next;
}
head = head->next;
delete head->prev;
head->prev = nullptr;
}

template<typename T>
void List<T>::pop_back() {
if (head == end) {
delete head;
head = end = cur = nullptr;
return;
}
if (cur == end) {
cur = cur->prev;
}
end = end->prev;
delete end->next;
end->next = nullptr;
}

template<typename T>
void List<T>::erase() {
if (cur == head) {
pop_front();
return;
}
if (cur == end) {
pop_back();
return;
}

cur->prev->next = cur->next;
cur->next->prev = cur->prev;
Node<T>* to;
if (cur != head) {
to = cur->prev;
}
else if (cur != end) {
to = cur->next;
}
else {
to = nullptr;
}
delete cur;
cur = to;
}

template<typename T>
void List<T>::next() {
if (cur == end) {
return;
}
cur = cur->next;
}

template<typename T>
void List<T>::prev() {
if (cur == head) {
return;
}
cur = cur->prev;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, List<T> list) {
Node<T>* ptr = list.head;
while(1) {
out << ptr->value << ' ';
if (!ptr->next)
break;
ptr = ptr->next;
}
return out;
}

template<typename T>
T List<T>::pointerValue() {
return cur->value;
}

template<typename T>
int List<T>::pointerPosition() {
Node<T>* ptr = head;
int cnt = 0;
while (1) {
cnt++;
if (ptr == cur)
break;
ptr = ptr->next;
}
return cnt;
}
