#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>//rand
#include <windows.h>//sleep


int randnum(int minimum, int maximum)//���ֵ����(��Сֵ,���ֵ)
{
	int random_number = 0;//�����
	maximum = maximum + 1;//��Ϊ���ֵ����������
	int funneed_maximum = maximum - minimum;//������Ҫ�����ֵ
	srand((unsigned)time(NULL));//��ȡʱ���
	random_number = rand() % funneed_maximum + minimum;//��ȡ�����(�������ֵ+��Сֵ=���ֵ)
	return random_number;//���������
}

int probability(int per_cent)//����(�ٷ���)
{
	int random_number = randnum(0, 100);
	if (random_number <= per_cent)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int main()
{
	char name[20] = "";
	char gender[20] = "";
	const char male[20] = "male";
	const char females[20] = "females";
	int input_weight = 0;//��������
	double standard_weight = 0;//��׼����
	double weight_difference = 0;//�������� �� ��׼���� �� ��
	int weight_status = 0;//����״̬(��ʾ����)
	int height = 0;
	char continental_nationality[20] = "";

	//������
	const char asia[16] = "asia";
	const char america[16] = "america";
	const char africa[16] = "africa";



	//��������
	printf("����һ�����ж�һ�����Ƿ��ܳ�Ϊ��ѡ����޵��˵ĳ���\n");
	printf("\n");//����
	printf("��/��������(name):");
	gets(name);
	fflush(stdin);//��ջ�����
	
	while (1)//�����޼�
	{
		printf("��/�����޼�(continentalnationality):");
		gets(continental_nationality);
		fflush(stdin);
		if ((strcmp(continental_nationality, asia) == 0) || (strcmp(continental_nationality, america) == 0) || (strcmp(continental_nationality, africa) == 0))//�޼��Ƿ�Υ��
		{
			break;
		}
		else
		{
			printf("�޼�����,��������\n");
		}
	}
	
	while (1)//�����Ա�
	{
		printf("��/�����Ա�(male/females):");
		gets(gender);
		fflush(stdin);
		if ((strcmp(gender, male) == 0) || (strcmp(gender, females) == 0))//�Ա��Ƿ�Υ��
		{
			break;
		}
		else
		{
			printf("�Ա�����,��������\n");
		}
	}
	
	while (1)//��������
	{
		printf("��/��������(kilogram):");
		scanf("%d", &input_weight);
		fflush(stdin);
		if (input_weight > 30)//�����Ƿ�Υ��
		{
			break;
		}
		else
		{
			printf("��������,��������\n");
		}
	}
	
	while (1)//�������
	{
		printf("��/�������(centimetre):");
		scanf("%d", &height);
		fflush(stdin);
		if (height > 130)//����Ƿ�Υ��
		{
			break;
		}
		else
		{
			printf("�������,��������\n");
		}
	}

	printf("\n");//���������ֿ�



	//��ȡʵ������
	if (strcmp(gender, male) == 0)//�Ա��Ƿ�Ϊ��
	{
		if (probability(75) == 1)//75%�����Ƿ����(��)
		{
			strcpy(gender, "male");//���ı�
			printf("��ʵ��ϲ��,�Ա������male\n");
		}
		else//(��)
		{
			strcpy(gender, "females");//�ı�
			printf("��ʵ�ܲп�,�Ա��ϧ��females\n");
		}
	}
	else if (strcmp(gender, females) == 0)//�Ա��Ƿ�ΪŮ
	{
		if (probability(75) == 1)//75%�����Ƿ����(��)
		{
			strcpy(gender, "females");//���ı�
			printf("��ʵ��ϲ��,�����females\n");
		}
		else//(��)
		{
			strcpy(gender, "male");//�ı�
			printf("��ʵ�ܲп�,��ϧ��male\n");
		}

	}

	input_weight = randnum(input_weight - 4, input_weight + 4);
	printf("��ʵ�е�ʵ������Ϊ%dǧ��\n", input_weight);
	height = randnum(height - 7, height + 7);
	printf("��ʵ�е�ʵ�����Ϊ%d����\n", height);

	printf("\n");//������ݺ�����ܽ�ֿ�
	


	//��ȡ����״̬(�֡���)
	if (strcmp(gender, male) == 0)//�Ա�Ϊ��
	{
		standard_weight = (height - 80) * 0.7;//��ȡ��׼����
		weight_difference = (input_weight - standard_weight) / standard_weight;//��ȡ���ز�ֵ
		
		if (weight_difference > 0.2)//̫��
		{
			printf("���˵����ؿ���̫��\n");
			weight_status = 5;
		}
		else if(weight_difference > 0.1)//ƫ��
		{
			printf("���˵����ؿ���ƫ��\n");
			weight_status = 4;
		}
		else if (weight_difference <= 0.1 && weight_difference >= -0.1)//����
		{
			printf("���˵����ؿ��ܺ���\n");
			weight_status = 3;
		}
		else if (weight_difference < -0.1)//ƫ��
		{
			printf("���˵����ؿ���ƫ��\n");
			weight_status = 2;
		}
		else if (weight_difference < -0.2)//̫��
		{
			printf("���˵����ؿ���̫��\n");
			weight_status = 1;
		}
		else
		{
			printf("error");
		}

	}
	else if (strcmp(gender, females) == 0)//�Ա�ΪŮ
	{
		standard_weight = (height - 70) * 0.6;//��ȡ��׼����
		weight_difference = (input_weight - standard_weight) / standard_weight;//��ȡ���ز�ֵ

		if (weight_difference > 0.2)//̫��
		{
			printf("���˵����ؿ���̫��\n");
			weight_status = 5;
		}
		else if (weight_difference > 0.1)//ƫ��
		{
			printf("���˵����ؿ���ƫ��\n");
			weight_status = 4;
		}
		else if (weight_difference <= 0.1 && weight_difference >= -0.1)//����
		{
			printf("���˵����ؿ��ܺ���\n");
			weight_status = 3;
		}
		else if (weight_difference < -0.1)//ƫ��
		{
			printf("���˵����ؿ���ƫ��\n");
			weight_status = 2;
		}
		else if (weight_difference < -0.2)//̫��
		{
			printf("���˵����ؿ���̫��\n");
			weight_status = 1;
		}
		else
		{
			printf("error");
		}
	
	}



	//��ȡ��Ϊ�����˵ĸ���
	if (strcmp(continental_nationality, asia) == 0)//������
	{
		if (strcmp(gender, male) == 0)//�Ա�Ϊ��
		{
			if (weight_status == 3)//����
			{
				printf("��Ϊ������Ϊ�߸���\n");
			}
			else if (weight_status == 2)//ƫ��
			{
				printf("��Ϊ������Ϊ�и���\n");
			}
			else
			{
				printf("��Ϊ������Ϊ�͸���\n");
			}
		}
		else if (strcmp(gender, females) == 0)//�Ա�ΪŮ
		{
			if (weight_status == 3)//����
			{
				printf("��Ϊ������Ϊ�߸���\n");
			}
			else if (weight_status == 4)//ƫ��
			{
				printf("��Ϊ������Ϊ�и���\n");
			}
			else
			{
				printf("��Ϊ������Ϊ�͸���\n");
			}
		}
	}
	else if (strcmp(continental_nationality, america) == 0)//������
	{
		if (strcmp(gender, male) == 0)//�Ա�Ϊ��
		{
			if (weight_status == 4)//ƫ��
			{
				printf("��Ϊ������Ϊ�߸���\n");
			}
			else if (weight_status == 3)//����
			{
				printf("��Ϊ������Ϊ�и���\n");
			}
			else
			{
				printf("��Ϊ������Ϊ�͸���\n");
			}
		}
		else if (strcmp(gender, females) == 0)//�Ա�ΪŮ
		{
			if (weight_status == 4)//ƫ��
			{
				printf("��Ϊ������Ϊ�߸���\n");
			}
			else if (weight_status == 5)//̫��
			{
				printf("��Ϊ������Ϊ�и���\n");
			}
			else
			{
				printf("��Ϊ������Ϊ�͸���\n");
			}
		}
	}
	else if (strcmp(continental_nationality, africa) == 0)//������
	{
		if (strcmp(gender, male) == 0)//�Ա�Ϊ��
		{
			if (weight_status == 2)//ƫ��
			{
				printf("��Ϊ������Ϊ�߸���\n");
			}
			else if (weight_status == 3)//����
			{
				printf("��Ϊ������Ϊ�и���\n");
			}
			else
			{
				printf("��Ϊ������Ϊ�͸���\n");
			}
		}
		else if (strcmp(gender, females) == 0)//�Ա�ΪŮ
		{
			if (weight_status == 3)//����
			{
				printf("��Ϊ������Ϊ�߸���\n");
			}
			else if (weight_status == 2)//ƫ��
			{
				printf("��Ϊ������Ϊ�и���\n");
			}
			else
			{
				printf("��Ϊ������Ϊ�͸���\n");
			}
		}
	}


	return 0;
}





