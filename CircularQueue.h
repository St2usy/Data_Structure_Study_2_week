#pragma once
const int MAX_QUEUE_SIZE = 100;
#include <iostream>

// 오류 처리 함수
inline void error(const char* message) {
	std::cout << message << std::endl;
	exit(1);
}

class CircularQueue {
protected:
	int rear;
	int front;
	int data[MAX_QUEUE_SIZE];
public:
	CircularQueue()
		: rear(0), front(0) {}
	~CircularQueue() {}
	bool isEmpty() {
		if (front == rear) return true;
		else return false;
	}
	bool isFuLL() {
		if ((rear + 1) % MAX_QUEUE_SIZE == front) return true;
		else return false;
	}
	void enqueue(int n) {
		if (isFuLL()) { error("Error :: Stack is Empty !!"); }
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}
	int dequeue() {
		if (isEmpty()) { error("Error :: Stack is Empty !!"); }
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek() {
		if (isEmpty()) { error("Error :: Stack is Empty !!"); }
		else {
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}
	void display() {
		std::cout << "큐 갯수는 : " << rear - front << std::endl;
		std::cout << "---------------Queue---------------" << std::endl;
		if (front < rear) {
			for (int i = (front + 1) % MAX_QUEUE_SIZE; i <= rear % MAX_QUEUE_SIZE; i++) {
				std::cout << data[i] << std::endl;
			}
		}
		else {
			for (int i = (front + 1) % MAX_QUEUE_SIZE; i <= (rear + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; i++) {
				std::cout << data[i] << std::endl;
			}
		}
	}
};