/*
 *
 *  ZDKAttachment.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 1/13/15.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 * By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 * of Service ( https://www.zendesk.com/company/terms ) and Application Developer and API License
 * Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 * acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

/**
 *  An attachment to a Zendesk comment
 */
@interface ZDKAttachment : NSObject

/**
 *  The id of this attachment in Zendesk.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, strong) NSNumber *attachmentId;

/**
 *  The name of the attachment in Zendesk.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, strong) NSString *filename;

/**
 *  The full url where the attchment can be downloaded.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, strong) NSString *contentURLString;

/**
 *  The content type of the attachment, i.e. image/png
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, strong) NSString *contentType;

/**
 *  The size of the attachment in bytes.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, strong) NSNumber *size;

/**
 *  Thumbnails associated with the attachment. A thumbnail is an attachment with a nil thumbnails array.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, strong) NSArray *thumbnails;


/**
 * Init with dictionary from API response.
 *
 *  @since 1.1.0.1
 *
 * @param dict the dictionary generated from the JSON API response
 */
- (instancetype) initWithDict:(NSDictionary*)dict;


@end
