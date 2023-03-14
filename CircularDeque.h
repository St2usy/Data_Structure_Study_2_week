#pragma once
const int MAX_QUEUE_SIZE = 100;
#include "CircularQueue.h"
#include <iostream>

// 오류 처리 함수
inline void error(const char* message) {
	std::cout << message << std::endl;
	exit(1);
}

class CircularDeque : public CircularQueue {
	void addRear(int n) { enqueue(n); }
	int deleteFront() { return dequeue(); }
	int getFront() { return peek(); }
	void addFront(int n) {
		if (isFuLL()) { error("Error : Stack is FULL!!"); }
		else {
			data[front] = n;
			front = (front + 1) % MAX_QUEUE_SIZE;
		}
	}
	int deleteRear() {
		if(isEmpty()) { error("Error : Stack is FULL!!"); }
		else {
			int popdata = data[rear];
			rear = (rear - 1) % MAX_QUEUE_SIZE;
			return popdata;
		}
	}
	int getRear() {
		if (isEmpty()) { error("Error : Stack is FULL!!"); }
		else return data[rear];
	}
	void display() {
		std::cout << "덱의 갯수는 : " <<  << std::endl;
	}
};