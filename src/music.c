/*
 * 应用程序music.c
 */

/*
* 创建设备文件 /dev/timer:
*     mknod /dev/timer c 123 2 -m 666
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termio.h>

#include "../include/speaker.h"
int getch(void)//解决了linux-C中不能使用getch()的问题 编写此函数需要事先将头文件termio.h引入
{
   struct termios tm, tm_old;
   int fd = 0, ch;
   if (tcgetattr(fd, &tm) < 0) {//保存现在的终端设置
     return -1;
   }
   tm_old = tm;
   cfmakeraw(&tm);//更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
   if (tcsetattr(fd, TCSANOW, &tm) < 0) {//设置上更改之后的设置
     return -1;
   }
   ch = getchar();
   if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {//更改设置为最初的样子
     return -1;
   }
   return ch;
}

int main(int argc,char *argv[])
{
	int cnt;
	int fd = open("/dev/speaker", O_RDWR);
    if(fd < 0) {
        perror("Open /dev/speaker error!\n");
        return -1;
    }
	ioctl(fd, TIMER_IOCSMODE, 3 << 1);      /* 方波方式 */
    ioctl(fd, TIMER_IOCSBYTE, 0b00110000);  /* 高低8位操作 */
	printf("请输入指令：\n");
	while(1)
	{
		char m;
		m=getch();//识别键盘输入的模式选择字符
		if(m=='d')//输入d进入电子琴模式
		{
			printf("进入电子琴\n");
			while(1)
			{
				char n;
				n=getch();//识别键盘输入的音乐字符
				if(n=='1')//低音1
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/131;
                    write(fd,&cnt, 2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
					
				}
				else if(n=='2')//低音2
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/147;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='3')//低音3
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/165;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='4')//低音4
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/175;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='5')//低音5
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/196;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='6')//低音6
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/220;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='7')//低音7
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/247;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='z')//中音1
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/262;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='x')//中音2
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/294;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='c')//中音3
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/330;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='v')//中音4
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/349;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='b')//中音5
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/392;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='n')//中音6
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/440;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='m')//中音7
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/494;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='w')//高音1
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/523;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='e')//高音2
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/587;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='r')//高音3
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/659;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='t')//高音4
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/698;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='y')//高音5
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/784;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='u')//高音6
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/880;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='i')//高音7
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/987;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='q')//在电子琴模式下，输入q退出电子琴模式
				{
					printf("退出电子琴\n");
					break;
				}
				else 
				{}
			}
		}
		else if(m=='y')//输入y播放特定乐曲，此处是播放“保卫黄河”
		{
				printf("播放乐曲 保卫黄河\n");
				int i;
				char notes[]={'w','w','c','b','w','w','c','b','c','c','b','w','w','n','n','v','e','e','b','n','b','v','c','x','c','b','n','b','v','c','x','c','z','b','n','w','c','b','r','e','w','b','n','c','b','n','w','c','b','r','e','w','b','n','w','b','n','b','n','b','w','w','b','c','b','n','b','e','e','b','n','w','w','b','n','e','e','b','n','r','r','b','n','r','e','w'};
				//notes[]是乐曲的乐谱
				for(i = 0; i < 86; i++) {
					char n;
					n=notes[i];
				    if((i==3)||(i==7)||(i==12)||(i==17)||(i==24)||(i==32)||(i==36)||(i==43)||(i==47)||(i==54)||(i==61)||(i==68)||(i==72)||(i==76)||(i==80))
					{//设定停顿点，停顿点处音乐字符播放延迟0.6s
				if(n=='1')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/131;
                    write(fd,&cnt, 2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
					
				}
				else if(n=='2')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/147;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='3')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/165;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='4')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/175;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='5')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/196;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='6')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/220;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='7')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/247;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='z')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/262;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='x')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/294;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='c')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/330;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='v')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/349;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='b')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/392;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='n')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/440;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='m')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/494;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='w')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/523;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='e')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/587;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='r')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/659;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='t')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/698;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='y')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/784;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='u')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/880;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='i')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/987;
					write(fd,&cnt,2);
					usleep(600000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else {}
					}
					else//正常音乐字符处延迟0.22s
					{
						if(n=='1')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/131;
                    write(fd,&cnt, 2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
					
				}
				else if(n=='2')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/147;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='3')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/165;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='4')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/175;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='5')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/196;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='6')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/220;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='7')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/247;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='z')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/262;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='x')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/294;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='c')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/330;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='v')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/349;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='b')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/392;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='n')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/440;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='m')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/494;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='w')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/523;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='e')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/587;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='r')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/659;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='t')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/698;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='y')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/784;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='u')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/880;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else if(n=='i')
				{
					ioctl(fd, TIMER_SPEAKERON, 0);
					cnt=1193182/987;
					write(fd,&cnt,2);
					usleep(220000);
					ioctl(fd, TIMER_SPEAKEROFF, 0);
				}
				else {}
					}
				}
				//ioctl(fd, TIMER_SPEAKEROFF, 0);
	     }
		else if(m=='q')//输入q退出
		{
			printf("退出\n");
			break;
		}
		else
			printf("请输入正确指令！\n");
	}
    close(fd);
	return 0;
}
