#include <iostream>
#include <string>
#include "Class.h"
#include "FuncOfRoom.h"

// 欢迎界面
char welcome()
{
    std::cout << "欢迎来到酒店管理系统!" << std::endl;
    std::cout << "1. 订房" << std::endl;
    std::cout << "2. 退房" << std::endl;
    std::cout << "3. 退出" << std::endl;
    std::cout << "请选择: ";
    char flag;
    std::cin >> flag;
    return flag;
}

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

// 计算房费
int CalculatePrice(int roomType , int roomCount)
{
    int roomPrice;
    switch (roomType)
    {
    case 1:
        roomPrice = 100;
        break;
    case 2:
        roomPrice = 200;
        break;
    case 3:
        roomPrice = 300;
        break;
    default:
        break;
    }
    return roomPrice * roomCount;
}

// 重置信息
void ResetInfo(RoomInfo& room)
{
    ResetHotelSubInfo(room);
    ResetPersonalInfo(room);
    ResetRoomInfo(room);
}

// 获取房间信息
std::vector<std::string> GetRoomInfo(RoomInfo& room)
{
    std::vector<std::string> RoomInfo;
    if (room.getSubStatus() == true)
    {
        RoomInfo.push_back( "姓名: " +room.getName());
        RoomInfo.push_back("身份证号: " + room.getPersonalId());
        RoomInfo.push_back("手机号: " + room.getPhoneNumber());
        RoomInfo.push_back("房间号: " + std::to_string(room.getRoomNumber()));
        RoomInfo.push_back("房间类型: " + std::to_string(room.getRoomType()));
        RoomInfo.push_back("入住时间: " + room.getSubStartTime());
        RoomInfo.push_back("退房时间: " + room.getSubEndTime());      
        RoomInfo.push_back("房间已定.");
    }else if (room.getSubStatus() == false)
    {
        RoomInfo.push_back("房间号: " + std::to_string(room.getRoomNumber()));
        RoomInfo.push_back("房间类型: " + std::to_string(room.getRoomType()));
        RoomInfo.push_back("房间未定.");
    }
    return RoomInfo;
}

// 获取订房日志
void GetSubLog(std::vector<RoomInfo>& room,int roomNumber)
{
    std::vector<std::string> RoomLog = GetRoomInfo(room[roomNumber]);
    for (int i = 0; i < RoomLog.size(); i++)
    {
        std::cout << RoomLog[i] << std::endl;
    }
}

// 订房
void SubScript(std::vector<RoomInfo>& room)
{
    int i = FindRoomInfo(room);
    if (i == -1)
    {
        return;
    }
    std::string name, personalId, phoneNumber;
    std::cout << "请输入姓名: ";
    std::cin >> name;
    std::cout << "请输入身份证号: ";
    std::cin >> personalId;
    std::cout << "请输入电话号码: ";
    std::cin >> phoneNumber; 
    room[i].InitPersonalInfo(name , personalId , phoneNumber);
    int roomNumber = i, roomType, roomPrice, roomCount, totalPrice;
    std::cout << "请输入要订房间类型和数量: (1.单人间: 100元/晚 2.双人间: 200元/晚 3.套房: 300元/晚)" << std::endl;
    std::cin >> roomType >> roomCount;
    totalPrice = CalculatePrice(roomType , roomCount);
    room[i].InitHotelSubInfo(roomNumber , roomType , roomCount , totalPrice);
    std::string SubStartTime, SubEndTime;
    std::cout << "请输入订房时间:";
    std::cin >> SubStartTime ;
    std::cout << "至";
    std::cin >> SubEndTime;
    room[i].InitRoomStatus(SubStartTime , SubEndTime);
    char flag;
    std::cout << "是否订房? (Y/N)";
    std::cin >> flag;
    if (flag == 'Y'){
        std::cout << "订房成功!" << std::endl;
        std::cout << "房间号:" << room[i].getRoomNumber() << std::endl;
        std::cout << "订房日志:" << std::endl;
        
    }
    else if(flag == 'N'){
        ResetInfo(room[i]);
        std::cout << "订房取消!" << std::endl;
    }
}

// 退房