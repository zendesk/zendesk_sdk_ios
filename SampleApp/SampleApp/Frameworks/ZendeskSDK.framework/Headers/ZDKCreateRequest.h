/*
 *
 *  ZDKCreateRequest.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 5/22/15.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKCustomField.h"

/**
 *  A request sent by the user.
 *
 *  @since 1.3.0.1
 */
@interface ZDKCreateRequest : NSObject


/**
 *  List of tags assoicated with the request
 *
 *  @since 1.3.0.1
 */
@property (nonatomic, strong) NSArray *tags;

/**
 *  The subject of the request, if subject is enabled in the account.
 *
 *  @since 1.3.0.1
 */
@property (nonatomic, strong) NSString *subject;

/**
 *  The body of the request
 *
 *  @since 1.3.0.1
 */
@property (nonatomic, strong) NSString *requestDescription;



/**
 *  List of upload tokens.
 *
 *  @since 1.3.0.1
 */
@property (nonatomic, strong) NSArray *attachments;




/**
 *  Init with dictionary
 *
 *  @param dict Data dictionary. Has the same structure as presented by this model object.
 *
 *  @since 1.3.0.1
 */
- (instancetype) initWithDict:(NSDictionary*)dict;



@end
