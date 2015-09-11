/*
 *
 *  ZDKPushRegistrationRequest.h
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

/**
 *  Models the api request which is formed when registering a device for push notifications.
 *
 *  @since 1.2.0.1
 */
@interface ZDKPushRegistrationRequest : NSObject


/**
 *  The device identifier.
 *
 *  @since 1.2.0.1
 */
@property (nonatomic) NSString *identifier;


/**
 *  The locale of the device in the format of ll-cc. en-us, en-ca.
 *
 *  @since 1.2.0.1
 */
@property (nonatomic) NSString *locale;


/**
 *  The divice type, e.g. iphone.
 *
 *  @since 1.2.0.1
 */
@property (nonatomic, readonly) NSString *device_type;

/**
 *  Token type, only used to identify Urban Airship channels, nil otherwise.
 *
 *  @since 1.4.0.1
 */
@property (nonatomic) NSString *token_type;


/**
 *  Returns a dictionary representation of the object.
 *
 *  @return a dictionary with property values keyed by property names.
 *
 *  @since 1.2.0.1
 */
- (NSMutableDictionary *) toJson;


@end
