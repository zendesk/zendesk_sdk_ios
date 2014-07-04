//
//  ZDToast.h
//  ZDToast
//
//  Created by Zendesk on 22/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "ZDToastStyle.h"
#import "ZDToastView.h"


/**
 * Presents a toast message to the user from the navigation bar of the top most view controller.
 * Usage:
 * <pre>
 * @code
 *
 * // Present from navigation bar.
 * [ZDToast show:@"I'm a toast message!" ofType:ZDToastOk inViewController:vc];
 *
 * [ZDToast show:@"I'm another toast message!" ofType:ZDToastOk for:3.0f inViewController:vc];
 *
 * UIView *view = [UIView alloc] initWithFrame:CGRectZero];
 * ... configure
 * [ZDToast showWithContent:view duration:0.0f inViewController:viewController autoDismiss:NO];
 *
 * // Present at the top of any view at full width
 * [ZDToast show:@"I'm a toast message!" ofType:ZDToastOk in:view];
 *
 * [ZDToast show:@"I'm another toast message!" ofType:ZDToastOk in:view at:y for:3.0f];
 *
 * UIView *view = [UIView alloc] initWithFrame:CGRectZero];
 * ... configure
 * [ZDToast showWithContent:view for:0.0f inViewController:viewController autoDismiss:NO];
 * </pre>
 *
 * Auto dismiss toasts will skip animating out if the toast view has no superview or 
 * if the toasts superview has no superview.
 *
 * @since 0.1
 */
@interface ZDToast : NSObject


#pragma mark show from UINavigationController


/**
 * Show a full width toast message below the UINavigationBar with a default duration of 2 seconds (2 TBC).
 * @param message the message to be presented
 * @param type ZDToastTypeEnum specifying the type of toast to be displayed
 * @param viewController the view controller in which to present the toast
 * @since 0.1
 */
+ (void)    show:(NSString*)message
          ofType:(ZDToastTypeEnum)type
inViewController:(UIViewController*)viewController;


/**
 * Show a full width toast message below the UINavigationBar for the requested duration.
 * @param message message to be presented
 * @param type ZDToastTypeEnum specifying the type of toast to be displayed
 * @param durationInSeconds total duration the toast will be displayed for including animations
 * @param viewController the view controller in which to present the toast
 * @since 0.1
 */
+ (void)    show:(NSString*)message
          ofType:(ZDToastTypeEnum)type
             for:(NSTimeInterval)durationInSeconds
inViewController:(UIViewController*)viewController;


#pragma mark show in view


/**
 * Show the toast message in the requested view at the top of the view.
 * @param message the message to be presented
 * @param type ZDToastTypeEnum specifying the type of toast to be displayed
 * @param view the view from which the message will animate down
 * @since 0.1
 */
+ (void) show:(NSString*)message
       ofType:(ZDToastTypeEnum)type
           in:(UIView*)view;


/**
 * Show the toast message in the requested view at location 'y' for the specified duration.
 * @param message the message to be presented
 * @param type ZDToastTypeEnum specifying the type of toast to be displayed
 * @param view the view from which the message will animate down
 * @param y the y position in the view to present from
 * @param durationInSeconds total duration the toast will be displayed for including animations
 * @since 0.1
 */
+ (void) show:(NSString*)message
       ofType:(ZDToastTypeEnum)type
           in:(UIView*)view
           at:(CGFloat)y
          for:(NSTimeInterval)durationInSeconds;


/**
 * Set the animation timing for the presentation of toasts.
 * @param duration
 * @since 0.1
 */
+ (void) setAnimationDuration:(NSTimeInterval)durationInSeconds;


#pragma mark - Custom content (v0.2)


/**
 * Show a full width toast message below the UINavigationBar using the provided view as content.
 * @param contentView the view to use as content for the toast, no margins or padding will be applied
 * @param durationInSeconds total duration the toast will be fully visible, if autoDismiss is false this is ignored
 * @param viewController the view controller in which to present the toast
 * @param autoDismiss default true, if false then auto dismiss will not occur
 * @since 0.2
 */
+ (void) showWithContent:(UIView*)contentView
                     for:(NSTimeInterval)durationInSeconds
        inViewController:(UIViewController*)viewController
             autoDismiss:(BOOL)autoDismiss;


/**
 * Show the toast message in the provided view at location 'y' for the requested duration.
 * @param contentView the view to use as content for the toast, no margins or padding will be applied
 * @param view the view from which the message will animate down
 * @param y the y position in the view to present from
 * @param durationInSeconds total duration the toast will be fully visible, if autoDismiss is false this is ignored
 * @param autoDismiss default true, if false then auto dismiss will not occur
 * @since 0.2
 */
+ (void) showWithContent:(UIView*)contentView
                      in:(UIView*)view
                      at:(CGFloat)y
                     for:(NSTimeInterval)durationInSeconds
             autoDismiss:(BOOL)autoDismiss;


/**
 * Animate out the current toast message.
 * @since 0.2
 */
+ (void) dismiss;


@end

