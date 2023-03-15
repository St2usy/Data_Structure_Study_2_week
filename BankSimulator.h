#pragma once
#include "CustomerQueue.h"
#include <iostream>
class BankSimulator {
private:
	int nSimulation; // �Է�: ��ü �ùķ��̼� Ƚ��
	double probArrival; // �Է�: �����ð��� �����ϴ� ��� �� ��
	int tMaxService; // �Է�: �� ���� ���� �ִ� ���� �ð�
	int totalWaitTime; // ���: ������ ��ٸ� ���ð�
	int nCustomers; // ��� : ��ü �� ��
	int nServedCustomers; // ��� : ���� ���� �� ��
	CustomerQueue que; // �� ���ť

	// ���� ���ڸ� �����Ͽ� �� ���� ���ο� ���� �ð� �ڵ� ���� �ڵ�
	double Random() { return rand() / (double)RAND_MAX;} // rand : 0���� RAND_MAX���� ������ ���� ����
	bool IsNewCustomer() { return Random() < probArrival; } // �մ� �ڵ� ����
	int RandServiceTime() { return (int)(tMaxService * Random()) + 1; } // ���� �ð� �ڵ�����

	// ���� ������ ���� ť�� ����
	void InsertCustomer(int arrivalTime) {
		Customer a(++nCustomers, arrivalTime, RandServiceTime());
		std::cout << a.id << " ������ �湮" << "(���� �ð� : " << a.tService << "��" << std::endl;
		que.enqueue(a);
	}
public:
	//������
	BankSimulator() : nCustomers(0), totalWaitTime(0), nServedCustomers(0) {}

	//�ùķ����� �Ķ���� �Է�
	void readSimulationParameters() {
		std::cout << "�ùķ��̼� �� �ִ� �ð� : ";
		std::cin >> nSimulation;
		std::cout << std::endl;
		std::cout << "�����ð��� �����ϴ� �� �� : ";
		std::cin >> probArrival;
		std::cout << std::endl;
		std::cout << "�ùķ��̼� �� �ִ� �ð� : ";
		std::cin >> tMaxService;
		std::cout << std::endl;
		std::cout << "==============================================================" << std::endl;
	}

	void run() {
		int clock = 0;
		int serviceTime = -1;
		while (clock < nSimulation) {
			clock++;
			std::cout << "����ð� : " << clock << std::endl;

 			if (IsNewCustomer()) InsertCustomer(clock); // ���ο� ���� ���������� ť�� ����
			if (serviceTime > 0) serviceTime--;
			else {
				if (que.isEmpty()) continue;
				Customer a = que.dequeue();
				nServedCustomers++;
				totalWaitTime += clock - a.tArrival;
				std::cout << a.id << " ����" << "���� ����(���ð� : " << clock-a.tService << "��)" << std::endl;
				serviceTime = a.tService - 1;
			}
		}
	}

	void printStat() {
		std::cout << "==============================================================" << std::endl;
		std::cout << "���� ���� ���� : " << nServedCustomers << std::endl;
		std::cout << "��ü ��� �ð� : " << totalWaitTime << std::endl;
		std::cout << "���񽺰� ��մ��ð� : " << (double)totalWaitTime/nServedCustomers << std::endl;
		std::cout << "���� ��� �� �� : " << nCustomers-nServedCustomers << std::endl;
	}
};