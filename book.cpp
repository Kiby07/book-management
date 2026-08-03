#include"book.h"
vector<bookinf> books;
//判断输入形式，防止崩溃的辅助函数
bool istext(const string &s)
{
    for (char ch : s)    //检查s里的每个字符
    {
        if (isdigit(ch))      //判断是否为数字的函数
            return false;
        if (!isalpha(ch) && !(unsigned char)ch > 127 && ch != ' ')  //判断是否是英文、汉字和空格
            return false;
    }
    return true;
}

bool isISBN(const string &s)
{
    for (char ch : s)
    {
        if (!isdigit(ch) && ch != '-')  //只能是数字和“-”符号
            return false;
    }
    return s.size() >= 5 && s.size() <= 15;  //长度要求
}

bool isdate(const string &s)
{
    if (s.size() != 7)  //先判断长度是否合规
        return false;
    if (s[4] != '-')
        return false;
    for (int i = 0; i < 7; ++i)
    {
        if (i == 4) continue;  //跳过对“-”是否为数字的判断
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

bool isprice(double price)
{
    return price > 0;  //排除负数可能
}

bool issearch(const string &s)  //在模糊查找中防止输入格式不对
{
    for (char ch : s)
    {
        if (isalpha(ch) || (unsigned char)ch > 127 || ch == '+' || ch == ' ')   //只允许字母、中文、空格、+ 号
        {
            continue;
        }
        return false;
    }
    return true;
}

//有功能的函数
void loadbooks()
{
    ifstream fin(FILENAME);  //读入文件里的数据
    if(!fin)
        {
            return ;
        }
    bookinf a;   //借用变量录入为bookinf
    while(fin>>a.ISBN>>a.name>>a.author>>a.press>>a.date>>a.price)
        books.push_back(a);   //加入到vector数组
    fin.close();
}

void savebooks()
{
    ofstream fout(FILENAME);  //写入文件
    for(int i = 0; i < books.size(); i++)
    {
        bookinf b = books[i];
        fout << b.ISBN << " " << b.name << " " << b.author << " "
             << b.press << " " << b.date << " " << b.price << endl;
    }
    fout.close();
}

void addbooks()
{
    bookinf a;
    printf("请输入5-15位的ISBN号：");
    cin>>a.ISBN;
    while(!isISBN(a.ISBN))  //判断是否只有数字和“-”符号
    {
        printf("不能包含文字且长度为5-15位，请重新输入ISBN：");
        cin>>a.ISBN;
    }

    printf("请输入书名：");
    cin >> a.name;
    while(!istext(a.name))  //判断是否只有汉字和英文字母和空格
    {
        printf("不能包含符号和数字，请重新输入书名：");
        cin>>a.name;
    }

    printf("请输入作者：");
    cin >> a.author;
    while(!istext(a.author))   //判断是否只有汉字和英文字母和空格
    {
        printf("不能包含符号和数字，请重新输入作者：");
        cin>>a.author;
    }

    printf("请输入出版社：");
    cin >> a.press;
    while(!istext(a.press))  //判断是否只有汉字和英文字母和空格
    {
        printf("不能包含符号和数字，请重新输入出版社：");
        cin>>a.press;
    }

    printf("请输入出版日期（如2020-03）：");
    cin >> a.date;
    while(!isdate(a.date))  //判断日期格式
    {
        printf("日期格式错误，请按YYYY-MM格式重新输入：");
        cin>>a.date;
    }

    printf("请输入价格：");
    cin >> a.price;
    while(!isprice(a.price))  //判断是否为负数
    {
        printf("不能为负数，请重新输入价格：");
        cin>>a.price;
    }

    books.push_back(a);
    printf("图书录入成功！\n");
}

void putbooks(bookinf b)  //输出展示图书内容
{
    printf("----------------------------\n");
    printf("ISBN：%s\n", b.ISBN.c_str());
    wprintf(L"书名：《%s》\n", b.name.c_str());
    printf("作者：%s\n", b.author.c_str());
    printf("出版社：%s\n", b.press.c_str());
    printf("出版日期：%s\n", b.date.c_str());
    printf("价格：%.2lf 元\n", b.price);
    printf("----------------------------\n");
}

void xiugaibooks()
{
    string temp;
    printf("请输入您需要修改的图书的5-15位ISNB号或图书名称:\n");
    cin>>temp;
    while(!(isISBN(temp))&&!(istext(temp)))
    {
        printf("输入格式错误，请重新输入：\n");
        cin>>temp;
    }
    for(int i=0;i<books.size();i++)
    {
        if(books[i].ISBN==temp||books[i].name==temp)
        {
           printf("请输入5-15位的ISBN号：");
           cin>>books[i].ISBN;
           while(!isISBN(books[i].ISBN))  //判断是否只有数字和“-”符号
           {
            printf("不能包含文字且长度为5-15位，请重新输入ISBN：");
            cin>>books[i].ISBN;
           }

           printf("请输入书名：");
           cin >> books[i].name;
           while(!istext(books[i].name))  //判断是否只有汉字和英文字母和空格
           {
            printf("不能包含符号和数字，请重新输入书名：");
            cin>>books[i].name;
           }

           printf("请输入作者：");
           cin >> books[i].author;
           while(!istext(books[i].author))   //判断是否只有汉字和英文字母和空格
          {
           printf("不能包含符号和数字，请重新输入作者：");
           cin>>books[i].author;
           }

          printf("请输入出版社：");
          cin >> books[i].press;
          while(!istext(books[i].press))  //判断是否只有汉字和英文字母和空格
          {
           printf("不能包含符号和数字，请重新输入出版社：");
           cin>>books[i].press;
           }

          printf("请输入出版日期（如2020-03）：");
          cin >> books[i].date;
          while(!isdate(books[i].date))  //判断日期格式
         {
           printf("日期格式或输入内容错误，请按YYYY-MM格式重新输入：");
           cin>>books[i].date;
          }

         printf("请输入价格：");
        while(!(cin >> books[i].price)&&!isprice(books[i].price))  //判断是否为负数,防止不是数字
        {
            cin.clear();
            cin.ignore(1024, '\n');
            printf("不能为负数且必须是数字，请重新输入价格：");
        }
        printf("图书信息修改成功！\n");
        return ;
        }
    }
    printf("查找失败!\n");
    int k;
    printf("重新修改请选1，退出请选2:\n");
    while (!(cin >> k))  //防止输入崩溃
    {
        cin.clear();    //恢复cin的功能
        cin.ignore(1024, '\n');   //清除垃圾数据
        printf("请输入数字重新选择：");
    }
    if(k==1)
        xiugaibooks();
    else if(k==2)
        return ;
    else
    {
        printf("选择无效，已退出修改!\n");
        return ;
    }
}

void deletebooks()
{
    string temp;
    printf("请输入您需要删除的图书的5-15位ISNB号或图书名称:\n");
    cin>>temp;
    while(!(isISBN(temp))&&!(istext(temp)))
    {
        printf("输入格式错误，请重新输入：\n");
        cin>>temp;
    }
    for(int i=0;i<books.size();i++)
    {
        if(books[i].ISBN==temp||books[i].name==temp)
        {
            books.erase(books.begin()+i);
            printf("删除成功!\n");
            return ;
        }
    }
    printf("查找失败!\n");
    int k;
    printf("重新删除请选1，退出请选2:\n");
    while (!(cin >> k))  //防止输入崩溃
    {
        cin.clear();    //恢复cin的功能
        cin.ignore(1024, '\n');   //清除垃圾数据
        printf("请输入数字重新选择：");
    }
    if(k==1)
        deletebooks();
    else if(k==2)
        return ;
    else
    {
        printf("选择无效，已退出删除!\n");
        return ;
    }
}

void findbooks()
{
    int opt;
    printf("请选择需要的查询方式:\n");
    printf("1.输入5-15位ISBN号或书名精确查找\n2.输入组合或图书包含的字模糊查找\n");
    while (!(cin >> opt))  //防止输入崩溃
    {
        cin.clear();    //恢复cin的功能
        cin.ignore(1024, '\n');   //清除垃圾数据
        printf("请输入数字重新选择：\n");
    }
    switch(opt)
    {
    case 1:
        exactsearch();
        break;
    case 2:
        mouhusearch();
        break;
    default:
        printf("选择失败，请重新选择!\n");
    }
}

void exactsearch()
{
    string temp;
    printf("请输入您需要查找的图书的5-15位ISNB号或图书名称:\n");
    cin>>temp;
    while(!(isISBN(temp))&&!(istext(temp)))
    {
        printf("输入格式错误，请重新输入：\n");
        cin>>temp;
    }
    int flag=0;
    for(int i=0;i<books.size();i++)
    {
        if(books[i].ISBN==temp||books[i].name==temp)
        {
            flag=1;
            printf("已找到图书!\n");
            putbooks(books[i]);
            return ;
        }
    }
    if(!flag)
    {
        printf("未找到图书!\n");
        int k;
        printf("重新精确查找请选1，返回查找页面请选2，退出查找请选3\n");
        while (!(cin >> k))  //防止输入崩溃
        {
           cin.clear();    //恢复cin的功能
           cin.ignore(1024, '\n');   //清除垃圾数据
           printf("请输入数字重新选择：");
        }
        if(k==1)
            exactsearch();
        else if(k==2)
            findbooks();
        else if(k==3)
            return ;
        else
            {
                printf("选择无效，已退出查找!\n");
                return ;
            }
    }
}

void mouhusearch()
{
    string temp;
    printf("请输入关键词，用+连接(例：设计+教程):\n");
    cin >> temp;
    while(!issearch(temp))  //防止输入格式不正确导致崩溃
    {
        printf("请按格式正确输入：\n");
        cin>>temp;
    }
    vector<string> key;  //建立vector把各个部分分开存储便于查找
    size_t pos;  //用表示下标的专用数据类型
    while((pos = temp.find("+")) != string::npos)  //“string::npos”相当于一个很大的数字，可以被pos的数据类型识别
        {
              key.push_back(temp.substr(0, pos));  //用substr取一部分的字符串
              temp = temp.substr(pos + 1);
        }
    key.push_back(temp);  //将剩余部分字符串加入到数组
    int flag= 0;  //假设找不到这样的图书
    for(int i = 0; i < books.size(); i++)
    {
        int ok = 1;  //假设可以找到和字符片段匹配的图书名
        for(int j = 0; j < key.size(); j++)
        {
            if(books[i].name.find(key[j]) == string::npos)  //找和数组中的字符串片段匹配的图书
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            putbooks(books[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("未找到图书!\n");
        int k;
        printf("重新模糊查找请选1，返回查找页面请选2，退出查找请选3\n");
        while (!(cin >> k))  //防止输入崩溃
        {
           cin.clear();    //恢复cin的功能
           cin.ignore(1024, '\n');   //清除垃圾数据
           printf("请输入数字重新选择：");
        }
        if(k==1)
            mouhusearch();
        else if(k==2)
            findbooks();
        else if(k==3)
            return ;
        else
            {
                printf("选择无效，已退出查找!\n");
                return ;
            }
    }
    else
        printf("找到以上有关图书!\n");
}

void tongji()
{
    int tot=books.size();
    if(!tot)
    {
        printf("暂未拥有图书数据\n");
        return ;
    }
    double sumprice = 0;
    double maxprice = books[0].price;
    double minprice = books[0].price;
    string maxbook=books[0].name;
    string minbook=books[0].name;
    for(int i = 0; i < tot; i++)
    {
        sumprice += books[i].price;
        if(books[i].price > maxprice)   //寻找最高价格
            {
                maxprice = books[i].price;
                maxbook=books[i].name;
            }
        if(books[i].price < minprice)   //寻找最低价格
            {
                minprice = books[i].price;
                minbook=books[i].name;
            }
    }
    printf("统计图书数据如下:\n");
    printf("总图书数目为：%d本\n",tot);
    printf("图书总价:%.2lf元\n",sumprice);
    printf("价格最高的图书：");
    wprintf(L"《%s》", maxbook.c_str());  //宽输出流
    printf("\n");
    printf("价格最低的图书：");
    wprintf(L"《%s》", minbook.c_str());
    printf("\n");
    printf("图书平均价格:%.2lf元\n",sumprice/tot);
    return ;
}

void presssearch()
{
    string temp;
    int flag=0;  //假设查找不到出版社
    printf("请输入需要查询的出版社:\n");
    cin >> temp;
    while(!istext(temp))  //判断是否只有汉字和英文字母和空格
    {
        printf("不能包含符号和数字，请重新输入出版社：");
        cin>>temp;
    }
    for(int i=0;i<books.size();i++)
    {
        if(books[i].press==temp)
        {
            flag=1;
            putbooks(books[i]);
        }
    }
    if(!flag)
    {
        printf("未查询到该出版社信息!\n");
        int k;
        printf("重新查询请选1，退出查询请选2\n");
         while (!(cin >> k))  //防止输入崩溃
        {
           cin.clear();    //恢复cin的功能
           cin.ignore(1024, '\n');   //清除垃圾数据
           printf("请输入数字重新选择：");
        }
        if(k==1)
            presssearch();
        else if(k==2)
            return ;
        else
            {
                printf("选择无效，已退出查询!\n");
                return ;
            }
    }
    else
        printf("找到以上有关图书!\n");
}

void authorsearch()
{
    string temp;
    int flag=0;
    printf("请输入需要查询的作者:\n");
    cin>>temp;
     while(!istext(temp))  //判断是否只有汉字和英文字母和空格
    {
        printf("不能包含符号和数字，请重新输入作者：");
        cin>>temp;
    }
    for(int i=0;i<books.size();i++)
    {
        if(books[i].author==temp)
        {
            flag=1;
            putbooks(books[i]);
        }
    }
    if(!flag)
    {
        printf("未查询到该作者信息!\n");
        int k;
        printf("重新查询请选1，退出查询请选2\n");
        while (!(cin >> k))  //防止输入崩溃
        {
           cin.clear();    //恢复cin的功能
           cin.ignore(1024, '\n');   //清除垃圾数据
           printf("请输入数字重新选择：");
        }
        if(k==1)
           authorsearch();
        else if(k==2)
            return ;
        else
            {
                printf("选择无效，已退出查询!\n");
                return ;
            }
    }
    else
        printf("找到以上有关图书!\n");
}

void datesearch()
{
    string temp;
    printf("请输入需要查找的出版时间:(例:2021-07)\n");
    while (!(cin >> temp) || !isdate(temp))  //防止日期输入形式错误
    {
        cin.clear();
        cin.ignore(1024, '\n');
        printf("日期格式或输入内容错误，请按YYYY-MM格式重新输入：");
    }
    int flag=0;  //标记假设没有找到匹配的图书
    for(int i=0;i<books.size();i++)
    {
        if(books[i].date.find(temp)!=string::npos)
        {
            flag=1;  //找到时更改标记
            putbooks(books[i]);
        }
    }
    if(!flag)
    {
        printf("未找到图书!\n");
        int k;
        printf("重新查询请选1，退出查询请选2\n");
        while (!(cin >> k))  //防止输入崩溃
        {
           cin.clear();    //恢复cin的功能
           cin.ignore(1024, '\n');   //清除垃圾数据
           printf("请输入数字重新选择：");
        }
        if(k==1)
           datesearch();
        else if(k==2)
            return ;
        else
            {
                printf("选择无效，已退出查询!\n");
                return ;
            }
    }
    else
        printf("找到以上有关图书!\n");
}
