//
//  ZDKAppSettings.h
//  ZendeskSDK
//
//  Created by Zendesk on 16/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ZDKRateMyAppSettings, ZDKContactUsSettings, ZDKConversationsSettings, ZDKHelpCenterSettings;

@interface ZDKAppSettings : NSObject


/**
 * Settings model object associated with the remote configuration of Rate My App component within your Zendesk instance
 */
@property (nonatomic, readonly) ZDKRateMyAppSettings *rateMyAappSettings;


/**
 * Settings model object associated with the remote configuration of Conversations component within your Zendesk instance
 */
@property (nonatomic, readonly) ZDKConversationsSettings *conversationsSettings;


/**
 * Settings model object associated with the remote configuration of Contact component within your Zendesk instance
 */
@property (nonatomic, readonly) ZDKContactUsSettings *contactUsSettings;


/**
 * Settings model object associated with the remote configuration of Help Cetner component within your Zendesk instance
 */
@property (nonatomic, readonly) ZDKHelpCenterSettings *helpCenterSettings;


- (id) initWithDictionary: (NSDictionary *) dictionary;

@end
