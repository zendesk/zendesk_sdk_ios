/*
 *
 *  ZDKAccountAuthHelper.h
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

#import <Foundation/Foundation.h>

@class ZDKAccount;


/**
 *  Utility class that helps in some misc tasks with an account
 */
NS_ASSUME_NONNULL_BEGIN
@interface ZDKAccountAuthHelper : NSObject

/**
 *  returns true if the account contains an auth token stored
 */
+ (BOOL)isOauthTokenAvailableForAccount:(ZDKAccount*)account;


/**
 *  creates a new request by adding the auth token from account to the passed request
 *
 *  @param account account to fetch auth token from
 *  @param request the original request
 *
 *  @return a newly created request that contains the auth headers
 */
+ (NSURLRequest*)requestWithAuthForAccount:(ZDKAccount*)account
                               withRequest:(NSURLRequest*)request;

/**
 *  stores the auth token into the passed account
 */
+ (void)storeAuthToken:(NSString*)authToken andUserId:(NSNumber*)userId toAccount:(ZDKAccount*)account;


/**
 *  check if the data returned from a response contains the auth token
 *
 *  @param data data returned from a login request
 *
 *  @return YES if the data contains auth token, otherwise return no
 */
+ (BOOL)checkResponseContainsAuthToken:(NSData*)data;

/**
 *  check if the data returned from a response contains the user id
 *
 *  @param data data returned from a login request
 *
 *  @return YES if the data contains user id, otherwise return no
 */
+ (BOOL)checkResponseContainsUserId:(NSData*)data;

/**
 *  returns the auth token from the data passed
 *
 *  @param data data returned from a login request
 *
 *  @return the auth token if the data contains it, otherwise return nil
 */
+ (NSString *__nullable)authTokenWithResponseData:(NSData*)data;

/**
 *  returns the user id from the data passed
 *
 *  @param data data returned from a login request
 *
 *  @return the user id if the data contains it, otherwise return nil
 */
+ (NSNumber *__nullable)userIdWithResponseData:(NSData*)data;


/**
 *  check if the account passed has the correct information required to be valid
 *
 *  @param account      account to validate
 *  @param authRequired is auth required
 *
 *  @return YES if the account has all the settings required, otherwise returns NO
 */
+ (BOOL)isAccount:(ZDKAccount*)account validWithAuthRequired:(BOOL)authRequired;

@end
NS_ASSUME_NONNULL_END
