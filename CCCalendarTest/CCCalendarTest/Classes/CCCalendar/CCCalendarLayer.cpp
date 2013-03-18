//
//  CCCalendarLayer.cpp
//  CCCalendarTest
//
//  Created by 陶 然景 on 13-3-18.
//
//

#include "CCCalendarLayer.h"
#include "CCCalendar.h"

CCCalendarLayer::CCCalendarLayer()
:m_pLeftButton(NULL)
,m_pRightButton(NULL)
,p_uCurrentYear(0)
,p_uCurrentMonth(0)
,m_pCalendar(NULL)
{
    
}

CCCalendarLayer::~CCCalendarLayer()
{
    CC_SAFE_RELEASE_NULL(m_pLeftButton);
    CC_SAFE_RELEASE_NULL(m_pRightButton);
    CC_SAFE_RELEASE_NULL(m_pCalendar);
}

bool CCCalendarLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCMenuItemImage *pLeftButton = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(CCCalendarLayer::leftButtonClicked));
    
    CCMenuItemImage *pRightButton = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(CCCalendarLayer::rightButtonClicked));
    
    pLeftButton->setPosition(ccp(0, 300));
    pRightButton->setPosition(ccp(460, 300));
    CCMenu* pMenu = CCMenu::create(pLeftButton, NULL);
    CCMenu* pMenu2 = CCMenu::create(pRightButton, NULL);
    pMenu->setPosition( CCPointZero );
    pMenu2->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    this->addChild(pMenu2, 1);
    
    this->setCalendar(CCCalendar::create());
    this->addChild(this->getCalendar());
    
    this->setCurrentYear(this->getCalendar()->getYear());
    this->setCurrentMonth(this->getCalendar()->getMonth());
    
    return true;
}

void CCCalendarLayer::leftButtonClicked(cocos2d::CCObject *pSender)
{
    this->removeChild(this->getCalendar(), true);
    if (this->getCurrentMonth() == 0)
    {
        this->setCurrentYear(this->getCurrentYear() - 1);
        this->setCurrentMonth(11);
    }
    else
    {
        this->setCurrentMonth(this->getCurrentMonth() - 1);
    }
    
    this->setCalendar(CCCalendar::create(this->getCurrentYear(), this->getCurrentMonth()));
    this->addChild(this->getCalendar());
}

void CCCalendarLayer::rightButtonClicked(cocos2d::CCObject *pSender)
{
    this->removeChild(this->getCalendar(), true);
    if (this->getCurrentMonth() == 11)
    {
        this->setCurrentYear(this->getCurrentYear() + 1);
        this->setCurrentMonth(0);
    }
    else
    {
        this->setCurrentMonth(this->getCurrentMonth() + 1);
    }
    
    this->setCalendar(CCCalendar::create(this->getCurrentYear(), this->getCurrentMonth()));
    this->addChild(this->getCalendar());
}