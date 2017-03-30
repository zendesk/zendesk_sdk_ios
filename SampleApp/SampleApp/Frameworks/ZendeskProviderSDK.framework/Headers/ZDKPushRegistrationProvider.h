/*
 *
 *  ZDKPushRegistrationProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 04/03/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKProvider.h"


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
@interface ZDKPushRegistrationProvider : ZDKProvider



/**
 *  Calls a push registration end point to register the given APNS device id.
 *
 *  This method stores the `ZDKPushRegistrationResponse` on successful registration. 
 *  Subsequent calls to this method with the same `identifier` bypass calls to the
 *  network and return the stored `ZDKPushRegistrationResponse` in the `callback`.
 *  Calling this method with a different `identifier` will remove any stored
 *  `ZDKPushRegistrationResponse` from storage.
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
 *  This method stores the `ZDKPushRegistrationResponse` on successful registration.
 *  Subsequent calls to this method with the same `identifier` bypass calls to the
 *  network and return the stored `ZDKPushRegistrationResponse` in the `callback`.
 *  Calling this method with a different `identifier` will remove any stored
 *  `ZDKPushRegistrationResponse` from storage.
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
 *  Successful calls to this method will remove any stored `ZDKPushRegistrationResponse`. 
 *
 *  @since 1.2.0.1
 *
 *  @param identifier The device identifier
 *  @param callback   Callback that provides the HTTP status code for the deletion request.
 */
- (void) unregisterDevice:(NSString *)identifier callback:(ZDKPushDeletionCallback)callback;

@end
