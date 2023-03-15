#pragma once
const int MAX_QUEUE_SIZE = 100;
#include "Customer.h"
#include <iostream>

// 오류 처리 함수
inline void error(const char* message) {
	std::cout << message << std::endl;
	exit(1);
}

class CustomerQueue {
protected:
	int rear;
	int front;
	Customer data[MAX_QUEUE_SIZE];
public:
	CustomerQueue()
		: rear(0), front(0) {}
	~CustomerQueue() {}
	bool isEmpty() {
		if (front == rear) return true;
		else return false;
	}
	bool isFuLL() {
		if ((rear + 1) % MAX_QUEUE_SIZE == front) return true;
		else return false;
	}
	void enqueue(Customer rhs) {
		if (isFuLL()) { error("Error :: Queue is Full !!"); }
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = rhs;
		}
	}
	Customer dequeue() {
		if (isEmpty()) { error("Error :: Queue is Empty !!"); }
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	Customer peek() {
		if (isEmpty()) { error("Error :: Queue is Empty !!"); }
		else {
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}
};