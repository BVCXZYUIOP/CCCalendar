//
//  CCCalendarDayCell.h
//  CCCalendarTest
//
//  Created by 陶 然景 on 13-3-18.
//
//

#ifndef __CCCalendarTest__CCCalendarDayCell__
#define __CCCalendarTest__CCCalendarDayCell__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

std::string convertInt(int number);

class CCCalendarDayCell: public CCLayer {
public:
    CCCalendarDayCell();
    ~CCCalendarDayCell();
    
    static CCCalendarDayCell* create(unsigned int year, unsigned int month, unsigned int day);
    CREATE_FUNC(CCCalendarDayCell);
    virtual bool init();
    virtual void onEnter();
    int getWeekDays();
protected:
    CC_SYNTHESIZE(unsigned int, m_uYear, Year);
    CC_SYNTHESIZE(unsigned int, m_uMonth, Month);
    CC_SYNTHESIZE(unsigned int, m_uDay, Day);
    

};

#endif /* defined(__CCCalendarTest__CCCalendarDayCell__) */
