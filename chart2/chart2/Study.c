#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��� ID, �̸�, �޿�, 5��

#define MAX 5

struct Employee {

	int ID;
	char* Name;
	int Pay;

}employee[MAX];

int main() {

	char* temp = (char*)malloc(sizeof(char) * 5); // �̸��� ���̸� �����ֱ� ���ؼ� �ӽ�����Ҹ� �����Ҵ�
	int Pay_Total = 0;                            // �հ踦 ���ϴ� Pay_Total�� ����, 0���� �ʱ�ȭ
	int Pay_Avg;                                  // ����� ���ϴ� Pay_Avg�� ����

	for (int i = 0; i < 5; i++) {

		printf("====== %d��° ��� �Է� ======\n", i + 1); 
		printf("��� ID : "); 
		scanf("%d", &(employee +i)->ID); // ��� ID �Է�

		printf("�̸� : ");
		scanf("%s", temp); // �ӽ������ temp�� �̸��� �޾ƿ�.
		employee[i].Name = (char*)malloc(strlen(temp) + 1); // �ӽ����� �� �̸��� ���̸� ���ؼ� �� ���̸�ŭ employee[i].name�� �迭�� �����Ҵ� 
		strcpy((employee + i)->Name, temp); // �ӽ�����ҿ� ����� �̸��� �����Ҵ��� �迭�� �־���.

		printf("�޿� : ");
		scanf("%d", &(employee + i)->Pay); // ��� �޿� �Է�

	}

	
	for (int i = 0; i < 5; i++) {

		Pay_Total = Pay_Total + (employee + i)->Pay; // ��� 5���� ���� ���
	}
	
	Pay_Avg = Pay_Total / MAX; // ��� 5���� ��� �޿� ���

	printf("\n\n=====================================\n");
	printf("�� �޿��� : %d ��ձ޿� : %d\n", Pay_Total, Pay_Avg);

	for (int i = 0; i < 5; i++) {

		free((employee + i)->Name); // �����Ҵ����� employee �迭�� free �����༭ �޸� ������ ����.
	}

	free(temp); // �ӽ������ temp�� free ����
}