/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/productpresenter_screen/ProductPresenterViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ProductPresenterViewBase::ProductPresenterViewBase() :
    buttonCallback(this, &ProductPresenterViewBase::buttonCallbackHandler)
{
    navigationBar.setXY(0, 218);
    navigationBar.setBitmap(Bitmap(BITMAP_PRODUCT_PRESENTER_NAV_BAR_ID));

    textBackground.setPosition(210, 0, 270, 218);
    textBackground.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

    shadowBox.setPosition(210, 0, 1, 218);
    shadowBox.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    textAreaContainer.setPosition(210, 53, 270, 165);
    textAreaContainer.setScrollbarsColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    bodyText.setPosition(18, 0, 234, 238);
    bodyText.setColor(touchgfx::Color::getColorFrom24BitRGB(118, 118, 118));
    bodyText.setLinespacing(0);
    bodyText.setTypedText(TypedText(T_POSTER_TEXT_00));
    textAreaContainer.add(bodyText);
    textAreaContainer.setScrollbarsPermanentlyVisible();
    textAreaContainer.setScrollbarsVisible(false);

    nextButton.setXY(424, 0);
    nextButton.setBitmaps(Bitmap(BITMAP_PRODUCT_PRESENTER_NEXT_ID), Bitmap(BITMAP_PRODUCT_PRESENTER_NEXT_PRESSED_ID));
    nextButton.setAction(buttonCallback);

    headlineText.setPosition(228, 20, 210, 26);
    headlineText.setColor(touchgfx::Color::getColorFrom24BitRGB(118, 118, 118));
    headlineText.setLinespacing(0);
    headlineText.setTypedText(TypedText(T_POSTER_HEADLINE_00));

    headlineTextSwap.setPosition(228, 20, 210, 26);
    headlineTextSwap.setColor(touchgfx::Color::getColorFrom24BitRGB(118, 118, 118));
    headlineTextSwap.setLinespacing(0);
    headlineTextSwap.setTypedText(TypedText(T_POSTER_HEADLINE_00));

    posterContainer.setPosition(0, 0, 210, 218);

    poster.setXY(0, 0);
    poster.setBitmap(Bitmap(BITMAP_POSTER_IMAGE_00_ID));
    posterContainer.add(poster);

    posterSwap.setXY(0, 0);
    posterSwap.setBitmap(Bitmap(BITMAP_POSTER_IMAGE_00_ID));
    posterContainer.add(posterSwap);

    gotoMenuButton.setXY(2, 218);
    gotoMenuButton.setBitmaps(Bitmap(BITMAP_PRODUCT_PRESENTER_MENU_BUTTON_ID), Bitmap(BITMAP_PRODUCT_PRESENTER_MENU_BUTTON_PRESSED_ID));
    gotoMenuButton.setAction(buttonCallback);

    activateLanguageSelectorButton.setXY(419, 231);
    activateLanguageSelectorButton.setBitmaps(Bitmap(BITMAP_FLAG_GBR_INACTIVE_ID), Bitmap(BITMAP_FLAG_GBR_INACTIVE_ID));
    activateLanguageSelectorButton.setAction(buttonCallback);

    mcuLoad.setXY(8, 200);

    add(navigationBar);
    add(textBackground);
    add(shadowBox);
    add(textAreaContainer);
    add(nextButton);
    add(headlineText);
    add(headlineTextSwap);
    add(posterContainer);
    add(gotoMenuButton);
    add(activateLanguageSelectorButton);
    add(mcuLoad);
}

void ProductPresenterViewBase::setupScreen()
{
    mcuLoad.initialize();
}

void ProductPresenterViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &nextButton)
    {
        //nextbuttonPressed
        //When nextButton clicked call virtual function
        //Call nextbuttonPressed
        nextbuttonPressed();
    }
    else if (&src == &gotoMenuButton)
    {
        //gotoMenuButtonClicked
        //When gotoMenuButton clicked change screen to MainMenu
        //Go to MainMenu with screen transition towards North
        application().gotoMainMenuScreenSlideTransitionNorth();
    }
    else if (&src == &activateLanguageSelectorButton)
    {
        //activateLanguageSelectorButtonClicked
        //When activateLanguageSelectorButton clicked call virtual function
        //Call activateLanguageSelectorButtonClicked
        activateLanguageSelectorButtonClicked();
    }
}
