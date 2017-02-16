/*
 *
 *  ZDKTicketFormsSettings.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 21/09/2016.
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
 *  Models the Conversations settings in the admin config panel.
 *
 *  @since 1.9.0.1
 */
@interface ZDKTicketFormsSettings : ZDKCoding


/**
 * enabled defines if the conversations component is enabled or not.
 *
 *  @since 1.9.0.1
 */
@property (nonatomic, assign, readonly) BOOL enabled;


/**
 * initWithDictionary, passing the NSDictionary of Conversations settings received from the server.
 *
 *  @since 1.9.0.1
 */
- (id) initWithDictionary:(NSDictionary *)dictionary;

@end
