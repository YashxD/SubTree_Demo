/**
  ******************************************************************************
  * This file is part of the TouchGFX 4.10.0 distribution.
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
  

#include <gui/settings_screen/AnalogClockWithSetTimeFunctionality.hpp>
#include <touchgfx/widgets/canvas/CWRUtil.hpp>
#include <touchgfx/Math3D.hpp>

AnalogClockWithSetTimeFunctionality::AnalogClockWithSetTimeFunctionality() :
    AnalogClock(),
    timeSettingChangedCallback(0)
{
    setTouchable(true);
}

void AnalogClockWithSetTimeFunctionality::handleClickEvent(const ClickEvent& evt)
{
    if (evt.getType() == ClickEvent::PRESSED)
    {
        updateHand(evt.getX(), evt.getY());
    }
}

void AnalogClockWithSetTimeFunctionality::handleDragEvent(const DragEvent& evt)
{
    updateHand(evt.getNewX(), evt.getNewY());
}

void AnalogClockWithSetTimeFunctionality::updateHand(int newX, int newY)
{
    int16_t vx = newX - clockRotationCenterX;
    int16_t vy = newY - clockRotationCenterY;

    int length;
    int angleInDegrees = CWRUtil::angle<int>(vx, vy, length);
    angleInDegrees = MAX(0, MIN(359, angleInDegrees));

    if (length < 30 || length > 120)
    {
        return;
    }

    uint8_t newTimeValue = 0;
    bool timeUpdated = false;

    switch (updateMode)
    {
    case AnalogClockWithSetTimeFunctionality::HOUR_UPDATE:
        newTimeValue = angleInDegrees / 30;
        if (getCurrentHour() != newTimeValue)
        {
            updateTime(newTimeValue, getCurrentMinute(), getCurrentSecond());
            timeUpdated = true;
        }
        break;
    case AnalogClockWithSetTimeFunctionality::MINUTE_UPDATE:
        newTimeValue = angleInDegrees / 6;
        if (getCurrentMinute() != newTimeValue)
        {
            updateTime(getCurrentHour(), newTimeValue, getCurrentSecond());
            timeUpdated = true;
        }
        break;
    case AnalogClockWithSetTimeFunctionality::SECOND_UPDATE:
        newTimeValue = angleInDegrees / 6;
        if (getCurrentSecond() != newTimeValue)
        {
            updateTime(getCurrentHour(), getCurrentMinute(), newTimeValue);
            timeUpdated = true;
        }
        break;
    default:
        break;
    }

    if (timeUpdated && timeSettingChangedCallback && timeSettingChangedCallback->isValid())
    {
        timeSettingChangedCallback->execute(updateMode,  newTimeValue);
    }
}

void AnalogClockWithSetTimeFunctionality::setUpdateMode(UpdateMode mode)
{
    updateMode = mode;

    hourHand.setAlpha(56);
    minuteHand.setAlpha(56);
    secondHand.setAlpha(56);


    switch (mode)
    {
    case AnalogClockWithSetTimeFunctionality::HOUR_UPDATE:
        hourHand.setAlpha(255);
        break;
    case AnalogClockWithSetTimeFunctionality::MINUTE_UPDATE:
        minuteHand.setAlpha(255);
        break;
    case AnalogClockWithSetTimeFunctionality::SECOND_UPDATE:
        secondHand.setAlpha(255);
        break;
    default:
        break;
    }

    hourHand.invalidate();
    minuteHand.invalidate();
    secondHand.invalidate();
}

