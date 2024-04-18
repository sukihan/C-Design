#pragma once
#include <iostream>
#include <vector>
#include "Class.h"

// 欢迎界面
char welcome();

// 查找房间
int FindRoomInfo(std::vector<RoomInfo>& room , std::string name); 
int FindRoomInfo(std::vector<RoomInfo>& room);

// 订房
void SubScript(std::vector<RoomInfo>& room);

// 退房

void UnSubScript(std::vector<RoomInfo> room);

// 计算房费
int CalculatePrice(int roomType , int roomCount);

// 重置信息
void ResetInfo(RoomInfo& room);

//获取房间信息
std::vector<std::string> GetRoomInfo(RoomInfo& room);

// 获取订房日志
void GetSubLog(std::vector<RoomInfo>& room,int RoomNumber);

// 