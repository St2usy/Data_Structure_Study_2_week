#pragma once
#include "CustomerQueue.h"
#include <iostream>
class BankSimulator {
private:
	int nSimulation; // 입력: 전체 시뮬레이션 횟수
	double probArrival; // 입력: 단위시간에 도착하는 평균 고객 수
	int tMaxService; // 입력: 한 고객에 대한 최대 서비스 시간
	int totalWaitTime; // 결과: 고객들이 기다린 전시간
	int nCustomers; // 결과 : 전체 고객 수
	int nServedCustomers; // 결과 : 서비스 받은 고객 수
	CustomerQueue que; // 고객 대기큐

	// 랜덤 숫자를 생성하여 고객 도착 여부와 서비스 시간 자동 생성 코드
	double Random() { return rand() / (double)RAND_MAX;} // rand : 0에서 RAND_MAX까지 랜덤한 숫자 생성
	bool IsNewCustomer() { return Random() < probArrival; } // 손님 자동 생성
	int RandServiceTime() { return (int)(tMaxService * Random()) + 1; } // 서비스 시간 자동생성

	// 새로 도착한 고객을 큐에 삽입
	void InsertCustomer(int arrivalTime) {
		Customer a(++nCustomers, arrivalTime, RandServiceTime());
		std::cout << a.id << " 번고객님 방문" << "(서비스 시간 : " << a.tService << "분" << std::endl;
		que.enqueue(a);
	}
public:
	//생성자
	BankSimulator() : nCustomers(0), totalWaitTime(0), nServedCustomers(0) {}

	//시뮬레이터 파라미터 입력
	void readSimulationParameters() {
		std::cout << "시뮬레이션 할 최대 시간 : ";
		std::cin >> nSimulation;
		std::cout << std::endl;
		std::cout << "단위시간에 도착하는 고객 수 : ";
		std::cin >> probArrival;
		std::cout << std::endl;
		std::cout << "시뮬레이션 할 최대 시간 : ";
		std::cin >> tMaxService;
		std::cout << std::endl;
		std::cout << "==============================================================" << std::endl;
	}

	void run() {
		int clock = 0;
		int serviceTime = -1;
		while (clock < nSimulation) {
			clock++;
			std::cout << "현재시각 : " << clock << std::endl;

 			if (IsNewCustomer()) InsertCustomer(clock); // 새로운 고객이 도착했으면 큐에 삽입
			if (serviceTime > 0) serviceTime--;
			else {
				if (que.isEmpty()) continue;
				Customer a = que.dequeue();
				nServedCustomers++;
				totalWaitTime += clock - a.tArrival;
				std::cout << a.id << " 번고객" << "서비스 시작(대기시간 : " << clock-a.tService << "분)" << std::endl;
				serviceTime = a.tService - 1;
			}
		}
	}

	void printStat() {
		std::cout << "==============================================================" << std::endl;
		std::cout << "서비스 받은 고객수 : " << nServedCustomers << std::endl;
		std::cout << "전체 대기 시간 : " << totalWaitTime << std::endl;
		std::cout << "서비스고객 평균대기시간 : " << (double)totalWaitTime/nServedCustomers << std::endl;
		std::cout << "현재 대기 고객 수 : " << nCustomers-nServedCustomers << std::endl;
	}
};