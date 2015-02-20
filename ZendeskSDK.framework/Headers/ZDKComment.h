/*
 *
 *  ZDKComment.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 13/06/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */
#import <Foundation/Foundation.h>

/**
 * A comment on a Zendesk request.
 */
@interface ZDKComment : NSObject

/**
 * The id of this comment in Zendesk.
 */
@property (nonatomic, readonly) NSNumber *commentId;

/**
 * The comment body/text.
 */
@property (nonatomic, strong) NSString *body;

/**
 * The Zendesk user id of the author.
 */
@property (nonatomic, strong) NSNumber *authorId;

/**
 * The timestmp fpr the creation of this comment.
 */
@property (nonatomic, strong) NSDate *createdAt;

/**
 *  Collection of ZDKAttachments associated with this comment
 */
@property (nonatomic, strong) NSArray *attachments;


/**
 * Initialise the model object with the account details ands the dispatcher to be used for requests.
 *
 * @param dictionary the dictionary generated from the API json
 */
- (instancetype) initWithDictionary:(NSDictionary*)dictionary;


@end

