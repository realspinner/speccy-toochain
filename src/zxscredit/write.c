#include "main.h"

// print string at x,y 
int printstring(unsigned char *cadena, int x, int y, unsigned char color, unsigned char back)
{
    int length,ncarac,bucle,xx;
    int xxx = 0;
    int yyy = 0;
    unsigned char *memo=scrbuf->pixels;
    int width=scrbuf->w;

    ncarac=strlen(cadena);
    length=16*ncarac;

    if(length>width)
	{
	    xx=x;
	} else {
	    if(x==-1)
		{
		    xx=(width/2)-(length/2);
		} else {
		    xx=x;
		}
	    xxx=xx;
	    yyy=y;
	}

    for(bucle=0;bucle<ncarac;bucle++)
	{
	    printchar(memo,cadena[bucle],xxx,yyy,color,back,width);
	    xxx+=16;
	    if(xxx>=width-16)
		{
		    xxx=0;
		    yyy+=20;
		}
	}
    return 0;
}

int printchar(unsigned char *memo, unsigned char carac, int x, int y, unsigned char color, unsigned char back, int width)
{
    int bucle1,pos;
    int bucle2 = 0;
    unsigned char bit_rot;
    Uint32 px,sx;

    pos=0;
    bit_rot=0x80;

    px=SDL_MapRGB(scrbuf->format, colour_palette[3*color], colour_palette[1+3*color], colour_palette[2+3*color]);
    sx=SDL_MapRGB(scrbuf->format, colour_palette[3*back], colour_palette[1+3*back], colour_palette[2+3*back]);

    for(bucle1=y;bucle1<y+16;bucle1++)
	{
	    for(bucle2=x;bucle2<x+16;bucle2++)
		{
		    if((characters[carac-32][pos])&bit_rot)
			{
			    putpixel(scrbuf,bucle2,bucle1,px);
			} else {
			    putpixel(scrbuf,bucle2,bucle1,sx);
			}
		    bit_rot/=2;
    		    if((bucle2==x+7)||(bucle2==x+15))
			{
			    pos++;
			    bit_rot=0x80;
			}
		}
	}
    return 0;
}

