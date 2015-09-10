/*
 *
 *  ZDKPushRegistrationProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 04/03/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>

@class ZDKPushRegistrationRequest, ZDKPushRegistrationResponse;


/**
 *  A callback for push registration.
 *
 *  @since 1.2.0.1
 *
 *  @param registrationResponse A model for the response to push registration.
 *  @param error                An error object. Nil unless there was an error.
 */
typedef void (^ZDKPushRegistrationCallback)(ZDKPushRegistrationResponse *registrationResponse, NSError *error);


/**
 *  A callback for unregistration.
 *
 *  @since 1.2.0.1
 *
 *  @param responseCode A model for the response removing push on a device.
 *  @param error        An error object. Nil unless there was an error.
 */
typedef void (^ZDKPushDeletionCallback)(NSNumber *responseCode, NSError *error);


/**
 *  Provider to register and unregister a device for push notifications.
 *
 *  @since 1.2.0.1
 */
@interface ZDKPushRegistrationProvider : NSObject


/**
 *  Calls a push registration end point to register the given device configuration.
 *  Deprecated as of version 1.4.0.1. please use registerForPushWithDeviceID or registerForPushWithUAChannelID
 *  @since 1.2.0.1
 *
 *  @param identifier The device identifier
 *  @param locale     The preferred device locale
 *  @param callback   Callback that will provide a newly created device ZDKPushRegistrationResponse.
 */
- (void) registerDevice:(NSString *)identifier locale:(NSString *)locale callback:(ZDKPushRegistrationCallback)callback __deprecated_msg("As of version 1.4.0.1, please use registerForPushWithDeviceID or registerForPushWithUAChannelID");


/**
 *  Calls a push registration end point to register the given APNS device id.
 *
 *  @param identifier The device identifier
 *  @param locale     The preferred device locale
 *  @param callback   Callback that will provide a newly created device ZDKPushRegistrationResponse
 *
 *  @since 1.4.0.1
 */
- (void) registerForPushWithDeviceID:(NSString *)identifier locale:(NSString *)locale callback:(ZDKPushRegistrationCallback)callback;


/**
 *  Calls a push registration end point to register the given Urban Airship channel id.
 *
 *  @param identifier The channel identifier
 *  @param locale     The preferred device locale
 *  @param callback   Callback that will provide a newly created device ZDKPushRegistrationResponse
 *
 *  @since 1.4.0.1
 */
- (void) registerForPushWithUAChannelID:(NSString*)identifier local:(NSString *)locale callback:(ZDKPushRegistrationCallback)callback;


/**
 *  Calls a push registration end point to unregister a device to receive push notifications.
 *
 *  @since 1.2.0.1
 *
 *  @param identifier The device identifier
 *  @param callback   Callback that provides the HTTP status code for the deletion request.
 */
- (void) unregisterDevice:(NSString *)identifier callback:(ZDKPushDeletionCallback)callback;

@end
