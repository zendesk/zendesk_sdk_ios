/*
 *
 *  ZDKHelpCenterSettings.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 16/10/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKCoding.h"

@interface ZDKHelpCenterSettings : ZDKCoding


/**
 * enabled defines if the conversations component is enabled or not
 */
@property (nonatomic, assign, readonly) BOOL enabled;

/**
 * String definition of the locale to be used by the help center component
 */
@property (nonatomic, copy, readonly) NSString *locale;


/**
 * initWithDictionary, passing the NSDictionary of Conversations settings received from the server
 */
- (id) initWithDictionary:(NSDictionary *)dictionary ;

@end
