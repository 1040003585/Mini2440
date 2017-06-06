#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <tgmath.h>
typedef unsigned int U32;
typedef unsigned short u16;
#if 0
 void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
 int munmap(void *addr, size_t length);
#endif
 unsigned short *fbmem=NULL;
#define X_SIZE  240
#define Y_SIZE  320
#define COLOR_Red		0xf800			//��
#define COLOR_Orange	0xfc00			//��
#define COLOR_Yellow	0xffe0			//��
#define COLOR_Green		0x07e0			//��
#define COLOR_Cyan		0x07ff			//��
#define COLOR_Blue		0x001f			//��
#define COLOR_Purple	0x8010			//��
#define COLOR_Black		0x0000			//��ɫ
#define COLOR_White		0xffff			//��ɫ
/**************************************************************
320��240 16Bpp TFT LCD�������ص���ʾ�������
**************************************************************/
void PutPixel(U32 x,U32 y, U32 c )
{
	if ( (x < X_SIZE) && (y < Y_SIZE) )
		*(fbmem+y*X_SIZE+x) = c ;
}
/**************************************************************
LCD��Ļ��ʾ��ֱ��ת
// LCD display is flipped vertically
// But, think the algorithm by mathematics point.
//   3I2
//   4 I 1
//  --+--   <-8 octants  mathematical cordinate
//   5 I 8
//   6I7
**************************************************************/
void Glib_Line(int x1,int y1,int x2,int y2,int color)
{
	int dx,dy,e;
	dx=x2-x1; 
	dy=y2-y1;
    
	if(dx>=0)
	{
		if(dy >= 0) // dy>=0
		{
			if(dx>=dy) // 1/8 octant
			{
				e=dy-dx/2;
				while(x1<=x2)
				{
					PutPixel(x1,y1,color);
					if(e>0){y1+=1;e-=dx;}	
					x1+=1;
					e+=dy;
				}
			}
			else		// 2/8 octant
			{
				e=dx-dy/2;
				while(y1<=y2)
				{
					PutPixel(x1,y1,color);
					if(e>0){x1+=1;e-=dy;}	
					y1+=1;
					e+=dx;
				}
			}
		}
		else		   // dy<0
		{
			dy=-dy;   // dy=abs(dy)

			if(dx>=dy) // 8/8 octant
			{
				e=dy-dx/2;
				while(x1<=x2)
				{
					PutPixel(x1,y1,color);
					if(e>0){y1-=1;e-=dx;}	
					x1+=1;
					e+=dy;
				}
			}
			else		// 7/8 octant
			{
				e=dx-dy/2;
				while(y1>=y2)
				{
					PutPixel(x1,y1,color);
					if(e>0){x1+=1;e-=dy;}	
					y1-=1;
					e+=dx;
				}
			}
		}	
	}
	else //dx<0
	{
		dx=-dx;		//dx=abs(dx)
		if(dy >= 0) // dy>=0
		{
			if(dx>=dy) // 4/8 octant
			{
				e=dy-dx/2;
				while(x1>=x2)
				{
					PutPixel(x1,y1,color);
					if(e>0){y1+=1;e-=dx;}	
					x1-=1;
					e+=dy;
				}
			}
			else		// 3/8 octant
			{
				e=dx-dy/2;
				while(y1<=y2)
				{
					PutPixel(x1,y1,color);
					if(e>0){x1-=1;e-=dy;}	
					y1+=1;
					e+=dx;
				}
			}
		}
		else		   // dy<0
		{
			dy=-dy;   // dy=abs(dy)

			if(dx>=dy) // 5/8 octant
			{
				e=dy-dx/2;
				while(x1>=x2)
				{
					PutPixel(x1,y1,color);
					if(e>0){y1-=1;e-=dx;}	
					x1-=1;
					e+=dy;
				}
			}
			else		// 6/8 octant
			{
				e=dx-dy/2;
				while(y1>=y2)
				{
					PutPixel(x1,y1,color);
					if(e>0){x1-=1;e-=dy;}	
					y1-=1;
					e+=dx;
				}
			}
		}	
	}
}
/****************************************************************************
* ���ƣ�DrawTree()
* ���ܣ�ʹ��ͼ�η���ѧ��ʵ��һ������ȷ�滭��
* ��ڲ�����xStart,yStart   ��֦/���ɵ���ʼ��λ��
*           length          ��֦/���ɵĳ���
*           angle           ��֦/���ɵ���б�Ƕ�(����)
*           num             �ݹ�����
* ���ڲ�������
****************************************************************************/
void  DrawTree( int xStart, int yStart,
                double length,
                double angle,
                int num )
{  int xEnd, yEnd;
   
   if(num == 0) return;  	// �������ѻ���
   
   xEnd = xStart + (int)(length * cos(angle));
   yEnd = yStart - (int)(length * sin(angle));	// ����y�����෴������Ҫ���

   // ��������������
   Glib_Line(xStart, yStart, xEnd, yEnd, COLOR_Green);

   // ���������������֦
   DrawTree( xEnd, yEnd, 
             length * 0.6,
             angle + 0.624,
             num - 1 );
   
   // �����������в���֦
   DrawTree( xEnd, yEnd, 
             length * 0.85,
             angle + 0.08,
             num - 1 );
             
   // �����������Ҳ���֦
   DrawTree( xEnd, yEnd, 
             length * 0.65,
             angle - 0.6,
             num - 1 );
}

void Lcd_Fill_Screen( unsigned short *mem,unsigned int c)
{
	unsigned int x,y ;
		
    for( y = 0 ; y < Y_SIZE ; y++ )
    {
    	for( x = 0 ; x < X_SIZE; x++ )
    	{
			*(mem+y*X_SIZE+x) = c ;
    	}
    }
}

int main(void)
{
    int fd = 0;
   

    fd = open("/dev/fb/0",O_RDWR);
    printf("fd = %d\n",fd);
    fbmem = mmap(0,320*240*2,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
    printf("fbmem = %p\n",fbmem);
    Lcd_Fill_Screen(fbmem,0x001f);
    munmap(fbmem,320*240*2);
    close(fd);
    return 0;
}
