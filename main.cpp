#include <allegro.h>
#include <stdlib.h>
#include <time.h>

volatile long speed = 0;
void increment_speed()
{
    speed++;
}
END_OF_FUNCTION(increment_speed);
LOCK_VARIABLE(speed);
LOCK_FUNCTION(increment_speed);

inline void init()
{
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 456, 480, 0, 0);
    install_timer();
    install_keyboard();
    install_mouse();
    install_timer();
    install_int_ex(increment_speed, BPS_TO_TIMER(100));
}

inline void deinit()
{
    clear_keybuf();
    allegro_exit();
}
int kx,ky,odlx=3;
int i = 1;
int map[20][10]
{
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1
};
int map2[20][10]
{
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1
};
BITMAP *kafelka3=NULL;
BITMAP *kafelka4=NULL;
BITMAP *kafelka5=NULL;
BITMAP *kafelka6=NULL;
BITMAP *kafelka7=NULL;
BITMAP *kafelka8=NULL;


BITMAP *bufor=NULL;
int obrot=1,ilklockow=0;
void kreska()
{
    kx=odlx;
    masked_blit(kafelka3,bufor,0,0,350,200,kafelka3->w,kafelka3->h);
    masked_blit(kafelka3,bufor,0,0,350+26,200,kafelka3->w,kafelka3->h);
        masked_blit(kafelka3,bufor,0,0,350+26+26,200,kafelka3->w,kafelka3->h);


    if(obrot==1)
    {
        masked_blit(kafelka3,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka3,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka3,bufor,0,0,10+26+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);



    }
    if(obrot==2)
    {
        masked_blit(kafelka3,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka3,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka3,bufor,0,0,10+odlx*26,10-23-23+i*23,kafelka3->w,kafelka3->h);

    }
    if(obrot==3)obrot=1;
    if(obrot==4)obrot=2;

    masked_blit(kafelka4,bufor,0,0,10+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    if(obrot==1)
    {
        masked_blit(kafelka4,bufor,0,0,10+26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
        masked_blit(kafelka4,bufor,0,0,10+26+26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    }
}
void kreska4()
{
    kx=odlx;

      masked_blit(kafelka5,bufor,0,0,350,200-23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,350,200,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,350+26,200,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,350+26+26,200,kafelka3->w,kafelka3->h);

    if(obrot==1)
    {
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+26+odlx*26,10+23+i*23,kafelka3->w,kafelka3->h);

    }
    if(obrot==2)
    {
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10+23+i*23,kafelka3->w,kafelka3->h);

    }
    if(obrot==3)
    {
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10-23-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+23+odlx*26,10-23-23+i*23,kafelka3->w,kafelka3->h);
    }
    if(obrot==4)
    {
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10-23-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10-23+odlx*26,10-23-23+i*23,kafelka3->w,kafelka3->h);
    }
    if(obrot==5)
    {
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+26+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);

    }
    if(obrot==6)
    {
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+26+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);

    }
    if(obrot==7)
    {
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10-23-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+23+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
    }
    if(obrot==8)
    {
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10+odlx*26,10-23-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka5,bufor,0,0,10-23+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
    }


    masked_blit(kafelka4,bufor,0,0,10+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    if(obrot==1)
    {
        masked_blit(kafelka4,bufor,0,0,10+26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
        masked_blit(kafelka4,bufor,0,0,10+26+26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    }
    if(obrot==2)
    {
        masked_blit(kafelka4,bufor,0,0,10-26-odlx*26,10+18*23,kafelka4->w,kafelka4->h);
        masked_blit(kafelka4,bufor,0,0,10-26-26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    }
    if(obrot==3||obrot==4||obrot==5||obrot==6||obrot==7)
    {
        masked_blit(kafelka4,bufor,0,0,10+26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);

    }
}

void kwadrat()
{
    kx=odlx;
    masked_blit(kafelka6,bufor,0,0,350,200,kafelka3->w,kafelka3->h);
    masked_blit(kafelka6,bufor,0,0,350+26,200,kafelka3->w,kafelka3->h);
    masked_blit(kafelka6,bufor,0,0,350,200-23,kafelka3->w,kafelka3->h);
    masked_blit(kafelka6,bufor,0,0,350+26,200-23,kafelka3->w,kafelka3->h);
    masked_blit(kafelka6,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
    masked_blit(kafelka6,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
    masked_blit(kafelka6,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
    masked_blit(kafelka6,bufor,0,0,10+26+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
    masked_blit(kafelka4,bufor,0,0,10+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    masked_blit(kafelka4,bufor,0,0,10+26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
}
void kreska2()
{

    masked_blit(kafelka7,bufor,0,0,350,200,kafelka3->w,kafelka3->h);
    masked_blit(kafelka7,bufor,0,0,350+26,200,kafelka3->w,kafelka3->h);

    masked_blit(kafelka7,bufor,0,0,350,200-23,kafelka3->w,kafelka3->h);

    kx=odlx;
    if(obrot==1)
    {
        masked_blit(kafelka7,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka7,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);

        masked_blit(kafelka7,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
    }
    if(obrot==2)
    {

        masked_blit(kafelka7,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka7,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka7,bufor,0,0,10+26+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
    }
    if(obrot==3)
    {
        masked_blit(kafelka7,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka7,bufor,0,0,10+26+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka7,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
    }
    if(obrot==4)
    {
        masked_blit(kafelka7,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka7,bufor,0,0,10+26+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka7,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
    }



    masked_blit(kafelka4,bufor,0,0,10+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    masked_blit(kafelka4,bufor,0,0,10+26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);

}
void kreska3()
{
    masked_blit(kafelka8,bufor,0,0,350,200,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,350+26,200,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,350,200-23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,350-26,200-23,kafelka3->w,kafelka3->h);
    if(obrot==1)
    {
        masked_blit(kafelka8,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10-26+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
    }
    if(obrot==2)
    {
        masked_blit(kafelka8,bufor,0,0,10+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10+26+odlx*26,10+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10+26+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10+26+26+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
    }
    if(obrot==3)
    {
        masked_blit(kafelka8,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10+odlx*26,10-23-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10-26+odlx*26,10+23-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10-26+odlx*26,10+23-23-23+i*23,kafelka3->w,kafelka3->h);

    }
    if(obrot==4)
    {
        masked_blit(kafelka8,bufor,0,0,10+odlx*26,10-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10+odlx*26,10-23-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10+26+odlx*26,10+23-23+i*23,kafelka3->w,kafelka3->h);
        masked_blit(kafelka8,bufor,0,0,10+26+odlx*26,10+23-23-23+i*23,kafelka3->w,kafelka3->h);

    }

    if(obrot==5)obrot=1;
    if(obrot!=3)
    {
        masked_blit(kafelka4,bufor,0,0,10+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
        masked_blit(kafelka4,bufor,0,0,10+26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    }
    if(obrot==3)
    {
        masked_blit(kafelka4,bufor,0,0,10+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
        masked_blit(kafelka4,bufor,0,0,10-26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    }

    if(obrot==1)masked_blit(kafelka4,bufor,0,0,10-26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
    if(obrot==2)masked_blit(kafelka4,bufor,0,0,10+26+26+odlx*26,10+18*23,kafelka4->w,kafelka4->h);
}
int kloc=1;
bool nastepny=false;
bool gameover=false;
void ustaw()
{
    if(kloc==1)
    {
        if(obrot==1)
        {
            map[i][odlx]=2;
            map[i][odlx+1]=2;
            map[i][odlx+2]=2;
            map2[i][odlx]=2;
            map2[i][odlx+1]=2;
            map2[i][odlx+2]=2;
        }

        if(obrot==2)
        {
            map[i-2][odlx]=2;
            map[i][odlx]=2;
            map[i-1][odlx]=2;
            map2[i-2][odlx]=2;
            map2[i][odlx]=2;
            map2[i-1][odlx]=2;


        }
    }
    if(kloc==5)
    {
        if(obrot==1)
        {
            map[i][odlx]=3;
            map[i][odlx+1]=3;
            map[i][odlx+2]=3;
            map[i+1][odlx+2]=3;

            map2[i][odlx]=2;
            map2[i][odlx+1]=2;
            map2[i][odlx+2]=2;
            map2[i+1][odlx+2]=2;
        }

        if(obrot==2)
        {
            map[i][odlx]=3;
            map[i][odlx+1]=3;
            map[i][odlx+2]=3;
            map[i+1][odlx]=3;

            map2[i][odlx]=2;
            map2[i][odlx+1]=2;
            map2[i][odlx+2]=2;
            map2[i+1][odlx]=2;


        }
        if(obrot==3)
        {
            map[i][odlx]=3;
            map[i-1][odlx]=3;
            map[i-2][odlx]=3;
            map[i-2][odlx+1]=3;

            map2[i][odlx]=2;
            map2[i-1][odlx]=2;
            map2[i-2][odlx]=2;
            map2[i-2][odlx+1]=2;


        }
        if(obrot==4)
        {
            map[i][odlx]=3;
            map[i-1][odlx]=3;
            map[i-2][odlx]=3;
            map[i-2][odlx-1]=3;

            map2[i][odlx]=2;
            map2[i-1][odlx]=2;
            map2[i-2][odlx]=2;
            map2[i-2][odlx-1]=2;


        }
        if(obrot==5)
        {
            map[i][odlx]=3;
            map[i][odlx+1]=3;
            map[i][odlx+2]=3;
            map[i-1][odlx+2]=3;

            map2[i][odlx]=2;
            map2[i][odlx+1]=2;
            map2[i][odlx+2]=2;
            map2[i-1][odlx+2]=2;


        }
        if(obrot==6)
        {
            map[i][odlx]=3;
            map[i][odlx+1]=3;
            map[i][odlx+2]=3;
            map[i-1][odlx]=3;

            map2[i][odlx]=2;
            map2[i][odlx+1]=2;
            map2[i][odlx+2]=2;
            map2[i-1][odlx]=2;


        }
        if(obrot==7)
        {
            map[i][odlx]=3;
            map[i-1][odlx]=3;
            map[i-2][odlx]=3;
            map[i][odlx+1]=3;

            map2[i][odlx]=2;
            map2[i-1][odlx]=2;
            map2[i-2][odlx]=2;
            map2[i][odlx+1]=2;


        }
        if(obrot==8)
        {
            map[i][odlx]=3;
            map[i-1][odlx]=3;
            map[i-2][odlx]=3;
            map[i][odlx-1]=3;

            map2[i][odlx]=2;
            map2[i-1][odlx]=2;
            map2[i-2][odlx]=2;
            map2[i][odlx-1]=2;


        }
        if(obrot==9)obrot=1;

    }
    if(kloc==2)
    {
        map[i-1][odlx]=5;
        map[i-1][odlx+1]=5;
        map[i][odlx]=5;
        map[i][odlx+1]=5;

        map2[i-1][odlx]=2;
        map2[i-1][odlx+1]=2;
        map2[i][odlx]=2;
        map2[i][odlx+1]=2;
    }
    if(kloc==3)
    {
        if(obrot==1)
        {
            map[i][odlx]=6;
            map[i][odlx+1]=6;
            map[i-1][odlx]=6;
            map2[i][odlx]=2;
            map2[i][odlx+1]=2;
            map2[i-1][odlx]=2;
        }
        if(obrot==2)
        {
            map[i][odlx]=6;
            map[i][odlx+1]=6;
            map[i-1][odlx+1]=6;
            map2[i][odlx]=2;
            map2[i][odlx+1]=2;
            map2[i-1][odlx+1]=2;
        }
        if(obrot==3)
        {
            map[i-1][odlx]=6;
            map[i-1][odlx+1]=6;
            map[i][odlx+1]=6;

            map2[i-1][odlx]=2;
            map2[i-1][odlx+1]=2;
            map2[i][odlx+1]=2;
        }
        if(obrot==4)
        {
            map[i-1][odlx]=6;
            map[i-1][odlx+1]=6;
            map[i][odlx]=6;
            map2[i-1][odlx]=2;
            map2[i-1][odlx+1]=2;
            map2[i][odlx]=2;
        }
        if(obrot==5)obrot=1;
    }
    if(kloc==4)
    {

        if(obrot==1)
        {

            map[i-1][odlx]=7;
            map[i-1][odlx-1]=7;
            map[i][odlx+1]=7;
            map[i][odlx]=7;
            map2[i-1][odlx]=2;
            map2[i-1][odlx-1]=2;
            map2[i][odlx+1]=2;
            map2[i][odlx]=2;
        }
        if(obrot==2)
        {
            map[i-1][odlx+1]=7;
            map[i-1][odlx+2]=7;
            map[i][odlx]=7;
            map[i][odlx+1]=7;
            map2[i-1][odlx+1]=2;
            map2[i-1][odlx+2]=2;
            map2[i][odlx]=2;
            map2[i][odlx+1]=2;
        }
        if(obrot==3)
        {
            map[i][odlx]=7;
            map[i-1][odlx]=7;
            map[i+1][odlx-1]=7;
            map[i][odlx-1]=7;
            map2[i][odlx]=2;
            map2[i-1][odlx]=2;
            map2[i+1][odlx-1]=2;
            map2[i][odlx-1]=2;
        }
        if(obrot==4)
        {
            map[i][odlx]=7;
            map[i-1][odlx]=7;
            map[i+1][odlx+1]=7;
            map[i][odlx+1]=7;
            map2[i][odlx]=2;
            map2[i-1][odlx]=2;
            map2[i+1][odlx-1]=2;
            map2[i][odlx-1]=2;
        }
        if(obrot==5)obrot=1;
    }
}
BITMAP *kafelka0=NULL;
void wstaw()
{
    if(gameover!=true)
    {
        ustaw();
        ilklockow=ilklockow+1;
        i=1;
        srand(time(NULL));
        obrot=1;
        kloc=rand()%(5-1+1)+1;
    }
}
bool lewy=true;
bool prawy=true;

int main()
{
    init();

    BITMAP *kafelka=load_bmp("k1.bmp",default_palette);
    BITMAP *kafelka2=load_bmp("k2.bmp",default_palette);
    BITMAP *kafelka9=load_bmp("k111.bmp",default_palette);
      BITMAP *kafelka10=load_bmp("k222.bmp",default_palette);
    kafelka0=load_bmp("k0.bmp",default_palette);
    kafelka5=load_bmp("k99.bmp",default_palette);
    kafelka6=load_bmp("k44.bmp",default_palette);
    kafelka7=load_bmp("k55.bmp",default_palette);
    kafelka8=load_bmp("k88.bmp",default_palette);

    kafelka3=load_bmp("k33.bmp",default_palette);
    kafelka4=load_bmp("k4.bmp",default_palette);
    bufor=create_bitmap(800,600);
    int x=0,y=0,linie=0,score=0;
    FONT *myfont;
    PALETTE palette;
    myfont = load_font("czcionkap.pcx", palette, NULL);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"");
    set_volume(255,255);
    SAMPLE *dzwiek = NULL;
    dzwiek = load_sample("4.wav");
    gameover=false;
    int odstep=0,odstep2=0;




    while (!key[KEY_ESC] )
    {


        if(key[KEY_ESC])return 0;
        clear_to_color(bufor,makecol(0,0,64));

        textout_ex(bufor,myfont,"Punkty:",300,20 ,makecol(0,128,255),-1);
        textprintf_ex(bufor,myfont,300,60,makecol(176,176,255),-1,"%d ", score);
        textout_ex(bufor,myfont,"Klocek:",300,100 ,makecol(0,128,255),-1);
        textout_ex(bufor,myfont,"Linie:",300,250 ,makecol(0,128,255),-1);
        textprintf_ex(bufor,myfont,300,290,makecol(176,176,255),-1,"%d ", linie);
        textout_ex(bufor,myfont,"Ilosc klockow:",300,330 ,makecol(0,128,255),-1);
        textprintf_ex(bufor,myfont,300,370,makecol(176,176,255),-1,"%d ", ilklockow);
        for(int z=1; z<9; z++)
        {

            if(map2[1][z]==2)
            {
                gameover=true;
                textout_ex(bufor,font,"Niestety  przegrales!",280,450,makecol(255,0,0),-1);
            }
            if(map2[1][z]!=2&&gameover==false)textout_ex(bufor,font,"Jeszcze nie przegrales!",272,450,makecol(128,255,128),-1);

        }
        for(int i=0; i<20; i++)
        {
            for(int j=0; j<10; j++)
            {

                if(map[i][j]==1)masked_blit(kafelka,bufor,0,0,10+j*26,10+i*23,kafelka->w,kafelka->h);
                if(map[i][j]==0)masked_blit(kafelka0,bufor,0,0,10+j*26,10+i*23,kafelka0->w,kafelka0->h);
                if(map[i][j]==2)masked_blit(kafelka3,bufor,0,0,10+j*26,10+i*23,kafelka3->w,kafelka3->h);
                if(map[i][j]==3)masked_blit(kafelka5,bufor,0,0,10+j*26,10+i*23,kafelka5->w,kafelka5->h);
                if(map[i][j]==5)masked_blit(kafelka6,bufor,0,0,10+j*26,10+i*23,kafelka6->w,kafelka6->h);
                if(map[i][j]==6)masked_blit(kafelka7,bufor,0,0,10+j*26,10+i*23,kafelka7->w,kafelka7->h);
                if(map[i][j]==7)masked_blit(kafelka8,bufor,0,0,10+j*26,10+i*23,kafelka8->w,kafelka8->h);
                if(map[i][j]==8)masked_blit(kafelka9,bufor,0,0,10+j*26,10+i*23,kafelka9->w,kafelka9->h);
                if(map[i][j]==9)masked_blit(kafelka10,bufor,0,0,10+j*26,10+i*23,kafelka10->w,kafelka10->h);
            }
        }

        odstep2=odstep2+1;
        if(odstep2==10)odstep2=0;
        while( speed > 0)
{

        if(key[KEY_LEFT]&&odstep2==1&&lewy==true)odlx=odlx-1;
        if(key[KEY_RIGHT]&&odstep2==1&&prawy==true)odlx=odlx+1;
         if(i<18&&map[i+1][odlx]!=2&&odstep==1)
        {
            i=i+1;


        }
        speed--;
}


        if(kloc==1 && obrot==1 &&(i==18 || map[i+1][odlx]==2 || map[i+1][odlx+1]==2 || map[i+1][odlx+2]==2  ||   map[i+1][odlx]==3 || map[i+1][odlx+1]==3 || map[i+1][odlx+2]==3 ||   map[i+1][odlx]==5 || map[i+1][odlx+1]==5 || map[i+1][odlx+2]==5 ||   map[i+1][odlx]==6 || map[i+1][odlx+1]==6 || map[i+1][odlx+2]==6 ||   map[i+1][odlx]==7 || map[i+1][odlx+1]==7 || map[i+1][odlx+2]==7))
        {
            wstaw();
        }
        if(kloc==1 && obrot==2 &&(i==18 || map[i+1][odlx]==2 || map[i+1][odlx]==3 || map[i+1][odlx]==5 || map[i+1][odlx]==6 || map[i+1][odlx]==7))
        {
            wstaw();
        }

        if(kloc==2  &&(i==18 || map[i+1][odlx]==2 || map[i+1][odlx+1]==2 || map[i+1][odlx]==3 || map[i+1][odlx+1]==3 || map[i+1][odlx]==5 || map[i+1][odlx+1]==5 || map[i+1][odlx]==6 || map[i+1][odlx+1]==6 || map[i+1][odlx]==7 || map[i+1][odlx+1]==7))
        {

            wstaw();
        }
        if(kloc==3 && obrot == 1 &&(i==18 || map[i+1][odlx]==2 || map[i+1][odlx+1]==2 || map[i+1][odlx]==2   || map[i+1][odlx]==3 || map[i+1][odlx+1]==3 || map[i+1][odlx]==3 || map[i+1][odlx]==5 || map[i+1][odlx+1]==5 || map[i+1][odlx]==5 ||  map[i+1][odlx]==6 || map[i+1][odlx+1]==6 || map[i+1][odlx]==6 ||  map[i+1][odlx]==7 || map[i+1][odlx+1]==7 || map[i+1][odlx]==7   ))
        {

            wstaw();
        }
        if(kloc==3 && obrot == 2  &&(i==18 ||  map[i+1][odlx]==2 || map[i+1][odlx+1]==2 || map[i][odlx+1]==2 ||  map[i+1][odlx]==3 || map[i+1][odlx+1]==3 || map[i][odlx+1]==3 ||  map[i+1][odlx]==5 || map[i+1][odlx+1]==5 || map[i][odlx+1]==5 ||  map[i+1][odlx]==6 || map[i+1][odlx+1]==6 || map[i][odlx+1]==6 ||  map[i+1][odlx]==7 || map[i+1][odlx+1]==7 || map[i][odlx+1]==7))
        {

            wstaw();
        }


        if(kloc==3 && obrot == 3 &&(i==18 || map[i][odlx]==2 || map[i][odlx+1]==2 || map[i+1][odlx+1]==2 ||   map[i][odlx]==3 || map[i][odlx+1]==3 || map[i+1][odlx+1]==3 ||   map[i][odlx]==5 || map[i][odlx+1]==5 || map[i+1][odlx+1]==5 ||   map[i][odlx]==6 || map[i][odlx+1]==6 || map[i+1][odlx+1]==6 ||   map[i][odlx]==7 || map[i][odlx+1]==7 || map[i+1][odlx+1]==7))
        {

            wstaw();
        }
        if(kloc==3 && obrot == 4  &&(i==18 ||map[i][odlx]==2 || map[i][odlx+1]==2 || map[i+1][odlx]==2 ||map[i][odlx]==3 || map[i][odlx+1]==3 || map[i+1][odlx]==3  ||map[i][odlx]==5 || map[i][odlx+1]==5 || map[i+1][odlx]==5  ||map[i][odlx]==6 || map[i][odlx+1]==6 || map[i+1][odlx]==6  ||map[i][odlx]==7 || map[i][odlx+1]==7 || map[i+1][odlx]==7))
        {

            wstaw();
        }



        if(kloc==4 && obrot == 1 &&(i==18 ||   map[i][odlx]==2 || map[i][odlx-1]==2 || map[i+1][odlx+1]==2 || map[i+1][odlx]==2 || map[i][odlx]==3 || map[i][odlx-1]==3 || map[i+1][odlx+1]==3 || map[i+1][odlx]==3 || map[i][odlx]==5 || map[i][odlx-1]==5 || map[i+1][odlx+1]==5 || map[i+1][odlx]==5 || map[i][odlx]==6 || map[i][odlx-1]==6 || map[i+1][odlx+1]==6 || map[i+1][odlx]==6 || map[i][odlx]==7 || map[i][odlx-1]==7 || map[i+1][odlx+1]==7 || map[i+1][odlx]==7))
        {
            wstaw();
        }
        if(kloc==4 && obrot == 2 &&(i==18 ||   map[i][odlx+1]==2 || map[i][odlx+2]==2 || map[i+1][odlx]==2 || map[i+1][odlx+1]==2 ||   map[i][odlx+1]==3 || map[i][odlx+2]==3 || map[i+1][odlx]==3 || map[i+1][odlx+1]==3 ||   map[i][odlx+1]==5 || map[i][odlx+2]==5 || map[i+1][odlx]==5 || map[i+1][odlx+1]==5 ||   map[i][odlx+1]==6 || map[i][odlx+2]==6 || map[i+1][odlx]==6 || map[i+1][odlx+1]==6 ||   map[i][odlx+1]==7 || map[i][odlx+2]==7 || map[i+1][odlx]==7 || map[i+1][odlx+1]==7))
        {

            wstaw();
        }
        if(kloc==4 && obrot == 3 &&(i==18 ||   map[i+1][odlx]==2 || map[i][odlx]==2 || map[i+2][odlx-1]==2 || map[i+1][odlx-1]==2 ||   map[i+1][odlx]==3 || map[i][odlx]==3 || map[i+2][odlx-1]==3 || map[i+1][odlx-1]==3  ||   map[i+1][odlx]==5 || map[i][odlx]==5 || map[i+2][odlx-1]==5 || map[i+1][odlx-1]==5  ||   map[i+1][odlx]==6 || map[i][odlx]==6 || map[i+2][odlx-1]==6 || map[i+1][odlx-1]==6   ||   map[i+1][odlx]==7 || map[i][odlx]==7 || map[i+2][odlx-1]==7 || map[i+1][odlx-1]==7  ))
        {
            if(i==18)i=i-1;
            wstaw();
        }
        if(kloc==4 && obrot == 4 &&(i==18 ||   map[i+1][odlx]==2 || map[i][odlx]==2 || map[i+2][odlx+1]==2 || map[i+1][odlx+1]==2 ||   map[i+1][odlx]==3 || map[i][odlx]==3 || map[i+2][odlx+1]==3 || map[i+1][odlx+1]==3  ||   map[i+1][odlx]==5 || map[i][odlx]==5 || map[i+2][odlx+1]==5 || map[i+1][odlx+1]==5  ||   map[i+1][odlx]==6 || map[i][odlx]==6 || map[i+2][odlx+1]==6 || map[i+1][odlx+1]==6   ||   map[i+1][odlx]==7 || map[i][odlx]==7 || map[i+2][odlx+1]==7 || map[i+1][odlx+1]==7  ))
        {
            if(i==18)i=i-1;
            wstaw();
        }


        if(kloc==5 && obrot == 1 &&(i==18 ||    map[i+1][odlx]==2 || map[i+1][odlx+1]==2 || map[i+1][odlx+2]==2 || map[i+2][odlx+2]==2 ||    map[i+1][odlx]==3 || map[i+1][odlx+1]==3 || map[i+1][odlx+2]==3 || map[i+2][odlx+2]==3 ||    map[i+1][odlx]==5 || map[i+1][odlx+1]==5 || map[i+1][odlx+2]==5 || map[i+2][odlx+2]==5 ||     map[i+1][odlx]==6 || map[i+1][odlx+1]==6 || map[i+1][odlx+2]==6 || map[i+2][odlx+2]==6 ||    map[i+1][odlx]==7 || map[i+1][odlx+1]==7 || map[i+1][odlx+2]==7 || map[i+2][odlx+2]==7))
        {

            wstaw();
        }
        if(kloc==5 && obrot == 2 &&(i==18 || map[i+1][odlx]==2 ||  map[i+1][odlx+1]==2  ||  map[i+1][odlx+2]==2 || map[i+2][odlx]==2 ||  map[i+1][odlx]==3 ||  map[i+1][odlx+1]==3  ||  map[i+1][odlx+2]==3 || map[i+2][odlx]==3 ||  map[i+1][odlx]==5 ||  map[i+1][odlx+1]==5  ||  map[i+1][odlx+2]==5 || map[i+2][odlx]==5 || map[i+1][odlx]==6 ||  map[i+1][odlx+1]==6  ||  map[i+1][odlx+2]==6 || map[i+2][odlx]==6 || map[i+1][odlx]==7 ||  map[i+1][odlx+1]==7  ||  map[i+1][odlx+2]==7 || map[i+2][odlx]==7 ))
        {


            wstaw();
        }
        if(kloc==5 && obrot == 3 &&(i==18 || map[i+1][odlx]==2 || map[i][odlx]==2 || map[i-1][odlx]==2 || map[i-1][odlx+1]==2 || map[i+1][odlx]==3 || map[i][odlx]==3 || map[i-1][odlx]==3 || map[i-1][odlx+1]==3 || map[i+1][odlx]==5 || map[i][odlx]==5 || map[i-1][odlx]==5 || map[i-1][odlx+1]==5 || map[i+1][odlx]==6 || map[i][odlx]==6 || map[i-1][odlx]==6 || map[i-1][odlx+1]==6 || map[i+1][odlx]==7 || map[i][odlx]==7 || map[i-1][odlx]==7 || map[i-1][odlx+1]==7   ))
        {


            wstaw();
        }
        if(kloc==5 && obrot == 4 &&(i==18 || map[i+1][odlx]==2 || map[i][odlx]==2 || map[i-1][odlx]==2 || map[i-1][odlx-1]==2 || map[i+1][odlx]==3 || map[i][odlx]==3 || map[i-1][odlx]==3 || map[i-1][odlx-1]==3 || map[i+1][odlx]==5 || map[i][odlx]==5 || map[i-1][odlx]==5 || map[i-1][odlx-1]==5 || map[i+1][odlx]==6 || map[i][odlx]==6 || map[i-1][odlx]==6 || map[i-1][odlx-1]==6 || map[i+1][odlx]==7 || map[i][odlx]==7 || map[i-1][odlx]==7 || map[i-1][odlx-1]==7   ))
        {


            wstaw();
        }
        if(kloc==5 && obrot == 5 &&(i==18 ||    map[i+1][odlx]==2 || map[i+1][odlx+1]==2 || map[i+1][odlx+2]==2 || map[i][odlx+2]==2 ||    map[i+1][odlx]==3 || map[i+1][odlx+1]==3 || map[i+1][odlx+2]==3 || map[i][odlx+2]==3 ||    map[i+1][odlx]==5 || map[i+1][odlx+1]==5 || map[i+1][odlx+2]==5 || map[i][odlx+2]==5 ||     map[i+1][odlx]==6 || map[i+1][odlx+1]==6 || map[i+1][odlx+2]==6 || map[i][odlx+2]==6 ||    map[i+1][odlx]==7 || map[i+1][odlx+1]==7 || map[i+1][odlx+2]==7 || map[i][odlx+2]==7))
        {

            wstaw();
        }
        if(kloc==5 && obrot == 6 &&(i==18 ||    map[i+1][odlx]==2 || map[i+1][odlx+1]==2 || map[i+1][odlx+2]==2 || map[i][odlx+2]==2 ||    map[i+1][odlx]==3 || map[i+1][odlx+1]==3 || map[i+1][odlx+2]==3 || map[i][odlx]==3 ||    map[i+1][odlx]==5 || map[i+1][odlx+1]==5 || map[i+1][odlx+2]==5 || map[i][odlx]==5 ||     map[i+1][odlx]==6 || map[i+1][odlx+1]==6 || map[i+1][odlx+2]==6 || map[i][odlx]==6 ||    map[i+1][odlx]==7 || map[i+1][odlx+1]==7 || map[i+1][odlx+2]==7 || map[i][odlx]==7))
        {

            wstaw();
        }
        if(kloc==5 && obrot==7  &&(i==18 || map[i+1][odlx]==2 || map[i+1][odlx+1]==2 || map[i+1][odlx]==3 || map[i+1][odlx+1]==3 || map[i+1][odlx]==5 || map[i+1][odlx+1]==5 || map[i+1][odlx]==6 || map[i+1][odlx+1]==6 || map[i+1][odlx]==7 || map[i+1][odlx+1]==7))
        {

            wstaw();
        }
        if(kloc==5 && obrot==8  &&(i==18 || map[i+1][odlx]==2 || map[i+1][odlx-1]==2 || map[i+1][odlx]==3 || map[i-1][odlx+1]==3 || map[i+1][odlx]==5 || map[i+1][odlx+1]==5 || map[i+1][odlx]==6 || map[i+1][odlx-1]==6 || map[i+1][odlx]==7 || map[i+1][odlx-1]==7))
        {

            wstaw();
        }
        if(key[KEY_S])
        {

            do
            {
            }
            while(!key[KEY_D]);
        }
        for(int o=0; o<20; o++)
        {
            if(  map2[o][1]==2 && map2[o][2]==2 &&  map2[o][3]==2 &&  map2[o][4]==2 && map2[o][5]==2 &&  map2[o][6]==2 &&  map2[o][7]==2 )
            {


                score=score+100;
                linie=linie+1;

                for(int y=1; y<9; y++)
                {
                    map[o][y]=9;
                    map2[o][y]=9;
                    }

                play_sample(dzwiek, 255,127,1000,1);
                rest(600);
                stop_sample(dzwiek);


            }
            if(map[0][o]==2)return 0;
        }




        if(key[KEY_SPACE]&&odstep2==1)
        {

            obrot=obrot+1;
            if(obrot==9&&kloc==5)obrot=1;
            if(obrot==5&&kloc==3)obrot=1;


        }
        if(key[KEY_DOWN])i++;

        odstep=odstep+1;
        if(odstep==66)odstep=0;


        if(kloc==1)kreska();
        if(kloc==2)kwadrat();
        if(kloc==3)kreska2();
        if(kloc==4)kreska3();
        if(kloc==5)kreska4();

        blit(bufor,screen,0,0,0,0,800,600);
    }
    remove_int( increment_speed);
    deinit();
    return 0;
}
END_OF_MAIN()
