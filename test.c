#include "stdio.h"
#include "string.h"

#define MAX_WORD_NUM		32

//已经完成排序
#define DONE		0
//未完成排序
#define UNDONE		1

int main(int argc, char** argv)
{
	int i,j;
	int flag = UNDONE;		//监控是否已经有序

	char *temp;
	char *buf[MAX_WORD_NUM];
	int buf_len = argc - 1;
	
	int cnt = 0;				//记录外循环次数

	if(argc < 2)
		return -1;

	for(i=0; i<buf_len; i++)
		buf[i] = argv[i+1];

	/*冒泡排序，注意循环的层次与方向*/
	for(i=0; i<buf_len-1 && flag; i++)
	{
		flag = DONE;
		cnt++;

		for(j=buf_len-2; j>=i; j--)
		{
			if(strcmp(buf[j],buf[j+1]) > 0)	//从小向大排列
			{
				temp = buf[j+1];
				buf[j+1] = buf[j];
				buf[j] = temp;
				
				flag = UNDONE;
			}
		}
	}

	for(i=0; i<buf_len-1; i++)
		printf("%s ",buf[i]);

	printf("%s\n",buf[buf_len-1]);

	printf("sort finished in %d cycles\n",cnt);

	return 0;
}
