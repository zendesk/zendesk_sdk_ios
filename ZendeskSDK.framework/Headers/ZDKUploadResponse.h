/*
 *
 *  ZDKUploadResponse.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 1/21/15.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 * By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 * of Service ( https://www.zendesk.com/company/terms ) and Application Developer and API License
 * Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 * acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKAttachment.h"

/**
 *  Model for an upload response.
 *
 *  @since 1.1.0.1
 */
@interface ZDKUploadResponse : NSObject


/**
 *  A token for the upload. This is used to associate the upload with a request.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, strong) NSString *uploadToken;


/**
 *  The attachment model for the upload.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, strong) ZDKAttachment *attachment;


/**
 *  Initialise with a dictionary represenation of an upload response.
 *
 *  @since 1.1.0.1
 *
 *  @param dict a dictionary containing values from which a new instance is created.
 *
 *  @return A new instance of ZDKUploadRequest.
 */
- (instancetype) initWithDict:(NSDictionary*)dict;

@end
