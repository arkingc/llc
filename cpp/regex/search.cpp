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

    //regex_search只要找到一个匹配子串机会停止查找
    if(regex_search(test_str,results,r))
        cout << results.str() << endl;

    return EXIT_SUCCESS;
}