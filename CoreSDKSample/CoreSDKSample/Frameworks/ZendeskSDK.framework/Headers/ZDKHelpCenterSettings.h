//
//  ZDKHelpCenterSettings.h
//  ZendeskSDK
//
//  Created by Zendesk on 16/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDKHelpCenterSettings : NSObject


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
