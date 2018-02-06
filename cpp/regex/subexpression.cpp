//
// Created by 陈希明 on 18/1/26.
// 编译器:c++
//

#include <iostream>
#include <regex>

using namespace std;

int main()
{
    //构造一个用于查找模式的regex
    regex r("([[:alnum:]]+)?\\.(cpp|cc)?");
    //定义一个对象保存搜索结果
    smatch results;

    //(查找)字符序列
    string test_str = "a.cc b.cpp c.l .cpp ";

    /*
     * match对象(匹配类型的对象)有两个名为prefix和suffix的成员，
     * 分别表示输入序列中当前匹配之前和之后部分的ssub_match对象。
     * 一个ssub_match对象有两个名为str和length的成员，分别返回
     * 匹配的string和该string的大小
     */
    for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it;
        it != end_it; ++it) {
        cout << it->str() << ":" << endl;
        cout << "\t" << (*it)[1].matched << "," << (*it)[1].str() << endl;
        cout << "\t" << (*it)[2].matched << "," << (*it)[2].str() << endl << endl;
    }

    return EXIT_SUCCESS;
}