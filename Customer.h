#pragma once
struct Customer {
	int id; // �� ��ȣ
	int tArrival; // ���� ������ �ð�
	int tService; // �� ���� ���񽺿� �ʿ��� �ð�
	Customer(int id = 0, int tArrival = 0, int tService = 0)
		: id(id), tArrival(tArrival), tService(tService) {}
};
