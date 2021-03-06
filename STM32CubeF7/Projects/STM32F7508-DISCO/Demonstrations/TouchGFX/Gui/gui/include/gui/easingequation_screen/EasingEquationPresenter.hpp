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
  #ifndef EASINGEQUATION_PRESENTER_HPP
#define EASINGEQUATION_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class EasingEquationView;

class EasingEquationPresenter : public Presenter, public ModelListener
{
public:
    EasingEquationPresenter(EasingEquationView& v);
    virtual ~EasingEquationPresenter() {};

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    void mcuLoadUpdated(uint8_t mcuLoadValue);

private:
    EasingEquationPresenter();

    EasingEquationView& view;
};


#endif // EASINGEQUATION_PRESENTER_HPP
