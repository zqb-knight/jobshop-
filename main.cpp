#include <windows.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#define LEN 1376
#define WID 768
#define A 3
/*unsigned _stdcall gante1(void*pArguement)//第一个甘特图
{
	int a,b;//均为循环变量
	//initgraph(1024,768,0);
	setcolor(GREEN);
	line(100,200,500,200);
	for(i=0;i<m;i++)
		for(j=0;j<10;j++)
			{
				rectangle(coordinate_0[i][k].start,20*i+10,coordinate_0[i][k].End,20*i+19);
					for(a=20*i+10;a<20*i+20;a++)
					for(b=out[i][k].begin;b<out[i][k].end;b++)
						putpixel(a,b,GREEN);
			}
	return 0;
			//putpixel(i,j,YELLOW);
} */


typedef struct xy_0{
    int start;
    int work;
    int step;
    int End;
    int f1;
}xy_0;      //存储矩形块的起点、工件号、步骤、终点

int WORK_NUM = 0,STEP_NUM = 0;
int END_TIME;
char str[100];
int t,f2;
clock_t interval,start,finish,temp;
int mac,time_jx,f = 0;
xy_0 coordinate_0[20][20];  //存储初始（未检修）的坐标

void get_struct(void);
void output();
int is_working(int i);
void push(int m, int s, int n);//m指机器，s指步骤，n指之后步骤移动的值
void insert(int m, int s, int jx,int q);//m指机器，s指步骤,jx检修时间
void output_2(void);
//void gt();


