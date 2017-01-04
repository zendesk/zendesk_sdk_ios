/*
 *
 *  ZDKAlertController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 09/11/2015.
 *
 *  Copyright © 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>

#import "ZDKAlertAction.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  The style of the alert UI when presented.
 *
 *  @since 1.5.0.1
 */
typedef NS_ENUM(NSInteger, ZDKAlertControllerStyle){
    /**
     *  Action sheet style UI.
     *
     *  @since 1.5.0.1
     */
    ZDKAlertControllerStyleActionSheet = 0,
    /**
     *  Alert style UI.
     *
     *  @since 1.5.0.1
     */
    ZDKAlertControllerStyleAlert
};

/**
 *  Presents an alert or action sheet. Manages the diferences in how action sheets are presented on older and newer iOS versions.
 *
 *  @since 1.5.0.1
 */
@interface ZDKAlertController : NSObject

/**
 *  The title for the alert where applicable.
 *
 *  @since 1.5.0.1
 */
@property (nullable, nonatomic, copy) NSString *title;

/**
 *  Messages for the alert where applicable.
 *
 *  @since 1.5.0.1
 */
@property (nullable, nonatomic, copy) NSString *message;

/**
 *  Style for the alert.
 *
 *  @since 1.5.0.1
 */
@property (nonatomic, assign, readonly) ZDKAlertControllerStyle preferredStyle;

/**
 *  Array of actions for the alert.
 *
 *  @since 1.5.0.1
 */
@property (nonatomic, copy, readonly) NSArray *actions;

/**
 *  Creates an alert controller with the parameters provided.
 *
 *  @param title title for the alert.
 *  @param message message for the alert.
 *  @param preferredStyle style for the alert.
 *
 *  @return A new ZDKAlert
 *
 *  @since 1.5.0.1
 */
+ (instancetype)alertControllerWithTitle:(nullable NSString *)title message:(nullable NSString *)message preferredStyle:(ZDKAlertControllerStyle)preferredStyle;

/**
 *  Adds an action to the alert controller.
 *
 *  @param action A ZDKAlertAction.
 *
 *  @since 1.5.0.1
 */
- (void)addAction:(ZDKAlertAction *)action;

/**
 *  Presents with the view controller and the assigned ZDKAlertControllerStyle.
 *
 *  @param viewController the view controller which will present the alert.
 *
 *  @since 1.5.0.1
 */
- (void)presentWithViewController:(UIViewController *)viewController;

/**
 *  Presents with the view controller and the assigned ZDKAlertControllerStyle within a 
 *  view for backwards compatability with action sheets.
 *
 *  @param viewController the view controller which will present the alert.
 *  @param view a view to show the action sheet from in older iOS versions.
 *
 *  @since 1.5.0.1
 */
- (void)presentWithViewController:(UIViewController *)viewController inView:(UIView *)view;

/**
 *  Presents with the view controller and the assigned ZDKAlertControllerStyle within a frame in a
 *  view for backwards compatability with action sheets.
 *
 *  @param viewController the view controller which will present the alert.
 *  @param view a view to show the action sheet from in older iOS versions.
 *  @param fromView the view from which an action sheet will be displayed for newer iOS
 *
 *  @since 1.5.0.1
 */
- (void)presentWithViewController:(UIViewController *)viewController inView:(UIView *)view fromView:(UIView *)fromView;

@end

NS_ASSUME_NONNULL_END