unsigned char characters[96][32]={
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,2,0,2,0,2,0,0,0,0,0,3,0,3,0,0,0},
{0,0,28,224,28,224,28,224,28,224,8,64,8,64,8,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,2,64,2,64,2,64,2,64,2,64,31,240,4,128,4,128,4,128,63,224,4,128,4,128,4,128,4,128,0,0},
{0,0,1,0,3,208,4,48,8,16,8,0,8,0,4,0,3,192,0,32,0,16,0,16,16,16,24,32,23,192,1,0},
{14,0,17,0,32,128,32,128,32,128,17,0,14,56,1,192,14,0,112,224,1,16,2,8,2,8,2,8,1,16,0,224},
{0,0,0,0,7,64,9,128,8,0,8,0,4,0,12,0,18,96,34,64,33,128,32,128,32,192,17,64,14,48,0,0},
{0,0,3,128,3,128,3,128,3,128,3,128,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,64,0,128,0,128,0,128,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,128,0,128,0,128,0,64},
{0,0,16,0,8,0,8,0,8,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,8,0,8,0,8,0,16,0},
{0,0,1,0,1,0,1,0,25,48,15,224,3,128,6,192,12,96,24,48,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,63,248,1,0,1,0,1,0,1,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,128,3,128,7,0,6,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,128,3,128,3,128,0,0},
{0,0,0,16,0,32,0,32,0,64,0,64,0,128,0,128,1,0,1,0,2,0,2,0,4,0,4,0,8,0,8,0},
{0,0,3,128,12,96,8,32,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,8,32,12,96,3,128},
{0,0,3,0,29,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,31,240},
{0,0,7,128,24,64,32,32,32,32,0,32,0,32,0,64,0,128,1,0,2,0,4,0,8,0,16,0,32,16,63,240},
{0,0,15,128,16,96,0,32,0,32,0,32,0,64,7,128,0,96,0,16,0,16,0,16,0,16,32,16,24,96,7,128},
{0,0,0,192,1,64,2,64,2,64,4,64,8,64,8,64,16,64,16,64,32,64,63,240,0,64,0,64,0,64,3,240},
{0,0,31,224,16,0,16,0,16,0,16,0,23,128,24,96,0,32,0,16,0,16,0,16,0,16,0,32,48,96,15,128},
{0,0,1,224,6,0,12,0,8,0,16,0,19,192,20,32,24,16,16,16,16,16,16,16,16,16,8,16,12,32,3,192},
{0,0,63,224,32,32,32,64,0,64,0,64,0,128,0,128,0,128,0,128,1,0,1,0,1,0,2,0,2,0,2,0},
{0,0,7,128,8,64,16,32,16,32,16,32,16,32,8,64,15,192,16,32,32,16,32,16,32,16,16,32,24,96,7,128},
{0,0,3,128,12,96,24,48,16,16,16,16,16,16,8,48,12,80,3,144,0,16,0,16,0,32,0,32,0,192,31,0},
{0,0,0,0,0,0,0,0,3,128,3,128,3,128,0,0,0,0,0,0,0,0,0,0,3,128,3,128,3,128,0,0},
{0,0,0,0,0,0,7,0,7,0,7,0,0,0,0,0,0,0,0,0,0,0,7,0,7,0,14,0,12,0,24,0},
{0,0,0,0,0,0,0,48,0,192,3,0,12,0,48,0,96,0,48,0,12,0,3,0,0,192,0,48,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,248,0,0,0,0,63,248,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,48,0,12,0,3,0,0,192,0,48,0,24,0,48,0,192,3,0,12,0,48,0,0,0,0,0},
{0,0,31,0,32,128,32,64,0,64,0,64,0,64,0,128,3,0,4,0,4,0,0,0,0,0,6,0,6,0,0,0},
{0,0,7,128,24,64,16,32,32,32,32,224,33,32,34,32,34,32,34,32,34,32,33,32,32,240,16,0,24,96,7,192},
{0,0,31,128,2,128,4,64,4,64,4,64,8,32,8,32,8,32,31,240,16,16,16,16,32,8,32,8,120,60,0,0},
{0,0,127,224,16,16,16,8,16,8,16,8,16,16,31,224,16,16,16,8,16,8,16,8,16,8,16,16,127,224,0,0},
{0,0,3,200,12,40,24,24,16,8,32,0,32,0,32,0,32,0,32,0,32,0,16,8,24,24,12,48,3,192,0,0},
{0,0,127,192,32,48,32,16,32,8,32,8,32,8,32,8,32,8,32,8,32,8,32,8,32,16,32,48,127,192,0,0},
{0,0,127,240,16,16,16,16,16,16,17,0,17,0,31,0,17,0,17,0,16,8,16,8,16,8,16,8,127,248,0,0},
{0,0,63,248,8,8,8,8,8,8,8,128,8,128,15,128,8,128,8,128,8,0,8,0,8,0,8,0,63,128,0,0},
{0,0,7,144,24,80,48,48,32,16,64,0,64,0,64,0,64,0,65,248,64,16,32,16,48,16,24,32,7,192,0,0},
{0,0,124,124,16,16,16,16,16,16,16,16,16,16,31,240,16,16,16,16,16,16,16,16,16,16,16,16,124,124,0,0},
{0,0,31,240,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,31,240,0,0},
{0,0,7,252,0,32,0,32,0,32,0,32,0,32,0,32,0,32,32,32,32,32,32,32,32,64,16,192,15,0,0,0},
{0,0,124,120,16,32,16,64,16,128,17,0,18,0,22,0,25,0,16,128,16,64,16,32,16,32,16,16,124,60,0,0},
{0,0,127,0,8,0,8,0,8,0,8,0,8,0,8,0,8,0,8,0,8,8,8,8,8,8,8,8,127,248,0,0},
{0,0,112,28,48,24,48,24,40,40,40,40,36,72,36,72,34,136,35,136,32,8,32,8,32,8,32,8,120,60,0,0},
{0,0,240,252,48,16,40,16,36,16,36,16,34,16,34,16,33,16,33,16,32,144,32,144,32,80,32,48,252,48,0,0},
{0,0,7,192,24,48,48,24,32,8,64,4,64,4,64,4,64,4,64,4,64,4,32,8,48,24,24,48,7,192,0,0},
{0,0,63,224,8,16,8,8,8,8,8,8,8,8,8,16,15,224,8,0,8,0,8,0,8,0,8,0,63,128,0,0},
{0,0,7,192,24,48,48,24,32,8,64,4,64,4,64,4,64,4,64,4,64,4,32,8,48,24,24,48,7,192,3,24},
{0,0,127,192,16,32,16,16,16,16,16,16,16,16,16,32,31,192,16,128,16,64,16,32,16,32,16,16,124,28,0,0},
{0,0,7,144,24,80,32,48,32,16,32,0,24,0,7,128,0,96,0,16,0,16,32,16,48,16,40,32,39,192,0,0},
{0,0,63,248,33,8,33,8,33,8,33,8,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,15,224,0,0},
{0,0,124,248,32,16,32,16,32,16,32,16,32,16,32,16,32,16,32,16,32,16,32,16,32,16,16,32,15,192,0,0},
{0,0,124,124,32,8,32,8,16,16,16,16,8,32,8,32,8,32,4,64,4,64,4,64,2,128,3,128,1,0,0,0},
{0,0,124,124,32,8,32,8,33,8,33,8,34,136,34,136,18,144,20,80,20,80,20,80,24,48,24,48,24,48,0,0},
{0,0,124,124,16,16,8,32,8,32,4,64,2,128,1,0,2,128,4,64,4,64,8,32,16,16,16,16,124,124,0,0},
{0,0,120,60,16,16,8,32,8,32,4,64,4,64,2,128,1,0,1,0,1,0,1,0,1,0,1,0,15,224,0,0},
{0,0,63,240,32,16,32,32,32,64,32,128,0,128,1,0,2,0,4,0,4,16,8,16,16,16,32,16,63,240,0,0},
{0,0,1,192,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,192},
{16,0,16,0,8,0,8,0,4,0,4,0,2,0,2,0,1,0,1,0,0,128,0,128,0,64,0,64,0,32,0,32},
{0,0,7,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,7,0},
{0,0,2,0,7,0,8,128,16,64,32,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,254,0,0},
{0,0,12,0,6,0,3,0,1,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,15,128,16,64,0,32,0,32,15,160,16,96,32,32,32,32,32,32,16,96,15,184,0,0},
{0,0,112,0,16,0,16,0,19,224,20,24,24,8,16,4,16,4,16,4,16,4,16,4,24,8,20,24,115,224,0,0},
{0,0,0,0,0,0,0,0,7,208,24,48,16,16,32,16,32,0,32,0,32,0,32,0,16,24,24,48,7,192,0,0},
{0,0,0,112,0,16,0,16,15,144,48,80,32,48,64,16,64,16,64,16,64,16,64,16,32,48,48,80,15,156,0,0},
{0,0,0,0,0,0,0,0,7,192,24,48,16,16,32,8,32,8,63,248,32,0,32,0,16,0,24,24,7,224,0,0},
{0,0,1,240,3,8,2,0,2,0,31,240,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,31,240,0,0},
{0,0,0,0,0,0,0,0,7,216,8,48,16,16,16,16,16,16,16,16,8,48,7,208,0,16,0,32,0,96,7,192},
{0,0,112,0,16,0,16,0,16,0,19,192,20,32,24,16,16,16,16,16,16,16,16,16,16,16,16,16,124,124,0,0},
{0,0,1,0,1,0,0,0,0,0,15,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,31,240,0,0},
{0,0,0,64,0,64,0,0,0,0,31,224,0,32,0,32,0,32,0,32,0,32,0,32,0,32,0,64,0,192,31,0},
{0,0,56,0,8,0,8,0,8,0,8,240,8,64,8,128,9,0,10,0,14,0,9,0,8,128,8,64,56,120,0,0},
{0,0,31,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,63,248,0,0},
{0,0,0,0,0,0,0,0,238,112,49,136,33,8,33,8,33,8,33,8,33,8,33,8,33,8,33,8,249,140,0,0},
{0,0,0,0,0,0,0,0,115,192,20,32,24,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,124,124,0,0},
{0,0,0,0,0,0,0,0,7,192,24,48,16,16,32,8,32,8,32,8,32,8,32,8,16,16,24,48,7,192,0,0},
{0,0,0,0,0,0,0,0,55,192,24,32,16,16,16,16,16,16,16,16,24,32,23,192,16,0,16,0,16,0,126,0},
{0,0,0,0,0,0,0,0,7,216,8,48,16,16,16,16,16,16,16,16,8,48,7,208,0,16,0,16,0,16,0,252},
{0,0,0,0,0,0,0,0,28,112,5,136,6,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,63,224,0,0},
{0,0,0,0,0,0,0,0,7,208,8,48,8,16,8,0,7,0,0,224,0,16,0,16,16,16,24,32,23,192,0,0},
{0,0,8,0,8,0,8,0,63,224,8,0,8,0,8,0,8,0,8,0,8,0,8,0,8,0,4,48,3,192,0,0},
{0,0,0,0,0,0,0,0,112,112,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,48,8,80,7,152,0,0},
{0,0,0,0,0,0,0,0,124,124,16,16,16,16,8,32,8,32,8,32,4,64,4,64,2,128,3,128,1,0,0,0},
{0,0,0,0,0,0,0,0,120,60,32,8,32,8,33,8,17,16,18,144,18,144,18,144,10,160,12,96,12,96,0,0},
{0,0,0,0,0,0,0,0,60,120,16,16,8,32,4,64,2,128,1,0,2,128,4,64,8,32,16,16,60,120,0,0},
{0,0,0,0,0,0,0,0,30,120,4,32,4,32,4,64,2,64,2,128,1,128,1,0,3,0,2,0,63,128,0,0},
{0,0,0,0,0,0,0,0,31,240,16,16,16,32,0,64,0,128,1,0,2,0,4,0,8,16,16,16,31,240,0,0},
{0,0,0,192,1,0,1,0,1,0,1,0,1,0,1,0,6,0,1,0,1,0,1,0,1,0,1,0,1,0,0,192},
{0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
{0,0,6,0,1,0,1,0,1,0,1,0,1,0,1,0,0,192,1,0,1,0,1,0,1,0,1,0,1,0,6,0},
{0,0,0,0,0,0,0,0,0,0,15,12,25,152,48,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,85,84,0,0,64,4,0,0,64,4,0,0,64,4,0,0,64,4,0,0,64,4,0,0,85,84,0,0,0,0}};