int main(void)
{
	//int i;
	//HANDLE hThread1;
    //hThread1 =(HANDLE)_beginthreadex(NULL,0,getinput,NULL,0,NULL);
   	int i,j;
    int a,b;
    int high = 0;
    
    char m[100];
    start = clock();
    for(a = 0;a < 20;a ++)
     for(b = 0;b < 20;b ++)
     {
     coordinate_0[a][b].start = 0;
     coordinate_0[a][b].work = 0;
     coordinate_0[a][b].step = 0;
     coordinate_0[a][b].End = 0;
     coordinate_0[a][b].f1 = 2;
     }
     //printf("111\n");
       get_struct();
//       printf("%d\n",coordinate_0[1][2].End);
//        runbar();
    initgraph(1376,768,0);
    setbkcolor(WHITE); 
    line(LEN / 2 - 10, 0, LEN / 2 - 10, WID);
    line(0, WID / 2 - 10, LEN, WID / 2 - 10);
	//tcolor(GREEN);
	//ne(100,200,500,200);
	for(i=0;i<=STEP_NUM;i++){
        xyprintf(10,i*20+55,"M%d",i);
		for(j=0;j<=WORK_NUM;j++)
			{
			//	rectangle(coordinate_0[i][k].start,20*i+10,coordinate_0[i][k].End,20*i+19);
					for(a=40*i+10;a<40*i+40;a++)
					  for(b=coordinate_0[i][j].start;b<coordinate_0[i][j].End;b++)
						{
						    if(coordinate_0[i][j].work == 0)  putpixel(b/2+40,a/2+50,EGERGB(0xD8,0XBF,0XD8));
                       else if(coordinate_0[i][j].work == 1)  putpixel(b/2+40,a/2+50,EGERGB(0xBA,0X55,0XD3));
                       else if(coordinate_0[i][j].work == 2)  putpixel(b/2+40,a/2+50,EGERGB(0x8A,0X2B,0XE2));
                       else if(coordinate_0[i][j].work == 3)  putpixel(b/2+40,a/2+50,EGERGB(0x0,0X0,0X8B));
                       else if(coordinate_0[i][j].work == 4)  putpixel(b/2+40,a/2+50,EGERGB(0xB0,0XC4,0XDE));
                       else if(coordinate_0[i][j].work == 5)  putpixel(b/2+40,a/2+50,EGERGB(0x5F,0X9E,0XA0));
                       else if(coordinate_0[i][j].work == 6)  putpixel(b/2+40,a/2+50,EGERGB(0x2F,0X4F,0X4F));
                       else if(coordinate_0[i][j].work == 7)  putpixel(b/2+40,a/2+50,EGERGB(0x7F,0XFF,0XAA));
                       else if(coordinate_0[i][j].work == 8)  putpixel(b/2+40,a/2+50,EGERGB(0x2E,0X8B,0X57));
                       else if(coordinate_0[i][j].work == 9)  putpixel(b/2+40,a/2+50,EGERGB(0xFF,0XFF,0X0));
                       else if(coordinate_0[i][j].work == 10) putpixel(b/2+40,a/2+50,EGERGB(0xF0,0XE6,0X8C));
                       else if(coordinate_0[i][j].work == 11) putpixel(b/2+40,a/2+50,EGERGB(0xFF,0XA5,0X0));
                       else if(coordinate_0[i][j].work == 12) putpixel(b/2+40,a/2+50,EGERGB(0x8B,0X45,0X13));
                       else if(coordinate_0[i][j].work == 13) putpixel(b/2+40,a/2+50,EGERGB(0x80,0X80,0X80));
                       else if(coordinate_0[i][j].work >= 14) putpixel(b/2+40,a/2+50,EGERGB(0xFF,0XDE,0XAD));
						}
			}
	}
	for(i = 0;i <= WORK_NUM;i ++)
    {
        if(i < 10){
        xyprintf(60*i + 10,20*(STEP_NUM+1) + 75,"W%d",i);
        //setfillcolor(EGERGB(0xFF, 0x0, 0x80));
        if(i == 0)  setfillcolor(EGERGB(0xD8,0XBF,0XD8));
        else if(i == 1) setfillcolor(EGERGB(0xBA,0X55,0XD3));
        else if(i == 2) setfillcolor(EGERGB(0x8A,0X2B,0XE2));
        else if(i == 3) setfillcolor(EGERGB(0x0,0X0,0X8B));
        else if(i == 4) setfillcolor(EGERGB(0xB0,0XC4,0XDE));
        else if(i == 5) setfillcolor(EGERGB(0x5F,0X9E,0XA0));
        else if(i == 6) setfillcolor(EGERGB(0x2F,0X4F,0X4F));
        else if(i == 7) setfillcolor(EGERGB(0x7F,0XFF,0XAA));
        else if(i == 8) setfillcolor(EGERGB(0x2E,0X8B,0X57));
        else if(i == 9) setfillcolor(EGERGB(0xFF,0XFF,0X0));
        bar(60*i + 40,20*(STEP_NUM+1) + 75,60*i + 50, 20*(STEP_NUM+1) + 94);
        }
        else{
        xyprintf(60*(i-10) + 10,20*(STEP_NUM+1) + 95,"W%d",i);
        if(i == 10) setfillcolor(EGERGB(0xF0,0XE6,0X8C));
        else if(i == 11) setfillcolor(EGERGB(0xFF,0XA5,0X0));
        else if(i == 12) setfillcolor(EGERGB(0x8B,0X45,0X13));
        else if(i == 13) setfillcolor(EGERGB(0x80,0X80,0X80));
        else if(i >= 14) setfillcolor(EGERGB(0xFF,0XDE,0XAD));

        bar(60*(i-10)+40,20*(STEP_NUM+1) + 96,60*(i-10)+50,20*(STEP_NUM+1) + 115);
        }
    }
    setfillcolor(EGERGB(0xDC,0X14,0X3C));
    xyprintf(10,20*(STEP_NUM+1) + 115,"RE");
    bar(40,20*(STEP_NUM+1) + 117,50,20*(STEP_NUM+1) + 135);
	//xyprintf(1000,500,"%d",END_TIME);
	
	/*          输出工件信息        */ 
	FILE* fptr = fopen("input.txt", "r");
	setfont(50, 20, "华文楷体");
	setcolor(BLACK);
	outtextxy(1376 / 2 + 200, high, "工件信息显示");
	high += 30;
    setfont(30, 10, "华文楷体");//指定字体高度宽度
    setcolor(BLUE);
    for(i = 0; i < 11; i++){
    	fgets(m,100,fptr);
    	if(i != 0)  xyprintf(1376 / 2, high, "工件%d", i);
    	outtextxy(1376 / 2 + 100, high, m);
    	high += 30;
	}
	
	/*       模拟加工过程      */      
	output();
	setfillcolor(WHITE);
	bar(0,WID/2,LEN/2,WID);
	setviewport(0, WID/2, LEN/2, WID, 1);
	for(i=0;i<=STEP_NUM;i++){
		setfont(18, 5, "华文楷体");
		setcolor(BLACK);
        xyprintf(10,i*20+55,"M%d",i);
		for(j=0;coordinate_0[i][j].f1 != 2 ;j++)
			{
			//	rectangle(coordinate_0[i][k].start,20*i+10,coordinate_0[i][k].End,20*i+19);
                    if(coordinate_0[i][j].f1 == 0){
					for(a=40*i+10;a<40*i+40;a++)
					  for(b=coordinate_0[i][j].start;b<coordinate_0[i][j].End;b++)
						{
						    if(coordinate_0[i][j].work == 0)  putpixel(b/2+40,a/2+50,EGERGB(0xD8,0XBF,0XD8));
                       else if(coordinate_0[i][j].work == 1)  putpixel(b/2+40,a/2+50,EGERGB(0xBA,0X55,0XD3));
                       else if(coordinate_0[i][j].work == 2)  putpixel(b/2+40,a/2+50,EGERGB(0x8A,0X2B,0XE2));
                       else if(coordinate_0[i][j].work == 3)  putpixel(b/2+40,a/2+50,EGERGB(0x0,0X0,0X8B));
                       else if(coordinate_0[i][j].work == 4)  putpixel(b/2+40,a/2+50,EGERGB(0xB0,0XC4,0XDE));
                       else if(coordinate_0[i][j].work == 5)  putpixel(b/2+40,a/2+50,EGERGB(0x5F,0X9E,0XA0));
                       else if(coordinate_0[i][j].work == 6)  putpixel(b/2+40,a/2+50,EGERGB(0x2F,0X4F,0X4F));
                       else if(coordinate_0[i][j].work == 7)  putpixel(b/2+40,a/2+50,EGERGB(0x7F,0XFF,0XAA));
                       else if(coordinate_0[i][j].work == 8)  putpixel(b/2+40,a/2+50,EGERGB(0x2E,0X8B,0X57));
                       else if(coordinate_0[i][j].work == 9)  putpixel(b/2+40,a/2+50,EGERGB(0xFF,0XFF,0X0));
                       else if(coordinate_0[i][j].work == 10) putpixel(b/2+40,a/2+50,EGERGB(0xF0,0XE6,0X8C));
                       else if(coordinate_0[i][j].work == 11) putpixel(b/2+40,a/2+50,EGERGB(0xFF,0XA5,0X0));
                       else if(coordinate_0[i][j].work == 12) putpixel(b/2+40,a/2+50,EGERGB(0x8B,0X45,0X13));
                       else if(coordinate_0[i][j].work == 13) putpixel(b/2+40,a/2+50,EGERGB(0x80,0X80,0X80));
                       else if(coordinate_0[i][j].work >= 14) putpixel(b/2+40,a/2+50,EGERGB(0xFF,0XDE,0XAD));
						}
                    }
                    else if(coordinate_0[i][j].f1 == 1){
                        
                        for(a=40*i+10;a<40*i+40;a++)
                          for(b=coordinate_0[i][j].start;b<coordinate_0[i][j].End;b++)
                            putpixel(b/2+40,a/2+50,EGERGB(0XDC,0X14,0X3C));
                    }
                        
			}
	}
	setviewport(0, 0, getwidth(), getheight(), 1);

	output_2();
   // gt();
	getch();
	return 0;
}

