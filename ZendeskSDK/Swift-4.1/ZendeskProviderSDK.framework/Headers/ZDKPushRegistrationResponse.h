/*
 *
 *  ZDKPushRegistrationResponse.h
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

/**
 *  This is a class model for a response for registering a device for push notifications.
 *
 *  @since 1.2.0.1
 */
@interface ZDKPushRegistrationResponse : NSObject


/**
 *  The device specific id
 *
 *  @since 1.2.0.1
 */
@property (nonatomic, copy) NSString *identifier;


/**
 *  Initialize an object with a dictionary.
 *
 *  @since 1.2.0.1
 *
 *  @param dictionary a dictionary with values for the properties on this class.
 *
 *  @return an initialized object.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;


@end
