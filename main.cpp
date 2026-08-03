#include"book.h"
int main()
{
    SetConsoleOutputCP(CP_ACP);
    SetConsoleCP(CP_ACP);
    loadbooks();
    int val;
    printf("============================\n");
    printf("|                          |\n");
    printf("|                          |\n");
    printf("| 欢迎使用图书登记管理系统 |\n");
    printf("|                          |\n");
    printf("|                          |\n");
    printf("============================\n");
    while(1)
    {
        printf("菜单:\n");
        printf("1.录入图书信息 2.查找图书 3.修改图书信息 4.删除图书 5.统计信息\n");
        printf("6.查找出版社信息 7.查找作者信息 8.查找出版时间 9.退出\n");
        printf("请选择功能:");
        while(!(cin>>val))
        {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "请输入数字选项！重新选择：\n";
        }
        switch(val)
        {
            case 1:
                printf("您选择的功能是:录入图书信息\n");
                addbooks();
                break;
            case 2:
                printf("您选择的功能是:查找图书\n");
                findbooks();
                break;
            case 3:
                printf("您选择的功能是:修改图书信息\n");
                xiugaibooks();
                break;
            case 4:
                printf("您选择的功能是:删除图书\n");
                deletebooks();
                break;
            case 5:
                printf("您选择的功能是:统计信息\n");
                tongji();
                break;
            case 6:
                printf("您选择的功能是:查找出版社信息\n");
                presssearch();
                break;
            case 7:
                printf("您选择的功能是:查找作者信息\n");
                authorsearch();
                break;
            case 8:
                printf("您选择的功能是:查找出版时间\n");
                datesearch();
                break;
            case 9:
                savebooks();
                printf("数据保存成功!\n");
                break;
        default:
            printf("无此功能，请重新选择\n");
        }
        if(val==9)
            break;
    }
    printf("感谢您的使用!\n");
    return 0;
}
