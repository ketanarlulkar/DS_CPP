#include <iostream>

class CircularQueue{
    int capacity;
    int rear;
    int front;
    int count;
    int arr[];
public:
    CircularQueue(int size):capacity(size), rear(-1), front(-1), count(0){
        arr[capacity] = {0};
    }

    bool isFull(){
        if (front == (rear + 1)%capacity){
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty(){
        if (rear == -1 && front == -1){
            return true;
        } else {
            return false;
        }
    }

    void display(){
        std::cout << "\n";
        for (int i = 0; i < capacity; i++){
            std::cout << arr[i] << "\t";
        }
        std::cout << "\n";
    }
    
    void enqueue(int data){
        if (isEmpty()){
            front = 0;
            rear = 0;
            arr[rear] = data;
            count = 1;
        } else if (!isFull()){
            rear = ((rear + 1)  % capacity);
            arr[rear] = data;
            count += 1;
        } else {
            std::cout << "Queue is full" << std::endl;;
        }
    }

    int dequeue(){
        int temp = 0;
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return temp;
        }else if(rear == front){
            temp = arr[front];
            arr[front] = 0;
            front = rear = -1;
            count = 0;
        } else {
            temp = arr[front];
            arr[front] = 0;
            front = ((front + 1) % capacity);
            count -= 1;
        }
        return temp;
    }

    int countSize(){
        return count;
    }
};

int main(){

    CircularQueue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.display();
    std::cout << q1.dequeue() << std::endl;
    std::cout << q1.dequeue() << std::endl;
    q1.display();
    q1.enqueue(2);
    std::cout << q1.dequeue() << std::endl;
    q1.enqueue(3);
    std::cout << q1.dequeue() << std::endl;
    q1.enqueue(4);
    std::cout << q1.dequeue() << std::endl;
    q1.enqueue(5);
    std::cout << q1.dequeue() << std::endl;
    q1.display();
    return 0;
}