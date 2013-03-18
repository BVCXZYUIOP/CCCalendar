//
//  CCCalendarLayer.h
//  CCCalendarTest
//
//  Created by 陶 然景 on 13-3-18.
//
//

#ifndef __CCCalendarTest__CCCalendarLayer__
#define __CCCalendarTest__CCCalendarLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "CCCalendar.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CCCalendarLayer: public CCLayer {
public:
    CCCalendarLayer();
    ~CCCalendarLayer();
    
    CREATE_FUNC(CCCalendarLayer)
    virtual bool init();
    
    CC_SYNTHESIZE_RETAIN(CCControlButton*, m_pLeftButton, LeftButton);
    CC_SYNTHESIZE_RETAIN(CCControlButton*, m_pRightButton, RightButton);
    CC_SYNTHESIZE_RETAIN(CCCalendar*, m_pCalendar, Calendar);
    
    // a selector callback
    void leftButtonClicked(CCObject* pSender);
    void rightButtonClicked(CCObject* pSender);
    
protected:
    CC_SYNTHESIZE(unsigned int, p_uCurrentYear, CurrentYear);
    CC_SYNTHESIZE(unsigned int, p_uCurrentMonth, CurrentMonth);
};

#endif /* defined(__CCCalendarTest__CCCalendarLayer__) */
