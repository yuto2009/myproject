#include<stdio.h>
int main(void)
{
        int mob=100,y=200,ydps=20,mdps=30,a,bougyo=0;

        printf("fight\n");
        while(1) {
                ydps = 20;
                mdps = 30;
                bougyo = 0;
                if(mob <= 0 || y <= 0) {
                        break;
                }else {

                        printf("kougeki\n");
                        scanf("%d",&a);
                        switch (a) {
                                case 1:
                                        printf("攻撃力20増加\n");
                                        ydps += 20;
                                        break;
                                case 2:
                                        printf("防御\n");
                                        bougyo = 20;
                                        break;
                        }
                        if(bougyo == 0){
                                mob = mob - ydps;
                        }
                        printf("tekilife%d\n",mob);

                        printf("tekikougeki\n");
                        if(bougyo >  0){
                                bougyo -= mdps;
                        }
                        if(bougyo < 0){
                                mdps = mdps - 20;
                                y = y - mdps;
                        }
                        else {
                                y = y - mdps;
                        }
                        printf("mylife%d\n",y);

                }
         }
        printf("finish\n");
        return 0;
}
~
~
