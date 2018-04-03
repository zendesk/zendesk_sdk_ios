/*
 *
 *  ZDKRequestHelper.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on  14/12/2015
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>
#import "ZendeskSDKConstants.h"


@protocol ZDKIdentity;
@class ZDKAccount, ZDKAuthenticationSpace;

NS_ASSUME_NONNULL_BEGIN
@interface ZDKRequestHelper : NSObject

/**
 *  Retrurn a dictionary of shared to be sent with the providors requests
 *
 *  @param authenticationSpace Authentication space used
 */
+ (NSDictionary *)sharedHeadersWithAuthenticationSpace:(ZDKAuthenticationSpace*)authenticationSpace;

/**
 * Returns a dictionary that has the Accept-Language header set in it
 *
 * @param headers    the request headers to update
 * @param userLocale the user locale to set
 *
 * @return the updated request header
 */
+ (NSDictionary *)requestHeaders:(NSDictionary*)headers byAddingLocale:(NSString*)userLocale;

/**
 *  Returns a String of User Agent Headers appendded together
 */
+ (NSString *)userAgentHeader;

/**
 *  Class is not instantiable
 */

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
