#pragma once
#include <iostream>
#include <vector>
#include "Class.h"

// 查找房间
int FindRoomInfo(std::vector<RoomInfo>& room , std::string name); 
int FindRoomInfo(std::vector<RoomInfo>& room);

// 订房
RoomInfo SubScript(std::vector<RoomInfo>& room);

// 退房

void UnSubScript(std::vector<RoomInfo> room);