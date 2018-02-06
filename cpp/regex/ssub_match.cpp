//
// Created by 陈希明 on 18/1/26.
// 编译器:c++
//

#include <iostream>
#include <regex>

using namespace std;

int main()
{
    /*
     * "拼写规则：i除非在c之后，否则必须在e之前"
     *
     * [^c]表明希望匹配任意不是'c'的字符，[^c]ei指出想匹配这种字符后接ei的字符串
     *
     * 为了与整个单词匹配，还需要一个正则表达式与这3个字母模式之前和之后的字母匹配
     * 模式[[:alpha:]]匹配任意字母。
     * 符号'+'表示希望"一个或多个"，符号'*'表示希望"零个或多个"
     */
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

    //构造一个用于查找模式的regex
    regex r(pattern);
    //定义一个对象保存搜索结果
    smatch results;

    //(查找)字符序列
    string test_str = "receipt freind theif receive";

    /*
     * match对象(匹配类型的对象)有两个名为prefix和suffix的成员，
     * 分别表示输入序列中当前匹配之前和之后部分的ssub_match对象。
     * 一个ssub_match对象有两个名为str和length的成员，分别返回
     * 匹配的string和该string的大小
     */
    for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it;
        it != end_it; ++it) {
        auto pos = it->prefix().length();               //前缀的大小
        pos = pos > 10 ? pos - 10 : 0;                  //最多需要10个字符
        cout << it->prefix().str().substr(pos)          //前缀的最后一部分
             << "\n\t\t>>> " << it->str() << "<<<\n"    //匹配的单词
             << it->suffix().str().substr(0,10)         //后缀的第一部分
             << endl;
    }

    return EXIT_SUCCESS;
}