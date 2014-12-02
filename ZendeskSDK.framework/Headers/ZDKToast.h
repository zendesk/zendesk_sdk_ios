/*
 *
 *  ZDKToast.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 22/04/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


#import <Foundation/Foundation.h>
#import "ZDKToastStyle.h"
#import "ZDKToastView.h"



/**
 * Presents a toast message to the user from the navigation bar of the top most view controller.
 * Usage:
 *
 * @code
 *
 * // Present from navigation bar.
 * [ZDKToast show:@"I'm a toast message!" ofType:ZDKToastUITypeOK inViewController:vc];
 *
 * [ZDKToast show:@"I'm another toast message!" ofType:ZDKToastUITypeOK for:3.0f inViewController:vc];
 *
 *
 * // Present at the top of any view at full width
 * [ZDKToast show:@"I'm a toast message!" ofType:ZDKToastUITypeOK in:view];
 *
 * [ZDKToast show:@"I'm another toast message!" ofType:ZDKToastUITypeOK in:view at:y for:3.0f];
 *
 * @endcode
 *
 * @discussion Auto dismiss toasts will skip animating out if the toast view has no superview or
 * if the toasts superview has no superview.
 *
 * @since 0.1
 */
@interface ZDKToast : NSObject


#pragma mark show from UINavigationController


/**
 * Show a full width toast message below the UINavigationBar for the requested duration.
 * @param message message to be presented
 * @param type ZDKToastUIType specifying the type of toast to be displayed
 * @param viewController the view controller in which to present the toast
 * @param durationInSeconds total duration the toast will be displayed for including animations
 * @param animationBlock block with any UI changes to be performed at the same time as the toast animation
 * @param animated YES to animate in
 * @since 0.1
 */
+ (void) showMessage:(NSString*)message
              ofType:(ZDKToastUIType)type
    inViewController:(UIViewController*)viewController
        withDuration:(NSTimeInterval)durationInSeconds
        andAnimation:(ZDKToastAnimation)animationBlock
            animated:(BOOL)animated;


/**
 * Show a full width toast message below the UINavigationBar for the requested duration.
 * @param message message to be presented
 * @param type ZDKToastUIType specifying the type of toast to be displayed
 * @param view the view from which the message will animate down
 * @param viewController the view controller in which to present the toast
 * @param durationInSeconds total duration the toast will be displayed for including animations
 * @param animationBlock block with any UI changes to be performed at the same time as the toast animation
 * @param animated YES to animate in
 * @since 0.2
 */
+ (void) showMessage:(NSString *)message
              ofType:(ZDKToastUIType)type
              inView:(UIView *)view
    inViewController:(UIViewController *)viewController
        withDuration:(NSTimeInterval)durationInSeconds
        andAnimation:(ZDKToastAnimation)animationBlock
            animated:(BOOL)animated;


#pragma mark show in view


/**
 * Show the toast message in the requested view at location 'y' for the specified duration.
 * @param message the message to be presented
 * @param type ZDKToastUIType specifying the type of toast to be displayed
 * @param view the view from which the message will animate down
 * @param initialYPosisition the y position in the view to present from
 * @param durationInSeconds total duration the toast will be displayed for including animations
 * @param animationBlock block with any UI changes to be performed at the same time as the toast animation
 * @param animated YES to animate in
 * @since 0.1
 */
+ (void) showMessage:(NSString*)message
              ofType:(ZDKToastUIType)type
              inView:(UIView*)view
          startingAt:(CGFloat)initialYPosisition
        withDuration:(NSTimeInterval)durationInSeconds
        andAnimation:(ZDKToastAnimation)animationBlock
            animated:(BOOL)animated;





#pragma mark with button dismiss


/**
 * Show a full width toast message below the UINavigationBar using the provided view as content.
 * @param message the message to be presented
 * @param type ZDKToastUIType specifying the type of toast to be displayed
 * @param viewController the view controller in which to present the toast
 * @param buttonText text of the button which dismisses the Toast
 * @param buttonActionBlock Block to be run when the toast button is pressed.
 * @param animationBlock block with any UI changes to be performed at the same time as the toast animation
 * @param animated YES to animate in
 * @since 0.2
 */
+ (void) showMessage:(NSString*)message
              ofType:(ZDKToastUIType)type
    inViewController:(UIViewController*)viewController
      withButtonText:(NSString*)buttonText
        buttonAction:(ZDKToastButtonAction)buttonActionBlock
        andAnimation:(ZDKToastAnimation)animationBlock
            animated:(BOOL)animated;


/**
 * Show the toast message in the provided view at location 'y' for the requested duration.
 * @param message the message to be presented
 * @param type ZDKToastUIType specifying the type of toast to be displayed
 * @param view the view from which the message will animate down
 * @param initialYPosisition the y position in the view to present from
 * @param buttonText text of the button which dismisses the Toast
 * @param buttonActionBlock Block to be run when the toast button is pressed.
 * @param animationBlock block with any UI changes to be performed at the same time as the toast animation
 * @param animated YES to animate in
 * @since 0.2
 */
+ (void) showMessage:(NSString*)message
              ofType:(ZDKToastUIType)type
              inView:(UIView*)view
          startingAt:(CGFloat)initialYPosisition
      withButtonText:(NSString*)buttonText
        buttonAction:(ZDKToastButtonAction)buttonActionBlock
        andAnimation:(ZDKToastAnimation)animationBlock
            animated:(BOOL)animated;


#pragma mark - util


/**
 * Set the animation timing for the presentation of toasts.
 * @param durationInSeconds The duration of the animation.
 * @since 0.1
 */
+ (void) setAnimationDuration:(NSTimeInterval)durationInSeconds;


/**
 * Dismiss all Toast messages for the specified view controller
 * @param viewController the view controller the Toast was created on
 * @param animate YES to animate the removal of the visible Toast
 */
+ (void) dismissForViewController:(UIViewController*)viewController animate:(BOOL)animate;


/**
 * Dismiss all Toast messages for the specified view
 * @param view the view the Toast was created on
 * @param animate YES to animate the removal of the visible Toast
 */
+ (void) dismissForView:(UIView*)view animate:(BOOL)animate;


@end
