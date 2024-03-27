#include <iostream>
using namespace std;
template<class type>
class Queue {
public:
    Queue(int array_size) {
      size = array_size;
        length = 0;
        data = new type[size];
        front = 0;
        rear = size - 1;
    }

    ~Queue() {
        delete[] data;
    }

    bool is_empty() // o(1)
      {
        return length == 0;
    }

    void enqueue(type new_item) // o(1)
     {
        if (is_full()) {
            cout << "Queue is full with size " << size << endl;
            return;
        }

        rear = (rear + 1) % size;
        data[rear] = new_item;
        length++;
    }

    void dequeue() // o(1)
    {
        if (is_empty())  {
            cout << "Queue is empty" << endl;
            return ;
        }

        front = (front + 1) % size;
        length--;
            }
    bool isfind(type value)// o(N)
      {
        for (int i = 0; i < length; i++) {
            int index = (front + i) % size;
            if (value == data[index]) {
                return true;
            }
        }
        return false;
    }
    void display() // o(N)
    {
        cout << "********all elements**********\n";
        if (is_empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

   for (int i = 0; i < length; i++) {
            int index = (front + i) % size;
            cout << "Item " << i + 1 << " : " << data[index] << endl;
   }
    }
    bool is_full() // o(1)
    {
        return length == size;
    }
private:
    int size;
    int length;
    type *data;
    int front;
    int rear;
};
int main() {
    Queue<string> q(3);

    return 0;
}
