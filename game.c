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

                        printf("攻撃\n");
                        printf("1,2から選んでね\n");
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
                                mob -= ydps;
                        }
                        printf("敵体力%d\n",mob);

                        printf("敵の攻撃\n");
                        if(bougyo > 0){
                                bougyo -= mdps;
                        }
                        if(bougyo < 0){
                                mdps -= 20;
                                y  -= mdps;
                        }
                        else {
                                y -= mdps;
                        }
                        printf("自分の体力%d\n",y);

                }
         }
        printf("finish\n");
        return 0;
}
