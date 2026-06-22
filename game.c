// memo
// 構造体はmain関数の外で宣言する？
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>
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
    int damege = attacker->atk + (rand() % 10); // atk ~ atk + 9random
    target->hp -= damege;
    printf("%sに%dのダメージ\n", target->name, damege);
}

void enemy_attack(Character *attacker, Character *target)
{
    int damege = attacker->atk + (rand() % 5); // atk ~ atk + 9random
    target->hp -= damege;
    printf("%sに%dのダメージ\n", target->name, damege);
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
    printf("%dダメージ", mpdamege);
    return mpdamege;
}

void enemy_mpattack(Character *attacker, Character *target)
{
    if (attacker->mp < 10)
    {
        enemy_attack(attacker, target);
        return;
    }
    attacker->mp -= 10;
    int damege = attacker->atk + (rand() % 30);
    target->hp -= damege;
    printf("%sの魔法攻撃%dのダメージ\n", attacker->name, damege);
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
        printf("れべるあぷ%dレベル\n",*level);
    }
    // 追加機能レベルがどこかのラインを超えたら、必要expを上げる
}

void show_map(char map[5][20])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int move_player(char map[5][20], int *px, int *py, int dx, int dy)
{
    int nx = *px + dx;
    int ny = *py + dy;

    if (map[ny][nx] == '#')
    {
        printf("壁だ\n");
        return 1;
    }
    map[*py][*px] = ' ';
    *px += dx;
    *py += dy;
    map[*py][*px] = 'p';

    int kakuritu = rand() % 10;
    return kakuritu;
}
/*
void move_enemy(char map[5][20], int *ex, int *ey)
{

    int dir = rand() % 4;

    int dx = 0;
    int dy = 0;

    switch (dir)
    {
    case 0:
        dy = -1;
        break;
    case 1:
        dy = 1;
        break;
    case 2:
        dx = -1;
        break;
    case 3:
        dx = 1;
        break;
    default:
        break;
    }

    int nx = *ex + dx;
    int ny = *ey + dy;

    if (map[ny][nx] == '#')
    {
        return;
    }
    map[*ey][*ex] = ' ';
    *ex = nx;
    *ey = ny;
    map[*ey][*ex] = 'e';
}
*/
void show_battle(Character *player , Character *enemy){
    printf("--------------------\n");
    printf("[%s]\n",enemy->name);
    printf("--------------------\n");
    printf("[%s]\n",player->name);
    printf("--------------------\n");
    char boxes[11];
    char mp_boxes[11];
    memset(mp_boxes, '-', 10);
    mp_boxes[10] = '\0';
    memset(boxes, '-', 10);
    boxes[10] = '\0';
    int mp_box  = player->mp *  10 / player->maxmp;
    int box  = player->hp *  10 / player->maxhp;
    for(int i = 0; i < box ; i++){
        boxes[i] = '#'; 
    }
    for(int j = 0; j < mp_box ; j++){
        mp_boxes[j] = '#'; 
    }

    printf("HP |%s| %d/%d\n",boxes,player->hp,player->maxhp);
    printf("MP |%s| %d/%d\n",mp_boxes,player->mp,player->maxmp);

    printf("--------------------\n");
    printf("> 1.たたかう 2.まほう\n");
    printf("  3.道具     4.なし\n");
    printf("--------------------\n");
}

int battle(Character *player, Character *mob, int *potion, int *exp, int *level)
{
    while (1)
    {
        system("cls");
        show_battle(player,mob);
        expup(player, mob, exp, level);
        if (mob->hp <= 0)
        {
            // enemy_index++;
            // if (enemy_index >= 3)
            //{
            //     printf("すべての敵を倒した\n");
            //     printf("gamecleare");
            //     printf("%dレベルまで到達\n", level);
            //     break;
            // }
            // printf("次の敵が現れた\n");
            // printf("%sだ\n", enemies[enemy_index].name);
            printf("%sを倒した\n", mob->name);
            return 1;
        }

        if (player->hp <= 0)
        {
            printf("gameover\n");
            printf("%dレベルまで到達\n", *level);
            return 0;
        }

        int a;
        scanf("%d", &a);

        int turn_atk = player->atk;
        switch (a)
        {
        case 1:
            attack(player, mob);
            break;
        case 2:
            mob->hp -= mpattack(player);
            break;
        case 3:
            use_potion(player, potion);
            break;
        }

        printf("敵からの攻撃\n");
        int enemy_action = rand() % 2;
        if (enemy_action == 0)
        {
            enemy_attack(mob, player);
        }
        else
        {
            enemy_mpattack(mob, player);
        }
        
    }
}


int main(void)
{
    srand(time(NULL));
    int px = 1, py = 1;
    int ex = 10, ey = 2;
    char input, map[5][20] = {
                    "###################",
                    "#                 #",
                    "#                 #",
                    "#                 #",
                    "###################",
                };
    map[py][px] = 'p';
    map[ey][ex] = 'e';
    show_map(map);
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
        scanf(" %c", &input);
        switch (input)
        {
        case 'w':
            move_player(map, &px, &py, 0, -1);
            break;
        case 's':
            move_player(map, &px, &py, 0, 1);
            break;
        case 'a':
            move_player(map, &px, &py, -1, 0);
            break;
        case 'd':
            move_player(map, &px, &py, 1, 0);
            break;
        case 'q':
            return 0;
        }
        //move_enemy(map, &ex, &ey);
        show_status(&player);
        show_map(map);
        int kakuritu = move_player(map, &px, &py, 0, 0);
        if (kakuritu == 0)
        {
            printf("戦闘開始\n");
            show_battle(&player,&enemies[enemy_index]);
            int result = battle(&player, &enemies[enemy_index], &potion, &exp, &level);
            if (result == 0)
            {
                printf("敗北\n");
                break;
            }
            enemy_index++;
            if (enemy_index >= 3)
            {
                printf("gameclear");
                break;
            }
            ex = 10, ey = 2;
        }
    }
}
