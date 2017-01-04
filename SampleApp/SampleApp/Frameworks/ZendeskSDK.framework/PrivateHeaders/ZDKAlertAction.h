/*
 *
 *  ZDKAlertAction.h
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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZDKAlertAction;

/**
 *  Style enum for alert actions.
 *
 *  @since 1.5.0.1
 */
typedef NS_ENUM(NSInteger, ZDKAlertActionStyle){
    /**
     *  The default UI stlye for an alert action.
     *
     *  @since 1.5.0.1
     */
    ZDKAlertActionStyleDefault = 0,
    /**
     *  Cancel UI stlye for an alert action.
     *
     *  @since 1.5.0.1
     */
    ZDKAlertActionStyleCancel,
    /**
     *  Destructive UI stlye for an alert action. Red text.'
     *
     *  @since 1.5.0.1
     */
    ZDKAlertActionStyleDestructive
};

/**
 *  Block typedef for alert action handlers.
 *
 *  @param action the alert which the handler belongs to.
 *
 *  @since 1.5.0.1
 */
typedef void (^ZDKAlertActionHandler)(ZDKAlertAction *action);

/**
 *  ZDKAlertAction mimics UIAlertAction containing logic for a single alert action and how that action should look.
 *
 *  @since 1.5.0.1
 */
@interface ZDKAlertAction : NSObject <NSCopying>

/**
 *  The title for this aciton.
 *
 *  @since 1.5.0.1
 */
@property (nullable, nonatomic, copy, readonly) NSString *title;

/**
 *  The style for this action.
 *
 *  @since 1.5.0.1
 */
@property (nonatomic, assign, readonly) ZDKAlertActionStyle style;

/**
 *  Handler which will be called when the action is chosen.
 *
 *  @since 1.5.0.1
 */
@property (nullable, nonatomic, copy, readonly) ZDKAlertActionHandler handler;

/**
 *  Creates a new ZDKAlertAction with the given paramenters.
 *
 *  @param title The title for this action.
 *  @param style The style for this action.
 *  @param handler A handler to which is called when this action is chosen.
 *
 *  @return A new ZDKAlertAction
 *
 *  @since 1.5.0.1
 */
+ (instancetype)actionWithTitle:(nullable NSString *)title style:(ZDKAlertActionStyle)style handler:(ZDKAlertActionHandler __nullable)handler;

@end

NS_ASSUME_NONNULL_END
