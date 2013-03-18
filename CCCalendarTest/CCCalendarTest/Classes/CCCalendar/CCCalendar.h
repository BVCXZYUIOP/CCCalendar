//
//  CCCalendar.h
//  CCCalendarTest
//
//  Created by 陶 然景 on 13-3-18.
//
//

#ifndef __CCCalendarTest__CCCalendar__
#define __CCCalendarTest__CCCalendar__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "CCCalendarDayCell.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CCCalendar: public CCLayer {
public:
    CCCalendar();
    ~CCCalendar();
    
    static CCCalendar* create(unsigned int year, unsigned int month);
    CREATE_FUNC(CCCalendar);
    virtual bool init();
    
    CC_SYNTHESIZE_RETAIN(CCArray*, m_pGridCellList, Grids);
    CC_SYNTHESIZE(unsigned int, m_uYear, Year);
    CC_SYNTHESIZE(unsigned int, m_uMonth, Month);
    CC_SYNTHESIZE(float, m_fGapX, GapX);
    CC_SYNTHESIZE(float, m_fGapY, GapY);
    
    void addAGridCell(CCCalendarDayCell *gridCell);
    int getColumnCount();
    int getRowCount();
    CCPoint getLastAvilableCellPosition();
    
    int getMonthDays();
    
protected:
    unsigned int m_uFirstDayOfTheWeekThisMonth;
};

#endif /* defined(__CCCalendarTest__CCCalendar__) */
