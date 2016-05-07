//
//  main.cpp
//  ps2016
//
//  Created by 강태진 on 2016. 5. 7..
//  Copyright © 2016년 강태진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>
#include <list>
#include <queue>
#include <stack>

using namespace std;

char tt;
char buf[1000010];
string ss;

void work()
{
    scanf("%s",buf);

    ss = buf;
    deque<char> st;
    stack<char> tempst;
    
    for(char &ch : ss)
    {
        if(isalnum(ch))
        {
            st.push_back(ch);
        }
        else if(ch == '<')
        {
            if(st.empty())continue;
            
            tt = st.back();
            st.pop_back();
            tempst.push(tt);
        }
        else if(ch == '>')
        {
            if(tempst.empty()) continue;
            else;
            tt = tempst.top();
            tempst.pop();
            st.push_back(tt);
        }
        else
        {
            if(st.empty()) continue;
            st.pop_back();
        }
    }
    while(!tempst.empty())
    {
        tt = tempst.top();
        tempst.pop();
        st.push_back(tt);
    }
    
    while(!st.empty())
    {
        printf("%c",st.front());
        st.pop_front();
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        work();
    }
    return 0;
}

/*
 * else 는 가까운 if에 붙는다.
 * 문자 입력 조심
 * 마지막 버퍼비워줘야함!!!!
 *
 */
