#include "func.h"

int main()
{
	if(!fork())
	{
		setsid();//创建新会话
		chdir("/");
		umask(0);
		int i;
		for(i=0;i<3;i++)
		{
			close(i);
		}
		while(1);
	}else{
		exit(0);
	}
}
