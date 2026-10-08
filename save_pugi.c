#include<stdio.h>

struct people {
        int num;
        char type[5];
        char explain[100];
};

void swapnum (char birthdays[],int numbers[]) {
        int i;
        for(i=0;i<8;i++) {
                numbers[i] =  birthdays[i] - '0';
        }
};

int main(void) {
        struct people lifes[] ={{1,"a","a"},
                                {2,"a","a"},
                                {3,"a","a"},
                                {4,"b","b"},
                                {5,"c","c"},
                                {6,"d","d"},
                                {7,"e","e"},
                                {8,"f","f"},
                                {9,"g","g"},
                                {11,"h","h"},
                                {12,"i","i"}};
        char birthday[8+1];
        int i,sum,first,second,lifenumber;
        int numbers[8];
        printf("生年月日を入力してください。\n");
        scanf("%s", birthday);
        swapnum(birthday,numbers);
        sum = 0;
        for(i=0;i<8;i++) {
                sum = sum + numbers[i];
        }
        if(sum == 11 || sum == 22) {
                lifenumber = sum;
        }
        first = sum /10;
        second = sum % 10;
        if(first == 0) {
                lifenumber = second;
        } else {
                lifenumber = first + second;
        }
        printf("%d",lifes[lifenumber].num);
        printf("%s",lifes[lifenumber].type);
        printf("%s",lifes[lifenumber].explain);
        printf("\n");


        return 0;
}
