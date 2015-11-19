/*
 *
 *  ZDKHelpCenterSettings.h
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

@interface ZDKHelpCenterSettings : ZDKCoding


/**
 * enabled defines if the conversations component is enabled or not
 */
@property (nonatomic, readonly) BOOL enabled;

/**
 * String definition of the locale to be used by the help center component
 */
@property (nonatomic, readonly) NSString *locale;


/**
 * initWithDictionary, passing the NSDictionary of Conversations settings received from the server
 */
- (id) initWithDictionary:(NSDictionary *)dictionary ;

@end