void get_struct()
{
        int i,j;
        int flag = 1;
        char ch;
        FILE* fptr = fopen("output.txt","r");
        if(fptr == NULL){
            printf("The file could not be opened!\n");
            exit(EXIT_FAILURE);
        }
        for(i = 0; flag ;i ++)
        {
             for(j = 0; ch != '\n' ;j ++)
             {
                    printf("000\n");
                     ch = fgetc(fptr);
                     if(ch == 'M') fseek(fptr,2,SEEK_CUR);
                     else if(ch == ' ') fseek(fptr,1,SEEK_CUR);

                     fscanf(fptr,"%d",&coordinate_0[i][j].start);
                     fseek(fptr,1,SEEK_CUR);
                     fscanf(fptr,"%d",&coordinate_0[i][j].work);
                     if(coordinate_0[i][j].work > WORK_NUM) WORK_NUM = coordinate_0[i][j].work;
                     fseek(fptr,1,SEEK_CUR);
                     fscanf(fptr,"%d",&coordinate_0[i][j].step);
                     if(coordinate_0[i][j].step > STEP_NUM) STEP_NUM = coordinate_0[i][j].step;
                     fseek(fptr,1,SEEK_CUR);
                     fscanf(fptr,"%d",&coordinate_0[i][j].End);
                     coordinate_0[i][j].f1 = 0;
                     fseek(fptr,1,SEEK_CUR);
                     ch = fgetc(fptr);
             }
             ch = fgetc(fptr);
             if(ch == 'T') {
                flag = 0;
                while(ch != '\n')
                  ch = fgetc(fptr);
                fseek(fptr,9,SEEK_CUR);
                fscanf(fptr,"%d",&END_TIME);
             }
             else fseek(fptr,-1,SEEK_CUR);

        }
        fclose(fptr);
}

