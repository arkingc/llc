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
     * 后接'?'的组件是可选的，因此即使模式匹配成功，后接'?'的子表达式也不一定是匹配的
     * 因此，对于后接'?'的子表达式，如果没有匹配，则matched成员为false;
     */
    for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it;
        it != end_it; ++it) {
        cout << it->str() << ":" << endl;
        cout << "\t" << (*it)[1].matched << "," << (*it)[1].str() << endl;
        cout << "\t" << (*it)[2].matched << "," << (*it)[2].str() << endl << endl;
    }

    return EXIT_SUCCESS;
}
