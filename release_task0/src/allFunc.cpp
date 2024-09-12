#include "allFunc.h"
#include "widget.h"
#include <iostream>
#include <fstream>
#include <sstream>

void encodeFunc(Widget &my, std::string input, std::string output, std::string cstr) {
    //构建参考字符数组
    char consult[95];
    for(int i = 0; i <= 94; i++)
        consult[i] = static_cast<char>(i + 32);

    unsigned int idx = 0;  //循环变量。用于确认编码串

    std::ifstream file(input);
    std::stringstream buf;

    if(!file) {my.errorType = 1;  return; }

    std::ofstream opfile(output);
    char ip;
    //读取字符：
    while (file.get(ip)){
        //特殊处理换行符
        if (ip == '\n'){
            opfile.put('\n');
            continue;  }
        int y = static_cast<int>(cstr[idx]) - 32;
        int x = static_cast<int>(ip) - 32;

        if(x >= 0 && x <= 94 - y)
            opfile.put(consult[x + y]);
        else if(x > 94 - y && x <= 94 )
            opfile.put(consult[x - 95 + y]);


        if(idx < cstr.length() - 1)
            idx ++;
        else
            idx = 0;

    }
    file.close();
    opfile.close();
}

//直接改参数即可
void decodeFunc(Widget &my, std::string input, std::string output, std::string cstr) {
    //构建参考字符数组
    char consult[95];
    for(int i = 0; i <= 94; i++)
        consult[i] = static_cast<char>(i + 32);

    unsigned int idx = 0;  //循环变量。用于确认编码串

    std::ifstream file(input);
    std::stringstream buf;

    if(!file) {my.errorType = 1;  return; }

    std::ofstream opfile(output);
    char ip;
    //读取字符：
    while (file.get(ip)){
        //特殊处理换行符
        if (ip == '\n'){
            opfile.put('\n');
            continue;  }
        int y = static_cast<int>(cstr[idx]) - 32;
        int k = static_cast<int>(ip) - 32;

        if(k >= y  && k <= 94)
            opfile.put(consult[k - y]);
        else if(k > -1 && k <= y - 1 )
            opfile.put(consult[k + 95 - y]);


        if(idx < cstr.length() - 1)
            idx ++;
        else
            idx = 0;

    }
    file.close();
    opfile.close();
}