void output()
{
	
	int end;
	int i,j;    //计数 
	int high = WID / 2;
	int pos = WID / 2 + 50;
	
	int lip,p,pm;// p   =   tuichang      pmyunxingweizhi
	/*       检修指令实时输出          */ 
	setfont(50, 20, "华文楷体");       //指定字体高度宽度
	setcolor(EGERGB(0xFF,0XDE,0XAD));
	setcolor(BLACK);
	xyprintf(LEN / 2, WID / 2, "检修指令实时输出");
	setfont(30, 10, "华文楷体");
    

	while(t <= END_TIME)
	{
		/*      接受检修指令       */ 
		
		if(kbhit() != 0)
	{
		    mac = 0;
		    time_jx = 0;
		    inputbox_getline("对话框","请输入检修指令",str,20);
		    for(i = 1; str[i] != ' '; i++)
	            mac = mac * 10 + ( str[i] - 48);
	        for(i = i + 1 ; str[i] != '\0'; i++)
	            time_jx = time_jx * 10 + (str[i] - 48);
	        finish = clock();
		    t = ((finish - start) / CLOCKS_PER_SEC) * A;
 	        j = is_working(mac);
 	        for(i = 0; coordinate_0[mac][i].f1 != 2;i++)
 	        {
 	        	end = i;
			}
 	        if(f2 == 1)
 	        {
 	        	
 	        	t = coordinate_0[mac][j].End;
 	        	
			}
 	        if(f2 == 0)
 	        {//?
 	        	p = time_jx - (coordinate_0[mac][j].End - t);
 	        	coordinate_0[mac][end+1].f1 = 0; 
 	        	for(i = end; i >= j; i--)
	        {
		        coordinate_0[mac][i+1].start = coordinate_0[mac][i].start;
                coordinate_0[mac][i+1].work = coordinate_0[mac][i].work;
                coordinate_0[mac][i+1].step = coordinate_0[mac][i].step;
                coordinate_0[mac][i+1].End = coordinate_0[mac][i].End;
	        }
	        coordinate_0[mac][j].start = t;
	        coordinate_0[mac][j].End = coordinate_0[mac][j].start + time_jx;
	        coordinate_0[mac][j].f1 = 1;
	        if(p > 0)
			{
				END_TIME += p;
				for(i = 0; i <= STEP_NUM; i++)
 	        	{
 	        		pm = is_working(i);
 	        		if(i != mac)
 	        		{
 	        			push(i,pm,p);
					 }
					else
					{
						if(f2 == 1) push(i,pm+2,p);
						else push(i,pm+1,p);
					}
				}
			}
 	        	
			}
			else 
			{
				coordinate_0[mac][end+1].f1 = 0;
				p = time_jx - (coordinate_0[mac][j + 1].start - coordinate_0[mac][j].End);
				for(i = end; i >= j+1; i--)
	        {
		        coordinate_0[mac][i+1].start = coordinate_0[mac][i].start;
                coordinate_0[mac][i+1].work = coordinate_0[mac][i].work;
                coordinate_0[mac][i+1].step = coordinate_0[mac][i].step;
                coordinate_0[mac][i+1].End = coordinate_0[mac][i].End;
	        }
	        coordinate_0[mac][j+1].start = coordinate_0[mac][j].End;
	        coordinate_0[mac][j+1].End = coordinate_0[mac][j+1].start + time_jx;
	        coordinate_0[mac][j+1].f1 = 1;
	        if(p > 0)
			{
				END_TIME += p;
			for(i = 0; i <= STEP_NUM; i++)
 	        	{
 	        		pm = is_working(i);
 	        		if(i != mac)
 	        		{
 	        			if(f2 == 1) push(i,pm+1,p);
						else push(i,pm,p);
					 }
					else
					{
						if(f2 == 1) push(i,pm+2,p);
						else push(i,pm+1,p);
					}
				}
			}
			}
			
		    xyprintf(LEN / 2,pos,"时间%d    机器%d  检修时间%d",t, mac, time_jx);
		    pos += 30;	
	    }
		else{
			finish = clock();
		    t = ((finish - start) / CLOCKS_PER_SEC) * A;
		}
		
		/*        模拟加工过程输出        */ 
		high = WID / 2;      //初始化 
		for(i = 0; i <= STEP_NUM; i++)
		{
			j = is_working(i);
			if(f2 == 0) 
			{
				setcolor(EGERGB(0X5F,0X9E,0XA0));   //工作为红色，空闲为绿色 
			    if(j == 0)
			       xyprintf(0, high, "%d %d 空闲       %d %d      ", t, i,t,coordinate_0[i][j].start);
			    else
				   xyprintf(0, high, "%d %d 空闲       %d %d      ", t, i,t - coordinate_0[i][j - 1].End,coordinate_0[i][j].start - coordinate_0[i][j - 1].End);   
			}
			else {
                setcolor(EGERGB(0XDC,0X14,0X3C));
			    if(coordinate_0[i][j].f1 == 0)
			     xyprintf(0, high, "%d %d 工作 %d-%d %d %d       ", t, i, coordinate_0[i][j].work, coordinate_0[i][j].step, t - coordinate_0[i][j].start, coordinate_0[i][j].End - coordinate_0[i][j].start);
			    else
			     xyprintf(0, high, "%d %d 检修      %d %d       ", t, i, t - coordinate_0[i][j].start, coordinate_0[i][j].End - coordinate_0[i][j].start);
			}
			high += 30;
			}
		}
	}

