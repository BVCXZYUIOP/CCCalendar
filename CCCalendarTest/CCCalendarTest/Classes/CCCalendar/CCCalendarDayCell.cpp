//
//  CCCalendarDayCell.cpp
//  CCCalendarTest
//
//  Created by 陶 然景 on 13-3-18.
//
//

#include "CCCalendarDayCell.h"

CCCalendarDayCell::CCCalendarDayCell()
:m_uYear(0)
,m_uMonth(0)
,m_uDay(0)
{
    
}

CCCalendarDayCell::~CCCalendarDayCell()
{
    
}

CCCalendarDayCell *CCCalendarDayCell::create(unsigned int year, unsigned int month, unsigned int day)
{
    CCCalendarDayCell *cell = CCCalendarDayCell::create();
    cell->setYear(year);
    cell->setMonth(month);
    cell->setDay(day);
    return cell;
}

bool CCCalendarDayCell::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    ccColor4B color = ccc4(0xFF, 0xFF, 0xFF, 0x7A);
    CCLayerColor *layer = CCLayerColor::create(color, 30, 30);
    this->addChild(layer);
    this->setContentSize(CCSize(30, 30));
    return true;
}

void CCCalendarDayCell::onEnter()
{
    CCLabelTTF* pLabel = CCLabelTTF::create(convertInt(this->getDay()).c_str(), "Thonburi", 34);
    pLabel->setPosition(ccp(this->getContentSize().width / 2, this->getContentSize().height / 2));
    this->addChild(pLabel);
}

int CCCalendarDayCell::getWeekDays()
{
    struct tm *fmt = new tm;
    fmt->tm_year = this->getYear() - 1900;
    fmt->tm_mon = this->getMonth();
    fmt->tm_mday = this->getDay();
    fmt->tm_hour = 1;
    fmt->tm_min = 1;
    fmt->tm_sec = 1;
    mktime(fmt);
    int weekday = fmt->tm_wday;
    delete fmt;
    return weekday;
    
}

std::string convertInt(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}