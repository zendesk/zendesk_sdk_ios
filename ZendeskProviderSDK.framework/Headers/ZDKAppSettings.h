/*
 *
 *  ZDKAppSettings.h
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

@class ZDKContactUsSettings, ZDKConversationsSettings, ZDKHelpCenterSettings, ZDKTicketFormsSettings;


@interface ZDKAppSettings : ZDKCoding

/**
 * Settings model object associated with the remote configuration of Conversations component within your Zendesk instance.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, strong, readonly) ZDKConversationsSettings *conversationsSettings;


/**
 * Settings model object associated with the remote configuration of Contact component within your Zendesk instance.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, strong, readonly) ZDKContactUsSettings *contactUsSettings;


/**
 * Settings model object associated with the remote configuration of Help Center component within your Zendesk instance.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, strong, readonly) ZDKHelpCenterSettings *helpCenterSettings;


/**
 * Settings model object associated with the remote configuration of Ticket Forms component within your Zendesk instance.
 *
 *  @since 1.9.0.1
 */
@property (nonatomic, strong, readonly) ZDKTicketFormsSettings *ticketFormsSettings;


/**
 *  Authentication type, anonymous or jwt.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, copy, readonly) NSString *authentication;


/**
 *  Initialize with a dictionary representation.
 *
 *  @since 0.9.3.1
 *
 *  @param dictionary a dictionary with settings data.
 *
 *  @return A new instance.
 */
- (id) initWithDictionary: (NSDictionary *) dictionary;

@end
