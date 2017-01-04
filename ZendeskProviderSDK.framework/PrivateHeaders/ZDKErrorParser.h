/*
 *
 *  ZDKErrorParser.h
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


/**
 *  Parses the response from a request executor
 */
@interface ZDKErrorParser : NSObject

/**
 *  Validates the response from an executor and returns an error if appropriate
 *
 *  @param response the URL response from the executor
 *  @param error    the original error
 *
 *  @return error if the response and error pair represent a request error
 */
+ (NSError *__nullable)errorWithURLResponse:(NSURLResponse *__nonnull)response
                              originalError:(NSError *__nullable)error;

@end
