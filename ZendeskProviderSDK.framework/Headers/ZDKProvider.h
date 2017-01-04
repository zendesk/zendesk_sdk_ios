/*
 *
 *  ZDKProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on  01/01/2016.
 *
 *  Copyright (c) 2016 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>

@class ZDKAuthenticationSpace;

/**
 *  ZDKProvider class
 *
 *  @since 1.6.0.1
 */
@interface ZDKProvider : NSObject

/**
 *  Authentication space to use
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong, readonly) ZDKAuthenticationSpace *authenticationSpace;

/**
 *  Creates a provider with an authentication space
 *
 *  @since 1.6.0.1
 *
 *  @param authenticationSpace authentication space to use with requests
 */
- (instancetype)initWithAuthenticationSpace:(ZDKAuthenticationSpace*)authenticationSpace;


@end
