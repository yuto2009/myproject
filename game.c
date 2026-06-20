// memo
// 構造体はmain関数の外で宣言する？
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
// 構造体らしい
typedef struct
{
    char name[20];
    int hp, maxhp;
    int mp, maxmp;
    int atk, def;
} Character;
// 攻撃関数player
void attack(Character *attacker, Character *target)
{
    int damege = attacker->atk + (rand() % 10); //atk ~ atk + 9random
    target->hp -= damege;
    printf("%sに%dのダメージ\n",target->name,damege);
}

void enemy_attack(Character *attacker , Character *target){
    int damege = attacker->atk + (rand() % 5); //atk ~ atk + 9random
    target->hp -= damege;
    printf("%sに%dのダメージ\n",target->name,damege);
}
// 表示関数
void show_status(Character *c)
{
    printf("[%s] HP: %d / %d \n", c->name, c->hp, c->maxhp);
}

int mpattack(Character *mpattacker)
{
    if (mpattacker->mp < 10)
    {
        printf("MPが足りない\n");
        return 0;
    }
    int mpdamege = mpattacker->atk + (rand() % 20);
    mpattacker->mp -= 10;
    printf("%dダメージ",mpdamege);
    return mpdamege;
}

void enemy_mpattack(Character * attacker, Character *target){
    if(attacker->mp < 10){
        enemy_attack(attacker, target);
        return;
    }
    attacker->mp -= 10;
    int damege = attacker->atk + (rand()% 30 );
    target->hp -= damege;
    printf("%sの魔法攻撃%dのダメージ\n", attacker->name,damege);
}

void use_potion(Character *c, int *potion)
{
    if (*potion == 0)
    {
        printf("ポーションが足りません\n");
        return;
    }

    if (c->maxhp == c->hp)
    {
        printf("体力が満タンです\n");
        return;
    }

    (*potion)--;
    c->hp += 50;

    if (c->maxhp < c->hp)
    {
        c->hp = c->maxhp;
    }
    else
    {
        printf("体力が50回復した\n");
    }
}

void expup(Character *p, Character *enemy, int *exp, int *level)
{
    if (enemy->hp <= 0)
    {
        *exp += 30;
        printf("経験値30獲得\n");
    }

    int need_exp = 50 + (*level * 20);

    if (*exp >= need_exp)
    {
        *level += 1;
        *exp -= need_exp;
        p->maxhp += 20;
        p->atk += 5;
        p->hp = p->maxhp;
        printf("れべるあぷ\n");
    }
    // 追加機能レベルがどこかのラインを超えたら、必要expを上げる
}
int main(void)
{
    srand(time(NULL));
    int a, potion = 3, exp = 0, level = 1;

    // 順番は上の構造体の宣言の順
    Character player = {"勇者", 200, 200, 50, 50, 30, 0};
    Character enemies[3] = {
        {"スライム", 100, 100, 30, 30, 20, 0},
        {"ゴブリン", 150, 150, 0, 0, 45, 0},
        {"ドラゴン", 300, 300, 100, 100, 90, 0},
    };
    int enemy_index = 0;
    printf("fight\n");
    while (1)
    {
        expup(&player, &enemies[enemy_index], &exp, &level);
        if (enemies[enemy_index].hp <= 0)
        {
            enemy_index++;
            if (enemy_index >= 3)
            {
                printf("すべての敵を倒した\n");
                break;
            }
            printf("次の敵が現れた\n");
        }

        if (player.hp <= 0)
        {
            break;
        }

        printf("攻撃\n");
        printf("1,2から選んでね\n");
        printf("1は攻撃、2は魔法、3は回復\n");
        scanf("%d", &a);

        int turn_atk = player.atk;
        switch (a)
        {
        case 1:
            attack(&player, &enemies[enemy_index]);
            break;
        case 2:
            enemies[enemy_index].hp -= turn_atk;
            break;
        case 3:
            use_potion(&player, &potion);
            break;
        }

        printf("敵からの攻撃\n");
        int enemy_action = rand() % 2;
        if(enemy_action == 0) {
            enemy_attack (&enemies[enemy_index], &player);
        } else {
            enemy_mpattack(&enemies[enemy_index], &player);
        }
        enemy_attack(&enemies[enemy_index], &player);
        printf("----------\n");
        show_status(&player);
        show_status(&enemies[enemy_index]);
        printf("----------\n");
    
    }
printf("finish\n");
return 0;
}
