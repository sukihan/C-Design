#include "Class.h"
#include "FuncOfRoom.h"

using namespace std;

// 初始化个人信息
void PersonalInfo::InitPersonalInfo(std::string name , std::string personalId , std::string phoneNumber)
{
    if (phoneNumber.size() != 11)
    {
        cout << "错误的电话号码!" << endl;
        return;
    }
    if (name == "NULL" || personalId == "NULL" || phoneNumber == "NULL")
    {
        cout << "个人信息不能为空!" << endl;
        return;
    }
    this -> Name = name;
    this -> PersonalId = personalId;
    this -> PhoneNumber = phoneNumber;
    cout << "个人信息初始化成功!" << endl;
}


// 设置个人信息
void PersonalInfo::SetPersonalInfo(int Info)
{
    if (Info == 1)
    {
        cout << "重新输入姓名: " << endl;
        cin >> this -> Name;
        string OldName = this -> Name;
        if (Name == "NULL")
        {
            cout << "姓名不能为空!" << endl;
            return;
        }
        else if (Name == OldName)
        {
            cout << "姓名不应与旧的一致！" << endl;
            return;
        }
    }
    else if (Info == 2)
    {
        cout << "重新输入身份证号: " << endl;
        cin >> this -> PersonalId;
        string OldPersonalId = this -> PersonalId;
        if (PersonalId == "NULL")
        {
            cout << "身份证号不能为空!" << endl;
            return;
        }
        else if (PersonalId == OldPersonalId)
        {
            cout << "身份证号不应与旧的一致！" << endl;
            return;
        }
    }
    else if (Info == 3)
    {
        cout << "重新输入电话号码: " << endl;
        string OldPhoneNumber = this -> PhoneNumber;
        cin >> this -> PhoneNumber;
        if (PhoneNumber.size() != 11)
        {
            cout << "错误的电话号码!" << endl;
            this -> PhoneNumber = OldPhoneNumber;
            return;
        }else if (PhoneNumber == OldPhoneNumber)
        {
            cout << "电话号码不应与旧的一致！" << endl;
            return;
        }
    }
    else {
        cout << "无效索引" << endl;
    }
}

// 初始化订房信息
void HotelSubscription::InitHotelSubInfo(int roomNumber , int roomType , int roomCount , int totalPrice)
{
    if (roomNumber == 0 || roomType == 0 || roomCount == 0 || totalPrice == 0)
    {
        cout << "订房信息不能为空!" << endl;
        return;
    }
    this -> roomNumber = roomNumber;
    this -> roomType = roomType;
    this -> roomCount = roomCount;
    this -> totalPrice = totalPrice;
    cout << "订房信息初始化成功!" << endl;
}

// 设置订房信息

void HotelSubscription::SetHotelSubInfo(int Info)
{
    if (Info == 1)
    {
        cout << "重新输入房间号: " << endl;
        cin >> this -> roomNumber;
        int OldRoomNumber = this -> roomNumber;
        if (roomNumber == 0)
        {
            cout << "房间号不能为空!" << endl;
            return;
        }
        else if (roomNumber == OldRoomNumber)
        {
            cout << "房间号不应与旧的一致！" << endl;
            return;
        }
    }
    else if (Info == 2)
    {
        cout << "重新输入房间类型: " << endl;
        cin >> this -> roomType;
        int OldRoomType = this -> roomType;
        if (roomType == 0)
        {
            cout << "房间类型不能为空!" << endl;
            return;
        }
        else if (roomType == OldRoomType)
        {
            cout << "房间类型不应与旧的一致！" << endl;
            return;
        }
    }
    else if (Info == 3)
    {
        cout << "重新输入房间数量: " << endl;
        cin >> this -> roomCount;
        int OldRoomCount = this -> roomCount;
        if (roomCount == 0)
        {
            cout << "房间数量不能为空!" << endl;
            return;
        }
        else if (roomCount == OldRoomCount)
        {
            cout << "房间数量不应与旧的一致！" << endl;
            return;
        }
        this->totalPrice = CalculatePrice(roomType , roomCount);
    }
    else if (Info == 5)
    {
        cout << "重新输入总价: " << endl;
        cin >> this -> totalPrice;
        int OldTotalPrice = this -> totalPrice;
        if (totalPrice == 0)
        {
            cout << "总价不能为空!" << endl;
            return;
        }
        else if (totalPrice == OldTotalPrice)
        {
            cout << "总价不应与旧的一致！" << endl;
            return;
        }
    }
}

// 初始化房间信息
void RoomInfo::InitRoomStatus(std::string subStartTime , std::string subEndTime)
{
    if (subStartTime == "NULL" || subEndTime == "NULL")
    {
        cout << "房间信息不能为空!" << endl;
        return;
    }
    this -> SubStartTime = subStartTime;
    this -> SubEndTime = subEndTime;
    cout << "房间信息初始化成功!" << endl;

}

// 设置房间信息
void RoomInfo::SetRoomStatus(int status)
{
    if (status == 1){
        cout << "重新输入入住时间: " << endl;
        cin >> this -> SubStartTime;
        string OldSubStartTime = this -> SubStartTime;
        if (SubStartTime == "NULL")
        {
            cout << "入住时间不能为空!" << endl;
            return;
        }
        else if (SubStartTime == OldSubStartTime)
        {
            cout << "入住时间不应与旧的一致！" << endl;
            return;
        }
    }
    else if (status == 2)
    {
        cout << "重新输入退房时间: " << endl;
        cin >> this -> SubEndTime;
        string OldSubEndTime = this -> SubEndTime;
        if (SubEndTime == "NULL")
        {
            cout << "退房时间不能为空!" << endl;
            return;
        }
        else if (SubEndTime == OldSubEndTime)
        {
            cout << "退房时间不应与旧的一致！" << endl;
            return;
        }
    }
}

// 获取房间其他信息
void RoomInfo::GetRoomOtherStatus(int status)
{
    if(status == 1){
        cout << "打扫状态 :" << endl;
        if (CleanStatus == true)
        {
            cout << "已打扫" << endl;
        }
        else
        {
            cout << "未打扫" << endl;
        }
    }else if(status == 2){
        cout << "订房状态 :" << endl;
        if (SubStatus == true)
        {
            cout << "已订房" << endl;
        }
        else
        {
            cout << "未订房" << endl;
        }
    }
}

// 设置房间其他信息
void RoomInfo::SetRoomOtherStatus(int status)
{
    if (status == 1)
    {
        cout << "重新输入打扫状态: " << endl;
        cin >> CleanStatus;
    }
    else if (status == 2)
    {
        cout << "重新输入订房状态: " << endl;
        cin >> SubStatus;
    }
}

// 重置订房信息
void ResetHotelSubInfo(HotelSubscription& hotel)
{
    hotel.roomNumber = 0;
    hotel.roomType = 0;
    hotel.roomCount = 0;
    hotel.totalPrice = 0;
}

// 重置房间信息
void ResetRoomInfo(RoomInfo& room)
{
    room.SubStartTime = "NULL";
    room.SubEndTime = "NULL";
    room.CleanStatus = true;
    room.SubStatus = false;
}

// 重置个人信息
void ResetPersonalInfo(PersonalInfo& personal)
{
    personal.Name = "NULL";
    personal.PersonalId = "NULL";
    personal.PhoneNumber = "NULL";
}