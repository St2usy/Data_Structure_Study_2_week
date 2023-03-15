#pragma once
struct Customer {
	int id; // 고객 번호
	int tArrival; // 고객이 도착한 시각
	int tService; // 이 고객의 서비스에 필요한 시간
	Customer(int id = 0, int tArrival = 0, int tService = 0)
		: id(id), tArrival(tArrival), tService(tService) {}
};
