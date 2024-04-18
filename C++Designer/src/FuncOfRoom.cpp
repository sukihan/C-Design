#include <iostream>
#include <string>
#include "Class.h"
#include "FuncOfRoom.h"

// 查找房间
int FindRoomInfo(std::vector<RoomInfo>& room, std::string name)
{
    for (int i = 0; i < room.size(); i++)
    {
        if (room[i].getName() == name)
        {
            return i;
        }
    }
    std::cout << "未找到该房间!" << std::endl;
    return -1;
}

int FindRoomInfo(std::vector<RoomInfo>& room)
{
    for (int i = 0; i < room.size(); i++)
    {
        if (room[i].getSubStatus() == false)
        {
            return i;
        }
    }
    std::cout << "房间已订完！" << std::endl;
    return -1;
}

// 订房
RoomInfo SubScript(std::vector<RoomInfo>& room)
{
    RoomInfo newRoom;
    int i = FindRoomInfo(room);
    if (i != -1){
        std::string name;
        std::cout << "请输入您的姓名：";
        std::cin >> name;
        std::string personalId;
        std::cout << "请输入您的身份证号：";
        std::cin >> personalId;
        std::string phoneNumber;
        std::cout << "请输入您的电话号码：";
        std::cin >> phoneNumber;
        newRoom.InitPersonalInfo(name , personalId , phoneNumber);
    }
}