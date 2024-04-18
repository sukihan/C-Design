#pragma once
#include <iostream>
#include <cmath>

/*
客房管理系统:
    1. 个人信息类
    2. 订房信息类
    3. 房间信息类
*/


// 个人信息类
class PersonalInfo
{
public:
    PersonalInfo() : Name("NULL") , PersonalId("NULL") , PhoneNumber("NULL"){};
    void InitPersonalInfo(std::string name , std::string personalId , std::string phoneNumber); // 设置个人信息
    void SetPersonalInfo(int Info);
    std::string getName() const {return Name;};
    std::string getPersonalId() const {return PersonalId;};
    std::string getPhoneNumber() const {return PhoneNumber;};
    friend void ResetPersonalInfo(PersonalInfo& personal); // 重置个人信息
private:
    std::string Name;
    std::string PersonalId;
    std::string PhoneNumber;
};


// 订房信息类
class HotelSubscription : public PersonalInfo
{
public:
    HotelSubscription() : PersonalInfo(),roomNumber(0),roomType(0),roomCount(0){}
    ~HotelSubscription(){}
    void InitHotelSubInfo(int roomNumber , int roomType , int roomCount , int totalPrice); // 订房信息
    void SetHotelSubInfo(int Info);
    friend void ResetHotelSubInfo(HotelSubscription& hotel); // 重置订房信息
    int getRoomNumber() const {return roomNumber;};
    int getRoomType() const {return roomType;};
    int getRoomCount() const {return roomCount;};
    int getTotalPrice() const {return totalPrice;};
private:
    int roomNumber;
    int roomType;
    int roomCount;
    int totalPrice;
};


// 房间信息类
class RoomInfo : public HotelSubscription
{
public:
    RoomInfo() : HotelSubscription(),SubStartTime(0),SubEndTime(0),CleanStatus(true),SubStatus(false){}
    ~RoomInfo(){}
    void InitRoomStatus(std::string subStartTime , std::string subEndTime); // 初始化房间信息
    void SetRoomStatus(int status); // 设置房间信息
    void GetRoomOtherStatus(int status);
    void SetRoomOtherStatus(int status);
    bool getCleanStatus() const {return CleanStatus;};
    bool getSubStatus() const {return SubStatus;};
    std::string getSubStartTime() const {return SubStartTime;};
    std::string getSubEndTime() const {return SubEndTime;};
    friend void ResetRoomInfo(RoomInfo& room); // 重置房间信息
private:
    std::string SubStartTime;
    std::string SubEndTime;
    bool CleanStatus;
    bool SubStatus;
};
