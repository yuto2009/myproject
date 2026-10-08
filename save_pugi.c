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

int firstnum1(int numbers[]) {
        int sum=0,first,second;
        sum = numbers[4] + numbers[5] + numbers[6] + numbers[7];
        if(sum == 11 || sum == 22) {
                return sum;
        } else {
                first = sum / 10;
                second = sum % 10;
                sum = first + second;
                return sum;
        }
};

int secondnum1(int numbers[]) {
        int sum=0,first,second;
        sum = numbers[0] + numbers[1] + numbers[2] + numbers[3] + numbers[6] + numbers[7];
        first = sum / 10;
        second = sum % 10;
        sum = first + second;
        return sum;
}

int thirdnum1(int first, int second) {
        int sum =0;
        sum = first + second;
        return sum;
}

int main(void) {
        struct people lifes[] ={{0,"",""},
                                {1,"a","a"},
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
        int i,sum,first,second,lifenumber,firstnum,secondnum,thirdnum;
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
        } else {
                first = sum /10;
                second = sum % 10;
                if(first == 0) {
                        lifenumber = second;
                } else {
                        lifenumber = first + second;
                }
        }
        firstnum = firstnum1(numbers);
        secondnum = secondnum1(numbers);
        thirdnum = thirdnum1(firstnum,secondnum);
        printf("%d",lifes[lifenumber-1].num);
        printf("%s",lifes[lifenumber-1].type);
        printf("%s\n",lifes[lifenumber-1].explain);
        printf("%d\n",firstnum);
        printf("%d\n",secondnum);
        printf("%d",thirdnum);
        printf("\n");

        return 0;
}
