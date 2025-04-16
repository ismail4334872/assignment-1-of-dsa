#include<iostream>
using namespace std;

#define max 100

class drones {
private:
    int droneid[max];
    int priority[max];
    int top;

public:
    drones() {
        top = -1;
    }

    bool isfull();
    bool isempty();
    void push(int id, int prior);
    void pop(int& id, int& prior);
    int getTop();
};

bool drones::isfull() {
    if (top == max - 1) {
        cout << "Stack is full" << endl;
        return true;
    }
    return false;
}

bool drones::isempty() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return true;
    }
    return false;
}

void drones::push(int id, int prior) {
    if (isfull()) {
        cout << "Stack is full, cannot push" << endl;
    }
    else {
        top++;
        droneid[top] = id;
        priority[top] = prior;
    }
}

void drones::pop(int& id, int& prior) {
    if (isempty()) {
        id = -1;
        prior = -1;
    }
    else {
        int highest = 0;
        for (int i = 1; i <= top; i++) {
            if (priority[i] > priority[highest]) {
                highest = i;
            }
        }
        id = droneid[highest];
        prior = priority[highest];
        for (int i = highest; i < top; i++) {
            droneid[i] = droneid[i + 1];
            priority[i] = priority[i + 1];
        }
        top--;
    }
}

int drones::getTop() {
    return top;
}

int main() {
    drones d;
    d.push(1, 5);
    d.push(2, 3);
    d.push(3, 8);
    d.push(4, 6);
    d.push(23, 10);
    d.push(32, 11);


    int id, prior;

    d.pop(id, prior);
    cout << "Popped Drone ID: " << id << ", Priority: " << prior << endl;

    d.pop(id, prior);
    cout << "Popped Drone ID: " << id << ", Priority: " << prior << endl;

    d.pop(id, prior);
    cout << "Popped Drone ID: " << id << ", Priority: " << prior << endl;

    d.pop(id, prior);
    cout << "Popped Drone ID: " << id << ", Priority: " << prior << endl;

    d.pop(id, prior);
    cout << "Popped Drone ID: " << id << ", Priority: " << prior << endl;

    return 0;
}
