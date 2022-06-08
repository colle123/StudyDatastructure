#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 사원 ID, 이름, 급여, 5명

#define MAX 5

struct Employee {

	int ID;
	char* Name;
	int Pay;

}employee[MAX];

int main() {

	char* temp = (char*)malloc(sizeof(char) * 5); // 이름의 길이를 구해주기 위해서 임시저장소를 동적할당
	int Pay_Total = 0;                            // 합계를 구하는 Pay_Total을 선언, 0으로 초기화
	int Pay_Avg;                                  // 평균을 구하는 Pay_Avg를 선언

	for (int i = 0; i < 5; i++) {

		printf("====== %d번째 사원 입력 ======\n", i + 1); 
		printf("사원 ID : "); 
		scanf("%d", &(employee +i)->ID); // 사원 ID 입력

		printf("이름 : ");
		scanf("%s", temp); // 임시저장소 temp에 이름을 받아옴.
		employee[i].Name = (char*)malloc(strlen(temp) + 1); // 임시저장 된 이름의 길이를 구해서 그 길이만큼 employee[i].name의 배열을 동적할당 
		strcpy((employee + i)->Name, temp); // 임시저장소에 저장된 이름을 동적할당한 배열에 넣어줌.

		printf("급여 : ");
		scanf("%d", &(employee + i)->Pay); // 사원 급여 입력

	}

	
	for (int i = 0; i < 5; i++) {

		Pay_Total = Pay_Total + (employee + i)->Pay; // 사원 5명의 총합 계산
	}
	
	Pay_Avg = Pay_Total / MAX; // 사원 5명의 평균 급여 계산

	printf("\n\n=====================================\n");
	printf("총 급여액 : %d 평균급여 : %d\n", Pay_Total, Pay_Avg);

	for (int i = 0; i < 5; i++) {

		free((employee + i)->Name); // 동적할당해준 employee 배열을 free 시켜줘서 메모리 누수를 막음.
	}

	free(temp); // 임시저장소 temp를 free 해줌
}