int is_working(int m)//is working 工作第几部 
{
	int i;
	for(i = 0; coordinate_0[m][i].f1 != 2; i++)
	{
		if(t < coordinate_0[m][i].start){
			f2 = 0;
			return i;
		}
		else if(t >= coordinate_0[m][i].start && t <= coordinate_0[m][i].End)
		{
			f2 = 1;
			return i;
		}
}
}

void push(int m, int s, int n)//m指机器，s指步骤，n指之后步骤移动的值
{
	int i;
	for(i = s;coordinate_0[m][i].f1 != 2 ; i++)
	{
		coordinate_0[m][i].End += n;
		coordinate_0[m][i].start += n;
	}
}

void output_2(void)
{
    FILE* fptr;
    int i,j;
    if((fptr = fopen("output2.txt","w")) == NULL)
	{
		printf("The file could not be opened!\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < STEP_NUM; i++)
	{
		fprintf(fptr,"M%d ",i);
	 	j = 0;
	 	while(coordinate_0[i][j].f1 != 2)
        {
            if(coordinate_0[i][j].f1 == 0)
	 		fprintf(fptr,"(%d,%d-%d,%d) ",coordinate_0[i][j].start,coordinate_0[i][j].work,coordinate_0[i][j].step,coordinate_0[i][j].End);
	 		else if(coordinate_0[i][j].f1 == 1)
	 		fprintf(fptr,"(%d,检修,%d) ",coordinate_0[i][j].start,coordinate_0[i][j].End);
            j ++;
        }
	 	/*while(coordinate_0[i][j].f1 == 0)  //工作
	 	{
	 		fprintf(fptr,"(%d,%d-%d,%d) ",coordinate_0[i][j].start,coordinate_0[i][j].work,coordinate_0[i][j].step,coordinate_0[i][j].End);
	 		j++;
		}
		while(coordinate_0[i][j].f1 == 1)  //检修   */
	    fprintf(fptr,"\n");
	}
	//参数还未确定！！！
		fprintf(fptr,"Time Used:%lf\n",t);
        fprintf(fptr,"End Time:%d\n",END_TIME);
        fclose(fptr);

}

/*void insert(int m, int s, int jx,int p)//m指机器，s指步骤,jx检修时间
{
	int i;
	
	if(s >= 0 && s != 1000)
	{
		for(i = WORK_NUM; i > s; i--)
	   {
		  coordinate_0[m][i+1].start = coordinate_0[m][i].start;
          coordinate_0[m][i+1].work = coordinate_0[m][i].work;
          coordinate_0[m][i+1].step = coordinate_0[m][i].step;
          coordinate_0[m][i+1].End = coordinate_0[m][i].End;
	   }
		coordinate_0[m][s+1].start = coordinate_0[m][i].End;
	    coordinate_0[m][s+1].End = coordinate_0[m][i+1].start + jx;
	    coordinate_0[m][s+1].f1 = 1;
	    if(p > 0)
	      push(m,s+1,p);
	}
	else
	{
		if(s == 1000)
		{
			for(i = WORK_NUM; i >= 0; i--)
	    {
		   coordinate_0[m][i+1].start = coordinate_0[m][i].start;
           coordinate_0[m][i+1].work = coordinate_0[m][i].work;
           coordinate_0[m][i+1].step = coordinate_0[m][i].step;
           coordinate_0[m][i+1].End = coordinate_0[m][i].End;
	    }
		  coordinate_0[m][0].start = t;
	      coordinate_0[m][0].End = coordinate_0[m][0].start + jx;
	      coordinate_0[m][0].f1 = 1;
	      if(p > 0)
	        push(m,0,p);
		}
		
		else if(s == -1000)
		{
			for(i = WORK_NUM; i > 0; i--)
	    {
		   coordinate_0[m][i+1].start = coordinate_0[m][i].start;
           coordinate_0[m][i+1].work = coordinate_0[m][i].work;
           coordinate_0[m][i+1].step = coordinate_0[m][i].step;
           coordinate_0[m][i+1].End = coordinate_0[m][i].End;
	    }
		  coordinate_0[m][1].start = t;
	      coordinate_0[m][1].End = coordinate_0[m][1].start + jx;
	      coordinate_0[m][1].f1 = 1;
	      if(p > 0)
	      push(m,1,p);
		}
		else{
			for(i = WORK_NUM; i > -s; i--)
	    {
		   coordinate_0[m][i+1].start = coordinate_0[m][i].start;
           coordinate_0[m][i+1].work = coordinate_0[m][i].work;
           coordinate_0[m][i+1].step = coordinate_0[m][i].step;
           coordinate_0[m][i+1].End = coordinate_0[m][i].End;
	    }
		  coordinate_0[m][(-s)+1].start = t;
	      coordinate_0[m][(-s)+1].End = coordinate_0[m][(-s)+1].start + jx;
	      coordinate_0[m][(-s)+1].f1 = 1;
	      if(p > 0)
	      push(m,(-s)+1,p);
		}
		}
	}*/

/*void gt()
{
	int i,j,a,b;
	for(i=0;i<=STEP_NUM;i++){
        xyprintf(10,i*20+434,"M%d",i);
		for(j=0;j<=WORK_NUM;j++)
			{
			//	rectangle(coordinate_0[i][k].start,20*i+10,coordinate_0[i][k].End,20*i+19);
					for(a=40*i+594;a<40*i+624;a++)
					  for(b=coordinate_0[i][j].start;b<coordinate_0[i][j].End;b++)
						{
					   if(coordinate_0[i][j].f1 == 1) putpixel(b/2+40,a/2+50,RED);
					   else if(coordinate_0[i][j].work == 0)  putpixel(b/2+40,a/2+50,EGERGB(0xD8,0XBF,0XD8));
                       else if(coordinate_0[i][j].work == 1)  putpixel(b/2+40,a/2+50,EGERGB(0xBA,0X55,0XD3));
                       else if(coordinate_0[i][j].work == 2)  putpixel(b/2+40,a/2+50,EGERGB(0x8A,0X2B,0XE2));
                       else if(coordinate_0[i][j].work == 3)  putpixel(b/2+40,a/2+50,EGERGB(0x0,0X0,0X8B));
                       else if(coordinate_0[i][j].work == 4)  putpixel(b/2+40,a/2+50,EGERGB(0xB0,0XC4,0XDE));
                       else if(coordinate_0[i][j].work == 5)  putpixel(b/2+40,a/2+50,EGERGB(0x5F,0X9E,0XA0));
                       else if(coordinate_0[i][j].work == 6)  putpixel(b/2+40,a/2+50,EGERGB(0x2F,0X4F,0X4F));
                       else if(coordinate_0[i][j].work == 7)  putpixel(b/2+40,a/2+50,EGERGB(0x7F,0XFF,0XAA));
                       else if(coordinate_0[i][j].work == 8)  putpixel(b/2+40,a/2+50,EGERGB(0x2E,0X8B,0X57));
                       else if(coordinate_0[i][j].work == 9)  putpixel(b/2+40,a/2+50,EGERGB(0xFF,0XFF,0X0));
                       else if(coordinate_0[i][j].work == 10) putpixel(b/2+40,a/2+50,EGERGB(0xF0,0XE6,0X8C));
                       else if(coordinate_0[i][j].work == 11) putpixel(b/2+40,a/2+50,EGERGB(0xFF,0XA5,0X0));
                       else if(coordinate_0[i][j].work == 12) putpixel(b/2+40,a/2+50,EGERGB(0x8B,0X45,0X13));
                       else if(coordinate_0[i][j].work == 13) putpixel(b/2+40,a/2+50,EGERGB(0x80,0X80,0X80));
                       else if(coordinate_0[i][j].work >= 14) putpixel(b/2+40,a/2+50,EGERGB(0xFF,0XDE,0XAD));
						}
			}
	}
	for(i = 0;i <= WORK_NUM;i ++)
    {
        if(i < 10){
        xyprintf(60*i + 10,20*(STEP_NUM+1) + 75,"W%d",i);
        //setfillcolor(EGERGB(0xFF, 0x0, 0x80));
        if(i == 0)  setfillcolor(EGERGB(0xD8,0XBF,0XD8));
        else if(i == 1) setfillcolor(EGERGB(0xBA,0X55,0XD3));
        else if(i == 2) setfillcolor(EGERGB(0x8A,0X2B,0XE2));
        else if(i == 3) setfillcolor(EGERGB(0x0,0X0,0X8B));
        else if(i == 4) setfillcolor(EGERGB(0xB0,0XC4,0XDE));
        else if(i == 5) setfillcolor(EGERGB(0x5F,0X9E,0XA0));
        else if(i == 6) setfillcolor(EGERGB(0x2F,0X4F,0X4F));
        else if(i == 7) setfillcolor(EGERGB(0x7F,0XFF,0XAA));
        else if(i == 8) setfillcolor(EGERGB(0x2E,0X8B,0X57));
        else if(i == 9) setfillcolor(EGERGB(0xFF,0XFF,0X0));
        bar(60*i + 40,20*(STEP_NUM+1) + 75,60*i + 50, 20*(STEP_NUM+1) + 94);
        }
        else{
        xyprintf(60*(i-10) + 10,20*(STEP_NUM+1) + 95,"W%d",i);
        if(i == 10) setfillcolor(EGERGB(0xF0,0XE6,0X8C));
        else if(i == 11) setfillcolor(EGERGB(0xFF,0XA5,0X0));
        else if(i == 12) setfillcolor(EGERGB(0x8B,0X45,0X13));
        else if(i == 13) setfillcolor(EGERGB(0x80,0X80,0X80));
        else if(i >= 14) setfillcolor(EGERGB(0xFF,0XDE,0XAD));

        bar(60*(i-10)+40,20*(STEP_NUM+1) + 96,60*(i-10)+50,20*(STEP_NUM+1) + 115);
        }
    }
}*/
