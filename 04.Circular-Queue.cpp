#include <iostream>
#define MAX 5
using namespace std;
template <class T>
class Queue {
private:
    int front, rear, counter;
    T arr[MAX];              
public:
    Queue() {
        front = -1;
        rear = -1;
        counter = 0;
    }
    bool isEmpty() {
        return (counter == 0);
    }
    bool isFull() {
        return (counter == MAX);
    }
    void enq(T data) {
        if (!isFull()) {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX;
            arr[rear] = data;
            counter++;
        } else {
            cout << "Overflow" << endl;
        }
    }
    void deq() {
        if (!isEmpty()) {
            cout << "Dequeued: " << arr[front] << endl;
            front = (front + 1) % MAX; // Circular increment
            counter--;
        } else {
            cout << "Underflow" << endl;
        }
    } 
    void display() {
        if (isEmpty()) {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "\n============= Queue Contents =============" << endl;
        cout << "Queue: ";
        for (int i = 0; i < counter; i++) {
            int idx = (front + i) % MAX;
            cout << arr[idx] << "\t";
        }
        cout << "\nFront Index: " << front
             << " | Rear Index: " << rear
             << " | Length: " << counter << endl;
        cout << "=========================================\n"
             << endl;
    }
};
int main() {
    Queue<int> que;
    int choice;
    int val;
    cout << "What do you want to do?\n"
         << "1 - Enqueue\n"
         << "2 - Dequeue\n"
         << "3 - Display\n"
         << "4 - Exit\n";
    do {
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            que.enq(val);
            break;
        case 2:
            que.deq();
            break;
        case 3:
            que.display();
            break;
        case 4:
            cout << "Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}