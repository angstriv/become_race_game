#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>//rand
#include <windows.h>//sleep


int randnum(int minimum, int maximum)//随机值函数(最小值,最大值)
{
	int random_number = 0;//随机数
	maximum = maximum + 1;//因为随机值不包括本数
	int funneed_maximum = maximum - minimum;//函数需要的最大值
	srand((unsigned)time(NULL));//获取时间刻
	random_number = rand() % funneed_maximum + minimum;//获取随机数(虚拟最大值+最小值=最大值)
	return random_number;//返回随机数
}

int probability(int per_cent)//概率(百分数)
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
	int input_weight = 0;//输入体重
	double standard_weight = 0;//标准体重
	double weight_difference = 0;//输入体重 和 标准体重 的 差
	int weight_status = 0;//体重状态(表示胖瘦)
	int height = 0;
	char continental_nationality[20] = "";

	//各个洲
	const char asia[16] = "asia";
	const char america[16] = "america";
	const char africa[16] = "africa";



	//输入数据
	printf("这是一个能判断一个人是否能成为您选择的洲的人的程序\n");
	printf("\n");//空行
	printf("他/她的名字(name):");
	gets(name);
	fflush(stdin);//清空缓存区
	
	while (1)//输入洲籍
	{
		printf("他/她的洲籍(continentalnationality):");
		gets(continental_nationality);
		fflush(stdin);
		if ((strcmp(continental_nationality, asia) == 0) || (strcmp(continental_nationality, america) == 0) || (strcmp(continental_nationality, africa) == 0))//洲籍是否违规
		{
			break;
		}
		else
		{
			printf("洲籍有误,重新输入\n");
		}
	}
	
	while (1)//输入性别
	{
		printf("他/她的性别(male/females):");
		gets(gender);
		fflush(stdin);
		if ((strcmp(gender, male) == 0) || (strcmp(gender, females) == 0))//性别是否违规
		{
			break;
		}
		else
		{
			printf("性别有误,重新输入\n");
		}
	}
	
	while (1)//输入体重
	{
		printf("他/她的体重(kilogram):");
		scanf("%d", &input_weight);
		fflush(stdin);
		if (input_weight > 30)//体重是否违规
		{
			break;
		}
		else
		{
			printf("体重有误,重新输入\n");
		}
	}
	
	while (1)//输入身高
	{
		printf("他/她的身高(centimetre):");
		scanf("%d", &height);
		fflush(stdin);
		if (height > 130)//身高是否违规
		{
			break;
		}
		else
		{
			printf("身高有误,重新输入\n");
		}
	}

	printf("\n");//输入和输出分开



	//获取实际数据
	if (strcmp(gender, male) == 0)//性别是否为男
	{
		if (probability(75) == 1)//75%概率是否抽中(是)
		{
			strcpy(gender, "male");//不改变
			printf("现实很喜感,性别真的是male\n");
		}
		else//(否)
		{
			strcpy(gender, "females");//改变
			printf("现实很残酷,性别可惜是females\n");
		}
	}
	else if (strcmp(gender, females) == 0)//性别是否为女
	{
		if (probability(75) == 1)//75%概率是否抽中(是)
		{
			strcpy(gender, "females");//不改变
			printf("现实很喜感,真的是females\n");
		}
		else//(否)
		{
			strcpy(gender, "male");//改变
			printf("现实很残酷,可惜是male\n");
		}

	}

	input_weight = randnum(input_weight - 4, input_weight + 4);
	printf("现实中的实际体重为%d千克\n", input_weight);
	height = randnum(height - 7, height + 7);
	printf("现实中的实际身高为%d厘米\n", height);

	printf("\n");//输出数据和最后总结分开
	


	//获取体重状态(胖、瘦)
	if (strcmp(gender, male) == 0)//性别为男
	{
		standard_weight = (height - 80) * 0.7;//获取标准体重
		weight_difference = (input_weight - standard_weight) / standard_weight;//获取体重差值
		
		if (weight_difference > 0.2)//太胖
		{
			printf("该人的体重可能太胖\n");
			weight_status = 5;
		}
		else if(weight_difference > 0.1)//偏胖
		{
			printf("该人的体重可能偏胖\n");
			weight_status = 4;
		}
		else if (weight_difference <= 0.1 && weight_difference >= -0.1)//合适
		{
			printf("该人的体重可能合适\n");
			weight_status = 3;
		}
		else if (weight_difference < -0.1)//偏瘦
		{
			printf("该人的体重可能偏瘦\n");
			weight_status = 2;
		}
		else if (weight_difference < -0.2)//太瘦
		{
			printf("该人的体重可能太瘦\n");
			weight_status = 1;
		}
		else
		{
			printf("error");
		}

	}
	else if (strcmp(gender, females) == 0)//性别为女
	{
		standard_weight = (height - 70) * 0.6;//获取标准体重
		weight_difference = (input_weight - standard_weight) / standard_weight;//获取体重差值

		if (weight_difference > 0.2)//太胖
		{
			printf("该人的体重可能太胖\n");
			weight_status = 5;
		}
		else if (weight_difference > 0.1)//偏胖
		{
			printf("该人的体重可能偏胖\n");
			weight_status = 4;
		}
		else if (weight_difference <= 0.1 && weight_difference >= -0.1)//合适
		{
			printf("该人的体重可能合适\n");
			weight_status = 3;
		}
		else if (weight_difference < -0.1)//偏瘦
		{
			printf("该人的体重可能偏瘦\n");
			weight_status = 2;
		}
		else if (weight_difference < -0.2)//太瘦
		{
			printf("该人的体重可能太瘦\n");
			weight_status = 1;
		}
		else
		{
			printf("error");
		}
	
	}



	//获取成为该种人的概率
	if (strcmp(continental_nationality, asia) == 0)//亚洲人
	{
		if (strcmp(gender, male) == 0)//性别为男
		{
			if (weight_status == 3)//合适
			{
				printf("成为该种人为高概率\n");
			}
			else if (weight_status == 2)//偏瘦
			{
				printf("成为该种人为中概率\n");
			}
			else
			{
				printf("成为该种人为低概率\n");
			}
		}
		else if (strcmp(gender, females) == 0)//性别为女
		{
			if (weight_status == 3)//合适
			{
				printf("成为该种人为高概率\n");
			}
			else if (weight_status == 4)//偏胖
			{
				printf("成为该种人为中概率\n");
			}
			else
			{
				printf("成为该种人为低概率\n");
			}
		}
	}
	else if (strcmp(continental_nationality, america) == 0)//美洲人
	{
		if (strcmp(gender, male) == 0)//性别为男
		{
			if (weight_status == 4)//偏胖
			{
				printf("成为该种人为高概率\n");
			}
			else if (weight_status == 3)//合适
			{
				printf("成为该种人为中概率\n");
			}
			else
			{
				printf("成为该种人为低概率\n");
			}
		}
		else if (strcmp(gender, females) == 0)//性别为女
		{
			if (weight_status == 4)//偏胖
			{
				printf("成为该种人为高概率\n");
			}
			else if (weight_status == 5)//太胖
			{
				printf("成为该种人为中概率\n");
			}
			else
			{
				printf("成为该种人为低概率\n");
			}
		}
	}
	else if (strcmp(continental_nationality, africa) == 0)//非洲人
	{
		if (strcmp(gender, male) == 0)//性别为男
		{
			if (weight_status == 2)//偏瘦
			{
				printf("成为该种人为高概率\n");
			}
			else if (weight_status == 3)//合适
			{
				printf("成为该种人为中概率\n");
			}
			else
			{
				printf("成为该种人为低概率\n");
			}
		}
		else if (strcmp(gender, females) == 0)//性别为女
		{
			if (weight_status == 3)//合适
			{
				printf("成为该种人为高概率\n");
			}
			else if (weight_status == 2)//偏瘦
			{
				printf("成为该种人为中概率\n");
			}
			else
			{
				printf("成为该种人为低概率\n");
			}
		}
	}


	return 0;
}





