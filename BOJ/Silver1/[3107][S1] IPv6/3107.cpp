#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    char input[100];
    scanf("%s", input);

    string s = "";
    string answer = "";

    int idx = 0;
    int summarized = 0;
    int block = 0;

    // 블럭 개수 체크, 모자란 문자 채우기
    while(input[idx] != '\0')
    {
        if(input[idx] == ':')
        {
            string t = "";

            if(s.size() > 0)
            {
                if(s.size() == 3) t = "0";
                else if(s.size() == 2) t = "00";
                else if(s.size() == 1) t = "000";

                block++;
            }
            answer += t + s + ":";
            s = "";
            
            if(input[idx+1] == ':')
            {
                summarized = answer.size()-1;
                answer += ":";
                idx += 2;
                continue;
            }

            idx++;
            continue;
        }

        s += input[idx++];
    }

    if(input[idx-1] != ':')
    {
        string t;
        if(s.size() == 3) t = "0";
        else if(s.size() == 2) t = "00";
        else if(s.size() == 1) t = "000";

        answer += t + s;
        block++;
    }
    
    // 모자란 블록만큼 보완
    if(block < 8)
    {
        string front = answer.substr(0, summarized);
        string back = answer.substr(summarized+2);

        if(summarized != 0)
            front += ":";

        for(int i=8; i>block; i--)
        {
            front += "0000:";
        }

        answer = front += back;
    }
    
    printf("%s", answer.substr(0, 39).c_str());
}