/* File Name: main.cpp
* Author: fangtest
* Created Time: Wed 03 Mar 2021 03:53:32 PM CST
*/

// Author: bob
// Created Time: Wed 03 Mar 2021 03:53:32 PM CST

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include "test.pb.h"
using namespace std;

int main(){
    pt::rsp_login rsp{};
    rsp.set_ret(pt::rsp_login_RET_SUCCESS);
    auto user_info = rsp.mutable_user_info();
    user_info->set_nickname("bob");
    user_info->set_icon("2143124EDF31");
    user_info->set_coin(3000);
    user_info->set_location("shanghai");

    for(int i = 0; i < 5; ++i)
    {
        auto record = rsp.add_record();
        record->set_time("2021-03-03 16:50");
        record->set_kill(i * 4);
        record->set_dead(i * 2);
        record->set_assist(i * 5);
    }

    string buff{};
    rsp.SerializeToString(&buff);
    pt::rsp_login rsp2{};
    if(!rsp2.ParseFromString(buff))
    {
        cout << "parse error!" << endl;
    }
    
    auto tmp_user_info = rsp2.user_info();
    cout << "set_nickname:" << tmp_user_info.nickname() << endl;
    cout << "coin:" << tmp_user_info.coin() << endl;

    for(int i = 0; i < rsp2.record_size(); i++)
    {
        auto tmp_record = rsp2.record(i);
        cout << "time:" << tmp_record.time() << "kill:" << tmp_record.kill() << endl;
    }
    return 0;
}
