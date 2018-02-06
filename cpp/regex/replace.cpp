//
// Created by 陈希明 on 18/1/26.
// 编译器:c++
//

#include <iostream>
#include <regex>

using namespace std;
using namespace std::regex_constants; //标志选项format_no_copy

int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";

    regex r(phone);
    smatch m;

    string input = "cxm (908) 555-1800";
    string fmt = "$2.$5.$7";

    //输出：cxm 908.555.1800
    cout << regex_replace(input,r,fmt) << endl;
    // format_no_copy：只输出序列中匹配的部分
    // 输出：908.555.1800
    cout << regex_replace(input,r,fmt,format_no_copy) << endl;

    return EXIT_SUCCESS;
}