/*
 *
 *  ZDKContactUsSettings.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 16/10/2014.  
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
#import "ZDKCoding.h"

/**
 *  Models the Contact Us settings in the admin config panel.
 *
 *  @since 0.9.3.1
 */
@interface ZDKContactUsSettings : ZDKCoding

/**
 * tags is a list of tags that should be included as part of the ticket creation.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, readonly) NSArray *tags;

/**
 * initWithDictionary, passing the NSDictionary of Contact Us settings received from the server.
 *
 *  @since 0.9.3.1
 */
- (id) initWithDictionary:(NSDictionary *)dictionary ;

@end
